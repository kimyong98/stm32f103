/*
 * stack.h
 *
 *  Created on: 2022. 5. 18.
 *      Author: 82107
 */

#ifndef INC_STACK_H_
#define INC_STACK_H_
#include "def.h"
#define STACK_SIZE		64U
#define SIZE_STACK_SCHED		1024U

#define SRAM_START			0x20000000U
#define SIZE_SRAM			((20) * 1024)
#define SRAM_END			((SRAM_START) + (SIZE_SRAM))
#define SCHED_STACK_START	((SRAM_END) - (64 * (SIZE_SRAM) ) )
#define GET_STACK(x)		((SRAM_END) - (x * (SIZE_SRAM) ) )


#endif /* INC_STACK_H_ */
