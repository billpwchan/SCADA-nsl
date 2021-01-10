@echo off

if "%JAVA_HOME%" == "" goto error
echo JAVA_HOME=%JAVA_HOME%

if "%HEARTS_HOME%" == "" goto error
echo HEARTS_HOME=%HEARTS_HOME%

if "%SCSHOME%" == "" goto error
echo SCSHOME=%SCSHOME%

set LIB=%SCSHOME%/hearts/jar

set LOCALCLASSPATH=%LIB%/heartscore.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/heartsplugin.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/hibernate/antlr-2.7.6.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/hibernate/commons-collections-3.1.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/hibernate/dom4j-1.6.1.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/hibernate/hibernate3.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/hibernate/hibernate-jpa-2.0-api-1.0.0.Final.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/hibernate/javassist-3.12.0.GA.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/hibernate/jta-1.1.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/hibernate/slf4j-api-1.6.1.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/jacorb/avalon-framework-4.1.5.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/jacorb/jacorb.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/jacorb/logkit-1.2.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/log4j/log4j.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/slf4j/slf4j-log4j12-1.6.1.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%LIB%/jdbc/mysql-connector-java-5.0.4-bin.jar

set JAVA_PARAM=-server -mx1024M -ss1M -XX:SurvivorRatio=32 
"%JAVA_HOME%/bin/java" %JAVA_PARAM% -cp %LOCALCLASSPATH% -Dapplication.home=%HEARTS_HOME% com.thales.scadasoft.hearts.core.business.Launcher %*

goto end

:error
echo No value for mandatory environment variable !!
echo    JAVA_HOME=%JAVA_HOME%
echo    HEARTS_HOME=%HEARTS_HOME%
echo    SCSHOME=%SCSHOME%

:end