/*
 * servo.c
 *
 *  Created on: 2022. 5. 22.
 *      Author: injog
 */
#include "driver.h"
#include "def.h"
#include "angle.h"
void servo_init(void);
void pwm(void);
void go(void)
{
	int path = 5;
	//4's leg
	duty(TIM4, TIM_CH1, FOUR_TWO + path);
	//1's leg
	duty(TIM2, TIM_CH1, ONE_TWO - path);
	duty(TIM3, TIM_CH3, TWO_TWO);
	duty(TIM3, TIM_CH1, THREE_TWO);
	systic_delay(200);
	//4's leg
	duty(TIM3, TIM_CH2, FOUR_ONE + path);
	//1's leg
	duty(TIM4, TIM_CH2, ONE_ONE - path);
	duty(TIM2, TIM_CH2, TWO_ONE);
	duty(TIM4, TIM_CH4, THREE_ONE);
	systic_delay(200);



	//2's leg
	duty(TIM3, TIM_CH3, TWO_TWO - path);
	//3's leg
	duty(TIM3, TIM_CH1, THREE_TWO + path);
	duty(TIM4, TIM_CH1, FOUR_TWO);
	duty(TIM2, TIM_CH1, ONE_TWO);
	systic_delay(200);
	//2's leg
	duty(TIM2, TIM_CH2, TWO_ONE - path);
	//3's leg
	duty(TIM4, TIM_CH4, THREE_ONE + path);
	duty(TIM3, TIM_CH2, FOUR_ONE);
	duty(TIM4, TIM_CH2, ONE_ONE);
	systic_delay(200);

}
void down(void)
{
	int path = 17;
	//down
	//1's leg
	duty(TIM4, TIM_CH2, ONE_ONE + path);
	duty(TIM2, TIM_CH1, ONE_TWO - path);
	//2's leg
	duty(TIM2, TIM_CH2, TWO_ONE + 20);
	duty(TIM3, TIM_CH3, TWO_TWO - 20);
	//3's leg
	duty(TIM4, TIM_CH4, THREE_ONE - path);
	duty(TIM3, TIM_CH1, THREE_TWO + path);
	//4's leg
	duty(TIM3, TIM_CH2, FOUR_ONE - 20);
	duty(TIM4, TIM_CH1, FOUR_TWO + 20);
	systic_delay(3000);


	//2's leg

	duty(TIM3, TIM_CH3, TWO_TWO);
	//4's leg

	duty(TIM4, TIM_CH1, FOUR_TWO);
	systic_delay(1000);

	//1's leg
	duty(TIM4, TIM_CH2, ONE_ONE);
	duty(TIM4, TIM_CH4, THREE_ONE);

	//2's leg
	duty(TIM2, TIM_CH2, TWO_ONE);
	//4's leg
	duty(TIM3, TIM_CH2, FOUR_ONE);

	duty(TIM2, TIM_CH1, ONE_TWO);
	duty(TIM3, TIM_CH1, THREE_TWO);
	systic_delay(2000);
}

void left(void)
{
	int path = 5;
	duty(TIM3, TIM_CH3, TWO_TWO);
	duty(TIM3, TIM_CH1, THREE_TWO);
	duty(TIM2, TIM_CH1, ONE_TWO-path);
	duty(TIM4, TIM_CH1, FOUR_TWO+path);
	systic_delay(200);
	duty(TIM2, TIM_CH2, TWO_ONE);
	duty(TIM4, TIM_CH4, THREE_ONE);
	duty(TIM4, TIM_CH2, ONE_ONE+path);
	duty(TIM3, TIM_CH2, FOUR_ONE+path);
	systic_delay(200);
	duty(TIM2, TIM_CH1, ONE_TWO);
	duty(TIM4, TIM_CH1, FOUR_TWO);
	duty(TIM3, TIM_CH3, TWO_TWO-path);
	duty(TIM3, TIM_CH1, THREE_TWO+path);
	systic_delay(200);
	duty(TIM4, TIM_CH2, ONE_ONE);
	duty(TIM3, TIM_CH2, FOUR_ONE);
	duty(TIM2, TIM_CH2, TWO_ONE+path);
	duty(TIM4, TIM_CH4, THREE_ONE+path);
	systic_delay(200);

}

