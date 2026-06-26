#!/bin/bash

if [ ! -f bin/DataSystem ]; then
./compile_macos.sh
fi

./bin/DataSystem
