/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*                              SWC : 	GPIO                                       */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"


void GPIO_PerClockControl(GPIO_RegDef_t *pGPIO_x,u8 EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIO_x == GPIOA){
			GPIOA_PCLK_EN();
		}else if(pGPIO_x == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(pGPIO_x == GPIOC)
		{
			GPIOC_PCLK_EN();
	}else{

		if(pGPIO_x == GPIOA){
					GPIOA_PCLK_DI();
				}else if(pGPIO_x == GPIOB)
				{
					GPIOB_PCLK_DI();
				}else if(pGPIO_x == GPIOC)
				{
					GPIOC_PCLK_DI();
				}
		}
}
}
/*void GPIO_All_Init(void){
}
*/
void GPIO_Initialize(GPIO_Handler * pGPIO_Handle){
	switch(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Mode){
	case GPIO_OUTPUT:

		if((pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)/8){
			pGPIO_Handle-> pGPIO_x->CR[1] &= ~( 0xF << ( 4 * (pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number-8))); // Clearing pre-set Mode bits before changing configuration
			pGPIO_Handle->pGPIO_x->CR[1] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Output_Type <<((4*(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number-8))));// x4 as each pin takes 2 bit-fields
			pGPIO_Handle->pGPIO_x->CR[1] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Speed <<((4*(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number-8))));// x4 as each pin takes 2 bit-fields
			}
		else{
			pGPIO_Handle-> pGPIO_x->CR[0] &= ~( 0xF << ( 4 * pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)); // Clearing pre-set Mode bits before changing configuration
			pGPIO_Handle->pGPIO_x->CR[0] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Output_Type <<(4*pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number));// x4 as each pin takes 2 bit-fields
			pGPIO_Handle->pGPIO_x->CR[0] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Speed <<((4*pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)));// x4 as each pin takes 2 bit-fields
			}break;
	case GPIO_INPUT:
		if((pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)/8){
		pGPIO_Handle-> pGPIO_x->CR[1] &= ~( 0xF << ( 4 * (pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number-8))); // Clearing pre-set Mode bits before changing configuration
		pGPIO_Handle->pGPIO_x->CR[1] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Input_Type <<((4*(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number-8))));// x4 as each pin takes 2 bit-fields
		}
		else{
		pGPIO_Handle-> pGPIO_x->CR[0] &= ~( 0xF << ( 4 * pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)); // Clearing pre-set Mode bits before changing configuration
		pGPIO_Handle->pGPIO_x->CR[0] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Input_Type <<(4*pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number));// x4 as each pin takes 2 bit-fields
		}
		if(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Input_Type == GPIO_IP_PullUp){
			pGPIO_Handle->pGPIO_x->BSRR = (1<<pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number);
			if((pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)/8) pGPIO_Handle->pGPIO_x->CR[1] &=~(4 <<((4*(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number-8))));
			else pGPIO_Handle->pGPIO_x->CR[0] &= ~(4<<(4*pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number));
		}break;
	 case GPIO_AF:

		if((pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)/8){
			pGPIO_Handle-> pGPIO_x->CR[1] &= ~( 0xF << ( 4 * (pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number-8))); // Clearing pre-set Mode bits before changing configuration
			pGPIO_Handle->pGPIO_x->CR[1] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Alt_Function <<((4*(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number-8))));// x4 as each pin takes 2 bit-fields
			pGPIO_Handle->pGPIO_x->CR[1] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Speed <<((4*(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number-8))));// x4 as each pin takes 2 bit-fields
			}
		else{
			pGPIO_Handle-> pGPIO_x->CR[0] &= ~( 0xF << ( 4 * pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)); // Clearing pre-set Mode bits before changing configuration
			pGPIO_Handle->pGPIO_x->CR[0] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Alt_Function <<(4*pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number));// x4 as each pin takes 2 bit-fields
			pGPIO_Handle->pGPIO_x->CR[0] |=(pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Speed <<((4*pGPIO_Handle->GPIO_PinConfig.GPIO_Pin_Number)));// x4 as each pin takes 2 bit-fields
			}break;
	default:break;
}
}

void GPIO_Deinit(GPIO_RegDef_t *pGPIOx){
	if(pGPIOx == GPIOA){
			GPIOA_PCLK_DI();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
}


u8 GPIO_ReadPin(GPIO_RegDef_t  * pGPIO_x,u8 Pin_Number)
{
	return  ((u8)GET_BIT(pGPIO_x ->IDR,Pin_Number));
}

void GPIO_WritePin(GPIO_RegDef_t  *pGPIO_x,u8 Pin_Number,u8 Value)
{
	if (Value != LOW)
	{
	//Write 1 to the output data register at the bit
	//SET_BIT(pGPIO_x->ODR,Pin_Number);
	pGPIO_x->BSRR = (1<<Pin_Number);
	}
	else
	{
	//CLR_BIT(pGPIO_x->ODR,Pin_Number);
	pGPIO_x->BRR =(1<<Pin_Number);
	}

}
u16 GPIO_ReadPort(GPIO_RegDef_t  * pGPIO_x)
{
	return ((u16) pGPIO_x->IDR);
}


void GPIO_WritePort(GPIO_RegDef_t  *pGPIO_x,u16 Value)
{
	pGPIO_x->ODR = Value;
}

void GPIO_TogglePin(GPIO_RegDef_t  *pGPIO_x,u8 Pin_Number){
	TOG_BIT(pGPIO_x->ODR,Pin_Number);
}
