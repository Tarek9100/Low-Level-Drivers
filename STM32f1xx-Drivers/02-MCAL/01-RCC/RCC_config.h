/**********************************************************
******************Author : TAREK WAEL**********************
******************Component : RCC	 **********************
******************Version : 01       **********************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/*Clock Type
 Options:
 1-RCC_HSE_CRYSTAL			2-RCC_HSE_RC				3-RCC_HSI			4-RCC_PLL  	
 */
#define RCC_CLOCK_TYPE		RCC_HSE_CRYSTAL

#if RCC_CLOCK_TYPE  ==       RCC_PLL
/*PLL Input Clock
Options: 
 1-RCC_PLL_HSI_DIV_2		2-RCC_PLL_HSE_DIV_2			3-RCC_PLL_HSE
*/
	
#define RCC_PLL_INPUT		RCC_PLL_HSI_DIV_2	

/*PLL Multiplier Value
Options: 2 --> 16
*/
#define RCC_PLL_MUL_VALUE	4
  
#endif
/*AHB Prescalar
Options:
1-SYSCLK_NO_DIV			2-SYSCLK_DIV_BY_2		3-SYSCLK_DIV_BY_4		4-SYSCLK_DIV_BY_8
5-SYSCLK_DIV_BY_16		6-SYSCLK_DIV_BY_64		7-SYSCLK_DIV_BY_128		8-SYSCLK_DIV_BY_256		
9-SYSCLK_DIV_BY_512	
*/
#define AHB_PRESCALAR	SYSCLK_NO_DIV

/*APB1 Prescalar
Options:
1-HCLK_NO_DIV			2-HCLK_DIV_BY_2			3-HCLK_DIV_BY_4			
4-HCLK_DIV_BY_8			5-HCLK_DIV_BY_16
*/
#define APB1_PRESCALAR	HCLK_NO_DIV

/*APB2 Prescalar
Options:
1-HCLK_NO_DIV			2-HCLK_DIV_BY_2			3-HCLK_DIV_BY_4			
4-HCLK_DIV_BY_8			5-HCLK_DIV_BY_16
*/
#define APB2_PRESCALAR	HCLK_NO_DIV
#endif
