################################################################################
#
# Namespace: 
# File name: genproxyheader.tcl
# Returns:
# Description: Generates the Proxy C++ header file.
#
################################################################################
#
# Author: Alain Bartolo
# Creation: 03/11/2000
# Modification:
#
################################################################################

global IDLInterface OrderedOperationList startIdl kPath separator

set outputFile [appendStr $kPath $separator [replace [file tail [replace $startIdl "\\" "/"]] ".idl" ""] "proxy.hh"]

# Create file with the following format: IdlFileNamereply.idl
set fileId [open $outputFile w 0666]

# if no interface was defined in IDL (only typedefs for example)
# create an empty file based on the file name and exit
if {[info exists IDLInterface] == 0} {

    puts $fileId [generateHeader $outputFile "the Proxy C++ header file" \
		      "Proxy C++ header file generated from the $startIdl interface" "cxx"]
} else {

    # make sure interface name ends with "Idl" 
    checkInterfaceName $IDLInterface $startIdl "genproxyheader"

    # get interface name (get rid of "Idl" suffix)
    set InterfaceName [getInterfaceName $IDLInterface]
    set className [appendStr $InterfaceName "Proxy"]

    puts $fileId [generateHeader $outputFile "the Proxy C++ header file" \
		      "Proxy C++ header file generated from the $IDLInterface interface" "cxx"]

    puts $fileId [appendStr "\#ifndef _SCS_" [string toupper $InterfaceName] "PROXY_H_"]
    puts $fileId [appendStr "\#define _SCS_" [string toupper $InterfaceName] "PROXY_H_"]
    puts $fileId ""
    puts $fileId "\#include \"scs.h\""
    puts $fileId "\#include \"scsredtype.hh\""
    puts $fileId "\#include \"almtype.hh\""
    puts $fileId "\#include \"scsthread.h\""
    puts $fileId "\#include \"manager.h\""
    puts $fileId ""
    puts $fileId "// Include types file so that all extra ORB typedefs are included"
    puts $fileId [appendStr "\#include <" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" ".hh"] ">"]
    puts $fileId [appendStr "\#include <" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" "_types.hh"] ">"]
    puts $fileId [appendStr "\#include <inputmgr_" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" ".hh"] ">"]
    puts $fileId ""
    puts $fileId [appendStr "class " $InterfaceName "Idl;"]
    puts $fileId [appendStr "class " $InterfaceName "Reply_i;"]
    puts $fileId ""
    puts $fileId "class InputMgr;"
    puts $fileId "class ImgMsgTag;"
    puts $fileId [appendStr "class InputMgr_" $InterfaceName "Idl;"]
    puts $fileId ""
    puts $fileId ""

    ########################
    # Begining of base class
    ########################

    puts $fileId [appendStr "class " $InterfaceName "Proxy"]
    puts $fileId "\{"
    puts $fileId "\npublic:"
    puts $fileId ""
    puts $fileId [appendStr "  $className" "();"]
    puts $fileId [appendStr "  virtual ~$className" "();"]
    puts $fileId ""
    puts $fileId "  virtual ScsStatus getStatus() const \{ return _status;\}"
    puts $fileId "  virtual void setStatus(ScsStatus status) \{ _status = status;\}"
    puts $fileId "  virtual ScsStatus deactivate()=0;"
    puts $fileId ""

    set toOutput ""

    foreach {operation} $OrderedOperationList {

	    if {[string length $toOutput] != 0} {
	        append toOutput ") = 0;\n\n"
	    }

	    set operationName [lindex $operation 1]

	    set operationFirstLine [appendStr "  virtual ScsStatus $operationName" "("]
	    set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]

	    set otherArgs [cxxArgsRef $operationName $argumentFirstCharPos false]
	
	    append toOutput $operationFirstLine
	    append toOutput [string trimleft $otherArgs]
    }

    if {[string length $toOutput] != 0} {
	    append toOutput ") = 0;\n\n"
	    puts $fileId $toOutput
    }

    puts $fileId [appendStr "  static ScsStatus Create" $InterfaceName "Proxy(const char* environment, const char* serverName, " $InterfaceName "Proxy*& proxy, const char* objectName = NULL, ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);"]
    puts $fileId [appendStr "  static ScsStatus Set" $InterfaceName "Priority(unsigned short priority) { s_" $InterfaceName "Priority= priority; return ScsValid;}"]
    
    puts $fileId [appendStr "  static ScsStatus Create" $InterfaceName "Proxy(" $InterfaceName "Idl_ptr obj, " $InterfaceName "Proxy*& proxy, ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);"]
    puts $fileId [appendStr "  static ScsStatus CreateAndOpen" $InterfaceName "Proxy(const char* environment, const char* serverName, " $InterfaceName "Proxy*& proxy, const char* physEnv = NULL, const char* objectName = NULL, ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);"]
    puts $fileId [appendStr "  static ScsStatus CreateAndOpen" $InterfaceName "Proxy(" $InterfaceName "Idl_ptr obj, " $InterfaceName "Proxy*& proxy, unsigned short needToOpen = 1, ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);"]
    puts $fileId ""
    puts $fileId "  // Change the current timeout - timeout value will be"
    puts $fileId "  // kept for all calls until new call to changeTimeout()."
    puts $fileId "  virtual void changeTimeout(const unsigned int & timeoutValueInMs);"
    puts $fileId ""
    puts $fileId "protected:"
    puts $fileId ""
    puts $fileId [appendStr "  static unsigned short s_" $InterfaceName "Priority;"]
    puts $fileId "  ScsStatus      _status;"
    puts $fileId "  unsigned int   _timeout;"
    puts $fileId "  unsigned short _priority;"
    puts $fileId "\};"
    puts $fileId ""

    ########################
    # Begining of 'S' class
    ########################

    puts $fileId [appendStr "class S" $className " : public " $className]
    puts $fileId "\{"
    puts $fileId "\npublic:"
    puts $fileId ""
    puts $fileId "  // objectId format is: serverName\@logicalEnv_hostName\[/objectName\]"
    puts $fileId [appendStr "  S" $className "(const char* objectId, const char * host);"]
    puts $fileId [appendStr "  S" $className "(" $IDLInterface "_ptr obj);"]
    puts $fileId [appendStr "  ~S" $className "();"]
    puts $fileId "  virtual ScsStatus deactivate() {return ScsValid;}"
    puts $fileId ""
    puts $fileId "  // Redefinition of changeTimeout - changes the current timeout period"
    puts $fileId "  // for CORBA requests "
    puts $fileId "  void changeTimeout(const unsigned int& timeout);"
    puts $fileId ""

    set toOutput ""

    foreach {operation} $OrderedOperationList {

	    if {[string length $toOutput] != 0} {
    	    append toOutput ");\n\n"
    	}

    	set operationName [lindex $operation 1]
    
    	set operationFirstLine [appendStr "  ScsStatus $operationName" "("]
    	set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]
    
    	set otherArgs [cxxArgsRef $operationName $argumentFirstCharPos false]
    	
    	append toOutput $operationFirstLine
    	append toOutput [string trimleft $otherArgs]
    }

    if {[string length $toOutput] != 0} {
	    append toOutput ");\n\n"
	    puts $fileId $toOutput
    }

    puts $fileId "private:"
    puts $fileId ""
    puts $fileId "  // Bind to non redundant server (with specific timeout if different from default ORB timeout)"
    puts $fileId [appendStr "  $IDLInterface" "_ptr bindWithTimeout(void);"]
    puts $fileId ""
    puts $fileId "  CORBA::String_var _implementation;"
    puts $fileId "  CORBA::String_var _objectName;"
    puts $fileId "  CORBA::String_var _host;"
    puts $fileId "  ScsLock           _sLock;"
    puts $fileId [appendStr "  $IDLInterface" "_var  _server;"]
    puts $fileId "  int               _isConnected;"
    puts $fileId "\};"
    puts $fileId ""

    ########################
    # Begining of 'IR' class
    ########################

    puts $fileId [appendStr "class IR" $className " : public " $className]
    puts $fileId "\{"
    puts $fileId "\npublic:"
    puts $fileId ""
    puts $fileId "  // serverName (without the environment name and host name"
    puts $fileId [appendStr "  IR" $className "(const char* serverName, ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);"]
    puts $fileId [appendStr "  ~IR" $className "();"]
    puts $fileId "  virtual ScsStatus deactivate();"
    puts $fileId ""

    set toOutput ""

    foreach {operation} $OrderedOperationList {

	if {[string length $toOutput] != 0} {
	    append toOutput ");\n\n"
	}

	set operationName [lindex $operation 1]

	set operationFirstLine [appendStr "  ScsStatus $operationName" "("]
	set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]

	set otherArgs [cxxArgsRef $operationName $argumentFirstCharPos false]
	
	append toOutput $operationFirstLine
	append toOutput [string trimleft $otherArgs]
    }

    if {[string length $toOutput] != 0} {
	append toOutput ");\n\n"
	puts $fileId $toOutput
    }

    puts $fileId ""
    puts $fileId "private:"
    puts $fileId ""
    puts $fileId "  ScsProcessIdl_var       _server;"
    puts $fileId [appendStr "  InputMgr_" $InterfaceName "Idl_var _" [string tolower $InterfaceName 0 0] "InputMgr;"]
    puts $fileId "  ImgMsgTag*              _tagProvider;"
    puts $fileId [appendStr "  " $InterfaceName "Reply_i*      _" [string tolower $InterfaceName 0 0] "Reply;"]
    puts $fileId "  PortableServer::POA_var _myPoa;"
    puts $fileId "\};"
    puts $fileId ""

    ########################
    # Begining of 'RR' class
    ########################

    puts $fileId [appendStr "class RR" $className " : public " $className]
    puts $fileId "\{"
    puts $fileId "\npublic:"
    puts $fileId ""

    set constructor [appendStr "  RR" $className "(const char*       environmentName,"]
    set ctorFirstCharPos [expr [string first "(" $constructor] + 1]

    puts $fileId $constructor
    puts $fileId [addWhiteSpaces "const char*       serverName," $ctorFirstCharPos]
    puts $fileId [addWhiteSpaces "char**            physEnvs," $ctorFirstCharPos]
    puts $fileId [addWhiteSpaces "char**            hosts," $ctorFirstCharPos]
    puts $fileId [addWhiteSpaces "short             nbPhysicalEnvs," $ctorFirstCharPos]
    puts $fileId [addWhiteSpaces "const char*       physEnv = NULL," $ctorFirstCharPos]
    puts $fileId [addWhiteSpaces "ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);" $ctorFirstCharPos]
    puts $fileId [appendStr "  ~RR" $className "();"]
    puts $fileId "  virtual ScsStatus deactivate();"
    puts $fileId ""

    set toOutput ""

    foreach {operation} $OrderedOperationList {

	if {[string length $toOutput] != 0} {
	    append toOutput ");\n\n"
	}

	set operationName [lindex $operation 1]

	set operationFirstLine [appendStr "  ScsStatus $operationName" "("]
	set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]

	set otherArgs [cxxArgsRef $operationName $argumentFirstCharPos false]
	
	append toOutput $operationFirstLine
	append toOutput [string trimleft $otherArgs]
    }

    if {[string length $toOutput] != 0} {
	append toOutput ");\n\n"
	puts $fileId $toOutput
    }

    puts $fileId ""
    puts $fileId "  AscManager* getAscManager(void) \{ return &_ascManager;\}"
    puts $fileId ""
    puts $fileId "  struct ChangeStateNotificationArg \{"
    puts $fileId [appendStr "    RR" $className "* _server;"]
    puts $fileId "    short _number;"
    puts $fileId "  \};"
    puts $fileId ""
    puts $fileId [appendStr "  struct " $InterfaceName "Connection \{"]
    puts $fileId "    CORBA::String_var          _host;"
    puts $fileId "    CORBA::String_var          _service;"
    puts $fileId "    CORBA::String_var          _serverName;"
    puts $fileId "    CORBA::String_var          _objectName;"
    puts $fileId [appendStr "    ScsProcessIdl_var          _" [string tolower $InterfaceName 0 0] "Server;"]
    puts $fileId [appendStr "    InputMgr_" $InterfaceName "Idl_var  _" [string tolower $InterfaceName 0 0] "InputMgr;"]
    puts $fileId "    ChangeStateNotificationArg _arg;"
    puts $fileId "    short                      _state;"
    puts $fileId "    int                        _subscribeId;"
    puts $fileId ""
    puts $fileId [appendStr "    $InterfaceName" "Connection();"]
    puts $fileId [appendStr "    ~$InterfaceName" "Connection();"]
    puts $fileId ""
    puts $fileId "    int  open(unsigned short priority);"
    puts $fileId "    int  isOpenned();"
    puts $fileId "  \};"
    puts $fileId ""
    puts $fileId "  void changeConnectionState(short number, const char* state);"
    puts $fileId "  void checkConnectionState(void);"
    puts $fileId ""
    puts $fileId "private:"
    puts $fileId ""
    puts $fileId [appendStr "  $InterfaceName" "Connection*   _connections;"]
    puts $fileId "  short                   _nbPhysicalEnvs;"
    puts $fileId "  ImgMsgTag*              _tagProvider;"
    puts $fileId "  AscManager              _ascManager;"
    puts $fileId [appendStr "  " $InterfaceName "Reply_i*        _" [string tolower $InterfaceName 0 0] "Reply;"]
    puts $fileId "  PortableServer::POA_var _myPoa;"
    puts $fileId "\};"
    puts $fileId ""
    puts $fileId "\#endif"
}
