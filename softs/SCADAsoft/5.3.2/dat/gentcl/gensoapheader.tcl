################################################################################
#
# Namespace: 
# File name: gensoapheader.tcl
# Returns:
# Description: Generates the SOAP header file.
#
################################################################################
#
# Author: Alain Bartolo
# Creation: 13/12/2000
# Modification:
#
################################################################################

global IDLInterface OrderedOperationList startIdl outputPath separator

set scadaORBHeader "scadaorb.h"
set outputFile [appendStr $outputPath $separator [replace [file tail [replace $startIdl "\\" "/"] ] ".idl" "_soap.hh"]]

# Create file with the following format: InterfaceName_soap.h
set fileId [open $outputFile w 0666]

# if no interface was defined in IDL (only typedefs for example)
# create an empty file based on the file name and exit
if {[info exists IDLInterface] == 0} {

    puts $fileId [generateHeader $outputFile "the SOAP header file" \
		      "Harmonizes implementation code in a Multi-Object Adapter environment" "cxx"]

} else {

    # make sure interface name ends with "Idl" 
    checkInterfaceName $IDLInterface $startIdl "gensoapheader"

    # get interface name (get rid of "Idl" suffix)
    set InterfaceName [getInterfaceName $IDLInterface]

    puts [appendStr "Generating C++ SOAP header             " $outputFile]

    puts $fileId [generateHeader $outputFile "the SOAP header file" \
		      "Harmonizes implementation code in a Multi-Object Adapter environment" "cxx"]

    puts $fileId [appendStr "\#ifndef _SCS_" [string toupper $InterfaceName] "_SOAP_H_"]
    puts $fileId [appendStr "\#define _SCS_" [string toupper $InterfaceName] "_SOAP_H_"]
    puts $fileId ""
    puts $fileId [appendStr "\#include <$scadaORBHeader" ">"]
    puts $fileId [appendStr "\#include <" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" "_skel.hh"] ">"]
    puts $fileId ""

    ########################
    # Begining of SOAP class
    ########################

    puts $fileId ""
    puts $fileId [appendStr "\#include <" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" "_types.hh"] ">"]
    puts $fileId ""

    puts $fileId [appendStr "class " $InterfaceName "SOAP : virtual public CORBA_INHERIT(" $IDLInterface ")"]
    puts $fileId "\#ifdef _SCS_ORBACUS_"
    puts $fileId "   , public virtual PortableServer::RefCountServantBase"
    puts $fileId "\#endif"
    puts $fileId "\{"
    puts $fileId " public:"
    puts $fileId ""
    puts $fileId [appendStr "   // The first instance of this class will be registerd in naming service as '" $InterfaceName "Idl'"]
    puts $fileId "   //   Next objects will have a marker composed of numeric characters"
    puts $fileId "   // The argument isMultithreaded is used to indicate whether the CORBA object is multithreaded or serialized"
    puts $fileId [appendStr "   $InterfaceName"  "SOAP(CORBA::Boolean isMultithreaded = 0);\n"]
    puts $fileId ""
    puts $fileId "   // The argument marker is used to distinguish serveral instances of this class"
    puts $fileId [appendStr "   //   Each object will be registred in naming service as 'marker:" $InterfaceName "Idl'"]
    puts $fileId "   // The argument isMultithreaded is used to indicate whether the CORBA object is multithreaded or serialized"
    puts $fileId [appendStr "   $InterfaceName"  "SOAP(const char* marker, CORBA::Boolean isMultithreaded = 0);\n"]
    puts $fileId ""
    puts $fileId [appendStr "   $InterfaceName"  "SOAP(PortableServer::POA_var & poa);\n"]
    puts $fileId [appendStr "   ~" $InterfaceName "SOAP();\n"]
    
    
    if {[string compare $IDLInterface "ScsProcessIdl"] != 0} {
	puts $fileId "   char* scs_implementation() throw (CORBA::SystemException);\n"
	puts $fileId "   char* scs_host() throw (CORBA::SystemException);\n"
	puts $fileId "   void  isAlive() throw (CORBA::SystemException);\n"
    }

    puts $fileId "   CORBA::Boolean scs_is_multithreaded() \{"
    puts $fileId "     return _isMultithreaded;"
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "   virtual PortableServer::POA_ptr _default_POA() \{"
    puts $fileId "     PortableServer::POA_var foo=_myPoa;"
    puts $fileId "     return foo._retn();"
    puts $fileId "   \}";
    puts $fileId ""
    puts $fileId "   void _activate_servant();"
    puts $fileId "   void _deactivate_servant();"
    puts $fileId ""
    puts $fileId " private:"
    puts $fileId ""
    puts $fileId "   CORBA::Boolean          _isMultithreaded;"
    puts $fileId "   PortableServer::POA_var _myPoa;"
    puts $fileId "   char*                   _myName;"
    puts $fileId "   CORBA::String_var       _objName;"
    puts $fileId ""
    puts $fileId "\};"
    puts $fileId ""
    puts $fileId "\#endif"
}
