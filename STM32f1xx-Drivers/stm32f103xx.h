/*
 * stm32f103xx.h
 *
 *  Created on: May 8, 2022
 *      Author: ENG TAREK
 */

#ifndef STM_ADDRESSES_H
#define STM_ADDRESSES_H

#include "STD_TYPES.h"
/*
 * base addresses of Flash and SRAM memories
 */

#define FLASH_BASEADDR						0x08000000U
#define SRAM1_BASEADDR						0x20000000U
#define SRAM2_BASEADDR						0x2001C000U
#define ROM_BASEADDR						0x1FFF0000U
#define SRAM 								SRAM1_BASEADDR


/*
 * AHBx and APBx Bus Peripheral base addresses
 */

#define PERIPH_BASEADDR 						0x40000000U
#define APB1PERIPH_BASEADDR						PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR						0x40010000U
#define AHBPERIPH_BASEADDR						0x40018000U




#define GPIOA_BASEADDR                  (APB2PERIPH_BASEADDR + 0x0800)
#define GPIOB_BASEADDR                  (APB2PERIPH_BASEADDR + 0x0C00)
#define GPIOC_BASEADDR 					(APB2PERIPH_BASEADDR + 0x1000)

#define RCC_BASEADDR                    (AHBPERIPH_BASEADDR + 0x9000) /**/
#define EXTI_BASEADDR					(APB2PERIPH_BASEADDR + 0x0400)
#define AFIO_BASEADDR					(APB2PERIPH_BASEADDR + 0x0000)
#define SYSCFG_BASEADDR					(APB2PERIPH_BASEADDR + 0x3800)
#define DMA1_BASEADDR					(AHBPERIPH_BASEADDR + 0x8000)

#define SPI1_BASEADDR					(APB2PERIPH_BASEADDR + 0x3000)
#define SPI2_BASEADDR					(APB1PERIPH_BASEADDR + 0x3800)

#define I2C1_BASEADDR					(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR					(APB1PERIPH_BASEADDR + 0x5800)


#define USART1_BASEADDR					(APB2PERIPH_BASEADDR + 0x1000)
#define USART2_BASEADDR					(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR					(APB1PERIPH_BASEADDR + 0x4800)

