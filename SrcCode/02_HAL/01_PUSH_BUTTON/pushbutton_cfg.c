#include "pushbutton_cfg.h"

PBConfigStruct_t pb_CfgStructArr[NUM_PB] = {
    [PB_1] = {
        .pb_Port = PB_1_PORT,
        .pb_Pin = PB_1_PIN,
        .pb_ActiveState = PB_1_STATE
    }
    ,[PB_2] = {
        .pb_Port = PB_2_PORT,
        .pb_Pin = PB_2_PIN,
        .pb_ActiveState = PB_2_STATE
    }        
};