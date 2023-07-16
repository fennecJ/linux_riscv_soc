#include <linux/interrupt.h>
#include <linux/errno.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/io.h>
#include <linux/of.h>
#include "dbg-riscv.h"

#define DRV_NAME "dbg_riscv"

#define DBGMON_PKG        0x0000
#define DBGMON_PC         0x1000
#define DBGMON_X1         0x1008
#define DBGMON_X2         0x1010
#define DBGMON_X3         0x1018
#define DBGMON_X4         0x1020
#define DBGMON_X5         0x1028
#define DBGMON_X6         0x1030
#define DBGMON_X7         0x1038
#define DBGMON_X8         0x1040
#define DBGMON_X9         0x1048
#define DBGMON_X10        0x1050
#define DBGMON_X11        0x1058
#define DBGMON_X12        0x1060
#define DBGMON_X13        0x1068
#define DBGMON_X14        0x1070
#define DBGMON_X15        0x1078
#define DBGMON_X16        0x1080
#define DBGMON_X17        0x1088
#define DBGMON_X18        0x1090
#define DBGMON_X19        0x1098
#define DBGMON_X20        0x10a0
#define DBGMON_X21        0x10a8
#define DBGMON_X22        0x10b0
#define DBGMON_X23        0x10b8
#define DBGMON_X24        0x10c0
#define DBGMON_X25        0x10c8
#define DBGMON_X26        0x10d0
#define DBGMON_X27        0x10d8
#define DBGMON_X28        0x10e0
#define DBGMON_X29        0x10e8
#define DBGMON_X30        0x10f0
#define DBGMON_X31        0x10f8
#define DBGMON_BP0        0x1100
#define DBGMON_BP1        0x1108
#define DBGMON_BP2        0x1110
#define DBGMON_BP3        0x1118
#define DBGMON_WP0        0x1120
#define DBGMON_WP1        0x1128
#define DBGMON_WP2        0x1130
#define DBGMON_WP3        0x1138
#define DBGMON_VC_EXC     0x1140
#define DBGMON_VC_IRQ     0x1144
#define DBGMON_DELAY      0x1148
#define DBGMON_STOP_TRACE 0x114c
#define DBGMON_IE         0x1150

struct riscv_dbg {
    void __iomem *base;
    int irq;
    dev_t devid;
    struct cdev cdev;
    struct device *dev;
    struct class *class;
};

struct riscv_dbg *dbgmon = NULL;

static void riscv_dbg_show_info(unsigned long data) {
    struct riscv_dbg *dev = *(struct riscv_dbg **)data;
    struct trace_package *pkgs = dev->base;
    int i;
    char buf[1024];

    for (i = 0; i < 128; i++) {
        tracer_decode(buf, pkgs++);
        printk(KERN_INFO "%s\n", buf);
    }

    writel(0, dev->base + DBGMON_STOP_TRACE);
    writel(1, dev->base + DBGMON_IE);

}

//static DECLARE_TASKLET(riscv_dbg_tasklet, riscv_dbg_show_info, (unsigned long)&dbgmon);

static DECLARE_TASKLET_OLD(riscv_dbg_tasklet, riscv_dbg_show_info);

static irqreturn_t riscv_dbg_irq(int irq, void *data) {
    struct riscv_dbg *dev = data;

    writel(0, dev->base + DBGMON_IE);
    tasklet_schedule(&riscv_dbg_tasklet);
    return IRQ_HANDLED;
}

