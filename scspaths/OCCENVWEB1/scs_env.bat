rem ######################
rem SCADAsoft Environment
rem ######################
set curdirpath=%~dp0

FOR %%F in (%curdirpath:~0,-1%) do set rootdir=%%~dpF
FOR %%F in (%rootdir:~0,-1%) do set rootdir=%%~dpF
set rootdir=%rootdir:~0,-1%

FOR %%F in (%curdirpath:~0,-1%) do set curdirname=%%~nF

FOR /F %%a IN ('hostname') DO set MACHINENAME=%%a

set USE_LOCALHOST=0
if %MACHINENAME%==W539751 set USE_LOCALHOST=1
if %MACHINENAME%==W536630 set USE_LOCALHOST=1
if %MACHINENAME%==D266885 set USE_LOCALHOST=1
if %MACHINENAME%==W545261 set USE_LOCALHOST=1


IF %curdirpath:~-4,-1%==sby goto standby
REM ELSE
goto setscsenv

:standby
set curdirname=%curdirname:~,-3%
set MACHINENAME=p-dummy
goto setscsenv

:setscsenv

title %SCSENV%_CMD

REM
set SOFTS_DIR=%rootdir%\softs

REM SCSHOME
set SCSHOME=%SOFTS_DIR%\SCADAsoft\5.3.2
REM set SCSHOME=%SOFTS_DIR%\SCADAsoft\5.3.1
set SCSARCH=xp-msvc10
set SCSDLLDIR=%SCSHOME%\%SCSARCH%\dll

REM JAVA
set JAVA_HOME=%SOFTS_DIR%\jdk1.6.0_34
set JAVA_HOME32=%SOFTS_DIR%\jdk1.6.0_34
IF EXIST %SOFTS_DIR%\jdk6_64b set JAVA_HOME=%SOFTS_DIR%\jdk6_64b
set PATH=%JAVA_HOME%\bin;%PATH%

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

REM tomcat use local install
set CATALINA_HOME=%curdirpath%\apache-tomcat-7.0.59

REM terracotta
set TERRACOTTA_HOME="%SOFTS_DIR%\terracotta-3.6.1"

REM geoserver
set GEOSERVER_HOME=%SOFTS_DIR%\geoserver-2.6.2

REM nginx
set NGINX_HOME=%SOFTS_DIR%\nginx-1.7.9
set PATH=%NGINX_HOME%;%PATH%

REM set SCADAsoft path
set SCSHOME=%SCSHOME:/=\%
set PATH=%SCSHOME%\%SCSARCH%\bin;%SCSHOME%\%SCSARCH%\dll;%SCSHOME%\%SCSARCH%\dll\rwav;%SCSHOME%\%SCSARCH%\dll\ilog;%SCSHOME%\%SCSARCH%\dll\msvc;%SCSHOME%\%SCSARCH%\dll\xerces;%PATH%

REM reset path
set SCSHOME=%SCSHOME:\=/%

set curdir=%cd%
set SCSPATH=%curdir:\=/%
IF EXIST bin set PATH=%SCSPATH:/=\%\bin;%PATH%

IF EXIST A:\bin\dev\msvc10\bin set PATH=A:\bin\dev\msvc10\bin;%PATH%
IF EXIST A:\bin\dev\msvc10\bin set SCSDLLDIR=A:\bin\dev\msvc10\bin

rem #################
rem traces
rem ##################
set SCSREQUESTFILTER=getState
set SCS_MSGFILTER_ACCEPTDELAY=60

set SVG_UNLOCK=1

IF %USE_LOCALHOST%==1 set CONFFILESUFFIX=_localhost
IF NOT EXIST scadasoft.cfg copy ..\scadasoft%CONFFILESUFFIX%.cfg scadasoft.cfg 

:checkEnvList
REM Create ScsEnvList if necessary
IF EXIST ScsEnvList goto skipEnvList

FOR /F %%a IN ('hostname') DO set REALMACHINENAME=%%a
set SCSPHYSNAME=%REALMACHINENAME%

IF %USE_LOCALHOST%==1 set REALMACHINENAME=localhost

echo OCCENV: p-dummy (%REALMACHINENAME%) [OCCENVA] {%REALMACHINENAME%:2104}, %SCSPHYSNAME% [OCCENVB] {%REALMACHINENAME%:2105} > ScsEnvList
REM echo SRV1: p-dummy (%REALMACHINENAME%) [SRV1A] {%REALMACHINENAME%:2104}, %SCSPHYSNAME% [SRV1B] {%REALMACHINENAME%:2105} > ScsEnvList
echo HMI1: %SCSPHYSNAME% [HMI1]  {%REALMACHINENAME%:2106} >> ScsEnvList
echo OCCENVWEB1: %SCSPHYSNAME% [OCCENVWEB1]  {%REALMACHINENAME%:2107} >> ScsEnvList
REM echo WEB1: %SCSPHYSNAME% [WEB1]  {%REALMACHINENAME%:2107} >> ScsEnvList
echo SRV2: p-dummy (%REALMACHINENAME%) [SRV2A] {%REALMACHINENAME%:2110}, %SCSPHYSNAME% [SRV2B] {%REALMACHINENAME%:2111} >> ScsEnvList
echo WEB2: %SCSPHYSNAME% [WEB2]  {%REALMACHINENAME%:2112} >> ScsEnvList
echo WEB3: %SCSPHYSNAME% [WEB3]  {%REALMACHINENAME%:2113} >> ScsEnvList
echo SRV1rpl: %SCSPHYSNAME% [SRV1A] {%REALMACHINENAME%:2114} >> ScsEnvList
echo SRV2rpl: %SCSPHYSNAME% [SRV2A] {%REALMACHINENAME%:2115} >> ScsEnvList
echo HMI1rpl: %SCSPHYSNAME% [HMI1]  {%REALMACHINENAME%:2116} >> ScsEnvList
echo HIST: %SCSPHYSNAME% [HIST]  {%REALMACHINENAME%:2117} >> ScsEnvList
echo OCCENVCONN1: %SCSPHYSNAME% [OCCENVCONN1]  {%REALMACHINENAME%:2118} >> ScsEnvList
REM echo HVSRV1N1: %SCSPHYSNAME% [HVSRV1N1]  {%REALMACHINENAME%:2118} >> ScsEnvList
echo HVSRV1N2: %SCSPHYSNAME% [HVSRV1N2]  {%REALMACHINENAME%:2119} >> ScsEnvList
echo HVSRV2N1: %SCSPHYSNAME% [HVSRV2N1]  {%REALMACHINENAME%:2120} >> ScsEnvList
echo HVSRV2N2: %SCSPHYSNAME% [HVSRV2N2]  {%REALMACHINENAME%:2121} >> ScsEnvList

:skipEnvList

set NSOPT=
IF %USE_LOCALHOST%==1 set NSOPT=-s

taonsadmin -l > nul: 2>&1
echo ERRORLEVEL %ERRORLEVEL%
if ERRORLEVEL 1 start /MIN taonameserv %NSOPT%