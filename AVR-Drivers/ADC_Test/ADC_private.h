/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*								Date : 30/10/2021                                  */
/*                              SWC : ADC                                          */
/*								Version : 1.0                                      */
/***********************************************************************************/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX   	*((volatile u8*)0x27)		//ADC Multiplexer selection register
#define ADMUX_REFS1		7						//Reference selection bit 1
#define ADMUX_REFS0		6						//Reference selection bit 0
#define ADMUX_ADLAR		5						//ADC left adjust result

#define ADCSRA 		*((volatile u8*)0x26)		//ADC control and status register A
#define ADCSRA_ADEN		7						//ADC enable
#define ADCSRA_ADSC		6						//ADC start conversion
#define ADCSRA_ADATE	5						//ADC auto trigger enable 
#define ADCSRA_ADIF		4						//ADC interrupt flag
#define ADCSRA_ADIE		3						//ADC interrupt enable
#define ADCSRA_ADPS2	2						//ADC prescalar bit 2
#define ADCSRA_ADPS1	1						//ADC prescalar bit 1
#define ADCSRA_ADPS0	0						//ADC prescalar bit 0

#define ADCH   		*((volatile u8*)0x25)		//ADC high register
#define ADCL   		*((volatile u8*)0x24)		//ADC low register
#define ADC 		*((volatile u16*)0x24)

#define DIV_BY_2	0
#define DIV_BY_4	2
#define DIV_BY_8	3
#define DIV_BY_16	4
#define DIV_BY_32	5
#define DIV_BY_64	6
#define DIV_BY_128	7

#define ADC_PSC_MASK 	0b11111000
#define ADC_MUX_MASK 	0b11100000

#define ADC_u8_NOT_BUSY			0
#define ADC_u8_BUSY				1

#endif
