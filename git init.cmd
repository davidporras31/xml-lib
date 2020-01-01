@echo off
git init
set /p mesage=Saisissez url git:
git clone %mesage%
pause