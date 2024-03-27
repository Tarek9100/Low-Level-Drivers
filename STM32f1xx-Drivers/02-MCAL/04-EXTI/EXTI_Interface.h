/*
 * EXTI_Interface.h
 *
 *  Created on: Jul 11, 2022
 *      Author: ENG TAREK
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_



void EXTI_Init(u8 Copy_u8Line, AFPortMap Copy_u8PortMap, u8 Copy_u8Mode );
void EXTI_Disable(u8 Copy_u8Line);
void EXTI_SWTrigger(u8 Copy_u8Line);
void EXTI0_SetCallBack(void (*ptr) (void));
void EXTI1_SetCallBack(void (*ptr) (void));
void EXTI2_SetCallBack(void (*ptr) (void));
void EXTI3_SetCallBack(void (*ptr) (void));
void EXTI4_SetCallBack(void (*ptr) (void));
void EXTI5_SetCallBack(void (*ptr) (void));
void EXTI6_SetCallBack(void (*ptr) (void));
void EXTI7_SetCallBack(void (*ptr) (void));
void EXTI8_SetCallBack(void (*ptr) (void));
void EXTI9_SetCallBack(void (*ptr) (void));
void EXTI10_SetCallBack(void (*ptr) (void));
void EXTI11_SetCallBack(void (*ptr) (void));
void EXTI12_SetCallBack(void (*ptr) (void));
void EXTI13_SetCallBack(void (*ptr) (void));
void EXTI14_SetCallBack(void (*ptr) (void));
void EXTI15_SetCallBack(void (*ptr) (void));
#endif /* EXTI_INTERFACE_H_ */
