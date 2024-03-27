/*
 * ADC_Program.c
 *
 *  Created on: Jul 12, 2022
 *      Author: ENG TAREK
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"
#include "RCC.h"

static u16 analogData_1 = 0;
static u16 analogData_2 = 0;
void ADC1_Init(){
/*Enable ADC1 Peripheral Clock*/
ADC1_PCLK_EN();
/*Enable ADC*/
SET_BIT(ADC1->CR[1],ADON);
/*Enable Injected Channels External Interrupt*/
SET_BIT(ADC1->CR[0],JEOCIE);
/*Enable Regular Channels External Interrupt*/
SET_BIT(ADC1->CR[0],EOCIE);
/*Enable External Trigger for Injected Channels*/
SET_BIT(ADC1->CR[1],JEXTTRIG);
/*Enable continuous mode*/
ADC1->CR[1] |= (1<<1);
/*Select TIM4 TRGO Event as external event for injected group*/
ADC1->CR[1] &= ~(7<<12);
ADC1->CR[1] |= (5<<12);
/*Select channel 2 & 3 regular*/
ADC1->SQR[0] &= ~(15<<20);
ADC1->SQR[2] &= ~(0x3FF<<0);
ADC1->SQR[2] |= (2<<0);
ADC1->SQR[2] |= (3<<6);
/* Select channel 13 injected */
ADC1->JSQR &= ~(63<<16);
ADC1->JSQR |= (11<<16);
/* Timer 4 TRGO event Configuration for ADC1_IN13 */
TIM4_PCLK_EN();
/* Set counter direction as upward*/
CLR_BIT(TIM4->CR[0],4);
/* Set timer reload value, update event each 5 ms */
TIM4->PSC = 3999;
TIM4->ARR = 10;
 /* Select update event as trigger output (TRGO) */
 TIM4->CR[1] &= ~(7<<4);
 TIM4->CR[1] |= (1<<6);

 /* Enable TIM2 counter */
 TIM4->CR[0] |= (1<<0);

 /* Start conversion of regular channels */
 ADC1->CR[1] |= (1<<22);

}

void ADC_IRQ_Callback(void)
{
  /* Check ADC1 EOC */
  if(GET_BIT(ADC1->SR,1))
  {
    /* Read analog data and clear EOC flag */
    analogData_1 = ADC1->DR;

    /* Start conversion of regular channels */
   SET_BIT(ADC1->CR[1],SWSTART);
  }
  else
  {
    /* Regular conversion is not done */
  }

  /* Check ADC1 JEOC */
  if(GET_BIT(ADC1->SR,2))
  {
    /* Read analog data */
    analogData_2 = ADC1->JDR[0];

    /* Clear JEOC flag */
    CLR_BIT(ADC1->SR,2);

    /* Next conversion will be trigger by timer 4 TRGO event */
  }
  else
  {
    /* Regular conversion is not done */
  }
}

