#!/bin/bash

source $(dirname $0)/common.sh

if [ $# -lt 1 ]; then
    echo "Argument Error"
    echo "Usage $0 <DIR>"
    exit 1
fi

DIR=$1
SRC=$DIR/main.cpp
ROOT=$(realpath $(dirname $0)/..)
BIN=$ROOT/bin/a.out
exe g++ $SRC -o $BIN -D__DEBUG__ -D__MULTIRUN__
exe $BIN

