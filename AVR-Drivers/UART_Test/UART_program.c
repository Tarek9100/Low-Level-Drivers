/*
 * UART_program.c
 *
 *  Created on: Nov 12, 2021
 *      Author: ENG TAREK
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_voidInit(void){
u8 Local_u8UCSRCValue =	0X80;
u8 Local_u16UBRRValue=51;/**/
/*Enable RX circuit*/
SET_BIT(UART_u8_UCSRB_REG,4);
/*Enable TX*/
SET_BIT(UART_u8_UCSRB_REG,3);
/*Select Asynch mode*/
CLR_BIT(Local_u8UCSRCValue,6);
/*Select parity bits*/
CLR_BIT(Local_u8UCSRCValue,5);
CLR_BIT(Local_u8UCSRCValue,4);
/*Select stop bits*/
SET_BIT(Local_u8UCSRCValue,3);
/*Select Character Size =8 bits)*/
SET_BIT(Local_u8UCSRCValue,2);
SET_BIT(Local_u8UCSRCValue,1);
CLR_BIT(UART_u8_UCSRB_REG,2);
/*Update UCSRC Variable into UCSRC Register*/
UART_u8_UCSRC_REG = Local_u8UCSRCValue;

/*Select Baud Rate=9600*/
UART_u8_UBRRL_REG = (u8)Local_u16UBRRValue;
UART_u8_UBRRH_REG =(u8)(Local_u16UBRRValue>>8);
}

void UART_voidASendByte(u8 Copy_u8TxByte)
{
	// Wait for flag that indicates that the buffer is empty
	while(!GET_BIT(UART_u8_UCSRA_REG,5));
		// Write Data into Tx Buffer
		UART_u8_UDR_REG = Copy_u8TxByte;
}
u8 UART_u8ReceiveByte(void)
{
	// Wait for the flag that indicates that there is unread received data
	while(!GET_BIT(UART_u8_UCSRA_REG,7));
	return UART_u8_UDR_REG;
}
