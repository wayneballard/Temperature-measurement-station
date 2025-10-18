/*
 * pwm.c
 *
 *  Created on: Jan 24, 2025
 *      Author: limok
 */


#include "pwm.h"

void PWM_Init(PWM_Handle_TypeDef* hpwm){
  PWM_WriteDuty(hpwm, hpwm -> Duty);
  HAL_TIM_PWM_Start(hpwm -> Timer, hpwm -> Channel);
}


void PWM_WriteDuty(PWM_Handle_TypeDef* hpwm, float duty){
  if(duty < 0.0f)
    duty = 0.0;
  else if(duty > 100.0f)
    duty = 100.0f;
  hpwm -> Duty = duty;
  int compare_value = (duty * (__HAL_TIM_GET_AUTORELOAD(hpwm->Timer)+1)) / 100;
  __HAL_TIME_SET_COMPARE(hpwm -> Timer, hpwm -> Channel, compare_value);


}

float PWM_ReadDuty(const PWM_Handle_TypeDef* hpwm)
{
  return hpwm->Duty;
}


