/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*                              SWC : 	DMA                                        */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_Interface.h"



void DMA_voidChannelInit(DMA_Config_t DMA_Config,u32* Copy_Pu32SourceAddress, u32* Copy_Pu32DestAddress,u16 Copy_u16BlockLen){
u8 ChannelID=1;

switch(DMA_Config.Transfer_mode){

case Memory_TO_Memory: DMA1->Channel[ChannelID].CCR =0x4AC0;break;
case Periph_TO_Memory:

	switch(DMA_Config.Source){
	case USART_3: ChannelID = 2;break;
	case SPI_1: ChannelID = 3;break;
	case USART_1:
	case I2C_2:ChannelID = 4;break;
	case SPI_2: ChannelID = 5;break;
	case I2C_1: ChannelID = 6;break;
	case USART_2: ChannelID = 7;break;
	default:break;
	DMA1->Channel[ChannelID].CCR =0x4A80;
	DMA1->Channel[ChannelID].CPAR = Copy_Pu32SourceAddress;DMA1->Channel[ChannelID].CMAR =Copy_Pu32DestAddress;
	}break;
case Memory_TO_Periph:

	switch(DMA_Config.Destination){
	case SPI_1: ChannelID = 2;break;
	case USART_3: ChannelID = 3;break;
	case SPI_2:ChannelID = 4;break;
	case USART_1:
	case I2C_2: ChannelID = 5;break;
	case I2C_1: ChannelID = 7;break;
	case USART_2: ChannelID = 6;break;
	default:break;
	DMA1->Channel[ChannelID].CCR =0x4A90;
	DMA1->Channel[ChannelID].CPAR = Copy_Pu32DestAddress;DMA1->Channel[ChannelID].CMAR =Copy_Pu32SourceAddress;
	}break;

	}

	if(DMA_Config.Circular_mode == Circular){
	SET_BIT(DMA1->Channel[ChannelID].CCR,5);
	}
	switch(DMA_Config.Interrupt_mode){
	case Transfer_Complete:SET_BIT(DMA1->Channel[ChannelID].CCR,1);break;
	case Half_Transfer_Complete:SET_BIT(DMA1->Channel[ChannelID].CCR,2);break;
	case Transfer_Error:SET_BIT(DMA1->Channel[ChannelID].CCR,3);break;
	default: break;
	}
	DMA1->Channel[ChannelID].CNDTR = Copy_u16BlockLen; //Number of data to be transferred max:65535
	SET_BIT(DMA1->Channel[ChannelID].CCR,0); //Enable Channel

}

void DMA_CH1_SetCallBack(void (*ptr) (void)){
	CH1_CallBack= ptr;
}
void DMA1_Channel1_IRQHandler(void){
	CH1_CallBack();
	DMA1->IFCR= 0x00000001;
}

void DMA_CH2_SetCallBack(void (*ptr) (void)){
	CH2_CallBack= ptr;
}
void DMA1_Channel2_IRQHandler(void){
	CH2_CallBack();
	DMA1->IFCR= 0x00000010;
}

void DMA_CH3_SetCallBack(void (*ptr) (void)){
	CH3_CallBack= ptr;
}
void DMA1_Channel3_IRQHandler(void){
	CH3_CallBack();
	DMA1->IFCR= 0x00000100;
}

void DMA_CH4_SetCallBack(void (*ptr) (void)){
	CH4_CallBack= ptr;
}
void DMA1_Channel4_IRQHandler(void){
	CH4_CallBack();
	DMA1->IFCR= 0x00001000;
}

void DMA_CH5_SetCallBack(void (*ptr) (void)){
	CH5_CallBack= ptr;
}
void DMA1_Channel5_IRQHandler(void){
	CH5_CallBack();
	DMA1->IFCR= 0x00010000;
}

void DMA_CH6_SetCallBack(void (*ptr) (void)){
	CH6_CallBack= ptr;
}
void DMA1_Channel6_IRQHandler(void){
	CH6_CallBack();
	DMA1->IFCR= 0x00100000;
}

void DMA_CH7_SetCallBack(void (*ptr) (void)){
	CH7_CallBack= ptr;
}
void DMA1_Channel7_IRQHandler(void){
	CH7_CallBack();
	DMA1->IFCR= 0x01000000;
}
