/*
 * UART_interface.h
 *
 *  Created on: Nov 12, 2021
 *      Author: ENG TAREK
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit(void);

void UART_voidASendByte(u8 Copy_u8TxByte);

u8 UART_u8ReceiveByte(void);

#endif /* UART_INTERFACE_H_ */
