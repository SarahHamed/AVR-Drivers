#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../../MCAL/01-DIO/DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"




u8 KPD_u8GetPressedKey(void){

	u8 Local_u8PresessedKey=KEY_NOT_PRESSED;
	u8 state=0;
	u8 user_array[][4]=USER_NUMBERS;
	u8 keypad_u8columnArray [] ={ KPD_C0_PIN, KPD_C1_PIN, KPD_C2_PIN, KPD_C3_PIN};
	u8 keypad_u8RowArray []={KPD_R0_PIN, KPD_R1_PIN,KPD_R2_PIN,KPD_R3_PIN};

	for(u8 col=0; col<4; col++){
		DIO_voidSetPinValue(KPD_PORT,keypad_u8columnArray[col],DIO_Low);
		for(u8 row=0;row<4;row++){
		state=DIO_enuGetPinValue(KPD_PORT,keypad_u8RowArray[row] );   //call by reference
		if(state==0)
		{
			Local_u8PresessedKey=user_array[col][row];
			while(!state)
			{
				state=DIO_enuGetPinValue(KPD_PORT,keypad_u8RowArray[row]);   //call by reference
			}
		}
		}
		DIO_voidSetPinValue(KPD_PORT,keypad_u8columnArray[col],DIO_High);
	}

	return Local_u8PresessedKey;
}
