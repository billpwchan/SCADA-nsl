@echo "===================="
@echo on

title SCADA1_REDIS_NODE1

set curdir=%~dp0
set REDIS_HOME=%curdir:\=/%

%REDIS_HOME%redis/bin/redis-server.exe %REDIS_HOME%redis/conf/redis.conf