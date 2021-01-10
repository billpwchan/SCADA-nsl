
@echo off

if {%1} == {}  goto :PRINT_USAGE

if {%ORB_NAME%} == {} goto :ERROR_ORBNAME


rem	######## Parse command options #######
	setlocal
	set AFlag=
	set IFlags=
	set DFlags=
	set oFlag=
    set DLLFlag=
	set OutDir=.
	set File=
	set RET=

:BEGIN_PARSING
	if {%1} == {} goto END_PARSING

	set arg=%1
	set option=%arg:~0,1%

	if %option% == - (
		call :PARSE_OPTION %arg% %2 
	) else if "%File%" == "" (
		set File=%1
	)
	if "%RET%" == "ERROR" goto :PRINT_USAGE

	if defined oFlag (
		rem ---- if find flag -o, skip argument OutputDir ----
		shift /1
		set oFlag=
	)

	shift /1
	goto :BEGIN_PARSING
:END_PARSING

	if {%File%} == {} goto :ERROR_NO_IDL

	call :BASENAME %File%
	set BaseName=%RET%

	if %ORB_NAME% == orbix goto :ORBIX_IDL
	if %ORB_NAME% == orbacus goto :ORBACUS_IDL
        if %ORB_NAME% == TAO goto :TAO_IDL
	goto :ERROR_UNKNOWN_ORB



rem	###### ORBIX compilation ######
:ORBIX_IDL
	set IDLflags=-B -s _skel.cpp -c .cpp -h .hh %IFlags% %DFlags%
	if defined AFlag (
		set IDLflags=%IDLflags% -A
	)
	set IDLflags=%IDLflags% -out %OutDir%

	rem ---- lauch ORBIX idl compiler ----
	if {%OSTYPE%} == {cygwin32} (
		cygpath -w %ORBIXHOME%/bin/idl.exe > foo.txt
		for /f %%I in (foo.txt) do %%I %IDLflags% %File%
		del foo.txt
	) else (
		%ORBIXHOME%\bin\idl %IDLflags% %File%	
	)

	rem ---- generate typedefs for _out types ----
	copy %OutDir%\%BaseName%.hh %OutDir%\%BaseName%_skel.hh
goto :CREATE_SOAP


rem	###### ORBacus compilation ######
:ORBACUS_IDL
	set IDLflags=--tie --h-suffix .hh %IFlags% %DFlags% %DLLFlag%
	if not defined AFlag (
		set IDLflags=%IDLflags% --no-type-codes
	)
	set IDLflags=%IDLflags% --output-dir %OutDir%
	rem ---- lauch ORBacus idl compiler ----
	echo "IDL compiler: %File%"
	if {%OSTYPE%} == {cygwin32} (
		cygpath -w %ORBACUSHOME%/bin/idl.exe > foo.txt
		for /f %%I in (foo.txt) do %%I %IDLflags% %File%
		del foo.txt
	) else (
		%ORBACUSHOME%\bin\idl %IDLflags% %File%
	)
	
goto :CREATE_SOAP

rem	###### TAO compilation ######
:TAO_IDL

        set TAO_IDL_FLAGS=-D_SCS_TAO_ -Cw -hc .hh -cs .cpp -ci .inl -hs _skel.hh -ss _skel.cpp -si _skel.inl -hT _skel_tie.hh -sT _skel_tie.cpp -GT -Gd -o %OutDir%
        set IDLflags=%TAO_IDL_FLAGS% %IFlags% %DFlags%
        rem ---- lauch TAO idl compiler ----
	echo "IDL compiler: %File%"
        tao_idl %IDLflags% %File%
        
goto :CREATE_SOAP

rem	###### SOAP generation ######
:CREATE_SOAP
    set File=%File:\=/%
	if {%OSTYPE%} == {cygwin32} (
		cygpath -w %SCSHOME%/dat/gentcl/soapgen.tcl > foo.txt
		for /f %%I in (foo.txt) do tclsh %%I -o%OutDir% %IFlags% %DFlags% %File%
		del foo.txt
	) else (
		tclsh %SCSHOME%\dat\gentcl\soapgen.tcl -o%OutDir% %IFlags% %DFlags% %File%
	)
goto :EOF


rem  ############################# END OF MAIN #############################



rem    ###### Procedure parse option ######
:PARSE_OPTION
	set _arg=%1
 	set _flag=%arg:~0,2%
	set RET=

	if %_flag% == -A (
		set AFlag=1
	) else if %_flag% == -I (
		set IFlags=%IFlags% %arg:\=/%
	) else if %_flag% == -D (
		set DFlags=%DFlags% %arg%
	) else if %_flag% == -o (
		if {%2} == {} (
			call :ERROR_OUTPUT_NOT_DEFINED
			set RET=ERROR
		) else (
			set OutDir=%2
			set oFlag=1
		)
    ) else if %_flag% == -- (
        set DLLFlag=--dll-import %arg:~12%
	) else (
		echo Unkown Option: %arg%
		set RET=ERROR
	)
goto :EOF



rem    ###### Procedure base name ######
:BASENAME
	setlocal
	set X=%1
	set X=%X:.idl=%
	set X=%X:\= %
	call :SUB_BASENAME %X%
	endlocal & set RET=%RET%
goto :EOF

:SUB_BASENAME
	if not {%2} == {} (
		shift /1
		goto :SUB_BASENAME
	)
	set RET=%1
goto :EOF



rem    ###### Usage ######
:PRINT_USAGE
	echo Usage:
	echo   scsidlsoap [options] idl_file
	echo Options:
	echo   -o DIR:       Write generated files to directory DIR.
	echo   -A:           Generate type codes and insertion and
	echo                 extraction functions for the any type.
	echo   -IDIR:        Put DIR in the include file search path.
	echo   -DNAME:       Predefine the macro NAME to be 1 within the IDL file.
	echo   -DNAME=DEF:   Predefine the macro NAME to be DEF.
goto :EOF

rem   ###### OUTPUT DIR NOT PROVIDED #######
:ERROR_OUTPUT_NOT_DEFINED
	echo option -o must be followed by the output directory.
goto :EOF


rem   ###### ORB_NAME NOT DEFINED #######
:ERROR_ORBNAME
	echo Environment variable ORB_NAME not defined.
	endlocal
goto :EOF


rem	###### Unknown ORB ######
:ERROR_UNKNOWN_ORB
	echo ORB defined by ORB_NAME (%ORB_NAME%) not supported.
	endlocal
goto :EOF


rem   ###### NO IDL DEFINED ###### 
:ERROR_NO_IDL
	echo No idl file specified.
	endlocal
goto :EOF




