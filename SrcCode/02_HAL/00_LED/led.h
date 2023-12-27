#ifndef LED_H_
#define LED_H_

#include "../../00_LIB/std_types.h"
typedef enum
{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly
	 */
	led_enumOk = 0,
    led_enumWrongActiveState,
    led_enumWrongState,
	led_enumLedOutOfBounds,
    /**
	 *@brief : generalized error
	 */
	led_enumNotOk

}led_enumError_t;

led_enumError_t LED_init(void);

led_enumError_t LED_SetLedState(u8 led_id, u8 State);

#endif