
#include "7_seg_cfg.h"
#include "7_seg.h"
#include "../../01_MCAL/01_PORT/port.h"
#include "../../01_MCAL/00_DIO/dio.h"

static seg_enumError_t segLedOn(u8 seg_id, seg_enumLed_t seg_led_id);
static seg_enumError_t segLedOff(u8 seg_id, seg_enumLed_t seg_led_id);

extern segConfigStruct_t segCfgStructArr[NUM_SEG];

seg_enumError_t segInit (void) {
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

seg_enumError_t seg_displayValueSingleSeg (u8 seg_id,u8 value) {
    seg_enumError_t errorStatus = seg_enumNotOk;
    if(seg_id >= NUM_SEG) {
        errorStatus = seg_enumSegOutOfBounds;
    }
    else if(value > MAX_DISPLAY_VALUE) {
        errorStatus = seg_enumDisplayValueOutOfBounds;
    } 
    else {
        switch(value) {
            case 0:
            /**
             * on: a b c d e f
             * off: g dp
            */
                if(segLedOn(seg_id,a))
                    break;
                if(segLedOn(seg_id,b))
                    break;
                if(segLedOn(seg_id,c))
                    break;
                if(segLedOn(seg_id,d))
                    break;
                if(segLedOn(seg_id,e))
                    break;
                if(segLedOn(seg_id,f))
                    break;

                if(segLedOff(seg_id,g))
                    break;
                if(segLedOff(seg_id,dp))
                    break;
            errorStatus = seg_enumOk;
            break;
            case 1:
            /**
             * on: b c
             * off:
            */
                if(segLedOn(seg_id,b))
                    break;
                if(segLedOn(seg_id,c))
                    break;

                if(segLedOff(seg_id,a))
                    break;
                if(segLedOff(seg_id,d))
                    break;
                if(segLedOff(seg_id,e))
                    break;
                if(segLedOff(seg_id,f))
                    break;
                if(segLedOff(seg_id,g))
                    break;
                if(segLedOff(seg_id,dp))
                    break;
            errorStatus = seg_enumOk;
            break;
            case 2:
            /**
             * on: a b d e g
             * off:
            */
                if(segLedOn(seg_id,a))
                    break;
                if(segLedOn(seg_id,b))
                    break;
                if(segLedOn(seg_id,d))
                    break;
                if(segLedOn(seg_id,e))
                    break;
                if(segLedOn(seg_id,g))
                    break;

                if(segLedOff(seg_id,c))
                    break;
                if(segLedOff(seg_id,f))
                    break;
                if(segLedOff(seg_id,dp))
                    break;
            errorStatus = seg_enumOk;
            break;
            case 3:
            /**
             * on: a b c d g
             * off:
            */
                if(segLedOn(seg_id,a))
                    break;
                if(segLedOn(seg_id,b))
                    break;
                if(segLedOn(seg_id,c))
                    break;
                if(segLedOn(seg_id,d))
                    break;
                if(segLedOn(seg_id,g))
                    break;

                if(segLedOff(seg_id,e))
                    break;
                if(segLedOff(seg_id,f))
                    break;
                if(segLedOff(seg_id,dp))
                    break;
            errorStatus = seg_enumOk;
            break;
            case 4:
            /**
             * on: b c f g
             * off:
            */
                if(segLedOn(seg_id,b))
                    break;
                if(segLedOn(seg_id,c))
                    break;
                if(segLedOn(seg_id,f))
                    break;
                if(segLedOn(seg_id,g))
                    break;

                if(segLedOff(seg_id,a))
                    break;
                if(segLedOff(seg_id,d))
                    break;
                if(segLedOff(seg_id,e))
                    break;
                if(segLedOff(seg_id,dp))
                    break;
            errorStatus = seg_enumOk;
            break;
            case 5:
            /**
             * on: a c d f g
             * off:
            */
                if(segLedOn(seg_id,a))
                    break;
                if(segLedOn(seg_id,c))
                    break;
                if(segLedOn(seg_id,d))
                    break;
                if(segLedOn(seg_id,f))
                    break;
                if(segLedOn(seg_id,g))
                    break;

                if(segLedOff(seg_id,b))
                    break;
                if(segLedOff(seg_id,e))
                    break;
                if(segLedOff(seg_id,dp))
                    break;
            errorStatus = seg_enumOk;
            break;
            case 6:
            /**
             * on: a c d e f g
             * off: b dp
            */
                if(segLedOn(seg_id,a))
                    break;
                if(segLedOn(seg_id,c))
                    break;
                if(segLedOn(seg_id,d))
                    break;
                if(segLedOn(seg_id,e))
                    break;
                if(segLedOn(seg_id,f))
                    break;
                if(segLedOn(seg_id,g))
                    break;

                if(segLedOff(seg_id,b))
                    break;
                if(segLedOff(seg_id,dp))
                    break;
            errorStatus = seg_enumOk;
            break;
            case 7:
            /**
             * on: a b c
             * off: d e f g dp
            */
                if(segLedOn(seg_id,a))
                    break;
                if(segLedOn(seg_id,b))
                    break;
                if(segLedOn(seg_id,c))
                    break;

                if(segLedOff(seg_id,d))
                    break;
                if(segLedOff(seg_id,e))
                    break;
                if(segLedOff(seg_id,f))
                    break;
                if(segLedOff(seg_id,g))
                    break;
                if(segLedOff(seg_id,dp))
                    break; 
            errorStatus = seg_enumOk;
            break;
            case 8:
            /**
             * on: a b c d e f g 
             * off: dp
            */
                if(segLedOn(seg_id,a))
                    break;
                if(segLedOn(seg_id,b))
                    break;
                if(segLedOn(seg_id,c))
                    break;
                if(segLedOn(seg_id,d))
                    break;
                if(segLedOn(seg_id,e))
                    break;
                if(segLedOn(seg_id,f))
                    break;
                if(segLedOn(seg_id,g))
                    break;

                if(segLedOff(seg_id,dp))
                    break;
            errorStatus = seg_enumOk;
            break;
            case 9:
            /**
             * on: a b c d f g 
             * off: e dp
            */
                if(segLedOn(seg_id,a))
                    break;
                if(segLedOn(seg_id,b))
                    break;
                if(segLedOn(seg_id,c))
                    break;
                if(segLedOn(seg_id,d))
                    break;
                if(segLedOn(seg_id,f))
                    break;
                if(segLedOn(seg_id,g))
                    break;

                if(segLedOff(seg_id,e))
                    break;
                if(segLedOff(seg_id,dp))
                    break;
            errorStatus = seg_enumOk;
            break;
        }
    }
    return errorStatus;
}
static seg_enumError_t segLedOff(u8 seg_id, seg_enumLed_t seg_led_id) {
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
static seg_enumError_t segLedOn(u8 seg_id, seg_enumLed_t seg_led_id) {
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

seg_enumError_t seg_displayValueMultiSeg (u16 value) {
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
            seg_displayValueSingleSeg(i, value % 10);
        }
        errorStatus = seg_enumOk;
    }
    return errorStatus;
}
