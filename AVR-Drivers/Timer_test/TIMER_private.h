/*
 * TIMER_private.h
 *
 *  Created on: Nov 23, 2021
 *      Author: ENG TAREK
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TCCR0 		*((volatile u8*)0x53) 	/*Timer0 Control Register*/
#define TCCR0_WGM00		6			/*Waveform generation Mode bit0*/
#define TCCR0_WGM01		3			/*Waveform generation Mode bit1*/
#define TCCR0_CS02		2			/*Prescalar bit2*/
#define TCCR0_CS01		1			/*Prescalar bit1*/
#define TCCR0_CS00		0			/*Prescalar bit0*/

#define OCR0 	*((volatile u8*)0x5C)	/*Output compare register0*/

#define TIMSK 	*((volatile u8*)0x59)	/*Timer mask*/
#define TIMSK_OCIE0		1				/*Output compare interrupt enable*/

#define TIMER0_u8_NORMAL	1
#define TIMER0_u8_PWM	2
#define TIMER0_u8_CTC	3

#endif /* TIMER_PRIVATE_H_ */
