#!/bin/bash

source $(dirname $0)/common.sh
source $(dirname $0)/atcoder/atcoder_common.sh

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
    template=$ROOT/bin/atcoder_template.cpp
    gen_atcoder_template $template
    python3 $(dirname $0)/render.py $template > $SRC
fi
