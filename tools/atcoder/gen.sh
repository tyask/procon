#!/bin/bash

. $(dirname $0)/../common.sh
. $(dirname $0)/atcoder_common.sh

root=$(dirname $0)/../..
workspace=$root/atcoder
config=$(dirname $0)/atcodertools.toml

function usage() {
    echo "Argument Error"
    echo "Usage: $0 <CONTEST> [-l|--login]"
    exit 1
}

if [ $# -lt 1 ]; then
    usage
fi

contest=$1; shift
login=false
for p in "$@"; do
    case $p in
        -l|--login) login=true;;
        *) echo "Argument Error: $p"; usage;;
    esac
done

$login || additional_opts+=" --without-login"

workspace=$(gen_workspace $contest)
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

template=$root/bin/atcoder_template.cpp
gen_atcoder_template $template

exe atcoder-tools gen $contest \
    --template $template \
    --workspace $workspace \
    --config $config \
    $additional_opts

