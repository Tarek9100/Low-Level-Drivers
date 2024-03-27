/*Lib Layer */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL*/
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"

void INT0_ISR();

int main(){
/*Set Directions of PD2(EXTI0) --> Input Pull-up// PC0(Led) --> Output */
	DIO_u8Init();
	EXTI_voidINT0Init();
	EXTI_u8Int0SetCallBack(&INT0_ISR);
	GIE_voidEnable();
	while(1)
	{


	}
	return 0;
}
/*ISR of EXTI0 implementation*/
void INT0_ISR(){
DIO_u8TogglePinValue(DIO_u8_PORTC,DIO_u8_PIN0);
}
