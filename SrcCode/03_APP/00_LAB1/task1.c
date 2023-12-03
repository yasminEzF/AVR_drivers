/*
 * main.c
 *
 * Created: 29-Nov-23 8:33:17 PM
 *  Author: Yasmin
 */ 

#include "dio.h"
#define F_CPU 1000000

int main(void)
{
	/* configure o/p pins */
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin0, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin1, DIO_enumOutput);
	
	while(1)
	{
		/* PA0 off, PA1 on */
		DIO_enumSetPin(DIO_enumPortA, DIO_enumPin0, DIO_enumLogicLow);
		DIO_enumSetPin(DIO_enumPortA, DIO_enumPin1, DIO_enumLogicHigh);
		 
		DIO_DelayMs(500);
		
		/* PA0 on, PA1 off */
		DIO_enumSetPin(DIO_enumPortA, DIO_enumPin1, DIO_enumLogicLow);
		DIO_enumSetPin(DIO_enumPortA, DIO_enumPin0, DIO_enumLogicHigh);
		
		DIO_DelayMs(500);
	}
}