#ifndef DIO_H_
#define DIO_H_

#define SET_BIT(REG,BIT) REG |= (1<<BIT) 
#define CLR_BIT(REG,BIT) REG &= ~(1<<BIT)
#define TGL_BIT(REG,BIT) REG ^= (1<<BIT)
#define GET_BIT(REG,BIT) (REG &= (1 << BIT))

#define DDRA *((volatile char*)0x3A)
#define PORTA *((volatile char*)0x3B)
#define PINA *((volatile char*)0x39)

#define DDRB *((volatile char*)0x37)
#define PORTB *((volatile char*)0x38)
#define PINB *((volatile char*)0x36)

#define DDRC *((volatile char*)0x34)
#define PORTC *((volatile char*)0x35)
#define PINC *((volatile char*)0x33)

#define DDRD *((volatile char*)0x31)
#define PORTD *((volatile char*)0x32)
#define PIND *((volatile char*)0x30)

/**
 *@brief : The ports Type of the AVR Atmega32                            
 */
typedef enum
{  
	DIO_enumPortA,
	DIO_enumPortB,
	DIO_enumPortC,
	DIO_enumPortD
}DIO_enumPorts_t;

/**
 *@brief : The Error List Type                                           
 */
typedef enum 
{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	DIO_enumOk,             
	/**
	 *@brief : NULL Pointer is passed.
	 */
	DIO_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	DIO_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	DIO_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	DIO_enumWrongConfig, 
	/**
	 *@brief : Unspecified Error .
	 */     
	DIO_enumNOK   
	
}DIO_enumError_t;
	
/**
 *@brief : The Configuration Type of Pins to be Input or Output !        
 */
typedef enum
{	
	/**
	 *@brief : Select Pin Configuration to be Output .
	 */
	DIO_enumOutput,
	/**
	 *@brief : Select Pin Configuration to be Input Internal PullUp .
	 */             
	DIO_enumInputInternalPU,
	/**
	 *@brief : Select Pin Configuration to be Input External PullDown
	 */    
	DIO_enumInputExternalPD   
}DIO_enumConfig_t;
	
/**
 *@brief :  Logic State Type : HIGH (5V) or LOW(0V )                     
 */
typedef enum
{   
	DIO_enumLogicLow,
	DIO_enumLogicHigh
}DIO_enumLogicState_t;

/**
 *@brief :  Pins Type                                                    
 */
typedef enum
{
	DIO_enumPin0,
	DIO_enumPin1,
	DIO_enumPin2,
	DIO_enumPin3,
	DIO_enumPin4,
	DIO_enumPin5,
	DIO_enumPin6,
	DIO_enumPin7
}DIO_enumPins_t;


/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig);

/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig);

/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState);

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState); 

/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue);

#endif /* DIO_H_ */