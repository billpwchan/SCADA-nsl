
@echo off


if {%1} == {}  goto :PRINT_USAGE

rem	######## Parse command options #######
	setlocal
	set iFlag=.
	set jFlag=..\libimg\
	set kFlag=..\lib\
	set lFlag=..\lib\
	set aFlag=0
	set bFlag=0
	set cFlag=0
	set dFlag=0
	set eFlag=0
	set I_Flags=
	set allFlag=1
	set File=
	set RET=

:BEGIN_PARSING
	if {%1} == {} goto END_PARSING

	set arg=%1
	set option=%arg:~0,1%

	if "%option%" == "-" (
		call :PARSE_OPTION %arg% %2 
	) else if "%File%" == "" (
		set File=%1
	)
	if "%RET%" == "ERROR" goto :PRINT_USAGE

	if defined waitDir (
		rem ---- if find flag -i -j -k or -l, skip argument DIR ----
		shift /1
		set waitDir=
	)

	shift /1
	goto :BEGIN_PARSING
:END_PARSING

	if {%File%} == {} goto :ERROR_NO_IDL
	
	if not exist %jFlag% mkdir %jFlag% 
	if not exist %kFlag% mkdir %kFlag% 

	call :BASENAME %File%
	set BaseName=%RET%

	rem ## launch generation ##

	if not "%allFlag%" == "0" (
		set aFlag=1
		set bFlag=1
		set cFlag=1
		set dFlag=1
		set eFlag=1
	)    

	if not "%aFlag%" == "0" (
		call :GENERATE_IMG_IDL %iFlag%
	)

	if not "%bFlag%" == "0" (
		call :GENERATE_IMG_CODE %jFlag%
	)

	if not "%cFlag%" == "0" (
		call :GENERATE_PROXY_CODE %kFlag%
	)

	if not "%dFlag%" == "0" (
		call :GENERATE_REPLY_CODE %lFlag%
	)

	if not "%eFlag%" == "0" (
		call :GENERATE_REPLY_IDL %iFlag%
	)


goto :EOF

rem ########################## END OF MAIN #############################



rem   ###### Generate Input Manager IDL file ######
:GENERATE_IMG_IDL
	echo Generating Input Manager IDL:           %1\\inputmgr_%BaseName%.idl

	if {%OSTYPE%} == {cygwin32} (
		cygpath -w %SCSHOME%/dat/gentcl/proxygen.tcl > foo.txt
		for /f %%I in (foo.txt) do tclsh %%I -a -i%iFlag% %I_Flags% %File%
		del foo.txt
	) else (
		tclsh %SCSHOME%\dat\gentcl\proxygen.tcl -a -i%iFlag% %I_Flags% %File%
	)

goto :EOF



rem   ###### Generate Input Manager C++ header and code ######
:GENERATE_IMG_CODE
	echo Generating Input Manager C++ header:    %1\\img%BaseName%_i.hh
	echo Generating Input Manager C++ code:      %1\\img%BaseName%_i.cpp

	if {%OSTYPE%} == {cygwin32} (
		cygpath -w %SCSHOME%/dat/gentcl/proxygen.tcl > foo.txt
		for /f %%I in (foo.txt) do tclsh %%I -b -j%jFlag% %I_Flags% %File%
		del foo.txt
	) else (
		tclsh %SCSHOME%\dat\gentcl\proxygen.tcl -b -j%jFlag% %I_Flags% %File%
	)

goto :EOF


rem   ###### Generate Proxy C++ header and code ######
:GENERATE_PROXY_CODE
	echo Generating C++ Proxy header             %1\\%BaseName%proxy.hh
	echo Generating C++ Proxy code               %1\\%BaseName%proxy.cpp

	if {%OSTYPE%} == {cygwin32} (
		cygpath -w %SCSHOME%/dat/gentcl/proxygen.tcl > foo.txt
		for /f %%I in (foo.txt) do tclsh %%I -c -k%kFlag% %I_Flags% %File%
		del foo.txt
	) else (
		tclsh %SCSHOME%\dat\gentcl\proxygen.tcl -c -k%kFlag% %I_Flags% %File%
	)

