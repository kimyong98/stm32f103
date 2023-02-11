/*
 * driver.h
 *
 *  Created on: Mar 27, 2022
 *      Author: 82107
 */

#ifndef DRIVER_H_
#define DRIVER_H_

#include <stdint.h>

/*
 * address definition according to RM0008 Reference manual
 */
/*
 * Bus address
 */
#define	PERIPH_BASEADDR						0x40000000U
#define APB1PERIPH_BASEADDR					PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR					0x40010000U
#define AHBPERIPH_BASEADDR					0x40018000U

/*
 * Base address of peripherals over APB1
 */
#define TIM2_BASEADDR						(APB1PERIPH_BASEADDR + 0x0000)
#define TIM3_BASEADDR						(APB1PERIPH_BASEADDR + 0x0400)
#define TIM4_BASEADDR						(APB1PERIPH_BASEADDR + 0x0800)
#define TIM5_BASEADDR						(APB1PERIPH_BASEADDR + 0x0C00)
#define TIM6_BASEADDR						(APB1PERIPH_BASEADDR + 0x1000)
#define TIM7_BASEADDR						(APB1PERIPH_BASEADDR + 0x1400)
#define TIM12_BASEADDR						(APB1PERIPH_BASEADDR + 0x1800)
#define TIM13_BASEADDR						(APB1PERIPH_BASEADDR + 0x1C00)
#define TIM14_BASEADDR						(APB1PERIPH_BASEADDR + 0x2000)
#define RTC_BASEADDR						(APB1PERIPH_BASEADDR + 0x2800)
#define WWDG_BASEADDR						(APB1PERIPH_BASEADDR + 0x2C00)
#define IWDG_BASEADDR						(APB1PERIPH_BASEADDR + 0x3000)
#define SPI2I2S_BASEADDR					(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3I2S_BASEADDR					(APB1PERIPH_BASEADDR + 0x3C00)
#define USART2_BASEADDR						(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR						(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR						(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR						(APB1PERIPH_BASEADDR + 0x5000)
#define I2C1_BASEADDR						(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR						(APB1PERIPH_BASEADDR + 0x5800)
#define CAN2_BASEADDR						(APB1PERIPH_BASEADDR + 0x6800)
#define CAN1_BASEADDR						(APB1PERIPH_BASEADDR + 0x6400)

/*
 * Base address of peripherals over APB2
 */
#define AFIO_BASEADDR						(APB2PERIPH_BASEADDR + 0x0000)
#define EXTI_BASEADDR						(APB2PERIPH_BASEADDR + 0x0400)
#define GPIOA_BASEADDR						(APB2PERIPH_BASEADDR + 0x0800)
#define GPIOB_BASEADDR						(APB2PERIPH_BASEADDR + 0x0C00)
#define GPIOC_BASEADDR						(APB2PERIPH_BASEADDR + 0x1000)
#define GPIOD_BASEADDR						(APB2PERIPH_BASEADDR + 0x1400)
#define GPIOE_BASEADDR						(APB2PERIPH_BASEADDR + 0x1800)
#define GPIOF_BASEADDR						(APB2PERIPH_BASEADDR + 0x1C00)
#define GPIOG_BASEADDR						(APB2PERIPH_BASEADDR + 0x2000)
#define ADC1_BASEADDR						(APB2PERIPH_BASEADDR + 0x2400)
#define ADC2_BASEADDR						(APB2PERIPH_BASEADDR + 0x2800)
#define TIM1_BASEADDR						(APB2PERIPH_BASEADDR + 0x2C00)
#define SPI1_BASEADDR						(APB2PERIPH_BASEADDR + 0x3000)
#define TIM8_BASEADDR						(APB2PERIPH_BASEADDR + 0x3400)
#define USART1_BASEADDR						(APB2PERIPH_BASEADDR + 0x3800)
#define ADC3_BASEADDR						(APB2PERIPH_BASEADDR + 0x3C00)
#define TIM9_BASEADDR						(APB2PERIPH_BASEADDR + 0x4C00)
#define TIM10_BASEADDR						(APB2PERIPH_BASEADDR + 0x5000)
#define TIM11_BASEADDR						(APB2PERIPH_BASEADDR + 0x5400)

/*
 * Base address of peripherals over AHB
 */
