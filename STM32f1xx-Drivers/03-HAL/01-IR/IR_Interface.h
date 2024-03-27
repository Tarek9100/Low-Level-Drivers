/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*                              SWC : 	IR                                         */
/***********************************************************************************/
#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H


#include "stm32f103xx.h"
#include "RCC_interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "NVIC_Interface.h"
#include "EXTI_Interface.h"
#include "IR_Private.h"
#include "IR_Config.h"

void IR_voidGetFrame(void);
void IR_Init(void);
void IR_voidTakeAction(void);
void IR_voidPlay(void);













#endif
