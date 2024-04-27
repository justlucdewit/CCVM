#include "../include/ccvm_execution.h"

uint8_t ccvm_get_next_byte(ccvm_virtual_machine* vm) {
    return vm->bytecode[vm->pointer_instruction_pointer++];
}

uint64_t ccvm_get_next_u64(ccvm_virtual_machine* vm) {
    uint64_t value = 0;

    // Combine the next 8 bytes into a single 64-bit integer, read it in big-endian order
    for (int i = 0; i < 8; i++) {
        value |= (uint64_t)ccvm_get_next_byte(vm) << (8 * (7 - i));
    }

    return value;
}

uint64_t ccvm_execute_program(ccvm_virtual_machine* vm) {
    while (!ccvm_flag_is_enabled(vm, CCVM_FLAG_EXIT)) {
        uint8_t instruction = ccvm_get_next_byte(vm);

        printf("the current instruction is: 0x%X\n", instruction);

        // =====================================================================
        // =                     Memory management opcodes                     =
        // =====================================================================
        if (instruction == 0x00)
            ccvm_instruction_mov_reg_literal(vm);
        else if (instruction == 0x01)
            ccvm_instruction_mov_reg_reg(vm);
        else if (instruction == 0x02)
            ccvm_instruction_mov_reg_mem(vm);
        else if (instruction == 0x03)
            ccvm_instruction_mov_mem_literal(vm);
        else if (instruction == 0x04)
            ccvm_instruction_mov_mem_reg(vm);
        else if (instruction == 0x05)
            ccvm_instruction_mov_mem_mem(vm);
        else if (instruction == 0x06)
            ccvm_instruction_push_lit(vm);
        else if (instruction == 0x07)
            ccvm_instruction_push_reg(vm);
        else if (instruction == 0x08)
            ccvm_instruction_push_mem(vm);
        else if (instruction == 0x09)
            ccvm_instruction_pop(vm);
        else if (instruction == 0x0A)
            ccvm_instruction_pop_register(vm);
        else if (instruction == 0x0B)
            ccvm_instruction_pop_memory(vm);
        else if (instruction == 0x0C)
            ccvm_instruction_swap(vm);
        else if (instruction == 0x0D)
            ccvm_instruction_rotate_left(vm);
        else if (instruction == 0x0E)
            ccvm_instruction_rotate_right(vm);
        else if (instruction == 0x0F)
            ccvm_instruction_dup(vm);

        // =====================================================================
        // =                     Memory management opcodes                     =
        // =====================================================================
        
        // =====================================================================
        // =                     Mathematical opcodes                          =
        // =====================================================================
        else if (instruction == 0x30)
            ccvm_instruction_math_add_stack(vm);

        // =====================================================================
        // =                     Other opcodes                                 =
        // =====================================================================
        else if (instruction == 0xFC)
            ccvm_instruction_bytecode_base_address_stack(vm);
        else if (instruction == 0xFE)
            ccvm_instruction_debug(vm);
        else if (instruction == 0xFF)
            ccvm_instruction_exit(vm);
        else {
            printf("unknown instruction encountered: 0x%X\n", instruction);
            exit(-1);
        }
    }

    return vm->registers[ccvm_stack_pop(vm)];
}
