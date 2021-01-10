@echo off

cd /D %~dp0
echo Stopping Environment
call scs_env.bat

scsshutdown -w -e %SCSENV%_%MACHINENAME%
REM ~ taskkill /F /IM taonameserv.exe
