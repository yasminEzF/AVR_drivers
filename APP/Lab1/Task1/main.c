#include "../../../MCAL/DIO.h"
#include <util/delay.h>

int main(void)
{
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin0,DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin1,DIO_enumOutput);
	
	
    while (1) 
    {
			//LED ON/OFF
			DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicHigh);
			DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicLow);
			_delay_ms(1000);
			DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicLow);
			DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicHigh);
			_delay_ms(1000);
    }
}

