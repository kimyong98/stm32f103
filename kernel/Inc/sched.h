/*
 * sched.h
 *
 *  Created on: 2022. 5. 18.
 *      Author: 82107
 */

#ifndef INC_SCHED_H_
#define INC_SCHED_H_
#include "def.h"
#define SYSTICK_TIM_CLK			16000000
#define INTCTRL			(volatile uint32_t *)0xE000ED04

void init_fault(void);
void init_systick_timer(uint32_t tick_hz);
__attribute__((naked)) void SysTick_Handler(void);
uint32_t get_tick(void);
void systic_delay(uint32_t ms);

void sched_start(void);
void call_sched(void);
#endif /* INC_SCHED_H_ */
