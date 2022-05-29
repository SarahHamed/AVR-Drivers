#include "../../lib/BIT_MATH.h"
#include  "../Global_Interrupt/GIE_register.h"
#include "EXT_register.h"
#include "../../lib/STD_TYPES.h"

void EXTI0_vidEnable(void)
{
	/*set sense control*/
	BIT_SET(MCUCR,MCUCR_ISC01);
	BIT_CLEAR(MCUCR,MCUCR_ISC00);

	/*enable interrupt*/
	BIT_SET(GICR,GICR_INT0);
	
}
