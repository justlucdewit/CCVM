# CC Virtual Machine
This repository contains the sourcecode for the CC Virtual Machine (CCVM). CCVM
is a bytecode interpreter (similar to JVM for java) created by Luc de Wit meant
to be used as a runtime for non-serious programming languages.

## Road-Map
In the future there are plans for extending the functionality of the CCVM and usages
of the CC Virtual Machine.
 - [ ] Get Hello World running on CCVM
 - [ ] Get fibonacci running on CCVM
 - [ ] Render a mandelbrot on CCVM
 - [ ] Creating an assembly language ontop of CCVM (CCA)
 - [ ] Creating a stack based language ontop of CCA
 - [ ] Creating a lisp like language ontop of CCA
 - [ ] Creating a procedural BASIC-like language ontop of CCA
 - [ ] Creating a C-like language ontop of CCA
 - [ ] Online CCVM/CCA interpreter using web assembly

# Instruction set
The current instructionset of the CC Virtual Machine
 - 0x00 MOV #REG# #LIT#
 - 0x01 MOV #REG# #REG#
 - 0x02 MOV #REG# #MEM#
 - 0x03 MOV #MEM# #LIT#
 - 0x04 MOV #MEM# #REG#
 - 0x05 MOV #MEM# #MEM#
 - 0x06 PUSH #LIT#
 - 0x07 PUSH #REG#
 - 0x08 PUSH #MEM#
 - 0x09 POP
 - 0x0A POP #REG#
 - 0x0B POP #MEM#
 - 0x0C SWAP
 - 0x0D ROTL
 - 0x0E ROTR
 - 0x0F DUP

 - 0x10 ALLOC #reg# #lit#
 - 0x11 ALLOC #reg# #reg#
 - 0x12 ALLOC #reg#
 - 0x13 ALLOC #lit#
 - 0x14 REALLOC #reg# #lit#
 - 0x15 REALLOC #reg# #reg#
 - 0x16 REALLOC #reg#
 - 0x17 REALLOC #lit#
 - 0x18 FREE #reg#
 - 0x19 FREE

 - 0xFD SYSCALL
 - 0xFE DEBUG
 - 0xFF EXIT

# SYSCALLS


|code| name        | reg a | reg b | reg c | reg d |
|----|-------------|-------|-------|-------|------ |
| 00 | Print       | memory location to the string | length of the string |
| 01 | Run ID      |
| 02 | Time        |

