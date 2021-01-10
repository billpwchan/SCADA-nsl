@echo off

cd /D %~dp0
echo Stopping Environment
set SCSENV=OCCENVWEB1
call scs_env.bat

start scsshutdown -w -e %SCSENV%_%MACHINENAME%

REM start nginx -c nginx.conf -s stop

REM call %GEOSERVER_HOME%\bin\shutdown.bat

call apache-tomcat-8.0.23\bin\shutdown.bat


REM ~ taskkill /F /IM taonameserv.exe

REM start scskillit AscManager@%SCSENV%_%MACHINENAME%
