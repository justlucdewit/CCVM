// Header for the stack implementation
#ifndef CCVM_STACK_H
#define CCVM_STACK_H

#include "ccvm.h"

void ccvm_stack_initialize(ccvm_virtual_machine* vm);
void ccvm_stack_push(ccvm_virtual_machine* vm, uint64_t value);
uint64_t ccvm_stack_pop(ccvm_virtual_machine* vm);
uint64_t ccvm_stack_peek(ccvm_virtual_machine* vm);

#endif // CCVM_STACK_H