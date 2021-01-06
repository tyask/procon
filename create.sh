#!/bin/bash

function exe() {
    local cmd="$@"
    eval "$cmd"
    local ret=$?
    if [ $ret -eq 0 ]; then
        echo "$cmd -->> SUCCESS"
    else
        echo "$cmd -->> FAILED($ret)"
    fi
    return $ret
}

if [ $# -lt 2 ]; then
    echo "Argument Error."
    echo "Usage: $0 <DIR> <FILES...>"
    exit 1
fi

dir=$1; shift
files=($@)

exe mkdir -p $dir

for file in ${files[@]}; do
    target=$dir/$file
    if [ -f $target ]; then
        echo "$target already exists"
    else
        exe cp template.cc $target
    fi
done

