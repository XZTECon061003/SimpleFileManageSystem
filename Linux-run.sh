#!/bin/bash

if [ ! -f bin/DataSystem ]; then
./compile.sh
fi

./bin/DataSystem
