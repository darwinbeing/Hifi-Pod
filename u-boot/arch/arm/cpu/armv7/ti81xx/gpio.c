/*
 * Copyright (c) 2009 Wind River Systems, Inc.
 * Tom Rix <Tom.Rix@windriver.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 *
 * This work is derived from the linux 2.6.27 kernel source
 * To fetch, use the kernel repository
 * git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux-2.6.git
 * Use the v2.6.27 tag.
 *
 * Below is the original's header including its copyright
 *
 *  linux/arch/arm/plat-omap/gpio.c
 *
 * Support functions for AM335X GPIO
 *
 * Copyright (C) 2003-2005 Nokia Corporation
 * Written by Juha Yrjölä <juha.yrjola@nokia.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <common.h>
#include <asm/arch/gpio.h>
#include <asm/io.h>
#include <asm/errno.h>

#define AM335X_GPIO_DIR_OUT	0
#define AM335X_GPIO_DIR_IN	1


static const struct gpio_bank gpio_bank_335x[4] = {
	{ (void *)AM335X_GPIO1_BASE },
	{ (void *)AM335X_GPIO2_BASE },
	{ (void *)AM335X_GPIO3_BASE },
	{ (void *)AM335X_GPIO4_BASE },
};

const struct gpio_bank *const g_pgpio_bank = gpio_bank_335x;


static inline const struct gpio_bank *get_gpio_bank(int gpio)
{
	return &gpio_bank_335x[gpio >> 5];
}

static inline int get_gpio_index(int gpio)
{
	return gpio & 0x1f;
}

static inline int gpio_valid(int gpio)
{
	if (gpio < 0)
		return -EINVAL;
	if (gpio < 192)
		return 0;
	return -EINVAL;
}

static int check_gpio(int gpio)
{
	if (gpio_valid(gpio) < 0) {
		printf("ERROR : check_gpio: invalid GPIO %d\n", gpio);
		return -EINVAL;
	}
	return 0;
}

static void _set_gpio_direction(const struct gpio_bank *bank, int gpio,
				int is_input)
{
	void *reg = bank->base;
	u32 l;


	reg += AM335X_GPIO_OE;

	l = __raw_readl(reg);

	if (is_input)
		l |= 1 << gpio;
	else
		l &= ~(1 << gpio);

	__raw_writel(l, reg);
}

/**
 * Get the direction of the GPIO by reading the GPIO_OE register
 * corresponding to the specified bank.
 */
static int _get_gpio_direction(const struct gpio_bank *bank, int gpio)
{
	void *reg = bank->base;
	u32 v;

	reg += AM335X_GPIO_OE;

	v = __raw_readl(reg);
	if (v & (1 << gpio))
		return AM335X_GPIO_DIR_IN;
	else
		return AM335X_GPIO_DIR_OUT;
}

static void _set_gpio_dataout(const struct gpio_bank *bank, int gpio,
				int enable)
{
	void *reg = bank->base;
	u32 l = 0;

	if (enable)
	    reg += AM335X_GPIO_SETDATAOUT;
	else
	    reg += AM335X_GPIO_CLEARDATAOUT;
	l = 1 << gpio;

	__raw_writel(l, reg);
}

/**
 * Set value of the specified gpio
 */
void gpio_set_value(int gpio, int value)
{
	const struct gpio_bank *bank;

	if (check_gpio(gpio) < 0)
		return;
	bank = get_gpio_bank(gpio);
	_set_gpio_dataout(bank, get_gpio_index(gpio), value);
}

/**
 * Get value of the specified gpio
 */
int gpio_get_value(int gpio)
{
	const struct gpio_bank *bank;
	void *reg;
	int input;

	if (check_gpio(gpio) < 0)
		return -EINVAL;
	bank = get_gpio_bank(gpio);
	reg = bank->base;
	input = _get_gpio_direction(bank, get_gpio_index(gpio));
	switch (input) {
	case AM335X_GPIO_DIR_IN:
	    reg += AM335X_GPIO_DATAIN;
	    break;
	case AM335X_GPIO_DIR_OUT:
	    reg += AM335X_GPIO_DATAOUT;
	    break;
	default:
	    return -EINVAL;
	}
	return (__raw_readl(reg)
			& (1 << get_gpio_index(gpio))) != 0;
}

/**
 * Set gpio direction as input
 */
int gpio_direction_input(unsigned gpio)
{
	const struct gpio_bank *bank;

	if (check_gpio(gpio) < 0)
		return -EINVAL;

	bank = get_gpio_bank(gpio);
	_set_gpio_direction(bank, get_gpio_index(gpio), 1);

	return 0;
}

/**
 * Set gpio direction as output
 */
int gpio_direction_output(unsigned gpio, int value)
{
	const struct gpio_bank *bank;

	if (check_gpio(gpio) < 0)
		return -EINVAL;

	bank = get_gpio_bank(gpio);
	_set_gpio_dataout(bank, get_gpio_index(gpio), value);
	_set_gpio_direction(bank, get_gpio_index(gpio), 0);

	return 0;
}

/**
 * Request a gpio before using it.
 *
 * NOTE: Argument 'label' is unused.
 */
int gpio_request(int gpio, const char *label)
{

	if (check_gpio(gpio) < 0)
		return -EINVAL;

	return 0;
}

/**
 * Reset and free the gpio after using it.
 */
void gpio_free(unsigned gpio)
{
	const struct gpio_bank *bank;

	if (check_gpio(gpio) < 0)
		return;
	bank = get_gpio_bank(gpio);

	_set_gpio_direction(bank, get_gpio_index(gpio), 1);
}
