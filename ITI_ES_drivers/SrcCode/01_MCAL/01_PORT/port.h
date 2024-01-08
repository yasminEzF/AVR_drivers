#ifndef PORT_H_
#define PORT_H_

typedef enum {
#if ((PORTS_NUM == PORT_A)||(PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
	port_enumPortA = 1,
#endif
#if ((PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
	port_enumPortB,
#endif
#if ((PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
	port_enumPortC,
#endif
#if (PORTS_NUM == PORTS_A_B_C_D)
	port_enumPortD
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

typedef enum
{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly
	 */
	port_enumOk = 0,
	/**
	 *@brief : NULL Pointer is passed
	 */
	port_enumNullPointer,
	/**
	 *@brief : Select Port Not exist  
	 */
	port_enumWrongPort,
	/**
	 *@brief : Select Pin Not exist  
	 */
	port_enumWrongPin,
	/**
	 *@brief : Select Configuration type Not Found 
	 */
	port_enumWrongConfig,
	/**
	 *@brief : Select pin state type Not Found 
	 */
	port_enumWrongPinState,
	/**
	 *@brief : generalized error
	 */
	port_enumNotOk

}port_enumError_t;

typedef enum {
	/**
	 *@brief : Select Pin Configuration to be Output.
	 */
	pin_enumOutput = 0,
	/**
	 *@brief : Select Pin Configuration to be Input.
	 */
	pin_enumInput
}pin_enumDir_t;

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
	pin_enumDir_t pinDir;
	pin_enumState_t pinState;
}port_pinConfigStruct_t;

typedef struct {
    port_enumPorts_t port_ID;
    port_enumPins_t pin_ID;
    port_pinConfigStruct_t pinCfg;
}port_configStruct_t;

void portInit(void);

port_enumError_t port_setCfg(port_configStruct_t* cfgPtr);

#endif /* PORT_H_ */
