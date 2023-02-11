/*
 * uart_test.c
 *
 *  Created on: 2022. 8. 25.
 *      Author: injog
 */
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

	GPIO_handle_t LED;

	LED.GPIOx = GPIOA;
	LED.config.MODE = GPIO_MODE_OP_PP;
	LED.config.PIN_NO = GPIO_PIN_NO5;
	LED.config.SPEED = GPIO_SPEED_10MH;

	gpio_clock_ctl(GPIOA);
	gpio_init(&LED);
	//tx
	LED.GPIOx = GPIOA;
	LED.config.MODE = AFIO_MODE_OP_PP;
	LED.config.PIN_NO = GPIO_PIN_NO9;
	LED.config.SPEED = GPIO_SPEED_50MH;

	gpio_clock_ctl(GPIOA);
	AFIO_PERIPHERAL_CLK_EN();
	gpio_init(&LED);

	//rx
	LED.config.MODE = GPIO_MODE_IP_FL;
	LED.config.PIN_NO = GPIO_PIN_NO10;
	gpio_init(&LED);


	usart_init(USART1);
	usart_irq_ctl(USART1);
	uint32_t b = 0;
	uint8_t c;
	while(1)
	{

/*
		c = usart_getc(USART1);
		if(c == 'a')
		{
			gpio_toggle_pin(GPIOA, GPIO_PIN_NO5);
			delay();
		}

*/
	}
}

