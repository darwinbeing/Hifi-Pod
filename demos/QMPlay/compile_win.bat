@echo off
qmake && mingw32-make
del /Q qmplay\lib\*.a
del /Q qmplay\plugins\*.a
del /Q qmplay\plugins\lib\*.a
del /Q qmplay\styles\*.a
pause
