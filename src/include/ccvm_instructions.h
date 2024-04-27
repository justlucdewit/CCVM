#ifndef CCVM_INSTRUCTIONS_H
#define CCVM_INSTRUCTIONS_H

#include "ccvm.h"
#include "ccvm_flags.h"
#include "ccvm_registers.h"
#include "ccvm_stack.h"
#include "ccvm_execution.h"

/// @brief The VM instruction to move a literal value into a register
/// @param vm An instance of the virtual machine
void ccvm_instruction_mov_reg_literal(ccvm_virtual_machine* vm);

/// @brief The VM instruction to move a value from one register to another
/// @param vm An instance of the virtual machine
void ccvm_instruction_mov_reg_reg(ccvm_virtual_machine* vm);

/// @brief The VM instruction to move a value from a memory address to a register
/// @param vm An instance of the virtual machine
void ccvm_instruction_mov_reg_mem(ccvm_virtual_machine* vm);

/// @brief The VM instruction to move a literal value into a memory address
/// @param vm An instance of the virtual machine
void ccvm_instruction_mov_mem_literal(ccvm_virtual_machine* vm);

/// @brief The VM instruction to move a value from a register to a memory address
/// @param vm An instance of the virtual machine
void ccvm_instruction_mov_mem_reg(ccvm_virtual_machine* vm);

/// @brief The VM instruction to move a value from one memory address to another
/// @param vm An instance of the virtual machine
void ccvm_instruction_mov_mem_mem(ccvm_virtual_machine* vm);

/// @brief The VM instruction to push a value onto the stack based on a literal
/// @param vm An instance of the virtual machine
void ccvm_instruction_push_lit(ccvm_virtual_machine* vm);

/// @brief The VM instruction to push a value onto the stack based on a register
/// @param vm An instance of the virtual machine
void ccvm_instruction_push_reg(ccvm_virtual_machine* vm);

/// @brief The VM instruction to push a value onto the stack based on a memory address
/// @param vm An instance of the virtual machine
void ccvm_instruction_push_mem(ccvm_virtual_machine* vm);

/// @brief The VM instruction to pop the top value off the stack
/// @param vm An instance of the virtual machine
void ccvm_instruction_pop(ccvm_virtual_machine* vm);

/// @brief The VM instruction to pop the top value off the stack and store it in a register
/// @param vm An instance of the virtual machine
void ccvm_instruction_pop_register(ccvm_virtual_machine* vm);

/// @brief The VM instruction to pop the top value off the stack and store it in a memory address
/// @param vm An instance of the virtual machine
void ccvm_instruction_pop_memory(ccvm_virtual_machine* vm);

/// @brief The VM instruction to swap the top two values on the stack
/// @param vm An instance of the virtual machine
void ccvm_instruction_swap(ccvm_virtual_machine* vm);

/// @brief The VM instruction to rotate the top three values on the stack to the left
/// @param vm An instance of the virtual machine
void ccvm_instruction_rotate_left(ccvm_virtual_machine* vm);

/// @brief The VM instruction to rotate the top three values on the stack to the right
/// @param vm An instance of the virtual machine
void ccvm_instruction_rotate_right(ccvm_virtual_machine* vm);

/// @brief The VM instruction to duplicate the top value on the stack
/// @param vm An instance of the virtual machine
void ccvm_instruction_dup(ccvm_virtual_machine* vm);

/// @brief The VM instruction to allocate some memory to a register of size based on a literal
/// @param vm An instance of the virtual machine
void ccvm_instruction_alloc_reg_lit(ccvm_virtual_machine* vm);

/// @brief The VM instruction to allocate some memory to a register of size based on a register
/// @param vm An instance of the virtual machine
void ccvm_instruction_alloc_reg_reg(ccvm_virtual_machine* vm);

/// @brief The VM instruction to allocate some memory to the stack of size based on a literal
/// @param vm An instance of the virtual machine
void ccvm_instruction_alloc_stack_lit(ccvm_virtual_machine* vm);

/// @brief The VM instruction to allocate some memory to the stack of size based on a register
/// @param vm An instance of the virtual machine
void ccvm_instruction_alloc_stack_reg(ccvm_virtual_machine* vm);

/// @brief The VM instruction to reallocate memory to a register of size based on a literal
/// @param vm An instance of the virtual machine
void ccvm_instruction_realloc_reg_lit(ccvm_virtual_machine* vm);

/// @brief The VM instruction to reallocate memory to a register of size based on a register
/// @param vm An instance of the virtual machine
void ccvm_instruction_realloc_reg_reg(ccvm_virtual_machine* vm);

/// @brief The VM instruction to reallocate memory to the stack of size based on a literal
/// @param vm An instance of the virtual machine
void ccvm_instruction_realloc_stack_lit(ccvm_virtual_machine* vm);

/// @brief The VM instruction to reallocate memory to the stack of size based on a register
/// @param vm An instance of the virtual machine
void ccvm_instruction_realloc_stack_reg(ccvm_virtual_machine* vm);

/// @brief The VM instruction to free a pointer, based on a register
/// @param vm An instance of the virtual machine
void ccvm_instruction_free_reg(ccvm_virtual_machine* vm);

/// @brief The VM instruction to free a pointer, based on the top value of the stack
/// @param vm An instance of the virtual machine
void ccvm_instruction_free_stack(ccvm_virtual_machine* vm);

/// @brief The VM instruction to add the top two values on the stack and push the result
/// @param vm An instance of the virtual machine
void ccvm_instruction_math_add_stack(ccvm_virtual_machine* vm);

/// @brief The VM instruction to push the base address of the bytecode onto the stack
/// @param vm An instance of the virtual machine
void ccvm_instruction_bytecode_base_address_stack(ccvm_virtual_machine* vm);

/// @brief The VM instruction to print debug information
/// @param vm An instance of the virtual machine
void ccvm_instruction_debug(ccvm_virtual_machine* vm);

/// @brief The VM instruction to set the exit flag to true causing the VM to exit with exit code stored in register A
/// @param vm An instance of the virtual machine
void ccvm_instruction_exit(ccvm_virtual_machine* vm);

#endif