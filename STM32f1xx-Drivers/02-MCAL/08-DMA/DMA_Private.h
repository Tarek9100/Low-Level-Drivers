/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*                              SWC : 	DMA                                        */
/***********************************************************************************/
#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

static void (*CH1_CallBack)(void) = NULL;
static void (*CH2_CallBack)(void) = NULL;
static void (*CH3_CallBack)(void) = NULL;
static void (*CH4_CallBack)(void) = NULL;
static void (*CH5_CallBack)(void) = NULL;
static void (*CH6_CallBack)(void) = NULL;
static void (*CH7_CallBack)(void) = NULL;


/*Transfer Modes */
#define Memory_TO_Memory 	0
#define Periph_TO_Memory 	1
#define Memory_TO_Periph 	2
#define Periph_TO_Periph 	3

/*Peripherals*/
typedef enum {
ADC_1,I2C_1,I2C_2,USART_1,USART_2,USART_3,SPI_1,SPI_2
}DMA_Peripherals;


#define Circular 			0
#define NOT_Circular		1

/*Interrupt Modes */
typedef enum{
	Free_running,Transfer_Complete,Half_Transfer_Complete,Transfer_Error
}DMA_Int_Modes;


















#endif
