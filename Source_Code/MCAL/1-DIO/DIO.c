/*
 * DIO.C
 *
 *  Created on: Nov 25, 2023
 *      Author: DELL
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/Bit_Math.h"
#include"DIO.h"

u8 DIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinDirection)
{
	u8 Local_u8ErrorState=0;
	if(Copy_u8Pin<=DIO_u8PIN7)
	{
		if(Copy_u8PinDirection == DIO_u8PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA : CLR_BIT(DDRA,Copy_u8Pin); break;
			case DIO_u8PORTB : CLR_BIT(DDRB,Copy_u8Pin); break;
			case DIO_u8PORTC : CLR_BIT(DDRC,Copy_u8Pin); break;
			case DIO_u8PORTD : CLR_BIT(DDRD,Copy_u8Pin); break;
			default : Local_u8ErrorState=1 ;             break;

			}
		}
		else if (Copy_u8PinDirection== DIO_u8PIN_OUTPUT)
		{
			switch (Copy_u8Port)
			{
			  case DIO_u8PORTA : SET_BIT(DDRA,Copy_u8Pin); break;
			  case DIO_u8PORTB : SET_BIT(DDRB,Copy_u8Pin); break;
			  case DIO_u8PORTC : SET_BIT(DDRC,Copy_u8Pin); break;
			  case DIO_u8PORTD : SET_BIT(DDRD,Copy_u8Pin); break;
			  default : Local_u8ErrorState=1 ;             break;
			}


		}
		else
			Local_u8ErrorState=1 ;

	}
	else
		Local_u8ErrorState=1 ;

	return Local_u8ErrorState;


}


u8 DIO_u8SetPortDirection(u8 Copy_u8Port  , u8 Copy_u8PortDirection)
{
	u8 Local_u8ErrorState=0;

		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : DDRA=Copy_u8PortDirection; break;
		case DIO_u8PORTB : DDRB=Copy_u8PortDirection; break;
		case DIO_u8PORTC : DDRC=Copy_u8PortDirection; break;
		case DIO_u8PORTD : DDRD=Copy_u8PortDirection; break;
		default : Local_u8ErrorState=1;               break;

		}
		return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState=0;
	if(Copy_u8Pin<=DIO_u8PIN7)
	{
		if(Copy_u8PinValue==DIO_u8PIN_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8Pin);  break;
			case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8Pin);  break;
			case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8Pin);  break;
			case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8Pin);  break;
			default : Local_u8ErrorState=1;                break;

			}

		}
		else if (Copy_u8PinValue==DIO_u8PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8Pin);  break;
			case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin);  break;
			case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin);  break;
			case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin);  break;
			default : Local_u8ErrorState=1;

			}
		}
		else
			Local_u8ErrorState=1;


	}
	return Local_u8ErrorState;

}
u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8PortValue)
{
	u8 Local_u8ErrorState=0;
	if(Copy_u8PortValue<=DIO_u8PORT_HIGH)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : PORTA=Copy_u8PortValue;     break;
		case DIO_u8PORTB : PORTB=Copy_u8PortValue;     break;
		case DIO_u8PORTC : PORTC=Copy_u8PortValue;     break;
		case DIO_u8PORTD : PORTD=Copy_u8PortValue;     break;
		default :          Local_u8ErrorState=1;       break;
		}
	}
	else
		Local_u8ErrorState=1;

	return Local_u8ErrorState;

}

u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 * Copy_pu8PinValue)
{
	u8 Local_u8ErrorState=0;
	if(Copy_pu8PinValue!=NULL && Copy_u8Pin<=DIO_u8PIN7)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : * Copy_pu8PinValue = GET_BIT(PINA,Copy_u8Pin);     break;
		case DIO_u8PORTB : * Copy_pu8PinValue = GET_BIT(PINB,Copy_u8Pin);     break;
		case DIO_u8PORTC : * Copy_pu8PinValue = GET_BIT(PINC,Copy_u8Pin);     break;
		case DIO_u8PORTD : * Copy_pu8PinValue = GET_BIT(PIND,Copy_u8Pin);     break;
		default : Local_u8ErrorState=1;                  break;

		}
	}
	else
		Local_u8ErrorState=1;

	return Local_u8ErrorState;
}












