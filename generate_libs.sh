#!/bin/bash
# Function:
#   1. generate lib/libmongoose.a while it does not exist;
#   2. generate lib/libjsoncpp.a while it does not exist.

root_dir=`pwd`
lib_dir="$root_dir"/lib

file1="$lib_dir"/libmongoose.a
if test -f "$file1"
then
    echo "\033[0;33m INFO: $file1 exists. \033[0m"
else
    cd "$root_dir"/thirdparty/mongoose
    gcc -c -o mongoose.o mongoose.c
    ar rcs libmongoose.a mongoose.o
    cd "$root_dir"
    cp "$root_dir"/thirdparty/mongoose/libmongoose.a "$lib_dir"

    echo "\033[0;32m Success to generate $file1 \033[0m"
fi

file2="$lib_dir"/libjsoncpp.a
if test -f "$file2"
then
    echo "\033[0;33m INFO: $file2 exists. \033[0m"
else
    cd "$root_dir"/thirdparty/jsoncpp
    mkdir build
    cd build
    cmake ..
    make
    cd "$root_dir"
    cp "$root_dir"/thirdparty/jsoncpp/build/src/lib_json/libjsoncpp.a "$lib_dir"

    echo "\033[0;32m Success to generate $file2 \033[0m"
fi
