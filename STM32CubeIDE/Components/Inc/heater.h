/*
 * heater.h
 *
 *  Created on: Jan 24, 2025
 *      Author: limok
 */

#ifndef INC_HEATER_H_
#define INC_HEATER_H_

#include "dio.h"
#include "pwm.h"

typedef enum {HEATER_ON_LOW, HEATER_ON_HIGH} Heater_Active_State_TypeDef;
typedef enum {HEATER_ON_DIO = 1, HEATER_OFF_DIO = 0} Heater_DIO_State_TypeDef;


typedef struct{
  DIO_Handle_TypeDef Output;
  Heater_Active_State_TypeDef ActiveState;
} HEATER_DIO_Handle_TypeDef;

typedef struct{
  PWM_Handle_TypeDef Output;
  Heater_Active_State_TypeDef ActiveState;
} HEATER_PWM_Handle_TypeDef;


#define HEATER_INIT_DIO_HANDLE(USER_NAME, ACTIVE_STATE) \
{                                                       \
  .Output = DIO_INIT_HANDLE(USER_NAME),               \
  .ActiveState = ACTIVE_STATE                         \
}

#define HEATER_INIT_PWM_HANDLE(TIMER, CHANNEL, ACTIVE_STATE)\
{                                                     \
  .Output = PWM_INIT_HANDLE((TIMER), CHANNEL),   \
  .ActiveState = ACTIVE_STATE                  \
}

void Heater_DIO_SetStateON(const HEATER_DIO_Handle_TypeDef* hhtr);
void Heater_DIO_SeteStateOFF(const HEATER_DIO_Handle_TypeDef* hhtr);
void Heater_DIO_ToggleState(const HEATER_DIO_Handle_TypeDef* hhtr);
void Heater_DIO_WriteState(const HEATER_DIO_Handle_TypeDef* hhtr, Heater_DIO_State_TypeDef state);
Heater_DIO_State_TypeDef HEATER_DIO_ReadState(const HEATER_DIO_Handle_TypeDef* hhtr);
void Heater_PWM_Init(HEATER_PWM_Handle_TypeDef* hhtr);
void Heater_PWM_WriteDuty(HEATER_PWM_Handle_TypeDef* hhtr, float duty);
float Heater_PWM_ReadDuty(HEATER_PWM_Handle_TypeDef* hhtr);


#endif /* INC_HEATER_H_ */
