/*
 * main.c
 *
 *  Created on: Oct 31, 2021
 *      Author: ENG TAREK
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "DIO_interface.h"

int main(){
	u8 Local_u8ADC_Reading;
	DIO_u8Init();
	ADC_voidInit();


	while(1){

	//Local_u8ADC_Reading = ADC_u8GetDigitalValueSync(0);
	DIO_u8SetPortValue(DIO_u8_PORTB,Local_u8ADC_Reading);
}
return 0;
}
