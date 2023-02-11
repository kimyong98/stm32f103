/*
 * driver_.h
 *
 *  Created on: 2022. 5. 8.
 *      Author: 82107
 */

#ifndef INC_DRIVER__H_
#define INC_DRIVER__H_
#include "driver.h"
/********************************************************
typedef struct
{
	uint32_t SPEED;				//@_SPEED
	uint8_t	ADDRESS;
	uint8_t ACK;				//@ACK
	uint8_t FM_DUTY_CYCLE;		//@DUTY_CYCLE
}I2C_config_t;

typedef struct
{
	I2C_t *I2Cx;
	I2C_config_t config;
}I2C_handle_t;

/*
 * @_SPEED

#define I2C_SPEED_SM				100000
#define I2C_SPEED_FM4K				400000
#define I2C_SPEED_FM2K				200000

/*
 * @ACK

#define I2C_ACK_ENABLE				1
#define I2C_ACK_DISABLE				0

/*
 * @DUTY_CYCLE

#define I2C_FM_DUTY_2				0
#define I2C_FM_DUTY_16_9			1
********************************************************/

void i2c_clock_ctl(I2C_t *I2Cx);
void i2c_master_init(I2C_t *I2Cx);
void i2c_slave_init(I2C_t *I2Cx, uint8_t addr);
void i2c_ctl(I2C_t *I2Cx, uint8_t flag);
void i2c_master_send_data(I2C_t *I2Cx, uint8_t *data, uint8_t len, uint8_t addr);
void i2c_master_receive(I2C_t *I2Cx, uint8_t *data, uint8_t len, uint8_t addr);
void i2c_irq_ctl(I2C_t *I2Cx, uint8_t flag);
void i2c_irq_prio_config(I2C_t *I2Cx, uint8_t prio);
void i2c_irq_handling(void);


#endif /* INC_DRIVER__H_ */
