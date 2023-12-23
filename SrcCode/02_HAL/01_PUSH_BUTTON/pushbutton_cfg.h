#ifndef PUSH_BUTTON_CFG_H_
#define PUSH_BUTTON_CFG_H_

#include "01_PORT/port.h"

#define NUM_PB          2

#define PB_1            0
#define PB_1_PORT       port_enumPortC
#define PB_1_PIN        port_enumP0
#define PB_1_STATE      pb_externalPD

#define PB_2           1
#define PB_2_PORT      port_enumPortC
#define PB_2_PIN       port_enumP1
#define PB_2_STATE     pb_internalPU

typedef enum {
    pb_externalPD = 0,
    pb_internalPU
}PBEnumState_t;

typedef struct {
    port_enumPorts_t pb_Port;
    port_enumPins_t pb_Pin;
    PBEnumState_t pb_ActiveState;
}PBConfigStruct_t;


#endif