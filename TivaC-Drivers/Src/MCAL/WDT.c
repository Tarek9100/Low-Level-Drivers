#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MCU_HW.h"

#include "WDT.h"
#include "WDT_Cfg.h"

void (*WDT1_CallBack)(void) = NULL;

void WDT1_Init(){

WDT1->LOAD = TIMEOUT;
while(!(GET_BIT(WDT1->ICR,31)));
WDT1->ICR|=InterruptType;
while(!(GET_BIT(WDT1->ICR,31)));	
SET_BIT(WDT1->TEST,8);
while(!(GET_BIT(WDT1->ICR,31)));	
		
}
void WDT1_SetTrigger( u32 Copy_u32Timeout){
	WDT1->LOAD = Copy_u32Timeout;
	while(!(GET_BIT(WDT1->ICR,31)));
}

void WDT_SetCallBack(void (*ptr)(void)){
WDT1_CallBack = ptr;
}

void WDT0_Handler(){
	WDT1_CallBack();
	WDT1->ICR = 255;
}