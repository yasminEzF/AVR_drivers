#include "std_types.h"
#include "bit_math.h"
#include "AVR_reg.h"
#include "dio.h"

/**
 * @brief  Returns the value of the specified DIO channel
 * @param  ChannelId ID of DIO channel (0 ~ 31)
 * @return Dio_LevelType (STD_HIGH or STD_LOW)
*/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId) {
    volatile uint8 *PIN_regPtr = NULL;
    Dio_LevelType pinValueReturn;
    Dio_PortType localPortID = ChannelId / 8;
    Dio_ChannelType localPinID = ChannelId % 8;
    switch(localPortID) {
        case PORT_A:
            PIN_regPtr = PINA_REG;
        break;
        case PORT_B:
            PIN_regPtr = PINB_REG;
        break;
        case PORT_C:
            PIN_regPtr = PINC_REG;
        break;
        case PORT_D:
            PIN_regPtr = PIND_REG;
        break;
    }
    if(PIN_regPtr != NULL) {
        pinValueReturn = (Dio_LevelType)GET_BIT(*PIN_regPtr,(uint8)localPinID);
    }
    return pinValueReturn;
}

/**
 * @brief  sets the level of a specified DIO channel
 * @param  ChannelId ID of DIO channel (0 ~ 31)
 * @param  Level (STD_HIGH or STD_LOW)
 * @return void
*/
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level) {
    volatile uint8 *PORT_regPtr = NULL;
    Dio_PortType localPortID = ChannelId / 8;
    Dio_ChannelType localPinID = ChannelId % 8;
    switch(localPortID) {
        case PORT_A:
            PORT_regPtr = PORTA_REG;
        break;
        case PORT_B:
            PORT_regPtr = PORTB_REG;
        break;
        case PORT_C:
            PORT_regPtr = PORTC_REG;
        break;
        case PORT_D:
            PORT_regPtr = PORTD_REG;
        break;
    }
    if(PORT_regPtr != NULL) {
        switch(Level) {
            case STD_HIGH:
                SET_BIT(*PORT_regPtr, localPinID);
            break;
            case STD_LOW:
                CLR_BIT(*PORT_regPtr, localPinID);
            break;
        }
    }    
}

/**
 * @brief  Returns the level of all channels of that port
 * @param  PortId ID of DIO Port (0 ~ 3)
 * @return Dio_PortLevelType Level of all channels of that port
*/
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId) {
    volatile uint8 *PIN_regPtr = NULL;
    Dio_PortLevelType portValueReturn;
    switch(PortId) {
        case PORT_A:
            PIN_regPtr = PINA_REG;
        break;
        case PORT_B:
            PIN_regPtr = PINB_REG;
        break;
        case PORT_C:
            PIN_regPtr = PINC_REG;
        break;
        case PORT_D:
            PIN_regPtr = PIND_REG;
        break;
    }
    if(PIN_regPtr != NULL) {
        portValueReturn = (Dio_PortLevelType)(*PIN_regPtr);
    }
    return portValueReturn;
}

/**
 * @brief  sets a value to the port
 * @param  PortId ID of DIO Port (0 ~ 3)
 * @param  Level Value to be written (0x00 ~ 0xFF)
 * @return none
*/
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level) {
    volatile uint8 *PORT_regPtr = NULL;
    switch(PortId) {
        case PORT_A:
            PORT_regPtr = PORTA_REG;
        break;
        case PORT_B:
            PORT_regPtr = PORTB_REG;
        break;
        case PORT_C:
            PORT_regPtr = PORTC_REG;
        break;
        case PORT_D:
            PORT_regPtr = PORTD_REG;
        break;
    }
    if(PORT_regPtr != NULL) {
        *PORT_regPtr = Level;
    }
}

