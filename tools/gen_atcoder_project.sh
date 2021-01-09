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
*)    workspace+=/misc;;
esac

contest_dir=$workspace/$contest
if [ -d "$contest_dir" ]; then
    read -p \
"""The contest directory already exists: $contest_dir.
Can I continue to generate contest directory? (y/n): """ ans
    case ${ans:0:1} in
        n|N) exit 0;;
        *) ;;
    esac
else
    exe mkdir -p $workspace
fi

exe atcoder-tools gen $contest \
    --without-login \
    --template $(dirname $0)/template.cpp \
    --workspace $workspace
