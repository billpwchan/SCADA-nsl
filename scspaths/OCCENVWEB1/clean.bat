echo on

del /Q log\*

REM geoserver
REM rmdir /Q /S data_dir

REM nginx
del nginx.pid
rmdir /Q /S temp

REM tomcat
set TOMCATROOT=apache-tomcat-6.0.37
del /Q %TOMCATROOT%\logs\*
rmdir /Q /S %TOMCATROOT%\work
rmdir /Q /S %TOMCATROOT%\temp

set TOMCATROOT=apache-tomcat-7.0.59
del /Q %TOMCATROOT%\logs\*
rmdir /Q /S %TOMCATROOT%\work
rmdir /Q /S %TOMCATROOT%\temp

set TOMCATROOT=apache-tomcat-8.0.23
del /Q %TOMCATROOT%\logs\*
rmdir /Q /S %TOMCATROOT%\work
rmdir /Q /S %TOMCATROOT%\temp