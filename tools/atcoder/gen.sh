#!/bin/bash

. $(dirname $0)/../common.sh
. $(dirname $0)/atcoder_common.sh

root=$(realpath $(dirname $0)/../..)
workspace=$root/atcoder
config=$(dirname $0)/atcodertools.toml

function usage() {
    echo "Usage: $0 <CONTEST> [-l|--login][-s|--suffix SUFFIX]"
    exit 1
}

argv=()
login=false
while (($# > 0)); do
    p=$1
    case $p in
        -l|--login)
            login=true
            ;;
        -*)
            echo "Argument Error: $p";
            usage
            ;;
        *)
            argv+=($p)
            ;;
    esac
    shift
done

if [ -z "${argv}" ]; then
    echo "You must specify contest name as argument"
    usage
fi

contest=${argv[0]};
$login || additional_opts+=" --without-login"

workspace=$(gen_workspace $contest)
for i in {1..9}; do
    dir=$workspace/$contest/$i # abc/abc001/1
    if [ ! -d "$dir" ]; then
        contest_dir=$dir
        break;
    fi
done

if [ -z "$contest_dir" ]; then
    echo "Failed to generate contest dir"
    exit 1
fi

template=$root/bin/atcoder_template.cpp
gen_atcoder_template $template

exe atcoder-tools gen $contest \
    --template $template \
    --workspace $contest_dir \
    --config $config \
    $additional_opts

