#include "led_cfg.h"

ledConfigStruct_t ledCfgStructArr[NUM_LEDS] = {
    [LED_1] = {
        .ledPort = LED_1_PORT,
        .ledPin = LED_1_PIN,
        .ledActiveState = LED_1_ACTIVE, 
        .ledState = LED_1_STATE
    }
    ,[LED_2] = {
        .ledPort = LED_2_PORT,
        .ledPin = LED_2_PIN,
        .ledActiveState = LED_2_ACTIVE, 
        .ledState = LED_2_STATE
    }        
};