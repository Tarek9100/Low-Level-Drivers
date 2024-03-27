#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include<avr/delay.h>

int main() {

	DIO_u8Init();
	LCD_voidInit8Bit();
	u8 Local_u8Frame=1;
	u8 Local_u8FrameNum=0;

	u8 Arr1[8] = { 0b11000, 0b01000, 0b11000, 0b10000, 0b10000, 0b11000,
			0b10100, 0b10000 };
	u8 Arr2[8] = { 0b00011, 0b00010, 0b00011, 0b01001, 0b00101, 0b00011,
			0b00001, 0b00001 };
	u8 Arr3[8] = { 0b00011, 0b00010, 0b00011, 0b00001, 0b00001, 0b01111,
			0b00001, 0b00001 };
	u8 Arr4[8] = { 0b00001, 0b00001, 0b00001, 0b00110, 0b00000, 0b00000,
			0b00000, 0b00000 };
	u8 Arr5[8] = { 0b10000, 0b10000, 0b10000, 0b01100, 0b00000, 0b00000,
			0b00000, 0b00000 };
	u8 Arr6[8] = { 0b00011, 0b00010, 0b00011, 0b00001, 0b00001, 0b00011,
			0b00101, 0b00001 };
	u8 Arr7[8] = { 0b01101, 0b01101, 0b00001, 0b00110, 0b00000, 0b00000,
			0b00000, 0b00000 };
	u8 Arr8[8] = { 0b00001, 0b00111, 0b01000, 0b00000, 0b00000, 0b00000,
			0b00000, 0b00000 };
	u8 Arr9[8] = { 0b00011, 0b00010, 0b00011, 0b00001, 0b00001, 0b00011,
			0b01101, 0b01101 };
	u8 Arr10[8] = { 0b10000, 0b01010, 0b00100, 0b00000, 0b00000, 0b00000,
			0b00000, 0b00000 };
	u8 Arr11[8] = { 0b00011, 0b00010, 0b00011, 0b01001, 0b00101, 0b00011,
			0b00001, 0b00001 };
	u8 Arr12[8] = { 0b00001, 0b01010, 0b00100, 0b00000, 0b00000, 0b00000,
			0b00000, 0b00000 };
	u8 Arr13[8] = { 0b11000, 0b01000, 0b11000, 0b10010, 0b10100, 0b11000,
			0b10000, 0b10000 };
	while (1) {
		DIO_u8GetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,&Local_u8Frame);
		if(Local_u8Frame==0){
			Local_u8FrameNum++;
			_delay_ms(400);
		}
		if(Local_u8FrameNum>2)
			Local_u8FrameNum=0;
		if(Local_u8FrameNum==0){
		 LCD_voidWriteCmd(1);
		 LCD_u8GoToXY(1, 0);
		 LCD_voidWriteString(" Hello ");
		 LCD_u8GoToXY(2, 0);
		 LCD_voidWriteString("I'm Tarek");
		 LCD_voidWriteSpecialChar(Arr1, 0, 1, 13);
		 LCD_voidWriteSpecialChar(Arr4, 2, 2, 12);
		 LCD_voidWriteSpecialChar(Arr5, 3, 2, 13);
		 LCD_voidWriteSpecialChar(Arr2, 1, 1, 12);
		 _delay_ms(300);
		 LCD_voidWriteSpecialChar(Arr3, 1, 1, 12);
		 _delay_ms(300);
		 }
		 if(Local_u8FrameNum==1){
		 LCD_voidWriteCmd(1);
		 LCD_u8GoToXY(1, 0);
		 LCD_voidWriteString(" I can play");
		 LCD_u8GoToXY(2, 0);
		 LCD_voidWriteString("football");
		 LCD_voidWriteSpecialChar(Arr1, 0, 1, 14);
		 LCD_voidWriteSpecialChar(Arr7, 2, 2, 13);
		 LCD_voidWriteSpecialChar(Arr5, 3, 2, 14);
		 LCD_voidWriteSpecialChar(Arr6, 1, 1, 13);
		 _delay_ms(300);
		 LCD_voidWriteSpecialChar(Arr8, 2, 2, 13);
		 LCD_voidWriteSpecialChar(Arr9, 1, 1, 13);
		 _delay_ms(300);}
		 if(Local_u8FrameNum==2){
		LCD_voidWriteCmd(1);
		LCD_u8GoToXY(1, 0);
		LCD_voidWriteString(" I can ");
		LCD_u8GoToXY(2, 0);
		LCD_voidWriteString("dance too");
		LCD_voidWriteSpecialChar(Arr13, 0, 1, 14);
		LCD_voidWriteSpecialChar(Arr12, 2, 2, 13);
		LCD_voidWriteSpecialChar(Arr5, 3, 2, 14);
		LCD_voidWriteSpecialChar(Arr11, 1, 1, 13);
		_delay_ms(300);
		LCD_voidWriteSpecialChar(Arr10, 3, 2, 14);
		LCD_voidWriteSpecialChar(Arr4, 2, 2, 13);
		_delay_ms(300);
	}
	}
	return 0;
}
