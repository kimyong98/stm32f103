/*
 * driver_spi.h
 *
 *  Created on: 2022. 4. 1.
 *      Author: 82107
 */

#ifndef INC_DRIVER_SPI_H_
#define INC_DRIVER_SPI_H_

#include "driver.h"

/*
 * Type definition of SPI configuration and SPI handler
 */
typedef struct{
	uint8_t MODE;					// @ MODE of spi
	uint8_t METHOD;					// @ Commnication METHOD
	uint8_t DFF;					// @ Data Frame Format
	uint8_t SSM;					// @ Software slave management
	uint8_t BAUD;					// @ Baud rate
	uint8_t CPOL;					// @ Clock polarity
	uint8_t CPHA;					// @ Clock phase
}SPI_config_t;

typedef struct{
	SPI_t *SPIx;
	SPI_config_t config;
}SPI_handle_t;

/*
 * Macro for SPI
 */
// @ MODE of spi
#define SPI_MODE_M					1
#define SPI_MODE_S					0

// @ Commnication METHOD
#define SPI_METHOD_FD				0		// FULL DUPLEX
#define SPI_METHOD_HD				1		// HALF DUPLEX
#define SPI_METHOD_SP_RX			2		// SIMPLEX RECIEVE

// @ Data Frame Format
#define SPI_DFF_8					0		// 8bits for 1 frame
#define SPI_DFF_16					1		// 16bits for 1 frame

// @ Software slave management
#define SPI_SSM_HW					0
#define SPI_SSM_SW					1

// @ Baud rate
#define SPI_BAUD_DIV_2				0
#define SPI_BAUD_DIV_4				1
#define SPI_BAUD_DIV_8				2
#define SPI_BAUD_DIV_16				3
#define SPI_BAUD_DIV_32				4
#define SPI_BAUD_DIV_64				5
#define SPI_BAUD_DIV_128			6
#define SPI_BAUD_DIV_256			7

// @ Clock polarity
#define SPI_CPOL_L					0
#define SPI_CPOL_H					1

// @ Clock phase
#define SPI_CPHA_F					0
#define SPI_CPHA_S					1

// Return SPIx IRQ Number Macro
#define RETURN_SPI_IRQ_NO(x)		(	(x == SPI1) ? 35:\
										(x == SPI2) ? 36:\
										(x == SPI3) ? 51:35	)

void spi_clock_ctl(SPI_t *SPIx);
void spi_init(SPI_handle_t *SPI_handle);
void spi_ctl(SPI_t *SPIx, uint8_t flag);
void spi_send(SPI_t *SPIx, uint8_t *data, uint8_t len);
void spi_receive(SPI_t *SPIx, uint8_t *data, uint8_t len);
void spi_irq_ctl(SPI_t *SPIx, uint8_t flag);
void spi_irq_prio_config(SPI_t *SPIx, uint8_t prio);
void spi_irq_handling(void);

#endif /* INC_DRIVER_SPI_H_ */
