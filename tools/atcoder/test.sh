#!/bin/bash

source $(dirname $0)/../common.sh
source $(dirname $0)/atcoder_common.sh

DIR=.
if [ $# -ge 1 ]; then
    DIR=$1
fi

SRC=$DIR/main.cpp
BIN=$ROOT/bin/a.out
TIMEOUT=2

exe rm $BIN
exe g++ $SRC -o $BIN -I$ROOT/lib/ac-library -std=c++17 -Wall

exe atcoder-tools test \
    -d $DIR \
    -t $TIMEOUT \
    -e $BIN \
    

