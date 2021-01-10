cd /D %~dp0
call scs_env.bat 
start /MIN dacsimulator.exe -s  IMG500CAMDOO.tcl
start /MIN dacsimulator.exe -s  IMG500SPK.tcl