static ssize_t dbg_read(struct file *filp, char __user *buf, size_t size, loff_t *ppos)
{
    uint32_t cnt = 0;
    uint32_t ret = 0;
    char msg[1024] = "";
    int64_t bp0, bp1, bp2, bp3, wp0, wp1, wp2, wp3;
    uint32_t exc, irq, dly;

    if (*ppos) return 0;

    bp0 = readq(dbgmon->base + DBGMON_BP0);
    bp1 = readq(dbgmon->base + DBGMON_BP1);
    bp2 = readq(dbgmon->base + DBGMON_BP2);
    bp3 = readq(dbgmon->base + DBGMON_BP3);
    wp0 = readq(dbgmon->base + DBGMON_WP0);
    wp1 = readq(dbgmon->base + DBGMON_WP1);
    wp2 = readq(dbgmon->base + DBGMON_WP2);
    wp3 = readq(dbgmon->base + DBGMON_WP3);
    exc = readl(dbgmon->base + DBGMON_VC_EXC);
    irq = readl(dbgmon->base + DBGMON_VC_IRQ);
    dly = readl(dbgmon->base + DBGMON_DELAY);

    if (bp0 < 0) cnt += sprintf(msg + cnt, "break point 0: 0x%08llx\n", bp0 << 1 >> 1);
    else         cnt += sprintf(msg + cnt, "break point 0: NA\n");
    if (bp1 < 0) cnt += sprintf(msg + cnt, "break point 1: 0x%08llx\n", bp1 << 1 >> 1);
    else         cnt += sprintf(msg + cnt, "break point 1: NA\n");
    if (bp2 < 0) cnt += sprintf(msg + cnt, "break point 2: 0x%08llx\n", bp2 << 1 >> 1);
    else         cnt += sprintf(msg + cnt, "break point 2: NA\n");
    if (bp3 < 0) cnt += sprintf(msg + cnt, "break point 3: 0x%08llx\n", bp3 << 1 >> 1);
    else         cnt += sprintf(msg + cnt, "break point 3: NA\n");

    if (wp0 < 0) cnt += sprintf(msg + cnt, "watch point 0: 0x%08llx\n", wp0 << 1 >> 1);
    else         cnt += sprintf(msg + cnt, "watch point 0: NA\n");
    if (wp1 < 0) cnt += sprintf(msg + cnt, "watch point 1: 0x%08llx\n", wp1 << 1 >> 1);
    else         cnt += sprintf(msg + cnt, "watch point 1: NA\n");
    if (wp2 < 0) cnt += sprintf(msg + cnt, "watch point 2: 0x%08llx\n", wp2 << 1 >> 1);
    else         cnt += sprintf(msg + cnt, "watch point 2: NA\n");
    if (wp3 < 0) cnt += sprintf(msg + cnt, "watch point 3: 0x%08llx\n", wp3 << 1 >> 1);
    else         cnt += sprintf(msg + cnt, "watch point 3: NA\n");

    cnt += sprintf(msg + cnt, "vector catch 0:%s\n", exc ? "" : " NA");
    if (exc & (1 <<  0)) cnt += sprintf(msg + cnt, "  [ 0] insn misaligned\n");
    if (exc & (1 <<  1)) cnt += sprintf(msg + cnt, "  [ 1] insn access fault\n");
    if (exc & (1 <<  2)) cnt += sprintf(msg + cnt, "  [ 2] illegal insn\n");
    if (exc & (1 <<  3)) cnt += sprintf(msg + cnt, "  [ 3] breakpoint\n");
    if (exc & (1 <<  4)) cnt += sprintf(msg + cnt, "  [ 4] load misaligned\n");
    if (exc & (1 <<  5)) cnt += sprintf(msg + cnt, "  [ 5] load access fault\n");
    if (exc & (1 <<  6)) cnt += sprintf(msg + cnt, "  [ 6] store/amo misaligned\n");
    if (exc & (1 <<  7)) cnt += sprintf(msg + cnt, "  [ 7] store/amo access fault\n");
    if (exc & (1 <<  8)) cnt += sprintf(msg + cnt, "  [ 8] U-mode ecall\n");
    if (exc & (1 <<  9)) cnt += sprintf(msg + cnt, "  [ 9] S-mode ecall\n");
    if (exc & (1 << 11)) cnt += sprintf(msg + cnt, "  [11] M-mode ecall\n");
    if (exc & (1 << 12)) cnt += sprintf(msg + cnt, "  [12] insn page fault\n");
    if (exc & (1 << 13)) cnt += sprintf(msg + cnt, "  [13] load page fault\n");
    if (exc & (1 << 15)) cnt += sprintf(msg + cnt, "  [15] store/amo page fault\n");

    cnt += sprintf(msg + cnt, "vector catch 1:%s\n", irq ? "" : " NA");
    if (irq & (1 <<  1)) cnt += sprintf(msg + cnt, "  [ 1] SSIP\n");
    if (irq & (1 <<  3)) cnt += sprintf(msg + cnt, "  [ 3] MSIP\n");
    if (irq & (1 <<  5)) cnt += sprintf(msg + cnt, "  [ 5] STIP\n");
    if (irq & (1 <<  7)) cnt += sprintf(msg + cnt, "  [ 7] MTIP\n");
    if (irq & (1 <<  9)) cnt += sprintf(msg + cnt, "  [ 9] SEIP\n");
    if (irq & (1 << 11)) cnt += sprintf(msg + cnt, "  [11] MEIP\n");

    cnt += sprintf(msg + cnt, "stop delay: %d\n", dly);

    cnt = size < cnt ? size : cnt;
    cnt = cnt < 1024 ? cnt  : 1024;
    *ppos = cnt;

    if (copy_to_user(buf, msg, cnt))
        ret = -EFAULT;
    else
        ret = cnt;

    return ret;
}

static char *split(char **ptr) {
    char *cur, *res;
    res = cur = *ptr;
    for (; **ptr && **ptr != ' ' && **ptr != '\n'; ++*ptr) **ptr |= 1 << 5;
    while (**ptr == ' ' || **ptr == '\n') {
        **ptr = '\0';
        ++*ptr;
    }
    return *res ? res : NULL;
}

