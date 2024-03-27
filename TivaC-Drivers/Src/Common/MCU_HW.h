#ifndef MCU_HW_H
#define MCU_HW_H

#define HIGH		1
#define LOW			0

#define ENABLE 		1
#define DISABLE 	0


#define RCC_BASEADDR									0x400FE000U 
#define RCC_TIM											*((volatile u32*)(RCC_BASEADDR + 0x604))
#define RCC_GPIO										*((volatile u32*)(RCC_BASEADDR + 0x608))
#define RCC_ADC											*((volatile u32*)(RCC_BASEADDR + 0x638))
#define RCC_TIMW										*((volatile u32*)(RCC_BASEADDR + 0x65C))
#define RCC_PRTIM										*((volatile u32*)(RCC_BASEADDR + 0xA04))
#define RCC_PRGPIO										*((volatile u32*)(RCC_BASEADDR + 0xA08))
#define RCC_PRTIMW										*((volatile u32*)(RCC_BASEADDR + 0xA5C))
												

#define NVIC_BASEADDR				0xE000E100U
#define SCB_BASEADDR				0xE000ED00U

#define NVIC_ISER0					*((volatile u32*)NVIC_BASEADDR)              //Enable external interrupts from 0 to 31
#define NVIC_ISER1					*((volatile u32*)NVIC_BASEADDR + 0x0004)	 //Enable external interrupts from 32 to 63

#define NVIC_ICER0					*((volatile u32*)NVIC_BASEADDR + 0x0080)     //Disable external interrupts from 0 to 31
#define NVIC_ICER1					*((volatile u32*)NVIC_BASEADDR + 0x0084)	 //Disable external interrupts from 32 to 63

#define NVIC_ISPR0					*((volatile u32*)NVIC_BASEADDR + 0x0100)     //Set Pending flag from 0 to 31
#define NVIC_ISPR1					*((volatile u32*)NVIC_BASEADDR + 0x0104)	 //Set Pending flag from 32 to 63

#define NVIC_ICPR0					*((volatile u32*)NVIC_BASEADDR + 0x0180)     //Clear Pending flag from 0 to 31
#define NVIC_ICPR1					*((volatile u32*)NVIC_BASEADDR + 0x0184)	 //Clear Pending flag from 32 to 63

#define NVIC_IABR0					*((volatile u32*)NVIC_BASEADDR + 0x0200)     //Read active flag from 0 to 31
#define NVIC_IABR1					*((volatile u32*)NVIC_BASEADDR + 0x0204)	 //Read active flag from 32 to 63

#define NVIC_IPR					 ((volatile u8*)NVIC_BASEADDR + 0x0300)      //Interrupt priority register

#define APINT					*((volatile u32*)SCB_BASEADDR + 0x000C)		 //System control register responsible for interrupt groups & sub-groups

#define SCB_GROUP3                   0x05FA0300									  // 4 bits for group and 0 bits for sub-group
#define SCB_GROUP4                   0x05FA0400                                   // 3 bits for group and 1 bits for sub-group
#define SCB_GROUP5                   0x05FA0500                                   // 2 bits for group and 2 bits for sub-group
#define SCB_GROUP6                   0x05FA0600                                   // 1 bits for group and 3 bits for sub-group
#define SCB_GROUP7                   0x05FA0700                                   // 0 bits for group and 4 bits for sub-group


/**************************GPIO Port Definitions************************/
#define GPIO_APB_BASEADDR								0x40004000U


#define GPIOA_BASEADDR								GPIO_APB_BASEADDR
#define GPIOB_BASEADDR								(GPIO_APB_BASEADDR + 0x1000)
#define GPIOC_BASEADDR								(GPIO_APB_BASEADDR + 0x2000)
#define GPIOD_BASEADDR								(GPIO_APB_BASEADDR + 0x3000)
#define GPIOE_BASEADDR								(GPIO_APB_BASEADDR + 0x20000)
#define GPIOF_BASEADDR								(GPIO_APB_BASEADDR + 0x21000)

#define GPIOA  				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  				((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD  				((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE  				((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF  				((GPIO_RegDef_t*)GPIOF_BASEADDR)




typedef struct 
{
	volatile u32 DATA[256];                           
	volatile u32 DIR;
	volatile u32 IS;
	volatile u32 IBE;
	volatile u32 IEV;
	volatile u32 IM;
	volatile u32 RIS;
	volatile u32 MIS;	
	volatile u32 ICR;
	volatile u32 AFSEL;
	volatile u32 Reserved2[55];
	volatile u32 DR2R;
	volatile u32 DR4R;
	volatile u32 DR8R;
	volatile u32 ODR;
	volatile u32 PUR;
	volatile u32 PDR;
	volatile u32 SLR;	
	volatile u32 DEN;
	volatile u32 LOCK;
	volatile u32 CR;
	volatile u32 AMSEL;
	volatile u32 PCTL;
	volatile u32 ADCCTL;
	volatile u32 MACTL;	
	volatile u32 Reserved3[678];
	volatile u32 PeriphID4;
	volatile u32 PeriphID5;
	volatile u32 PeriphID6;
	volatile u32 PeriphID7;
	volatile u32 PeriphID0;
	volatile u32 PeriphID1;
	volatile u32 PeriphID2;
	volatile u32 PeriphID3;
	volatile u32 CellID0;
	volatile u32 CellID1;
	volatile u32 CellID2;
	volatile u32 CellID3;		
}GPIO_RegDef_t;



/***********************GPIO Clock Enable Macros*****************************/
#define GPIOA_PCLK_EN()			(RCC_GPIO|=(1<<0))
#define GPIOB_PCLK_EN()			(RCC_GPIO|=(1<<1))
#define GPIOC_PCLK_EN()			(RCC_GPIO|=(1<<2))
#define GPIOD_PCLK_EN()			(RCC_GPIO|=(1<<3))
#define GPIOE_PCLK_EN()			(RCC_GPIO|=(1<<4))
#define GPIOF_PCLK_EN()			(RCC_GPIO|=(1<<5))
/**********************GPIO Clock Disable Macros****************************/
#define GPIOA_PCLK_DI()			(RCC_GPIO&= ~(1<<0))
#define GPIOB_PCLK_DI()			(RCC_GPIO&= ~(1<<1))
#define GPIOC_PCLK_DI()			(RCC_GPIO&= ~(1<<2))
#define GPIOD_PCLK_DI()			(RCC_GPIO&= ~(1<<3))
#define GPIOE_PCLK_DI()			(RCC_GPIO&= ~(1<<4))
#define GPIOF_PCLK_DI()			(RCC_GPIO&= ~(1<<5))

/**********************************************************************/
/***************************WDT_1 Definition***************************/
#define WDT1_BASEADDR						0x40001000U
#define WDT1						((WDT1_RegDef_t*)WDT1_BASEADDR)

#define STANDARD					3
#define NMI							7
typedef struct{
	volatile u32 LOAD;
	volatile u32 VALUE;
	volatile u32 CTL;
	volatile u32 ICR;
	volatile u32 RIS;
	volatile u32 MIS;
	volatile u32 TEST;	
	volatile u32 LOCK;
	volatile u32 PeriphID4;
	volatile u32 PeriphID5;
	volatile u32 PeriphID6;
	volatile u32 PeriphID7;
	volatile u32 PeriphID0;
	volatile u32 PeriphID1;
	volatile u32 PeriphID2;
	volatile u32 PeriphID3;
	volatile u32 CellID0;
	volatile u32 CellID1;
	volatile u32 CellID2;
	volatile u32 CellID3;		
}WDT1_RegDef_t;
/***********************************************************************/
/***********************GPTM Definitions********************************/

#define GPTM_BASEADDR					0x40030000U

#define TIM0_BASEADDR					GPTM_BASEADDR
#define TIM1_BASEADDR					(GPTM_BASEADDR + 0x1000)
#define TIM2_BASEADDR					(GPTM_BASEADDR + 0x2000)
#define TIM3_BASEADDR					(GPTM_BASEADDR + 0x3000)
#define TIM4_BASEADDR					(GPTM_BASEADDR + 0x4000)
#define TIM5_BASEADDR					(GPTM_BASEADDR + 0x5000)

#define TIM0_WIDE_BASEADDR					(GPTM_BASEADDR + 0x6000)
#define TIM1_WIDE_BASEADDR					(GPTM_BASEADDR + 0x7000)
#define TIM2_WIDE_BASEADDR					(GPTM_BASEADDR + 0xC000)
#define TIM3_WIDE_BASEADDR					(GPTM_BASEADDR + 0xD000)
#define TIM4_WIDE_BASEADDR					(GPTM_BASEADDR + 0xE000)
#define TIM5_WIDE_BASEADDR					(GPTM_BASEADDR + 0xF000)

#define TIM0					((TIM_RegDef_t*)TIM0_BASEADDR)
#define TIM1					((TIM_RegDef_t*)TIM1_BASEADDR)
#define TIM2					((TIM_RegDef_t*)TIM2_BASEADDR)
#define TIM3					((TIM_RegDef_t*)TIM3_BASEADDR)
#define TIM4					((TIM_RegDef_t*)TIM4_BASEADDR)
#define TIM5					((TIM_RegDef_t*)TIM5_BASEADDR)
#define TIM_W0					((TIM_RegDef_t*)TIM0_WIDE_BASEADDR)
#define TIM_W1					((TIM_RegDef_t*)TIM1_WIDE_BASEADDR)
#define TIM_W2					((TIM_RegDef_t*)TIM2_WIDE_BASEADDR)
#define TIM_W3					((TIM_RegDef_t*)TIM3_WIDE_BASEADDR)
#define TIM_W4					((TIM_RegDef_t*)TIM4_WIDE_BASEADDR)
#define TIM_W5					((TIM_RegDef_t*)TIM5_WIDE_BASEADDR)

