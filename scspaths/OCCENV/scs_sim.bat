cd /D %~dp0
call scs_env.bat 
start /MIN dacsimulator.exe -s  %1