/*
 * peripheral definitions ( Peripheral base addresses typecasted to xxx_RegDef_t)
 */

 typedef struct
{
	volatile u32 CR[2];
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_RegDef_t;

typedef struct
{
	volatile u32 CR[2];
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_RegDef_t;

typedef struct
{
	volatile u32 CR;					//RCC clock control register																	Address offset: 0x00
	volatile u32 CFGR;					//RCC clock configuration register																Address offset: 0x04
	volatile u32 CIR;					//RCC clock u32errupt register																	Address offset: 0x08
	volatile u32 APB2RSTR;				//RCC APB2 peripheral reset register															Address offset: 0x0C
	volatile u32 APB1RSTR;				//RCC APB1 peripheral reset register															Address offset: 0x10
	volatile u32 AHBENR;				//RCC AHB peripheral clock enable register														Address offset: 0x14
	volatile u32 APB2ENR;				//RCC APB2 peripheral clock enable register 													Address offset: 0x18
	volatile u32 APB1ENR;				//RCC APB1 peripheral clock enable register														Address offset: 0x1C
	volatile u32 BDCR;					//RCC Backup domain control register 															Address offset: 0x20
	volatile u32 CSR;					//RCC clock control & status register															Address offset: 0x24

}RCC_RegDef_t; /**/

typedef struct{

	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_RegDef_t;

typedef struct{

	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}AFIO_RegDef_t;



typedef struct{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;
}DMA_Channel_t;

typedef struct{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel_t Channel[7];

}DMA_RegDef_t;


typedef struct{
	volatile u32 USART_SR;
	volatile u32 USART_DR;
	volatile u32 USART_BRR;
	volatile u32 USART_CR[3];
	volatile u32 USART_GTPR;

}USART_RegDef_t;


#define GPIOA  				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  				((GPIO_RegDef_t*)GPIOC_BASEADDR)

#define RCC 				((RCC_RegDef_t*)RCC_BASEADDR)
#define SYSCFG				((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)
#define DMA1				((DMA_RegDef_t*)DMA1_BASEADDR)

#define SPI1				 ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2                 ((SPI_RegDef_t*)SPI2_BASEADDR)

#define EXTI 				((EXTI_RegDef_t*)EXTI_BASEADDR)
#define AFIO 				((AFIO_RegDef_t*)AFIO_BASEADDR)

#define USART1               ((USART_RegDef_t*)USART1_BASEADDR)
#define USART2               ((USART_RegDef_t*)USART2_BASEADDR)
#define USART3               ((USART_RegDef_t*)USART3_BASEADDR)
/*
 * Clock Enable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))

/*
 * Clock Enable Macros for DMA peripheral
 */

#define DMA1_PCLK_EN() (RCC->AHBENR |= (1 << 0))


/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN()			(RCC->APB2ENR |=(1<<2))
#define GPIOB_PCLK_EN()			(RCC->APB2ENR |=(1<<3))
#define GPIOC_PCLK_EN()			(RCC->APB2ENR |=(1<<4))

/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI()			(RCC->APB2ENR &= ~(1<<2))
#define GPIOB_PCLK_DI()			(RCC->APB2ENR &= ~(1<<3))
#define GPIOC_PCLK_DI()			(RCC->APB2ENR &= ~(1<<4))


/* Clock Enable/Disable for SPIx peripherals */

#define SPI1_PCLK_EN()			(RCC->APB2ENR |= (1<<12))
#define SPI1_PCLK_DI()			(RCC->APB2ENR &= ~(1<<12))

#define SPI2_PCLK_EN()			(RCC->APB1ENR |= (1<<14))
#define SPI2_PCLK_DI()			(RCC->APB1ENR &= ~(1<<14))

#define SPI3_PCLK_EN()			(RCC->APB1ENR |= (1<<15))
#define SPI3_PCLK_DI()			(RCC->APB1ENR &= ~(1<<15))

/* Clock Enable/Disable for USARTx peripherals */

#define USART1_PCLK_EN()			(RCC->APB2ENR |= (1<<4))
#define USART1_PCLK_DI()			(RCC->APB2ENR &= ~(1<<4))

#define USART2_PCLK_EN()			(RCC->APB1ENR |= (1<<17))
#define USART2_PCLK_DI()			(RCC->APB1ENR &= ~(1<<17))

#define USART3_PCLK_EN()			(RCC->APB1ENR |= (1<<18))
#define USART3_PCLK_DI()			(RCC->APB1ENR &= ~(1<<18))


/* Clock Enable/Disable for I2Cx peripherals */

#define I2C1_PCLK_EN()			(RCC->APB1ENR |= (1<<21))
#define I2C1_PCLK_DI()			(RCC->APB1ENR &= ~(1<<21))

#define I2C2_PCLK_EN()			(RCC->APB1ENR |= (1<<22))
#define I2C2_PCLK_DI()			(RCC->APB1ENR &= ~(1<<22))




#define IRQ_NO_EXTI0			6
#define IRQ_NO_EXTI1			7
#define IRQ_NO_EXTI2			8
#define IRQ_NO_EXTI3			9
#define IRQ_NO_EXTI4			10
#define IRQ_NO_EXTI9_5			23
#define IRQ_NO_EXTI15_10		40
#define IRQ_NO_DMA1_CH1			11
#define IRQ_NO_DMA1_CH2			12
#define IRQ_NO_DMA1_CH3			13
#define IRQ_NO_DMA1_CH4			14
#define IRQ_NO_DMA1_CH5			15
#define IRQ_NO_DMA1_CH6			16
#define IRQ_NO_DMA1_CH7			17

/*
	this enum represents Alternative function in lower register
	AFRLy: Alternate function selection for port x bit y (y = 0..7)
	These bits are written by software to configure alternate function I/Os
	AFRLy selection:
	0000: AF0
	0001: AF1
	0010: AF2
	0011: AF3
	0100: AF4
	0110: AF6
	0111: AF7
	1000: AF8
	1001: AF9
	1010: AF10
	1011: AF11
	1100: AF12
	1101: AF13
	1110: AF14
	1111: AF15
*/
typedef enum
{
	AF0,AF1,AF2,AF3,AF4,AF5,AF6,AF7,AF8,AF9,AF10,AF11,AF12,AF13,AF14,AF15
}Alt_FunctionL;

typedef enum
{
	A,B,C
}AFPortMap;
#endif

