/*
 * driver_leg.c
 *
 *  Created on: 2022. 5. 22.
 *      Author: injog
 */
#include "driver.h"
void leg_init(void)
{
	GPIO_handle_t PWM;

	PWM.config.MODE = AFIO_MODE_OP_PP;
	PWM.config.SPEED = GPIO_SPEED_10MH;
	gpio_clock_ctl(GPIOA);
	gpio_clock_ctl(GPIOB);

	PWM.GPIOx = GPIOA;

	PWM.config.PIN_NO = GPIO_PIN_NO0;
	gpio_init(&PWM);
	PWM.config.PIN_NO = GPIO_PIN_NO1;
	gpio_init(&PWM);
	PWM.config.PIN_NO = GPIO_PIN_NO6;
	gpio_init(&PWM);
	PWM.config.PIN_NO = GPIO_PIN_NO7;
	gpio_init(&PWM);

	PWM.GPIOx = GPIOB;

	PWM.config.PIN_NO = GPIO_PIN_NO0;
	gpio_init(&PWM);
	PWM.config.PIN_NO = GPIO_PIN_NO1;
	gpio_init(&PWM);
	PWM.config.PIN_NO = GPIO_PIN_NO6;
	gpio_init(&PWM);
	PWM.config.PIN_NO = GPIO_PIN_NO7;
	gpio_init(&PWM);
	PWM.config.PIN_NO = GPIO_PIN_NO8;
	gpio_init(&PWM);
	PWM.config.PIN_NO = GPIO_PIN_NO9;
	gpio_init(&PWM);

	TIM_handle_t timer;
	timer.config.ARR = 1000;
	timer.config.PSC = 320;

	TIM2_PERIPHERAL_CLK_EN();
	TIM3_PERIPHERAL_CLK_EN();
	TIM4_PERIPHERAL_CLK_EN();

	timer.TIMx = TIM2;
	timer_init(&timer);
	timer.TIMx = TIM3;
	timer_init(&timer);
	timer.TIMx = TIM4;
	timer_init(&timer);

	pwm_init(TIM2,TIM_CH1);
	pwm_init(TIM2,TIM_CH2);

	pwm_init(TIM3,TIM_CH1);
	pwm_init(TIM3,TIM_CH2);
	pwm_init(TIM3,TIM_CH3);
	pwm_init(TIM3,TIM_CH4);

	pwm_init(TIM4,TIM_CH1);
	pwm_init(TIM4,TIM_CH2);
	pwm_init(TIM4,TIM_CH3);
	pwm_init(TIM4,TIM_CH4);
}

