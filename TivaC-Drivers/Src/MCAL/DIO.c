#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MCU_HW.h"
#include "DIO.h"

void GPIO_PerClockControl(GPIO_RegDef_t *pGPIO_x ,u8 EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIO_x == GPIOA){
		GPIOA_PCLK_EN();
		while(!(GET_BIT(RCC_PRGPIO,0)));
		}else if(pGPIO_x == GPIOB)
		{
		GPIOB_PCLK_EN();
		while(!(GET_BIT(RCC_PRGPIO,1)));
		}else if(pGPIO_x == GPIOC)
		{
		GPIOC_PCLK_EN();
		while(!(GET_BIT(RCC_PRGPIO,2)));
		}else if(pGPIO_x == GPIOD)
		{
		GPIOD_PCLK_EN();
		while(!(GET_BIT(RCC_PRGPIO,3)));
		}
		else if(pGPIO_x == GPIOE)
		{
		GPIOE_PCLK_EN();
		while(!(GET_BIT(RCC_PRGPIO,4)));
		}	
		else if(pGPIO_x == GPIOF)
		{
		GPIOF_PCLK_EN();
		while(!(GET_BIT(RCC_PRGPIO,5)));
		}
	}
	
	else{

		if(pGPIO_x == GPIOA){
					GPIOA_PCLK_DI();
				}else if(pGPIO_x == GPIOB)
				{
					GPIOB_PCLK_DI();
				}else if(pGPIO_x == GPIOC)
				{
					GPIOC_PCLK_DI();
				}else if(pGPIO_x == GPIOD)
				{
					GPIOD_PCLK_DI();
				}
				else if(pGPIO_x == GPIOE)
				{
					GPIOE_PCLK_DI();
				}
				else if(pGPIO_x == GPIOF)
				{
					GPIOF_PCLK_DI();
				}
		}
}

u8 DIO_ReadChannel(DIO_Port_t PortID, DIO_Channel_t ChannelID){
	switch(PortID){
	case(PA): SET_BIT(GPIOA->DEN,ChannelID);return(GPIOA->DATA[ChannelID + 1]);break;
	case(PB): SET_BIT(GPIOB->DEN,ChannelID);return(GPIOB->DATA[ChannelID + 1]);break;
	case(PC): SET_BIT(GPIOC->DEN,ChannelID);return(GPIOC->DATA[ChannelID + 1]);break;
	case(PD): SET_BIT(GPIOD->DEN,ChannelID);return(GPIOD->DATA[ChannelID + 1]);break;
	case(PE): SET_BIT(GPIOE->DEN,ChannelID);return(GPIOE->DATA[ChannelID + 1]);break;
	case(PF): SET_BIT(GPIOF->DEN,ChannelID);return(GPIOF->DATA[ChannelID + 1]);break;
	}	 
}

void DIO_WriteChannel(DIO_Port_t PortID, DIO_Channel_t ChannelID , u8 DIO_State){
	switch(PortID){
	case(PA): SET_BIT(GPIOA->DEN,ChannelID);SET_BIT(GPIOA->DIR,ChannelID);GPIOA->DATA[ChannelID + 1]=(DIO_State<<ChannelID);break;
	case(PB): SET_BIT(GPIOB->DEN,ChannelID);SET_BIT(GPIOB->DIR,ChannelID);GPIOB->DATA[ChannelID + 1]=(DIO_State<<ChannelID);break;
	case(PC): SET_BIT(GPIOC->DEN,ChannelID);SET_BIT(GPIOC->DIR,ChannelID);GPIOC->DATA[ChannelID + 1]=(DIO_State<<ChannelID);break;
	case(PD): SET_BIT(GPIOD->DEN,ChannelID);SET_BIT(GPIOD->DIR,ChannelID);GPIOD->DATA[ChannelID + 1]=(DIO_State<<ChannelID);break;
	case(PE): SET_BIT(GPIOE->DEN,ChannelID);SET_BIT(GPIOE->DIR,ChannelID);GPIOE->DATA[ChannelID + 1]=(DIO_State<<ChannelID);break;
	case(PF): SET_BIT(GPIOF->DEN,ChannelID);SET_BIT(GPIOF->DIR,ChannelID);GPIOF->DATA[ChannelID + 1]=(DIO_State<<ChannelID);break;
	}	
}

u8 DIO_ReadPort(DIO_Port_t PortID){
	switch(PortID){
	case(PA): GPIOA->DEN = 0xFF;return(GPIOA->DATA[255]);break;
	case(PB): GPIOB->DEN = 0xFF;return(GPIOB->DATA[255]);break;
	case(PC): GPIOC->DEN = 0xFF;return(GPIOC->DATA[255]);break;
	case(PD): GPIOD->DEN = 0xFF;return(GPIOD->DATA[255]);break;
	case(PE): GPIOE->DEN = 0xFF;return(GPIOE->DATA[255]);break;
	case(PF): GPIOF->DEN = 0xFF;return(GPIOF->DATA[255]);break;
	}	
}	

void DIO_WritePort(DIO_Port_t PortID , u8 DIO_Value){
	switch(PortID){
	case(PA): GPIOA->DEN = 0xFF;GPIOA->DIR =0XFF;GPIOA->DATA[255]=DIO_Value;break;
	case(PB): GPIOB->DEN = 0xFF;GPIOB->DIR =0XFF;GPIOB->DATA[255]=DIO_Value;break;
	case(PC): GPIOC->DEN = 0xFF;GPIOC->DIR =0XFF;GPIOC->DATA[255]=DIO_Value;break;
	case(PD): GPIOD->DEN = 0xFF;GPIOD->DIR =0XFF;GPIOD->DATA[255]=DIO_Value;break;
	case(PE): GPIOE->DEN = 0xFF;GPIOE->DIR =0XFF;GPIOE->DATA[255]=DIO_Value;break;
	case(PF): GPIOF->DEN = 0xFF;GPIOF->DIR =0XFF;GPIOF->DATA[255]=DIO_Value;break;
	}	
}


void DIO_ToggleChannel(DIO_Port_t PortID,DIO_Channel_t ChannelID){
	switch(PortID){
	case(PA): SET_BIT(GPIOA->DEN,ChannelID);SET_BIT(GPIOA->DIR,ChannelID);GPIOA->DATA[ChannelID + 1]^=(1<<ChannelID);break;
	case(PB): SET_BIT(GPIOB->DEN,ChannelID);SET_BIT(GPIOB->DIR,ChannelID);GPIOB->DATA[ChannelID + 1]^=(1<<ChannelID);break;
	case(PC): SET_BIT(GPIOC->DEN,ChannelID);SET_BIT(GPIOC->DIR,ChannelID);GPIOC->DATA[ChannelID + 1]^=(1<<ChannelID);break;
	case(PD): SET_BIT(GPIOD->DEN,ChannelID);SET_BIT(GPIOD->DIR,ChannelID);GPIOD->DATA[ChannelID + 1]^=(1<<ChannelID);break;
	case(PE): SET_BIT(GPIOE->DEN,ChannelID);SET_BIT(GPIOE->DIR,ChannelID);GPIOE->DATA[ChannelID + 1]^=(1<<ChannelID);break;
	case(PF): SET_BIT(GPIOF->DEN,ChannelID);SET_BIT(GPIOF->DIR,ChannelID);GPIOF->DATA[ChannelID + 1]^=(1<<ChannelID);break;
	}	
}