
cd /D %~dp0
call scs_env.bat 

REM copy ScsEnvTable.eclipse ScsEnvTable
REM copy BAConnectorConfiguration.xml.eclipse BAConnectorConfiguration.xml

set PATH=%SOFTS_DIR%\jre7\bin;%PATH%

set ECLIPSE_HOME=%SOFTS_DIR%\eclipse
%ECLIPSE_HOME%\eclipse.exe

REM copy ScsEnvTable.prod ScsEnvTable
REM copy BAConnectorConfiguration.xml.prod BAConnectorConfiguration.xml
