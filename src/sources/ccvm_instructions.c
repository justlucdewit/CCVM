#include "../include/ccvm_instructions.h"

void ccvm_instruction_mov_reg_literal(ccvm_virtual_machine* vm) {
    uint8_t reg_index = ccvm_get_next_byte(vm);
    uint64_t value = ccvm_get_next_u64(vm);

    ccvm_set_register(vm, reg_index, value);
}

void ccvm_instruction_mov_reg_reg(ccvm_virtual_machine* vm) {
    uint8_t reg_index = ccvm_get_next_byte(vm);
    uint64_t value = ccvm_get_register(vm, ccvm_get_next_byte(vm));

    ccvm_set_register(vm, reg_index, value);
}

void ccvm_instruction_mov_reg_mem(ccvm_virtual_machine* vm) {
    uint8_t reg_index = ccvm_get_next_byte(vm);
    uint64_t memory_address = ccvm_get_next_u64(vm);

    // get the value located at the memory address
    uint64_t value = *((uint64_t*)memory_address);

    ccvm_set_register(vm, reg_index, value);
}

void ccvm_instruction_mov_mem_literal(ccvm_virtual_machine* vm) {
    uint64_t memory_address = ccvm_get_next_u64(vm);
    uint64_t value = ccvm_get_next_u64(vm);

    // set the value at the memory address
    *((uint64_t*)memory_address) = value;
}

void ccvm_instruction_mov_mem_reg(ccvm_virtual_machine* vm) {
    uint64_t memory_address = ccvm_get_next_u64(vm);
    uint8_t register_index = ccvm_get_next_byte(vm);
    uint64_t value = ccvm_get_register(vm, register_index);

    // set the value at the memory address
    *((uint64_t*)memory_address) = value;
}

void ccvm_instruction_mov_mem_mem(ccvm_virtual_machine* vm) {
    uint64_t memory_address_dest = ccvm_get_next_u64(vm);
    uint64_t memory_address_src = ccvm_get_next_u64(vm);

    // get the value located at the source memory address
    uint64_t value = *((uint64_t*)memory_address_src);

    // set the value at the destination memory address
    *((uint64_t*)memory_address_dest) = value;
}

void ccvm_instruction_push_lit(ccvm_virtual_machine* vm) {
    // Get the next 8 bytes as a 64-bit integer
    uint64_t value = ccvm_get_next_u64(vm);

    // Push the value onto the stack
    ccvm_stack_push(vm, value);
}

void ccvm_instruction_push_reg(ccvm_virtual_machine* vm) {
    // Get the register index
    uint8_t register_index = ccvm_get_next_byte(vm);

    // Get the value of that register
    uint64_t value = ccvm_get_register(vm, register_index);

    // Push the value onto the stack
    ccvm_stack_push(vm, value);    
}

void ccvm_instruction_push_mem(ccvm_virtual_machine* vm) {
    // Get the memory address
    uint64_t memory_address = ccvm_get_next_u64(vm);

    // Get the value located at the memory address
    uint64_t value = *((uint64_t*)memory_address);

    // Push the value onto the stack
    ccvm_stack_push(vm, value);
}

void ccvm_instruction_pop(ccvm_virtual_machine* vm) {
    ccvm_stack_pop(vm);
}

void ccvm_instruction_pop_register(ccvm_virtual_machine* vm) {
    uint64_t value = ccvm_stack_pop(vm);
    uint8_t register_index = ccvm_get_next_byte(vm);

    ccvm_set_register(vm, register_index, value);
}

void ccvm_instruction_pop_memory(ccvm_virtual_machine* vm) {
    uint64_t value = ccvm_stack_pop(vm);
    uint64_t memory_address = ccvm_get_next_u64(vm);

    *((uint64_t*)memory_address) = value;
}

void ccvm_instruction_swap(ccvm_virtual_machine* vm) {
    uint64_t temp1 = ccvm_stack_pop(vm);
    uint64_t temp2 = ccvm_stack_pop(vm);

    ccvm_stack_push(vm, temp1);
    ccvm_stack_push(vm, temp2);
}

