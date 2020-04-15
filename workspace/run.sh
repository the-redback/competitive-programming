#!/bin/bash
set -eou pipefail

program=$1
input_file=$2
output_file=$3

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
