#include "DIO.h"
#include <util/delay.h>

#define DDRA *((volatile u8*)0x3A)
#define DDRB *((volatile u8*)0x37)
#define DDRC *((volatile u8*)0x34)
#define DDRD *((volatile u8*)0x31)

#define PORTA *((volatile u8*)0x3B)
#define PORTB *((volatile u8*)0x38)
#define PORTC *((volatile u8*)0x35)
#define PORTD *((volatile u8*)0x32)

#define PINA  *((volatile u8*)0x39)
#define PINB  *((volatile u8*)0x36)
#define PINC  *((volatile u8*)0x33)
#define PIND  *((volatile u8*)0x30)

DIO_enumErrorStatus_t DIO_enumSetPortConfig(u8 Copy_enumPortNum, DIO_enumConfig_t Copy_enumConfig )
{
	DIO_enumErrorStatus_t Ret_enumErrorStatus;
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enumErrorStatus=DIO_enumWrongPort;
	}
	else if(Copy_enumConfig>DIO_enumInputExternalPD)
	{
		Ret_enumErrorStatus=DIO_enumWrongConfig;
	}
	else
	{
		Ret_enumErrorStatus=DIO_enumOk;
		switch(Copy_enumPortNum)
		{
				case DIO_enumPortA:
				switch(Copy_enumConfig)
				{
					case DIO_enumOutput:
						DDRA=0xFF;
						break;
					case DIO_enumInputInternalPU:
						DDRA=0x00;
						PORTA=0xFF;
						break;
					case DIO_enumInputExternalPD:
						DDRA=0x00;
						PORTA=0X00;
						break;
				} 
				break;
				
				case DIO_enumPortB:
					switch(Copy_enumConfig)
					{
						case DIO_enumOutput:
						DDRB=0xFF;
						break;
						case DIO_enumInputInternalPU:
						DDRB=0x00;
						PORTB=0xFF;
						break;
						case DIO_enumInputExternalPD:
						DDRB=0x00;
						PORTB=0X00;
						break;
					}
					break;
				
				case DIO_enumPortC:
					switch(Copy_enumConfig)
					{
						case DIO_enumOutput:
						DDRC=0xFF;
						break;
						case DIO_enumInputInternalPU:
						DDRC=0x00;
						PORTC=0xFF;
						break;
						case DIO_enumInputExternalPD:
						DDRC=0x00;
						PORTC=0X00;
						break;
					}
					break;
					
				case DIO_enumPortD:
					switch(Copy_enumConfig)
					{
						case DIO_enumOutput:
						DDRD=0xFF;
						break;
						case DIO_enumInputInternalPU:
						DDRD=0x00;
						PORTD=0xFF;
						break;
						case DIO_enumInputExternalPD:
						DDRD=0x00;
						PORTD=0X00;
						break;
					}
					break;
				
		}
		
	}

return Ret_enumErrorStatus;	
}

