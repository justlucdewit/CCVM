#ifndef H_CCVM_EXECUTION
#define H_CCVM_EXECUTION

#include <stdint.h>

#include "ccvm.h"
#include "ccvm_flags.h"
#include "ccvm_registers.h"

/// @brief Function that gets the current to-be-executed instruction within an instance of the virtual machine, and then advances the program counter
/// @param vm An instance of the virtual machine
/// @return A single byte representing the opcode to be executed
uint8_t ccvm_get_next_instruction(ccvm_virtual_machine* vm);

/// @brief Function that starts the execution of the currently loaded program in an instance of the virtual machine
/// @param vm An instance of the virtual machine
void ccvm_execute_program(ccvm_virtual_machine* vm);

#endif