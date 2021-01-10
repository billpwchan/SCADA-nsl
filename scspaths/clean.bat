echo on

for /D %%i in (*) do del /Q %%i\ScsEnvList
for /D %%i in (*) do del /Q %%i\scadasoft.cfg

rmdir /S /Q SRV1sby
rmdir /S /Q SRV2sby
rmdir /S /Q SRV1rpl
rmdir /S /Q SRV2rpl
rmdir /S /Q HMI1rpl

for /D %%i in (*) do start /MIN /D %%i cmd /C clean.bat
