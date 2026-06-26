@echo off

if not exist bin mkdir bin

echo Building DataSystem...

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
-g ^
-Wall ^
-Wextra ^
-std=c11 ^
-o bin\DataSystem.exe

if errorlevel 1 (
echo Build Failed
pause
exit /b 1
)

echo Build Success
pause
