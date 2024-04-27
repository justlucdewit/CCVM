#ifndef H_CCVM
#define H_CCVM

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief The structure representing the entire cc virtual machine and all its
 * state and memory.
 * 
 * This struct encapsulates the state and memory of the cc virtual machine (CCVM),
 * including the program counter, bytecode buffer, flags, and registers.
 */
typedef struct ccvm_virtual_machine {
    /**
     * @brief A pointer to a memory location within the bytecode buffer, 
     * representing where the virtual machine is currently executing.
     * 
     * This pointer indicates the current instruction being executed by the
     * virtual machine. It points to a memory location within the bytecode buffer.
     */
    uint64_t pointer_instruction_pointer;

    /**
     * @brief A pointer to a memory buffer that contains the CCVM bytecode 
     * to be executed.
     * 
     * This pointer points to the beginning of the bytecode buffer, which contains
     * the instructions to be executed by the virtual machine.
     */
    uint8_t* bytecode;

    /**
     * @brief The length of the bytecode buffer.
     * 
     * This variable specifies the length of the bytecode buffer in bytes.
     */
    size_t bytecode_buffer_length;

    /**
     * @brief Flags representing different states of the virtual machine used for conditional logic
     * 
     * These flags are used to check for certain states within the virtual machine, to check if 2 numbers are equal, not equal, less then, greather then, less then or equal, less then or not equal, or zero
     * the flags are referenced using the ccvm_flag enum and can be controlled using the functions within ccvm_flags.h header
     */
    uint8_t flags;

    /**
     * @brief An array of registers used by the virtual machine for storing 
     * intermediate values.
     * 
     * This array contains the registers used by the virtual machine for
     * storing intermediate values during program execution.
     * The number of registers is fixed at 4.
     * 
     * The registers are named A, B, C, and D
     */
    uint64_t registers[4];
} ccvm_virtual_machine;

#endif