#include "../include/ccvm_file_reader.h"
#include "../include/ccvm_execution.h"

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("usage: CCVM <filename>\n\n");
        return 0;
    }

    // Create the virtual machine
    ccvm_virtual_machine vm = { 0 };

    // Load the program into the virtual machine
    ccvm_load_program_from_file(&vm, argv[1]);

    // Execute the program within the virtual machine
    ccvm_execute_program(&vm);

    return 0;
}