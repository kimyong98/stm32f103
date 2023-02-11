/*
 * driver_uart.h
 *
 *  Created on: 2022. 8. 11.
 *      Author: injog
 */

#ifndef INC_DRIVER_USART_H_
#define INC_DRIVER_USART_H_
#include "driver.h"

void usart_init(USART_t * USARTx);
void usart_putc(USART_t * pUSARTx, uint8_t data);
uint8_t usart_getc(USART_t * pUSARTx);
void usart_irq_ctl(USART_t * pUSARTx);

#endif /* INC_DRIVER_USART_H_ */
