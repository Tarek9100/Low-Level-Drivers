/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*                              SWC : 	NVIC                                       */
/***********************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


void NVIC_InterruptControl(u8 Copy_u8InterruptNum, u8 EnOrDi);
void NVIC_PendingFlagControl(u8 Copy_u8InterruptNum, u8 SetOrClr);
u8 NVIC_ReadActiveFlag(u8 Copy_u8InterruptNum);
void NVIC_SetPriority(s8 Copy_s8ID , u8 Copy_u8GroupPriority, u8 Copy_u8SubgroupPriority, u32 Copy_u32Group);
























#endif
