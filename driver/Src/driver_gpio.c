/*
 * driver_gpio.c
 *
 *  Created on: 2022. 3. 29.
 *      Author: 82107
 */
#include "driver.h "

void gpio_clock_ctl(GPIO_t *GPIOx)
{
	if(GPIOx == GPIOA)
	{
		GPIOA_PERIPHERAL_CLK_EN();
	}
	else if(GPIOx == GPIOB)
	{
		GPIOB_PERIPHERAL_CLK_EN();
	}
	else if(GPIOx == GPIOC)
	{
		GPIOC_PERIPHERAL_CLK_EN();
	}
	else if(GPIOx == GPIOD)
	{
		GPIOD_PERIPHERAL_CLK_EN();
	}
	else if(GPIOx == GPIOE)
	{
		GPIOE_PERIPHERAL_CLK_EN();
	}
}

void gpio_init(GPIO_handle_t *GPIO_handle)
{
	uint8_t HLflag = GPIO_handle->config.PIN_NO / 8;
	uint8_t offset = (GPIO_handle->config.PIN_NO % 8) * 4;
	if(GPIO_handle->config.MODE == GPIO_MODE_IP_AN)
	{
		// ANALOG configuration later
	}
	else if(GPIO_handle->config.MODE == GPIO_MODE_IP_FL)
	{
		if(HLflag == 1)
		{
			GPIO_handle->GPIOx->CRH &= ~(15 << offset);
			GPIO_handle->GPIOx->CRH |= (4 << offset);
		}
		else
		{
			GPIO_handle->GPIOx->CRL &= ~(15 << offset);
			GPIO_handle->GPIOx->CRL |= (4 << offset);
		}
	}
	else if(GPIO_handle->config.MODE == GPIO_MODE_IP_PD)
	{
		if(HLflag == 1)
		{
			GPIO_handle->GPIOx->CRH &= ~(15 << offset);
			GPIO_handle->GPIOx->CRH |= (8 << offset);
			GPIO_handle->GPIOx->ODR &= ~(1 << GPIO_handle->config.PIN_NO);
		}
		else
		{
			GPIO_handle->GPIOx->CRL &= ~(15 << offset);
			GPIO_handle->GPIOx->CRL |= (8 << offset);
			GPIO_handle->GPIOx->ODR &= ~(1 << GPIO_handle->config.PIN_NO);
		}
	}
	else if(GPIO_handle->config.MODE == GPIO_MODE_IP_PU)
	{
		if(HLflag == 1)
		{
			GPIO_handle->GPIOx->CRH &= ~(15 << offset);
			GPIO_handle->GPIOx->CRH |= (8 << offset);
			GPIO_handle->GPIOx->ODR |= (1 << GPIO_handle->config.PIN_NO);
		}
		else
		{
			GPIO_handle->GPIOx->CRL &= ~(15 << offset);
			GPIO_handle->GPIOx->CRL |= (8 << offset);
			GPIO_handle->GPIOx->ODR |= (1 << GPIO_handle->config.PIN_NO);
		}
	}
	else if(GPIO_handle->config.MODE == GPIO_MODE_OP_PP)
	{
		if(HLflag == 1)
		{
			GPIO_handle->GPIOx->CRH &= ~(15 << offset);
			if(GPIO_handle->config.SPEED == GPIO_SPEED_10MH)
			{
				GPIO_handle->GPIOx->CRH |= (1 << offset);
			}
			else if(GPIO_handle->config.SPEED == GPIO_SPEED_2MH)
			{
				GPIO_handle->GPIOx->CRH |= (2 << offset);
			}
			else
			{
				GPIO_handle->GPIOx->CRH |= (3 << offset);
			}
		}
		else
		{
			GPIO_handle->GPIOx->CRL &= ~(15 << offset);
			if(GPIO_handle->config.SPEED == GPIO_SPEED_10MH)
			{
				GPIO_handle->GPIOx->CRL |= (1 << offset);
			}
			else if(GPIO_handle->config.SPEED == GPIO_SPEED_2MH)
			{
				GPIO_handle->GPIOx->CRL |= (2 << offset);
			}
			else
			{
				GPIO_handle->GPIOx->CRL |= (3 << offset);
			}
		}
	}
	else if(GPIO_handle->config.MODE == GPIO_MODE_OP_OD)
	{
		if(HLflag == 1)
		{
			GPIO_handle->GPIOx->CRH &= ~(15 << offset);
			if(GPIO_handle->config.SPEED == GPIO_SPEED_10MH)
			{
				GPIO_handle->GPIOx->CRH |= (5 << offset);
			}
			else if(GPIO_handle->config.SPEED == GPIO_SPEED_2MH)
			{
				GPIO_handle->GPIOx->CRH |= (6 << offset);
			}
			else
			{
				GPIO_handle->GPIOx->CRH |= (7 << offset);
			}
		}
		else
		{
			GPIO_handle->GPIOx->CRL &= ~(15 << offset);
			if(GPIO_handle->config.SPEED == GPIO_SPEED_10MH)
			{
				GPIO_handle->GPIOx->CRL |= (5 << offset);
			}
			else if(GPIO_handle->config.SPEED == GPIO_SPEED_2MH)
			{
				GPIO_handle->GPIOx->CRL |= (6 << offset);
			}
			else
			{
				GPIO_handle->GPIOx->CRL |= (7 << offset);
			}
		}
	}
	else if(GPIO_handle->config.MODE == AFIO_MODE_OP_PP)
	{
		if(HLflag == 1)
		{
			GPIO_handle->GPIOx->CRH &= ~(15 << offset);
			if(GPIO_handle->config.SPEED == GPIO_SPEED_10MH)
			{
				GPIO_handle->GPIOx->CRH |= (9 << offset);
			}
			else if(GPIO_handle->config.SPEED == GPIO_SPEED_2MH)
			{
				GPIO_handle->GPIOx->CRH |= (10 << offset);
			}
			else
			{
				GPIO_handle->GPIOx->CRH |= (11 << offset);
			}
		}
		else
		{
			GPIO_handle->GPIOx->CRL &= ~(15 << offset);
			if(GPIO_handle->config.SPEED == GPIO_SPEED_10MH)
			{
				GPIO_handle->GPIOx->CRL |= (9 << offset);
			}
			else if(GPIO_handle->config.SPEED == GPIO_SPEED_2MH)
			{
				GPIO_handle->GPIOx->CRL |= (10 << offset);
			}
			else
			{
				GPIO_handle->GPIOx->CRL |= (11 << offset);
			}
		}
	}
	else if(GPIO_handle->config.MODE == AFIO_MODE_OP_OD)
	{
		if(HLflag == 1)
		{
			GPIO_handle->GPIOx->CRH &= ~(15 << offset);
			if(GPIO_handle->config.SPEED == GPIO_SPEED_10MH)
			{
				GPIO_handle->GPIOx->CRH |= (13 << offset);
			}
			else if(GPIO_handle->config.SPEED == GPIO_SPEED_2MH)
			{
				GPIO_handle->GPIOx->CRH |= (14 << offset);
			}
			else
			{
				GPIO_handle->GPIOx->CRH |= (15 << offset);
			}
		}
		else
		{
			GPIO_handle->GPIOx->CRL &= ~(15 << offset);
			if(GPIO_handle->config.SPEED == GPIO_SPEED_10MH)
			{
				GPIO_handle->GPIOx->CRL |= (13 << offset);
			}
			else if(GPIO_handle->config.SPEED == GPIO_SPEED_2MH)
			{
				GPIO_handle->GPIOx->CRL |= (14 << offset);
			}
			else
			{
				GPIO_handle->GPIOx->CRL |= (15 << offset);
			}
		}
	}
}

