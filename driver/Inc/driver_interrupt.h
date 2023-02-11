/*
 * driver_interrupt.h
 *
 *  Created on: 2022. 4. 6.
 *      Author: 82107
 */

#ifndef INC_DRIVER_INTERRUPT_H_
#define INC_DRIVER_INTERRUPT_H_
#include "driver.h"

#define NVIC_ISER				0XE000E100
#define NVIC_ICER				0XE000E180
#define NVIC_IPR				0xE000E300


void irq_ctl(uint8_t irq_number, uint8_t flag);
void irq_prio_config(uint8_t irq_number, uint8_t prio);


#endif /* INC_DRIVER_INTERRUPT_H_ */
