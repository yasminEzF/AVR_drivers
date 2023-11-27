# DIO Module Readme

This readme file provides an overview and usage instructions for the DIO (Digital Input/Output) module. The DIO module consists of three files: `DIO.h`, `DIO.c`, and `App`. Additionally, the DIO module relies on two supporting files: `bitmath.h` and `std-types.h`. It also includes a `delay_ms` function for introducing delays in your code. Below, you will find information about the driver's files, functions, and usage Below, you will find information about each file, including its purpose and the functions it contains.

## Files Description

### 1. DIO.h

The `DIO.h` file contains all the necessary function prototypes, constants, and definitions required for using the DIO module. It serves as the header file for the DIO module, providing an interface for users to access the module's functionality. This file also includes the necessary `bitmath.h` and `std-types.h` files.

### 2. DIO.c

The `DIO.c` file contains the implementation of the DIO module's functions. It includes the logic and code required to perform various operations such as setting pin directions, setting pin values, and retrieving pin values. This file serves as the main implementation file for the DIO module. It also includes the necessary `bitmath.h` and `std-types.h` files.

### 3. App

The `App` directory contains two task files: `task1.c` and `task2.c`, which demonstrate the usage of the DIO module in different scenarios.

#### a. task1.c

The `task1.c` file demonstrates how to toggle between two LEDs using the DIO module. It utilizes the functions provided by the DIO module to control the state of the LEDs connected to specific pins. This file serves as an example usage of the DIO module for basic LED toggling.

#### b. task2.c

The `task2.c` file demonstrates how to count the number of times a switch is pressed and convert the count into a 4-bit binary representation. Each bit of the binary representation corresponds to an LED, which is controlled by the DIO module. The DIO module functions are used to set the LED states based on the binary value. This file serves as an example usage of the DIO module for more advanced applications involving switches and LEDs.

## DIO module Functions

The DIO module provides the following functions:

### 1. `u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinDirection)`

This function is used to set the direction of a specific pin on a given port. It takes three parameters:
- `Copy_u8Port`: The port number to which the pin belongs.
- `Copy_u8Pin`: The pin number whose direction will be set.
- `Copy_u8PinDirection`: The desired direction of the pin (input or output).

### 2. `u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8PortDirection)`

This function is used to set the direction of an entire port. It takes two parameters:
- `Copy_u8Port`: The port number whose direction will be set.
- `Copy_u8PortDirection`: The desired direction of the port (input or output).

### 3. `u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue)`

This function is used to set the value of a specific pin on a given port. It takes three parameters:
- `Copy_u8Port`: The port number to which the pin belongs.
- `Copy_u8Pin`: The pin number whose value will be set.
- `Copy_u8PinValue`: The desired value of the pin (high or low).

### 4. `u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8PortValue)`

This function is used to set the value of an entire port. It takes two parameters:
- `Copy_u8Port`: The port number whose value will be set.
- `Copy_u8PortValue`: The desired value of the port (high or low).

### 5. `u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8PinValue)`

This function is used to retrieve the value of a specific pin on a given port. It takes three parameters:
- `Copy_u8Port`: The port number to which the pin belongs.
- `Copy_u8Pin`: The pin number whose value will be retrieved.
- `Copy_pu8PinValue`: A pointer to a variable where the pin value will be stored.

### 6. `void DIO_DelayMs(uint32_t TimeMs)`

This function introduces a delay in milliseconds using the `NOP` instruction. It can be used to pause the execution of your code for a specific duration.

- `TimeMs`: The delay duration in milliseconds.

## Usage

To use the DIO module in your application, follow these steps:

1. Include the `DIO.h` header file in your source file.
2. Implement the necessary hardware-specific code to initialize the ports andpins used by the DIO module.
3. Call the DIO module functions as needed to perform your desired operations on the ports and pins.
4. Utilize the `DIO_DelayMs` function to introduce delays in your code. For example, to introduce a 500 ms delay, use the following code:

   `c
   DIO_DelayMs(500);

Refer to the provided `task1.c` and `task2.c` files in the `App` directory for example usages of the DIO module. Modify the code according to your hardware configuration and requirements.

Note: Make sure to configure the microcontroller's ports and pins before using the DIO module functions to ensure proper operation.

## Conclusion

The DIO module provides a convenient interface for controlling digital input/output operations on microcontroller ports and pins. By using the provided functions, you can easily set pin directions, set pin values, retrieve pin values, and control entire port directions and values. The example tasks in the `App` directory demonstrate how to use the DIO module for basic LED toggling and more advanced applications involving switches and LEDs.
