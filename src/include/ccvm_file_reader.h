#ifndef H_CCVM_FILE_READER
#define H_CCVM_FILE_READER

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "ccvm.h"

/// @brief A function that takes a file location and will give you the number of bytes read and the file contents
/// @param filename A c-string containing the filename of the file to be read
/// @param num_bytes A pointer to a size_t variable where the number of bytes read will be stored after reading
/// @return A pointer to a location in memory where the bytes of the file are stored after reading
uint8_t* load_bytes_from_file(const char* filename, size_t* num_bytes);

/// @brief A function that takes a CCVM instance and a file location of a .ccb file, and loads the bytecode within that .ccb into the virtual machine, ready to be executed
/// @param vm An instance of the virtual machine
/// @param file_location A string containing the file location of the .ccb file
void ccvm_load_program_from_file(ccvm_virtual_machine* vm, char* file_location);

/// @brief A function that takes a pointer to a location in memory where the bytes of the bytecode is stored, and inserts that program into the virtual machien ready to be executed
/// @param vm An instance of the virtual machine
/// @param program A pointer to a location in memory where the bytecode is stored
void ccvm_load_program_from_buffer(ccvm_virtual_machine* vm, uint8_t* program);

#endif