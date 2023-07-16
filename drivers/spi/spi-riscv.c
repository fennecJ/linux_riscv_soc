#include <linux/interrupt.h>
#include <linux/errno.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/spi/spi.h>
#include <linux/io.h>
#include <linux/of.h>

#define DRV_NAME "spi_riscv"

#define RISCV_SPI_CR1  0x000
#define RISCV_SPI_CR2  0x004
#define RISCV_SPI_SR   0x008
#define RISCV_SPI_DR   0x00c
#define RISCV_DMA_SRC  0x800
#define RISCV_DMA_DEST 0x804
#define RISCV_DMA_LEN  0x808
#define RISCV_DMA_CON  0x80c
#define RISCV_DMA_IE   0x810
#define RISCV_DMA_IP   0x814
#define RISCV_DMA_IC   0x818

#define TYPE_FIXED 0x0
#define TYPE_INCR  0x1
#define TYPE_CONST 0x2
#define SIZE_BYTE  0x0
#define SIZE_HWORD 0x1
#define SIZE_WORD  0x2
#define SIZE_DWORD 0x3

#define RISCV_SPI_CR1_BR_SFT        (3)

#define RISCV_SPI_CR1_CPHA_MASK     (1 <<  0)
#define RISCV_SPI_CR1_CPOL_MASK     (1 <<  1)
#define RISCV_SPI_CR1_MSTR_MASK     (1 <<  2)
#define RISCV_SPI_CR1_BR_MASK       (7 <<  3)
#define RISCV_SPI_CR1_SPE_MASK      (1 <<  6)
#define RISCV_SPI_CR1_LSBF_MASK     (1 <<  7)
#define RISCV_SPI_CR1_SSI_MASK      (1 <<  8)
#define RISCV_SPI_CR1_SSM_MASK      (1 <<  9)
#define RISCV_SPI_CR1_RXONLY_MASK   (1 << 10)
#define RISCV_SPI_CR1_DFF_MASK      (1 << 11)
#define RISCV_SPI_CR1_CRCNXT_MASK   (1 << 12)
#define RISCV_SPI_CR1_CRCEN_MASK    (1 << 13)
#define RISCV_SPI_CR1_BIDIOE_MASK   (1 << 14)
#define RISCV_SPI_CR1_BIDIMODE_MASK (1 << 15)
#define RISCV_SPI_CR1_DEL_MASK      (1 << 16)

#define RISCV_SPI_CR2_RXDMAEN_MASK  (1 <<  0)
#define RISCV_SPI_CR2_TXDMAEN_MASK  (1 <<  1)
#define RISCV_SPI_CR2_SSOE_MASK     (1 <<  2)
#define RISCV_SPI_CR2_ERRORIE_MASK  (1 <<  5)
#define RISCV_SPI_CR2_RXNEIE_MASK   (1 <<  6)
#define RISCV_SPI_CR2_TXEIE_MASK    (1 <<  7)

#define RISCV_SPI_SR_TXE_MASK       (1 <<  0)
#define RISCV_SPI_SR_RXNE_MASK      (1 <<  1)
#define RISCV_SPI_SR_CHSIDE_MASK    (1 <<  2)
#define RISCV_SPI_SR_UDR_MASK       (1 <<  5)
#define RISCV_SPI_SR_CRCERR_MASK    (1 <<  6)
#define RISCV_SPI_SR_MODF_MASK      (1 <<  7)
#define RISCV_SPI_SR_OVR_MASK       (1 <<  7)
#define RISCV_SPI_SR_BSY_MASK       (1 <<  7)

struct riscv_spi {
    void __iomem *base;
    int irq;
    int len;
    int count;
    int bytes_per_word;
    unsigned long cr1;
    unsigned long cr2;
    bool dma_ie;

    /* data buffers */
    const unsigned char *tx;
    unsigned char *rx;
};

static void riscv_spi_tx_word(struct riscv_spi* spi) {
    uint16_t txd = 0xffff;
    if (spi->tx) {
        txd = spi->tx[spi->count];
    }

    writel(txd, spi->base + RISCV_SPI_DR);
}

static void riscv_spi_rx_word(struct riscv_spi* spi) {
    uint16_t rxd = readl(spi->base + RISCV_SPI_DR);
    if (spi->rx) {
        spi->rx[spi->count] = rxd;
    }
}

static int riscv_spi_transfer_one(struct spi_master *master,
                                  struct spi_device *spi, struct spi_transfer *t) {
    struct riscv_spi *rvspi = spi_master_get_devdata(spi->master);
    rvspi->tx = t->tx_buf;
    rvspi->rx = t->rx_buf;
    if (rvspi->irq && t->len >= 0x80) {
        while (readl(rvspi->base + RISCV_DMA_CON) >> 31)
            cpu_relax();
        writel(rvspi->tx ? (int) virt_to_phys(rvspi->tx) : -1, rvspi->base + RISCV_DMA_SRC);
        writel(rvspi->rx ? (int) virt_to_phys(rvspi->rx) :  0, rvspi->base + RISCV_DMA_DEST);
        writel(t->len, rvspi->base + RISCV_DMA_LEN);
        writel(1, rvspi->base + RISCV_DMA_IC);
        writel(1, rvspi->base + RISCV_DMA_IE);
        writel(SIZE_WORD                            << 10 | // dest size
               SIZE_WORD                            <<  8 | // src size
               (rvspi->rx ? TYPE_INCR : TYPE_CONST) <<  6 | // dest type
               (rvspi->tx ? TYPE_INCR : TYPE_CONST) <<  4 | // src type
               0                                    <<  1 | // bypass spi
               1, rvspi->base + RISCV_DMA_CON);
        goto done;
    }
    for (rvspi->count = 0; rvspi->count < t->len; rvspi->count += 1) {
        while (!(readl(rvspi->base + RISCV_SPI_SR) & RISCV_SPI_SR_TXE_MASK))
            cpu_relax();
        riscv_spi_tx_word(rvspi);
        while (!(readl(rvspi->base + RISCV_SPI_SR) & RISCV_SPI_SR_RXNE_MASK))
            cpu_relax();
        riscv_spi_rx_word(rvspi);
    }
    spi_finalize_current_transfer(master);

done:
    return t->len;
}

