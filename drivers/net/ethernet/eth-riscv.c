#include <linux/platform_device.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/io.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/inetdevice.h>

#define DRV_NAME "eth_riscv"

#define ETH_RG_RESET 0x00
#define ETH_RG_TXLEN 0x04
#define ETH_RG_TXFIFO 0x08
#define ETH_RG_TXCTRL 0x0C
#define ETH_RG_TXDIS 0x10
#define ETH_RG_RXLEN 0x14
#define ETH_RG_RXFIFO 0x18
#define ETH_RG_RXCTRL 0x1C
#define ETH_RG_RXDIS 0x20
#define ETH_RG_IE 0x24
#define ETH_RG_IP 0x28
#define ETH_RG_IC 0x2C
#define ETH_RG_MAC0 0x30
#define ETH_RG_MAC1 0x34

#define MAX_ETH_FRAME_SIZE   1792
#define TX_RETRY 1000

struct riscv_eth_priv {
    void __iomem  *base;
    struct device *dev;
    spinlock_t     rx_lock;
    spinlock_t     tx_lock;
    bool           irq_dis;
};

static struct net_device *riscv_netdev;

#if (0)
static void dump(unsigned char *buf)
{
    unsigned char *p, sbuf[2*(sizeof(struct ethhdr) + sizeof(struct iphdr))];
    int i;
    p = sbuf;

    for(i = 0; i < sizeof(struct ethhdr); i++) {
        p += sprintf(p, "%02X ", buf[i]);
    }
    printk("eth %s\n", sbuf);

    p = sbuf;
    for(i = 0; i < sizeof(struct iphdr); i++) {
        p += sprintf(p, "%02X ", buf[sizeof(struct ethhdr) + i]);
    }
    printk("iph %s\n", sbuf);

    p = sbuf;
    for(i = 0; i < 4; i++) {
        p += sprintf(p, "%02X ", buf[sizeof(struct ethhdr) + sizeof(struct iphdr) + i]);
    }
    printk("payload %s\n", sbuf);
}
#endif

static void riscv_eth_reg_set(struct net_device *dev, size_t offset, uint32_t data) {
    struct riscv_eth_priv *priv = netdev_priv(dev);
    writel(readl(priv->base + offset) | data, priv->base + offset);
}

static void riscv_eth_reg_clr(struct net_device *dev, size_t offset, uint32_t data) {
    struct riscv_eth_priv *priv = netdev_priv(dev);
    writel(readl(priv->base + offset) & ~data, priv->base + offset);
}

static void riscv_eth_reg_write(struct net_device *dev, size_t offset, uint32_t data) {
    struct riscv_eth_priv *priv = netdev_priv(dev);
    writel(data, priv->base + offset);
}

static uint32_t riscv_eth_reg_read(struct net_device *dev, size_t offset) {
    struct riscv_eth_priv *priv = netdev_priv(dev);
    return readl(priv->base + offset);
}

static void riscv_eth_rx(unsigned long data) {
    struct net_device *dev = *(struct net_device **)data;
    struct riscv_eth_priv *priv = netdev_priv(dev);
    struct sk_buff *skb;
    uint32_t len, *ptr, i, tmp;
    // uint8_t *ptr;

    spin_lock(&priv->rx_lock);
    while (!!(len = riscv_eth_reg_read(dev, ETH_RG_RXLEN))) {
        skb = dev_alloc_skb(len + 4);
        if (!skb) {
            dev_err(priv->dev, "%s(#%d), rx: low on mem - packet dropped\n", __func__, __LINE__);
            dev->stats.rx_dropped++;
            goto rx_exit;
        }
        skb_reserve(skb, 4); /* align IP on 32B boundary */
        ptr = skb_put(skb, len);
        for (i = 0; i < len; i += 4) {
            ptr[i/4] = riscv_eth_reg_read(dev, ETH_RG_RXFIFO);
            // tmp = riscv_eth_reg_read(dev, ETH_RG_RXFIFO);
            // ptr[i + 0] = (tmp >>  0) & 0xff;
            // ptr[i + 1] = (tmp >>  8) & 0xff;
            // ptr[i + 2] = (tmp >> 16) & 0xff;
            // ptr[i + 3] = (tmp >> 24) & 0xff;
        }
        riscv_eth_reg_write(dev, ETH_RG_RXDIS, 1);

        skb->dev = dev;
        skb->protocol = eth_type_trans(skb, dev);
        skb->ip_summed = CHECKSUM_UNNECESSARY;
        dev->stats.rx_packets++;
        dev->stats.rx_bytes += len;
        netif_rx(skb);
    }
rx_exit:
    spin_unlock(&priv->rx_lock);
    if (!priv->irq_dis) riscv_eth_reg_set(dev, ETH_RG_IE, 1 << 1);
}

