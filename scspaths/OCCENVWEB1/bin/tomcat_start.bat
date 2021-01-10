set TOMCATROOT=apache-tomcat-6.0.37
set TOMCATROOT=apache-tomcat-7.0.59
set TOMCATROOT=apache-tomcat-8.0.23
set CATALINA_HOME=%SCSPATH%\%TOMCATROOT%

set JAVA_HOME=%SOFTS_DIR%\jdk1.7.0_79_x86_64
set JRE_HOME=%SOFTS_DIR%\jdk1.7.0_79_x86_64

copy /Y ..\monitoring-configuration.xml  apache-tomcat-8.0.23\conf\hypervisor-configuration\monitoring-configuration.xml
IF %USE_LOCALHOST%==1 copy /Y ..\monitoring-configuration_localhost.xml  apache-tomcat-8.0.23\conf\hypervisor-configuration\monitoring-configuration.xml

IF %SCSENV%==OCCENVWEB1 goto web1
goto web2



:web1
xcopy /Y /I HMI1\monitoring-local.properties  %TOMCATROOT%\conf\hypervisor-configuration
xcopy /Y /I HMI1\mwt-connector-configuration.xml  %TOMCATROOT%\conf\hypervisor-configuration
IF %USE_LOCALHOST%==1 copy /Y HMI1\mwt-connector-configuration_localhost.xml  %TOMCATROOT%\conf\hypervisor-configuration\mwt-connector-configuration.xml
copy /Y ..\subsystems.xml  %TOMCATROOT%\conf\hypervisor-configuration\systemConfiguration\instances\subsystems.xml
IF %USE_LOCALHOST%==1 copy /Y ..\subsystems_localhost.xml  %TOMCATROOT%\conf\hypervisor-configuration\systemConfiguration\instances\subsystems.xml

xcopy /Y /I HMI1\systemConfiguration\local.properties  %TOMCATROOT%\conf\hypervisor-configuration\systemConfiguration
xcopy /Y /I HMI1\server.xml %TOMCATROOT%\conf
xcopy /Y /I HMI1\gis-server.xml %TOMCATROOT%\conf\hypervisor-configuration\widgets\situationView

goto do_start

:web2
xcopy /Y /I HMI2\monitoring-local.properties  %TOMCATROOT%\conf\hypervisor-configuration
xcopy /Y /I HMI2\mwt-connector-configuration.xml  %TOMCATROOT%\conf\hypervisor-configuration
xcopy /Y /I HMI2\systemConfiguration\local.properties  %TOMCATROOT%\conf\hypervisor-configuration\systemConfiguration
xcopy /Y /I HMI2\server.xml %TOMCATROOT%\conf
xcopy /Y /I HMI2\gis-server.xml %TOMCATROOT%\conf\hypervisor-configuration\widgets\situationView


:do_start
set JAVA_OPTS=-Xms300M -XX:MaxPermSize=256M -Xmx3000M
set JAVA_OPTS=%JAVA_OPTS% -XX:+HeapDumpOnOutOfMemoryError -XX:OnError="taskkill -F -PID %%p " -XX:OnOutOfMemoryError="taskkill -F -PID %%p "

%TOMCATROOT%\bin\startup.bat 
