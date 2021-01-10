################################################################################
#
# Namespace: 
# File name: gensoaptie.tcl
# Returns:
# Description: Generates the SOAP tie header file.
#
################################################################################
#
# Author: Alain Bartolo
# Creation: 16 Jan 2001
# Modification:
#
################################################################################

global IDLInterface OrderedOperationList startIdl outputPath separator

set outputFile [appendStr $outputPath $separator [replace [file tail [replace $startIdl "\\" "/"] ] ".idl" "_soap_tie.hh"]]

# Create file with the following format: idlFileName_soap_tie.hh
set fileId [open $outputFile w 0666]

# if no interface was defined in IDL (only typedefs for example)
# create an empty file based on the file name and exit
if {[info exists IDLInterface] == 0} {
    
    puts $fileId [generateHeader $outputFile "the SOAP TIE Header file" \
		      " a file used by TIE implementation classes in a Multi-ORB environment" "cxx"]
} else {

    # make sure interface name ends with "Idl" 
    checkInterfaceName $IDLInterface $startIdl "gensoaptie"

    # get interface name (get rid of "Idl" suffix)
    set InterfaceName [getInterfaceName $IDLInterface]

    puts [appendStr "Generating C++ SOAP tie header         " $outputFile]

    puts $fileId [generateHeader $outputFile "the SOAP TIE Header file" \
		      "Harmonizes TIE implementation classes in a Multi-ORB environment" "cxx"]

    puts $fileId [appendStr "\#ifndef _SCS_" [string toupper $InterfaceName] "_SOAP_TIE_HH_"]
    puts $fileId [appendStr "\#define _SCS_" [string toupper $InterfaceName] "_SOAP_TIE_HH_"]
    puts $fileId ""
    puts $fileId [appendStr "\#include <" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" "_soap.hh"] ">"]
    puts $fileId ""

    ######################################
    # Begining of TIE SOAP template class
    ######################################

    puts $fileId [appendStr "template<class T_SOAP> class $InterfaceName" "SOAP_TIE : public $InterfaceName" "SOAP \{"]
    puts $fileId ""
    puts $fileId " public:"
    puts $fileId ""
    puts $fileId "   // ctor"
    puts $fileId [appendStr "   $InterfaceName" "SOAP_TIE(T_SOAP * objp) : $InterfaceName" "SOAP(), m_obj(objp), m_rel(1) \{"]
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "   // dtor"
    puts $fileId [appendStr "   virtual ~$InterfaceName" "SOAP_TIE() \{"]
    puts $fileId "     if(m_rel) delete m_obj;"
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "   char * scs_implementation(void)"
    puts $fileId "     throw(CORBA::SystemException) \{"
    puts $fileId "     return m_obj->scs_implementation();"
    puts $fileId "   \}"
    puts $fileId "   char * scs_host(void)"
    puts $fileId "     throw(CORBA::SystemException) \{"
    puts $fileId "     return m_obj->scs_host();"
    puts $fileId "   \}"
    puts $fileId "   void   isAlive(void)"
    puts $fileId "     throw(CORBA::SystemException) \{"
    puts $fileId "     m_obj->isAlive();"
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId [appendStr "   static $IDLInterface" "_ptr _narrow(CORBA::Object_ptr p) \{"]
    puts $fileId [appendStr "     return $IDLInterface" "::_narrow(p);"]
    puts $fileId "   \}"
    puts $fileId "\n   // IDL operations\n"

    set toOutput ""

    foreach {operation} $OrderedOperationList {
	
	set operationName [lindex $operation 1]
	set numArgs [getNumberOfArgs $operationName]

	set operationFirstLine [appendStr "   virtual " [lindex $IDLOperation($operationName) 1] " $operationName" "("]
	set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]

	set otherArgs [cxxArgsRef $operationName $argumentFirstCharPos false]
	
	append toOutput $operationFirstLine
	append toOutput [string trimleft $otherArgs]

	append toOutput ")\n     throw(CORBA::SystemException) \{\n"

	# Check if there is a return value
	if {[string compare [lindex $IDLOperation($operationName) 1] "void"] == 0} {
	    set operationFirstLine [appendStr "     m_obj->" $operationName "("]
	} else {
	    set operationFirstLine [appendStr "     return m_obj->" $operationName "("]
	}
	
	set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]

	set otherArgs [cxxArgsNoType $operationName $argumentFirstCharPos]
	
	append toOutput $operationFirstLine
	append toOutput [string trimleft $otherArgs]
	append toOutput ");\n   \}\n\n"
	
    }

    puts $fileId $toOutput

    puts $fileId ""
    puts $fileId " private:"
    puts $fileId ""
    puts $fileId "   T_SOAP * m_obj;"
    puts $fileId "   CORBA::Boolean m_rel;"
    puts $fileId ""
    puts $fileId [appendStr "   " $InterfaceName "SOAP_TIE(const $InterfaceName" "SOAP_TIE<T_SOAP>&)\{\}"]
    puts $fileId [appendStr "   void operator=(const $InterfaceName" "SOAP_TIE<T_SOAP>&)\{\}"]
    puts $fileId ""
    puts $fileId "\};\n"
    puts $fileId ""
    puts $fileId [appendStr "\#define DEF_TIE_SOAP_$IDLInterface" "(X)\\"]
    puts $fileId [appendStr "   typedef $InterfaceName" "SOAP_TIE<X> $InterfaceName" "SOAP_TIE\#\#X;"]
    puts $fileId ""
    puts $fileId [appendStr "\#define TIE_SOAP_$IDLInterface" "(X) $InterfaceName" "SOAP_TIE\#\#X"]
    puts $fileId ""
    puts $fileId "\#endif"
}