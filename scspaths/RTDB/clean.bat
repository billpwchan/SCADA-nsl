echo off

del /Q log\*
del /Q dbmdump.log
del /Q Database\UserLibs\libCE_SCS.dll

rmdir /S /Q Database\DbmPoller
rmdir /S /Q Database\History
rmdir /S /Q Database\HisServer
rmdir /S /Q Database\binary

