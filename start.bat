@echo off
title DataSystem Builder
chcp 65001 > nul

echo.
echo =====================================
echo        Building DataSystem
echo =====================================
echo.

gcc ^
main.c ^
src\core\object.c ^
src\list\linked_list.c ^
src\tree\btree.c ^
src\sort\sort.c ^
src\file\fmgr.c ^
src\ui\menu.c ^
src\mgr\sys_mgr.c ^
-Iinclude ^
-std=c11 ^
-Wall ^
-Wextra ^
-o DataSystem.exe

if errorlevel 1 (
echo.
echo =====================================
echo            BUILD FAILED
echo =====================================
pause
exit /b 1
)

echo.
echo =====================================
echo         BUILD SUCCESSFUL
echo =====================================
echo.

DataSystem.exe

echo.
echo =====================================
echo          PROGRAM EXITED
echo =====================================
pause
