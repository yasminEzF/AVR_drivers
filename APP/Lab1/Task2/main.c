#include <util/delay.h>
#include "../../../MCAL/DIO.h"

int main(void)
{
	/*LED1*/
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin0,DIO_enumOutput);
	/*LED2*/
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin1,DIO_enumOutput);
	/*LED3*/
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin2,DIO_enumOutput);
	/*LED4*/
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin3,DIO_enumOutput);
	
	/*SWITCH*/

	/*SET AS INPUT*/
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin4,DIO_enumInputInternalPU);
	
	u8 counter=0;
	DIO_enumLogicState DIO_enumLogicStateValue;
	while (1)
	{
		DIO_enumReadState(DIO_enumPortA,DIO_enumPin4,&DIO_enumLogicStateValue);	
		if(DIO_enumLogicStateValue==0)
		{
			_delay_ms(500);
			counter++;
			
			if(counter==16)
			{
				counter=0;
			}
			if(GET_BIT(counter,0)==1)
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicHigh);
			}
			else
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicLow);
			}
			if(GET_BIT(counter,1)==1)
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicHigh);
			}
			else
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicLow);
			}
			if(GET_BIT(counter,2)==1)
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin2,DIO_enumLogicHigh);
			}
			else
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin2,DIO_enumLogicLow);
			}
			if(GET_BIT(counter,3)==1)
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin3,DIO_enumLogicHigh);
			}
			else
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin3,DIO_enumLogicLow);
			}
		}
}
}

