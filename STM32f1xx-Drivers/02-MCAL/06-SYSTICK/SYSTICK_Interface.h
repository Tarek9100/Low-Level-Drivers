/*
 * SYSTICK_Interface.h
 *
 *  Created on: Jul 12, 2022
 *      Author: ENG TAREK
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


void STK_Delay_MicroSeconds(u32 Copy_u32MicroSecond);

void STK_Count_MicroSeconds(u32 Copy_u32MicroSecond, void (*Copy_ptr)(void));

void STK_Stop_Interval(void);

u32 STK_Get_Elapsed_Time(void);
u32 STK_Get_Remaining_Time(void);

#endif /* SYSTICK_INTERFACE_H_ */
