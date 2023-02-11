/*
 * spi_receive.c
 *
 *  Created on: 2022. 4. 3.
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


	//receieve
	GPIO_handle_t SPI2P;
	SPI2P.GPIOx = GPIOB;
	SPI2P.config.MODE = AFIO_MODE_OP_PP;
	SPI2P.config.SPEED = GPIO_SPEED_50MH;

	//NSS
	gpio_clock_ctl(GPIOB);
	SPI2P.config.PIN_NO = GPIO_PIN_NO12;
	gpio_init(&SPI2P);
	//SCK
	SPI2P.config.MODE = GPIO_MODE_IP_FL;
	SPI2P.config.PIN_NO = GPIO_PIN_NO13;
	gpio_init(&SPI2P);
	//MISO
	SPI2P.config.MODE = AFIO_MODE_OP_PP;
	SPI2P.config.PIN_NO = GPIO_PIN_NO14;
	gpio_init(&SPI2P);
	//MOSI
	SPI2P.config.MODE = GPIO_MODE_IP_FL;
	SPI2P.config.PIN_NO = GPIO_PIN_NO15;
	gpio_init(&SPI2P);

	SPI_handle_t spi;
	spi.SPIx = SPI2;
	spi.config.MODE = SPI_MODE_S;
	spi.config.BAUD = SPI_BAUD_DIV_2;
	spi.config.METHOD = SPI_METHOD_FD;
	spi.config.DFF = SPI_DFF_8;
	spi.config.CPHA = SPI_CPHA_F;
	spi.config.CPOL =  SPI_CPOL_L;
	spi.config.SSM = SPI_SSM_SW;

	spi_clock_ctl(SPI2);
	spi_init(&spi);
	spi_ctl(SPI2, ENABLE);


	uint8_t data;
	while(1)
	{
		spi_receive(SPI2, &data, 1);
		if(data == (uint8_t)0x7)
		{
			gpio_toggle_pin(GPIOA, GPIO_PIN_NO5);
		}
	}

}

