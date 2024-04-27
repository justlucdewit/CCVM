#ifndef H_CCVM_EXECUTION
#define H_CCVM_EXECUTION

#include <stdint.h>

#include "ccvm.h"
#include "ccvm_flags.h"
#include "ccvm_registers.h"
#include "ccvm_instructions.h"

/// @brief Function that gets the current to-be-executed byte within an instance of the virtual machine, and then advances the program counter
/// @param vm An instance of the virtual machine
/// @return A single byte representing the opcode to be executed
uint8_t ccvm_get_next_byte(ccvm_virtual_machine* vm);

/// @brief Function that combines the next 8 bytes into a single 64-bit integer, and then advances the program counter
uint64_t ccvm_get_next_u64(ccvm_virtual_machine* vm);

/// @brief Function that starts the execution of the currently loaded program in an instance of the virtual machine
/// @param vm An instance of the virtual machine
/// @return The exit code of the program
uint64_t ccvm_execute_program(ccvm_virtual_machine* vm);

#endif