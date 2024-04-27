#include "../include/ccvm_file_reader.h"

uint8_t* load_bytes_from_file(const char* filename, size_t* num_bytes) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        *num_bytes = 0;
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory to hold the file contents
    uint8_t* buffer = (uint8_t*)malloc(file_size);
    if (buffer == NULL) {
        fclose(file);
        perror("Error allocating memory");
        *num_bytes = 0;
        return NULL;
    }

    // Read the file contents into the buffer
    size_t bytes_read = fread(buffer, sizeof(uint8_t), file_size, file);
    fclose(file);

    if (bytes_read != file_size) {
        free(buffer);
        perror("Error reading file");
        *num_bytes = 0;
        return NULL;
    }

    *num_bytes = bytes_read;
    return buffer;
}

void ccvm_load_program_from_file(ccvm_virtual_machine* vm, char* file_location) {
    vm->bytecode = load_bytes_from_file(file_location, &vm->bytecode_buffer_length);
}

void ccvm_load_program_from_buffer(ccvm_virtual_machine* vm, uint8_t* program) {
    vm->bytecode = program;
}