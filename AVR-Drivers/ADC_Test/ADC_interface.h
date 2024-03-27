/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*								Date : 30/10/2021                                  */
/*                              SWC : ADC                                          */
/*								Version : 1.0                                      */
/***********************************************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);
u8 ADC_u8GetDigitalValueSync(u8 Copy_u8ChannelNum,u16 *Copy_pu16ReturnedDigitalValue);
u8 ADC_u8GetDigitalValueAsync(u8 Copy_u8ChannelNum ,u16 *Copy_pu16ReturnedDigitalValue , void(*Copy_pf)(void));
#endif
