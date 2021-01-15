#!/bin/bash

source $(dirname $0)/../common.sh

if [ $# -lt 1 ]; then
    echo "Argument Error"
    echo "Usage $0 <DIR>"
    exit 1
fi

DIR=$1
SRC=$DIR/main.cpp
ROOT=$(dirname $0)/../..
BIN=$ROOT/bin/a.out
TIMEOUT=2

exe rm $BIN
exe g++ $SRC -o $BIN -D__DEBUG__

exe atcoder-tools test \
    -d $DIR \
    -t $TIMEOUT \
    -e $BIN \
    

