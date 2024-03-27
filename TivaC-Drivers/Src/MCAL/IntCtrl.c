#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Mcu_HW.h"
#include "IntCtrl.h"


void NVIC_InterruptControl(u8 Copy_u8InterruptNum, u8 EnOrDi){
	if(EnOrDi){
	if(Copy_u8InterruptNum <=31){
		NVIC_ISER0 = (1 << Copy_u8InterruptNum);
	}
	else if(Copy_u8InterruptNum <=59){
		Copy_u8InterruptNum-=32;
		NVIC_ISER1 = (1 << Copy_u8InterruptNum);
	}
}
	else {
	if(Copy_u8InterruptNum <=31){
		NVIC_ICER0 = (1 << Copy_u8InterruptNum);
	}
	else if(Copy_u8InterruptNum <=59){
		Copy_u8InterruptNum-=32;
		NVIC_ICER1 = (1 << Copy_u8InterruptNum);
	}
}
}

void NVIC_PendingFlagControl(u8 Copy_u8InterruptNum, u8 SetOrClr){
if(SetOrClr){
	if(Copy_u8InterruptNum <=31){
		NVIC_ISPR0 = (1 << Copy_u8InterruptNum);
		}
	else if(Copy_u8InterruptNum <=59){
		Copy_u8InterruptNum-=32;
		NVIC_ISPR1 = (1 << Copy_u8InterruptNum);
		}
}
else{
	if(Copy_u8InterruptNum <=31){
		NVIC_ICPR0 = (1 << Copy_u8InterruptNum);
			}
	else if(Copy_u8InterruptNum <=59){
		Copy_u8InterruptNum-=32;
		NVIC_ICPR1 = (1 << Copy_u8InterruptNum);
			}
}
}

u8 NVIC_ReadActiveFlag(u8 Copy_u8InterruptNum){
	u8 Local_u8Result=0;
	if(Copy_u8InterruptNum <=31){
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8InterruptNum);
		}
	else if(Copy_u8InterruptNum <=59){
		Copy_u8InterruptNum-=32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8InterruptNum);
		}
	return Local_u8Result;
}

void NVIC_SetPriority(s8 Copy_s8ID , u8 Copy_u8GroupPriority, u8 Copy_u8SubgroupPriority, u32 Copy_u32Group){

u8 Local_u8Priority = Copy_u8SubgroupPriority|Copy_u8GroupPriority<<((Copy_u32Group-0x05FA0300)/256);
/*External Peripherals*/
if(Copy_s8ID >= 0){
	NVIC_IPR[Copy_s8ID] = Local_u8Priority<<4;
}
/*Core Peripheral*/
else{

}
SCB_AIRCR = Copy_u32Group;
}

