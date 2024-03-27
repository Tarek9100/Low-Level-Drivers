/*
 * TIMER_program.c
 *
 *  Created on: Nov 23, 2021
 *      Author: ENG TAREK
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_interface.h"

static void (TIMER0_pvCallBackFunc)(void)=NULL;
void TIMER0_voidIntialize(){
#if TIMER0_u8_MODE == TIMER0_u8_CTC
CLR_BIT(TCCR0,TCCR0_WGM00);
CLR_BIT(TCCR0,TCCR0_WGM01);
/* Output compare match interrupt enable*/
SET_BIT(TIMSK,TIMSK_OCIE0);
/*Set compare match value to 250*/
OCR0=250;
/*Prescalar : Division by 8*/
CLR_BIT(TCCR0,TCCR0_CS00);
SET_BIT(TCCR0,TCCR0_CS01);
CLR_BIT(TCCR0,TCCR0_CS02);
}

u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void)){

	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
	Local_u8ErrorState = STD_TYPES_NOK;
	}
return Local_u8ErrorState;
}
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void){
	if(TIMER0_pvCallBackFunc != NULL){
		TIMER0_pvCallBackFunc();
	}

}
