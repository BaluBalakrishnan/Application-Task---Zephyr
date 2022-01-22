//LIS2DH ACCELEROMETER SENSOR X,Y,Z AXIS

/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr.h>
#include <sys/printk.h>
#include <kernel.h>
#include<init.h>
#define I2C_ADDR 			0X19
#define LIS2DH_CHIP_ID                  0x33
#define x  6.14
#define y -3.18
#define z  0.12

static struct k_timer my_timer;
static int my_timer_handler(struct k_timer *dummy)
{
	float temp[3];
	temp[0] = x/100000;
	temp[1] = y/100000;
	temp[2] = z/100000;
	printk("\nk_uptime_get_ time : %lld \n",k_uptime_get());
	printk("\nx-axis val :%f\t", k_uptime_get()*temp[0]);
	printk("y-axis val :%f\t", k_uptime_get()*temp[1]);
	printk("z-axis val :%f\n", k_uptime_get()*temp[2]);
}

void fun(void)
{
	printk("\ni2c address : 0x%x",I2C_ADDR);
	printk("\nlis2dh sensor address : 0x%x\n",LIS2DH_CHIP_ID);
	/* (Address of timer, Handler, stop function) */
	k_timer_init(&my_timer, my_timer_handler, NULL);
	/* (Address of timer, Initial timer duration, Timer period ) */
	k_timer_start(&my_timer, K_SECONDS(3), K_MSEC(1000));
}

SYS_INIT(fun, APPLICATION, 3);
