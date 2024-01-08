#include "std_types.h"
#include "bit_math.h"
#include "AVR_reg.h"
#include "port.h"

#define NUM_PINS    32
uint8 initCalled_flag = 0;
Port_ConfigType ConfigArr[NUM_PINS];
Port_ConfigType ConfigDefault = {
    .pinMode = PIN_MODE_DIO,
    .pinDirection = PORT_PIN_OUT,
    .pinLevelInit = 0,
    .pinDirectionChange = TRUE,
    .pinModeChange = TRUE,
    .pinInternalPullUpActive = FALSE
};
/**
 * @brief  Initializes ALL ports and port pins with the configuration set pointed to by the parameter
 * @param  ConfigPtr* Pointer to configuration set
 * @return none
*/
void Port_Init (const Port_ConfigType* ConfigPtr) {
    if(ConfigPtr != NULL) {
        volatile uint8 *DDR_regPtr = NULL, *PORT_regPtr = NULL;
        
        uint8 localPortID;
        Port_PinType localPinID;
        
        for(Port_PinType pin = PORT_A_PIN_0; pin <= PORT_D_PIN_7; pin++) {
            DDR_regPtr = NULL;
            PORT_regPtr = NULL;
            
            localPortID = pin / 8;
            localPinID = pin % 8;

            if(ConfigPtr[pin].pinDirectionChange == TRUE) {
                ConfigArr[pin].pinDirectionChange = TRUE;
            }
            else {
                ConfigArr[pin].pinDirectionChange = FALSE;
            }

            if(ConfigPtr[pin].pinModeChange == TRUE) {
                ConfigArr[pin].pinModeChange = TRUE;
            }
            else {
                ConfigArr[pin].pinModeChange = FALSE;
            }
        
            switch(ConfigPtr[pin].pinMode) {
                case PIN_MODE_DIO:
                    switch(localPortID) {
                        case PORT_A:
                            DDR_regPtr = DDRA_REG;
                            PORT_regPtr = PORTA_REG;
                        break;
                        case PORT_B:
                            DDR_regPtr = DDRB_REG;
                            PORT_regPtr = PORTB_REG;
                        break;
                        case PORT_C:
                            DDR_regPtr = DDRC_REG;
                            PORT_regPtr = PORTC_REG;
                        break;
                        case PORT_D:
                            DDR_regPtr = DDRD_REG;
                            PORT_regPtr = PORTD_REG;
                        break;
                    }
                    if((DDR_regPtr != NULL) && (PORT_regPtr != NULL)) {
                        switch(ConfigPtr[pin].pinDirection) {
                            case PORT_PIN_IN:
                                ConfigArr[pin].pinDirection = PORT_PIN_IN;
                                CLR_BIT(*DDR_regPtr,(uint8)localPinID);
                                switch(ConfigPtr[pin].pinInternalPullUpActive) {
                                    case 0:
                                        ConfigArr[pin].pinInternalPullUpActive = 0;
                                        CLR_BIT(*PORT_regPtr,(uint8)localPinID);
                                    break;
                                    case 1:
                                        ConfigArr[pin].pinInternalPullUpActive = 1;
                                        SET_BIT(*PORT_regPtr,(uint8)localPinID);
                                    break;
                                }
                            break;
                            case PORT_PIN_OUT:
                                ConfigArr[pin].pinDirection = PORT_PIN_OUT;
                                SET_BIT(*DDR_regPtr,(uint8)localPinID);
                                switch(ConfigPtr[pin].pinLevelInit) {
                                    case 0:
                                        ConfigArr[pin].pinLevelInit = 0;
                                        CLR_BIT(*PORT_regPtr,(uint8)localPinID);
                                    break;
                                    case 1:
                                        ConfigArr[pin].pinLevelInit = 1;
                                        SET_BIT(*PORT_regPtr,(uint8)localPinID);
                                    break;
                                }
                            break;
                        }
                    }
                break;
            }
        }
        initCalled_flag = 1;
    }
}

