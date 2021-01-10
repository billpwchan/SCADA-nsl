echo off
title BA_SCADA1_NODE1_TERRACOTTA

xcopy  /Y /I BAConnectorConfiguration.xml.prod BAConnectorConfiguration.xml

set JAVA_HOME=%SOFTS_DIR%\jdk1.7.0_80_x64
set JRE_HOME=%SOFTS_DIR%\jdk1.7.0_80_x64

setlocal
set TC_INSTALL_DIR=%TERRACOTTA_HOME%

for %%C in ("\bin\java -server -XX:MaxDirectMemorySize=64g" "\bin\java -server -XX:MaxDirectMemorySize=1g" "\bin\java -client  -XX:MaxDirectMemorySize=64g" "\bin\java -client -XX:MaxDirectMemorySize=1g" "\bin\java") do (
  set JAVA_COMMAND=%JAVA_HOME%%%~C
  %JAVA_HOME%%%~C -version > NUL 2>&1
  if not errorlevel 1 (
    goto found_command
  )
)

rem rmi.dgc.server.gcInterval is set an year to avoid system gc in case authentication is enabled
rem users may change it accordingly

:found_command
set CLASSPATH=%TC_INSTALL_DIR%\lib\tc.jar
set OPTS=%SERVER_OPT% -Xms256m
set OPTS=%OPTS% -Dcom.sun.management.jmxremote
set OPTS=%OPTS% -Dsun.rmi.dgc.server.gcInterval=31536000
set OPTS=%OPTS% -Dtc.install-root=%TC_INSTALL_DIR%

set JAVA_OPTS=%OPTS% %JAVA_OPTS%

REM clean temporary dir before startup
rmdir /Q /S terracotta\server-data
rmdir /Q /S terracotta\server-logs
rmdir /Q /S terracotta\server-statistics

%JAVA_COMMAND% -server %JAVA_OPTS% -cp %CLASSPATH% com.tc.server.TCServerMain -n terracotta_scada1_node1 -f terracotta_config.xml

endlocal
