/*
 * driver_interrupt.c
 *
 *  Created on: 2022. 4. 6.
 *      Author: 82107
 */
#include "driver.h"

void irq_ctl(uint8_t irq_number, uint8_t flag)
{
	uint8_t offset1 = irq_number / 32;
	uint8_t offset2 = irq_number % 32;



	if(flag == SET)
	{
		*((volatile uint32_t *)(NVIC_ISER + 0X4 * offset1)) |= 1 << offset2;
	}
	else
	{
		*((volatile uint32_t *)(NVIC_ICER + 0X4 * offset1)) |= 1 << offset2;
	}
}

void irq_prio_config(uint8_t irq_number, uint8_t prio)
{
	uint8_t offset1 = irq_number / 4;
	uint8_t offset2 = irq_number % 4;

	*(volatile uint32_t *)(NVIC_IPR + 0X4 * offset1) |= 1 << (8 * offset2 + 4);
}
