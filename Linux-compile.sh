#!/bin/bash

mkdir -p bin

echo "Building DataSystem..."

gcc 
main.c 
src/core/object.c 
src/list/linked_list.c 
src/tree/btree.c 
src/sort/sort.c 
src/file/fmgr.c 
src/ui/menu.c 
src/mgr/sys_mgr.c 
-Iinclude 
-g 
-Wall 
-Wextra 
-std=c11 
-o bin/DataSystem

if [ $? -eq 0 ]; then
echo "Build Success"
else
echo "Build Failed"
fi
