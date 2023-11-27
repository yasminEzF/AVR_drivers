/*
 * main.c
 *
 *  Created on: Nov 26, 2023
 *      Author: Mayada
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/Bit_Math.h"
#include"../../MCAL/1-DIO/DIO.h"

#include<util/delay.h>

int main (void)
{
	while(1)
	{
		/**TASK1**/
		/**set pin A0 as output for first led**/
		DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
		/**set pin A1 as output for second led**/
		DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_OUTPUT);

		/**set pin A1 as low**/
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_LOW);
		/**set pin A0 as high**/
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);

		_delay_ms(1000);
		/**set pin A0 as low**/
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		/**set pin A1 as high**/
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);

		_delay_ms(1000);


	




	}
	return 0;
}

