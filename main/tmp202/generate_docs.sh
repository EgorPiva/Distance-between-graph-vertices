#!/bin/bash

echo "Generating documentation with Doxygen..."

# Check if Doxygen is installed
if ! command -v doxygen &> /dev/null; then
    echo "Error: Doxygen is not installed"
    echo "Please install Doxygen using your package manager"
    echo "For Ubuntu/Debian: sudo apt-get install doxygen"
    echo "For macOS: brew install doxygen"
    exit 1
fi

# Create docs directory if it doesn't exist
mkdir -p docs

# Run Doxygen
doxygen Doxyfile

if [ $? -eq 0 ]; then
    echo "Documentation generated successfully in docs/html/"
    echo "You can open docs/html/index.html in your browser"
else
    echo "Error generating documentation"
fi

exit 0 