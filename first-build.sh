#!/bin/bash

sudo apt -yq install libmpc-dev flex bison

src_dir=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

rm -rf $src_dir/../{build,install}
mkdir -p $src_dir/../{build,install}

cd $src_dir/../build

../src/configure CC=/usr/bin/gcc CXX=/usr/bin/g++                          \
                 --prefix=$(realpath ../install)                           \
                 --enable-languages=c,c++                                  \
                 --enable-libstdcxx-debug                                  \
                 --enable-libstdcxx-backtrace                              \
                 --disable-bootstrap                                       \
                 --disable-multilib                                        \
                 --disable-libvtv                                          \
                 --with-system-zlib                                        \
                 --without-isl                                             \
                 --enable-multiarch
