#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MCU_HW.h"

#include "IntCtrl.h"
#include "PORT.h"
#include "DIO.h"
#include "WDT.h"
#include "GPTM.h"

#define TIME 	100

volatile u8 flag= 0;

void TIMER2A_Handler(void){
	flag =1;
	SET_BIT(TIM2->ICR,0);
}


int main(){

	GPIO_PerClockControl(GPIOA,ENABLE);
	GPIO_PerClockControl(GPIOB,ENABLE);
	GPIO_PerClockControl(GPIOC,ENABLE);
	GPIO_PerClockControl(GPIOD,ENABLE);
	GPIO_PerClockControl(GPIOE,ENABLE);
	GPIO_PerClockControl(GPIOF,ENABLE);
	TIM2_PCLK_EN();
	GPTM_Init();
	NVIC_InterruptControl(TIMER2A_IRQn,ENABLE);
	
	
	PORT_Init();
	GPTM_StartTimer_Periodic(2,TIME);
	while(1){
	
		if(flag == 1){
			DIO_ToggleChannel(PB,Ch1);
			flag =0;
		}
	}
	return 0;
}
