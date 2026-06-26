@echo off

if not exist bin\DataSystem.exe (
call compile.cmd
)

bin\DataSystem.exe

pause
