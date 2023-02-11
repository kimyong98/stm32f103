/*
 * pwm.c
 *
 *  Created on: 2022. 4. 23.
 *      Author: 82107
 */
#include <stdio.h>
#include "driver.h"

void delay(void)
{
	uint32_t delay = 0x1FFFFF;
	while(delay != 0)
	{
		delay--;
	}
}

int main(void)
{
	RCC_handle_t rcc;
	rcc.RCCptr = RCC;
	rcc.config.MHZ = RCC_SYSCLK_16MH;
	rcc.config.APB1_DIV = RCC_APB1_DIV_NONE;
	rcc.config.APB2_DIV = RCC_APB2_DIV_NONE;
	configure_sysclk(&rcc);

	/*
	 * 20ms clk = 16KH arr = 1000 psc = 320
	 */

	GPIO_handle_t PWM;
	PWM.GPIOx = GPIOA;
	PWM.config.MODE = AFIO_MODE_OP_PP;
	PWM.config.PIN_NO = GPIO_PIN_NO0;
	PWM.config.SPEED = GPIO_SPEED_10MH;

	gpio_clock_ctl(GPIOA);
	gpio_init(&PWM);

	TIM_handle_t timer2;
	timer2.TIMx = TIM2;
	timer2.config.ARR = 1000;
	timer2.config.PSC = 320;

	TIM2_PERIPHERAL_CLK_EN();
	timer_init(&timer2);

	pwm_init(TIM2,TIM_CH1);
	pwm_init(TIM2,TIM_CH2);
	duty(TIM2, TIM_CH1, 100);
	duty(TIM2, TIM_CH2, 100);
	timer_enable(TIM2);

	uint16_t i = 0;
	uint16_t j[3] = {25,75,125};
	while(1)
	{
		delay();
		duty(TIM2, TIM_CH1, j[i%3]);
		duty(TIM2, TIM_CH2, j[i%3]);
		i++;
	}
}
