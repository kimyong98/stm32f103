   /*
 * spi.c
 *
 *  Created on: 2022. 4. 3.
 *      Author: 82107
 */
#include <stdint.h>
#include "driver.h"

uint8_t A = 0;

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

	GPIO_handle_t BUTTON;
	BUTTON.GPIOx = GPIOC;
	BUTTON.config.MODE = GPIO_MODE_IP_PU;
	BUTTON.config.PIN_NO = GPIO_PIN_NO13;
	BUTTON.config.TRIGGER = GPIO_IT_TR_FA;

	gpio_clock_ctl(GPIOC);
	gpio_init(&BUTTON);
	gpio_exti_config(&BUTTON);
	gpio_irq_init(&BUTTON);

	// send
	GPIO_handle_t SPI1P;
	SPI1P.GPIOx = GPIOA;
	SPI1P.config.MODE = AFIO_MODE_OP_PP;
	SPI1P.config.SPEED = GPIO_SPEED_50MH;

	//NSS
	gpio_clock_ctl(GPIOA);
	SPI1P.config.PIN_NO = GPIO_PIN_NO4;
	gpio_init(&SPI1P);
	//SCK
	SPI1P.config.PIN_NO = GPIO_PIN_NO5;
	gpio_init(&SPI1P);
	//MISO
	SPI1P.config.MODE = GPIO_MODE_IP_FL;
	SPI1P.config.PIN_NO = GPIO_PIN_NO6;
	gpio_init(&SPI1P);
	//MOSI
	SPI1P.config.MODE = AFIO_MODE_OP_PP;
	SPI1P.config.PIN_NO = GPIO_PIN_NO7;
	gpio_init(&SPI1P);

	SPI_handle_t spi1;
	spi1.SPIx = SPI1;
	spi1.config.MODE = SPI_MODE_M;
	spi1.config.BAUD = SPI_BAUD_DIV_2;
	spi1.config.METHOD = SPI_METHOD_FD;
	spi1.config.DFF = SPI_DFF_8;
	spi1.config.CPHA = SPI_CPHA_F;
	spi1.config.CPOL =  SPI_CPOL_L;
	spi1.config.SSM = SPI_SSM_SW;

	spi_clock_ctl(SPI1);
	spi_init(&spi1);
	spi_ctl(SPI1, ENABLE);



	while(1);


}

void EXTI15_10_IRQHandler(void)
{
	uint8_t data = (uint8_t)0x7;
	spi_send(SPI1, &data, 1);
	EXTI->PR |= (1 << GPIO_PIN_NO13);
}

