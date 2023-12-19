/*
 * task2.c
 *
 * Created: 29-Nov-23 9:08:25 PM
 *  Author: Yasmin
 */ 

#include "bit_math.h"
#include "std_types.h"
#include "dio.h"

int main(void)
{
	/* configure i/p & o/p pins */
	
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin0, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin1, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin2, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin3, DIO_enumOutput);
	
	DIO_enumSetPinConfig(DIO_enumPortC, DIO_enumPin0, DIO_enumInputExternalPD);
	
	/* initially all LEDs off */
	DIO_enumSetPort(DIO_enumPortA,DIO_enumLogicLow);
	
	u8 u8_localVar_SwitchValue = 0;
	u8* u8_localPtr_SwitchPinValue = NULL;
	while(1)
	{
		DIO_enumError_t errorState = DIO_enumReadState(DIO_enumPortC, DIO_enumPin0, u8_localPtr_SwitchPinValue);
		if(errorState == DIO_enumOk) {
			if(!u8_localPtr_SwitchPinValue) {
				if(*u8_localPtr_SwitchPinValue) {
					u8_localVar_SwitchValue++;
					if(u8_localVar_SwitchValue == 16) {
						u8_localVar_SwitchValue = 0;
					}
					u8_localPtr_SwitchPinValue = NULL;
					do {
						errorState = DIO_enumReadState(DIO_enumPortC, DIO_enumPin0, u8_localPtr_SwitchPinValue);
					} while((errorState == DIO_enumOk) && (*u8_localPtr_SwitchPinValue));
				}
			}
		}
		
		if(GET_BIT(u8_localVar_SwitchValue, 0)) {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin0, DIO_enumLogicHigh);
		}
		else {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin0, DIO_enumLogicLow);
		}
		if(GET_BIT(u8_localVar_SwitchValue, 1)) {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin1, DIO_enumLogicHigh);
		}
		else {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin1, DIO_enumLogicLow);
		}
		if(GET_BIT(u8_localVar_SwitchValue, 2)) {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin2, DIO_enumLogicHigh);
		}
		else {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin2, DIO_enumLogicLow);
		}
		if(GET_BIT(u8_localVar_SwitchValue, 3)) {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin3, DIO_enumLogicHigh);
		}
		else {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin3, DIO_enumLogicLow);
		}
	}
}