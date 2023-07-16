/*
 * Toggles a GPIO pin to restart a device
 *
 * Copyright (C) 2014 Google, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Based on the gpio-poweroff driver.
 */
#include <linux/reboot.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/of_platform.h>
#include <linux/module.h>

#define DRV_NAME "pwrcon_riscv"
#define CFGREG_RSTN      0x000
#define CFGREG_BOOTVEC   0x004
#define CFGREG_DDROFFSET 0x008
#define CFGREG_RSVREG0   0x010
#define CFGREG_RSVREG1   0x014
#define CFGREG_VER       0x018

struct riscv_pwrcon {
    void __iomem  *base;
    struct device *dev;
    struct notifier_block restart_handler;
};

struct riscv_pwrcon *pwrcon = NULL;

static void riscv_pwrcon_reg_set(struct riscv_pwrcon *dev, size_t offset, uint32_t data) {
    writel(readl(dev->base + offset) | data, dev->base + offset);
}

static void riscv_pwrcon_reg_write(struct riscv_pwrcon *dev, size_t offset, uint32_t data) {
    writel(data, dev->base + offset);
}

static void riscv_pwrcon_poweroff(void) {
    riscv_pwrcon_reg_write(pwrcon, CFGREG_RSTN, 0);
    WARN_ON(1);
}

static int riscv_pwrcon_notify(struct notifier_block *this,
                               unsigned long mode, void *cmd) {
    struct riscv_pwrcon *dev = container_of(this, struct riscv_pwrcon, restart_handler);
    riscv_pwrcon_reg_set(dev, CFGREG_RSTN, 1 << 31);
    while (1);
    WARN_ON(1);

    return NOTIFY_DONE;
}

static int riscv_pwrcon_probe(struct platform_device *pdev) {
    struct riscv_pwrcon *dev;
    struct resource *mem;
    int ret;
    
    if (pwrcon) {
        dev_err(&pdev->dev, "%s: riscv_pwrcon already registered",
               __func__);
        return -EBUSY;
    }

    dev = devm_kzalloc(&pdev->dev, sizeof(struct riscv_pwrcon), GFP_KERNEL);
    if (unlikely(!dev))
        return -ENOMEM;

    mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    dev->base = devm_ioremap_resource(&pdev->dev, mem);
    if (IS_ERR(dev->base)) {
        dev_err(&pdev->dev, "could not acquire device memory\n");
        return PTR_ERR(dev->base);
    }

    dev->restart_handler.notifier_call = riscv_pwrcon_notify;
    dev->restart_handler.priority = 129;

    platform_set_drvdata(pdev, dev);

    // register restart
    ret = register_restart_handler(&dev->restart_handler);
    if (ret) {
        dev_err(&pdev->dev, "%s: cannot register restart handler, %d\n",
                __func__, ret);
        return -ENODEV;
    }

    pwrcon = dev;

    // register power off
    // if (pm_power_off != NULL) {
    //     dev_err(&pdev->dev, "%s: pm_power_off function already registered",
    //            __func__);
    //     return 0;
    // }

    pm_power_off = &riscv_pwrcon_poweroff;

    return 0;
}

static int riscv_pwrcon_remove(struct platform_device *pdev) {
    struct riscv_pwrcon *dev = platform_get_drvdata(pdev);
    int ret;

    ret = unregister_restart_handler(&dev->restart_handler);
    if (ret) {
        dev_err(&pdev->dev, "%s: cannot unregister restart handler, %d\n",
                __func__, ret);
        return -ENODEV;
    }
    pwrcon = NULL;
    if (pm_power_off == &riscv_pwrcon_poweroff) {
        pm_power_off = NULL;
    }

    return 0;
}

static const struct of_device_id of_riscv_pwrcon_match[] = {
    { .compatible = "riscv,cfgreg", },
    {},
};

static struct platform_driver riscv_pwrcon_driver = {
    .probe = riscv_pwrcon_probe,
    .remove = riscv_pwrcon_remove,
    .driver = {
        .name = DRV_NAME,
        .of_match_table = of_riscv_pwrcon_match,
    },
};

module_platform_driver(riscv_pwrcon_driver);

MODULE_DESCRIPTION("RISCV power control driver");
MODULE_AUTHOR("Yutong Shen <yutongshen213@gmail.com>");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:" DRV_NAME);