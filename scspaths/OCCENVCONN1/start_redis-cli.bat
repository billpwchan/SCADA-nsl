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

echo Execute Command "%curdir%redis\bin\redis-cli -h localhost -p %local_port%"
%curdir%redis\bin\redis-cli -h localhost -p %local_port%
