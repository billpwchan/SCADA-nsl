@echo off

REM MySQL Import cmd (for memory) : 
REM %MYSQL_HOME%\bin\mysql --user=%USER% --password=%PSWD% %DATABASE% < %FILENAME%

if "%1%" == "" goto error

REM The name of the TABLE is passed by the HEARTS Server,
REM but can be used manually if the user knows the name of the TABLE
set TABLE_NAME=%1

REM To change depending on project settings
set ZIP_HOME=D:\softs\7-Zip
set MYSQL_HOME=D:\softs\MySQL\MySQL Server 5.6
set EXPORT_DIR=D:\Temp\ROOT_SLOT\space3\SCDMSRVLT\TABLE_BACKUP

REM To change depending on project settings
set USER=root
set PSWD=password
set DATABASE=hearts

REM Fixed part of the script
set CURRENT_DATE=%DATE:~6,4%%DATE:~3,2%%DATE:~0,2%
set CURRENT_TIME=%TIME:~0,2%%TIME:~3,2%%TIME:~6,2%%TIME:~9,2%

REM Replace the spaces in CURRENT_TIME with "0".
set CURRENT_TIME=%CURRENT_TIME: =0%

REM Check if mysqldump.exe can be found.

if exist "%MYSQL_HOME%\bin\mysqldump.exe" goto mysql_exists
echo == "mysqldump.exe" not found. Cannot continue.
goto end

:mysql_exists:

REM Create a specific folder named by the current date
set EXPORT_DIR=%EXPORT_DIR%\%2%CURRENT_DATE%
if exist %EXPORT_DIR% goto exist
mkdir %EXPORT_DIR%

:exist
set FILENAME=%EXPORT_DIR%\%TABLE_NAME%#%CURRENT_DATE%%CURRENT_TIME%
set SQLFILENAME=%FILENAME%.sql
set ZIPFILENAME=%FILENAME%.zip

@echo on
"%MYSQL_HOME%\bin\mysqldump" --user=%USER% --password=%PSWD% %DATABASE% %TABLE_NAME% > %SQLFILENAME%
@echo off
echo == TABLE '%TABLE_NAME%' saved in the file '%SQLFILENAME%'.

@echo on
%ZIP_HOME%\7z a -tzip %ZIPFILENAME% %SQLFILENAME% > NUL
@echo off
echo == File '%SQLFILENAME%' compressed in the archive file '%ZIPFILENAME%'.

del %SQLFILENAME%
echo == File '%SQLFILENAME%' removed.

goto end

:error
echo Invalid parameter
echo Usage:  %0% TABLE_NAME
echo         TABLE_NAME: The name of the table to dump in a file.

:end
