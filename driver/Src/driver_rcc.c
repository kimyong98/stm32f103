/*
 * driver_rcc.c
 *
 *  Created on: Mar 27, 2022
 *      Author: 82107
 */
#include "driver.h"

void configure_sysclk(RCC_handle_t *RCC_handle)
{
	// 1. Configure PLL
	RCC_handle->RCCptr->CFGR |= (RCC_handle->config.MHZ << 18);
	RCC_handle->RCCptr->CFGR &= ~(1 << 16);
	// 2. Enable PLL and wait flag
	RCC_handle->RCCptr->CR |= (1 << 24);
	while( !( RCC_handle->RCCptr->CR & (1 << 25) ) );
	// 3. Initialize bus prescalers
	uint32_t tmp = 0U;
	//tmp |= (RCC_handle->config.AHB_DIV << 4);
	tmp |= (RCC_handle->config.APB1_DIV << 8);
	tmp |= (RCC_handle->config.APB1_DIV << 11);
	RCC_handle->RCCptr->CFGR |= tmp;
	// 4. Configure flash latency
	if(RCC_handle->config.MHZ <= RCC_SYSCLK_24MH)
	{
		*FLASH_ACR |= ZERO_WAIT_STATE;
	}
	else
	{
		*FLASH_ACR |= ONE_WAIT_STATE;
	}
	// 5. Select PLL as  sysclk
	RCC_handle->RCCptr->CFGR |= 2;
	while((RCC_handle->RCCptr->CFGR & (0x3 << 2)) != 0x8);
}
