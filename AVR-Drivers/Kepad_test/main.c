/*
 * main.c
 *
 *  Created on: Oct 2, 2021
 *      Author: ENG TAREK
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include <avr/delay.h>
#include "LCD_interface.h"
#include "KPD_interface.h"

u32 Concat(u8 *Arr, u8 Local_u8End, u8 Local_u8Start);
int main() {
	u8 Local_u8Key, Local_u8Counter1 = 0, Local_u8Counter2 = 0;
	u8 Local_Au8Numbers[15] = { '?' };
	u16 Local_Au16FirstNumber[15] = { 0 };
	u8 Local_u8Num = 0, Local_u8End = 1;
	DIO_u8Init();
	LCD_voidInit8Bit();
	LCD_u8GoToXY(1, 0);
	while (1) {
		KPD_u8GetKey(&Local_u8Key);
		if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED) {
			LCD_voidWriteChar(Local_u8Key);
			Local_Au8Numbers[Local_u8Counter1] = Local_u8Key;
			if ((Local_Au8Numbers[Local_u8Counter1] - '0') < 10) {
				if (Local_u8Counter2 != 0)
					Local_u8Num *= 10;
				Local_u8Num += Local_Au8Numbers[Local_u8Counter1];
				Local_u8Counter2++;
			} else {
				Local_u8Counter2 = 0;
				Local_u8Num += Local_Au8Numbers[Local_u8Counter1];
				Local_Au16FirstNumber[]=Local_u8Num;
				Local_u8Num = 0;
			}
			Local_u8Counter1++;

		}

		return 0;
	}

	u32 Concat(u8 *Arr, u8 end, u8 start) {
		u32 result = 0;
		u8 i;
		for (i = start; i < end; i++) {

		}

		return result;
	}
