#include "SrcCode\00_LIB\std_types.h"
#include "7_seg_cfg.h"
#include "7_seg.h"
#include "SrcCode\01_MCAL\01_PORT\port.h"
#include "SrcCode\01_MCAL\00_DIO\dio.h"

/**
 * @brief  turns on a led segment in a specified seven segment
 * @param  seg_id seven segment index
 * @param  seg_led_id specific led segment index
 * @return seg_enumError_t seven segment error status
*/
static seg_enumError_t _7SEG_SegLedOn(u8 seg_id, seg_enumLed_t seg_led_id);

/**
 * @brief  turns off a led segment in a specified seven segment
 * @param  seg_id seven segment index
 * @param  seg_led_id specific led segment index
 * @return seg_enumError_t seven segment error status
*/
static seg_enumError_t _7SEG_SegLedOff(u8 seg_id, seg_enumLed_t seg_led_id);

/**
 * @brief  displays a single digit number on a specified seven segment
 * @param  seg_id seven segment index
 * @param  value
 * @return seg_enumError_t seven segment error status
*/
seg_enumError_t _7SEG_DisplayValueSingleSeg (u8 seg_id,u8 value) {
    seg_enumError_t errorStatus = seg_enumNotOk;
    if(seg_id >= NUM_SEG) {
        errorStatus = seg_enumSegOutOfBounds;
    }
    else if(value > MAX_DISPLAY_VALUE) {
        errorStatus = seg_enumDisplayValueOutOfBounds;
    } 
    else {
		u8 displayValue;
		switch(value) {
			case 0:
				displayValue = DISPLAY_0;
			break;
			case 1:
				displayValue = DISPLAY_1;
			break;
			case 2:
				displayValue = DISPLAY_2;
			break;
			case 3:
				displayValue = DISPLAY_3;
			break;
			case 4:
				displayValue = DISPLAY_4;
			break;
			case 5:
				displayValue = DISPLAY_5;
			break;
			case 6:
				displayValue = DISPLAY_6;
			break;
			case 7:
				displayValue = DISPLAY_7;
			break;
			case 8:
				displayValue = DISPLAY_8;
			break;
			case 9:
				displayValue = DISPLAY_9;
			break;
			default:
				displayValue = 0x00;
		}
        for(seg_enumLed_t led_id = a; led_id <= dp; led_id++) {
            errorStatus = seg_enumNotOk;
            if((displayValue >> led_id) & 0x1) {
                _7SEG_SegLedOn(seg_id, led_id);
            }
            else {
                _7SEG_SegLedOff(seg_id, led_id);
            }
            errorStatus = seg_enumOk;
        }
    }
    return errorStatus;
}

extern segConfigStruct_t segCfgStructArr[NUM_SEG];

seg_enumError_t _7SEG_Init (void) {
    seg_enumError_t errorStatus = seg_enumNotOk;
    port_configStruct_t current_seg;
    for(u8 i = 0; i < NUM_SEG; i++) {
        if(segCfgStructArr[i].segCommon > seg_enumCommonCathode) {
            errorStatus = seg_enumWrongCommon;
            break;
        }
        else {
            current_seg.pinCfg.pinDir = pin_enumOutput;
            current_seg.pinCfg.pinState = pin_enumInactive;
            for(u8 j = a; j <= dp; j++) {
                errorStatus = seg_enumNotOk;
                current_seg.port_ID = segCfgStructArr[i].segPinsArr[j].port_id;
                current_seg.pin_ID = segCfgStructArr[i].segPinsArr[j].pin_id;
                switch(segCfgStructArr[i].segCommon) {
                    case seg_enumCommonAnode:
                        current_seg.pinCfg.pinState = pin_enumActive;
                    break;
                    case seg_enumCommonCathode:
                        current_seg.pinCfg.pinState = pin_enumInactive;
                    break;
                }
                if(!port_setCfg(&current_seg)) {
                    errorStatus = seg_enumOk;
                }
                else {
                    break;
                } 
            }                                    
        }
    }
    return errorStatus;
}
static seg_enumError_t _7SEG_SegLedOff(u8 seg_id, seg_enumLed_t seg_led_id) {
    seg_enumError_t errorStatus = seg_enumNotOk;
    switch(segCfgStructArr[seg_id].segCommon) {
        case seg_enumCommonAnode:
            if(!DIO_enumSetPin(segCfgStructArr[seg_id].segPinsArr[seg_led_id].port_id,segCfgStructArr[seg_id].segPinsArr[seg_led_id].pin_id,DIO_enumLogicHigh))
                errorStatus = seg_enumOk;
        break;
        case seg_enumCommonCathode:
            if(!DIO_enumSetPin(segCfgStructArr[seg_id].segPinsArr[seg_led_id].port_id,segCfgStructArr[seg_id].segPinsArr[seg_led_id].pin_id,DIO_enumLogicLow))
                errorStatus = seg_enumOk;
        break;
    }
    return errorStatus;
}
static seg_enumError_t _7SEG_SegLedOn(u8 seg_id, seg_enumLed_t seg_led_id) {
    seg_enumError_t errorStatus = seg_enumNotOk;
    switch(segCfgStructArr[seg_id].segCommon) {
        case seg_enumCommonAnode:
            if(!DIO_enumSetPin(segCfgStructArr[seg_id].segPinsArr[seg_led_id].port_id,segCfgStructArr[seg_id].segPinsArr[seg_led_id].pin_id,DIO_enumLogicLow))
                errorStatus = seg_enumOk;        
        break;
        case seg_enumCommonCathode:
            if(!DIO_enumSetPin(segCfgStructArr[seg_id].segPinsArr[seg_led_id].port_id,segCfgStructArr[seg_id].segPinsArr[seg_led_id].pin_id,DIO_enumLogicHigh))
                errorStatus = seg_enumOk;        
        break;
    }
    return errorStatus;
}

seg_enumError_t _7SEG_DisplayValueMultiSeg (u16 value) {
    seg_enumError_t errorStatus = seg_enumNotOk;
    u16 max_value = 1;
    for(u8 i = NUM_SEG; i > 0; i--) {
        max_value *= 10;
    }
	max_value--;
    if(value > max_value) {
        errorStatus = seg_enumDisplayValueOutOfBounds;
    }
    else {
        for(u8 i = 0; value > 0 && i < NUM_SEG; i++, value /= 10) {
            _7SEG_DisplayValueSingleSeg(i, value % 10);
        }
        errorStatus = seg_enumOk;
    }
    return errorStatus;
}
