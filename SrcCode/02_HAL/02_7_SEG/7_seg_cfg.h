#ifndef SEG_CFG_H_
#define SEG_CFG_H_

#include "../../01_MCAL/01_PORT/port.h"

/**
 *         a
 *      -------
 *     |       |
 *   f |       | b
 *     |   g   |
 *      -------
 *     |       |
 *   e |       | c
 *     |   d   |
 *      -------   . dp
*/

#define NUM_SEG           2

#define SEG_1             0
#define SEG_1_A_PORT      port_enumPortA
#define SEG_1_A_PIN       port_enumP0
#define SEG_1_B_PORT      port_enumPortA
#define SEG_1_B_PIN       port_enumP1
#define SEG_1_C_PORT      port_enumPortA
#define SEG_1_C_PIN       port_enumP2
#define SEG_1_D_PORT      port_enumPortA
#define SEG_1_D_PIN       port_enumP3
#define SEG_1_E_PORT      port_enumPortA
#define SEG_1_E_PIN       port_enumP4
#define SEG_1_F_PORT      port_enumPortA
#define SEG_1_F_PIN       port_enumP5
#define SEG_1_G_PORT      port_enumPortA
#define SEG_1_G_PIN       port_enumP6
#define SEG_1_DP_PORT     port_enumPortA
#define SEG_1_DP_PIN      port_enumP7

#define SEG_1_COMMON      seg_enumCommonAnode

#define SEG_2             1
#define SEG_2_A_PORT      port_enumPortB
#define SEG_2_A_PIN       port_enumP0
#define SEG_2_B_PORT      port_enumPortB
#define SEG_2_B_PIN       port_enumP1
#define SEG_2_C_PORT      port_enumPortB
#define SEG_2_C_PIN       port_enumP2
#define SEG_2_D_PORT      port_enumPortB
#define SEG_2_D_PIN       port_enumP3
#define SEG_2_E_PORT      port_enumPortB
#define SEG_2_E_PIN       port_enumP4
#define SEG_2_F_PORT      port_enumPortB
#define SEG_2_F_PIN       port_enumP5
#define SEG_2_G_PORT      port_enumPortB
#define SEG_2_G_PIN       port_enumP6
#define SEG_2_DP_PORT     port_enumPortB
#define SEG_2_DP_PIN      port_enumP7

#define SEG_2_COMMON      seg_enumCommonAnode


//#define seg1 initial value 0~9

typedef enum {
    a = 0,
    b,
    c,
    d,
    e,
    f,
    g,
    dp
}seg_enumLed_t;

typedef enum {
    seg_enumCommonAnode = 0,
    seg_enumCommonCathode
}seg_enumCommon_t;

typedef struct {
    port_enumPorts_t port_id;
    port_enumPins_t pin_id;
}segPinConfigStruct_t;

typedef struct {
    segPinConfigStruct_t segPinsArr[8];
    seg_enumCommon_t segCommon;
    //initial
}segConfigStruct_t;

#endif