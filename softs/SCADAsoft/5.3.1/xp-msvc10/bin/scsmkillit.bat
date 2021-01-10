
@echo off

if {%1} == {} (
    echo Usage:
    echo    scsmkillit.bat process_name_or_id [process_name_or_id] [process_name_or_id] ... 
    echo    scsmkillit.bat -all
    goto :EOF
)



call scspsit.bat > __psit__.txt

if NOT {%1} == {-all} goto KILL_NEXT    
    

rem ----------------
rem  kill all
rem ----------------

setlocal

for /f "delims=" %%I in (__psit__.txt) do set foo=%%I
set foo2=%foo:~0,27%
if ("%foo2%") == ("There are no active servers") (
    echo %foo%
    del /f __psit__.txt  
    endlocal
    goto :EOF
)

endlocal

if {%OSTYPE%} == {cygwin32} (
    grep -U -v "OS-pid" __psit__.txt > __find__.txt
) else (
    %SYSTEMROOT%\system32\find /V "OS-pid" __psit__.txt > __find__.txt
)

for /f "eol=-" %%I in (__find__.txt) do call scskillit.bat %%I

goto END_KILL




rem ---------------------
rem  kill next process
rem ---------------------

:KILL_NEXT
	if {%1} == {} goto END_KILL

    if {%OSTYPE%} == {cygwin32} (
        grep %1 __psit__.txt > __find__.txt
    ) else (
        %SYSTEMROOT%\system32\find "%1" __psit__.txt > __find__.txt
    )
    
    for /f "eol=-" %%I in (__find__.txt) do call scskillit.bat %%I

    shift /1

goto :KILL_NEXT



:END_KILL
   @del /f __psit__.txt
   @del /f __find__.txt

