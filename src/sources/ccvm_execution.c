#include "../include/ccvm_execution.h"

uint8_t ccvm_get_next_instruction(ccvm_virtual_machine* vm) {
    return vm->bytecode[vm->pointer_instruction_pointer++];
}

void ccvm_execute_program(ccvm_virtual_machine* vm) {
    while (!ccvm_flag_is_enabled(vm, CCVM_FLAG_EXIT)) {
        uint8_t instruction = ccvm_get_next_instruction(vm);

        if (instruction == 0x00) {
            ccvm_flag_enable(vm, CCVM_FLAG_EXIT);
        } else if (instruction == 0xff) {
            printf("CCVM_DEBUG: \n");
            printf("REG A: 0x%lX (%ld)\n", vm->registers[CCVM_REG_A], vm->registers[CCVM_REG_A]);
            printf("REG B: 0x%lX (%ld)\n", vm->registers[CCVM_REG_B], vm->registers[CCVM_REG_B]);
            printf("REG C: 0x%lX (%ld)\n", vm->registers[CCVM_REG_C], vm->registers[CCVM_REG_C]);
            printf("REG D: 0x%lX (%ld)\n", vm->registers[CCVM_REG_D], vm->registers[CCVM_REG_D]);
        } else {
            printf("unknown instruction encountered: 0x%X\n", instruction);
        }
    }
}