#!/bin/bash

x=$(g++ -std=c++11 $1 -H 2>&1 | grep bits/stdc++.h)
directory=`echo $x | awk '{ print $NF }'`

mkdir bits
cp $directory bits/
cd bits
g++ -std=c++11 stdc++.h


# Speed up compiler time of c++
# ./script.sh main.cpp

# and use > #include "bits/stdc++.h"
