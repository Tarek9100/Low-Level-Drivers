/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*								Date : 24/9/2021                                   */
/*                              SWC : LCD                                          */
/*								Version : 1.0                                      */
/***********************************************************************************/

/*Library layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <avr/delay.h>
/*MCAL*/
#include "DIO_interface.h"

/*HAL*/
#include"LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

void LCD_voidInit8Bit(void) {
	_delay_ms(35);
	LCD_voidWriteCmd(0b00111000);
	LCD_voidWriteCmd(0b00001100);
	LCD_voidWriteCmd(0x01);
	_delay_ms(2);
	LCD_voidWriteCmd(0b00000110);
}

void LCD_voidInit4Bit(void) {
	_delay_ms(35);
	LCD_voidWriteCmd(0b00100000);
	LCD_voidWriteCmd(0b00100000);
	LCD_voidWriteCmd(0b00100000);
	LCD_voidWriteCmd(0b00000000);
	LCD_voidWriteCmd(0b11000000);
	LCD_voidWriteCmd(0b00000000);
	LCD_voidWriteCmd(0b00010000);
	_delay_ms(2);
	LCD_voidWriteCmd(0b00000000);
	LCD_voidWriteCmd(0b01100000);
}
void LCD_voidWriteChar(u8 Copy_u8Char) {
	/* RS =  1 (Data byte)        */
	DIO_u8SetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8_HIGH);
	/* R/w = 0 (Write operation) */
	DIO_u8SetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);
	/* Send Data byte to LCD    */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Char);
	/*Enable pulse             */
	DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, DIO_u8_HIGH);
	_delay_us(2);
	DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, DIO_u8_LOW);
}
void LCD_voidWriteCmd(u8 Copy_u8Cmd) {
	/* RS =  0 (command byte)        */
	DIO_u8SetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8_LOW);
	/* R/w = 0 (Write operation) */
	DIO_u8SetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);
	/* Send Data byte to LCD    */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Cmd);
	/*Enable pulse             */
	DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, DIO_u8_HIGH);
	_delay_us(2);
	DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, DIO_u8_LOW);
}
void LCD_voidWriteString(u8 *Copy_Pu8String) {
	u8 Local_u8_stringcounter = 0;
	/* Send Data byte to LCD */
	while (Copy_Pu8String[Local_u8_stringcounter] != '\0') {
		LCD_voidWriteChar(Copy_Pu8String[Local_u8_stringcounter]);
		Local_u8_stringcounter++;
	}
}
u8 LCD_u8GoToXY(u8 Copy_u8LineNum, u8 Copy_u8CharLocation) {
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch (Copy_u8LineNum) {
	case LCD_u8_LINE_1:
		LCD_voidWriteCmd(0x80 + Copy_u8CharLocation);
		break;
	case LCD_u8_LINE_2:
		LCD_voidWriteCmd(0xC0 + Copy_u8CharLocation);
		break;
	default:
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

void LCD_voidWriteNumber(u16 Copy_u16Number) {
	u16 Local_u16_Remaining;
	u16 Local_u16_Reverse = 1;
	u8 Local_u8_FinalReverse;

	if (Copy_u16Number == 0) {
		LCD_voidWriteChar(Copy_u16Number + '0');
	} else {
		while (Copy_u16Number != 0) {
			Local_u16_Remaining = Copy_u16Number % 10;
			Local_u16_Reverse = Local_u16_Reverse * 10 + Local_u16_Remaining;
			Copy_u16Number /= 10;
		}
		while (Local_u16_Reverse != 1) {
			Local_u8_FinalReverse = Local_u16_Reverse % 10;
			LCD_voidWriteChar(Local_u8_FinalReverse + '0');
			Local_u16_Reverse /= 10;
		}
	}
}
void LCD_voidWriteSpecialChar(u8* Copy_Au8Pattern, u8 Copy_u8PatternNumber,
		u8 Copy_u8XPos, u8 Copy_u8YPos) {
	u8 Local_u8CGRAMAddress = 0, Local_u8Counter;
	/*Calculate CGRAM Address*/
	Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;
	/* Send CG Ram address command to LCD, with setting bit 6 , and clearing bit 7*/
	LCD_voidWriteCmd(Local_u8CGRAMAddress + 64);
	/*Write the pattern into CG Ram*/
	for (Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
		LCD_voidWriteChar(Copy_Au8Pattern[Local_u8Counter]);
	/*Going Back to DD Ram to display Pattern*/
	LCD_u8GoToXY(Copy_u8XPos, Copy_u8YPos);
	/*Display Pattern written in CG Ram*/
	LCD_voidWriteChar(Copy_u8PatternNumber);
}

