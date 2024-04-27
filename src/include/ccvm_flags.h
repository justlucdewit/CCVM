#ifndef H_CCVM_FLAGS
#define H_CCVM_FLAGS

#include <stdint.h>

#include "ccvm.h"

/// @brief An enum that represents the flags that the virtual machine can have
typedef enum ccvm_flag {
    CCVM_FLAG_EXIT    = 0b00000001,
    CCVM_FLAG_DEBUG   = 0b00000010,
    CCVM_FLAG_EQUAL   = 0b00000100,
    CCVM_FLAG_SMALLER = 0b00001000,
    CCVM_FLAG_GREATER = 0b00010000,
    CCVM_FLAG_ZERO    = 0b00100000
} ccvm_flag;

/// @brief Function that checks if a flag is enabled in an instance of the virtual machine
/// @param vm An instance of the virtual machine
/// @param flag The flag to check if it is enabled
/// @return 1 if the flag is enabled, 0 if it is not
uint8_t ccvm_flag_is_enabled(ccvm_virtual_machine* vm, ccvm_flag flag);

/// @brief Function that enables a flag in an instance of the virtual machine
/// @param vm An instance of the virtual machine
/// @param flag The flag to enable
void ccvm_flag_enable(ccvm_virtual_machine* vm, ccvm_flag flag);

/// @brief Function that disables a flag in an instance of the virtual machine
/// @param vm An instance of the virtual machine
/// @param flag The flag to disable
void ccvm_flag_disable(ccvm_virtual_machine* vm, ccvm_flag flag);

#endif