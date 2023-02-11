/*
 * driver_i2c.c
 *
 *  Created on: 2022. 5. 8.
 *      Author: 82107
 */
#include "driver.h"
void i2c_clock_ctl(I2C_t *I2Cx)
{
	if(I2Cx == I2C1)
	{
		I2C1_PERIPHERAL_CLK_EN();
	}
	else
	{
		I2C2_PERIPHERAL_CLK_EN();
	}
}

void i2c_master_init(I2C_t *I2Cx)
{
	I2C1->CR1 |= (1<<15);  // reset the I2C
	uint32_t delay = 0x1FFFFF;
	while(delay != 0)
	{
		delay--;
	}
	I2C1->CR1 &= ~(1<<15);  // Normal operation

	//16MH
	I2Cx->CR2 |= 16;
	I2Cx->CCR |= 80;

	//trise
	I2Cx->TRISE |= 17;

	// enable I2c
	I2Cx->CR1 |= 1;

	//ACK
	I2Cx->CR1 |= 1 << 10;

}
void i2c_slave_init(I2C_t *I2Cx, uint8_t addr)
{


	//16MH
	I2Cx->CR2 |= 16;
	I2Cx->CCR |= 80;

	//address
	uint32_t temp = 0;
	temp |= 1 << 14;
	temp |= addr << 1;
	I2Cx->OAR1 |= temp;

	//trise
	I2Cx->TRISE = 17;

	// enable I2c
	I2Cx->CR1 |= 1;

	//ACK
	I2Cx->CR1 |= 1 << 10;
}

void i2c_master_send_data(I2C_t *I2Cx, uint8_t *data, uint8_t len, uint8_t addr)
{
	// start condition
	I2Cx->CR1 |= 1 << 8;
	// check SB
	while(!(I2Cx->SR1 & 1 << 0));
	// address phase
	uint8_t address = 0;
	address |= addr << 1;
	address &= ~(1);
	I2Cx->DR = address;
	// check addr
	while(!(I2Cx->SR1 & 1 << 1));
	// send all data
	while( len > 0)
	{
		// check TXE
		while(!(I2Cx->SR1 & 1 << 7));
		I2Cx->DR = *data;
		data++;
		len--;
	}
	// check TXE and BTF
	while(!(I2Cx->SR1 & 1 << 7));
	while(!(I2Cx->SR1 & 1 << 2));

	// stop condition
	I2Cx->CR1 |= 1 << 9;
}

void i2c_master_receive(I2C_t *I2Cx, uint8_t *data, uint8_t len, uint8_t addr)
{
	// start condition
	I2Cx->CR1 |= 1 << 8;
	// check SB
	while(!(I2Cx->SR1 & 1 << 0));
	// address phase
	uint8_t address = 0;
	address |= addr << 1;
	address &= 1;
	I2Cx->DR = address;
	// check addr
	while(!(I2Cx->SR1 & 1 << 1));

	// receive 1 byte
	if (len == 1)
	{
		// disable acking
		I2Cx->CR1 &= ~(1 << 10);
		// clear addr
		I2Cx->SR1 &= ~(1 << 1);
		// check RXNE
		while(!(I2Cx->SR1 & 1 << 7));
		//generate stop condition
		I2Cx->CR1 |= 1 << 9;
		// read
		*data = I2Cx->DR;

	}
	// send all data
	while( len > 1)
	{
		// clear addr
		I2Cx->SR1 &= ~(1 << 1);
		for(uint32_t i = len; i>0; i--)
		{
			// check RXNE
			while(!(I2Cx->SR1 & 1 << 7));
			if(i == 2)
			{
				// disable acking
				I2Cx->CR1 &= ~(1 << 10);
				//generate stop condition
				I2Cx->CR1 |= 1 << 9;
			}
			// read
			*data = I2Cx->DR;
			data++;
		}
	}
	//ACK
	I2Cx->CR1 |= 1 << 10;
}



