goto :EOF


rem ###### Generate Reply C++ header and code ######
:GENERATE_REPLY_CODE
	echo Generating C++ reply header             %1\\%BaseName%reply_i.hh
	echo Generating C++ reply code               %1\\%BaseName%reply_i.cpp

	if {%OSTYPE%} == {cygwin32} (
		cygpath -w %SCSHOME%/dat/gentcl/proxygen.tcl > foo.txt
		for /f %%I in (foo.txt) do tclsh %%I -d -l%lFlag% %I_Flags% %File%
		del foo.txt
	) else (
		tclsh %SCSHOME%\dat\gentcl\proxygen.tcl -d -l%lFlag% %I_Flags% %File%
	)

goto :EOF


rem   ###### Generate Reply IDL ######
:GENERATE_REPLY_IDL
	echo Generating reply IDL                    %1\\%BaseName%reply.idl

	if {%OSTYPE%} == {cygwin32} (
		cygpath -w %SCSHOME%/dat/gentcl/proxygen.tcl > foo.txt
		for /f %%I in (foo.txt) do tclsh %%I -e -i%iFlag% %I_Flags% %File%
		del foo.txt
	) else (
		tclsh %SCSHOME%\dat\gentcl\proxygen.tcl -e -i%iFlag% %I_Flags% %File%
	)

goto :EOF





rem    ###### Procedure parse option ######
:PARSE_OPTION
	set _arg=%1
 	set _flag=%arg:~0,2%
	set RET=

	if %_flag% == -i (
		if {%2} == {} (
			call :ERROR_DIR_NOT_DEFINED -i
			set RET=ERROR
		) else (
			set iFlag=%2
			set waitDir=1
		)

	) else if %_flag% == -j (
		if {%2} == {} (
			call :ERROR_DIR_NOT_DEFINED -j
			set RET=ERROR
		) else (
			set jFlag=%2
			set waitDir=1
		)

	) else if %_flag% == -k (
		if {%2} == {} (
			call :ERROR_DIR_NOT_DEFINED -k
			set RET=ERROR
		) else (
			set kFlag=%2
			set waitDir=1
		)

	) else if %_flag% == -l (
		if {%2} == {} (
			call :ERROR_DIR_NOT_DEFINED -l
			set RET=ERROR
		) else (
			set lFlag=%2
			set waitDir=1
		)

	) else if %_flag% == -a (
		set allFlag=0
		set aFlag=1
	) else if %_flag% == -b (
		set allFlag=0
		set bFlag=1
	) else if %_flag% == -c (
		set allFlag=0
		set cFlag=1
	) else if %_flag% == -d (
		set allFlag=0
		set dFlag=1
	) else if %_flag% == -e (
		set allFlag=0
		set eFlag=1

	) else if %_flag% == -I (
		set I_Flags=%I_Flags% %arg%

	) else (
		echo ERROR Unkown Option: %arg%
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
	echo scsidlgen [options] idl_file \n
	echo Options:
	echo   -i DIR:      Write generated IDL files to directory DIR.
	echo   -j DIR:      Write generated Input Manager C++ files to directory DIR.
	echo   -k DIR:      Write generated Proxy C++ files to directory DIR.
	echo   -l DIR:      Write generated Reply C++ files to directory DIR.
	echo   -a           Only generate Input Manager IDL file.
	echo   -b           Only generate Input Manager C++ (header + code) files.
	echo   -c           Only generate Proxy C++ (header + code) files.
	echo   -d           Only generate Reply C++ (header + code) files.
	echo   -e           Only generate Reply IDL file.
	echo   -IDIR:        Put DIR in the include file search path.
	echo   By default, all IDL and C++ files are generated with the following paths:
	echo    - IDL files are generated in the current path (./).
	echo    - Input Manager C++ files are generated in \"../libimg\"
	echo    - Proxy C++ files are generated in \"../lib\"
	echo    - Reply C++ files are generated in \"../lib\"
goto :EOF

rem   ######  DIR NOT PROVIDED #######
:ERROR_DIR_NOT_PROVIDED
	echo option %1 must be followed by a directory.
goto :EOF