static void riscv_spi_set_cs(struct spi_device *spi, bool is_high) {
    struct riscv_spi *rvspi = spi_master_get_devdata(spi->master);
    if (is_high) {
        if (rvspi->cr2 & RISCV_SPI_CR2_SSOE_MASK) {
            rvspi->cr2 &= ~RISCV_SPI_CR2_SSOE_MASK;
            writel(rvspi->cr2, rvspi->base + RISCV_SPI_CR2);
        }
    } else {
        if (!(rvspi->cr2 & RISCV_SPI_CR2_SSOE_MASK)) {
            rvspi->cr2 |= RISCV_SPI_CR2_SSOE_MASK;
            writel(rvspi->cr2, rvspi->base + RISCV_SPI_CR2);
        }
    }
}

static irqreturn_t riscv_spi_irq(int irq, void *dev) {
    struct spi_master *master = dev;
    struct riscv_spi *rvspi = spi_master_get_devdata(master);

    if (readl(rvspi->base + RISCV_DMA_IP) & readl(rvspi->base + RISCV_DMA_IE)) {
        writel(0, rvspi->base + RISCV_DMA_IE);
        spi_finalize_current_transfer(master);
    }
    return IRQ_HANDLED;
}

static int riscv_spi_probe(struct platform_device *pdev) {
    struct riscv_spi *spi;
    struct spi_master *master;
    struct resource *res;
    int err;

    master = spi_alloc_master(&pdev->dev, sizeof(struct riscv_spi));
    if (!master)
        return -ENODEV;

    /* setup the master state. */
    master->bus_num = pdev->id;
    master->num_chipselect = 16;
    master->mode_bits = SPI_CS_HIGH;
    master->bits_per_word_mask = SPI_BPW_RANGE_MASK(1, 16);
    master->dev.of_node = pdev->dev.of_node;
    master->transfer_one = riscv_spi_transfer_one;
    master->set_cs = riscv_spi_set_cs;

    spi = spi_master_get_devdata(master);

    /* find and map our resources */
    res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    spi->base = devm_ioremap_resource(&pdev->dev, res);
    if (IS_ERR(spi->base)) {
        err = PTR_ERR(spi->base);
        goto exit;
    }

    /* initialize control register status */
    spi->cr1 = RISCV_SPI_CR1_MSTR_MASK;
    spi->cr2 = RISCV_SPI_CR2_SSOE_MASK;

    /* enable spi */
    spi->cr1 &= ~RISCV_SPI_CR1_SPE_MASK;
    writel(spi->cr1, spi->base + RISCV_SPI_CR1);
    spi->cr1 &= ~(RISCV_SPI_CR1_BR_MASK|
                  RISCV_SPI_CR1_LSBF_MASK|
                  RISCV_SPI_CR1_DFF_MASK|
                  RISCV_SPI_CR1_DEL_MASK);
    spi->cr1 |= // RISCV_SPI_CR1_DEL_MASK |
                (2 << RISCV_SPI_CR1_BR_SFT) |
                RISCV_SPI_CR1_SPE_MASK;
    writel(spi->cr1, spi->base + RISCV_SPI_CR1);

    /* disable spi interrupts */
    spi->cr2 &= ~(RISCV_SPI_CR2_TXEIE_MASK|
                  RISCV_SPI_CR2_RXNEIE_MASK|
                  RISCV_SPI_CR2_ERRORIE_MASK);
    writel(spi->cr2, spi->base + RISCV_SPI_CR2);

    spi->dma_ie = 0;
    writel(spi->dma_ie, spi->base + RISCV_DMA_IE);

    /* flush rxdata */
    readl(spi->base + RISCV_SPI_DR);

    /* irq is optional */
    spi->irq = platform_get_irq(pdev, 0);
    if (spi->irq > 0) {
        err = devm_request_irq(&pdev->dev, spi->irq, riscv_spi_irq, 0,
                       pdev->name, master);
        if (err)
            goto exit;
    }
    else spi->irq = 0;

    err = devm_spi_register_master(&pdev->dev, master);
    if (err)
        goto exit;
    dev_info(&pdev->dev, "base %p, irq %d\n", spi->base, spi->irq);

    return 0;
exit:
    spi_master_put(master);
    return err;
}

static const struct of_device_id riscv_spi_match[] = {
    { .compatible = "riscv,spi0", },
    {},
};
MODULE_DEVICE_TABLE(of, riscv_spi_match);

static struct platform_driver riscv_spi_driver = {
    .probe = riscv_spi_probe,
    .driver = {
        .name = DRV_NAME,
        .pm = NULL,
        .of_match_table = of_match_ptr(riscv_spi_match),
    },
};
module_platform_driver(riscv_spi_driver);

MODULE_DESCRIPTION("RISCV SPI driver");
MODULE_AUTHOR("Yutong Shen <yutongshen213@gmail.com>");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:" DRV_NAME);