#include "../include/ccvm_file_reader.h"
#include "../include/ccvm_execution.h"
#include "../include/ccvm_stack.h"

#define STR1(x)  #x
#define STR(x)  STR1(x)

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("CCVM V" STR(MAJOR_VERSION) "."  STR(MINOR_VERSION) "."  STR(BUILD_NUMBER) "\n");
        printf("usage: CCVM <filename>\n\n");
        return 0;
    }

    // Create the virtual machine
    ccvm_virtual_machine vm = { 0 };

    // Initialize the virtual machine
    ccvm_stack_initialize(&vm);

    // Load the program into the virtual machine
    ccvm_load_program_from_file(&vm, argv[1]);

    // Execute the program within the virtual machine
    uint64_t exit_code = ccvm_execute_program(&vm);

    return exit_code;
}