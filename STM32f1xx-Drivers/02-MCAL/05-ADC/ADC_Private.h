/*
 * ADC_Private.h
 *
 *  Created on: Jul 12, 2022
 *      Author: ENG TAREK
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define APB2PERIPH_BASEADDR			0x40010000U

#define ADC1_BASEADDR		(APB2PERIPH_BASEADDR + 0x2400)
#define ADC2_BASEADDR		(APB2PERIPH_BASEADDR + 0x2800)
#define ADC3_BASEADDR		(APB2PERIPH_BASEADDR + 0x3C00)
#define TIM4_BASEADDR		(APB1PERIPH_BASEADDR + 0x800)

#define ADC1 				((ADC_RegDef_t*)ADC1_BASEADDR)
#define ADC2 				((ADC_RegDef_t*)ADC2_BASEADDR)
#define ADC3 				((ADC_RegDef_t*)ADC3_BASEADDR)
#define TIM4				((TIM_RegDef_t*)TIM4_BASEADDR)

typedef struct{
volatile u32 CR[2];
volatile u32 SMCR;
volatile u32 DIER;
volatile u32 SR;
volatile u32 EGR;
volatile u32 CCMR[2];
volatile u32 CCER;
volatile u32 CNT;
volatile u32 PSC;
volatile u32 ARR;
volatile u32 Reserved1;
volatile u32 CCR[4];
volatile u32 Reserved2;
volatile u32 DCR;
volatile u32 DMAR;
}TIM_RegDef_t;

typedef struct{

volatile u32 SR;
volatile u32 CR[2];
volatile u32 SMPR[2];
volatile u32 JOFR[4];
volatile u32 HTR;
volatile u32 LTR;
volatile u32 SQR[3];
volatile u32 JSQR;
volatile u32 JDR[4];
volatile u32 DR;

}ADC_RegDef_t;
//CR1 Register Bit Definitions
#define JEOCIE		7
#define EOCIE		5
//CR2 Register Bit Definitions
#define ADON 		0
#define SWSTART		22
#define JSWSTART	21
#define JEXTTRIG	15

//SR Register Bit Definitions

#endif /* ADC_PRIVATE_H_ */
