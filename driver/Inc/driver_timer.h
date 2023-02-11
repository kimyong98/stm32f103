/*
 * driver_timer.h
 *
 *  Created on: 2022. 4. 17.
 *      Author: 82107
 */

#ifndef INC_DRIVER_TIMER_H_
#define INC_DRIVER_TIMER_H_
#include "driver.h"

/*
 * Type definition of TIMER configuration and TIMER handler
 */
typedef struct{
	uint16_t PSC;				//prescaler
	uint16_t ARR;				//auto reload register
}TIM_config_t;

typedef struct{
	TIM_t *TIMx;
	TIM_config_t config;
}TIM_handle_t;

/*
 * @channel
 */
#define TIM_CH1						0
#define TIM_CH2						1
#define TIM_CH3						2
#define TIM_CH4						3


// Return TIMx IRQ Number Macro
#define RETURN_TIM_IRQ_NO(x)		(	(x == TIM2) ? 28:\
										(x == TIM3) ? 29:\
										(x == TIM4) ? 30:\
										(x == TIM5) ? 50:28	)

void timer_init(TIM_handle_t* TIM_handle);
/*
void timer_pwm_config(void);
void timer_pwm_enable(void);
*/
void pwm_init(TIM_t *TIMx, uint8_t ch);
void duty(TIM_t *TIMx, uint8_t ch, uint16_t duty);
void timer_enable(TIM_t *TIMx);

#endif /* INC_DRIVER_TIMER_H_ */
