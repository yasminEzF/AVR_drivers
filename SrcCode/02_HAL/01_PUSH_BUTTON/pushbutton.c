#include "../../01_MCAL/01_PORT/port.h"
#include "../../01_MCAL/00_DIO/dio.h"
#include "pushbutton_cfg.h"
#include "pushbutton.h"

extern PBConfigStruct_t pbCfgStructArr [NUM_PB];

pb_enumError_t PB_Init(void) {
    pb_enumError_t errorStatus = pb_enumNotOk;
    port_configStruct_t current_pb;
    for(u8 i = 0; i < NUM_PB; i++) {
        errorStatus = pb_enumNotOk;
        if(pbCfgStructArr[i].pb_ActiveState > pb_internalPU) {
            errorStatus = pb_enumWrongActiveState;
        }
        else {
            current_pb.port_ID = pbCfgStructArr[i].pb_Port;
            current_pb.pin_ID = pbCfgStructArr[i].pb_Pin;
            current_pb.pinCfg.pinDir = pin_enumInput;
            switch(pbCfgStructArr[i].pb_ActiveState) {
                case pb_externalPD:     /* Active high */
                    current_pb.pinCfg.pinState = pin_enumInactive;                    
                break;
                case pb_internalPU:      /* Active low */
                    current_pb.pinCfg.pinState = pin_enumActive;
                break;
            }         
            if(!port_setCfg(&current_pb)) {
                errorStatus = pb_enumOk;
            }                        
        }
    }
    return errorStatus;
}

pb_enumError_t PB_ReadState(u8 pb_id, u8* pb_state) {
    pb_enumError_t errorStatus = pb_enumNotOk;
    if(pb_id >= NUM_PB) {
            errorStatus = pb_enumPBOutOfBounds;
    }
    else {
        u8 temp = NULL;
        if(!(DIO_enumReadState(pbCfgStructArr[pb_id].pb_Port, pbCfgStructArr[pb_id].pb_Pin, &temp))) {
            errorStatus = pb_enumOk;
            switch(pbCfgStructArr[pb_id].pb_ActiveState) {
                case pb_externalPD:     
                    switch (temp) {
                        case DIO_enumLogicHigh:
                            *pb_state = pb_pressed;
                        break;
                        case DIO_enumLogicLow:
                            *pb_state = pb_notPressed;
                        break;
                    }                    
                break;
                case pb_internalPU:
                    switch(temp) {
                        case DIO_enumLogicHigh:
                            *pb_state = pb_notPressed;
                        break;
                        case DIO_enumLogicLow:
                            *pb_state = pb_pressed;
                        break;
                    }                   
                break;
            }
        }
    }
    return errorStatus;
}


