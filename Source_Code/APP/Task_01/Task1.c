#include "C:\Users\omar\Documents\Atmel Studio\7.0\XC8Application1\DIO.h"


void delay_ms(unsigned int milliseconds) {

	for (unsigned int i = 0; i < milliseconds; ++i) {
		for (unsigned int j = 0; j < 100; ++j) {
			asm volatile("nop"); 
		}
	}
}

int main(void)
{
	
	DIO_enumError_t Error_status;
	
	Error_status = DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin0,DIO_enumOutput);
	while(Error_status != DIO_enumOk);
	Error_status = DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin1,DIO_enumOutput);
	while(Error_status != DIO_enumOk);
	
	while(1)
	{
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicLow);
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicHigh);
		delay_ms(1000);
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicLow);
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicHigh);
		delay_ms(1000);
	}
	return 0;
}