
cd /D %~dp0

call scs_env.bat

IF %SCSENV:~-3%==rpl goto replay
REM not in replay
set ASCOPT=
goto afterreplay

:replay
xcopy /Y /I ScsEnvTablerpl ScsEnvTable
set ASCOPT=-W

:afterreplay

IF NOT EXIST log mkdir log
IF NOT EXIST Database\UserLibs mkdir Database\UserLibs

xcopy /Y /I %SCSDLLDIR%\libCE_SCS.dll  Database\UserLibs


REM ~ del DpcVarServer


REM check is binary BD exist
if exist "Database\binary\dbkheader.dat" goto :start
REM dump database
del dbmdump.log
del DpcVarServer
rmdir /S /Q Database\DbmPoller

goto start


:start
REM start limitlog
IF NOT EXIST %SCSENV%_%MACHINENAME%.pid scslimitlog -d -p -n 3000 -l 30 %SCSENV%_%MACHINENAME%

type ScsEnvTable > \\.\pipe\%SCSENV%_%MACHINENAME%
type ScsEnvList > \\.\pipe\%SCSENV%_%MACHINENAME%
type scadasoft.cfg > \\.\pipe\%SCSENV%_%MACHINENAME%

REM verbose TAO logs
REM ~ set DpcVarServer_DBG_TAO=1
REM ~ set InputMgr_DBG_TAO=1

REM OLS notif configuration
set SCS_OLS_SCLIENT_TIMEOUT=60000
set SCS_NOTIFICATION_MAX_SIZE=200

REM inputmanager config
set SCS_IMG_RSP_STRATEGY=HMI1;WEB1;WEB2;WEB3
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

ascmanager.exe -z -W -f 60000 -F -w -e %SCSENV%_%MACHINENAME% -s1 -p3 >> \\.\pipe\%SCSENV%_%MACHINENAME% 2>&1 <nul:
set /P logpid=<%SCSENV%_%MACHINENAME%.pid
del /Q %SCSENV%_%MACHINENAME%.pid
taskkill /F /PID %logpid%