#define SDIO_BASEADDR						(AHBPERIPH_BASEADDR + 0X0000)
#define DMA1_BASEADDR						(AHBPERIPH_BASEADDR + 0X8000)
#define DMA2_BASEADDR						(AHBPERIPH_BASEADDR + 0X8400)
#define RCC_BASEADDR						(AHBPERIPH_BASEADDR + 0X9000)
#define FMI_BASEADDR						(AHBPERIPH_BASEADDR + 0XA000)
#define CRC_BASEADDR						(AHBPERIPH_BASEADDR + 0XB000)

/*
 * Base address of core peripherals
 */
#define STK_BASEADDR						0XE000E010U
#define NVIC_BASEADDR						0XE000E100U
#define SCB_BASEADDR						0XE000ED00U
#define MPU_BASEADDR						0XE000ED90U

/*
 * AFIO(Alternate function I/O)
 */
typedef struct{
	volatile uint32_t EVCR;					//Event control register
	volatile uint32_t MAPR;					//AF remap and debug I/O configuration register
	volatile uint32_t EXTICR1;				//External interrupt configuration register 1
	volatile uint32_t EXTICR2;				//External interrupt configuration register 2
	volatile uint32_t EXTICR3;				//External interrupt configuration register 3
	volatile uint32_t EXTICR4;				//External interrupt configuration register 4
	volatile uint32_t MAPR1;				//AF remap and debug I/O configuration register2
}AFIO_t;

#define AFIO								( (AFIO_t *)AFIO_BASEADDR )

/*
 * EXTI(External interrupt/event controller)
 */
typedef struct{
	volatile uint32_t IMR;					//Interrupt mask register
	volatile uint32_t EMR;					//Event mask register
	volatile uint32_t RTSR;					//Rising trigger selection register
	volatile uint32_t FTSR;					//Falling trigger selection register
	volatile uint32_t SWIER;				//Software interrupt event register
	volatile uint32_t PR;					//Pending register
}EXTI_t;

#define EXTI								( (EXTI_t *)EXTI_BASEADDR )

/*
 * GPIO(general-purpose I/O ports)
 */
typedef struct{
	volatile uint32_t CRL;					//Port configuration register low
	volatile uint32_t CRH;					//Port configuration register high
	volatile uint32_t IDR;					//Port input data register
	volatile uint32_t ODR;					//Port output data register
	volatile uint32_t BSRR;					//Port bit set/reset register
	volatile uint32_t BRR;					//Port bit reset register
	volatile uint32_t LCKR;					//Port configuration lock register
}GPIO_t;

#define GPIOA								( (GPIO_t *)GPIOA_BASEADDR )
#define GPIOB								( (GPIO_t *)GPIOB_BASEADDR )
#define GPIOC								( (GPIO_t *)GPIOC_BASEADDR )
#define GPIOD								( (GPIO_t *)GPIOD_BASEADDR )
#define GPIOE								( (GPIO_t *)GPIOE_BASEADDR )
#define GPIOF								( (GPIO_t *)GPIOF_BASEADDR )
#define GPIOG								( (GPIO_t *)GPIOG_BASEADDR )

/*
 * RCC(Reset and clock control)
 */
typedef struct{
	volatile uint32_t CR;					//Clock control register
	volatile uint32_t CFGR;					//Clock configuration register
	volatile uint32_t CIR;					//Clock interrupt register
	volatile uint32_t APB2RSTR;				//APB2 peripheral reset register
	volatile uint32_t APB1RSTR;				//APB1 peripheral reset register
	volatile uint32_t AHBENR;				//AHB Peripheral Clock enable register
	volatile uint32_t APB2ENR;				//APB2 peripheral clock enable register
	volatile uint32_t APB1ENR;				//APB1 peripheral clock enable register
	volatile uint32_t BDCR;					//Backup domain control register
	volatile uint32_t CSR;					//Control/status register
	volatile uint32_t AHBSTR;				//AHB peripheral clock reset register
	volatile uint32_t CFGR2;					//Clock configuration register2
}RCC_t;

#define RCC		((RCC_t *)RCC_BASEADDR)

/*
 * SPI(Serial peripheral interface)
 */
typedef struct{
	volatile uint32_t CR1;					//SPI control register 1
	volatile uint32_t CR2;					//SPI control register 2
	volatile uint32_t SR;					//SPI status register
	volatile uint32_t DR;					//SPI data register
	volatile uint32_t CRCPR;				//SPI CRC polynomial register
	volatile uint32_t RXCRCR;				//SPI RX CRC register
	volatile uint32_t TXCRCR;				//SPI TX CRC register
	volatile uint32_t I2SCFGR;				//SPI_I2S configuration register
	volatile uint32_t I2SPR;				//SPI_I2S prescaler register
}SPI_t;

