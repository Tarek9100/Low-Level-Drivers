/*
 * SPI_program.c
 *
 *  Created on: Nov 13, 2021
 *      Author: ENG TAREK
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"


#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"

void SPI_voidInit(void){
/*Enable SPI peripheral*/
SET_BIT(SPI_u8_SPCR_REG,6);
/*Select DORD =LSB*/
SET_BIT(SPI_u8_SPCR_REG,5);
#if SPI_u8_MODE == SPI_u8_MASTER
SET_BIT(SPI_u8_SPCR_REG,4);
/*Select Clk = f/64 */
SET_BIT(SPI_u8_SPCR_REG,1);
CLR_BIT(SPI_u8_SPCR_REG,0);
#elif 	SPI_u8_MODE == SPI_u8_SLAVE
CLR_BIT(SPI_u8_SPCR_REG,4);
#else
#error "Wrong Choice"
#endif
/*Select CPOL and CPHA = Leading Edge =Falling ,Setup */
SET_BIT(SPI_u8_SPCR_REG,3);
SET_BIT(SPI_u8_SPCR_REG,2);
}

u8 SPI_u8Transieve(u8 Copy_u8TxByte){
/*Write Data to be Transfered*/
SPI_u8_SPDR_REG =Copy_u8TxByte;
/*Wait for Flag*/
while(!GET_BIT(SPI_u8_SPSR_REG,7));
/*Read Data*/
return SPI_u8_SPDR_REG;
}

void SPI_u8SendByte(u8 Copy_u8TxByte){
/*Write Data to be Transfered*/
SPI_u8_SPDR_REG =Copy_u8TxByte;
/*Wait for Flag*/
while(!GET_BIT(SPI_u8_SPSR_REG,7));
}

u8 SPI_u8ReceiveByte(void){
/*Send Dummy Data*/
SPI_u8_SPDR_REG = 0xFF;
/*Wait for Flag*/
while(!GET_BIT(SPI_u8_SPSR_REG,7));
/*Read Data*/
return SPI_u8_SPDR_REG;
}
