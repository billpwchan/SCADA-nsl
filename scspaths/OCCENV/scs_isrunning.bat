echo off

cd /D %~dp0
call scs_env.bat

set ASCPID=
for /f "tokens=2" %%x in ('scspsit -h 127.0.0.1 AscManager@%SCSENV%_%MACHINENAME% ^| FIND "AscManager"') do set ASCPID=%%x
if not defined ASCPID goto:ascnotrunning
set ASCPIDEXIST=
for /f "tokens=2" %%x in ('tasklist /FI "IMAGENAME eq ascmanager.exe" /NH 2^>nul: ^| FIND " %ASCPID% "') do set ASCPIDEXIST=1
if not defined ASCPIDEXIST goto:ascnotrunning
for /f "tokens=1" %%x in ('scspsit  -h 127.0.0.1 -p AscManager@%SCSENV%_%MACHINENAME% ^| FINDSTR exception ^| FINDSTR /v TIMEOUT') do goto:ascnotrunning

echo.[INFO] AscManager@%SCSENV%_%MACHINENAME% is running.
exit /B 0

:ascnotrunning
echo.[INFO] AscManager@%SCSENV%_%MACHINENAME% is not running.
exit /B 1