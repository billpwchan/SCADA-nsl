@echo off

cd /D %~dp0
echo Stopping Environment
set SCSENV=WEB2
call scs_env.bat

start scsshutdown -w -e %SCSENV%_%MACHINENAME%

start nginx -c nginx.conf -s stop

call %GEOSERVER_HOME%\bin\shutdown.bat

call apache-tomcat-6.0.37\bin\shutdown.bat


REM ~ taskkill /F /IM taonameserv.exe
