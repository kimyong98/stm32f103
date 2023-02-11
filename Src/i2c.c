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
	 * I2C1 SCL : PB6 SDA : PB7
	 */

	GPIO_handle_t I2C;
	I2C.GPIOx = GPIOB;
	I2C.config.MODE = AFIO_MODE_OP_OD;
	I2C.config.SPEED = GPIO_SPEED_10MH;
	I2C.config.PIN_NO = GPIO_PIN_NO6;
	gpio_clock_ctl(GPIOB);
	gpio_init(&I2C);
	I2C.config.PIN_NO = GPIO_PIN_NO7;
	gpio_init(&I2C);

	i2c_clock_ctl(I2C1);
	i2c_master_init(I2C1);
	uint8_t data1 = 'a';
	uint8_t data2 = 'b';
	while(1)
	{
		i2c_master_send_data(I2C1, &data2, 1, 0x8);
		delay();
		i2c_master_send_data(I2C1, &data1, 1, 0x8);
		delay();
	}
}
