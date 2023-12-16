#include "portCfg.h"

#if (CONFIGURATION_STYLE == PRE_COMPILE)

#elif (CONFIGURATION_STYLE == POST_COMPILE)

    pinCfgConfigStruct_t portConfigArr [PORTS_NUM][8] = {
    #if ((PORTS_NUM == PORT_A)||(PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
        [portCfg_enumPortA] = {
            [portCfg_enumP0] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP1] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP2] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP3] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP4] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP5] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP6] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP7] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumActive
            }
        }
    #endif

    #if ((PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
        ,[portCfg_enumPortB] = {
            [portCfg_enumP0] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP1] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP2] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP3] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP4] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP5] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP6] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP7] = {
                .pinConfig = pinCfg_enumOutput,
                .pinState = pinCfg_enumInactive
            }
        }
    #endif

    #if ((PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
        ,[portCfg_enumPortC] = {
            [portCfg_enumP0] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP1] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP2] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP3] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP4] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP5] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP6] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumInactive
            }
            ,[portCfg_enumP7] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumInactive
            }
        }
    #endif

    #if (PORTS_NUM == PORTS_A_B_C_D)
        ,[portCfg_enumPortD] = {
            [portCfg_enumP0] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP1] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP2] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP3] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP4] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP5] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP6] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumActive
            }
            ,[portCfg_enumP7] = {
                .pinConfig = pinCfg_enumInput,
                .pinState = pinCfg_enumActive
            }
        }
    #endif
    };

#else
    #error "no config style specified"
#endif