void gpio_deinit(GPIO_t *GPIOx)
{
	if(GPIOx == GPIOA)
	{
		GPIOA_PERIPHERAL_RESET();
	}
	else if(GPIOx == GPIOB)
	{
		GPIOB_PERIPHERAL_RESET();
	}
	else if(GPIOx == GPIOC)
	{
		GPIOC_PERIPHERAL_RESET();
	}
	else if(GPIOx == GPIOD)
	{
		GPIOD_PERIPHERAL_RESET();
	}
	else if(GPIOx == GPIOE)
	{
		GPIOE_PERIPHERAL_RESET();
	}
}

void gpio_exti_config(GPIO_handle_t *GPIO_handle)
{
	// AFIO clock enable
	AFIO_PERIPHERAL_CLK_EN();

	// EXTI Line configure
	uint8_t EXTIx = GPIO_handle->config.PIN_NO / 4;
	uint8_t offset = 4 * (GPIO_handle->config.PIN_NO % 4);
	if(EXTIx == 0)
	{
		AFIO->EXTICR1 |= (IS_GPIOx(GPIO_handle->GPIOx) << offset);
	}
	else if(EXTIx == 1)
	{
		AFIO->EXTICR2 |= (IS_GPIOx(GPIO_handle->GPIOx) << offset);
	}
	else if(EXTIx == 2)
	{
		AFIO->EXTICR3 |= (IS_GPIOx(GPIO_handle->GPIOx) << offset);
	}
	else if(EXTIx == 3)
	{
		AFIO->EXTICR4 |= (IS_GPIOx(GPIO_handle->GPIOx) << offset);
	}
	// Configure the mask bits of the 20 Interrupt lines (EXTI_IMR)
	EXTI->IMR |= (1 << GPIO_handle->config.PIN_NO);
	//Configure the Trigger Selection bits of the Interrupt lines (EXTI_RTSR and EXTI_FTSR)
	if(GPIO_handle->config.TRIGGER == GPIO_IT_TR_RI)
	{
		EXTI->RTSR |= (1 << GPIO_handle->config.PIN_NO);
	}
	else if(GPIO_handle->config.TRIGGER == GPIO_IT_TR_FA)
	{
		EXTI->FTSR |= (1 << GPIO_handle->config.PIN_NO);
	}
	else if(GPIO_handle->config.TRIGGER == GPIO_IT_TR_RF)
	{
		EXTI->RTSR |= (1 << GPIO_handle->config.PIN_NO);
		EXTI->FTSR |= (1 << GPIO_handle->config.PIN_NO);
	}


}

