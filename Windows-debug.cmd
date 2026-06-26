@echo off

if not exist bin\DataSystem.exe (
call compile.cmd
)

gdb bin\DataSystem.exe
pause
