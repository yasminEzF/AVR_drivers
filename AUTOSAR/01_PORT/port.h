#ifndef PORT_H_
#define PORT_H_

#include "std_types.h"

#define PortSetPinDirectionApi      TRUE

#define TRUE    1
#define FALSE   0

/*****************************************************************************/
/*                             development errors                            */
/*****************************************************************************/
#define PORT_E_PARAM_PIN                0x0A
#define PORT_E_DIRECTION_UNCHANGEABLE   0x0B
#define PORT_E_INIT_FAILED              0x0C
#define PORT_E_PARAM_INVALID_MODE       0x0D
#define PORT_E_MODE_UNCHANGEABLE        0x0E
#define PORT_E_UNINIT                   0x0F
#define PORT_E_PARAM_POINTER            0x10

/*****************************************************************************/
/*                               type definitions                            */
/*****************************************************************************/

/**
 * @brief As several port pin modes shall be configurable on one pin
*/
typedef uint8 Port_PinModeType;
#define PIN_MODE_DIO     0

/**
 * @brief Possible directions of a port pin
*/
typedef enum {
    /**
     * Sets port pin as input 
    */
    PORT_PIN_IN,
    /**
     * Sets port pin as output
     */   
    PORT_PIN_OUT
} Port_PinDirectionType;

/**
 * @brief Type of the external data structure containing the initialization data for port module
*/
typedef struct {
    /* ADC, SPI, DIO */
    Port_PinModeType pinMode;
    /* input/output */
    Port_PinDirectionType pinDirection;
    /* Pin level initial value */
    uint8 pinLevelInit;
    /* Pin direction changeable during runtime */
    uint8 pinDirectionChange;
    /* Port mode changeable during runtime */
    uint8 pinModeChange;

    /* Activation of internal pull-ups */
    uint8 pinInternalPullUpActive;
    
} Port_ConfigType;

/**
 * @brief Data type for the symbolic name of a port pin ( 0 ~ 31 )
*/
typedef uint8 Port_PinType;
#define PORT_A_PIN_0        0
#define PORT_A_PIN_1        1
#define PORT_A_PIN_2        2
#define PORT_A_PIN_3        3
#define PORT_A_PIN_4        4
#define PORT_A_PIN_5        5
#define PORT_A_PIN_6        6
#define PORT_A_PIN_7        7

#define PORT_B_PIN_0        8
#define PORT_B_PIN_1        9
#define PORT_B_PIN_2        10
#define PORT_B_PIN_3        11
#define PORT_B_PIN_4        12
#define PORT_B_PIN_5        13
#define PORT_B_PIN_6        14
#define PORT_B_PIN_7        15

#define PORT_C_PIN_0        16
#define PORT_C_PIN_1        17
#define PORT_C_PIN_2        18
#define PORT_C_PIN_3        19
#define PORT_C_PIN_4        20
#define PORT_C_PIN_5        21
#define PORT_C_PIN_6        22
#define PORT_C_PIN_7        23

#define PORT_D_PIN_0        24
#define PORT_D_PIN_1        25
#define PORT_D_PIN_2        26
#define PORT_D_PIN_3        27
#define PORT_D_PIN_4        28
#define PORT_D_PIN_5        29
#define PORT_D_PIN_6        30
#define PORT_D_PIN_7        31


#define PORT_A  0x00
#define PORT_B  0x01
#define PORT_C  0x02
#define PORT_D  0x03

/*****************************************************************************/
/*                                  functions                                */
/*****************************************************************************/

/**
 * @brief  Initializes ALL ports and port pins with the configuration set pointed to by the parameter
 * @param  Port_ConfigType* Pointer to configuration set
 * @return none
*/
void Port_Init( const Port_ConfigType* ConfigPtr );

#if (PortSetPinDirectionApi == TRUE)
/**
 * @brief  Sets the port pin direction if configured as changeable
 * @param  Port_PinType Port Pin ID number
 * @param  Port_PinDirectionType Port Pin Direction
 * @return none
*/
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif
/**
 * @brief  Refreshes unchangeable port direction
 * @param  none
 * @return none 
*/
void Port_RefreshPortDirection( void );

/**
 * @brief  
 * @param  Port_PinType
 * @param  Port_PinModeType
 * @return 
*/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );


#endif /* PORT_H_ */

/**
 * The PORT Driver module shall configure all ports and port pins
that are not used (neither as GPIO nor special purpose IO) to be set to a defined state
by the PORT Driver module configuration
*/
/**
 * For refreshing of the port on the microcontroller, the PORT driver
shall allow the user to refresh the direction of those port pins whose direction is set by
configuration and cannot be changed dynamically
*/

