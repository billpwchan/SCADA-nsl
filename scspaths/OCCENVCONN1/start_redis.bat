@echo "===================="
@echo off


set curdir=%~dp0
set REDIS_HOME=%curdir:\=/%

REM ================================================================
REM Check if local instance of Redis is already started
REM if instance is already started : exit
REM Get local port of redis instance
for /f  "tokens=1,2* delims= " %%i in ('type redis\conf\redis.conf ^|find "port"') do (
	echo Ligne: %%i %%j
	set local_port=%%j
)

REM Test connection with local instance
call start_redis_tool  localhost %local_port% --connect
echo : %errorlevel%
IF %errorlevel%==0 goto alreadyrunning
REM ================================================================


REM ================================================================
REM Check if remote instance of Redis is already started
REM Get host and port of  remote instance
for /f  "tokens=1,2,3* delims= " %%i in ('type redis\conf\redis-slave.conf ^|find "slaveof"') do (
	echo Ligne: %%i %%j %%k
	set slave_host=%%j
	set slave_port=%%k
)

echo slave_host=%slave_host%
echo slave_port=%slave_port%

REM Test connection with remote  instance
REM if remote is not started : local instance is started with default configuration %REDIS_HOME%redis/conf/redis.conf
call start_redis_tool  %slave_host% %slave_port% --connect
echo : %errorlevel%
IF %errorlevel%==1 goto start_node

REM if remote instance is started: get the role of the remote instance (master or slave ?)
set redisRemoteNode="slave"
for /f  %%A in ('%curdir%redis\bin\redis-cli -h %slave_host% -p %slave_port% ROLE^|find "master"')  do (
	set redisRemoteNode=%%A
	echo Status: %slave_host% is %%A
)
REM ================================================================

REM ================================================================
REM if the role of the remote instance is master:  local instance is started with slave configuration %REDIS_HOME%redis/conf/redis-slave.conf
REM if the role of the remote instance is slave:  
REM		remote instance is turned in master role %REDIS_HOME%redis/conf/redis-slave.conf
REM		local instance is started with slave configuration %REDIS_HOME%redis/conf/redis-slave.conf
echo "Redis Remote Node Role: %redisRemoteNode%"
if "%redisRemoteNode%" == "master" (goto start_node_slave) else (goto turn_remote_in_master)

:start_node
echo Starting redis node default configuration
start /B /WAIT %REDIS_HOME%redis/bin/redis-server.exe %REDIS_HOME%redis/conf/redis.conf
goto eof

:turn_remote_in_master
echo Remote redis node %slave_host% %slave_port% is in slave role
echo Turn the remote server in master role
echo Execute Command "%curdir%redis\bin\redis-cli -h %slave_host% -p %slave_port% slaveof no one"
%curdir%redis\bin\redis-cli -h %slave_host% -p %slave_port% slaveof no one
timeout 5

:start_node_slave
echo Starting redis node in slave role 
start /B /WAIT %REDIS_HOME%redis/bin/redis-server.exe %REDIS_HOME%redis/conf/redis-slave.conf
goto eof

:alreadyrunning
echo Local Redis Node is Already running
goto eof

:eof
exit /b %errorlevel%
REM ================================================================
