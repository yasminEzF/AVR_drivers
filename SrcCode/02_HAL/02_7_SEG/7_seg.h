#ifndef SEG_H_
#define SEG_H_

#include "../../00_LIB/std_types.h"

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

seg_enumError_t segInit (void);
seg_enumError_t seg_displayValueSingleSeg (u8 seg_id,u8 value);
seg_enumError_t seg_displayValueMultiSeg (u16 value);

#endif