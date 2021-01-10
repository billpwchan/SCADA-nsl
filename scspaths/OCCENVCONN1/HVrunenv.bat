@echo "===================="
@echo on

cd /D %~dp0
call scs_env.bat 
title %SCSENV%

IF NOT EXIST BAConnectorConfiguration.xml copy BAConnectorConfiguration.xml.prod BAConnectorConfiguration.xml
IF NOT EXIST log mkdir log

IF NOT EXIST ScsEnvTable copy ScsEnvTable.prod ScsEnvTable

xcopy /Y /I BAConnectorConfiguration.xml.eclipse BAConnectorConfiguration.xml

copy ..\subsystems.xml BASystemConfiguration\instances\subsystems.xml
IF %USE_LOCALHOST%==1 copy ..\subsystems_localhost.xml BASystemConfiguration\instances\subsystems.xml

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

ascmanager -e %SCSENV% -W -s1 -p3 > \\.\pipe\%SCSENV%_%MACHINENAME% 2>&1 <nul:

set /P logpid=<%SCSENV%_%MACHINENAME%.pid
del /Q %SCSENV%_%MACHINENAME%.pid
taskkill /F /PID %logpid%
goto exit

:alreadyrunning
echo Cannot start: application already running
pause

:exit
