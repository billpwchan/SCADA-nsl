@echo "===================="
@echo on

cd /D %~dp0

set SCSENV=WEB2

call scs_env.bat 

REM tomcat use local install
set CATALINA_HOME=%curdirpath%\apache-tomcat-6.0.37

title %SCSENV%

IF NOT EXIST log mkdir log
IF NOT EXIST temp mkdir temp

REM start limitlog
IF NOT EXIST %SCSENV%_%MACHINENAME%.pid goto startlimitlog
set /P logpid=<%SCSENV%_%MACHINENAME%.pid
tasklist /FI "IMAGENAME eq scslimitlog.exe" /FO LIST | findstr PID | findstr %logpid%
echo ERRORLEVEL %ERRORLEVEL%
IF %ERRORLEVEL%==0 goto alreadyrunning

del /Q %SCSENV%_%MACHINENAME%.pid

:startlimitlog
scslimitlog -d -p -n 3000 -l 30 %SCSENV%_%MACHINENAME%

type ScsEnvTable > \\.\pipe\%SCSENV%_%MACHINENAME%
type ScsEnvList > \\.\pipe\%SCSENV%_%MACHINENAME%
type scadasoft.cfg > \\.\pipe\%SCSENV%_%MACHINENAME%

ascmanager -e %SCSENV% -W -s1 -p3  >> \\.\pipe\%SCSENV%_%MACHINENAME% 2>&1 <nul:

set /P logpid=<%SCSENV%_%MACHINENAME%.pid
del /Q %SCSENV%_%MACHINENAME%.pid
taskkill /F /PID %logpid%
goto exit

:alreadyrunning
echo Cannot start: application already running
pause

:exit