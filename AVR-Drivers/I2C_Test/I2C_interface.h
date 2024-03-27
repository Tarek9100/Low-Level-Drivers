/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*								Date : 20/11/2021                                  */
/*                              SWC : I2C                                          */
/*								Version : 1.0                                      */
/***********************************************************************************/


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

typedef enum{
	I2C_OK,
	I2C_SC_ERR,
	I2C_RSC_ERR,
	I2C_SLA_W_ERR,
	I2C_SLA_R_ERR,
	I2C_DATA_MT_ERR,
	I2C_NULL_POINTER,
	I2C_DATA_MR_ERR
}I2C_ERROR_STATE_TYPE;
void I2C_voidInit(u8 Copy_u8MyAddress);

I2C_ERROR_STATE_TYPE I2C_EnuSendStartCondition(void);

I2C_ERROR_STATE_TYPE I2C_EnuSendRepeatedStartCondition(void);

I2C_ERROR_STATE_TYPE I2C_EnuSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

I2C_ERROR_STATE_TYPE I2C_EnuSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

I2C_ERROR_STATE_TYPE I2C_EnuSendDataByte(u8 Copy_u8Data_Byte);

I2C_ERROR_STATE_TYPE I2C_EnuReadDataByte(u8* Copy_Pu8RecData_Byte);

I2C_ERROR_STATE_TYPE I2C_EnuSendStopCondition(void);


#endif /* I2C_INTERFACE_H_ */
