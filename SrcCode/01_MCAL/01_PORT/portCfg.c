#include "portCfg.h"
#include "std_types.h"

#if (CONFIGURATION_STYLE == PRE_COMPILE)

#elif (CONFIGURATION_STYLE == POST_COMPILE)

    pinConfigStruct_t portConfigArr [PORTS_NUM][8] = {
    #if ((PORTS_NUM == PORT_A)||(PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
        [port_enumPortA] = {
            [port_enumP0] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumActive
            }
            ,[port_enumP1] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumActive
            }
            ,[port_enumP2] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumActive
            }
            ,[port_enumP3] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumActive
            }
            ,[port_enumP4] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumActive
            }
            ,[port_enumP5] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumActive
            }
            ,[port_enumP6] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumActive
            }
            ,[port_enumP7] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumActive
            }
        }
    #endif

    #if ((PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
        ,[port_enumPortB] = {
            [port_enumP0] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP1] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP2] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP3] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP4] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP5] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP6] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP7] = {
                .pinConfig = pin_enumOutput,
                .pinState = pin_enumInactive
            }
        }
    #endif

    #if ((PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
        ,[port_enumPortC] = {
            [port_enumP0] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP1] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP2] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP3] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP4] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP5] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP6] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumInactive
            }
            ,[port_enumP7] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumInactive
            }
        }
    #endif

    #if (PORTS_NUM == PORTS_A_B_C_D)
        ,[port_enumPortD] = {
            [port_enumP0] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumActive
            }
            ,[port_enumP1] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumActive
            }
            ,[port_enumP2] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumActive
            }
            ,[port_enumP3] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumActive
            }
            ,[port_enumP4] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumActive
            }
            ,[port_enumP5] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumActive
            }
            ,[port_enumP6] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumActive
            }
            ,[port_enumP7] = {
                .pinConfig = pin_enumInput,
                .pinState = pin_enumActive
            }
        }
    #endif
    };

#else
    #error "no config style specified"
#endif

