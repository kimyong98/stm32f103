/*
 * driver_gpio.h
 *
 *  Created on: 2022. 3. 29.
 *      Author: 82107
 */

#ifndef INC_DRIVER_GPIO_H_
#define INC_DRIVER_GPIO_H_

#include "driver.h "

/*
 * Type definition of GPIO configuration and GPIO handler
 */
typedef struct{
	uint8_t PIN_NO;			// @Pin number
	uint8_t	MODE;			// @Pin mode
	uint8_t SPEED;			// @Output mode speed
	uint8_t TRIGGER;		// @Interrupt TRIGGER
}GPIO_config_t;

typedef struct{
	GPIO_t *GPIOx;
	GPIO_config_t config;
}GPIO_handle_t;


/*
 * Macro for GOIO
 */
// @Pin number
#define GPIO_PIN_NO0					0
#define GPIO_PIN_NO1					1
#define GPIO_PIN_NO2					2
#define GPIO_PIN_NO3					3
#define GPIO_PIN_NO4					4
#define GPIO_PIN_NO5					5
#define GPIO_PIN_NO6					6
#define GPIO_PIN_NO7					7
#define GPIO_PIN_NO8					8
#define GPIO_PIN_NO9					9
#define GPIO_PIN_NO10					10
#define GPIO_PIN_NO11					11
#define GPIO_PIN_NO12					12
#define GPIO_PIN_NO13					13
#define GPIO_PIN_NO14					14
#define GPIO_PIN_NO15					15

// @Pin mode
#define GPIO_MODE_IP_AN					0				//Input Analog
#define GPIO_MODE_IP_FL					1				//Input floating
#define GPIO_MODE_IP_PD					2				//Input pull-down
#define GPIO_MODE_IP_PU					3				//Input pull-up
#define GPIO_MODE_OP_PP					4				//General purpose output Push-pull
#define GPIO_MODE_OP_OD					5				//General purpose output Open-drain
#define AFIO_MODE_OP_PP					6				//Alternate Function output Push-pull
#define AFIO_MODE_OP_OD					7				//Alternate Function output Open-drain

// @Output mode speed
#define GPIO_SPEED_10MH					1				//Maximum output speed 10MHZ
#define GPIO_SPEED_2MH					2				//Maximum output speed 2 MHz
#define GPIO_SPEED_50MH					3				//Maximum output speed 50 MHz

// @Interrupt TRIGGER
#define GPIO_IT_NONE					0				//None of interrupt
#define GPIO_IT_TR_RI					1				//Interrupt trigger for rising edge
#define GPIO_IT_TR_FA					2				//Interrupt trigger for falling edge
#define GPIO_IT_TR_RF					3				//Interrupt trigger for rising and falling edge

// Return GPIOx Macro
#define IS_GPIOx(x)		(	(x == GPIOA) ? 0:\
							(x == GPIOB) ? 1:\
							(x == GPIOC) ? 2:\
							(x == GPIOD) ? 3:\
							(x == GPIOE) ? 4:\
							(x == GPIOF) ? 5:\
							(x == GPIOG) ? 6:0	)

void gpio_clock_ctl(GPIO_t *GPIOx);

void gpio_init(GPIO_handle_t *GPIO_handle);
void gpio_deinit(GPIO_t *GPIOx);
void gpio_exti_config(GPIO_handle_t *GPIO_handle);
void gpio_irq_init(GPIO_handle_t *GPIO_handle);

uint8_t gpio_read_pin(GPIO_t *GPIOx, uint8_t PIN_NO);
void gpio_write_pin(GPIO_t *GPIOx, uint8_t PIN_NO, uint8_t value);
void gpio_toggle_pin(GPIO_t *GPIOx, uint8_t PIN_NO);


#endif /* INC_DRIVER_GPIO_H_ */