void right(void)
{
	int path = 7;
	duty(TIM3, TIM_CH3, TWO_TWO);
	duty(TIM3, TIM_CH1, THREE_TWO);
	duty(TIM2, TIM_CH1, ONE_TWO-path);
	duty(TIM4, TIM_CH1, FOUR_TWO+path);
	systic_delay(200);
	duty(TIM2, TIM_CH2, TWO_ONE);
	duty(TIM4, TIM_CH4, THREE_ONE);
	duty(TIM4, TIM_CH2, ONE_ONE-path);
	duty(TIM3, TIM_CH2, FOUR_ONE-path);
	systic_delay(200);
	duty(TIM2, TIM_CH1, ONE_TWO);
	duty(TIM4, TIM_CH1, FOUR_TWO);
	duty(TIM3, TIM_CH3, TWO_TWO-path);
	duty(TIM3, TIM_CH1, THREE_TWO+path);
	systic_delay(200);
	duty(TIM4, TIM_CH2, ONE_ONE);
	duty(TIM3, TIM_CH2, FOUR_ONE);
	duty(TIM2, TIM_CH2, TWO_ONE-path);
	duty(TIM4, TIM_CH4, THREE_ONE-path);
	systic_delay(200);

}
int main(void)
{

	RCC_handle_t rcc;
	rcc.RCCptr = RCC;
	rcc.config.MHZ = RCC_SYSCLK_16MH;
	rcc.config.APB1_DIV = RCC_APB1_DIV_NONE;
	rcc.config.APB2_DIV = RCC_APB2_DIV_NONE;
	configure_sysclk(&rcc);
	//config systick timer
	init_systick_timer(1000);



	GPIO_handle_t LED;


	//tx
	LED.GPIOx = GPIOA;
	LED.config.MODE = AFIO_MODE_OP_PP;
	LED.config.PIN_NO = GPIO_PIN_NO9;
	LED.config.SPEED = GPIO_SPEED_10MH;

	gpio_clock_ctl(GPIOA);
	AFIO_PERIPHERAL_CLK_EN();
	gpio_init(&LED);

	//rx
	LED.config.MODE = GPIO_MODE_IP_FL;
	LED.config.PIN_NO = GPIO_PIN_NO10;
	gpio_init(&LED);
	servo_init();
	pwm();

	usart_init(USART1);
	//usart_irq_ctl(USART1);
	uint8_t data;

	while(1)
	{
		//standup		//1's leg
		duty(TIM4, TIM_CH2, ONE_ONE);
		duty(TIM2, TIM_CH1, ONE_TWO);
		//3's leg
		duty(TIM4, TIM_CH4, THREE_ONE);
		duty(TIM3, TIM_CH1, THREE_TWO);
		//2's leg
		duty(TIM2, TIM_CH2, TWO_ONE);
		duty(TIM3, TIM_CH3, TWO_TWO);
		//4's leg
		duty(TIM3, TIM_CH2, FOUR_ONE);
		duty(TIM4, TIM_CH1, FOUR_TWO);
		systic_delay(1000);
		data = usart_getc(USART1);

		if(data == 'a'){
			down();
		}
		else if(data == 'b')
		{
			for(int i=0; i<10; i++)
				go();
			systic_delay(2000);
		}
		else if(data == 'c')
		{
			for(int i=0; i<10; i++)
				left();
		}
		else if(data == 'd')
		{
			for(int i=0; i<10; i++)
				right();
			duty(TIM4, TIM_CH2, ONE_ONE);
			duty(TIM2, TIM_CH1, ONE_TWO);
			//3's leg
			duty(TIM4, TIM_CH4, THREE_ONE);
			duty(TIM3, TIM_CH1, THREE_TWO);
			//2's leg
			duty(TIM2, TIM_CH2, TWO_ONE);
			duty(TIM3, TIM_CH3, TWO_TWO);
			//4's leg
			duty(TIM3, TIM_CH2, FOUR_ONE);
			duty(TIM4, TIM_CH1, FOUR_TWO);
			systic_delay(2000);
		}

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
