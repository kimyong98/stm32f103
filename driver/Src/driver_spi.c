/*
 * driver_spi.c
 *
 *  Created on: 2022. 4. 1.
 *      Author: 82107
 */
#include "driver.h"


void spi_clock_ctl(SPI_t *SPIx)
{
	if(SPIx == SPI1)
	{
		SPI1_PERIPHERAL_CLK_EN();
	}
	else if(SPIx == SPI2)
	{
		SPI2_PERIPHERAL_CLK_EN();
	}
	else if(SPIx == SPI3)
	{
		SPI3_PERIPHERAL_CLK_EN();
	}
}

void spi_init(SPI_handle_t *SPI_handle)
{
	if(SPI_handle->config.MODE == SPI_MODE_S)
	{
		// set DFF bit
		SPI_handle->SPIx->CR1 |= SPI_handle->config.DFF << 11;
		// set CPOL and CPHA
		SPI_handle->SPIx->CR1 |= SPI_handle->config.CPOL << 1;
		SPI_handle->SPIx->CR1 |= SPI_handle->config.CPHA << 0;
		// set SSM
		if(SPI_handle->config.SSM == SPI_SSM_SW)
		{
			SPI_handle->SPIx->CR1 |= 1 << 9;
			SPI_handle->SPIx->CR1 &= ~(1 << 8);
		}
		else
		{
			SPI_handle->SPIx->CR1 &= ~(1 << 9);
		}
		// set MSTR
		SPI_handle->SPIx->CR1 &= ~(1 << 2);
	}
	else
	{
		// set BR
		SPI_handle->SPIx->CR1 |= SPI_handle->config.BAUD << 3;
		// set CPOL and CPHA
		SPI_handle->SPIx->CR1 |= SPI_handle->config.CPOL << 1;
		SPI_handle->SPIx->CR1 |= SPI_handle->config.CPHA << 0;
		// set DFF bit
		SPI_handle->SPIx->CR1 |= SPI_handle->config.DFF << 11;
		// set SSM
		if(SPI_handle->config.SSM == SPI_SSM_SW)
		{
			SPI_handle->SPIx->CR1 |= 1 << 9;
			SPI_handle->SPIx->CR1 |= 1 << 8;
		}
		else
		{
			SPI_handle->SPIx->CR1 &= ~(1 << 9);
		}
		// set MSTR
		SPI_handle->SPIx->CR1 |= 1 << 2;
	}
	if(SPI_handle->config.METHOD == SPI_METHOD_FD)
	{
		SPI_handle->SPIx->CR1 &= ~(1 << 15);
		SPI_handle->SPIx->CR1 &= ~(1 << 10);
	}
	else if(SPI_handle->config.METHOD == SPI_METHOD_HD)
	{
		SPI_handle->SPIx->CR1  |= (1 << 15);
	}
	else if(SPI_handle->config.METHOD == SPI_METHOD_SP_RX)
	{
		SPI_handle->SPIx->CR1 &= ~(1 << 15);
		SPI_handle->SPIx->CR1 |= 1 << 10;
	}
}

void spi_ctl(SPI_t *SPIx, uint8_t flag)
{
	if(flag == ENABLE)
	{
		SPIx->CR1 |= 1 << 6;
	}
	else
	{
		SPIx->CR1 &= ~(1 << 6);
	}
}

void spi_send(SPI_t *SPIx, uint8_t *data, uint8_t len)
{
	while(len > 0)
	{
		while( !(SPIx->SR & 1 << 1));
		if(SPIx->CR1 & 1 << 11)
		{
			// 16bits
			SPIx->DR = *(uint16_t *)data;
			(uint16_t *)data++;
			len = len - 2;
		}
		else
		{
			//8bits
			SPIx->DR = *data;
			while(SPIx->SR & 1 << 0);
			data++;
			len--;
		}
	}
}

void spi_receive(SPI_t *SPIx, uint8_t *data, uint8_t len)
{
	while(len > 0)
	{
		while( !(SPIx->SR & 1 << 0));
		if(SPIx->CR1 & 1 << 11)
		{
			// 16bits
			*(uint16_t *)data = (uint16_t)SPIx->DR;
			(uint16_t *)data++;
			len = len - 2;
		}
		else
		{
			//8bits
			*data = (uint8_t)SPIx->DR;
			data++;
			len--;
		}
	}
}


void spi_irq_ctl(SPI_t *SPIx, uint8_t flag)
{
	if(flag == SET)
	{
		irq_ctl(RETURN_SPI_IRQ_NO(SPIx), SET);
	}
	else
	{
		irq_ctl(RETURN_SPI_IRQ_NO(SPIx), RESET);
	}
}

void spi_irq_prio_config(SPI_t *SPIx, uint8_t prio)
{
	irq_prio_config(RETURN_SPI_IRQ_NO(SPIx), prio);
}











