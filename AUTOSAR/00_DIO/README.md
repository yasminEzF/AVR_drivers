# AVR DIO driver in compliance with the Autosar standard (22-11)

## DIO module types

### 1. `typedef uint8 Dio_ChannelType;`
numeric ID of DIO channel ( 0 ~ 31 ).
---
### 2. `typedef uint8 Dio_PortType;`
numeric ID of DIO port ( 0 ~ 3 ).

    #define PORT_A  0x00
    #define PORT_B  0x01
    #define PORT_C  0x02
    #define PORT_D  0x03
--- 
### 3. `typedef struct Dio_ChannelGroupType;`
Type for the definition of a channel group, which consists of several adjoining channels within a port.
> `uint8 mask;` defines the positions of the channel group.

> `uint8 offset;` the position of the Channel Group on the port, counted from the LSB.

> `Dio_PortType port;` the port on which the Channel group is defined.
---
### 4. `typedef uint8 Dio_LevelType;`
possible levels a DIO channel can have (input or output).

    #define STD_LOW     0x00
    #define STD_HIGH    0x01 
- `STD_LOW`     Physical state 0V
- `STD_HIGH`    Physical state 5V or 3.3V
---
### 5. `typedef uint8 Dio_PortLevelType;`
the μC owns ports of 8-bit widths, Dio_PortLevelType inherits the size of the port (0x00 ~ 0xFF).
---

## DIO module Functions

### 1.  `Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);`
Returns the value of the specified DIO channel.
- **Input:** `ChannelId` ID of DIO channel (0 ~ 31).
- **Return:** `Dio_LevelType` (STD_HIGH or STD_LOW).
---
### 2. `void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);`
sets the level of a specified DIO channel.
- **Input:** 
    - `ChannelId` ID of DIO channel (0 ~ 31).
    - `Level` (STD_HIGH or STD_LOW).
- **Return:** none.
---
### 3. `Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);`
Returns the level of all channels of that port.
- **Input:** `PortId` ID of DIO Port (0 ~ 3).
- **Return:** `Dio_PortLevelType` Level of all channels of that port.
---
### 4. `void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);`
sets a value to the port.
- **Input:** 
   - `PortId` ID of DIO Port (0 ~ 3).
   - `Level` Value to be written (0x00 ~ 0xFF)
- **Return:** none.
---
### 5. `Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr);`
reads a subset of the adjoining bits of a port.
- **Input:** `ChannelGroupIdPtr*` Pointer to ChannelGroup.
- **Return:** `Dio_PortLevelType` Level of a ChannelGroup.
---
### 6. `void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);`
sets a subset of the adjoining bits of a port to a specified level.
- **Input:**
    - `ChannelGroupIdPtr*` Pointer to ChannelGroup.
    - `Level` Value to be written to ChannelGroup.
- **Return:** none.
---
### 7. `Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId);`
flips (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip.
- **Input:** `ChannelId` ID of DIO channel (0 ~ 31).
- **Return:** `Dio_LevelType`Value after flip (STD_HIGH or STD_LOW).
---
### 6. `void Dio_MaskedWritePort (Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);`
sets the value of a given port with required mask.
- **Input:**
    - `PortId` ID of DIO Port (0 ~ 3).
    - `Level` Value to be written (0x00 ~ 0xFF).
    - `Mask` Channels to be masked in the port (if mask = 1 -> write level value).
- **Return:** none.
---

