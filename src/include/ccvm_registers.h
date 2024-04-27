#ifndef H_CCVM_REGISTER
#define H_CCVM_REGISTER

#include "ccvm.h"

/// @brief An enum that represents the registers that the virtual machine has
typedef enum ccvm_registers {
    CCVM_REG_A = 0,
    CCVM_REG_B = 1,
    CCVM_REG_C = 2,
    CCVM_REG_D = 3,
} ccvm_registers;

/// @brief Function that gets the value of a register in an instance of the virtual machine
/// @param vm An instance of the virtual machine
/// @param register The register to get the value of
/// @return The value of the register
uint64_t ccvm_get_register(ccvm_virtual_machine* vm, ccvm_registers reg);

/// @brief Function that sets the value of a register in an instance of the virtual machine
/// @param vm An instance of the virtual machine
/// @param register The register to set the value of
/// @param value The value to set the register to
void ccvm_set_register(ccvm_virtual_machine* vm, ccvm_registers reg, uint64_t value);

#endif