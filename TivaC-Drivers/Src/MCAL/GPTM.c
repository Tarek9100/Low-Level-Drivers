#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Mcu_HW.h"
#include "GPTM.h"
#include "GPTM_Cfg.h"
void (*GPTM_TIM0A_CallBack)(void); 
void (*GPTM_TIM1A_CallBack)(void); 
void (*GPTM_TIM2A_CallBack)(void); 


void GPTM_PerClockEnable(TIM_RegDef_t *pGPTM_x)
{
		if(pGPTM_x == TIM0){
		TIM0_PCLK_EN();
		while(!(GET_BIT(RCC_PRTIM,0)));
		}else if(pGPTM_x == TIM1)
		{
		TIM1_PCLK_EN();
		while(!(GET_BIT(RCC_PRTIM,1)));
		}else if(pGPTM_x == TIM2)
		{
		TIM2_PCLK_EN();
		while(!(GET_BIT(RCC_PRTIM,2)));
		}else if(pGPTM_x == TIM3)
		{
		TIM3_PCLK_EN();
		while(!(GET_BIT(RCC_PRTIM,3)));
		}
		else if(pGPTM_x == TIM4)
		{
		TIM4_PCLK_EN();
		while(!(GET_BIT(RCC_PRTIM,4)));
		}	
		else if(pGPTM_x == TIM5)
		{
		TIM5_PCLK_EN();
		while(!(GET_BIT(RCC_PRTIM,5)));
		}
		else if(pGPTM_x == TIM_W0){
		TIM0W_PCLK_EN();
		while(!(GET_BIT(RCC_PRTIMW,0)));
		}else if(pGPTM_x == TIM_W1)
		{
		TIM1W_PCLK_EN();
		while(!(GET_BIT(RCC_PRTIMW,1)));
		}else if(pGPTM_x == TIM_W2)
		{
		TIM2W_PCLK_EN();
		while(!(GET_BIT(RCC_PRTIMW,2)));
		}else if(pGPTM_x == TIM_W3)
		{
		TIM3W_PCLK_EN();
		while(!(GET_BIT(RCC_PRTIMW,3)));
		}
		else if(pGPTM_x == TIM_W4)
		{
		TIM4W_PCLK_EN();
		while(!(GET_BIT(RCC_PRTIMW,4)));
		}	
		else if(pGPTM_x == TIM_W5)
		{
		TIM5W_PCLK_EN();
		while(!(GET_BIT(RCC_PRTIMW,5)));
		}
}
void GPTM_Init(){
	#if Timer_Modes == T0_16BITS_SINGLE
	CLR_BIT(TIM0->CTL,0); //Make sure timer is disabled
	TIM0->CFG = 0x04; //Timer0 works as a 16-bit timer
	TIM0->TAMR = 0x01; // Selecting one-shot mode
	#elif Timer_Modes == T1_16BITS_PERIODIC
	CLR_BIT(TIM1->CTL,0); //Make sure timer is disabled
	TIM1->CFG = 0x04; //Timer1 works as a 16-bit timer
	TIM1->TAMR = 0x02; // Selecting periodic mode
	#elif Timer_Modes == T2_32BITS_PERIODIC
	CLR_BIT(TIM2->CTL,0); //Make sure timer is disabled
	TIM2->CFG = 0x00; //Timer2 works as a 32-bit timer
	TIM2->TAMR = 0x02; // Selecting periodic mode
	#endif
}
void GPTM_StartTimer_OneShot(u8 Copy_u8Channel,u32 Copy_u32Value){
	//TIMER 0
	TIM0->TAILR = Copy_u32Value;
	SET_BIT(TIM0->IMR,0);//Enable interrupt for Timer A0 is triggered
	SET_BIT(TIM0->CTL,0);//Timer A0 is enabled and begins counting
	SET_BIT(TIM0->ICR,0);//Clear interrupt flag only for the first time 
}
	
void GPTM_StartTimer_Periodic(u8 Copy_u8Channel,u32 Copy_u32Value){
switch(Copy_u8Channel){

case 1:

	//TIMER 1
	TIM1->TAILR = Copy_u32Value;
	SET_BIT(TIM1->IMR,0);//Enable interrupt for Timer A1 is triggered
	SET_BIT(TIM1->CTL,0);//Timer A1 is enabled and begins counting
	SET_BIT(TIM1->ICR,0);//Clear interrupt flag only for the first time 
	break;
case 2:	
	//TIMER 2
	TIM2->TAILR = Copy_u32Value;
	SET_BIT(TIM2->IMR,0);//Enable interrupt for Timer A2 is triggered
	SET_BIT(TIM2->CTL,0);//Timer A2 is enabled and begins counting
	SET_BIT(TIM2->ICR,0);//Clear interrupt flag only for the first time 
	break;
}	
}
void GPTM_StopTimer(u8 Copy_u8Channel){
	switch(Copy_u8Channel){
case 0: CLR_BIT(TIM0->CTL,0);break;
case 1: CLR_BIT(TIM1->CTL,0);break;
case 2: CLR_BIT(TIM2->CTL,0);break;
	}
}	


u32 GPTM_GetElapsedTime(u8 Copy_u8Channel){
switch(Copy_u8Channel){
case 0: return (TIM0->TAILR)-(TIM0->TAV);break;	
case 1: return (TIM1->TAILR)-(TIM1->TAV);break;	
case 2: return (TIM2->TAILR)-(TIM2->TAV);break;	
	
	
}
}
u32 GPTM_GetRemainingTime(u8 Copy_u8Channel){
switch(Copy_u8Channel){
case 0: return (TIM0->TAV);break;	
case 1: return (TIM1->TAV);break;	
case 2: return (TIM2->TAV);break;	
	
}		
}

void GPTM_TIMA0_SetCallBack(void (*ptr)(void)){
GPTM_TIM0A_CallBack = ptr;
}
void TIMER0A_Handler(){
GPTM_TIM0A_CallBack;
SET_BIT(TIM0->ICR,0);	
}

void GPTM_TIMA1_SetCallBack(void (*ptr)(void)){
GPTM_TIM1A_CallBack = ptr;
}
TIMER1A_Handler(){
GPTM_TIM1A_CallBack;
}
void GPTM_TIMA2_SetCallBack(void (*ptr)(void)){
GPTM_TIM2A_CallBack = ptr;
}

