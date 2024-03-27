/*
 * TIMER_interface.h
 *
 *  Created on: Nov 23, 2021
 *      Author: ENG TAREK
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_voidIntialize();

u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));

#endif /* TIMER_INTERFACE_H_ */
