#!/bin/bash

source $(dirname $0)/common.sh

if [ $# -lt 1 ]; then
    echo "Argument Error"
    echo "Usage $0 <CONTEST>"
    exit 1
fi

contest=$1
root=$(dirname $0)/..
workspace=$root/atcoder

case $contest in
abc*) workspace+=/abc;;
arc*) workspace+=/arc;;
agc*) workspace+=/agc;;
*) echo "unsupported contest"; exit 1;;
esac

exe mkdir -p $workspace

exe atcoder-tools gen $contest \
    --without-login \
    --template $(dirname $0)/template.cc \
    --workspace $workspace
