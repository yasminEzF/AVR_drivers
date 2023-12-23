#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"

/**
 * @brief numeric ID of DIO channel ( 0 ~ 31 )
*/
typedef uint8 Dio_ChannelType;

/**
 * @brief numeric ID of DIO port ( 0 ~ 3 )
*/
typedef uint8 Dio_PortType;

#define PORT_A  0x00
#define PORT_B  0x01
#define PORT_C  0x02
#define PORT_D  0x03

/**
 * @brief Type for the definition of a channel group, which consists of several adjoining channels within a port
*/
typedef struct {
    /**
     * defines the positions of the channel group
    */
    uint8 mask;
    /**
     * the position of the Channel Group on the port, counted from the LSB
    */
    uint8 offset;
    /**
     * the port on which the Channel group is defined
    */
    Dio_PortType port;
}Dio_ChannelGroupType;

/**
 * @brief possible levels a DIO channel can have (input or output)
*/
typedef uint8 Dio_LevelType;
/**
 * Physical state 0V
*/
#define STD_LOW     0x00
/**
* Physical state 5V or 3.3V
*/
#define STD_HIGH    0x01 

/**
 * @brief the μC owns ports of 8-bit widths, Dio_PortLevelType inherits the size of the port.
 * 0x00 ~ 0xFF
*/
typedef uint8 Dio_PortLevelType;

/*****************************************************************************/
/*                                  functions                                */
/*****************************************************************************/
/**
 * @brief  Returns the value of the specified DIO channel
 * @param  Dio_ChannelType ID of DIO channel (0 ~ 31)
 * @return Dio_LevelType (STD_HIGH or STD_LOW)
*/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
/**
 * @brief  Returns the value of the specified DIO channel
 * @param  Dio_ChannelType ID of DIO channel (0 ~ 31)
 * @param  Dio_LevelType (STD_HIGH or STD_LOW)
 * @return void
*/
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);
/**
 * @brief  Returns the level of all channels of that port
 * @param  Dio_PortType ID of DIO Port (0 ~ 3)
 * @return Dio_PortLevelType Level of all channels of that port
*/
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);
/**
 * @brief  sets a value to the port
 * @param  Dio_PortType ID of DIO Port (0 ~ 3)
 * @param  Dio_PortLevelType Value to be written (0x00 ~ 0xFF)
 * @return none
*/
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);

/**
 * @brief  reads a subset of the adjoining bits of a port
 * @param  Dio_ChannelGroupType* Pointer to ChannelGroup
 * @return Dio_PortLevelType Level of a ChannelGroup
*/
Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr);

/**
 * @brief  sets a subset of the adjoining bits of a port to a specified level
 * @param  Dio_ChannelGroupType* Pointer to ChannelGroup
 * @param  Dio_PortLevelType Value to be written to ChannelGroup
 * @return none
*/
void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);

//void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo );

/**
 * @brief  flips (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip
 * @param  Dio_ChannelType ID of DIO channel (0 ~ 31)
 * @return Dio_LevelType Value to be written (STD_HIGH or STD_LOW)
*/
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId );

/**
 * @brief  sets the value of a given port with required mask
 * @param  Dio_PortType ID of DIO Port (0 ~ 3)
 * @param  Dio_PortLevelType Value to be written (0x00 ~ 0xFF)
 * @param  Dio_PortLevelType Channels to be masked in the port (if mask = 1 -> write level value)
 * @return none
*/
void Dio_MaskedWritePort( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask );

#endif /* DIO_H_ */