#define TIM0_PCLK_EN()			(RCC_TIM|=(1<<0))
#define TIM1_PCLK_EN()			(RCC_TIM|=(1<<1))
#define TIM2_PCLK_EN()			(RCC_TIM|=(1<<2))
#define TIM3_PCLK_EN()			(RCC_TIM|=(1<<3))
#define TIM4_PCLK_EN()			(RCC_TIM|=(1<<4))
#define TIM5_PCLK_EN()			(RCC_TIM|=(1<<5))
#define TIM0W_PCLK_EN()			(RCC_TIMW|=(1<<0))
#define TIM1W_PCLK_EN()			(RCC_TIMW|=(1<<1))
#define TIM2W_PCLK_EN()			(RCC_TIMW|=(1<<2))
#define TIM3W_PCLK_EN()			(RCC_TIMW|=(1<<3))
#define TIM4W_PCLK_EN()			(RCC_TIMW|=(1<<4))
#define TIM5W_PCLK_EN()			(RCC_TIMW|=(1<<5))

typedef struct{
	
	volatile u32 CFG;
	volatile u32 TAMR;
	volatile u32 TBMR;
	volatile u32 CTL;
	volatile u32 SYNC;
	volatile u32 Reserved1;
	volatile u32 IMR;
	volatile u32 RIS;	
	volatile u32 MIS;
	volatile u32 ICR;
	volatile u32 TAILR;
	volatile u32 TBILR;
	volatile u32 TAMATCHR;
	volatile u32 TBMATCHR;
	volatile u32 TAPR;
	volatile u32 TBPR;
	volatile u32 TAPMR;
	volatile u32 TBPMR;
	volatile u32 TAR;
	volatile u32 TBR;
	volatile u32 TAV;	
	volatile u32 TBV;	
	volatile u32 TCPD;	
	volatile u32 TAPS;	
	volatile u32 TBPS;	
	volatile u32 TAPV;	
	volatile u32 TBPV;	
	volatile u32 PP;
	
	
}TIM_RegDef_t;


#define None			0
#define _1US_16BIT 		1	
#define _1US_24BIT		2	
#define _1US_32BIT		3	
#define _100US_32BIT	4

/****************************************************************/
/***************************ADC Driver***************************/

#define ADC_BASEADDR					0x40038000U

#define ADC0_BASEADDR					ADC_BASEADDR
#define ADC1_BASEADDR					(ADC_BASEADDR + 0x1000)

#define ADC0							((ADC_RegDef_t*)ADC0_BASEADDR)
#define ADC1							((ADC_RegDef_t*)ADC1_BASEADDR)

typedef struct{
	volatile u32 ACTSS;
	volatile u32 RIS;	
	volatile u32 IM;
	volatile u32 ISC;
	volatile u32 OSTAT;
	volatile u32 EMUX;
	volatile u32 USTAT;
	volatile u32 TSSEL;
	volatile u32 SSPRI;
	volatile u32 SPC;
	volatile u32 PSSI;	
	volatile u32 SAC;
	volatile u32 DCISC;
	volatile u32 CTL;
	volatile u32 Reserved0;
	volatile u32 SSMUX0;
	volatile u32 SSCTL0;
	volatile u32 SSFIFO0;
	volatile u32 SSFSTAT0;
	volatile u32 SSOP0;
	volatile u32 SSDC0;
	volatile u32 Reserved1[2];
	volatile u32 SSMUX1;
	volatile u32 SSCTL1;
	volatile u32 SSFIFO1;
	volatile u32 SSFSTAT1;
	volatile u32 SSOP1;
	volatile u32 SSDC1;
	volatile u32 Reserved2[2];
	volatile u32 SSMUX2;
	volatile u32 SSCTL2;
	volatile u32 SSFIFO2;
	volatile u32 SSFSTAT2;
	volatile u32 SSOP2;
	volatile u32 SSDC2;
	volatile u32 Reserved3[2];
	volatile u32 SSMUX3;
	volatile u32 SSCTL3;
	volatile u32 SSFIFO3;
	volatile u32 SSFSTAT3;
	volatile u32 SSOP3;
	volatile u32 SSDC3;
	volatile u32 Reserved4[2];
	volatile u32 DCRIC;
	volatile u32 Reserved5[64];
	volatile u32 DCCTL0;
	volatile u32 DCCTL1;
	volatile u32 DCCTL2;
	volatile u32 DCCTL3;
	volatile u32 DCCTL4;
	volatile u32 DCCTL5;
	volatile u32 DCCTL6;
	volatile u32 DCCTL7;
	volatile u32 Reserved6[9];
	volatile u32 DCCMP0;
	volatile u32 DCCMP1;
	volatile u32 DCCMP2;
	volatile u32 DCCMP3;
	volatile u32 DCCMP4;
	volatile u32 DCCMP5;
	volatile u32 DCCMP6;
	volatile u32 DCCMP7;	
	volatile u32 Reserved7[89];
	volatile u32 PP;	
	volatile u32 PC;	
	volatile u32 CC;			
}ADC_RegDef_t;

#define ADC0_PCLK_EN()			(RCC_ADC|=(1<<0))
#define ADC1_PCLK_EN()			(RCC_ADC|=(1<<1))
#define ADC0_PCLK_DI()			(RCC_ADC&=~(1<<0))
#define ADC1_PCLK_DI()			(RCC_ADC&=~(1<<1))


#endif