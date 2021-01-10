@echo off
cls

echo.
echo SCSHOME = %SCSHOME%
echo SCSPATH = %SCSPATH%
echo.

if exist %SCSHOME%/dat/ScsVisu/Tools/scadadoc.tcl goto Start
echo.
echo Unable to find SCSHOME/dat/ScsVisu/Tools/scadadoc.tcl!
echo.
goto Exit

:Start
echo.
echo Invoking scadadoc with scstclsh...
echo.
scstclsh %SCSHOME%/dat/ScsVisu/Tools/scadadoc.tcl
if %errorlevel% leq 1 goto Done

echo.
echo Error: could not invoke scstclsh (%errorlevel%)
echo Now trying with tclsh...
echo.
pause
echo.

tclsh %SCSHOME%/dat/ScsVisu/Tools/scadadoc.tcl
if %errorlevel% leq 1 goto Done
echo.
echo Unable to run scadadoc! (%errorlevel%)
echo.
echo.
goto Exit

:Done
echo.
echo Completed!
if %errorlevel% equ 1 echo But errors may occured...
echo.
echo.
goto Exit

:Exit
pause
