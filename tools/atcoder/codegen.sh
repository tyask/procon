#!/bin/bash

. $(dirname $0)/../common.sh
. $(dirname $0)/atcoder_common.sh

root=$(realpath $(dirname $0)/../..)
config=$(dirname $0)/atcodertools.toml

function usage() {
    echo "Argument Error"
    echo "Usage: $0 <CONTEST> <PROBLEM> [-l|--login]"
    exit 1
}

if [ $# -lt 1 ]; then
    usage
fi

contest=$1;
problem=${2^^};
shift 2
url=$(printf 'https://atcoder.jp/contests/%s/tasks/%s_%s' $contest $contest $problem)
echo "url: $url"

login=false
for p in "$@"; do
    case $p in
        -l|--login) login=true;;
        *) echo "Argument Error: $p"; usage;;
    esac
done

$login || additional_opts+=" --without-login"

workspace=$(gen_workspace $contest)
problem_dir=$workspace/$contest/$problem
src=$(realpath $problem_dir/main.cpp)

if [ -f $src ]; then
    read -p \
"""The src file already exists: $src.
Can I continue to overwrite the src file? (y/n): """ ans
    case ${ans:0:1} in
        n|N) exit 0;;
        *) ;;
    esac
fi

exe mkdir -p $problem_dir

template=$root/bin/atcoder_template.cpp
gen_atcoder_template $template

exe "atcoder-tools codegen $url --template $template --config $config $additional_opts > $src"

