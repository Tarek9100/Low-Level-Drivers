#ifndef WDT_H_
#define WDT_H_



void WDT1_Init(void);

void WDT1_SetTrigger( u32 Copy_u32Timeout);

void WDT_SetCallBack(void (*ptr)(void));



















#endif