#define SPI1								( (SPI_t *)SPI1_BASEADDR)
#define SPI2								( (SPI_t *)SPI2I2S_BASEADDR)
#define SPI3								( (SPI_t *)SPI3I2S_BASEADDR)

/*
 * Tim(TIMER)
 */
typedef struct{
	volatile uint32_t CR1;					//TIMx control register 1
	volatile uint32_t CR2;					//TIMx control register 2
	volatile uint32_t SMCR;					//TIMx slave mode control register
	volatile uint32_t DIER;					//TIMx DMA/Interrupt enable register
	volatile uint32_t SR;					//TIMx status register
	volatile uint32_t EGR;					//TIMx event generation register
	volatile uint32_t CCMR1;				//TIMx capture/compare mode register 1
	volatile uint32_t CCMR2;				//TIMx capture/compare mode register 2
	volatile uint32_t CCER;					//TIMx capture/compare enable register
	volatile uint32_t CNT;					//TIMx counter
	volatile uint32_t PSC;					//TIMx prescaler
	volatile uint32_t ARR;					//TIMx auto-reload register
	volatile uint32_t RESERVED1;			//RESERVED1
	volatile uint32_t CCR1;					//TIMx capture/compare register 1
	volatile uint32_t CCR2;					//TIMx capture/compare register 2
	volatile uint32_t CCR3;					//TIMx capture/compare register 3
	volatile uint32_t CCR4;					//TIMx capture/compare register 4
	volatile uint32_t RESERVED2;			//RESERVED2
	volatile uint32_t DCR;					//TIMx DMA control register
	volatile uint32_t DMAR;					//TIMx DMA address for full transfer
}TIM_t;

#define TIM2								( (TIM_t *)TIM2_BASEADDR)
#define TIM3								( (TIM_t *)TIM3_BASEADDR)
#define TIM4								( (TIM_t *)TIM4_BASEADDR)
#define TIM5								( (TIM_t *)TIM5_BASEADDR)

/*
 * I2C
 */
typedef struct{
	volatile uint32_t CR1;					//I2C Control register 1
	volatile uint32_t CR2;					//I2C Control register 2
	volatile uint32_t OAR1;					//I2C Own address register 1
	volatile uint32_t OAR2;					//I2C Own address register 2
	volatile uint32_t DR;					//I2C Data register
	volatile uint32_t SR1;					//I2C Status register 1
	volatile uint32_t SR2;					//I2C Status register 2
	volatile uint32_t CCR;					//I2C Clock control register
	volatile uint32_t TRISE;				//I2C TRISE register
}I2C_t;
#define I2C1								( (I2C_t *)I2C1_BASEADDR)
#define I2C2								( (I2C_t *)I2C2_BASEADDR)

/*
 * UART
 */
typedef struct{
	volatile uint32_t SR;					//Status register
	volatile uint32_t DR;					//Data register
	volatile uint32_t BRR;					//Baud rate register
	volatile uint32_t CR1;					//Control register 1
	volatile uint32_t CR2;					//Control register 2
	volatile uint32_t CR3;					//Control register 3
	volatile uint32_t GTPR;					//Guard time and prescaler register
}USART_t;
#define USART1								( (USART_t *)USART1_BASEADDR)
#define USART2								( (USART_t *)USART2_BASEADDR)
#define USART3								( (USART_t *)USART3_BASEADDR)
#define UART4								( (USART_t *)UART4_BASEADDR)
#define UART5								( (USART_t *)UART5_BASEADDR)


/*
 * FMI(Flash memory interface)
 */
#define FLASH_ACR							( (volatile uint32_t *)0X40022000 )


/*
 * General Macro
 */
// set/reset, enable/disable
#define SET									1
#define RESET								0
#define ENABLE								SET
#define DISABLE								RESET

