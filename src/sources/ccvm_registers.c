#include "../include/ccvm_registers.h"

uint64_t ccvm_get_register(ccvm_virtual_machine* vm, ccvm_registers reg) {
    return vm->registers[reg];
}

void ccvm_set_register(ccvm_virtual_machine* vm, ccvm_registers reg, uint64_t value) {
    vm->registers[reg] = value;
}