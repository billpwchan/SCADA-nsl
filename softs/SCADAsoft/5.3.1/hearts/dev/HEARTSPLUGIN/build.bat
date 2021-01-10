
echo JAVA_HOME: %JAVA_HOME%
if "%JAVA_HOME%" == "" goto errorJava

rem ------------------------------------------------------
rem 	Repertoire ou sont situees les librairies ne devrait y en avoir qu'un, relatif au chemin courant
rem ------------------------------------------------------
set HOME=%~dp0
set LIB=%HOME%lib

rem ------------------------------------------------------
rem 	Fabrication du ClassPath
rem ------------------------------------------------------
set ANT_TASK=all
set ANT_FILE=%HOME%build.xml
set LOCALCLASSPATH=%LIB%\ant.jar
set LOCALCLASSPATH=%LOCALCLASSPATH%;%JAVA_HOME%\lib\tools.jar

echo ----------------------------------------
echo                  START
echo ----------------------------------------
echo LOCALCLASSPATH: %LOCALCLASSPATH%
"%JAVA_HOME%\bin\java.exe" -classpath %LOCALCLASSPATH% org.apache.tools.ant.Main -buildfile %ANT_FILE% %ANT_TASK%

goto end


:errorJava

echo ERROR: JAVA_HOME not found in your environment.
echo Please, set the JAVA_HOME variable in your environment to match the
echo location of the Java Virtual Machine you want to use.
goto end


:end

echo ----------------------------------------
echo                  END
echo ----------------------------------------

pause

