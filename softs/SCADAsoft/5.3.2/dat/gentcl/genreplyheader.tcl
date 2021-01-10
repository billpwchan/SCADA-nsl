################################################################################
#
# Namespace: 
# File name: genreplyheader.tcl
# Returns:
# Description: Generates the C++ reply header file.
#
################################################################################
#
# Author: Alain Bartolo
# Creation: 03/11/2000
# Modification:
#
################################################################################

global IDLInterface OrderedOperationList startIdl lPath separator

set outputFile [appendStr $lPath $separator [replace [file tail [replace $startIdl "\\" "/"]] ".idl" ""] "reply_i.hh"]

# Create file with the following format: IdlFileNamereply.idl
set fileId [open $outputFile w 0666]

# if no interface was defined in IDL (only typedefs for example)
# create an empty file based on the file name and exit
if {[info exists IDLInterface] == 0} {

    puts $fileId [generateHeader $outputFile "the Reply C++ header file" \
		      "Reply C++ header file generated from the $startIdl interface" "cxx"]

} else {

    # make sure interface name ends with "Idl" 
    checkInterfaceName $IDLInterface $startIdl "genreplyheader"

    # get interface name (get rid of "Idl" suffix)
    set InterfaceName [getInterfaceName $IDLInterface]
    set className [appendStr $InterfaceName "Reply_i"]

    puts $fileId [generateHeader $outputFile "the Reply C++ header file" \
		      "Reply C++ header file generated from the $IDLInterface interface" "cxx"]

    puts $fileId [appendStr "\#ifndef _SCS_" [string toupper $InterfaceName] "REPLY_I_H_"]
    puts $fileId [appendStr "\#define _SCS_" [string toupper $InterfaceName] "REPLY_I_H_"]
    puts $fileId ""
    puts $fileId "\#include \"msgfilter.h\""
    puts $fileId "\#include \"scs.h\""
    puts $fileId [appendStr "\#include \"" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" "reply_soap.hh"] "\""]
    puts $fileId ""
    puts $fileId [appendStr "class " $className " : virtual public " $InterfaceName "ReplySOAP \{"]
    puts $fileId ""
    puts $fileId "  public:"
    puts $fileId ""
    puts $fileId [appendStr "   $className" "(int nbMaxReplies);"]
    puts $fileId [appendStr "   $className" "(PortableServer::POA_var & poa, int nbMaxReplies);"]
    puts $fileId [appendStr "   ~$className" "(void);"]
    puts $fileId ""

    foreach {operation} $OrderedOperationList {

	set operationName [lindex $operation 1]

	set operationFirstLine [appendStr "   virtual void $operationName" "Reply(const ScsMessageTag & tag,"]
	set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]

	puts $fileId $operationFirstLine

	if {[getNumberOfInoutAndOutArgs $operationName] != 0} {
	    puts $fileId [addWhiteSpaces "const ScsStatusIdl & scsStatusIdlResult," $argumentFirstCharPos]
	} else {
	    puts $fileId [addWhiteSpaces "const ScsStatusIdl & scsStatusIdlResult)" $argumentFirstCharPos]
	}

	# only generate functions if the number of out args is not 0
	if {[getNumberOfInoutAndOutArgs $operationName] != 0} {
	    puts $fileId [appendStr [cxxArgsReply $operationName $argumentFirstCharPos false true] ")"]
	} 

	puts $fileId "    throw(CORBA::SystemException);"
	puts $fileId ""
    }

    puts $fileId "   ScsStatus getResult(const ScsMessageTag & tag, const unsigned int & timeout);"
    puts $fileId ""

    # for each function containing "out" and "inout" arguments
    foreach {operation} $OrderedOperationList {

	set operationName [lindex $operation 1]

	# only generate functions if the number of inout and out args is not 0
	if {[getNumberOfInoutAndOutArgs $operationName] != 0} {
	    set firstOutLine [appendStr "   ScsStatus get" [string toupper $operationName 0 0] "Result(const ScsMessageTag & tag, const unsigned int & timeout, "]
	    set argumentFirstCharPos [expr [string first "(" $firstOutLine ] + 1]
	    puts $fileId [appendStr $firstOutLine [string trimleft [cxxArgsResult $operationName $argumentFirstCharPos false ]] ");"]
	}
    }

    puts $fileId ""

    puts $fileId "  private:"
    puts $fileId ""
    puts $fileId "   ScsMsgFilter  _filter;"
    puts $fileId "   ScsStatusIdl  _result;"
    puts $fileId "   ScsMessageTag _replyTag;"
    puts $fileId "   ScsLock       _replyLock;"
    puts $fileId ""

    foreach {operation} $OrderedOperationList {

	set operationName [lindex $operation 1]

	# only generate functions if the number of out args is not 0
	if {[getNumberOfInoutAndOutArgs $operationName] != 0} {
	    puts $fileId [uniqueOutArgs $operationName 3]
	}
    }

    puts $fileId "\};"
    puts $fileId ""
    puts $fileId "\#endif"
}
