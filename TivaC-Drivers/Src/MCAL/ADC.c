#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Mcu_HW.h"
#include "ADC.h"
#include "ADC_Cfg.h"

void ADC_Init(){
GPIOD_PCLK_EN();GPIOE_PCLK_EN();GPIOF_PCLK_EN(); //Enabling first 10 ADC channels 	
GPIOD->CR|=0x0F;GPIOE->CR|=0xFF;GPIOF->CR|=0xFF;	
	
	
}