// Clock Enable for peripheral
#define AFIO_PERIPHERAL_CLK_EN()			(RCC->APB2ENR |= (1 << 0))
#define GPIOA_PERIPHERAL_CLK_EN()			(RCC->APB2ENR |= (1 << 2))
#define GPIOB_PERIPHERAL_CLK_EN()			(RCC->APB2ENR |= (1 << 3))
#define GPIOC_PERIPHERAL_CLK_EN()			(RCC->APB2ENR |= (1 << 4))
#define GPIOD_PERIPHERAL_CLK_EN()			(RCC->APB2ENR |= (1 << 5))
#define GPIOE_PERIPHERAL_CLK_EN()			(RCC->APB2ENR |= (1 << 6))
#define SPI1_PERIPHERAL_CLK_EN()			(RCC->APB2ENR |= (1 << 12))
#define SPI2_PERIPHERAL_CLK_EN()			(RCC->APB1ENR |= (1 << 14))
#define SPI3_PERIPHERAL_CLK_EN()			(RCC->APB1ENR |= (1 << 15))
#define TIM2_PERIPHERAL_CLK_EN()			(RCC->APB1ENR |= (1 << 0))
#define TIM3_PERIPHERAL_CLK_EN()			(RCC->APB1ENR |= (1 << 1))
#define TIM4_PERIPHERAL_CLK_EN()			(RCC->APB1ENR |= (1 << 2))
#define TIM5_PERIPHERAL_CLK_EN()			(RCC->APB1ENR |= (1 << 3))
#define	I2C1_PERIPHERAL_CLK_EN()			(RCC->APB1ENR |= (1 << 21))
#define	I2C2_PERIPHERAL_CLK_EN()			(RCC->APB1ENR |= (1 << 22))


// Clock Disable for peripheral
#define AFIO_PERIPHERAL_CLK_DI()			(RCC->APB2ENR &= ~(1 << 0))
#define GPIOA_PERIPHERAL_CLK_DI()			(RCC->APB2ENR &= ~(1 << 2))
#define GPIOB_PERIPHERAL_CLK_DI()			(RCC->APB2ENR &= ~(1 << 3))
#define GPIOC_PERIPHERAL_CLK_DI()			(RCC->APB2ENR &= ~(1 << 4))
#define GPIOD_PERIPHERAL_CLK_DI()			(RCC->APB2ENR &= ~(1 << 5))
#define GPIOE_PERIPHERAL_CLK_DI()			(RCC->APB2ENR &= ~(1 << 6))
#define SPI1_PERIPHERAL_CLK_DI()			(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PERIPHERAL_CLK_DI()			(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PERIPHERAL_CLK_DI()			(RCC->APB1ENR &= ~(1 << 15))
#define TIM2_PERIPHERAL_CLK_DI()			(RCC->APB1ENR &= ~(1 << 0))
#define TIM3_PERIPHERAL_CLK_DI()			(RCC->APB1ENR &= ~(1 << 1))
#define TIM4_PERIPHERAL_CLK_DI()			(RCC->APB1ENR &= ~(1 << 2))
#define TIM5_PERIPHERAL_CLK_DI()			(RCC->APB1ENR &= ~(1 << 3))
#define	I2C1_PERIPHERAL_CLK_DI()			(RCC->APB1ENR &= ~(1 << 21))
#define	I2C2_PERIPHERAL_CLK_DI()			(RCC->APB1ENR &= ~(1 << 22))


// Reset register for peripheral
#define AFiO_PERIPHERAL_RESET()				do{(RCC->APB2RSTR |= (1 << 0)); (RCC->APB2RSTR &= ~(1 << 0));}while(0)
#define GPIOA_PERIPHERAL_RESET()			do{(RCC->APB2RSTR |= (1 << 2)); (RCC->APB2RSTR &= ~(1 << 2));}while(0)
#define GPIOB_PERIPHERAL_RESET()			do{(RCC->APB2RSTR |= (1 << 3)); (RCC->APB2RSTR &= ~(1 << 3));}while(0)
#define GPIOC_PERIPHERAL_RESET()			do{(RCC->APB2RSTR |= (1 << 4)); (RCC->APB2RSTR &= ~(1 << 4));}while(0)
#define GPIOD_PERIPHERAL_RESET()			do{(RCC->APB2RSTR |= (1 << 5)); (RCC->APB2RSTR &= ~(1 << 5));}while(0)
#define GPIOE_PERIPHERAL_RESET()			do{(RCC->APB2RSTR |= (1 << 6)); (RCC->APB2RSTR &= ~(1 << 6));}while(0)

#include "driver_rcc.h"
#include "driver_gpio.h"
#include "driver_spi.h"
#include "driver_interrupt.h"
#include "driver_timer.h"
#include "driver_i2c.h"
#include "driver_leg.h"
#include "driver_usart.h"
//#include "driver_i2c.h"
#endif /* DRIVER_H_ */
