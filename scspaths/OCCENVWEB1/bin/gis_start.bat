@echo "===================="
@echo on

cd /D %~dp0

IF NOT EXIST %SCSPATH:/=\%\data_dir mkdir %SCSPATH:/=\%\data_dir

set JAVA_HOME=%SOFTS_DIR%\jdk1.7.0_80

set GEOSERVER_DATA_DIR=%SCSPATH:/=\%\data_dir
set GEOSERVER_HOME=%SOFTS_DIR%\geoserver-2.7

REM set JAVA_OPTS=-Djetty.port=8180 -Xms300M -XX:MaxPermSize=128m
set JAVA_OPTS=-Djetty.port=8180
call %GEOSERVER_HOME%\bin\startup.bat
