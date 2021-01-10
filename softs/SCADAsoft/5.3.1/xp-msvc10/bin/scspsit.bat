
@echo off
if "%ORB_NAME%" == "" (
	echo Environment variable ORB_NAME not defined.
	goto :EOF

) else if "%ORB_NAME%" == "orbix" (
	psit.exe %1 %2 %3 %4 %5 %6
	goto :EOF

) else if "%ORB_NAME%" == "orbacus" (
	orbacus_psit.exe %1 %2 %3 %4 %5 %6	
	goto :EOF
        
) else if "%ORB_NAME%" == "TAO" (
	orbacus_psit.exe %1 %2 %3 %4 %5 %6	
	goto :EOF
        
) else (
	echo ORB defined in environment variable ORB_NAME not supported
	goto :EOF
)