void gpio_irq_init(GPIO_handle_t *GPIO_handle)
{
	uint8_t no = GPIO_handle->config.PIN_NO;
	if(no <= GPIO_PIN_NO4)
	{
		*((volatile uint32_t *)NVIC_BASEADDR) |= ( 1 << (GPIO_handle->config.PIN_NO + 6) );
	}
	else if((no > GPIO_PIN_NO4) && (no <= GPIO_PIN_NO9))
	{
		*((volatile uint32_t *)NVIC_BASEADDR) |= (1 << 23);
	}
	else if((no > GPIO_PIN_NO9) && (no <= GPIO_PIN_NO15))
	{
		*((volatile uint32_t *)(NVIC_BASEADDR+0X4)) |= (1 << 8);
	}
}


uint8_t gpio_read_pin(GPIO_t *GPIOx, uint8_t PIN_NO)
{
	if(GPIOx->IDR & (1 << PIN_NO))
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void gpio_write_pin(GPIO_t *GPIOx, uint8_t PIN_NO, uint8_t value)
{
	if(value == SET)
	{
		GPIOx->BSRR |= (1 << PIN_NO);
	}
	else
	{
		GPIOx->BSRR |= (1 << (PIN_NO + 16));
	}
}

void gpio_toggle_pin(GPIO_t *GPIOx, uint8_t PIN_NO)
{
	if(GPIOx->ODR & (1 << PIN_NO))
	{
		GPIOx->BSRR |= (1 << (PIN_NO + 16));
	}
	else
	{
		GPIOx->BSRR |= (1 << PIN_NO);
	}
}






