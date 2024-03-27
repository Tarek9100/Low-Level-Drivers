/*
 * SYSTICK_Private.h
 *
 *  Created on: Jul 12, 2022
 *      Author: ENG TAREK
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

static void (*CallBack)(void) = NULL;
#define  SYSTICK_BASEADDR			0xE000E010

#define SYSTICK						((STK_RegDef_t*)SYSTICK_BASEADDR)
typedef struct{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_RegDef_t;

#define STK_ENABLE					0
#define STK_INT_ENABLE				1
#define STK_CLKSOURCE				3
#define STK_COUNTFLAG				16



#define ENABLE						1
#define DISABLE						0

#endif /* SYSTICK_PRIVATE_H_ */
