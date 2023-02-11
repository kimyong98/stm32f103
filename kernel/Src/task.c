/*
 * task.c
 *
 *  Created on: 2022. 5. 17.
 *      Author: 82107
 */
#include "def.h"

tcb_t TCB[NUM_OF_TASK];
uint8_t ntask = 0;
uint32_t stack[NUM_OF_TASK][STACK_SIZE];
tcb_t *current_task = &TCB[0];
tcb_t *next_task = &TCB[0];
extern uint8_t tmp;
tcb_t *prio_task[NUM_OF_TASK];
uint32_t idle_ctr;
extern uint32_t current_prio;
extern int32_t count;

void task_create(void(*task_func)(), uint8_t prio)
{

	__asm volatile ("cpsid i");
	stack[ntask][STACK_SIZE - 1] = 1<<24;				//PSR
	stack[ntask][STACK_SIZE - 2] = (uint32_t)task_func;		//R13 PC
	stack[ntask][STACK_SIZE - 3] = 0XFFFFFFFD;				//R12 LR 0xFFFFFFFD
	stack[ntask][STACK_SIZE - 4] = 0;						//R3
	stack[ntask][STACK_SIZE - 5] = 0;						//R2
	stack[ntask][STACK_SIZE - 6] = 0;						//R1
	stack[ntask][STACK_SIZE - 7] = 0;						//R0

	stack[ntask][STACK_SIZE - 9] = 0;						//R11
	stack[ntask][STACK_SIZE - 10] = 0;						//R10
	stack[ntask][STACK_SIZE - 11] = 0;						//R9
	stack[ntask][STACK_SIZE - 12] = 0;						//R8
	stack[ntask][STACK_SIZE - 13] = 0;						//R7
	stack[ntask][STACK_SIZE - 14] = 0;						//R6
	stack[ntask][STACK_SIZE - 15] = 0;						//R5
	stack[ntask][STACK_SIZE - 16] = 0;						//R4

	TCB[ntask].sp = &stack[ntask][STACK_SIZE - 16];
	TCB[ntask].prio = prio;
	TCB[ntask].delay = 0;
	prio_task[prio] = &TCB[ntask];
	if(ntask != 0)
	{
		TCB[ntask-1].next = &TCB[ntask];
		TCB[ntask].next = &TCB[0];
	}
	ntask++;
	__asm volatile ("cpsie i");

}
void idle_task(void)
{
	while(1)
	{
		idle_ctr++;
	}
}
void task_delay(uint32_t tick)
{
	__asm volatile ("cpsid i");

	current_task->delay = tick;
	tmp = 64;
	for(count=0; count<ntask; count++)
	{
		if(TCB[count].delay == 0)
		{
			if(TCB[count].prio < tmp)
				tmp = TCB[count].prio;
		}
	}


	if(current_prio != tmp)
	{
		current_prio = tmp;
		next_task = prio_task[tmp];
	}
	__asm volatile ("cpsie i");
	call_sched();
}


