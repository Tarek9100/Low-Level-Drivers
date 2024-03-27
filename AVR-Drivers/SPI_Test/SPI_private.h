/*
 * SPI_private.h
 *
 *  Created on: Nov 13, 2021
 *      Author: ENG TAREK
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI_u8_SPCR_REG		*((volatile u8*)0x2D)
#define SPI_u8_SPSR_REG     *((volatile u8*)0x2E)
#define SPI_u8_SPDR_REG		*((volatile u8*)0x2F)

#define SPI_u8_MASTER 1
#define SPI_u8_SLAVE 2
#endif /* SPI_PRIVATE_H_ */
