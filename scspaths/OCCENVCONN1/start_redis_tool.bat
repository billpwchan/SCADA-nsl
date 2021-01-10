@echo "===================="
@echo on

title REST_MGR_TOOL

set host=%1
set port=%2
set option=%3

set SOFTS_DIR=%~dp0../../softs
echo %SOFTS_DIR%

IF EXIST %SOFTS_DIR%\jdk1.8.0_102_x86 set JAVA_HOME32=%SOFTS_DIR%\jdk1.8.0_102_x86
REM SRA: pas dans le SCSTraining/softs
IF EXIST %SOFTS_DIR%\ojdk1.8.0_131_x86 set JAVA_HOME32=%SOFTS_DIR%\ojdk1.8.0_131_x86

%JAVA_HOME32%\bin\java.exe -cp redis/libs/* RedisManagerTool %host% %port% %option%
echo : %errorlevel%
exit /b %errorlevel%