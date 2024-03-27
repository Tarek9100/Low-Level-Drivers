/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*								Date : 20/11/2021                                  */
/*                              SWC : I2C                                          */
/*								Version : 1.0                                      */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_config.h"
#include"I2C_private.h"
#include "I2C_interface.h"


void I2C_voidInit(u8 Copy_u8MyAddress){
/*Assign our own address*/
TWI_u8_TWAR_REG = Copy_u8MyAddress<<1;
/*Enable Ack & Enable TWI*/
SET_BIT(TWI_u8_TWCR_REG,6);
SET_BIT(TWI_u8_TWCR_REG,2);
/*Set no Prescalar*/
CLR_BIT(TWI_u8_TWSR_REG,1);
CLR_BIT(TWI_u8_TWSR_REG,0);
/*Set TWBR Register to set CLK = 100KHz*/
TWI_u8_TWBR_REG = 32;

}

I2C_ERROR_STATE_TYPE I2C_EnuSendStartCondition(void){
	I2C_ERROR_STATE_TYPE Local_EnuErrorState = I2C_OK;

	/*Send Start Condition*/
	SET_BIT(TWI_u8_TWCR_REG,5);
	/*Clear flag to start job*/
	SET_BIT(TWI_u8_TWCR_REG,7);
	/*Wait for the flag */
	while(!GET_BIT(TWI_u8_TWCR_REG,7));
	/*Check status code*/
	if(TWI_u8_TWSR_REG & 0xF8 != 0x08){
	Local_EnuErrorState = I2C_SC_ERR;
	}
return Local_EnuErrorState;}

I2C_ERROR_STATE_TYPE I2C_EnuSendRepeatedStartCondition(void){
	I2C_ERROR_STATE_TYPE Local_EnuErrorState = I2C_OK;

		/*Send Start Condition*/
		SET_BIT(TWI_u8_TWCR_REG,5);
		/*Clear flag to start job*/
		SET_BIT(TWI_u8_TWCR_REG,7);
		/*Wait for the flag */
		while(!GET_BIT(TWI_u8_TWCR_REG,7));
		/*Check status code*/
		if(TWI_u8_TWSR_REG & 0xF8 != 0x10){
		Local_EnuErrorState = I2C_RSC_ERR;
		}
	return Local_EnuErrorState;
}


I2C_ERROR_STATE_TYPE I2C_EnuSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress){
	I2C_ERROR_STATE_TYPE Local_EnuErrorState = I2C_OK;
	/*Set Slave Address*/
	TWI_u8_TWDR_REG = Copy_u8SlaveAddress<<1;
	/*Select Write Mode*/
	CLR_BIT(TWI_u8_TWDR_REG,0);
	/*Clear Start condition bit*/
	CLR_BIT(TWI_u8_TWCR_REG,5);
	/*Clear flag to start job*/
	SET_BIT(TWI_u8_TWCR_REG,7);
	/*Wait for the flag */
	while(!GET_BIT(TWI_u8_TWCR_REG,7));
	/*Check status code*/
	if(TWI_u8_TWSR_REG & 0xF8 != 0x18){
	Local_EnuErrorState = I2C_SLA_W_ERR;
	}
	return Local_EnuErrorState;
	}

I2C_ERROR_STATE_TYPE I2C_EnuSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress){
		I2C_ERROR_STATE_TYPE Local_EnuErrorState = I2C_OK;
		/*Set Slave Address*/
		TWI_u8_TWDR_REG = Copy_u8SlaveAddress<<1;
		/*Select Read Mode*/
		SET_BIT(TWI_u8_TWDR_REG,0);
		/*Clear Start condition bit*/
		CLR_BIT(TWI_u8_TWCR_REG,5);
		/*Clear flag to start job*/
		SET_BIT(TWI_u8_TWCR_REG,7);
		/*Wait for the flag */
		while(!GET_BIT(TWI_u8_TWCR_REG,7));
		/*Check status code*/
		if(TWI_u8_TWSR_REG & 0xF8 != 0x40){
		Local_EnuErrorState = I2C_SLA_R_ERR;
		}
		return Local_EnuErrorState;
		}

I2C_ERROR_STATE_TYPE I2C_EnuSendDataByte(u8 Copy_u8Data_Byte){
			I2C_ERROR_STATE_TYPE Local_EnuErrorState = I2C_OK;
			/*Set Data into data register*/
			TWI_u8_TWDR_REG = Copy_u8Data_Byte;
			/*Clear flag to start job*/
			SET_BIT(TWI_u8_TWCR_REG,7);
			/*Wait for the flag */
			while(!GET_BIT(TWI_u8_TWCR_REG,7));
			/*Check status code*/
			if(TWI_u8_TWSR_REG & 0xF8 != 0x28){
			Local_EnuErrorState = I2C_DATA_MT_ERR;
			}
			return Local_EnuErrorState;
			}


I2C_ERROR_STATE_TYPE I2C_EnuReadDataByte(u8* Copy_Pu8RecData_Byte){
I2C_ERROR_STATE_TYPE Local_EnuErrorState = I2C_OK;
if(Copy_Pu8RecData_Byte != NULL){
/*Clear flag to start job*/
SET_BIT(TWI_u8_TWCR_REG,7);
/*Wait for the flag */
while(!GET_BIT(TWI_u8_TWCR_REG,7));
/*Check status code*/
if(TWI_u8_TWSR_REG & 0xF8 != 0x50){
Local_EnuErrorState = I2C_DATA_MR_ERR;
}
else
	*Copy_Pu8RecData_Byte = TWI_u8_TWDR_REG;
}
else
	Local_EnuErrorState =I2C_NULL_POINTER;
return Local_EnuErrorState;
}


I2C_ERROR_STATE_TYPE I2C_EnuSendStopCondition(void){
	I2C_ERROR_STATE_TYPE Local_EnuErrorState = I2C_OK;
		/*Send Stop Condition*/
		SET_BIT(TWI_u8_TWCR_REG,4);
		/*Clear flag to start job*/
		SET_BIT(TWI_u8_TWCR_REG,7);
	return Local_EnuErrorState;
}


