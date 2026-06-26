#!/bin/bash

if [ ! -f bin/DataSystem ]; then
./compile_macos.sh
fi

lldb ./bin/DataSystem
