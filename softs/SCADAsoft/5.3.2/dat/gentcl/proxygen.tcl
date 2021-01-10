#!/bin/sh 
# The backslash makes the next line a comment \
exec $TCLHOME/bin/tclsh "$0" ${1+"$@"}

set imgrIdl 0
set imgrCxx 0
set proxyCxx 0
set replyCxx 0
set replyIdl 0
set all 1
set startIdl ""
set tmpFile ""

# Paths for generated files.
set iPath ""
set jPath ""
set kPath ""
set lPath ""

# Name of binary which outputs TCL arrays from an IDL to standard output  
set system [lindex [array get tcl_platform platform] 1]
if { [string compare $system "windows"] == 0 } {
    set separator "\\"
} else {
    set separator "/"

}


# Get path of main script so that path can
# be added to other scripts name 
set pgePath $env(SCSHOME)
append pgePath $separator
append pgePath "dat"
append pgePath $separator
append pgePath "gentcl"
append pgePath $separator

# source proxy generator utility procedures
set utils $pgePath
append utils "scsgenutil.tcl"
source $utils

proc usage {extraMsg} {

    set toReturn $extraMsg
    append toReturn "\nusage: proxygen "
    append toReturn " options IDL_file\n"
    append toReturn "        No options generate all the files in the current directory\n"
    append toReturn "        -a only generates Input Manager IDL file\n"
    append toReturn "        -b only generates Input Manager C++ files (header + code)\n"
    append toReturn "        -c only generates C++ Proxy files (header + code)\n"
    append toReturn "        -d only generates C++ Reply files (header + code)\n"
    append toReturn "        -e only generates Reply Idl file\n"
    append toReturn "        IDL_file is a valid IDL file with a single interface\n"

    return $toReturn
}

# Paths are unspecified by default
set pathSpecified 0
set includePath ""

foreach arg $argv {
        
    switch -glob -- $arg {
	
	-a {
	    #Input Manager Idl
	    set imgrIdl 1
	    set all 0
	}
	
	-b {
	    # Input Manager C++ code & header
	    set imgrCxx 1
	    set all 0
	}

	-c {
	    # C++ Proxy code & header
	    set proxyCxx 1
	    set all 0
	}

	-d {
	    # C++ Reply code & header
	    set replyCxx 1
	    set all 0
	}
	
	-I* {
	    append includePath $arg
	    append includePath " "
	}

	-e { 
	    # IDL reply
	    set replyIdl 1
	    set all 0
	}
	
	-i* {
	    set iPath [string range $arg 2 end]
	}

	-j* {
	    set jPath [string range $arg 2 end]
	}

	-k* {
	    set kPath [string range $arg 2 end]
	}

	-l* {
	    set lPath [string range $arg 2 end]
	}

	*.idl {
	    # IDL file name containing the interface from which all proxy generated
	    # files are constructed.
	    set startIdl $arg
	}

	default {
	    puts [usage "Unknown option $arg"]
	    exit
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
    set tmpFile "proxygen_tmp_$h.tcl"
}

# puts [appendStr $genProxyProg $includePath $startIdl]

if {[string compare $::env(ORB_NAME) "TAO"] == 0} {
    set taooption "-Cw"
} else {
    set taooption ""
}

set system [lindex [array get tcl_platform platform] 1]
if { [string compare $system "windows"] == 0 } {
    set genProxyProg "exec scsgen.exe $taooption $includePath $startIdl 2>nul > $tmpFile"
} else {
    set genProxyProg "exec scsgen $taooption $includePath $startIdl 2>/dev/null > $tmpFile"
}

if {[catch $genProxyProg result]} {
    puts "proxygen.tcl: `scsgen` exited with an error."

    # Binary failed. Output result and exit (avoid outputing
    # TCL stack trace)
    puts $result

    # delete temporary file
    file delete $tmpFile

    exit
}


# Source the generated file
if {[catch {source $tmpFile} result]} {
    puts $result

    # delete temporary file
    file delete $tmpFile

    exit 1
}

proc procImgrIdl {} {
    upvar pgePath pgePath

    source [appendStr $pgePath "genimgridl.tcl"]
}

proc procImgrCxx {} {
    upvar pgePath pgePath

    source [appendStr $pgePath "geninputmgrheader.tcl"]
    source [appendStr $pgePath "geninputmgrcode.tcl"]
}

proc procProxyCxx {} {
    upvar pgePath pgePath 

    source [appendStr $pgePath "genproxyheader.tcl"]
    source [appendStr $pgePath "genproxycode.tcl"]
}

proc procReplyCxx {} {
    upvar pgePath pgePath 

    source [appendStr $pgePath "genreplyheader.tcl"]
    source [appendStr $pgePath "genreplycode.tcl"]
}

proc procReplyIdl {} {
    upvar pgePath pgePath 

    source [appendStr $pgePath "genreplyidl.tcl"]
}

if {[catch {
    foreach arg {"imgrIdl" "imgrCxx" "proxyCxx" "replyCxx" "replyIdl"} {
    

	# If all is set or for each possible argument do:
	if {$all == 1} {
	
	    # call the procedure (format = procArgName)
	    [appendStr "proc" [string toupper $arg 0 0]] 
	} else {
	    
	    if {(([string compare $arg "imgrIdl"] == 0) && ($imgrIdl == 1)) ||
	    (([string compare $arg "imgrCxx"] == 0) && ($imgrCxx == 1)) ||
	    (([string compare $arg "proxyCxx"] == 0) && ($proxyCxx == 1)) ||
	    (([string compare $arg "replyCxx"] == 0) && ($replyCxx == 1)) ||
	    (([string compare $arg "replyIdl"] == 0) && ($replyIdl == 1))} {
		# call the procedure (format = procArgName)
		[appendStr "proc" [string toupper $arg 0 0]] 
	    }
	}
    } 
} result]} {
    # delete temporary file
    file delete $tmpFile
    puts $result
    exit 1
}

# delete temporary file
  file delete $tmpFile

