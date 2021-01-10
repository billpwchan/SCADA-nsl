
cd /D %~dp0

xcopy /Y /I ScsEnvTablered ScsEnvTable

call scs_env.bat
title %SCSENV%
IF %SCSENV:~-3%==rpl goto replay
REM not in replay
set ASCOPT=
goto afterreplay

:replay
xcopy /Y /I ScsEnvTablerpl ScsEnvTable
set ASCOPT=-W

:afterreplay

IF NOT EXIST log mkdir log
IF NOT EXIST bin mkdir bin
IF NOT EXIST Alarms mkdir Alarms
IF NOT EXIST Alarms\UserLibs mkdir Alarms\UserLibs
IF NOT EXIST Database\UserLibs mkdir Database\UserLibs

xcopy /Y /I %SCSDLLDIR%\libDemoAutomaton.* Alarms\UserLibs
xcopy /Y /I %SCSDLLDIR%\libstdautomaton.* Alarms\UserLibs
xcopy /Y /I %SCSDLLDIR%\libCE_SCS.*  Database\UserLibs
xcopy /Y /I %SCSDLLDIR%\libCE_Demo.*  Database\UserLibs

xcopy /Y /I %SCSDLLDIR%\libscshooks.* bin

REM ~ del DpcVarServer

REM net share %SCSENV%_%MACHINENAME% /DELETE
REM net share %SCSENV%_%MACHINENAME%=%curdir%

REM check is binary BD exist
if exist "Database\binary\dbkheader.dat" goto :start
REM dump database
del dbmdump.log
del DpcVarServer
rmdir /S /Q Database\DbmPoller

start /b dbserver -e%SCSENV%_%MACHINENAME% -a -f -k > dbmdump.log 2>&1
REM Wait dbserver becomes SCS_UP
REM ----------------------------------
:loop
ping 128.0.0.1 -w 5000 >nul: 2>&1
if not exist dbmdump.log goto :loop
for /f %%a in ('findstr SCS_UP dbmdump.log') do goto :endofloop
goto :loop
:endofloop
REM Snapshot
REM ----------------------------------
echo.[INFO] Binary snapshot
cmd /c dbmforcesnap -w
>nul: call scskillit DbmServer@%SCSENV%_%MACHINENAME%
goto start


:start
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

REM verbose TAO logs
REM ~ set DpcVarServer_DBG_TAO=1
REM ~ set InputMgr_DBG_TAO=1

REM OLS notif configuration
set SCS_OLS_SCLIENT_TIMEOUT=60000
set SCS_NOTIFICATION_MAX_SIZE=5000

REM inputmanager config
set SCS_IMG_RSP_STRATEGY=HMI1;WEB1;WEB2;WEB3;HVSRV1N1;HVSRV1N2;HVSRV2N1;HVSRV2N2
set SCSSYNCNOTIFY=1
set SCS_IMG_LONG_DURATION_THRS=1000;500;1000

REM recording config
set RPL_DBXMAXREC=1000
set RPL_OLSMAXREC=10

REM for CORBA traces
set SCSREQUESTFILTER=syncWakeUpSync:syncWakeUp:syncNextWakeUpTime

echo > \\.\pipe\%SCSENV%_%MACHINENAME%
echo ================================================================ > \\.\pipe\%SCSENV%_%MACHINENAME%
echo ============     ENV VARIABLES             ===================== > \\.\pipe\%SCSENV%_%MACHINENAME%
set > \\.\pipe\%SCSENV%_%MACHINENAME%
echo ================================================================ > \\.\pipe\%SCSENV%_%MACHINENAME%

ascmanager.exe -z -f 60000 -F -W -w -e %SCSENV%_%MACHINENAME% -s1 -p3 >> \\.\pipe\%SCSENV%_%MACHINENAME% 2>&1 <nul:
set /P logpid=<%SCSENV%_%MACHINENAME%.pid
del /Q %SCSENV%_%MACHINENAME%.pid
taskkill /F /PID %logpid%
goto exit

:alreadyrunning
echo Cannot start: application already running
pause

:exit
