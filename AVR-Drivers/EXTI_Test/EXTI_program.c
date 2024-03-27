/*
 * program.c
 *
 *  Created on: Oct 9, 2021
 *      Author: ENG TAREK
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"

/*Global pointer to function to hold ISR addresses*/
static void (*EXTI_pvINT0Func)(void)=NULL;
static void (*EXTI_pvINT1Func)(void)=NULL;
static void (*EXTI_pvINT2Func)(void)=NULL;

void EXTI_voidINT0Init(void){
/*Check sense control*/
#if  INT0_SENSE	== LOW_LEVEL
CLR_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC01);
CLR_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC00);

#elif 	INT0_SENSE == ON_CHANGE
CLR_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC01);
SET_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC00);

#elif 	INT0_SENSE == FALLING_EDGE
SET_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC01);
CLR_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC00);

#elif 	INT0_SENSE == RISING_EDGE
SET_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC01);
SET_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC00);

#else
#error "Wrong INT0_SENSE Configuration option"
#endif
/*Check peripheral interrupt enable initial state*/
#if INT0_INITIAL_STATE == ENABLED
/*Enable EXTI0 Peripheral interrupt enable*/
SET_BIT(EXTI_u8_GICR_REG, GICR_INT0);
#elif INT0_INITIAL_STATE == DISABLED
/*Enable EXTI0 Peripheral interrupt enable*/
CLR_BIT(EXTI_u8_GICR_REG,GICR_INT0);
#else
#error "Wrong INT0_INITIAL_STATE Configuration option"
#endif
}

void EXTI_voidINT1Init(void){
/*Check sense control*/
#if  INT1_SENSE	== LOW_LEVEL
CLR_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC11);
CLR_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC10);

#elif 	INT1_SENSE == ON_CHANGE
CLR_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC11);
SET_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC10);

#elif 	INT1_SENSE == FALLING_EDGE
SET_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC11);
CLR_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC10);

#elif 	INT1_SENSE == RISING_EDGE
SET_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC11);
SET_BIT(EXTI_u8_MCUCR_REG,MCUCR_ISC10);

#else
#error "Wrong INT1_SENSE Configuration option"
#endif
/*Check peripheral interrupt enable initial state*/
#if INT1_INITIAL_STATE == ENABLED
/*Enable EXTI0 Peripheral interrupt enable*/
SET_BIT(EXTI_u8_GICR_REG,GICR_INT1);

#elif INT1_INITIAL_STATE == DISABLED
/*Enable EXTI0 Peripheral interrupt enable*/
CLR_BIT(EXTI_u8_GICR_REG,GICR_INT1);
#else
#error "Wrong INT0_INITIAL_STATE Configuration option"
#endif
}

void EXTI_voidINT2Init(void){
/*Select the trigger source of EXTI2 to falling edge*/
CLR_BIT(EXTI_u8_MCUCSR_REG,MCUCSR_INT2);
/*Enable EXTI2 Peripheral interrupt enable*/
SET_BIT(EXTI_u8_GICR_REG,GICR_INT2);
}

u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void)){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pvInt0Func!=NULL){
		EXTI_pvINT0Func = Copy_pvInt0Func;
	}
	else
		Local_u8ErrorState = STD_TYPES_NOK;
return Local_u8ErrorState;
}
u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func)(void)){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pvInt1Func!=NULL){
		EXTI_pvINT1Func = Copy_pvInt1Func;
	}
	else
		Local_u8ErrorState = STD_TYPES_NOK;
return Local_u8ErrorState;
}
u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func)(void)){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pvInt2Func!=NULL){
		EXTI_pvINT0Func = Copy_pvInt2Func;
	}
	else
		Local_u8ErrorState = STD_TYPES_NOK;
return Local_u8ErrorState;
}
/*ISR of INT0*/
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	if(EXTI_pvINT0Func != NULL){
		EXTI_pvINT0Func();
	}
	}
/*ISR of INT1*/
void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if(EXTI_pvINT1Func != NULL){
		EXTI_pvINT1Func();
	}
	}
/*ISR of INT2*/
void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	if(EXTI_pvINT2Func != NULL){
		EXTI_pvINT2Func();
	}
	}


