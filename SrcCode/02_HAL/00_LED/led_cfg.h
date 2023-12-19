#ifndef LED_CFG_H_
#define LED_CFG_H_

#include "01_PORT/port.h"

#define NUM_LEDS        2

#define LED_1           0
#define LED_1_PORT      port_enumPortA
#define LED_1_PIN       port_enumP0
#define LED_1_ACTIVE    led_activeHigh
#define LED_1_STATE     led_off

#define LED_2           1
#define LED_2_PORT      port_enumPortA
#define LED_2_PIN       port_enumP1
#define LED_2_ACTIVE    led_activeLow
#define LED_2_STATE     led_on

typedef enum {
    led_off = 0,
    led_on
}led_configEnumState_t;

typedef enum {
    led_activeLow = 0,
    led_activeHigh
}led_configEnumActive_t;

typedef struct {
    port_enumPorts_t ledPort;
    port_enumPins_t ledPin;
    led_configEnumActive_t ledActiveState; 
    led_configEnumState_t ledState;
}ledConfigStruct_t;


#endif