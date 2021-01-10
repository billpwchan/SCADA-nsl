################################################################################
#
# Namespace: 
# File name: geninputmgrheader.tcl
# Returns:
# Description: Generates the Input Manager C++ header file.
#
################################################################################
#
# Author: Alain Bartolo
# Creation: 03/11/2000
# Modification:
#
################################################################################

global IDLInterface OrderedOperationList startIdl jPath separator


    
set outputFile [appendStr $jPath $separator "img" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" ""] "_i.hh"]

# Create file with the following format: IdlFileNamereply.idl
set fileId [open $outputFile w 0666]

# if no interface was defined in IDL (only typedefs for example)
# create an empty file based on the file name and exit
if {[info exists IDLInterface] == 0} {

    puts $fileId [generateHeader $outputFile "the Input Manager C++ header file" \
		      "Input Manager C++ header file generated from the $startIdl interface" "cxx"]
} else {

    # make sure interface name ends with "Idl" 
    checkInterfaceName $IDLInterface $startIdl "geninputmgrheader"

    # get interface name (get rid of "Idl" suffix)
    set InterfaceName [getInterfaceName $IDLInterface]
    set className [appendStr "InputMgr_" $InterfaceName "_i"]

    puts $fileId [generateHeader $outputFile "the Input Manager C++ header file" \
		      "Input Manager C++ header file generated from the $IDLInterface interface" "cxx"]

    puts $fileId [appendStr "\#ifndef _SCS_INPUTMGR_" [string toupper $InterfaceName] "_H_"]
    puts $fileId [appendStr "\#define _SCS_INPUTMGR_" [string toupper $InterfaceName] "_H_"]
    puts $fileId ""
    puts $fileId [appendStr "\#include \"inputmgr_" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" "_soap_tie.hh"] "\""]
    puts $fileId "\#include \"scsimgmodule.h\""
    puts $fileId ""
    puts $fileId "class InputMgrBinding_i;"
    puts $fileId "class InputMgr_i;"
    puts $fileId ""
    puts $fileId "class $className : public ScsImgModule \{"
    puts $fileId ""
    puts $fileId "   public:"
    puts $fileId ""
    puts $fileId [addWhiteSpaces [appendStr $className "(const char* serverName);"] 6]
    puts $fileId [addWhiteSpaces [appendStr "~$className" "();"] 6]
    puts $fileId ""

    foreach {operation} $OrderedOperationList {

	set operationName [lindex $operation 1]

	set operationFirstLine "      virtual void $operationName"
	append operationFirstLine "(ScsProcessIdl_ptr source,"
	set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]

	set otherArgs [cxxInArgsRef $operationName $argumentFirstCharPos]
	
	puts $fileId $operationFirstLine
	puts $fileId [addWhiteSpaces "CORBA::ULong timeout," $argumentFirstCharPos]
	puts $fileId [addWhiteSpaces "CORBA::UShort priority," $argumentFirstCharPos]
	puts $fileId [addWhiteSpaces "const ScsMessageTag & tag," $argumentFirstCharPos]
	puts $fileId [addWhiteSpaces "const ScsTimeValIdl & onlineTime$otherArgs)" $argumentFirstCharPos]
	puts $fileId "       throw(CORBA::SystemException);"    
	puts $fileId ""
    }

    puts $fileId "      static void createFunction();"
    puts $fileId "      static ScsImgModule * tryBind(const char * serviceName);"
    puts $fileId ""
    puts $fileId "      int setServerUp(const unsigned int & timeout);"
    puts $fileId "      int setStandByUp(const char * remoteService, const char * remoteHost);"
    puts $fileId "\};"
    puts $fileId ""

    set tie "DEF_TIE_SOAP_InputMgr_"
    append tie $IDLInterface
    append tie "("
    append tie $className
    append tie ")"

    puts $fileId $tie
    puts $fileId ""
    puts $fileId "\#endif"
}