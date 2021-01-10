echo off

del /Q log\*
del /Q Profiles\*.snap
del /Q DpcVarServer
del /Q dbmdump.log
del /Q Database\UserLibs\libCE_SCS.dll
del /Q Alarms\UserLibs\libstdautomaton.dll
del /Q *.pid
rmdir /S /Q Alarms\EventList
rmdir /S /Q Database\DbmPoller
rmdir /S /Q Database\History
rmdir /S /Q Database\HisServer
rmdir /S /Q Database\binary
rmdir /S /Q dac\spy
rmdir /S /Q LT
rmdir /S /Q snapshots
rmdir /S /Q Replay
