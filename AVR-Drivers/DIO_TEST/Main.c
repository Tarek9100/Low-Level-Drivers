/*Lib Layer */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

/* MCAL*/
#include "DIO_interface.h"
int main(){
	u8 Local_u8SwitchValue=1;
	/*Set Direction of PC5 OUTPUT*/
	DIO_u8SetPinDirection(DIO_u8_PORTC,DIO_u8_PIN0,DIO_u8_OUTPUT);

	while(1)
	{
		DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN0,DIO_u8_HIGH);
		_delay_ms(2000);
		DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN0,DIO_u8_LOW);
		_delay_ms(2000);

	}
	return 0;
}
