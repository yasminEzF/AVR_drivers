#include <stddef.h>
#include "C:\Users\omar\Documents\Atmel Studio\7.0\XC8Application1\DIO.h"


DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumNOK;
	if(Copy_enumPortNum > DIO_enumPortD)
	{
		return Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	
	else if (Copy_enumPinNum > DIO_enumPin7)
	{
		return Ret_enumErrorStatus = DIO_enumWrongPin;
	}
	
	else if (Add_Pu8PinValue == NULL)
	{
		return Ret_enumErrorStatus = DIO_enumNullPointer;
	}
	
	else
	{
		Ret_enumErrorStatus = DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			if(GET_BIT(DDRA,Copy_enumPinNum) == 1)   /*in case the user attempts to read from a output pin by mistake*/
			{
				return Ret_enumErrorStatus = DIO_enumWrongConfig;
			}
			if(GET_BIT(PINA,Copy_enumPinNum))
			{
				*Add_Pu8PinValue = DIO_enumLogicHigh;
			}
			else
			{
				*Add_Pu8PinValue = DIO_enumLogicLow;
			}
			break;
			
			case DIO_enumPortB:
			if(GET_BIT(DDRB,Copy_enumPinNum) == 1)   /*in case the user attempts to read from a output pin by mistake*/
			{
				return Ret_enumErrorStatus = DIO_enumWrongConfig;
			}
			if(GET_BIT(PINB,Copy_enumPinNum))
			{
				*Add_Pu8PinValue = DIO_enumLogicHigh;
			}
			else
			{
				*Add_Pu8PinValue = DIO_enumLogicLow;
			}
			break;
			
			case DIO_enumPortC:
			if(GET_BIT(DDRC,Copy_enumPinNum) == 1)   /*in case the user attempts to read from a output pin by mistake*/
			{
				return Ret_enumErrorStatus = DIO_enumWrongConfig;
			}
			if(GET_BIT(PINC,Copy_enumPinNum))
			{
				*Add_Pu8PinValue = DIO_enumLogicHigh;
			}
			else
			{
				*Add_Pu8PinValue = DIO_enumLogicLow;
			}
			break;
			
			case DIO_enumPortD:
			if(GET_BIT(DDRD,Copy_enumPinNum) == 1)   /*in case the user attempts to read from a output pin by mistake*/
			{
				return Ret_enumErrorStatus = DIO_enumWrongConfig;
			}
			if(GET_BIT(PIND,Copy_enumPinNum))
			{
				*Add_Pu8PinValue = DIO_enumLogicHigh;
			}
			else
			{
				*Add_Pu8PinValue = DIO_enumLogicLow;
			}
			break;
		}
	}
	return Ret_enumErrorStatus;
}





DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumNOK;
	if(Copy_enumPortNum > DIO_enumPortD)
	{
		return Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	
	else if (Copy_enumLogicState > DIO_enumLogicHigh)
	{
		return Ret_enumErrorStatus = DIO_enumWrongConfig;
	}
	
	else if (DDRA > 0x00)				/*in case the user attempts to write on a input pin by mistake*/
	{
		return Ret_enumErrorStatus = DIO_enumWrongConfig;
	}
	
	else if (DDRB > 0x00)				/*in case the user attempts to write on a input pin by mistake*/
	{
		return Ret_enumErrorStatus = DIO_enumWrongConfig;
	}
	
	else if (DDRC > 0x00)				/*in case the user attempts to write on a input pin by mistake*/
	{
		return Ret_enumErrorStatus = DIO_enumWrongConfig;
	}
	
	else if (DDRD > 0x00)				/*in case the user attempts to write on a input pin by mistake*/
	{
		return Ret_enumErrorStatus = DIO_enumWrongConfig;
	}
	
	else
	{
		Ret_enumErrorStatus = DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			if (Copy_enumLogicState == DIO_enumLogicHigh)
			{
				PORTA = 0xff;
			}
			
			else
			{
				PORTA = 0x00;
			}
			break;
			
			case DIO_enumPortB:
			if (Copy_enumLogicState == DIO_enumLogicHigh)
			{
				PORTB = 0xff;
			}
			
			else
			{
				PORTB = 0x00;
			}
			break;
			
			case DIO_enumPortC:
			if (Copy_enumLogicState == DIO_enumLogicHigh)
			{
				PORTC = 0xff;
			}
			
			else
			{
				PORTC = 0x00;
			}
			break;
			
			case DIO_enumPortD:
			if (Copy_enumLogicState == DIO_enumLogicHigh)
			{
				PORTD = 0xff;
			}
			
			else
			{
				PORTD = 0x00;
			}
			break;
		}
	}
	return Ret_enumErrorStatus;
}




DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumNOK;
	if(Copy_enumPortNum > DIO_enumPortD)
	{
		return Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	
	else if (Copy_enumPinNum > DIO_enumPin7)
	{
		return Ret_enumErrorStatus = DIO_enumWrongPin;
	}
	
	else if (Copy_enumLogicState > DIO_enumLogicHigh)
	{
		return Ret_enumErrorStatus = DIO_enumWrongConfig;
	}
	
	else
	{
		Ret_enumErrorStatus = DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			
//			if(GET_BIT(DDRA,Copy_enumPinNum) == 0)   /*in case the user attempts to write on a input pin by mistake*/
//			{
//				return Ret_enumErrorStatus = DIO_enumWrongConfig;
//			} 
			
			else if (Copy_enumLogicState == DIO_enumLogicHigh)
			{
				SET_BIT(PORTA,Copy_enumPinNum);
			}
			else
			{
				CLR_BIT(PORTA,Copy_enumPinNum);
			}
			break;
			
			case DIO_enumPortB:
			
			if(GET_BIT(DDRB,Copy_enumPinNum) == 0)   /*in case the user attempts to write on a input pin by mistake*/
			{
				return Ret_enumErrorStatus = DIO_enumWrongConfig;
			}
			
			else if (Copy_enumLogicState == DIO_enumLogicHigh)
			{
				SET_BIT(PORTB,Copy_enumPinNum);
			}
			else
			{
				CLR_BIT(PORTB,Copy_enumPinNum);
			}
			break;
			
			case DIO_enumPortC:
			
			if(GET_BIT(DDRC,Copy_enumPinNum) == 0)   /*in case the user attempts to write on a input pin by mistake*/
			{
				return Ret_enumErrorStatus = DIO_enumWrongConfig;
			}
			
			else if (Copy_enumLogicState == DIO_enumLogicHigh)
			{
				SET_BIT(PORTC,Copy_enumPinNum);
			}
			else
			{
				CLR_BIT(PORTC,Copy_enumPinNum);
			}
			break;
			
			case DIO_enumPortD:
			
			if(GET_BIT(DDRD,Copy_enumPinNum) == 0)   /*in case the user attempts to write on a input pin by mistake*/
			{
				return Ret_enumErrorStatus = DIO_enumWrongConfig;
			}
			
			else if (Copy_enumLogicState == DIO_enumLogicHigh)
			{
				SET_BIT(PORTD,Copy_enumPinNum);
			}
			else
			{
				CLR_BIT(PORTD,Copy_enumPinNum);
			}
			break;
		}
	}
	return Ret_enumErrorStatus;
}



DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumNOK;
	if(Copy_enumPortNum > DIO_enumPortD)
	{
		return Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	
	else if (Copy_enumConfig > DIO_enumInputExternalPD)
	{
		return Ret_enumErrorStatus = DIO_enumWrongConfig;
	}
	
	else if (Copy_enumPinNum > DIO_enumPin7)
	{
		return Ret_enumErrorStatus = DIO_enumWrongPin;
	}
	
	else
	{
		Ret_enumErrorStatus = DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			
			switch(Copy_enumConfig)
			{
				case DIO_enumOutput:
				SET_BIT(DDRA,Copy_enumPinNum);
				break;
				
				case DIO_enumInputInternalPU:
				//CLR_BIT(DDRA,Copy_enumPinNum);
				//SET_BIT(PORTA,Copy_enumPinNum);
				DDRA = 0x0F;
				PORTA = 0x10;
				break;
				
				case DIO_enumInputExternalPD:
				CLR_BIT(DDRA,Copy_enumPinNum);
				CLR_BIT(PORTA,Copy_enumPinNum);
				break;
			}
			
			break;
			
			
			case DIO_enumPortB:
			
			switch(Copy_enumConfig)
			{
				case DIO_enumOutput:
				SET_BIT(DDRB,Copy_enumPinNum);
				break;
				
				case DIO_enumInputInternalPU:
				CLR_BIT(DDRB,Copy_enumPinNum);
				SET_BIT(PORTB,Copy_enumPinNum);
				break;
				
				case DIO_enumInputExternalPD:
				CLR_BIT(DDRB,Copy_enumPinNum);
				CLR_BIT(PORTB,Copy_enumPinNum);
				break;
			}
			
			break;
			
			
			case DIO_enumPortC:
			
			switch(Copy_enumConfig)
			{
				case DIO_enumOutput:
				SET_BIT(DDRC,Copy_enumPinNum);
				break;
				
				case DIO_enumInputInternalPU:
				CLR_BIT(DDRC,Copy_enumPinNum);
				SET_BIT(PORTC,Copy_enumPinNum);
				break;
				
				case DIO_enumInputExternalPD:
				CLR_BIT(DDRC,Copy_enumPinNum);
				CLR_BIT(PORTC,Copy_enumPinNum);
				break;
			}
			
			break;
			
			
			case DIO_enumPortD:
			
			switch(Copy_enumConfig)
			{
				case DIO_enumOutput:
				SET_BIT(DDRD,Copy_enumPinNum);
				break;
				
				case DIO_enumInputInternalPU:
				CLR_BIT(DDRD,Copy_enumPinNum);
				SET_BIT(PORTD,Copy_enumPinNum);
				break;
				
				case DIO_enumInputExternalPD:
				CLR_BIT(DDRD,Copy_enumPinNum);
				CLR_BIT(PORTD,Copy_enumPinNum);
				break;
			}
			
			break;
		}
	}
	return Ret_enumErrorStatus;
}






DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumNOK;
	
	if(Copy_enumPortNum > DIO_enumPortD)
	{
		return Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	
	else if (Copy_enumConfig > DIO_enumInputExternalPD)
	{
		return Ret_enumErrorStatus = DIO_enumWrongConfig;
	}
	
	else
	{
		Ret_enumErrorStatus = DIO_enumOk;
		
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutput:
				DDRA = 0xff;
				break;
				
				case DIO_enumInputInternalPU:
				DDRA = 0x00;
				PORTA = 0xff;
				break;
				
				case DIO_enumInputExternalPD:
				DDRA = 0x00;
				PORTA = 0x00;
				break;
			}
			
			case DIO_enumPortB:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutput:
				DDRB = 0xff;
				break;
				
				case DIO_enumInputInternalPU:
				DDRB = 0x00;
				PORTB = 0xff;
				break;
				
				case DIO_enumInputExternalPD:
				DDRB = 0x00;
				PORTB = 0x00;
				break;
			}
			
			case DIO_enumPortC:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutput:
				DDRC = 0xff;
				break;
				
				case DIO_enumInputInternalPU:
				DDRC	 = 0x00;
				PORTC = 0xff;
				break;
				
				case DIO_enumInputExternalPD:
				DDRC = 0x00;
				PORTC = 0x00;
				break;
			}
			
			case DIO_enumPortD:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutput:
				DDRD = 0xff;
				break;
				
				case DIO_enumInputInternalPU:
				DDRD = 0x00;
				PORTD = 0xff;
				break;
				
				case DIO_enumInputExternalPD:
				DDRD = 0x00;
				PORTD = 0x00;
				break;
			}
		}
	}
	return Ret_enumErrorStatus;
}






