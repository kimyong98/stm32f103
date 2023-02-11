/*
 * driver_uart.c
 *
 *  Created on: 2022. 8. 11.
 *      Author: injog
 */
#include "driver.h"
int sem = 0;
void usart_init(USART_t * pUSARTx)
{

/******************************** Configuration of CR1******************************************/

	//Implement the code to enable the Clock for given USART peripheral
	 if(pUSARTx == USART1)
	 {
		 RCC->APB2ENR |= 1 << 14;
	 }
	 else if(pUSARTx == USART2)
	 {
		 RCC->APB1ENR |= 1 << 17;
	 }
	 else if(pUSARTx == USART3)
	 {
		 RCC->APB1ENR |= 1 << 18;
	 }
	 else if(pUSARTx == UART4)
	 {
		 RCC->APB1ENR |= 1 << 19;
	 }
	 else if(pUSARTx == UART5)
	 {
		 RCC->APB1ENR |= 1 << 20;
	 }

	 pUSARTx->CR1 |= 1 << 13;

	 pUSARTx->BRR = 0x683;


	 pUSARTx->CR1 |= 1 << 2;
	 pUSARTx->CR1 |= 1 << 3;


}



void usart_putc(USART_t * pUSARTx, uint8_t data)
{
	while(!(pUSARTx->SR & (1 << 7)));  //wait for Tx Empty flag
    pUSARTx->DR = data;         //write to DR register
    while(!(pUSARTx->SR & (1 << 6)));
}


uint8_t usart_getc(USART_t * pUSARTx)
{
	uint8_t data;
    while(!(pUSARTx->SR & (1 << 5)));   //wait for Rx Not Empty flag
    data = (uint8_t)pUSARTx->DR;
    return data; //read from DR register
}

void usart_irq_ctl(USART_t * pUSARTx)
{
	if(pUSARTx == USART1)
	{
		irq_ctl(37, SET);
	}
	else if(pUSARTx == USART2)
	{
		irq_ctl(38, SET);
	}
	else if(pUSARTx == USART3)
	{
		irq_ctl(39, SET);
	}
	else if(pUSARTx == UART4)
	{
		irq_ctl(52, SET);
	}
	else if(pUSARTx == UART5)
	{
		irq_ctl(53, SET);
	}
	pUSARTx->CR1 |= (1<<7) | (1<<6) | ((1<<5));
}

void USART1_IRQHandler(void)
{
	uint8_t data;
	data = usart_getc(USART1);
	if(data == 'a')
	{
		//gpio_toggle_pin(GPIOA, GPIO_PIN_NO5);
		duty(TIM2, TIM_CH2, 90);
		duty(TIM3, TIM_CH3, 50);
		//4's leg
		duty(TIM3, TIM_CH2, 60);
		duty(TIM4, TIM_CH1, 100);
		//1's leg
		duty(TIM4, TIM_CH2, 90);
		duty(TIM2, TIM_CH1, 50);
		//3's leg
		duty(TIM4, TIM_CH4, 60);
		duty(TIM3, TIM_CH1, 100);
		/*
		sem = 1;
		while(delay != 0)
		{
			delay--;
		}
		*/
	}
}
