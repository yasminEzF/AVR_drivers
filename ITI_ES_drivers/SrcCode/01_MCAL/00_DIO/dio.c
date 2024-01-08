#include "../../00_LIB/bit_math.h"
#include "../../00_LIB/std_types.h"
#include "../../00_LIB/AVR_reg.h"
#include "../01_PORT/portCfg.h"
#include "dio.h"

DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig) {
	DIO_enumError_t errorStatus = DIO_enumNotOk;
	if(Copy_enumPortNum > PORTS_NUM) {
		errorStatus = DIO_enumWrongPort;
	}
	else if(Copy_enumConfig > DIO_enumInputExternalPD) {
		errorStatus = DIO_enumWrongConfig;
	}
	else if(Copy_enumPinNum > DIO_enumPin7) {
		errorStatus = DIO_enumWrongPin;
	}
	else {
		errorStatus = DIO_enumOk;
		volatile u8 *DDR_regPtr = NULL, *PORT_regPtr = NULL;
		switch(Copy_enumPortNum) {
#if ((PORTS_NUM == PORT_A)||(PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortA:
				DDR_regPtr = DDRA_REG;
				PORT_regPtr = PORTA_REG;
				break;
#endif
#if ((PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortB:
				DDR_regPtr = DDRB_REG;
				PORT_regPtr = PORTB_REG;
			break;
#endif
#if ((PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortC:
				DDR_regPtr = DDRC_REG;
				PORT_regPtr = PORTC_REG;
			break;
#endif
#if (PORTS_NUM == PORTS_A_B_C_D)
			case DIO_enumPortD:
				DDR_regPtr = DDRD_REG;
				PORT_regPtr = PORTD_REG;
			break;
#endif
			default:
                    errorStatus = DIO_enumWrongPort;
		}
		if((DDR_regPtr == NULL) || (PORT_regPtr == NULL)){
			errorStatus = DIO_enumWrongPort;
		}
		else {
			switch(Copy_enumConfig) {
				case DIO_enumOutput:
					SET_BIT(*DDR_regPtr,Copy_enumPinNum);
				break;
				case DIO_enumInputInternalPU:
					CLR_BIT(*DDR_regPtr, Copy_enumPinNum);
					SET_BIT(*PORT_regPtr, Copy_enumPinNum);
				break;
				case DIO_enumInputExternalPD:
					CLR_BIT(*DDR_regPtr, Copy_enumPinNum);
					CLR_BIT(*PORT_regPtr, Copy_enumPinNum);
				break;
				default:
					errorStatus = DIO_enumWrongConfig;
			}
		}
	}
	return errorStatus;
}

DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig) {
	DIO_enumError_t errorStatus = DIO_enumNotOk;
	if(Copy_enumPortNum > PORTS_NUM) {
		errorStatus = DIO_enumWrongPort;
	}
	else if(Copy_enumConfig > DIO_enumInputExternalPD) {
		errorStatus = DIO_enumWrongConfig;
	}
	else {
		errorStatus = DIO_enumOk;
		volatile u8 *DDR_regPtr = NULL, *PORT_regPtr = NULL;
		switch(Copy_enumPortNum) {
#if ((PORTS_NUM == PORT_A)||(PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortA:
				DDR_regPtr = DDRA_REG;
				PORT_regPtr = PORTA_REG;
			break;
#endif
#if ((PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortB:
				DDR_regPtr = DDRB_REG;
				PORT_regPtr = PORTB_REG;
			break;
#endif
#if ((PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortC:
				DDR_regPtr = DDRC_REG;
				PORT_regPtr = PORTC_REG;
			break;
#endif
#if (PORTS_NUM == PORTS_A_B_C_D)
			case DIO_enumPortD:
				DDR_regPtr = DDRD_REG;
				PORT_regPtr = PORTD_REG;
			break;
#endif
			default:
                    errorStatus = DIO_enumWrongPort;
		}
		if((DDR_regPtr == NULL) || (PORT_regPtr == NULL)){
			errorStatus = DIO_enumWrongPort;
		}
		else {
			switch(Copy_enumConfig) {
				case DIO_enumOutput:
					*DDR_regPtr = 0xFF;
				break;
				case DIO_enumInputInternalPU:
					*DDR_regPtr = 0x00;
					*PORT_regPtr = 0xFF;
				break;
				case DIO_enumInputExternalPD:
					*DDR_regPtr = 0x00;
					*PORT_regPtr = 0x00;
				break;
				default:
					errorStatus = DIO_enumWrongConfig;
			}
		}
	}
	return errorStatus;
}

DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState) {
	DIO_enumError_t errorStatus = DIO_enumNotOk;
	if(Copy_enumPortNum > PORTS_NUM) {
		errorStatus = DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum > DIO_enumPin7) {
		errorStatus = DIO_enumWrongPin;
	}
	else if(Copy_enumLogicState > DIO_enumLogicHigh) {
		errorStatus = DIO_enumWrongPinState;
	}
	else {
		errorStatus = DIO_enumOk;
		volatile u8 *PORT_regPtr = NULL;
		switch(Copy_enumPortNum) {
#if ((PORTS_NUM == PORT_A)||(PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortA:
				PORT_regPtr = PORTA_REG;
			break;
#endif
#if ((PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortB:
				PORT_regPtr = PORTB_REG;
			break;
#endif
#if ((PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortC:
				PORT_regPtr = PORTC_REG;
			break;
#endif
#if (PORTS_NUM == PORTS_A_B_C_D)
			case DIO_enumPortD:
				PORT_regPtr = PORTD_REG;
			break;
#endif
			default:
                    errorStatus = DIO_enumWrongPort;
		}
		if(PORT_regPtr == NULL) {
			errorStatus = DIO_enumWrongPort;
		}
		else {
			switch(Copy_enumLogicState) {
				case DIO_enumLogicHigh:
					SET_BIT(*PORT_regPtr, Copy_enumPinNum);
				break;
				case DIO_enumLogicLow:
					CLR_BIT(*PORT_regPtr, Copy_enumPinNum);
				break;
				default:
					errorStatus = DIO_enumWrongPinState;
			}
		}
	}
	return errorStatus;
}

DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue) {
	DIO_enumError_t errorStatus = DIO_enumNotOk;
	if(Copy_enumPortNum > PORTS_NUM) {
		errorStatus = DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum > DIO_enumPin7) {
		errorStatus = DIO_enumWrongPin;
	}	
	else {
		errorStatus = DIO_enumOk;
		volatile u8 *PIN_regPtr = NULL;
		switch(Copy_enumPortNum) {
#if ((PORTS_NUM == PORT_A)||(PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortA:
				PIN_regPtr = PINA_REG;
			break;
#endif
#if ((PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortB:
				PIN_regPtr = PINB_REG;
			break;
#endif
#if ((PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortC:
				PIN_regPtr = PINC_REG;
			break;
#endif
#if (PORTS_NUM == PORTS_A_B_C_D)
			case DIO_enumPortD:
				PIN_regPtr = PIND_REG;
			break;
#endif
			default:
                    errorStatus = DIO_enumWrongPort;
		}
		if(PIN_regPtr == NULL) {
			errorStatus = DIO_enumWrongPort;
		}
		else {
			*Add_Pu8PinValue = (u8)GET_BIT(*PIN_regPtr,(u8)Copy_enumPinNum);
		}
	}
	return errorStatus;
}

DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState) {
	DIO_enumError_t errorStatus = DIO_enumNotOk;
	if(Copy_enumPortNum > PORTS_NUM) {
		errorStatus = DIO_enumWrongPort;
	}
	else if(Copy_enumLogicState > DIO_enumLogicHigh) {
		errorStatus = DIO_enumWrongPinState;
	}
	else {
		errorStatus = DIO_enumOk;
		volatile u8 *PORT_regPtr = NULL;
		switch(Copy_enumPortNum) {
#if ((PORTS_NUM == PORT_A)||(PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortA:
				PORT_regPtr = PORTA_REG;
			break;
#endif
#if ((PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortB:
				PORT_regPtr = PORTB_REG;
			break;
#endif
#if ((PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
			case DIO_enumPortC:
				PORT_regPtr = PORTC_REG;
			break;
#endif
#if (PORTS_NUM == PORTS_A_B_C_D)
			case DIO_enumPortD:
				PORT_regPtr = PORTD_REG;
			break;
#endif
			default:
                    errorStatus = DIO_enumWrongPort;
		}
		if(PORT_regPtr == NULL) {
			errorStatus = DIO_enumWrongPort;
		}
		else {
			switch(Copy_enumLogicState) {
				case DIO_enumLogicHigh:
					ASSIGN_REG(*PORT_regPtr, 0xFF);
				break;
				case DIO_enumLogicLow:
					ASSIGN_REG(*PORT_regPtr, 0x00);
				break;
				default:
					errorStatus = DIO_enumWrongPinState;
			}
		}
	}
	return errorStatus;
}

void DIO_DelayMs(u32 Copy_u32TimeMs) {
	// Assembly code auto-generated
	// by utility from Bret Mulvey
	// Delay 1 000 cycles
	// 1ms at 1 MHz
	while(Copy_u32TimeMs--) {
		asm volatile (
			"    ldi  r18, 2	\n"
			"    ldi  r19, 75	\n"
			"1:  dec  r19	\n"
			"    brne 1b	\n"
			"    dec  r18	\n"
			"    brne 1b	\n"
			"    rjmp 1f	\n"
			"1:	\n"
		);	
	}
	
}