void ccvm_instruction_rotate_left(ccvm_virtual_machine* vm) {
    uint64_t temp1 = ccvm_stack_pop(vm);
    uint64_t temp2 = ccvm_stack_pop(vm);
    uint64_t temp3 = ccvm_stack_pop(vm);

    ccvm_stack_push(vm, temp2);
    ccvm_stack_push(vm, temp1);
    ccvm_stack_push(vm, temp3);
}

void ccvm_instruction_rotate_right(ccvm_virtual_machine* vm) {
    uint64_t temp1 = ccvm_stack_pop(vm);
    uint64_t temp2 = ccvm_stack_pop(vm);
    uint64_t temp3 = ccvm_stack_pop(vm);

    ccvm_stack_push(vm, temp1);
    ccvm_stack_push(vm, temp3);
    ccvm_stack_push(vm, temp2);
}

void ccvm_instruction_dup(ccvm_virtual_machine* vm) {
    // pop the value, then push the same value twice
    uint64_t value = ccvm_stack_pop(vm);
    ccvm_stack_push(vm, value);
    ccvm_stack_push(vm, value);
}

void ccvm_instruction_alloc_reg_lit(ccvm_virtual_machine* vm) {
    // Get the target register and the size of the allocation
    uint8_t target_register_index = ccvm_get_next_byte(vm);
    uint64_t size_literal = ccvm_get_next_u64(vm);

    // Allocate the memory
    uint64_t memory_address = (uint64_t)malloc(size_literal);

    // Set the register to the memory address
    ccvm_set_register(vm, target_register_index, memory_address);
}

void ccvm_instruction_alloc_reg_reg(ccvm_virtual_machine* vm) {
    // Get the target register and the size of the allocation
    uint8_t target_register_index = ccvm_get_next_byte(vm);
    uint8_t size_register_index = ccvm_get_next_byte(vm);
    uint64_t size = ccvm_get_register(vm, size_register_index);

    // Allocate the memory
    uint64_t memory_address = (uint64_t)malloc(size);

    // Set the register to the memory address
    ccvm_set_register(vm, target_register_index, memory_address);
}

void ccvm_instruction_alloc_stack_lit(ccvm_virtual_machine* vm) {
    // Get the size of the allocation
    uint64_t size_literal = ccvm_get_next_u64(vm);

    // Allocate the memory
    uint64_t memory_address = (uint64_t)malloc(size_literal);

    // Push the memory address onto the stack
    ccvm_stack_push(vm, memory_address);
}

void ccvm_instruction_alloc_stack_reg(ccvm_virtual_machine* vm) {
    // Get the size of the allocation
    uint8_t size_register_index = ccvm_get_next_byte(vm);
    uint64_t size = ccvm_get_register(vm, size_register_index);

    // Allocate the memory
    uint64_t memory_address = (uint64_t)malloc(size);

    // Push the memory address onto the stack
    ccvm_stack_push(vm, memory_address);
}

void ccvm_instruction_realloc_reg_lit(ccvm_virtual_machine* vm) {
    // Get the target register and the size of the reallocation
    uint8_t target_register_index = ccvm_get_next_byte(vm);
    uint64_t size_literal = ccvm_get_next_u64(vm);

    // Get the memory address
    uint64_t memory_address = ccvm_get_register(vm, target_register_index);

    // Reallocate the memory
    memory_address = (uint64_t)realloc((void*)memory_address, size_literal);

    // Set the register to the memory address
    ccvm_set_register(vm, target_register_index, memory_address);
}

void ccvm_instruction_realloc_reg_reg(ccvm_virtual_machine* vm) {
    // Get the target register and the size of the reallocation
    uint8_t target_register_index = ccvm_get_next_byte(vm);
    uint8_t size_register_index = ccvm_get_next_byte(vm);
    uint64_t size = ccvm_get_register(vm, size_register_index);

    // Get the memory address
    uint64_t memory_address = ccvm_get_register(vm, target_register_index);

    // Reallocate the memory
    memory_address = (uint64_t)realloc((void*)memory_address, size);

    // Set the register to the memory address
    ccvm_set_register(vm, target_register_index, memory_address);
}

