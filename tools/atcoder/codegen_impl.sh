#!/bin/bash

. $(dirname $0)/../common.sh
. $(dirname $0)/atcoder_common.sh

root=$(realpath $(dirname $0)/../..)
config=$(dirname $0)/atcodertools.toml

function usage() {
    echo "Argument Error"
    echo "Usage: $0 <URL> [-l|--login]"
    exit 1
}

if [ $# -lt 1 ]; then
    usage
    exit
fi

url=$1; shift
login=false
for p in "$@"; do
    case $p in
        -l|--login) login=true;;
        *) echo "Argument Error: $p"; usage;;
    esac
done

$login || additional_opts+=" --without-login"

template=$root/bin/atcoder_template.cpp
gen_atcoder_template $template 1>&2

atcoder-tools codegen $url --template $template --config $config $additional_opts

