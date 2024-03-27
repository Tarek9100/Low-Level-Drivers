/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*								Date : 30/10/2021                                  */
/*                              SWC : ADC                                          */
/*								Version : 1.0                                      */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"


static u16 *ADC_pu16DigitalValue = NULL;
static void(*ADC_pfNotification)(void) = NULL;
static u8 ADC_u8BusyFlag = ADC_u8_NOT_BUSY;

void ADC_voidInit(void){
	/*AVCC as reference voltage*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	/*Right Adjust*/
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	/*Set prescalar to divide by 128*/
	/*Clear the MUX bits in ADMUX register*/
	ADCSRA &= ADC_PSC_MASK;
	/*Set the required channel into the MUX bits*/
	ADCSRA |= ADC_PRESC;
	/*Enable Peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8GetDigitalValueSync(u8 Copy_u8ChannelNum ,u16 *Copy_pu16ReturnedDigitalValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32TimerOutCounter = 0;
	if((ADC_u8BusyFlag == ADC_u8_NOT_BUSY ) && (Copy_u8ChannelNum <= 31) && (Copy_pu16ReturnedDigitalValue != NULL) )
	{
		/*update busy flag to be in busy state*/
		ADC_u8BusyFlag = ADC_u8_BUSY;
		/*Clear channel region*/
		ADMUX &= ADC_MUX_MASK;
		/* Select channel */
		ADMUX |= Copy_u8ChannelNum ;
		/* Start conversion */
		SET_BIT(ADCSRA ,ADCSRA_ADSC);
		/* Wait for the Flag */
		while((GET_BIT(ADCSRA,ADCSRA_ADIF) == 0 ) && (Local_u32TimerOutCounter < 500000))
		{
			Local_u32TimerOutCounter++;
		}
		/*check flag is set*/
		if(GET_BIT(ADCSRA,ADCSRA_ADIF))
		{
			/*clear flag*/
			SET_BIT(ADCSRA,ADCSRA_ADIF);

			/* Read Digital Value */
			*Copy_pu16ReturnedDigitalValue = ADC;
		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else {
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 ADC_u8GetDigitalValueAsync(u8 Copy_u8ChannelNum ,u16 *Copy_pu16ReturnedDigitalValue , void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8ChannelNum < 31) && (Copy_pu16ReturnedDigitalValue != NULL) && (Copy_pf != NULL))
	{
		/* update global pointers */
		ADC_pu16DigitalValue = Copy_pu16ReturnedDigitalValue;
		ADC_pfNotification = Copy_pf;
		/*Clear channel region*/
		ADMUX &= ADC_MUX_MASK;
		/* Select channel */
		ADMUX|= Copy_u8ChannelNum ;
		/* Enable ADC interrupt */
		SET_BIT(ADCSRA ,ADCSRA_ADIE);
		/* Start conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);
	}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	return Local_u8ErrorState;
	}

void __vector_16(void)__attribute__((signal));
void __vector_16(void)
{
	if((ADC_pu16DigitalValue != NULL) && (ADC_pfNotification != NULL))
	{
		/* update Busy flag to be Not Busy*/
		ADC_u8BusyFlag = ADC_u8_NOT_BUSY ;
		/* update pointer with the result */
		*ADC_pu16DigitalValue = ADC;
		/*Call notification function*/
		ADC_pfNotification();
		/*Disable ADC interrupt */
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}
}
