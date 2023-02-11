/*
 * driver_rcc.h
 *
 *  Created on: Mar 27, 2022
 *      Author: 82107
 */

#include "driver.h "

/*
 * We only use HSI by PLL
 */

/*
 * Type definition of RCC configuration and RCC handler
 */
typedef struct{
	uint8_t MHZ;		// @ Sysclk
	uint8_t APB1_DIV;	// @ APB1 prescaler
	uint8_t APB2_DIV;	// @ APB2 prescaler
//	uint8_t AHB_DIV;	// @ AHB prescaler
}RCC_config_t;

typedef struct{
	RCC_t *RCCptr;
	RCC_config_t config;
}RCC_handle_t;

/*
 * Macro for RCC
 */
// @ Sysclk
#define RCC_SYSCLK_16MH					2
#define RCC_SYSCLK_20MH					3
#define RCC_SYSCLK_24MH					4
#define RCC_SYSCLK_26MH					13
#define RCC_SYSCLK_28MH					5
#define RCC_SYSCLK_32MH					6
#define RCC_SYSCLK_36MH					7

/*
// @ AHB prescaler
#define RCC_AHB_DIV_NONE				0
#define RCC_AHB_DIV_2					8
#define RCC_AHB_DIV_4					9
#define RCC_AHB_DIV_8					10
#define RCC_AHB_DIV_16					11
#define RCC_AHB_DIV_64					12
#define RCC_AHB_DIV_128					13
#define RCC_AHB_DIV_256					14
#define RCC_AHB_DIV_512					15
*/

// @ APB1 prescaler
#define RCC_APB1_DIV_NONE				0
#define RCC_APB1_DIV_2					4
#define RCC_APB1_DIV_4					5
#define RCC_APB1_DIV_8					6
#define RCC_APB1_DIV_16					7

// @ APB2 prescaler
#define RCC_APB2_DIV_NONE				0
#define RCC_APB2_DIV_2					4
#define RCC_APB2_DIV_4					5
#define RCC_APB2_DIV_8					6
#define RCC_APB2_DIV_16					7

// @ LATENCY in FLASH_ACR
#define ZERO_WAIT_STATE					0
#define ONE_WAIT_STATE					1
#define TWO_WAIT_STATE					2

void configure_sysclk(RCC_handle_t *RCC_handle);
