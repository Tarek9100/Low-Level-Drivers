/**********************************************************
******************Author : TAREK WAEL**********************
******************Component : RCC	 **********************
******************Version : 01       **********************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

static u16  AHB_Prescalar[8] = {2,4,8,16,64,128,256,512};
static u8 	 APB_Prescalar[4] = {2,4,8,16};

void RCC_voidInitSysClock(void){
RCC->CFGR &= ~(0x3);	 
#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
RCC->CFGR |=0x00000001;
RCC->CR |= 0X00010000; /*Enable HSE_crystal*/

#elif	RCC_CLOCK_TYPE == RCC_HSE_RC
RCC->CFGR |= 0x00000001;
RCC->CR |= 0X00050000; /*Enable HSE_RC*/

#elif	RCC_CLOCK_TYPE == RCC_HSI

RCC->CR |= 0x00000001; /*Enable HSI*/

#elif	RCC_CLOCK_TYPE == RCC_PLL
RCC->CFGR &= ~(0xF << 18);
RCC->CFGR |= ((RCC_PLL_MUL_VALUE - 2)<< 18);
SET_BIT(RCC->CFGR, 1);
 #if  	RCC_PLL_INPUT ==  RCC_PLL_HSI_DIV_2

CLR_BIT(RCC->CFGR,16);
RCC->CR |= 0x01000001;
#elif 	RCC_PLL_INPUT == RCC_PLL_HSE

SET_BIT(RCC->CFGR,16);
CLR_BIT(RCC->CFGR,17);
RCC->CR |= 0x01010000;
#elif 	RCC_PLL_INPUT == RCC_PLL_HSE_DIV_2

SET_BIT(RCC->CFGR,16);
SET_BIT(RCC->CFGR,17);
RCC->CR |= 0x01010000;

#else 
	#error("Wrong PLL Clock Source!")
#endif
#else
	#error("Wrong Clock Type!")	
#endif	
}

void RCC_voidInitPBusClock(void){
	
//Set AHB Clock value	
RCC->CFGR &= ~(0xF << 4);
RCC->CFGR |= AHB_PRESCALAR<< 4;

//Set APB1 Clock value
RCC->CFGR &= ~(0x7 << 8);
RCC->CFGR |= APB1_PRESCALAR<< 8;

//Set APB2 Clock value
RCC->CFGR &= ~(0x7 << 11);
RCC->CFGR |= APB2_PRESCALAR<< 11;	
}
void RCC_voidEnableClock( u8 Copy_u8BusId, u8 Copy_u8PerId){

if(Copy_u8PerId < 32){
	
	switch(Copy_u8BusId)

	{
	case RCC_AHB: SET_BIT(RCC->AHBENR,Copy_u8PerId);break;
	case RCC_APB1:SET_BIT(RCC->APB1ENR,Copy_u8PerId);break;
	case RCC_APB2:SET_BIT(RCC->APB2ENR,Copy_u8PerId);break;
	}
}
else{
	

}
}
void RCC_voidDisableClock( u8 Copy_u8BusId, u8 Copy_u8PerId){

if(Copy_u8PerId < 32){
	
	switch(Copy_u8BusId)

	{
		case RCC_AHB: CLR_BIT(RCC->AHBENR,Copy_u8PerId);break;
		case RCC_APB1:CLR_BIT(RCC->APB1ENR,Copy_u8PerId);break;
		case RCC_APB2:CLR_BIT(RCC->APB2ENR,Copy_u8PerId);break;
	}
}
else{
	
/*Return Error*/
}
}	

u32 RCC_u32GetPCLK1Value(void){

	u32 pclk1,SystemClk=8000000;
	u8 clksrc,temp,ahbp,apb1p;

	clksrc = ((RCC->CFGR >>2) & 0x03);
	if(clksrc == 0){
		SystemClk = 16000000;
	}
	else if(clksrc == 2){

	}
	// AHB
	temp =((RCC->CFGR >>4) & 0xF);
	if(temp <8){
		ahbp =1;
	}
	else{
		ahbp = AHB_Prescalar[temp-8];
	}
	//APB1
	temp =((RCC->CFGR >>8) & 0x7);

	if(temp <4){
		apb1p = 1;
	}
	else{
		apb1p = APB_Prescalar[temp-4];
	}
	pclk1 = (SystemClk / ahbp) / apb1p;

	return pclk1;
}

u32 RCC_u32GetPCLK2Value(void){

	u32 pclk2,SystemClk=8;
	u8 clksrc,temp,ahbp,apb2p;

	clksrc = ((RCC->CFGR >>2) & 0x03);
	if(clksrc == 0){
		SystemClk = 16000000;
	}

	else if(clksrc == 2){

	}
	// AHB
	temp =((RCC->CFGR >>4) & 0xF);
	if(temp <8){
		ahbp =1;
	}
	else{
		ahbp = AHB_Prescalar[temp-8];
	}
	//APB1
	temp =((RCC->CFGR >>11) & 0x7);

	if(temp <4){
		apb2p = 1;
	}
	else{
		apb2p = APB_Prescalar[temp-4];
	}
	pclk2 = (SystemClk / ahbp) / apb2p;

	return pclk2;
}