/**
 * @brief  reads a subset of the adjoining bits of a port
 * @param  ChannelGroupIdPtr* Pointer to ChannelGroup
 * @return Dio_PortLevelType Level of a ChannelGroup
*/
Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr) {
    volatile uint8 *PIN_regPtr = NULL;
    Dio_PortLevelType channelGroupValueReturn;
    switch(ChannelGroupIdPtr->port) {
        case PORT_A:
            PIN_regPtr = PINA_REG;
        break;
        case PORT_B:
            PIN_regPtr = PINB_REG;
        break;
        case PORT_C:
            PIN_regPtr = PINC_REG;
        break;
        case PORT_D:
            PIN_regPtr = PIND_REG;
        break;
    }
    if(PIN_regPtr != NULL) {
        /**
         * mask bit = 0 -> reg
         * mask bit = 1 -> lvl
        */
        channelGroupValueReturn = (Dio_PortLevelType)((*PIN_regPtr & (ChannelGroupIdPtr->mask)) >> (ChannelGroupIdPtr->offset));
    }
    return channelGroupValueReturn;
}

/**
 * @brief  sets a subset of the adjoining bits of a port to a specified level
 * @param  ChannelGroupIdPtr* Pointer to ChannelGroup
 * @param  Level Value to be written to ChannelGroup
 * @return none
*/
void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level) {
    volatile uint8 *PORT_regPtr = NULL;
    switch(ChannelGroupIdPtr->port) {
        case PORT_A:
            PORT_regPtr = PORTA_REG;
        break;
        case PORT_B:
            PORT_regPtr = PORTB_REG;
        break;
        case PORT_C:
            PORT_regPtr = PORTC_REG;
        break;
        case PORT_D:
            PORT_regPtr = PORTD_REG;
        break;
    }
    if(PORT_regPtr != NULL) {

        /**
         * mask bit = 0 -> reg
         * mask bit = 1 -> lvl
        */
        uint8 temp = (*PORT_regPtr & ~(ChannelGroupIdPtr->mask)) | ((ChannelGroupIdPtr->mask) & (Level << (ChannelGroupIdPtr->offset)));
        *PORT_regPtr = temp;
    }
}

/**
 * @brief  flips (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip
 * @param  ChannelId ID of DIO channel (0 ~ 31)
 * @return Dio_LevelType Value after flip (STD_HIGH or STD_LOW)
*/
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId) {
    volatile uint8 *PORT_regPtr = NULL;
    Dio_LevelType pinValueReturn;
    Dio_PortType localPortID = ChannelId / 8;
    Dio_ChannelType localPinID = ChannelId % 8;
    switch(localPortID) {
        case PORT_A:
            PORT_regPtr = PORTA_REG;
        break;
        case PORT_B:
            PORT_regPtr = PORTB_REG;
        break;
        case PORT_C:
            PORT_regPtr = PORTC_REG;
        break;
        case PORT_D:
            PORT_regPtr = PORTD_REG;
        break;
    }
    if(PORT_regPtr != NULL) {
        TGL_BIT(*PORT_regPtr,(uint8)localPinID);
        pinValueReturn = (Dio_LevelType)GET_BIT(*PORT_regPtr,(uint8)localPinID);
    }
    return pinValueReturn;
}

/**
 * @brief  sets the value of a given port with required mask
 * @param  PortId ID of DIO Port (0 ~ 3)
 * @param  Level Value to be written (0x00 ~ 0xFF)
 * @param  Mask Channels to be masked in the port (if mask = 1 -> write level value)
 * @return none
*/
void Dio_MaskedWritePort (Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask) {
    volatile uint8 *PORT_regPtr = NULL;
    switch(PortId) {
        case PORT_A:
            PORT_regPtr = PORTA_REG;
        break;
        case PORT_B:
            PORT_regPtr = PORTB_REG;
        break;
        case PORT_C:
            PORT_regPtr = PORTC_REG;
        break;
        case PORT_D:
            PORT_regPtr = PORTD_REG;
        break;
    }
    if(PORT_regPtr != NULL) {
        /**
         * mask bit = 0 -> reg
         * mask bit = 1 -> lvl
        */
        uint8 temp = (*PORT_regPtr & ~(Mask)) | (Mask & Level);
        *PORT_regPtr = temp;
    }
}

//void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo );
