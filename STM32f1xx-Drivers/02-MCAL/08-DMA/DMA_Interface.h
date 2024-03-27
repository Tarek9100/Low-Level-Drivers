/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*                              SWC : 	DMA                                        */
/***********************************************************************************/
#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

#include "stm32f103xx.h"
#include "DMA_Private.h"
#include "DMA_Config.h"

typedef struct{
	u8 Transfer_mode;
	u8 Source;
	u8 Destination;
	u8 Circular_mode;
	u8 Interrupt_mode;
}
DMA_Config_t;


void DMA_voidChannelInit(DMA_Config_t DMA_Config,u32* Copy_Pu32SourceAddress, u32* Copy_Pu32DestAddress,u16 Copy_u16BlockLen);

void DMA_CH1_SetCallBack(void (*ptr) (void));
void DMA_CH2_SetCallBack(void (*ptr) (void));
void DMA_CH3_SetCallBack(void (*ptr) (void));
void DMA_CH4_SetCallBack(void (*ptr) (void));
void DMA_CH5_SetCallBack(void (*ptr) (void));
void DMA_CH6_SetCallBack(void (*ptr) (void));
void DMA_CH7_SetCallBack(void (*ptr) (void));



















#endif
