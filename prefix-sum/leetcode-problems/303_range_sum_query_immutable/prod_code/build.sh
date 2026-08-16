#!/bin/bash

# Usage:
# ./build.sh -prod source.cpp

# This tells the script to stop immediately if any command fails.
set -e


# These lines read command-line arguments
# $1 means the first argument
# $2 means the second argument
MODE=$1
SOURCE_FILE=$2
OUTPUT_FILE="test"




# This checks whether MODE or SOURCE_FILE is empty.
# -z means “is empty.”
# then show usage instructions.
if [ -z "$MODE" ] || [ -z "$SOURCE_FILE" ]; then
    echo "Usage:"
    echo "  ./build.sh -prod source.cpp"
    exit 1
fi



# This checks whether the selected mode is valid.
# Currently, this script only supports production/release mode.
if [ "$MODE" != "-prod" ]; then
    echo "Invalid mode: $MODE"
    echo "Usage:"
    echo "  ./build.sh -prod source.cpp"
    exit 1
fi


# std=c++17: Use the C++17 standard.
# Wall: Enable many common warnings.
# Wextra: Enable extra warnings not included in -Wall.
# Wpedantic: Warn about non-standard C++ usage.
# Wconversion: Warn about possible unsafe type conversions.
# Wshadow: Warn when a variable hides another variable with the same name.
# Wsign-conversion: Warn about signed/unsigned conversion issues.
COMMON_FLAGS="-std=c++17 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wsign-conversion"


echo "Building in production/release mode..."

g++ $COMMON_FLAGS \
    -O2 \
    prefix_sum/leetcode_problems/303_range_sum_query_immutable/prod_code/num_array.cpp \
    "$SOURCE_FILE" \
    -o "$OUTPUT_FILE"




echo "Build successful."
echo "Run using: ./$OUTPUT_FILE"