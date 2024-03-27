/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*								Date : 20/11/2021                                  */
/*                              SWC : I2C                                          */
/*								Version : 1.0                                      */
/***********************************************************************************/

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define TWI_u8_TWBR_REG		 *((volatile u8*)0x20)
#define TWI_u8_TWCR_REG      *((volatile u8*)0x56)
#define TWI_u8_TWSR_REG      *((volatile u8*)0x21)

#define TWI_u8_TWDR_REG      *((volatile u8*)0x23)

#define TWI_u8_TWAR_REG      *((volatile u8*)0x22)


#endif /* I2C_PRIVATE_H_ */
