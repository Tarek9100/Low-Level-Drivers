/*
 * EXTI_Private.h
 *
 *  Created on: Jul 11, 2022
 *      Author: ENG TAREK
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

static void (*EXTI0_CallBack)(void)= NULL;
static void (*EXTI1_CallBack)(void)= NULL;
static void (*EXTI2_CallBack)(void)= NULL;
static void (*EXTI3_CallBack)(void)= NULL;
static void (*EXTI4_CallBack)(void)= NULL;
static void (*EXTI5_CallBack)(void)= NULL;
static void (*EXTI6_CallBack)(void)= NULL;
static void (*EXTI7_CallBack)(void)= NULL;
static void (*EXTI8_CallBack)(void)= NULL;
static void (*EXTI9_CallBack)(void)= NULL;
static void (*EXTI10_CallBack)(void)= NULL;
static void (*EXTI11_CallBack)(void)= NULL;
static void (*EXTI12_CallBack)(void)= NULL;
static void (*EXTI13_CallBack)(void)= NULL;
static void (*EXTI14_CallBack)(void)= NULL;
static void (*EXTI15_CallBack)(void)= NULL;

/*EXTI Lines*/
#define LINE0              0
#define LINE1              1
#define LINE2              2
#define LINE3              3
#define LINE4              4
#define LINE5              5
#define LINE6              6
#define LINE7              7
#define LINE8              8
#define LINE9              9
#define LINE10             10
#define LINE11             11
#define LINE12             12
#define LINE13             13
#define LINE14             14
#define LINE15             15

#define RISING				0
#define FALLING				1
#define CHANGE				2

#endif /* EXTI_PRIVATE_H_ */
