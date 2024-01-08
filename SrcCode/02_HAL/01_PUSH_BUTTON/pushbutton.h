#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_

#include "00_LIB/std_types.h"

typedef enum {
	/**
	 *@brief : Everything Ok, Function had Performed Correctly
	 */
	pb_enumOk = 0,
    pb_enumWrongActiveState,
    pb_enumWrongState,
	pb_enumPBOutOfBounds,
    /**
	 *@brief : generalized error
	 */
	pb_enumNotOk

}pb_enumError_t;

typedef enum {
    pb_notPressed = 0,
    pb_pressed
}pb_pressedState;

pb_enumError_t PB_Init(void);
pb_enumError_t PB_ReadState(u8 pb_id,u8* pb_state);

#endif