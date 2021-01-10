################################################################################
#
# Namespace: 
# File name: gensoapcode.tcl
# Returns:
# Description: Generates the SOAP code file.
#
################################################################################
#
# Author: Alain Bartolo
# Creation: 13/12/2000
# Modification:
#
################################################################################

global IDLInterface OrderedOperationList startIdl outputPath separator

set outputFile [appendStr $outputPath $separator [replace [file tail [replace $startIdl "\\" "/"] ] ".idl" "_soap.cpp"]]

# Create file with the following format: idlFileName_soap.cpp
set fileId [open $outputFile w 0666]

# if no interface was defined in IDL (only typedefs for example)
# create an empty file based on the file name and exit
if {[info exists IDLInterface] == 0} {

    puts $fileId [generateHeader $outputFile "the SOAP code file" \
		      "Harmonizes implementation code in a Multi-Object Adapter environment" "cxx"]

} else {

    # make sure interface name ends with "Idl" 
    checkInterfaceName $IDLInterface $startIdl "gensoapcode"

    # get interface name (get rid of "Idl" suffix)
    set InterfaceName [getInterfaceName $IDLInterface]

    puts [appendStr "Generating C++ SOAP code               " $outputFile]

    puts $fileId [generateHeader $outputFile "the SOAP code file" \
		      "Harmonizes implementation code in a Multi-Object Adapter environment" "cxx"]

    puts $fileId [appendStr "\#include \"" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" "_soap.hh"] "\""]

    ########################
    # Begining of SOAP class
    ########################

    puts $fileId ""
    
    puts $fileId [appendStr "$InterfaceName" "SOAP::$InterfaceName" "SOAP(PortableServer::POA_var & poa):"]
    puts $fileId "  _isMultithreaded(1),"
    puts $fileId "  _myName(NULL),"
    puts $fileId "  _myPoa(poa)"
    puts $fileId "\{"
    puts $fileId ""
    puts $fileId "    if (ScadaORB::inst == NULL) \{"
    puts $fileId [appendStr "       SCS_SL_STD(cerr) << \"ERROR in constructor of " $InterfaceName "SOAP:  Scadasof::Initialize has to be called before !\" << SCS_SL_STD(endl);" ]
    puts $fileId "       exit(-1);"
    puts $fileId "    \}"
    puts $fileId " "
    puts $fileId [appendStr "    _objName = CORBA::string_dup(\"$IDLInterface" "\");"]
    puts $fileId "\}\n\n"


    puts $fileId [appendStr "$InterfaceName" "SOAP::$InterfaceName" "SOAP(const char* marker, CORBA::Boolean isMultithreaded):"]
    puts $fileId "  _isMultithreaded(isMultithreaded),"
    puts $fileId "  _myName(NULL)"
    puts $fileId "\{"
    puts $fileId "    if (ScadaORB::inst == NULL) \{"
    puts $fileId [appendStr "       SCS_SL_STD(cerr) << \"ERROR in constructor of " $InterfaceName "SOAP:  Scadasof::Initialize has to be called before !\" << SCS_SL_STD(endl);" ]
    puts $fileId "       exit(-1);"
    puts $fileId "    \}"
    puts $fileId " "
    puts $fileId "    _myPoa = ScadaORB::inst -> GetPOA(_isMultithreaded);"
    puts $fileId " "
    puts $fileId "    SCS_SL_STD(string) name=marker;"
    puts $fileId [appendStr "    name += \":" $IDLInterface "\";"]
    puts $fileId "    _objName = CORBA::string_dup(name.c_str());"
    puts $fileId "\}\n\n"
    
    puts $fileId [appendStr "$InterfaceName" "SOAP::$InterfaceName" "SOAP(CORBA::Boolean isMultithreaded):"]
    puts $fileId "  _isMultithreaded(isMultithreaded),"
    puts $fileId "  _myName(NULL)"
    puts $fileId "\{"
    puts $fileId "    if (ScadaORB::inst == NULL) \{"
    puts $fileId [appendStr "       SCS_SL_STD(cerr) << \"ERROR in constructor of " $InterfaceName "SOAP:  Scadasof::Initialize has to be called before !\" << SCS_SL_STD(endl);" ]
    puts $fileId "       exit(-1);"
    puts $fileId "    \}"
    puts $fileId " "
    puts $fileId "    _myPoa = ScadaORB::inst -> GetPOA(_isMultithreaded);"
    puts $fileId " "
    puts $fileId [appendStr "    _objName = CORBA::string_dup(\"$IDLInterface" "\");"]
    puts $fileId "\}\n\n"

    puts $fileId [appendStr "$InterfaceName" "SOAP::~" "$InterfaceName" "SOAP()"]
    puts $fileId "\{"
#
#   CBE : ToDo TRACE A WARNING OR ASSERTION FAILURE IF NOT UNREGISTERED
#     
    puts $fileId "\}\n\n"

    puts $fileId [appendStr "void $InterfaceName" "SOAP::" "_deactivate_servant()"]
    puts $fileId "\{"
    puts $fileId "    if (_myName) \{"    
    puts $fileId "      try \{"    
    puts $fileId [appendStr "        ScadaORB::inst->UnRegisterRef(_myName, _isMultithreaded);"]
    puts $fileId "      \} catch (CORBA::UNKNOWN) \{"    
    puts $fileId "      \}"    
    puts $fileId "      delete \[\] _myName;"    
    puts $fileId "      _myName = NULL;"    
    puts $fileId "    \}"    
    puts $fileId "\}\n\n"

    puts $fileId [appendStr "void $InterfaceName" "SOAP::" "_activate_servant()"]
    puts $fileId "\{"
    puts $fileId "  try \{"    
#
#   CBE : ToDo modify the ScadaORB RegisterRef method signature shall take a ServantBase_ptr instead of void*
#
    puts $fileId "        _myName = ScadaORB::inst->RegisterRef(_objName, (PortableServer::ServantBase*) this, _isMultithreaded);"
    puts $fileId "      \} catch (CORBA::UNKNOWN) \{"    
    puts $fileId [appendStr "       SCS_SL_STD(cerr) << \"FAIL to RegisterRef object: \" << (const char*) _objName << \" for interface: " $InterfaceName " !\" << SCS_SL_STD(endl);" ]
    puts $fileId "      \}"    
    puts $fileId "\}\n\n"

    if {[string compare $IDLInterface "ScsProcessIdl"] != 0} {
	puts $fileId [appendStr "char* " $InterfaceName "SOAP::scs_implementation() throw (CORBA::SystemException) \{\n"]
	puts $fileId "   return CORBA::string_dup(ScadaORB::inst->GetContextName());"
	puts $fileId "\}\n"

	puts $fileId [appendStr "char* " $InterfaceName "SOAP::scs_host() throw (CORBA::SystemException) \{\n"]
	puts $fileId "   return CORBA::string_dup(ScadaORB::inst->MyHost());"
    	puts $fileId "\}\n"

	puts $fileId [appendStr "void " $InterfaceName "SOAP::isAlive() throw (CORBA::SystemException) \{\n"]
    	puts $fileId "\}\n"
    }
}

