/*
 * led_blinky001.c
 *
 *  Created on: 2022. 3. 30.
 *      Author: 82107
 */
#include <stdint.h>
#include "driver.h"

int main(void)
{
	RCC_handle_t rcc;
	rcc.RCCptr = RCC;
	rcc.config.MHZ = RCC_SYSCLK_16MH;
	rcc.config.APB1_DIV = RCC_APB1_DIV_NONE;
	rcc.config.APB2_DIV = RCC_APB2_DIV_NONE;
	configure_sysclk(&rcc);

	GPIO_handle_t LED;
	LED.GPIOx = GPIOA;
	LED.config.MODE = GPIO_MODE_OP_PP;
	LED.config.PIN_NO = GPIO_PIN_NO5;
	LED.config.SPEED = GPIO_SPEED_10MH;

	gpio_clock_ctl(GPIOA);
	gpio_init(&LED);

	GPIO_handle_t BUTTON;
	BUTTON.GPIOx = GPIOC;
	BUTTON.config.MODE = GPIO_MODE_IP_PU;
	BUTTON.config.PIN_NO = GPIO_PIN_NO13;
	BUTTON.config.TRIGGER = GPIO_IT_TR_FA;

	gpio_clock_ctl(GPIOC);
	gpio_init(&BUTTON);
	gpio_exti_config(&BUTTON);
	gpio_irq_init(&BUTTON);


	while(1);

}

void EXTI15_10_IRQHandler(void)
{
	gpio_toggle_pin(GPIOA, GPIO_PIN_NO5);
	EXTI->PR |= (1 << GPIO_PIN_NO13);

}
