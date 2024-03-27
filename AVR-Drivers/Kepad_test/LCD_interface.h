/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*								Date : 24/9/2021                                   */
/*                              SWC : LCD                                          */
/*								Version : 1.0                                      */
/***********************************************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


#define LCD_u8_LINE_1 	1
#define LCD_u8_LINE_2 	2

void LCD_voidInit4Bit(void);
void LCD_voidInit8Bit(void);
void LCD_voidWriteChar(u8 Copy_u8Char);
void LCD_voidWriteCmd(u8 Copy_u8Cmd);
void LCD_voidWriteString(u8 *Copy_Pu8String);
void LCD_voidWriteNumber(u16 Copy_u16Number);
void LCD_voidWriteSpecialChar(u8* Copy_Au8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);
u8 LCD_u8GoToXY(u8 Copy_u8LineNum,u8 Copy_u8CharLocation);


#endif
