#!/bin/bash

src_dir=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd $src_dir/../build

make -j$(nproc)
make -j$(nproc) install
