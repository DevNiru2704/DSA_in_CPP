#!/bin/zsh

# Check if filename argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <filename.cpp>"
    exit 1
fi

# Get the input file
input_file="$1"

# Check if file exists
if [ ! -f "$input_file" ]; then
    echo "Error: File '$input_file' not found!"
    exit 1
fi

# Get filename without extension
filename="${input_file%.cpp}"

# Compile the C++ file
echo "Compiling $input_file..."
g++ -o "${filename}.exe" "$input_file"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful! Running ${filename}.exe..."
    echo "----------------------------------------"
    ./"${filename}.exe"
    echo "\n----------------------------------------"
    echo "Program exited with code: $?"
    # Clean up the executable
    rm "${filename}.exe"
    echo "Executable cleaned up."
else
    echo "Compilation failed!"
    exit 1
fi