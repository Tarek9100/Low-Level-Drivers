/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*                              SWC : 	S2P	                                       */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "S2P_Interface.h"
void S2P_voidSendSynchronous(u8 Copy_u8Data){
	s8 Local_s8Counter;
	u8 Local_u8Bit;
	for(Local_s8Counter=7;Local_s8Counter>=0;Local_s8Counter--){
		/*Send bit by bit starting from the MSB */
		Local_u8Bit = GET_BIT(Copy_u8Data,Local_s8Counter);
		GPIO_WritePin(STP_SERIAL_DATA,Local_s8Counter);
		/*Send Pulse to Shift Clock */
		GPIO_WritePin(STP_SHIFT_CLK,HIGH);
		STK_Delay_MicroSeconds(1);
		GPIO_WritePin(STP_SHIFT_CLK,LOW);
		STK_Delay_MicroSeconds(1);
	}
	/*Send Pulse to Storage Clock*/
	GPIO_WritePin(STP_STORAGE_CLK,HIGH);
	STK_Delay_MicroSeconds(1);
	GPIO_WritePin(STP_STORAGE_CLK,LOW);
	STK_Delay_MicroSeconds(1);

}
