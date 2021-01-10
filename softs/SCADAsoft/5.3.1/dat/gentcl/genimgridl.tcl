################################################################################
#
# Namespace: 
# File name: genimgridl.tcl
# Returns:
# Description: Generates the Input Manager IDL file.
#
################################################################################
#
# Author: Alain Bartolo
# Creation: 03/11/2000
# Modification:
#
################################################################################

global IDLInterface OrderedOperationList startIdl iPath separator

set outputFile [appendStr $iPath $separator "inputmgr_" [file tail [replace $startIdl "\\" "/"]]]

# Create file with the following format: IdlFileNamereply.idl
set fileId [open $outputFile w 0666]

# if no interface was defined in IDL (only typedefs for example)
# create an empty file based on the file name and exit
if {[info exists IDLInterface] == 0} {

    puts $fileId [generateHeader $outputFile "the Input Manager IDL file" \
		      "Input Manager IDL generated from the $startIdl file" "cxx"]

} else {

    # make sure interface name ends with "Idl" 
    checkInterfaceName $IDLInterface $startIdl "genimgridl"

    # get interface name (get rid of "Idl" suffix)
    set InterfaceName [getInterfaceName $IDLInterface]

    puts $fileId [generateHeader $outputFile "the Input Manager IDL file" \
		      "Input Manager IDL generated from the $IDLInterface interface" "cxx"]

    puts $fileId "\#include <scsredtype.idl>"

    # Replace Windows NT paths by a UNIX path since GNU's basename only works on UNIX
    # style paths.
    puts $fileId [appendStr "\#include <" [file tail [replace $startIdl "\\" "/"]] ">"]

    # Add include IDL for each external interface
    #puts $fileId  [getIdlIncludes $OrderedOperationList "all"]

    puts $fileId ""
    puts $fileId [appendStr "interface InputMgr_$InterfaceName" "Idl : ScsProcessIdl"]
    puts $fileId "\{"
    puts $fileId "   // Set priority request"
    puts $fileId "   oneway void setPriority(in unsigned short priority);"
    puts $fileId ""

    foreach {operation} $OrderedOperationList {

	set operationName [lindex $operation 1]

	# find out position of first '(' to pretty print arguments.
	set operationFirstLine "   void $operationName"
	append operationFirstLine "(in ScsProcessIdl source,"
	set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]

	set otherArgs [idlInArgs $operationName $argumentFirstCharPos]

	puts $fileId $operationFirstLine
	puts $fileId [addWhiteSpaces "in unsigned long timeout," $argumentFirstCharPos]
  puts $fileId [addWhiteSpaces "in unsigned short priority," $argumentFirstCharPos]
	puts $fileId [addWhiteSpaces "in ScsMessageTag tag," $argumentFirstCharPos]
	puts $fileId [addWhiteSpaces "in ScsTimeValIdl onlineTime$otherArgs);" $argumentFirstCharPos]
	puts $fileId ""
    }

    puts $fileId "\};"
}
