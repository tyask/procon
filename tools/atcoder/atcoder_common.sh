#!/bin/bash

source $(dirname ${BASH_SOURCE[0]})/../common.sh

ROOT=$(realpath $(dirname ${BASH_SOURCE[0]})/../..)
BASE_TEMPLATE=$(realpath $(dirname ${BASH_SOURCE[0]})/../template.cpp)
export ENABLE_PREDICTION=1

function gen_atcoder_template() {
    local template=$1
    exe "sed 's/\(#define __AUTO_GENERATE__\) 0/\1 1/' $BASE_TEMPLATE > $template"
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
