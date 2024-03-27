/**********************************************************
******************Author : TAREK WAEL**********************
******************Component : RCC	 **********************
******************Version : 01       **********************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "stm32f103xx.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock( u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock( u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidInitPBusClock(void);
u32 RCC_u32GetPCLK1Value(void);
u32 RCC_u32GetPCLK2Value(void);
#endif
