#include "7_seg_cfg.h"

segConfigStruct_t segCfgStructArr[NUM_SEG] = {
    [SEG_1] = {
        .segPinsArr = {
            [a] = {
                .port_id = SEG_1_A_PORT,
                .pin_id = SEG_1_A_PIN
            },
            [b] = {
                .port_id = SEG_1_B_PORT,
                .pin_id = SEG_1_B_PIN
            },
            [c] = {
                .port_id = SEG_1_C_PORT,
                .pin_id = SEG_1_C_PIN
            },
            [d] = {
                .port_id = SEG_1_D_PORT,
                .pin_id = SEG_1_D_PIN
            },
            [e] = {
                .port_id = SEG_1_E_PORT,
                .pin_id = SEG_1_E_PIN
            },
            [f] = {
                .port_id = SEG_1_F_PORT,
                .pin_id = SEG_1_F_PIN
            },
            [g] = {
                .port_id = SEG_1_G_PORT,
                .pin_id = SEG_1_G_PIN
            },
            [dp] = {
                .port_id = SEG_1_DP_PORT,
                .pin_id = SEG_1_DP_PIN
            }
        },
        .segCommon = SEG_1_COMMON
    },
	[SEG_2] = {
		.segPinsArr = {
			[a] = {
				.port_id = SEG_2_A_PORT,
				.pin_id = SEG_2_A_PIN
			},
			[b] = {
				.port_id = SEG_2_B_PORT,
				.pin_id = SEG_2_B_PIN
			},
			[c] = {
				.port_id = SEG_2_C_PORT,
				.pin_id = SEG_2_C_PIN
			},
			[d] = {
				.port_id = SEG_2_D_PORT,
				.pin_id = SEG_2_D_PIN
			},
			[e] = {
				.port_id = SEG_2_E_PORT,
				.pin_id = SEG_2_E_PIN
			},
			[f] = {
				.port_id = SEG_2_F_PORT,
				.pin_id = SEG_2_F_PIN
			},
			[g] = {
				.port_id = SEG_2_G_PORT,
				.pin_id = SEG_2_G_PIN
			},
			[dp] = {
				.port_id = SEG_2_DP_PORT,
				.pin_id = SEG_2_DP_PIN
			}
		},
		.segCommon = SEG_2_COMMON
	}        
};