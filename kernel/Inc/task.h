/*
 * task.h
 *
 *  Created on: 2022. 5. 17.
 *      Author: 82107
 */

#ifndef INC_TASK_H_
#define INC_TASK_H_

#include "def.h"

#define NUM_OF_TASK		64
struct TCB{
	uint32_t *sp;
	struct TCB *next;
	uint8_t prio;
	int32_t delay;
};

typedef struct TCB tcb_t;

void task_create(void(*task_func)(), uint8_t prio);
void idle_task(void);
void task_delay(uint32_t ms);


#endif /* INC_TASK_H_ */
