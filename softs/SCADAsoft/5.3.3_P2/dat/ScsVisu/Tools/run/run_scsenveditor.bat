@echo off
cls

echo.
echo SCSHOME = %SCSHOME%
echo SCSPATH = %SCSPATH%
echo.

if exist %SCSHOME%/dat/ScsVisu/Tools/scsenveditor/main.tcl goto Start
echo.
echo Unable to find SCSHOME/dat/ScsVisu/Tools/scsenveditor/main.tcl!
echo.
goto Exit

:Start
echo.
echo Invoking ScsEnvEditor with wish...
echo.
wish %SCSHOME%/dat/ScsVisu/Tools/scsenveditor/main.tcl
if %errorlevel% leq 1 goto Done

echo.
echo Error: could not invoke wish (%errorlevel%)
echo Now trying with wish84...
echo.
pause
echo.

wish84 %SCSHOME%/dat/ScsVisu/Tools/scsenveditor/main.tcl
if %errorlevel% leq 1 goto Done
echo.
echo Unable to run ScsEnvEditor! (%errorlevel%)
echo.
echo.
goto Exit

:Done
echo.
echo Completed!
echo.
echo.
goto Exit

:Exit
