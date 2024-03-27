/***********************************************************************************/
/*                              Name : Tarek Wael                                  */
/*								Date : 16/10/2021                                  */
/*                              SWC : GIE                                          */
/*								Version : 1.0                                      */
/***********************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"

void GIE_voidEnable(void){
	SET_BIT(SREG,SREG_I);
}
void GIE_voidDisable(void){
	CLR_BIT(SREG,SREG_I);
}
