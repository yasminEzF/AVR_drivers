#ifndef PORTCFG_H_
#define PORTCFG_H_

#include "std_types.h"

/*  choose pre or post compile  */
#define CONFIGURATION_STYLE      POST_COMPILE		/*configuration style*/

#define PRE_COMPILE         0
#define POST_COMPILE        1

/*  pre compile configurations  */
#define PORTS_NUM           PORTS_A_B_C_D/*number of ports to be used*/

#define PORT_A              1
#define PORTS_A_B           2
#define PORTS_A_B_C         3
#define PORTS_A_B_C_D       4

#define OUTPUT_PIN				1
#define INPUT_PIN				0

#define OUTPUT_LOW_PIN          0
#define OUTPUT_HIGH_PIN         1

#define IP_INTERNAL_PU_PIN      1
#define IP_EXTERNAL_PD_PIN      0

#define PA0_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PA0_STATE          		OUTPUT_LOW_PIN		/*desired pin state*/
#define PA1_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PA1_STATE          		OUTPUT_LOW_PIN		/*desired pin state*/
#define PA2_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PA2_STATE          		OUTPUT_LOW_PIN		/*desired pin state*/
#define PA3_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PA3_STATE          		OUTPUT_LOW_PIN		/*desired pin state*/
#define PA4_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PA4_STATE          		OUTPUT_LOW_PIN		/*desired pin state*/
#define PA5_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PA5_STATE          		OUTPUT_LOW_PIN		/*desired pin state*/
#define PA6_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PA6_STATE          		OUTPUT_LOW_PIN		/*desired pin state*/
#define PA7_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PA7_STATE          		OUTPUT_LOW_PIN		/*desired pin state*/

#define PB0_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PB0_STATE          		OUTPUT_HIGH_PIN		/*desired pin state*/
#define PB1_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PB1_STATE          		OUTPUT_HIGH_PIN		/*desired pin state*/
#define PB2_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PB2_STATE          		OUTPUT_HIGH_PIN		/*desired pin state*/
#define PB3_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PB3_STATE          		OUTPUT_HIGH_PIN		/*desired pin state*/
#define PB4_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PB4_STATE          		OUTPUT_HIGH_PIN		/*desired pin state*/
#define PB5_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PB5_STATE          		OUTPUT_HIGH_PIN		/*desired pin state*/
#define PB6_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PB6_STATE          		OUTPUT_HIGH_PIN		/*desired pin state*/
#define PB7_DIRECTION           OUTPUT_PIN			/*desired pin direction*/
#define PB7_STATE          		OUTPUT_HIGH_PIN		/*desired pin state*/

#define PC0_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PC0_STATE          		IP_EXTERNAL_PD_PIN		/*desired pin state*/
#define PC1_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PC1_STATE          		IP_EXTERNAL_PD_PIN		/*desired pin state*/
#define PC2_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PC2_STATE          		IP_EXTERNAL_PD_PIN		/*desired pin state*/
#define PC3_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PC3_STATE          		IP_EXTERNAL_PD_PIN		/*desired pin state*/
#define PC4_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PC4_STATE          		IP_EXTERNAL_PD_PIN		/*desired pin state*/
#define PC5_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PC5_STATE          		IP_EXTERNAL_PD_PIN		/*desired pin state*/
#define PC6_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PC6_STATE          		IP_EXTERNAL_PD_PIN		/*desired pin state*/
#define PC7_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PC7_STATE          		IP_EXTERNAL_PD_PIN		/*desired pin state*/

#define PD0_DIRECTION    		INPUT_PIN			/*desired pin direction*/
#define PD0_STATE          		IP_INTERNAL_PU_PIN		/*desired pin state*/
#define PD1_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PD1_STATE          		IP_INTERNAL_PU_PIN		/*desired pin state*/
#define PD2_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PD2_STATE          		IP_INTERNAL_PU_PIN		/*desired pin state*/
#define PD3_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PD3_STATE          		IP_INTERNAL_PU_PIN		/*desired pin state*/
#define PD4_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PD4_STATE          		IP_INTERNAL_PU_PIN		/*desired pin state*/
#define PD5_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PD5_STATE          		IP_INTERNAL_PU_PIN		/*desired pin state*/
#define PD6_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PD6_STATE          		IP_INTERNAL_PU_PIN		/*desired pin state*/
#define PD7_DIRECTION           INPUT_PIN			/*desired pin direction*/
#define PD7_STATE          		IP_INTERNAL_PU_PIN		/*desired pin state*/

/*  post compile configurations */

typedef enum {
#if ((PORTS_NUM == PORT_A)||(PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
	port_enumPortA = 0
#endif
#if ((PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
	,port_enumPortB
#endif
#if ((PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
	,port_enumPortC
#endif
#if (PORTS_NUM == PORTS_A_B_C_D)
	,port_enumPortD
#endif
}port_enumPorts_t;

typedef enum
{
	port_enumP0 = 0,
	port_enumP1,
	port_enumP2,
	port_enumP3,
	port_enumP4,
	port_enumP5,
	port_enumP6,
	port_enumP7
}port_enumPins_t;

typedef enum {
	/**
	 *@brief : Select Pin Configuration to be Output.
	 */
	pin_enumOutput = 0,
	/**
	 *@brief : Select Pin Configuration to be Input.
	 */
	pin_enumInput
}pin_enumConfig_t;

typedef enum {
	/**
	 *@brief : Select Pin Configuration to be Low.
	 * incase input : 	input external pulldown
	 * incase output :	output low
	 */
	pin_enumInactive = 0,
	/**
	 *@brief : Select Pin Configuration to be High.
	 * incase input : 	input internal pullup
	 * incase output :	output high
	 */
	pin_enumActive
}pin_enumState_t;

typedef struct {
	pin_enumConfig_t pinConfig;
	pin_enumState_t pinState;
}pinConfigStruct_t;

#endif /* PORTCFG_H_ */