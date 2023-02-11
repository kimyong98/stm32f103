/*
 * led_blinky001.c
 *
 *  Created on: 2022. 3. 30.
 *      Author: 82107
 */
#include <stdint.h>
#include "driver.h"

void delay(void)
{
	uint32_t delay = 0xFFFFF;
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

	GPIO_handle_t LED;
	LED.GPIOx = GPIOA;
	LED.config.MODE = GPIO_MODE_OP_PP;
	LED.config.PIN_NO = GPIO_PIN_NO5;
	LED.config.SPEED = GPIO_SPEED_10MH;

	gpio_clock_ctl(GPIOA);
	gpio_init(&LED);


	while(1)
	{
		delay();
		gpio_toggle_pin(GPIOA, GPIO_PIN_NO5);
	}

}


