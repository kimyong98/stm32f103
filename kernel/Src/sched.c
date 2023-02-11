/*
 * sched.c
 *
 *  Created on: 2022. 5. 18.
 *      Author: 82107
 */
#include "def.h"

uint32_t tick = 0;
uint32_t current_prio = 63;
extern tcb_t *current_task;
extern tcb_t *next_task;
extern tcb_t TCB[NUM_OF_TASK];
extern tcb_t *prio_task[NUM_OF_TASK];
extern uint8_t ntask;

uint8_t tmp = 63;
int32_t count;
void init_fault(void)
{
	volatile uint32_t *pSHCSR = (uint32_t *)0xE000ED24;

	*pSHCSR |= (1 << 16);
	*pSHCSR |= (1 << 17);
	*pSHCSR |= (1 << 18);

}
void init_systick_timer(uint32_t tick_hz)
{
	volatile uint32_t *pSRVR = (uint32_t *)0xE000E014;
	volatile uint32_t *pSCSR = (uint32_t *)0xE000E010;
	volatile uint32_t *SYSPRI3 = (uint32_t *)0xE000ED20;
	uint32_t count_value = (SYSTICK_TIM_CLK/tick_hz)-1;

	*pSRVR &= ~0xFFFFFFFF;

	*pSRVR |= count_value;

	*SYSPRI3 = (*SYSPRI3&0x00FFFFFF) | 0xE0000000;
	*SYSPRI3 = (*SYSPRI3&0xFF00FFFF) | 0x00F00000;

	*pSCSR |= (1 << 1);
	*pSCSR |= (1 << 2);

	*pSCSR |= (1 << 0);

}
__attribute__((naked)) void SysTick_Handler(void)
{
	tick++;
	tmp = current_prio;
	for(count=0; count<ntask; count++)
	{
		if(--TCB[count].delay <= 0)
		{
			TCB[count].delay = 0;
			if(TCB[count].prio < tmp)
				tmp = TCB[count].prio;
		}
	}


	if(current_prio != tmp)
	{
		current_prio = tmp;
		next_task = prio_task[tmp];
		//call sched
		*INTCTRL = 0x10000000;
	}

	__asm("BX LR");
}
void PendSV_Handler(void)
{
	__asm("CPSID I");

	__asm("MRS R0, PSP");
	__asm("STMDB R0!, {R4-R11}");
	__asm("LDR R1, =current_task");
	__asm("LDR R1, [R1]");
	__asm("STR R0, [R1]");

	__asm("LDR R1, =next_task");
	__asm("LDR R1, [R1]");
	__asm("LDR R0, =current_task");
	__asm("STR R1, [R0]");
	__asm("LDR R0, [R0]");
	__asm("LDR R1, [R0]");
	__asm("LDMIA R1!, {R4-R11}");
	__asm("MSR PSP, R1");

	__asm("CPSIE I");
	__asm("BX LR");
}

uint32_t get_tick(void)
{
	return tick;
}
void systic_delay(uint32_t ms)
{
	uint32_t t = get_tick();
	while((get_tick() - t) < ms);
	return;
}



void sched_start(void)
{
	__asm("CPSID I");

	__asm volatile ("MOV R0, #0X02");
	__asm volatile ("MSR CONTROL, R0");

	__asm volatile("LDR R0, =current_task");
	__asm volatile("LDR R2, [R0]");
	__asm volatile("LDR SP, [R2]");
	__asm volatile("POP {R4-R11}");
	__asm volatile("POP {R12}");
	__asm volatile("POP {R0-R3}");
	__asm volatile("ADD SP,SP,#4");
	__asm volatile("POP {LR}");
	__asm volatile("ADD SP,SP,#4");

	__asm("CPSIE I");

	__asm volatile("BX LR");
}

void call_sched(void)
{
	*INTCTRL = 0x10000000;
}



void MemManage_Handler(void)
{
	while(1);
}
void BusFault_Handler(void)
{
	while(1);
}
void UsageFault_Handler(void)
{
	while(1);
}
