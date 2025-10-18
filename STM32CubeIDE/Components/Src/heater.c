/*
 * heater.c
 *
 *  Created on: Jan 25, 2025
 *      Author: limok
 */

#include "heater.h"


void Heater_DIO_WriteState(const HEATER_DIO_Handle_TypeDef* hhtr, Heater_DIO_State_TypeDef state)
{
  DIO_Write(&(hhtr->Output), (hhtr->ActiveState == HEATER_ON_HIGH) ? state : !state);
}

void Heater_DIO_SetStateOn(const HEATER_DIO_Handle_TypeDef* hhtr){
  Heater_DIO_WriteState(hhtr, HEATER_ON_DIO);
}

void Heater_DIO_SetStateOff(const HEATER_DIO_Handle_TypeDef* hhtr){
  Heater_DIO_WriteState(hhtr, HEATER_OFF_DIO);
}


void Heater_DIO_ToggleState(const HEATER_DIO_Handle_TypeDef* hhtr){
  DIO_Toggle(&(hhtr->Output));
}


Heater_DIO_State_TypeDef HEATER_DIO_ReadState(const HEATER_DIO_Handle_TypeDef* hhtr){
  _Bool state = DIO_Read(&(hhtr -> Output));
    return (hhtr->ActiveState == HEATER_ON_HIGH) ? state : !state;
}

void Heater_PWM_Init(HEATER_PWM_Handle_TypeDef* hhtr){
  hhtr -> Output.Duty = (hhtr -> ActiveState == HEATER_ON_HIGH) ? (hhtr -> Output.Duty) : (100.0f - hhtr -> Output.Duty);
  PWN_Init(&(hhtr -> Output));
}


void Heater_PWM_WriteDuty(HEATER_PWM_Handle_TypeDef* hhtr, float duty){
  hhtr -> Output.Duty = (hhtr -> ActiveState == HEATER_ON_HIGH) ? (duty) : (100.0f - duty);
  PWM_WriteDuty(&(hhtr -> Output), hhtr -> Output.Duty);
}


float Heater_PWM_ReadDuty(HEATER_PWM_Handle_TypeDef* hhtr){
  return (hhtr -> ActiveState == HEATER_ON_HIGH) ? (hhtr -> Output.Duty) : (100.0f -  hhtr -> Output.Duty);
}
