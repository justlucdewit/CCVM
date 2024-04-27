#!/bin/bash

# Define build number (example: timestamp)
MAJOR_VERSION=1
MINOR_VERSION=0
BUILD_NUMBER=$(date +%s)

# Check if dist directory exists
if [ -d "dist" ]; then
    rm -rf dist/*
else
    mkdir dist
fi

# Compile the code with build number macro
gcc src/sources/main.c \
    src/sources/ccvm_flags.c \
    src/sources/ccvm_file_reader.c \
    src/sources/ccvm_execution.c \
    src/sources/ccvm_instructions.c \
    src/sources/ccvm_stack.c \
    src/sources/ccvm_registers.c \
    -o dist/ccvm \
    -DBUILD_NUMBER=$BUILD_NUMBER \
    -DMAJOR_VERSION=$MAJOR_VERSION \
    -DMINOR_VERSION=$MINOR_VERSION