void ccvm_instruction_realloc_stack_lit(ccvm_virtual_machine* vm) {
    // Get the size of the reallocation
    uint64_t size_literal = ccvm_get_next_u64(vm);

    // Pop the memory address
    uint64_t memory_address = ccvm_stack_pop(vm);

    // Reallocate the memory
    memory_address = (uint64_t)realloc((void*)memory_address, size_literal);

    // Push the memory address back onto the stack
    ccvm_stack_push(vm, memory_address);
}

void ccvm_instruction_realloc_stack_reg(ccvm_virtual_machine* vm) {
    // Get the size of the reallocation
    uint8_t size_register_index = ccvm_get_next_byte(vm);
    uint64_t size = ccvm_get_register(vm, size_register_index);

    // Pop the memory address
    uint64_t memory_address = ccvm_stack_pop(vm);

    // Reallocate the memory
    memory_address = (uint64_t)realloc((void*)memory_address, size);

    // Push the memory address back onto the stack
    ccvm_stack_push(vm, memory_address);
}

void ccvm_instruction_free_reg(ccvm_virtual_machine* vm) {
    // Get the register index
    uint8_t register_index = ccvm_get_next_byte(vm);

    // Get the value of that register
    uint64_t value = ccvm_get_register(vm, register_index);

    // Free the value
    free((void*)value);
}

void ccvm_instruction_free_stack(ccvm_virtual_machine* vm) {
    // Pop the value from the stack
    uint64_t value = ccvm_stack_pop(vm);

    // Free the value
    free((void*)value);
}

void ccvm_instruction_math_add_stack(ccvm_virtual_machine* vm) {
    // Pop the top two values from the stack
    uint64_t value1 = ccvm_stack_pop(vm);
    uint64_t value2 = ccvm_stack_pop(vm);

    // Add the values together and push the result onto the stack
    ccvm_stack_push(vm, value1 + value2);
}

void ccvm_instruction_bytecode_base_address_stack(ccvm_virtual_machine* vm) {
    // Push the base address of the bytecode onto the stack
    ccvm_stack_push(vm, (uint64_t)vm->bytecode);
}

void ccvm_instruction_debug(ccvm_virtual_machine* vm) {
    printf("Debug Information:\n");

    // Instruction Pointer debug information
    printf("Instruction Pointer: 0x%lX (%ld)\n\n", vm->pointer_instruction_pointer, vm->pointer_instruction_pointer);

    // Register debug information
    printf("REG A: 0x%lX (%ld)\n", vm->registers[CCVM_REG_A], vm->registers[CCVM_REG_A]);
    printf("REG B: 0x%lX (%ld)\n", vm->registers[CCVM_REG_B], vm->registers[CCVM_REG_B]);
    printf("REG C: 0x%lX (%ld)\n", vm->registers[CCVM_REG_C], vm->registers[CCVM_REG_C]);
    printf("REG D: 0x%lX (%ld)\n\n", vm->registers[CCVM_REG_D], vm->registers[CCVM_REG_D]);

    // Flag debug information
    printf("Flags: 0x%X\n", vm->flags);
    printf("EXIT: %d\n", ccvm_flag_is_enabled(vm, CCVM_FLAG_EXIT));
    printf("DEBUG: %d\n", ccvm_flag_is_enabled(vm, CCVM_FLAG_DEBUG));
    printf("EQUAL: %d\n", ccvm_flag_is_enabled(vm, CCVM_FLAG_EQUAL));
    printf("SMALLER: %d\n", ccvm_flag_is_enabled(vm, CCVM_FLAG_SMALLER));
    printf("GREATER: %d\n", ccvm_flag_is_enabled(vm, CCVM_FLAG_GREATER));
    printf("ZERO: %d\n\n", ccvm_flag_is_enabled(vm, CCVM_FLAG_ZERO));

    // Stack debug information
    printf("Stack Length: %ld\n", vm->stack.length);
    printf("Stack Capacity: %ld\n", vm->stack.capacity);
    printf("Stack Data: ");
    for (int i = 0; i < vm->stack.length; i++) {
        printf("%ld ", vm->stack.data[i]);
    }
    printf("\n\n");
}

void ccvm_instruction_exit(ccvm_virtual_machine* vm) {
    ccvm_flag_enable(vm, CCVM_FLAG_EXIT);
}