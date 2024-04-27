#include "../include/ccvm_flags.h"

uint8_t ccvm_flag_is_enabled(ccvm_virtual_machine* vm, ccvm_flag flag) {
    return vm->flags & flag;
}

void ccvm_flag_enable(ccvm_virtual_machine* vm, ccvm_flag flag) {
    vm->flags = vm->flags | flag;
}

void ccvm_flag_disable(ccvm_virtual_machine* vm, ccvm_flag flag) {
    vm->flags = vm->flags & ~flag;
}