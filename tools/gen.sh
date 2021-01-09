#!/bin/bash

source $(dirname $0)/common.sh

if [ $# -lt 1 ]; then
    echo "Argument Error."
    echo "Usage: $0 <SRC>"
    exit 1
fi

SRC=$1
DIR=$(dirname $SRC)

exe mkdir -p $DIR

if [ -f $SRC ]; then
    echo "$SRC already exists"
else
    exe cp template.cc $target
fi
