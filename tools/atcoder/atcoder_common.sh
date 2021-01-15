#!/bin/bash

source $(dirname $0)/../common.sh

ROOT=$(dirname $0)/../..
BASE_TEMPLATE=$(dirname $0)/../template.cpp

function gen_atcoder_template() {
    local template=$1
    exe "sed 's/\(#define __ATCODER__\) 0/\1 1/' $BASE_TEMPLATE > $template"
}

function gen_workspace() {
    local contest=$1
    local workspace=$ROOT/atcoder
    case $contest in
    abc*) workspace+=/abc;;
    arc*) workspace+=/arc;;
    agc*) workspace+=/agc;;
    *)    workspace+=/misc;;
    esac
    echo $workspace
}
