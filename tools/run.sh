#!/bin/bash

source $(dirname $0)/common.sh

if [ $# -ge 1 ]; then
    DIR=$1
else
    DIR=.
fi

SRC=$DIR/main.cpp
ROOT=$(realpath $(dirname $0)/..)
BIN=$ROOT/bin/a.out
exe g++ $SRC -o $BIN -D__TEST__ || exit $?

echo "Running..."
exe $BIN
