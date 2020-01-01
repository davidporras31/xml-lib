@echo off
git status
set /p mesage=Saisissez mesage commit:
git add .
git commit -m "%mesage%"
git push