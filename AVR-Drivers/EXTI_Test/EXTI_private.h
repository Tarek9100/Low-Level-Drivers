/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*								Date : 9/10/2021                                   */
/*                              SWC : EXTI                                         */
/*								Version : 1.0                                      */
/***********************************************************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define EXTI_u8_MCUCR_REG    *((volatile u8*)0x55)
#define EXTI_u8_MCUCSR_REG   *((volatile u8*)0x54)

#define EXTI_u8_GICR_REG     *((volatile u8*)0x5B)
#define EXTI_u8_GIFR_REG     *((volatile u8*)0x5A)

#define LOW_LEVEL		1
#define ON_CHANGE 		2
#define FALLING_EDGE 	3
#define RISING_EDGE 	4

#define	ENABLED 		1
#define DISABLED		2
#endif /* EXTI_PRIVATE_H_ */
