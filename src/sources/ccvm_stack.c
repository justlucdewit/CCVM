#include "../include/ccvm_stack.h"

void ccvm_stack_initialize(ccvm_virtual_machine* vm) {
    // Initialize the stack with a capacity of 1024
    vm->stack.data = (uint64_t*)malloc(1024 * sizeof(uint64_t));
    vm->stack.capacity = 1024;
    vm->stack.length = 0;
}

void ccvm_stack_push(ccvm_virtual_machine* vm, uint64_t value) {
    // Check if the stack is full
    if (vm->stack.length == vm->stack.capacity) {
        // Resize the stack
        vm->stack.capacity *= 2;
        vm->stack.data = (uint64_t*)realloc(vm->stack.data, vm->stack.capacity * sizeof(uint64_t));
    }
    
    // Push the value onto the stack
    vm->stack.data[vm->stack.length++] = value;
}

uint64_t ccvm_stack_pop(ccvm_virtual_machine* vm) {
    // Check if the stack is empty
    if (vm->stack.length == 0) {
        // Handle stack underflow
        printf("Stack underflow\n");
        exit(1);
    }
    
    // Pop the value from the stack
    return vm->stack.data[--vm->stack.length];
}

uint64_t ccvm_stack_peek(ccvm_virtual_machine* vm) {
    // Check if the stack is empty
    if (vm->stack.length == 0) {
        // Handle stack underflow
        printf("Stack underflow\n");
        exit(1);
    }
    
    // Return the top value of the stack
    return vm->stack.data[vm->stack.length - 1];
}
