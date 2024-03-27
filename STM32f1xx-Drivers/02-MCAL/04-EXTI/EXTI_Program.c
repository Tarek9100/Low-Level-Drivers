/*
 * EXTI_Program.c
 *
 *  Created on: Jul 11, 2022
 *      Author: ENG TAREK
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f103xx.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"



void EXTI_Init(u8 Copy_u8Line, AFPortMap Copy_u8PortMap, u8 Copy_u8Mode ){
u8 Local_u8RegID = 0;
switch(Copy_u8Mode){
case CHANGE: SET_BIT(EXTI->FTSR,Copy_u8Line);SET_BIT(EXTI->RTSR,Copy_u8Line);break;
case RISING: SET_BIT(EXTI->RTSR,Copy_u8Line);break;
case FALLING: SET_BIT(EXTI->FTSR,Copy_u8Line);break;
}
SET_BIT(EXTI->IMR,Copy_u8Line);//Enables the desired line

Local_u8RegID = Copy_u8Line/4;
Copy_u8Line %=4;
AFIO->EXTICR[Local_u8RegID] &= ~((0b1111) << (Copy_u8Line*4));
AFIO->EXTICR[Local_u8RegID] |= ((Copy_u8PortMap) << (Copy_u8Line*4)); //Choosing the desired pin in activated line
}

void EXTI_Disable(u8 Copy_u8Line){
	CLR_BIT(EXTI->IMR,Copy_u8Line);
}
void EXTI_SWTrigger(u8 Copy_u8Line){
	SET_BIT(EXTI->SWIER,Copy_u8Line);
	while(!(GET_BIT(EXTI->PR,Copy_u8Line))){
		EXTI->PR = 1<<Copy_u8Line;
	}
}
void EXTI0_SetCallBack(void (*ptr) (void)){
	EXTI0_CallBack= ptr;
}

void EXTI0_IRQHandler(void){
	EXTI0_CallBack();
	EXTI->PR = 1<<0;
}

void EXTI1_SetCallBack(void (*ptr) (void)){
	EXTI1_CallBack= ptr;
}

void EXTI1_IRQHandler(void){
	EXTI1_CallBack();
	EXTI->PR = 1<<1;
}

void EXTI2_SetCallBack(void (*ptr) (void)){
	EXTI2_CallBack= ptr;
}

void EXTI2_IRQHandler(void){
	EXTI2_CallBack();
	EXTI->PR = 1<<2;
}

void EXTI3_SetCallBack(void (*ptr) (void)){
	EXTI3_CallBack= ptr;
}

void EXTI3_IRQHandler(void){
	EXTI3_CallBack();
	EXTI->PR = 1<<3;
}

void EXTI4_SetCallBack(void (*ptr) (void)){
	EXTI4_CallBack= ptr;
}

void EXTI4_IRQHandler(void){
	EXTI4_CallBack();
	EXTI->PR = 1<<4;
}
void EXTI5_SetCallBack(void (*ptr) (void)){
	EXTI5_CallBack= ptr;
}

void EXTI5_IRQHandler(void){
	EXTI5_CallBack();
	EXTI->PR = 1<<5;
}

void EXTI6_SetCallBack(void (*ptr) (void)){
	EXTI6_CallBack= ptr;
}

void EXTI6_IRQHandler(void){
	EXTI6_CallBack();
	EXTI->PR = 1<<6;
}

void EXTI7_SetCallBack(void (*ptr) (void)){
	EXTI7_CallBack= ptr;
}

void EXTI7_IRQHandler(void){
	EXTI7_CallBack();
	EXTI->PR = 1<<7;
}

void EXTI8_SetCallBack(void (*ptr) (void)){
	EXTI8_CallBack= ptr;
}

void EXTI8_IRQHandler(void){
	EXTI8_CallBack();
	EXTI->PR = 1<<8;
}

void EXTI9_SetCallBack(void (*ptr) (void)){
	EXTI9_CallBack= ptr;
}

void EXTI9_IRQHandler(void){
	EXTI9_CallBack();
	EXTI->PR = 1<<9;
}

void EXTI10_SetCallBack(void (*ptr) (void)){
	EXTI10_CallBack= ptr;
}

void EXTI10_IRQHandler(void){
	EXTI10_CallBack();
	EXTI->PR = 1<<10;
}
void EXTI11_SetCallBack(void (*ptr) (void)){
	EXTI11_CallBack= ptr;
}

void EXTI11_IRQHandler(void){
	EXTI11_CallBack();
	EXTI->PR = 1<<11;
}

void EXTI12_SetCallBack(void (*ptr) (void)){
	EXTI12_CallBack= ptr;
}

void EXTI12_IRQHandler(void){
	EXTI12_CallBack();
	EXTI->PR = 1<<12;
}

void EXTI13_SetCallBack(void (*ptr) (void)){
	EXTI13_CallBack= ptr;
}

void EXTI13_IRQHandler(void){
	EXTI13_CallBack();
	EXTI->PR = 1<<13;
}

void EXTI14_SetCallBack(void (*ptr) (void)){
	 EXTI14_CallBack= ptr;
}

void EXTI14_IRQHandler(void){
	EXTI14_CallBack();
	EXTI->PR = 1<<14;
}
void EXTI15_SetCallBack(void (*ptr) (void)){
	 EXTI15_CallBack= ptr;
}

void EXTI15_IRQHandler(void){
	EXTI15_CallBack();
	EXTI->PR = 1<<15;
}
