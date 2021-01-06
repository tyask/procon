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

target=$1
dir=$(dirname $target)

if [ -f $target ]; then
    echo "$target already exists"
    exit
fi

exe mkdir -p $dir
exe cp template.cc $target