#if (PortSetPinDirectionApi == TRUE)
/**
 * @brief  
 * @param  Port_PinType
 * @param  Port_PinDirectionType
 * @return none
*/
void Port_SetPinDirection (Port_PinType Pin, Port_PinDirectionType Direction) {
    if(initCalled_flag && ConfigArr[Pin].pinDirectionChange) {
        volatile uint8 *DDR_regPtr = NULL;
        uint8 localPortID = Pin / 8;
        Port_PinType localPinID = Pin % 8;
        switch(localPortID) {
            case PORT_A:
                DDR_regPtr = DDRA_REG;
            break;
            case PORT_B:
                DDR_regPtr = DDRB_REG;
            break;
            case PORT_C:
                DDR_regPtr = DDRC_REG;
            break;
            case PORT_D:
                DDR_regPtr = DDRD_REG;
            break;
        }
        if(DDR_regPtr != NULL) {
            switch(Direction) {
                case PORT_PIN_IN:
                    CLR_BIT(*DDR_regPtr,(uint8)localPinID);
                break;
                case PORT_PIN_OUT:
                    SET_BIT(*DDR_regPtr,(uint8)localPinID);
                break;
            }
        }
    }
}
#endif
/**
 * @brief  
 * @param  none
 * @return none 
*/
void Port_RefreshPortDirection (void) {
    if(initCalled_flag) {
        volatile uint8 *DDR_regPtr = NULL, *PORT_regPtr = NULL;
        
        uint8 localPortID;
        Port_PinType localPinID;
        
        for(Port_PinType pin = PORT_A_PIN_0; pin <= PORT_D_PIN_7; pin++) {
            if(ConfigArr[pin].pinDirectionChange == FALSE) {
                DDR_regPtr = NULL;
                PORT_regPtr = NULL;
                
                localPortID = pin / 8;
                localPinID = pin % 8;

                switch(ConfigArr[pin].pinMode) {
                    case PIN_MODE_DIO:
                        switch(localPortID) {
                            case PORT_A:
                                DDR_regPtr = DDRA_REG;
                                PORT_regPtr = PORTA_REG;
                            break;
                            case PORT_B:
                                DDR_regPtr = DDRB_REG;
                                PORT_regPtr = PORTB_REG;
                            break;
                            case PORT_C:
                                DDR_regPtr = DDRC_REG;
                                PORT_regPtr = PORTC_REG;
                            break;
                            case PORT_D:
                                DDR_regPtr = DDRD_REG;
                                PORT_regPtr = PORTD_REG;
                            break;
                        }
                        if((DDR_regPtr != NULL) && (PORT_regPtr != NULL)) {
                            switch(ConfigArr[pin].pinDirection) {
                                case PORT_PIN_IN:
                                    CLR_BIT(*DDR_regPtr,(uint8)localPinID);
                                    switch(ConfigArr[pin].pinInternalPullUpActive) {
                                        case 0:
                                            CLR_BIT(*PORT_regPtr,(uint8)localPinID);
                                        break;
                                        case 1:
                                            SET_BIT(*PORT_regPtr,(uint8)localPinID);
                                        break;
                                    }
                                break;
                                case PORT_PIN_OUT:
                                    SET_BIT(*DDR_regPtr,(uint8)localPinID);
                                    switch(ConfigArr[pin].pinLevelInit) {
                                        case 0:
                                            CLR_BIT(*PORT_regPtr,(uint8)localPinID);
                                        break;
                                        case 1:
                                            SET_BIT(*PORT_regPtr,(uint8)localPinID);
                                        break;
                                    }
                                break;
                            }
                        }
                    break;
                }
                
            }           
        }
    }
}

/**
 * @brief  
 * @param  Port_PinType
 * @param  Port_PinModeType
 * @return 
*/
void Port_SetPinMode (Port_PinType Pin, Port_PinModeType Mode) {
    if(initCalled_flag) {
        volatile uint8 *DDR_regPtr = NULL, *PORT_regPtr = NULL;
        
        uint8 localPortID;
        Port_PinType localPinID;
        
        for(Port_PinType pin = PORT_A_PIN_0; pin <= PORT_D_PIN_7; pin++) {
            if(ConfigArr[pin].pinModeChange == TRUE) {
                DDR_regPtr = NULL;
                PORT_regPtr = NULL;
                
                localPortID = pin / 8;
                localPinID = pin % 8;

                switch(ConfigArr[pin].pinMode) {
                    case PIN_MODE_DIO:
                        switch(localPortID) {
                            case PORT_A:
                                DDR_regPtr = DDRA_REG;
                                PORT_regPtr = PORTA_REG;
                            break;
                            case PORT_B:
                                DDR_regPtr = DDRB_REG;
                                PORT_regPtr = PORTB_REG;
                            break;
                            case PORT_C:
                                DDR_regPtr = DDRC_REG;
                                PORT_regPtr = PORTC_REG;
                            break;
                            case PORT_D:
                                DDR_regPtr = DDRD_REG;
                                PORT_regPtr = PORTD_REG;
                            break;
                        }
                        if((DDR_regPtr != NULL) && (PORT_regPtr != NULL)) {
                            
                        }
                    break;
                }
                
            }           
        }
    }
}
