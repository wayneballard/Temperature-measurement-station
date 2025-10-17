/**
  ******************************************************************************
  * @file     : dio.h
  * @author   : AW    Adrian.Wojcik@put.poznan.pl
  * @version  : 1.3.0
  * @date     : Nov 27, 2022
  * @brief    : Digital inputs/outputs components driver.
  *
  ******************************************************************************
  */

#ifndef INC_DIO_H_
#define INC_DIO_H_


#ifdef USE_HAL_DRIVER
#include "stm32f7xx_hal.h"
#endif


#ifdef USE_HAL_DRIVER
typedef GPIO_TypeDef* DIO_Port_TypeDef;
typedef uint16_t DIO_Pin_TypeDef;
#endif

typedef struct {
  DIO_Port_TypeDef Port;
  DIO_Pin_TypeDef Pin;
} DIO_Handle_TypeDef;


#ifdef USE_HAL_DRIVER
#define DIO_INIT_HANDLE(USER_NAME)      \
        {                               \
          .Port = USER_NAME##_GPIO_Port,\
          .Pin = USER_NAME##_Pin,       \
        }
#endif


void DIO_WriteLowState(const DIO_Handle_TypeDef* hdio);
void DIO_WriteHighState(const DIO_Handle_TypeDef* hdio);
void DIO_WriteGivenState(const DIO_Handle_TypeDef* hdio, _Bool state);
void DIO_Toggle(const DIO_Handle_TypeDef* hdio);
_Bool DIO_Read(const DIO_Handle_TypeDef* hdio);

#endif /* INC_DIO_H_ */
