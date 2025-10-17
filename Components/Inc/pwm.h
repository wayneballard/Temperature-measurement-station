/*
 * pwm.h
 *
 *  Created on: Jan 24, 2025
 *      Author: limok
 */

#ifndef INC_PWM_H_
#define INC_PWM_H_

#ifdef USE_HAL_DRIVER
#include "stm32f7xx_hal.h"
#endif

#ifdef USE_HAL_DRIVER
typedef TIM_HandleTypeDef* PWM_TIM_TypeDef;
typedef uint32_t PWM_Channel_TypeDef;
#endif

typedef struct{
  PWM_TIM_TypeDef Timer;
  PWM_Channel_TypeDef Channel;
  float Duty;
} PWM_Handle_TypeDef;


#ifdef USE_HAL_DRIVER
#define PWM_INIT_HANDLE(TIMER, CHANNEL)      \
{                                            \
  .Timer = TIMER,                            \
  .Channel = CHANNEL,                        \
  .Duty = 0.0f                               \
}
#endif


void PWM_Init(PWM_Handle_TypeDef* hpwm);
void PWM_WriteDuty(PWM_Handle_TypeDef* hpwm, float duty);
float PWM_ReadDuty(const PWM_Handle_TypeDef* hpwm); //set Duty Cycle
#endif /* INC_PWM_H_ */
