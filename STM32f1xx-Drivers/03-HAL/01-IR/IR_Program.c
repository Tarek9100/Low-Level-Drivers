/*
 * IR_Program.c
 *
 *  Created on: Apr 14, 2023
 *      Author: ENG TAREK
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "IR_Interface.h"

volatile u8 u8StartFlag = 0;
volatile u32 u32FrameData[50]={0};
volatile u8 u8EdgeCounter = 0;
volatile u8 u8Data=0;

/*This function reads the frame and translate it to specific action through u8Data variable*/
void IR_voidPlay(void){
	asm("NOP");
}
void IR_voidTakeAction(void){
	u8 i;
	u32 u32FrameData[50]={0};
	if(u32FrameData[0] >= 11000  && u32FrameData[0] <=15000){
		for(i=0;i<8;i++){
			if(u32FrameData[17+i] >=2000 && u32FrameData[17+i] <=2300){

				SET_BIT(u8Data,i);
			}
			else{
				CLR_BIT(u8Data,i);
			}
		}
		voidPlay();
	}
	else{
		/*Invalid Frame*/
	}
	u8StartFlag=0;
	u32FrameData[0]=0;
	u8EdgeCounter =0;
}

void IR_voidGetFrame(void){
	if(u8StartFlag ==0){
		STK_Count_MicroSeconds(1000000,IR_voidTakeAction);
		u8StartFlag =1;
	}
	else{
		u32FrameData[u8EdgeCounter]= STK_Get_Elapsed_Time();
		STK_Count_MicroSeconds(1000000,IR_voidTakeAction);
		u8EdgeCounter++;
	}
}
void IR_Init(void){
	RCC_voidInitSysClock();
	RCC_voidInitPBusClock();
	GPIO_Handler GPIO_IR;
	GPIO_IR.GPIO_PinConfig.GPIO_Pin_Number=0;
	GPIO_IR.GPIO_PinConfig.GPIO_Pin_Speed = GPIO_SPEED_02;
	GPIO_IR.GPIO_PinConfig.GPIO_Pin_Mode = GPIO_INPUT;
	GPIO_IR.GPIO_PinConfig.GPIO_Pin_Input_Type = GPIO_IP_Floating;
	EXTI10_SetCallBack(IR_voidGetFrame);
	EXTI_Init(EXTI_LINE0,A,FALLING);
	NVIC_InterruptControl(6,ENABLE);
}
