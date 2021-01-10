################################################################################
#
# Namespace: 
# File name: genreplyidl.tcl
# Returns:
# Description: Generates the reply IDL file.
#
################################################################################
#
# Author: Alain Bartolo
# Creation: 03/11/2000
# Modification:
#
################################################################################

global IDLInterface OrderedOperationList startIdl iPath separator

set outputFile [appendStr $iPath $separator [replace [file tail [replace $startIdl "\\" "/"]] ".idl" ""] "reply.idl"]

# Create file with the following format: IdlFileNamereply.idl
set fileId [open $outputFile w 0666]

# if no interface was defined in IDL (only typedefs for example)
# create an empty file based on the file name and exit
if {[info exists IDLInterface] == 0} {

    puts $fileId [generateHeader $outputFile "the Reply IDL file" \
		      "Reply IDL generated from the $startIdl file" "cxx"]
} else {

    # make sure interface name ends with "Idl" 
    checkInterfaceName $IDLInterface $startIdl "genreplyidl"

    # get interface name (get rid of "Idl" suffix)
    set InterfaceName [getInterfaceName $IDLInterface]

    puts $fileId [generateHeader $outputFile "the Reply IDL file" \
		      "Reply IDL generated from the $IDLInterface interface" "cxx"]

    puts $fileId "\#include \"scsredtype.idl\""
    puts $fileId [appendStr "\#include \"" [file tail [replace $startIdl "\\" "/"]] "\""]

    # Add include IDL for each external interface
    puts $fileId  [getIdlIncludes $OrderedOperationList "out"]

    puts $fileId ""

    set replyName "interface $InterfaceName"
    append replyName "ReplyIdl : ScsProcessIdl"

    puts $fileId $replyName
    puts $fileId "\{"

    foreach {operation} $OrderedOperationList {

	set operationName [lindex $operation 1]

	set operationFirstLine "void $operationName"
	append operationFirstLine "Reply(in ScsMessageTag tag,"
	set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]

	set otherArgs [idlOutToInArgs $operationName $argumentFirstCharPos]
	
	puts $fileId $operationFirstLine
	puts $fileId [addWhiteSpaces "in ScsStatusIdl scsStatusIdlResult$otherArgs);" $argumentFirstCharPos]
	
	puts $fileId ""
    }

    puts $fileId "\};"
}