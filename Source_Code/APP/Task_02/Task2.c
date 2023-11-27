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
		


		/**set portB as output for 4 led**/
		DIO_u8SetPortDirection(DIO_u8PORTB,DIO_u8PORT_OUTPUT);
		/**set pin A0 as input for switch**/
	    DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_INPUT);
	    /**activate pullup for pin A0**/
	    DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
	    /**to store value of pin A0**/
		u8 Local_u8Counter=0;
		u8 Local_u8PinValue;
		while(Local_u8Counter<16)
		{
			/**to read value of pin A0**/
			DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN0,&Local_u8PinValue);
			if(!Local_u8PinValue)
			{
				Local_u8Counter++;
			}
			_delay_ms(1000);
			/**set portB as value of Local_u8Counter for 4 led**/
			DIO_u8SetPortValue(DIO_u8PORTB,Local_u8Counter);
			_delay_ms(1000);


		}




	}
	return 0;
}

