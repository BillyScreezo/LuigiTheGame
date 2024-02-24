#!/usr/bin/bash

BUILD_TYPE=$1
if [ -z $BUILD_TYPE ]; then
    BUILD_TYPE=Debug
fi

build_dir="build"

rm -rf "${build_dir}"
mkdir -p "${build_dir}"
cd "${build_dir}"

cmake -G "Unix Makefiles" \
    -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
    ../
make -j4