//static DECLARE_TASKLET(riscv_eth_tasklet, riscv_eth_rx, (unsigned long)&riscv_netdev);
static DECLARE_TASKLET_OLD(riscv_eth_tasklet, riscv_eth_rx);

static irqreturn_t riscv_eth_irq(int irq, void *dev) {
    riscv_eth_reg_clr(dev, ETH_RG_IE, 1 << 1);
    tasklet_schedule(&riscv_eth_tasklet);
    return IRQ_HANDLED;
}

static int riscv_eth_open(struct net_device *dev) {
    struct riscv_eth_priv *priv = netdev_priv(dev);

    priv->irq_dis = 0;
    riscv_eth_reg_set(dev, ETH_RG_TXCTRL, 1);
    riscv_eth_reg_set(dev, ETH_RG_RXCTRL, 1);
    riscv_eth_reg_set(dev, ETH_RG_IE, 1 << 1);
    return 0;
}

static int riscv_eth_stop(struct net_device *dev) {
    struct riscv_eth_priv *priv = netdev_priv(dev);

    priv->irq_dis = 1;
    riscv_eth_reg_clr(dev, ETH_RG_TXCTRL, 1);
    riscv_eth_reg_clr(dev, ETH_RG_RXCTRL, 1);
    riscv_eth_reg_clr(dev, ETH_RG_IE, 1 << 1);
    return 0;
}

static netdev_tx_t riscv_eth_start_xmit(struct sk_buff *skb, struct net_device *dev) {
    struct riscv_eth_priv *priv = netdev_priv(dev);
    int len, retry, i;

    spin_lock(&priv->tx_lock);
    for (retry = TX_RETRY; riscv_eth_reg_read(dev, ETH_RG_RESET) >> 31 && retry; --retry);
    if (!retry) {
        dev->stats.tx_dropped++;
        dev->stats.tx_errors++;
        spin_unlock(&priv->tx_lock);
        return NETDEV_TX_BUSY;
    }
    len = skb->len < 60 ? 60 : skb->len;
    riscv_eth_reg_write(dev, ETH_RG_TXLEN, len);
    for (i = 0; i < skb->len; i += 4)
        riscv_eth_reg_write(dev, ETH_RG_TXFIFO, ((uint32_t *)skb->data)[i/4]);
    /* Padding */
    for (; i < 60; i += 4)
        riscv_eth_reg_write(dev, ETH_RG_TXFIFO, 0);
    spin_unlock(&priv->tx_lock);

    skb_tx_timestamp(skb);
    dev_kfree_skb_any(skb);
    dev->stats.tx_packets++;
    dev->stats.tx_bytes += len;

    return NETDEV_TX_OK;
}

static void riscv_eth_set_rx_mode(struct net_device *dev) {
    // dbg_info("Enter into riscv_eth_set_rx_mode.\n");
}

//static void riscv_eth_tx_timeout(struct net_device *dev) {
//    dbg_info("Enter into riscv_eth_tx_timeout.\n");
//}

