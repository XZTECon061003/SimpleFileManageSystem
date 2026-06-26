#!/bin/bash

if [ ! -f bin/DataSystem ]; then
./compile.sh
fi

gdb ./bin/DataSystem
