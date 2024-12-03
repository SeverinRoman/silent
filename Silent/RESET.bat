@echo off
cd /d %~dp0
rmdir /s /q Intermediate
rmdir /s /q Binaries
rmdir /s /q .vscode
rmdir /s /q DerivedDataCache
rmdir /s /q .vs
del /q BeatEmUp.sln
del /q BeatEmUp.code-workspace
pause