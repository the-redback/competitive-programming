#!/bin/bash
set -xeou pipefail
program=main.cpp
input_file=input
output_file=my_output
if [ $# -eq 1 ]; then
    program=$1
fi

if [[ "$(uname 2>/dev/null)" == "Linux" ]]; then
  time_cmd=$(which time)
else
  time_cmd=$(which gtime)
fi

output_binary=${program%.c*}.o

g++ -std=c++11 $program -o $output_binary

$time_cmd -p ./$output_binary <$input_file >$output_file

# Example:
#   ./run.sh main.cpp in.txt out.txt
