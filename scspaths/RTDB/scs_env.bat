rem ######################
rem SCADAsoft Environment
rem ######################
set curdirpath=%~dp0

FOR %%F in (%curdirpath:~0,-1%) do set rootdir=%%~dpF
FOR %%F in (%rootdir:~0,-1%) do set rootdir=%%~dpF
set rootdir=%rootdir:~0,-1%

FOR %%F in (%curdirpath:~0,-1%) do set curdirname=%%~nF

FOR /F %%a IN ('hostname') DO set MACHINENAME=%%a

IF %curdirpath:~-4,-1%==sby goto standby
REM ELSE
goto setscsenv

:standby
set curdirname=%curdirname:~,-3%
set MACHINENAME=p-dummy
goto setscsenv

:setscsenv
set SCSENV=%curdirname%

title %SCSENV%_CMD

REM
set SOFTS_DIR=%rootdir%\softs

REM SCSHOME
set SCSHOME=%SOFTS_DIR%\SCADAsoft\5.3.1
set SCSARCH=xp-msvc10
set SCSDLLDIR=%SCSHOME%\%SCSARCH%\dll

REM JAVA
set JAVA_HOME=%SOFTS_DIR%\jdk1.6.0_34

REM PYTHON
set PYTHONOPTIMIZE=1
set PYTHONHOME=%SOFTS_DIR%\Python27
set PATH=%PYTHONHOME%;%PATH%

REM TCL rootdir
set TCLHOME=%SCSHOME%\TCL
set TCL_LIBRARY=%TCLHOME%\lib

set ORB_NAME=TAO
set TAO_VERSION=10508
set PATH=%TCLHOME%\bin;%PATH%

REM TAO
set ACE_ROOT=%SCSHOME%\ACE_wrappers
set TAO_ROOT=%ACE_ROOT%\TAO
set ACEHOME=%ACE_ROOT%
set TAOHOME=%TAO_ROOT%
set PATH=%PATH%;%ACE_ROOT%\bin;%ACE_ROOT%\lib

REM MYSQL
set MYSQL_HOME=%SOFTS_DIR%\mysql-5.6.10-win32
set PATH=%MYSQL_HOME%\bin;%PATH%

REM tomcat
set CATALINA_HOME=%SOFTS_DIR%\apache-tomcat-7.0.39

REM terracotta
set TERRACOTTA_HOME="%SOFTS_DIR%\terracotta-3.6.1"

REM geoserver
set GEOSERVER_HOME=%SOFTS_DIR%\geoserver-2.5

REM set SCADAsoft path
set SCSHOME=%SCSHOME:/=\%
set PATH=%SCSHOME%\%SCSARCH%\bin;%SCSHOME%\%SCSARCH%\dll;%SCSHOME%\%SCSARCH%\dll\rwav;%SCSHOME%\%SCSARCH%\dll\ilog;%SCSHOME%\%SCSARCH%\dll\msvc;%SCSHOME%\%SCSARCH%\dll\xerces;%PATH%

REM reset path
set SCSHOME=%SCSHOME:\=/%

set curdir=%cd%
set SCSPATH=%curdir:\=/%
IF EXIST bin set PATH=%SCSPATH:/=\%\bin;%PATH%

IF EXIST D:\dev\bin\dev\xp-msvc10\bin set PATH=D:\dev\bin\dev\xp-msvc10\bin;%PATH%
IF EXIST D:\dev\bin\dev\xp-msvc10\bin set SCSDLLDIR=D:\dev\bin\dev\xp-msvc10\bin

rem #################
rem traces
rem ##################
set SCSREQUESTFILTER=getState
set SCS_MSGFILTER_ACCEPTDELAY=60

set SVG_UNLOCK=1


IF NOT EXIST scadasoft.cfg xcopy ..\scadasoft.cfg .

REM Create ScsEnvList if necessary
IF EXIST ScsEnvList goto skipEnvList

FOR /F %%a IN ('hostname') DO set REALMACHINENAME=%%a
echo RTDB: %REALMACHINENAME% {%REALMACHINENAME%:2206} > ScsEnvList
echo HMI1: %REALMACHINENAME% {%REALMACHINENAME%:2208} >> ScsEnvList

:skipEnvList

REM start watchdog
set SCSCONFIG=%SCSPATH%/scadasoft.cfg

:endenv

taonsadmin -l > nul: 2>&1
echo ERRORLEVEL %ERRORLEVEL%
if ERRORLEVEL 1 start /MIN taonameserv