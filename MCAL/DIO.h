/*
 * DIO.h
 *
 * Created: 11/25/2023 2:45:49 PM
 *  Author: yasmi
 */ 

	
#ifndef DIO_H_
#define DIO_H_
 
#include "std_types.h"
#include "std_math.h"

 typedef enum
 {
	 DIO_enumOk,
	 DIO_enumNullPointer,
	 DIO_enumWrongPort,
	 DIO_enumWrongPin,
	 DIO_enumWrongConfig,
	 DIO_enumWrongLogicState
 }DIO_enumErrorStatus_t;
 
 typedef enum
 {
	 DIO_enumOutput,
	 DIO_enumInputInternalPU,
	 DIO_enumInputExternalPD
 }DIO_enumConfig_t;
 
 typedef enum
 {
	 DIO_enumPortA,
	 DIO_enumPortB,
	 DIO_enumPortC,
	 DIO_enumPortD
 }DIO_enumPorts_t;

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

 typedef enum
 {
	 DIO_enumLogicLow,
	 DIO_enumLogicHigh
 }DIO_enumLogicState;
 
 DIO_enumErrorStatus_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum, DIO_enumConfig_t Copy_enumConfig );
 DIO_enumErrorStatus_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum, DIO_enumConfig_t Copy_enumConfig);
 DIO_enumErrorStatus_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum, DIO_enumLogicState Copy_enumLogicState);
 DIO_enumErrorStatus_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum, DIO_enumLogicState Copy_enumLogicState);
 DIO_enumErrorStatus_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum, DIO_enumLogicState* Add_PenumPinValue);


#endif /* DIO_H_ */