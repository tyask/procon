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
suffix=""
login=false
while (($# > 0)); do
    p=$1
    case $p in
        -l|--login)
            login=true
            ;;
        -s|--suffix)
            if [ -z "$2" ]; then
                echo "The specified option requires an argument: $p"
                usage
            fi
            suffix=$2
            shift
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

workspace=$(gen_workspace $contest $suffix)
contest_dir=$workspace/$contest
if [ -d "$contest_dir" ]; then
    read -p \
"""The contest directory already exists: $contest_dir.
Can I continue to generate contest directory? (y/n): """ ans
    case ${ans:0:1} in
        y|Y) ;;
        n|N) exit 0;;
        *) exit 0;;
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

