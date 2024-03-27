/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*                              SWC : 	NVIC                                       */
/***********************************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


static void (*CallBack)(void) = NULL;

#define NVIC_BASEADDR				0xE000E100U
#define SCB_BASEADDR				0xE000ED00U

#define NVIC_ISER0					*((volatile u32*)NVIC_BASEADDR)              //Enable external interrupts from 0 to 31
#define NVIC_ISER1					*((volatile u32*)NVIC_BASEADDR + 0x0004)	 //Enable external interrupts from 32 to 63

#define NVIC_ICER0					*((volatile u32*)NVIC_BASEADDR + 0x0080)     //Disable external interrupts from 0 to 31
#define NVIC_ICER1					*((volatile u32*)NVIC_BASEADDR + 0x0084)	 //Disable external interrupts from 32 to 63

#define NVIC_ISPR0					*((volatile u32*)NVIC_BASEADDR + 0x0100)     //Set Pending flag from 0 to 31
#define NVIC_ISPR1					*((volatile u32*)NVIC_BASEADDR + 0x0104)	 //Set Pending flag from 32 to 63

#define NVIC_ICPR0					*((volatile u32*)NVIC_BASEADDR + 0x0180)     //Clear Pending flag from 0 to 31
#define NVIC_ICPR1					*((volatile u32*)NVIC_BASEADDR + 0x0184)	 //Clear Pending flag from 32 to 63

#define NVIC_IABR0					*((volatile u32*)NVIC_BASEADDR + 0x0200)     //Read active flag from 0 to 31
#define NVIC_IABR1					*((volatile u32*)NVIC_BASEADDR + 0x0204)	 //Read active flag from 32 to 63

#define NVIC_IPR					 ((volatile u8*)NVIC_BASEADDR + 0x0300)      //Interrupt priority register

#define SCB_AIRCR					*((volatile u32*)SCB_BASEADDR + 0x000C)		 //System control register responsible for interrupt groups & sub-groups

#define SCB_GROUP3                   0x05FA0300
#define SCB_GROUP4                   0x05FA0400
#define SCB_GROUP5                   0x05FA0500
#define SCB_GROUP6                   0x05FA0600
#define SCB_GROUP7                   0x05FA0700



#define ENABLE 							1
#define DISABLE							0






#endif