// for kernel > 5.6, need another unsigned para
static void riscv_eth_tx_timeout(struct net_device *dev, unsigned int a) {
    dbg_info("Enter into riscv_eth_tx_timeout.\n");
}

int riscv_eth_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd) {
    dbg_info("Enter into riscv_eth_ioctl.\n");
    return 0;
}

static const struct net_device_ops riscv_eth_netdev_ops = {
    .ndo_open            = riscv_eth_open,
    .ndo_stop            = riscv_eth_stop,
    .ndo_start_xmit      = riscv_eth_start_xmit,
    .ndo_set_rx_mode     = riscv_eth_set_rx_mode,
    .ndo_tx_timeout      = riscv_eth_tx_timeout,
    .ndo_do_ioctl        = riscv_eth_ioctl,
    .ndo_validate_addr   = eth_validate_addr,
    .ndo_set_mac_address = eth_mac_addr,
};

static int riscv_eth_probe(struct platform_device *pdev) {
    struct net_device *dev;
    struct riscv_eth_priv *priv;
    struct resource *mem;
    void __iomem *base;
    int irq, r = 0;

    irq = platform_get_irq(pdev, 0);
    if (irq < 0)
        return -EPROBE_DEFER;

    mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    base = devm_ioremap_resource(&pdev->dev, mem);
    if (IS_ERR(base)) {
        dev_err(&pdev->dev, "could not acquire device memory\n");
        return PTR_ERR(base);
    }
    
    dev = devm_alloc_etherdev(&pdev->dev, sizeof(struct riscv_eth_priv));
    if (!dev)
        return -ENOMEM;

    SET_NETDEV_DEV(dev, &pdev->dev);
    priv = netdev_priv(dev);

    priv->base = base;
    priv->dev  = &pdev->dev;
    priv->irq_dis = 1;

    dev->irq   = irq;
    
    dev->netdev_ops = &riscv_eth_netdev_ops;

    *(int *)dev->dev_addr = riscv_eth_reg_read(dev, ETH_RG_MAC0);
    *(short *)(dev->dev_addr + 4) = riscv_eth_reg_read(dev, ETH_RG_MAC1);

    spin_lock_init(&priv->rx_lock);
    spin_lock_init(&priv->tx_lock);

    riscv_eth_reg_set(dev, ETH_RG_RESET, 1);
    r = request_irq(dev->irq, riscv_eth_irq, 0, dev_name(&pdev->dev), dev);
    if (r) {
        dev_err(&pdev->dev, "could not attach interrupt: %d\n", r);
        return r;
    }

    riscv_eth_reg_set(dev, ETH_RG_TXCTRL, 2 << 16);
    riscv_eth_reg_set(dev, ETH_RG_RXCTRL, 2 << 16);

    platform_set_drvdata(pdev, dev);
    r = register_netdev(dev);
    if (r < 0) {
        dev_err(&pdev->dev, "cannot register net device: %d\n", r);
    }

    riscv_netdev = dev;
    return r;
}

static int riscv_eth_remove(struct platform_device *pdev) {
    struct net_device *dev = platform_get_drvdata(pdev);
    unregister_netdev(dev);
    return 0;
}

static const struct of_device_id riscv_eth_match[] = {
    { .compatible = "riscv,eth0", },
    {},
};
MODULE_DEVICE_TABLE(of, riscv_eth_match);

static struct platform_driver riscv_eth_driver = {
    .probe = riscv_eth_probe,
    .remove = riscv_eth_remove,
    .driver = {
        .name = DRV_NAME,
        .of_match_table = of_match_ptr(riscv_eth_match),
    },
};
module_platform_driver(riscv_eth_driver);

MODULE_DESCRIPTION("RISCV Ethernet driver");
MODULE_AUTHOR("Yutong Shen <yutongshen213@gmail.com>");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:" DRV_NAME);