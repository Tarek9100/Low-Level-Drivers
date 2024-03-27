

#define F_CPU 8000000UL
#include <avr/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"

//Master code
int main(void)
{
	u8 Local_u8Data;
	DIO_u8Init();
	SPI_voidInit();
	while(1)
	{
		Local_u8Data= SPI_u8Transieve('b');
		if(Local_u8Data == 5)
		{
			DIO_u8TogglePinValue(DIO_u8_PORTD,DIO_u8_PIN7);
		}
		_delay_ms(500);
		Local_u8Data= SPI_u8Transieve('a');
		if(Local_u8Data == 5)
		{
			DIO_u8TogglePinValue(DIO_u8_PORTD,DIO_u8_PIN7);
		}
		_delay_ms(500);
	}
	return 0;
}

//
//int main(void)
//{
//	//Slave code
//	u8 Local_u8Data;
//	DIO_u8Init();
//	SPI_voidInit();
//	while(1)
//	{
//		Local_u8Data= SPI_u8Transieve(5);
//		if(Local_u8Data == 'a')
//		{
//			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_HIGH);
//		}
//		else if(Local_u8Data == 'b')
//		{
//			DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_LOW);
//		}
//		//no need for delay as the master is delaying and the slave is waiting for the master
//	}
//	return 0;
//}
