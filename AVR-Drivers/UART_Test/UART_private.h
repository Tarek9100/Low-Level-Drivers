/*
 * UART_private.h
 *
 *  Created on: Nov 12, 2021
 *      Author: ENG TAREK
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


#define  UART_u8_UDR_REG		*((volatile u8*)0x2C)
#define  UART_u8_UCSRA_REG		*((volatile u8*)0x2B)
#define  UART_u8_UCSRB_REG		*((volatile u8*)0x2A)
#define  UART_u8_UCSRC_REG		*((volatile u8*)0x40)

#define  UART_u8_UBRRH_REG		*((volatile u8*)0x40)
#define  UART_u8_UBRRL_REG		*((volatile u8*)0x29)

#endif /* UART_PRIVATE_H_ */
