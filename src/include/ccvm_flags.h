#ifndef H_CCVM_FLAGS
#define H_CCVM_FLAGS

#include <stdint.h>

#include "ccvm.h"

typedef enum ccvm_flag {
    CCVM_FLAG_EXIT    = 0b00000001,
    CCVM_FLAG_DEBUG   = 0b00000010,
    CCVM_FLAG_EQUAL   = 0b00000100,
    CCVM_FLAG_SMALLER = 0b00001000,
    CCVM_FLAG_GREATER = 0b00010000,
    CCVM_FLAG_ZERO    = 0b00100000
} ccvm_flag;

uint8_t ccvm_flag_is_enabled(ccvm_virtual_machine* vm, ccvm_flag flag);

uint8_t ccvm_flag_enable(ccvm_virtual_machine* vm, ccvm_flag flag);

void ccvm_flag_disable(ccvm_virtual_machine* vm, ccvm_flag flag);

#endif