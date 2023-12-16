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

led_enumError_t ledInit(void);
led_enumError_t ledOn(u8 led_id);
led_enumError_t ledOff(u8 led_id);

#endif