#include "../../01_MCAL/01_PORT/port.h"
#include "../../01_MCAL/00_DIO/dio.h"
#include "led.h"
#include "led_cfg.h"


extern ledConfigStruct_t ledCfgStructArr [NUM_LEDS];

led_enumError_t ledInit(void) {
    led_enumError_t errorStatus = led_enumNotOk;
    port_configStruct_t current_led;
    for(u8 i = 0; i < NUM_LEDS; i++) {
        errorStatus = led_enumNotOk;
        if(ledCfgStructArr[i].ledActiveState > led_activeHigh) {
            errorStatus = led_enumWrongActiveState;
            break;
        }
        else if(ledCfgStructArr[i].ledState > led_on) {
            errorStatus = led_enumWrongState;
            break;
        }
        else {
            current_led.port_ID = ledCfgStructArr[i].ledPort;
            current_led.pin_ID = ledCfgStructArr[i].ledPin;
            current_led.pinCfg.pinDir = pin_enumOutput;
            switch(ledCfgStructArr[i].ledActiveState) {
                case led_activeHigh:
                    switch(ledCfgStructArr[i].ledState) {
                        case led_on:
                            current_led.pinCfg.pinState = pin_enumActive;
                        break;
                        case led_off:
                            current_led.pinCfg.pinState = pin_enumInactive;
                        break;
                    }                    
                break;
                case led_activeLow:
                    switch(ledCfgStructArr[i].ledState) {
                        case led_on:
                            current_led.pinCfg.pinState = pin_enumInactive;
                        break;
                        case led_off:
                            current_led.pinCfg.pinState = pin_enumActive;
                        break;
                    }
                break;
            }         
            if(!port_setCfg(&current_led)) {
                errorStatus = led_enumOk;
            }                        
        }
    }
    return errorStatus;
}


led_enumError_t ledOn(u8 led_id) {
    led_enumError_t errorStatus = led_enumNotOk;
    if(led_id >= NUM_LEDS) {
        errorStatus = led_enumLedOutOfBounds;
    }
    else {
        switch(ledCfgStructArr[led_id].ledActiveState) {
            case led_activeHigh:
                if(!DIO_enumSetPin(ledCfgStructArr[led_id].ledPort,ledCfgStructArr[led_id].ledPin,DIO_enumLogicHigh)) {
                    errorStatus = led_enumOk;
                }                
            break;
            case led_activeLow:
                if(!DIO_enumSetPin(ledCfgStructArr[led_id].ledPort,ledCfgStructArr[led_id].ledPin,DIO_enumLogicLow)) {
                    errorStatus = led_enumOk;
                }
            break;
        }
    }
    return errorStatus;
}

led_enumError_t ledOff(u8 led_id) {
    led_enumError_t errorStatus = led_enumNotOk;
    if(led_id >= NUM_LEDS) {
        errorStatus = led_enumLedOutOfBounds;
    }
    else {
        errorStatus = led_enumOk;
        switch(ledCfgStructArr[led_id].ledActiveState) {
            case led_activeHigh:
                if(!DIO_enumSetPin(ledCfgStructArr[led_id].ledPort,ledCfgStructArr[led_id].ledPin,DIO_enumLogicLow)) {
                    errorStatus = led_enumOk;
                }
            break;
            case led_activeLow:
                if(!DIO_enumSetPin(ledCfgStructArr[led_id].ledPort,ledCfgStructArr[led_id].ledPin,DIO_enumLogicHigh)) {
                    errorStatus = led_enumOk;
                }
            break;
        }
    }
    return errorStatus;
}