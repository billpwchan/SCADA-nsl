@echo "===================="
@echo on

title BA_SCADA1_NODE1

set arg1=%1
set arg2=%2

set srvname=%arg1:~2,80%
set physenv=%arg2:~2,80%
set SCS_ARGS=-Dscadasoft.servername=%srvname% -Dscadasoft.physicalenv=%physenv% -Dscadasoft.remote.envname=%REMOTE_ENV%

REM 
set "JAVA_OPTS=-Xms600M -Xmx1050M"
set JAVA_OPTS=%JAVA_OPTS% -XX:OnError="taskkill -F -PID %%p " -XX:OnOutOfMemoryError="taskkill -F -PID %%p "

IF EXIST %SOFTS_DIR%\jdk1.8.0_102_x86 set JAVA_HOME32=%SOFTS_DIR%\jdk1.8.0_102_x86
IF EXIST %SOFTS_DIR%\zulujdk8.0.153 set JAVA_HOME32=%SOFTS_DIR%\zulujdk8.0.153

REM uncomment to use JMX locally when you cannot control the firewall
REM set JAVA_OPTS=%JAVA_OPTS% -Djava.rmi.server.hostname=127.0.0.1
REM set JAVA_OPTS=%JAVA_OPTS% -Dcom.sun.management.jmxremote=true
REM set JAVA_OPTS=%JAVA_OPTS% -Dcom.sun.management.jmxremote.port=27091
REM set JAVA_OPTS=%JAVA_OPTS% -Dcom.sun.management.jmxremote.rmi.port=27091
REM set JAVA_OPTS=%JAVA_OPTS% -Dcom.sun.management.jmxremote.authenticate=false
REM set JAVA_OPTS=%JAVA_OPTS% -Dcom.sun.management.jmxremote.local.only=false
REM set JAVA_OPTS=%JAVA_OPTS% -Dcom.sun.management.jmxremote.ssl=false

REM uncomment to use all the power of JMC console
REM set JAVA_OPTS=%JAVA_OPTS% -XX:+UnlockCommercialFeatures -XX:+FlightRecorder

REM uncomment for debugging jna pb use:
REM set JAVA_OPTS=%JAVA_OPTS% -Djna.debug_load.jna=true -Djna.debug_load=true


REM use local compilation to debug
set root=D:\dev\work\scs_source\hvc
REM %JAVA_HOME32%\bin\java.exe -agentlib:jdwp=transport=dt_socket,address=localhost:19019,server=y,suspend=n -server %JAVA_OPTS% -cp %root%\scsjsonapi\target\classes;%root%\scsgenjsonapi\target\classes;%root%\scsapi\target\classes;%root%\restgateway\target\classes;%root%\restmathcmp\target\classes;rest_lib/*;. %SCS_ARGS% com.thalesgroup.scadasoft.rest.GatewayApp

SETLOCAL EnableDelayedExpansion
set PLUGIN_LIST=
FOR /R rest_plugin %%G IN (*.jar) DO set PLUGIN_LIST=!PLUGIN_LIST!%%G,
set RESTGW_JAR=
FOR /R rest_bin %%G IN (restgateway*.jar) DO set RESTGW_JAR=%%G

%JAVA_HOME32%\bin\java.exe -agentlib:jdwp=transport=dt_socket,address=localhost:19019,server=y,suspend=n -server %JAVA_OPTS% %SCS_ARGS% -Dloader.path=%PLUGIN_LIST% -jar %RESTGW_JAR%