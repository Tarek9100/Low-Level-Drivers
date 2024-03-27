/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*								Date : 9/10/2021                                   */
/*                              SWC : EXTI                                         */
/*								Version : 1.0                                      */
/***********************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


void EXTI_voidINT0Init(void);
void EXTI_voidINT1Init(void);
void EXTI_voidINT2Init(void);
u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void));
u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func)(void));
u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func)(void));
#define GICR_INT0	6
#define GICR_INT1	7
#define GICR_INT2	5

#define MCUCR_ISC11	3
#define MCUCR_ISC10	2
#define MCUCR_ISC01	1
#define MCUCR_ISC00	0

#define MCUCSR_INT2	6

#endif /* EXTI_INTERFACE_H_ */
