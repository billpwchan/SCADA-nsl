#!/bin/sh 
# The backslash makes the next line a comment \
exec $TCLHOME/bin/tclsh "$0" ${1+"$@"}

global argv0

set startIdl ""
set tmpFile ""

# Where the output files will be located
set outputPath ""

set system [lindex [array get tcl_platform platform] 1]
if { [string compare $system "windows"] == 0 } {
    set separator "\\"
} else {
    set separator "/"

}

set soapPath $env(SCSHOME)
append soapPath $separator
append soapPath "dat"
append soapPath $separator
append soapPath "gentcl"
append soapPath $separator

# source proxy generator utility procedures
set utils $soapPath
append utils "scsgenutil.tcl"
source $utils

proc usage {extraMsg} {
    global argv0

    set toReturn $extraMsg
    append toReturn "\nusage: "
    append toReturn $argv0
    append toReturn " -IDIR IDL_file\n"
    append toReturn "        where IDL_file is a valid IDL file with only one interface\n"
    append toReturn "        and DIR adds a directory in the include file search path.\n"

    return $toReturn

}

set includePath ""

foreach arg $argv {
    
    switch -glob -- $arg {
	
	-o* {
	    set outputPath [string range $arg 2 end]
	}

	-I* {
	    append includePath $arg
	    append includePath " "
	}

	*.idl {
	    # IDL file name containing the interface from which all proxy generated
	    # files are constructed.
	    set startIdl $arg
	}
    }
}

# tmpFile is used to receive output from $genProxyProg
# It will contain TCL arrays which are then sourced in current interpreter
set tmpFile ""

if {[string length $startIdl] == 0} {
    puts [usage "No IDL file specified"]
    exit
} else {
    set h [info hostname]
    set tmpFile ".soapgentmp_$h.tcl"
}

# Name of binary which outputs TCL arrays from an IDL to standard output  

if {[string compare $::env(ORB_NAME) "TAO"] == 0} {
    set taooption "-Cw"
} else {
    set taooption ""
}

if { [string compare $system "windows"] == 0 } {
    set genProxyProg "exec scsgen.exe $taooption $includePath $startIdl 2>nul > $tmpFile"
} else {
    set genProxyProg "exec scsgen $taooption $includePath $startIdl 2>/dev/null > $tmpFile"
}

if {[catch $genProxyProg result]} {
    # Binary failed. Output result and exit (avoid outputing
    # TCL stack trace)
    puts "error ($result) while running SCS generator"

    # delete temporary file
    file delete $tmpFile

    exit
}

# Source the generated file
if {[catch {source $tmpFile} result]} {

    puts "error ($result) while sourcing soap temporary file"

    # delete temporary file
    file delete $tmpFile

    exit 1
}

if {[catch {source [appendStr $soapPath "gensoapheader.tcl"]} result] } {

    puts "error ($result) while generating soap header"

    # delete temporary file
    file delete $tmpFile
    exit 1
}

if {[catch {source [appendStr $soapPath "gensoapcode.tcl"]} result] } {

    puts "error ($result) while generating soap code"

    # delete temporary file
    file delete $tmpFile
    exit 1
}

if {[catch {source [appendStr $soapPath "gensoaptypes.tcl"]} result] } {

     puts "error ($result) while generating soap types"

     # delete temporary file
     file delete $tmpFile
     exit 1
}

if {[catch {source [appendStr $soapPath "gensoaptie.tcl"]} result] } {

     puts "error ($result) while generating soap TIE header"

     # delete temporary file
     file delete $tmpFile
     exit 1
}

# delete temporary file
file delete $tmpFile

