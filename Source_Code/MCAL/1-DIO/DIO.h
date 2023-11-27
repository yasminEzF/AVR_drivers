/*
 * DIO.h
 *
 *  Created on: Nov 25, 2023
 *      Author: DELL
 */

#ifndef DIO_H_
#define DIO_H_

#define PORTA         *((volatile u8 * )0x3b)
#define DDRA          *((volatile u8 * )0x3a)
#define PINA          *((volatile u8 * )0x39)

#define PORTB         *((volatile u8 * )0x38)
#define DDRB          *((volatile u8 * )0x37)
#define PINB          *((volatile u8 * )0x36)

#define PORTC         *((volatile u8 * )0x35)
#define DDRC          *((volatile u8 * )0x34)
#define PINC          *((volatile u8 * )0x33)

#define PORTD         *((volatile u8 * )0x32)
#define DDRD          *((volatile u8 * )0x31)
#define PIND          *((volatile u8 * )0x30)

#define DIO_u8PORTA            0
#define DIO_u8PORTB            1
#define DIO_u8PORTC            2
#define DIO_u8PORTD            3

#define DIO_u8PIN0             0
#define DIO_u8PIN1             1
#define DIO_u8PIN2             2
#define DIO_u8PIN3             3
#define DIO_u8PIN4             4
#define DIO_u8PIN5             5
#define DIO_u8PIN6             6
#define DIO_u8PIN7             7

#define DIO_u8PIN_INPUT        0
#define DIO_u8PIN_OUTPUT       1

#define DIO_u8PIN_LOW          0
#define DIO_u8PIN_HIGH         1

#define DIO_u8PORT_INPUT       0
#define DIO_u8PORT_OUTPUT      0xff

#define DIO_u8PORT_LOW         0
#define DIO_u8PORT_HIGH        0xff

#define NULL                   0

u8 DIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinDirection);
u8 DIO_u8SetPortDirection(u8 Copy_u8Port  , u8 Copy_u8PortDirection);

u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinValue);
u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8PortValue);

u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 * Copy_pu8PinValue);




#endif /* DIO_H_ */
