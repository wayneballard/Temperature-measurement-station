/**
  ******************************************************************************
  * @file     : dio.c
  * @author   : AW    Adrian.Wojcik@put.poznan.pl
  * @version  : 1.3.0
  * @date     : Nov 27, 2022
  * @brief    : Digital inputs/outputs components driver.
  *
  ******************************************************************************
  */

/* Private includes ----------------------------------------------------------*/
#include "dio.h"



void DIO_WriteLowState(const DIO_Handle_TypeDef* hdio)
{
  HAL_GPIO_WritePin(hdio->Port, hdio->Pin, GPIO_PIN_RESET);
}


void DIO_WriteHighState(const DIO_Handle_TypeDef* hdio){
  HAL_GPIO_WritePin(hdio->Port, hdio->Pin, GPIO_PIN_SET); // -> - assign operator
}

void DIO_WriteGivenState(const DIO_Handle_TypeDef* hdio, _Bool state){
  HAL_GPIO_WritePin(hdio -> Port, hdio -> Pin, (GPIO_PinState)state);
}

void DIO_Toggle(const DIO_Handle_TypeDef* hdio){
  HAL_GPIO_TogglePin(hdio -> Port, hdio -> Pin);
}

_Bool DIO_Read(const DIO_Handle_TypeDef* hdio){
  return (_Bool)HAL_GPIO_ReadPin(hdio -> Port, hdio -> Pin);
}
