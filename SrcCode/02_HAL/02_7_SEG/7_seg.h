#ifndef SEG_H_
#define SEG_H_

#include "std_types.h"

#define DISPLAY_0   0x3F
#define DISPLAY_1   0x06
#define DISPLAY_2   0x5B
#define DISPLAY_3   0x4F
#define DISPLAY_4   0x66
#define DISPLAY_5   0x6D
#define DISPLAY_6   0x7D
#define DISPLAY_7   0x07
#define DISPLAY_8   0x7F
#define DISPLAY_9   0x6F

#define MAX_DISPLAY_VALUE		9

typedef enum {
	/**
	 *@brief : Everything Ok, Function had Performed Correctly
	 */
	seg_enumOk = 0,
    seg_enumWrongCommon,
    seg_enumSegOutOfBounds,
	seg_enumDisplayValueOutOfBounds,
    /**
	 *@brief : generalized error
	 */
	seg_enumNotOk
}seg_enumError_t;

seg_enumError_t _7SEG_Init (void);
seg_enumError_t _7SEG_DisplayValueSingleSeg (u8 seg_id,u8 value);
seg_enumError_t _7SEG_DisplayValueMultiSeg (u16 value);

#endif