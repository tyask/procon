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


