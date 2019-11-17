#ifndef __SERIAL_INTERFACE__H
#define __SERIAL_INTERFACE__H

#include <stdint.h>

#include "TASRun.h"

typedef enum
{
	SERIAL_COMPLETE,
	SERIAL_PREFIX,
	SERIAL_SETUP,
	SERIAL_CONSOLE,
	SERIAL_NUM_CONTROLLERS,
	SERIAL_CONTROLLER_DATA_CONTINUE,
	SERIAL_CONTROLLER_DATA_START,
	SERIAL_SETTINGS,
	SERIAL_TRANSITION,
	SERIAL_POWER,
	SERIAL_BULK,
	SERIAL_LANE,
	SERIAL_CMD_Q_1,
	SERIAL_CMD_Q_2,
	SERIAL_TRANSITION_1,
	SERIAL_TRANSITION_2,
	SERIAL_TRANSITION_3,
} SerialInterfaceState;

typedef enum
{
	RUN_NONE=-1,
	RUN_A=0,
	RUN_B=1,
	RUN_C=2,
	RUN_D=3
} SerialRun;

typedef uint8_t (*OutputFunction)(uint8_t *buffer, uint16_t n);

typedef struct {
	SerialInterfaceState state;
	SerialRun selected_run;
	OutputFunction output_func;
	uint8_t controller_data_buffer[sizeof(RunData) * MAX_CONTROLLERS * MAX_DATA_LANES];
	uint32_t controller_data_bytes_read;
} serial_interface_state_t;

void serial_interface_reset();
void serial_interface_set_output_function(OutputFunction func);
uint8_t serial_interface_output(uint8_t *buffer, uint16_t n);
void serial_interface_consume(uint8_t byte);

#endif  // __INPUT_PROCESSOR__H
