/*
 * driver_timer.c
 *
 *  Created on: 2022. 4. 17.
 *      Author: 82107
 */
#include "driver.h"

void timer_init(TIM_handle_t* TIM_handle)
{

	TIM_handle->TIMx->PSC = TIM_handle->config.PSC - 1;
	TIM_handle->TIMx->ARR = TIM_handle->config.ARR - 1;
	TIM_handle->TIMx->CR1 |= 1 << 7;

	//TIM_handle->TIMx->DIER |= 1 << 0;
	//irq_ctl(RETURN_TIM_IRQ_NO(TIM_handle->TIMx), SET);

	// TIMER update
	TIM_handle->TIMx->EGR |= 1 << 0;
}

void pwm_init(TIM_t *TIMx, uint8_t ch)
{

	if(ch == TIM_CH1)
	{
		TIMx->CCMR1 |= 6 << 4;
		TIMx->CCMR1 |= 1 << 3;

		TIMx->EGR |= 1 << 0;

		TIMx->CCER |= 1 << 0;
	}
	else if(ch == TIM_CH2)
	{
		TIMx->CCMR1 |= 6 << 12;
		TIMx->CCMR1 |= 1 << 11;

		TIMx->EGR |= 1 << 0;

		TIMx->CCER |= 1 << 4;
	}
	else if(ch == TIM_CH3)
	{
		TIMx->CCMR2 |= 6 << 4;
		TIMx->CCMR2 |= 1 << 3;

		TIMx->EGR |= 1 << 0;

		TIMx->CCER |= 1 << 8;
	}
	else
	{
		TIMx->CCMR2 |= 6 << 12;
		TIMx->CCMR2 |= 1 << 11;

		TIMx->EGR |= 1 << 0;

		TIMx->CCER |= 1 << 12;
	}
}

void duty(TIM_t *TIMx, uint8_t ch, uint16_t duty)
{
	if(ch == TIM_CH1)
	{
		TIMx->CCR1 = duty;
	}
	else if(ch == TIM_CH2)
	{
		TIMx->CCR2 = duty;
	}
	else if(ch == TIM_CH3)
	{
		TIMx->CCR3 = duty;
	}
	else
	{
		TIMx->CCR4 = duty;
	}

	// TIMER update
	TIMx->EGR |= 1 << 0;
}

void timer_enable(TIM_t *TIMx)
{
	TIMx->CR1 |= 1 << 0;
}
