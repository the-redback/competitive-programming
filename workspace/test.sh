#!/bin/bash

# Example: To run
# ./test.sh
#
# With Debug
# ./test.sh -d

export program_file=main.cpp
export DBG=""

while test $# -gt 0; do
  case "$1" in
    -h | --help)
      echo "test.sh - test program against input and output"
      echo ""
      echo "test.sh [options] application"
      echo ""
      echo "options:"
      echo "-h, --help                show brief help"
      echo "-d, --debug               Test in debug mode"
      echo ""
      echo "Example:"
      echo "  Test main.cpp file: ./test.sh"
      echo "  Test another file other than main.cpp: ./test.sh a.cpp"
      exit 0
      ;;
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

export output_binary=${program_file%.c*}.o

echo $program_file $output_binary

if ! g++ -std=c++11 $DBG $program_file -o $output_binary; then
  exit
fi
INPUT_NAME=input
OUTPUT_NAME=output
MY_NAME=my_output

if [[ "$(uname 2>/dev/null)" == "Linux" ]]; then
  time_cmd=$(which time)
else
  time_cmd=$(which gtime)
fi

rm -R $MY_NAME* &>/dev/null
for test_file in $INPUT_NAME*; do
  i=$((${#INPUT_NAME}))
  test_case=${test_file:$i}
  if ! $time_cmd -o time.out -f "(%es)" ./$output_binary <$INPUT_NAME$test_case >$MY_NAME$test_case; then
    echo [1m[31mSample test \#$test_case: Runtime Error[0m $(cat time.out)
    echo ========================================
    echo Sample Input \#$test_case
    cat $INPUT_NAME$test_case
  else
    if diff --brief --ignore-space-change $MY_NAME$test_case $OUTPUT_NAME$test_case; then
      echo [1m[32mSample test \#$test_case: Accepted[0m $(cat time.out)
    else
      echo [1m[31mSample test \#$test_case: Wrong Answer[0m $(cat time.out)
      echo ========================================
      echo Sample Input \#$test_case
      cat $INPUT_NAME$test_case
      echo ========================================
      echo Sample Output \#$test_case
      cat $OUTPUT_NAME$test_case
      echo ========================================
      echo My Output \#$test_case
      cat $MY_NAME$test_case
      echo ========================================
    fi
  fi
done
