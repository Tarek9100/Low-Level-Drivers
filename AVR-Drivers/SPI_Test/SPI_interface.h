/*
 * SPI_interface.h
 *
 *  Created on: Nov 13, 2021
 *      Author: ENG TAREK
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidInit(void);

u8 SPI_u8Transieve(u8 Copy_u8TxByte);

void SPI_u8SendByte(u8 Copy_u8TxByte);

u8 SPI_u8ReceiveByte(void);

#endif /* SPI_INTERFACE_H_ */
