@echo "===================="
@echo on

cd /D %~dp0
call scs_env.bat 

set PATH=%JAVA_HOME%\bin;%PATH%

IF NOT EXIST %SOFTS_DIR%\apacheds-2.0.0-M16\instances\default\partitions\hypervisor xcopy /Y /I hypervisor %SOFTS_DIR%\apacheds-2.0.0-M16\instances\default\partitions\hypervisor

cd /d %SOFTS_DIR%\apacheds-2.0.0-M16\bin

apacheds.bat

