/*
 * servo.c
 *
 *  Created on: 2022. 5. 22.
 *      Author: injog
 */
#include "driver.h"
#include "def.h"

void servo_init(void);
void pwm(void);
void task_down(void)
{
	while(1){
		duty(TIM4, TIM_CH2, 100);
		duty(TIM2, TIM_CH1, 40);
		task_delay(1000);
	}
}
void task_stand(void)
{
	while(1){
		duty(TIM4, TIM_CH2, 75);
		duty(TIM2, TIM_CH1, 75);
		task_delay(2000);
	}
}
void task1(void)
{
	while(1){
		//stand up
		//1's leg
		duty(TIM4, TIM_CH2, 75);
		duty(TIM2, TIM_CH1, 75);
		//2's leg
		duty(TIM2, TIM_CH2, 75);
		duty(TIM3, TIM_CH3, 75);
		//3's leg
		duty(TIM4, TIM_CH4, 75);
		duty(TIM3, TIM_CH1, 75);
		//4's leg
		duty(TIM3, TIM_CH2, 75);
		duty(TIM4, TIM_CH1, 75);
		task_delay(1000);

		//down

		//1's leg
		duty(TIM4, TIM_CH2, 80);
		duty(TIM2, TIM_CH1, 50);
		//3's leg
		duty(TIM4, TIM_CH4, 70);
		duty(TIM3, TIM_CH1, 100);
		task_delay(1500);

		//sit
		//2's leg
		duty(TIM2, TIM_CH2, 55);
		duty(TIM3, TIM_CH3, 85);
		//4's leg
		duty(TIM3, TIM_CH2, 95);
		duty(TIM4, TIM_CH1, 65);
		//1's leg
		duty(TIM4, TIM_CH2, 65);
		duty(TIM2, TIM_CH1, 75);
		//3's leg
		duty(TIM4, TIM_CH4, 85);
		duty(TIM3, TIM_CH1, 75);
		task_delay(1500);

		//shake hand
		for(int i=0;i<3;i++)
		{
			duty(TIM3, TIM_CH1, 100);
			task_delay(500);
			duty(TIM3, TIM_CH1, 70);
			task_delay(500);
		}
		//down
		//2's leg
		duty(TIM2, TIM_CH2, 80);
		duty(TIM3, TIM_CH3, 50);
		//4's leg
		duty(TIM3, TIM_CH2, 70);
		duty(TIM4, TIM_CH1, 100);
		//1's leg
		duty(TIM4, TIM_CH2, 80);
		duty(TIM2, TIM_CH1, 50);
		//3's leg
		duty(TIM4, TIM_CH4, 70);
		duty(TIM3, TIM_CH1, 100);
		task_delay(1500);

		//standup
		//2's leg
		duty(TIM2, TIM_CH2, 75);
		duty(TIM3, TIM_CH3, 75);
		//4's leg
		duty(TIM3, TIM_CH2, 75);
		duty(TIM4, TIM_CH1, 75);

		task_delay(200);
		//1's leg
		duty(TIM4, TIM_CH2, 75);
		duty(TIM2, TIM_CH1, 75);
		//3's leg
		duty(TIM4, TIM_CH4, 75);
		duty(TIM3, TIM_CH1, 75);
		task_delay(1500);
	}
}


int main(void)
{

	init_fault();
	RCC_handle_t rcc;
	rcc.RCCptr = RCC;
	rcc.config.MHZ = RCC_SYSCLK_16MH;
	rcc.config.APB1_DIV = RCC_APB1_DIV_NONE;
	rcc.config.APB2_DIV = RCC_APB2_DIV_NONE;
	configure_sysclk(&rcc);
	//config systick timer
	init_systick_timer(1000);

	servo_init();
	pwm();

	task_create(idle_task, 63);

	task_create(task1, 61);

	sched_start();

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

	timer_enable(TIM2);
	timer_enable(TIM3);
	timer_enable(TIM4);

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
}