DIO_enumErrorStatus_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum, DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumErrorStatus_t RET_enumErrorStatus;
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		RET_enumErrorStatus=DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7)
	{
		RET_enumErrorStatus=DIO_enumWrongPin;
	}
	else if(Copy_enumConfig>DIO_enumInputExternalPD)
	{
		RET_enumErrorStatus=DIO_enumWrongConfig;
	}
	else
	{
		RET_enumErrorStatus=DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutput:
				DDRA|=(1<<Copy_enumPinNum);
				break;
				case DIO_enumInputInternalPU:
				DDRA&=~(1<<Copy_enumPinNum);
				PORTA|=(1<<Copy_enumPinNum);
				break;
				case DIO_enumInputExternalPD:
				DDRA&=~(1<<Copy_enumPinNum);
				PORTA&=~(1<<Copy_enumPinNum);
				break;
			}
			break;
			
			case DIO_enumPortB:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutput:
				DDRB|=(1<<Copy_enumPinNum);
				break;
				case DIO_enumInputInternalPU:
				DDRB&=~(1<<Copy_enumPinNum);
				PORTB|=(1<<Copy_enumPinNum);
				break;
				case DIO_enumInputExternalPD:
				DDRB&=~(1<<Copy_enumPinNum);
				PORTB&=~(1<<Copy_enumPinNum);
				break;
			}
			break;
			
			case DIO_enumPortC:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutput:
				DDRC|=(1<<Copy_enumPinNum);
				break;
				case DIO_enumInputInternalPU:
				DDRC&=~(1<<Copy_enumPinNum);
				PORTC|=(1<<Copy_enumPinNum);
				break;
				case DIO_enumInputExternalPD:
				DDRC&=~(1<<Copy_enumPinNum);
				PORTC&=~(1<<Copy_enumPinNum);
				break;
			}
			break;
		
		
		case DIO_enumPortD:
		switch(Copy_enumConfig)
		{
			case DIO_enumOutput:
			DDRD|=(1<<Copy_enumPinNum);
			break;
			case DIO_enumInputInternalPU:
			DDRD&=~(1<<Copy_enumPinNum);
			PORTD|=(1<<Copy_enumPinNum);
			break;
			case DIO_enumInputExternalPD:
			DDRD&=~(1<<Copy_enumPinNum);
			PORTD&=~(1<<Copy_enumPinNum);
			break;
		}
		break;

	}
	}
	return RET_enumErrorStatus;
	}
	
	DIO_enumErrorStatus_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum, DIO_enumLogicState Copy_enumLogicState)
	{
		DIO_enumErrorStatus_t RET_enumErrorStatus;
		
		if(Copy_enumPortNum>DIO_enumPortD)
		{
				RET_enumErrorStatus=DIO_enumWrongPort;
		}
		else if(Copy_enumLogicState>Copy_enumLogicState)
		{
			RET_enumErrorStatus=DIO_enumWrongLogicState;
		}
		else
		{
			RET_enumErrorStatus=DIO_enumOk;
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
					switch(Copy_enumPortNum)
					{
						case DIO_enumPortA:
						PORTA=0xFF;
						break;
						case DIO_enumPortB:
						PORTB=0xFF;
						break;
						case DIO_enumPortC:
						PORTC=0xFF;
						break;
						case DIO_enumPortD:
						PORTD=0xFF;
						break;
					}
					break;
					
					case DIO_enumLogicLow:
					switch(Copy_enumPortNum)
					{
						case DIO_enumPortA:
						PORTA=0x00;
						break;
						case DIO_enumPortB:
						PORTB=0x00;
						break;
						case DIO_enumPortC:
						PORTC=0x00;
						break;
						case DIO_enumPortD:
						PORTD=0x00;
						break;
					}
					break;
					
				}
		}
		return RET_enumErrorStatus;	
	}
	
	DIO_enumErrorStatus_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum, DIO_enumLogicState Copy_enumLogicState)
	{
		DIO_enumErrorStatus_t RET_enumErrorStatus;
		if(Copy_enumPortNum>DIO_enumPortD)
		{
			RET_enumErrorStatus= DIO_enumWrongPort;
		}
		else if(Copy_enumPinNum>DIO_enumPin7)
		{
			RET_enumErrorStatus= DIO_enumWrongPin;
		}
		else if(Copy_enumLogicState>DIO_enumLogicHigh)
		{
			RET_enumErrorStatus=DIO_enumWrongLogicState;
		}
		else
		{
			RET_enumErrorStatus=DIO_enumOk;
			switch(Copy_enumLogicState)
			{
				case DIO_enumLogicHigh:
				switch(Copy_enumPortNum)
				{
					case DIO_enumPortA:
					PORTA|=(1<<Copy_enumPinNum);
					break;
					case DIO_enumPortB:
					PORTB|=(1<<Copy_enumPinNum);
					break;
					case DIO_enumPortC:
					PORTC|=(1<<Copy_enumPinNum);
					break;
					case DIO_enumPortD:
					PORTD|=(1<<Copy_enumPinNum);
					break;
				}
				break;
				
				case DIO_enumLogicLow:
				switch(Copy_enumPortNum)
				{
					case DIO_enumPortA:
					PORTA&=~(1<<Copy_enumPinNum);
					break;
					case DIO_enumPortB:
					PORTB&=~(1<<Copy_enumPinNum);
					break;
					case DIO_enumPortC:
					PORTC&=~(1<<Copy_enumPinNum);
					break;
					case DIO_enumPortD:
					PORTD&=~(1<<Copy_enumPinNum);
					break;
				}
				break;
			}
		}
			return RET_enumErrorStatus;

	}

DIO_enumErrorStatus_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum, DIO_enumLogicState* Add_PenumPinValue)
{
	DIO_enumErrorStatus_t RET_enumErrorStatus;
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		RET_enumErrorStatus=DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7)
	{
		RET_enumErrorStatus=DIO_enumWrongPin;
	}
	else if(Add_PenumPinValue==NULL)
	{
		RET_enumErrorStatus=DIO_enumNullPointer;
	}
	else
	{
		RET_enumErrorStatus=DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			*Add_PenumPinValue=GET_BIT(PINA,Copy_enumPinNum);
			break; 
			case DIO_enumPortB:
			*Add_PenumPinValue=GET_BIT(PINB,Copy_enumPinNum);
			break;
			case DIO_enumPortC:
			*Add_PenumPinValue=GET_BIT(PINC,Copy_enumPinNum);
			break;
			case DIO_enumPortD:
			*Add_PenumPinValue=GET_BIT(PIND,Copy_enumPinNum);
			break;
		}
	}
	return RET_enumErrorStatus;
}	

		
