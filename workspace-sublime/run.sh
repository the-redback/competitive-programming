#!/bin/bash
set -eou pipefail

program=$1
input_file=$2
output_file=$3

output_binary=${program%.c*}.o

g++ -std=c++11 $program -o $output_binary

time -p (./$output_binary < $input_file > $output_file)


# Example:
#   ./run.sh main.cpp input.in output.in
