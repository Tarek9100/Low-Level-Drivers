/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*								Date : 2/10/2021                                   */
/*                              SWC : KPD                                          */
/*								Version : 1.0                                      */
/***********************************************************************************/
/* Lib Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

static u8 KPD_Au8RowPins[4]={KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};
static u8 KPD_Au8RowPorts[4]={KPD_u8_R1_PORT,KPD_u8_R2_PORT,KPD_u8_R3_PORT,KPD_u8_R4_PORT};

static u8 KPD_Au8ColPins[4]={KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};
static u8 KPD_Au8ColPorts[4]={KPD_u8_C1_PORT,KPD_u8_C2_PORT,KPD_u8_C3_PORT,KPD_u8_C4_PORT};


static u8 KPD_Au8KEYS[4][4]= KPD_KEYS;


u8 KPD_u8GetKey(u8* Copy_pu8ReturnedKey){

	u8 Local_u8ErrorState=STD_TYPES_OK;
	u8 Local_u8RowCounter;
	u8 Local_u8ColCounter;
	u8 Local_u8PinValue;
	u8 Local_u8Flag=0;


	if(Copy_pu8ReturnedKey!=NULL)
	{
			//	Apply keypad algorithm
		*Copy_pu8ReturnedKey=KPD_u8_KEY_NOT_PRESSED;
			//	Activate each row then check the columns
			for(Local_u8RowCounter=0;Local_u8RowCounter<4;Local_u8RowCounter++)
					{
						// Activate row
						DIO_u8SetPinValue(KPD_Au8RowPorts[Local_u8RowCounter],KPD_Au8RowPins[Local_u8RowCounter],DIO_u8_LOW);

						for(Local_u8ColCounter=0;Local_u8ColCounter<4;Local_u8ColCounter++)
						{
							//check columns status
							DIO_u8GetPinValue(KPD_Au8ColPorts[Local_u8ColCounter],KPD_Au8ColPins[Local_u8ColCounter],&Local_u8PinValue);
							//check if pin value is low
							if(Local_u8PinValue==DIO_u8_LOW)//key pressed
							{
								//debouncing
								_delay_ms(20);
								while(Local_u8PinValue==DIO_u8_LOW)
								{
									//check columns status
									DIO_u8GetPinValue(KPD_Au8ColPorts[Local_u8ColCounter],KPD_Au8ColPins[Local_u8ColCounter],&Local_u8PinValue);
								}
								//return key value
								*Copy_pu8ReturnedKey=KPD_Au8KEYS[Local_u8RowCounter][Local_u8ColCounter];
								Local_u8Flag=1;
								break;
							}
						}
						// Deactivate row
						DIO_u8SetPinValue(KPD_Au8RowPorts[Local_u8RowCounter],KPD_Au8RowPins[Local_u8RowCounter],DIO_u8_HIGH);

							if(Local_u8Flag==1)
								break;
					}
	}
	else
	{
			Local_u8ErrorState=STD_TYPES_NOK;
	}


	return Local_u8ErrorState;


}
