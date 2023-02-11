/*
 * real.c
 *
 *  Created on: 2022. 5. 18.
 *      Author: 82107
 */
#include "driver.h"
#include "def.h"

uint32_t i=0, j=0;
void task1(void)
{
	while(1){
		i++;
	}
}
void task2(void)
{
	while(1){
		j++;
		task_delay(1);
	}
}

int main(void)
{
	//init_scheduler_stack();
	//config system clock
	init_fault();
	RCC_handle_t rcc;
	rcc.RCCptr = RCC;
	rcc.config.MHZ = RCC_SYSCLK_16MH;
	rcc.config.APB1_DIV = RCC_APB1_DIV_NONE;
	rcc.config.APB2_DIV = RCC_APB2_DIV_NONE;
	configure_sysclk(&rcc);
	//config systick timer
	init_systick_timer(1000);

	// create idle
	task_create(idle_task, 63);
	// create tasks
	task_create(task2, 61);
	task_create(task1, 62);

	sched_start();
	while(1);
}

