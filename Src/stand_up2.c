/*
 * pwm1.c
 *
 *  Created on: 2022. 5. 9.
 *      Author: injog
 */

/*
		//1's leg
		duty(TIM4, TIM_CH2, 90);
		duty(TIM2, TIM_CH1, 50);
		//2's leg
		duty(TIM2, TIM_CH2, 90);
		duty(TIM3, TIM_CH3, 50);
		//3's leg
		duty(TIM4, TIM_CH4, 60);
		duty(TIM3, TIM_CH1, 100);
		//4's leg
		duty(TIM3, TIM_CH2, 60);
		duty(TIM4, TIM_CH1, 100);
 */

#include <stdio.h>
#include "driver.h"
void servo_init(void);
void pwm(void);
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

	servo_init();
	pwm();


	duty(TIM2, TIM_CH1, 75);
	duty(TIM2, TIM_CH2, 75);
	duty(TIM3, TIM_CH1, 75);
	duty(TIM3, TIM_CH2, 75);
	duty(TIM3, TIM_CH3, 75);
	duty(TIM3, TIM_CH4, 75);
	duty(TIM4, TIM_CH1, 75);
	duty(TIM4, TIM_CH2, 75);
	duty(TIM4, TIM_CH3, 75);
	duty(TIM4, TIM_CH4, 75);

	timer_enable(TIM2);
	timer_enable(TIM3);
	timer_enable(TIM4);

	while(1)
	{

		//1's leg
		duty(TIM4, TIM_CH2, 85);
		duty(TIM2, TIM_CH1, 75);
		//2's leg
		duty(TIM2, TIM_CH2, 85);
		duty(TIM3, TIM_CH3, 75);
		//3's leg
		duty(TIM4, TIM_CH4, 65);
		duty(TIM3, TIM_CH1, 75);
		//4's leg
		duty(TIM3, TIM_CH2, 65);
		duty(TIM4, TIM_CH1, 75);
		delay();
	}
}

void servo_init(void)
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
}

void pwm(void)
{
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