static ssize_t dbg_write(struct file *file, const char __user *buf,
                    size_t size, loff_t * offset) {
    char msg[1024] = "";
    char *item, *val_str, *ptr;
    int i = 0, cnt;
    int64_t val = 0, en = 0;

    printk(KERN_INFO "Enter into dbg_write\n");

    cnt = size < 1024 ? size : 1024;
    if (copy_from_user(msg, buf, cnt))
        return -EFAULT;

    printk(KERN_INFO "%s\n", msg);

    ptr = msg;
    while (*ptr == ' ') ptr++;
    while (!!(item = split(&ptr)) && !!(val_str = split(&ptr))) {
        if (strcmp(val_str, "no")) {
            en = 1;
            val = simple_strtoull(val_str, NULL, 0);
        }

        if (!(strcmp(item, "bp0")))      writeq(en << 63 | val, dbgmon->base + DBGMON_BP0);
        else if (!(strcmp(item, "bp1"))) writeq(en << 63 | val, dbgmon->base + DBGMON_BP1);
        else if (!(strcmp(item, "bp2"))) writeq(en << 63 | val, dbgmon->base + DBGMON_BP2);
        else if (!(strcmp(item, "bp3"))) writeq(en << 63 | val, dbgmon->base + DBGMON_BP3);
        else if (!(strcmp(item, "wp0"))) writeq(en << 63 | val, dbgmon->base + DBGMON_WP0);
        else if (!(strcmp(item, "wp1"))) writeq(en << 63 | val, dbgmon->base + DBGMON_WP1);
        else if (!(strcmp(item, "wp2"))) writeq(en << 63 | val, dbgmon->base + DBGMON_WP2);
        else if (!(strcmp(item, "wp3"))) writeq(en << 63 | val, dbgmon->base + DBGMON_WP3);
        else if (!(strcmp(item, "vc0"))) writel(val, dbgmon->base + DBGMON_VC_EXC);
        else if (!(strcmp(item, "vc1"))) writel(val, dbgmon->base + DBGMON_VC_IRQ);
        else if (!(strcmp(item, "dly"))) writel(val, dbgmon->base + DBGMON_DELAY);

        i++;
        if (i > 100) break;
    }
    
    return cnt;
}

static int dbg_open(struct inode *inode, struct file *filp) {
    return 0;
}

static int dbg_release(struct inode *inode, struct file *filp) {
    return 0;
}

static const struct file_operations dbg_fops =
{
    .owner = THIS_MODULE,
    .read = dbg_read,
    .write = dbg_write,
    .open = dbg_open,
    .release = dbg_release,
};

static int riscv_dbg_probe(struct platform_device *pdev) {
    struct riscv_dbg *dev;
    struct resource *res;
    int ret;


    dev = kzalloc(sizeof(struct riscv_dbg), GFP_KERNEL);
    if (!dev)
        return -ENOMEM;

    /* find and map our resources */
    res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    dev->base = devm_ioremap_resource(&pdev->dev, res);
    if (IS_ERR(dev->base)) {
        ret = PTR_ERR(dev->base);
        goto alloc_fail;
    }

    dev->irq = platform_get_irq(pdev, 0);
    if (dev->irq <= 0) {
        ret = -ENODEV;
        goto alloc_fail;
    }

    dbgmon = dev;
    
    ret = devm_request_irq(&pdev->dev, dev->irq, riscv_dbg_irq, 0,
                   pdev->name, dev);
    if (ret)
        goto alloc_fail;

    platform_set_drvdata(pdev, dev);

    ret = alloc_chrdev_region(&dev->devid, 0, 1, "dbgmon");
    if (ret < 0)
        goto alloc_fail;

    dev->class = class_create(THIS_MODULE, "chardrv");
    if (IS_ERR(dev->class)) {
        ret = PTR_ERR(dev->class);
        goto class_fail;
    }
    
    dev->dev = device_create(dev->class, NULL, dev->devid, NULL, "dbgmon");
    if (IS_ERR(dev->dev)) {
        ret = PTR_ERR(dev->dev);
        goto dev_fail;
    }

    cdev_init(&dev->cdev, &dbg_fops);
    ret = cdev_add(&dev->cdev, dev->devid, 1);
    if (ret < 0)
        goto cdev_fail;

    writel(1, dev->base + DBGMON_IE);
    dev_info(&pdev->dev, "base %p, irq %d\n", dev->base, dev->irq);

    return 0;

cdev_fail:
    device_destroy(dev->class, dev->devid);
dev_fail:
    class_destroy(dev->class);
class_fail:
    unregister_chrdev_region(dev->devid, 1);
alloc_fail:
    kfree(dev);
    return ret;
}

static int riscv_dbg_remove(struct platform_device *pdev) {
    struct riscv_dbg *dev = platform_get_drvdata(pdev);

    cdev_del(&dev->cdev);
    device_destroy(dev->class, dev->devid);
    class_destroy(dev->class);
    unregister_chrdev_region(dev->devid, 1);
    kfree(dev);
    return 0;
}

static const struct of_device_id riscv_dbg_match[] = {
    { .compatible = "riscv,dbgmon", },
    {},
};
MODULE_DEVICE_TABLE(of, riscv_dbg_match);

static struct platform_driver riscv_dbg_driver = {
    .probe = riscv_dbg_probe,
    .remove = riscv_dbg_remove,
    .driver = {
        .name = DRV_NAME,
        .of_match_table = of_match_ptr(riscv_dbg_match),
    },
};
module_platform_driver(riscv_dbg_driver);

MODULE_DESCRIPTION("RISCV debug driver");
MODULE_AUTHOR("Yutong Shen <yutongshen213@gmail.com>");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:" DRV_NAME);