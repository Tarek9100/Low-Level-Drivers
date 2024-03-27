/*
 * main.c
 *
 *  Created on: Nov 13, 2021
 *      Author: ENG TAREK
 */
#include "STD_TYPES.h"
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "DIO_interface.h"
#include "UART_interface.h"

int main(){
u8 Local_u8Var;
DIO_u8Init();
UART_voidInit();

while(1){
Local_u8Var= UART_u8ReceiveByte();
if(Local_u8Var == 'a')
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_HIGH);
else
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_LOW);
_delay_ms(500);
}

return 0;}

