#!/bin/bash
set -eou pipefail

# Example: To run
# ./run.sh
#
# With Debug
# ./run.sh -d

export program_file=main.cpp
export DBG=""
export input_file=input
export output_file=my_output

while test $# -gt 0; do
  case "$1" in
    -d)
      echo "-d was selected; compiling in DEBUG mode!" >&2
      DBG=-Dredback
      shift
      ;;
    *.cpp | *.c)
      export program_file=$1
      shift
      ;;
    *)
      break
      ;;
  esac
done

if [[ "$(uname 2>/dev/null)" == "Linux" ]]; then
  time_cmd=$(which time)
else
  time_cmd=$(which gtime)
fi

output_binary=${program_file%.c*}.o

g++ -std=c++14 $DBG $program_file -o $output_binary

$time_cmd -p ./$output_binary <$input_file >$output_file

# Example:
#   ./run.sh main.cpp in.txt out.txt
