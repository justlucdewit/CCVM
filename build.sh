#!/bin/bash

# Check if dist directory exists
if [ -d "dist" ]; then
    rm -rf dist/*
else
    mkdir dist
fi

# Compile the code
gcc src/sources/main.c \
    src/sources/ccvm_flags.c \
    src/sources/ccvm_file_reader.c \
    src/sources/ccvm_execution.c \
    -o dist/ccvm