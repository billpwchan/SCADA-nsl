################################################################################
#
# Namespace: 
# File name: genproxycode.tcl
# Returns:
# Description: Generates the Proxy C++ code file.
#
################################################################################
#
# Author: Alain Bartolo
# Creation: 03/11/2000
# Modification:
#
################################################################################

global IDLInterface OrderedOperationList startIdl kPath separator

set outputFile [appendStr $kPath $separator [replace [file tail [replace $startIdl "\\" "/"]] ".idl" ""] "proxy.cpp"]

# Create file with the following format: IdlFileNamereply.idl
set fileId [open $outputFile w 0666]

# if no interface was defined in IDL (only typedefs for example)
# create an empty file based on the file name and exit
if {[info exists IDLInterface] == 0} {

    puts $fileId [generateHeader $outputFile "the Proxy C++ code file" \
                      "Proxy C++ code file generated from the $startIdl interface" "cxx"]
} else {

    # make sure interface name ends with "Idl" 
    checkInterfaceName $IDLInterface $startIdl "genproxycode"

    # get interface name (get rid of "Idl" suffix)
    set InterfaceName [getInterfaceName $IDLInterface]
    set lowIntName [string tolower $InterfaceName 0 0]
    set className [appendStr $InterfaceName "Proxy"]

    puts $fileId [generateHeader $outputFile "the Proxy C++ code file" \
                      "Proxy C++ code file generated from the $IDLInterface interface" "cxx"]

    puts $fileId "\#ifndef WIN32"
    puts $fileId "\#include <unistd.h>"
    puts $fileId "\#include <pwd.h>"
    puts $fileId "\#endif"
    puts $fileId ""
    puts $fileId "\#include <scadaorb.h>"
    puts $fileId [appendStr "\#include <" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" ".hh"] ">"]
    puts $fileId "\#include <inputmgr.hh>"
    puts $fileId [appendStr "\#include <inputmgr_" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" ".hh"] ">"]
    puts $fileId "\#include <inputmgrbindings.hh>"
    puts $fileId ""
    puts $fileId "\#include \"scs.h\""
    puts $fileId "\#include \"scserror.h\""
    puts $fileId "\#include \"agent.h\""
    puts $fileId "\#include \"imgmsgtag.h\""
    puts $fileId [appendStr "\#include \"" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" "reply_i.hh"] "\""]
    puts $fileId "\#include \"proxyerror.h\""
    puts $fileId "\#include \"ascconnection.h\""
    puts $fileId "\#include \"scsutils.h\""
    puts $fileId ""
    puts $fileId [appendStr "\#include <" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" "proxy.hh"] ">"]
    puts $fileId ""
    puts $fileId "\#ifdef _SCS_PROXY_TRACE_"
    puts $fileId "\#include \"trace.h\""
    puts $fileId "\#endif"
    puts $fileId "\#ifdef SCS_STD"
    puts $fileId "\#include <sstream>"
    puts $fileId "\#endif"
    puts $fileId ""
    puts $fileId ""
    puts $fileId [appendStr "unsigned short " $className "::s_" $InterfaceName "Priority = 10;"]
    puts $fileId ""

    ########################
    # Begining of base class
    ########################

    puts $fileId [appendStr $className "::" $className "()"]
    puts $fileId "  : _status(ScsValid)"
    puts $fileId "\{"
    puts $fileId "  _timeout  = Scadasoft::GetORBTimeout();"
    puts $fileId "  _priority = SCS_PRIORITY_NORMAL;"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId [appendStr $className "::~" $className "()"]
    puts $fileId "\{"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId "// ----------------------------------------"
    puts $fileId ""

    ##############################
    # Begining of Creator function
    ##############################
    puts $fileId [appendStr "ScsStatus " $InterfaceName "Proxy::Create" $InterfaceName "Proxy(const char* environment, const char* serverName, " $InterfaceName "Proxy*& proxy, const char* objectName, ScsPriorityLevels priority)"]
    puts $fileId "\{"
    puts $fileId "  ScsStatus status = ScsValid;"
    puts $fileId ""
    puts $fileId [appendStr "  status = CreateAndOpen" $InterfaceName "Proxy(environment, serverName, proxy, 0, objectName, priority);"]
    puts $fileId ""
    puts $fileId "  return status;"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId "// ----------------------------------------"
    puts $fileId ""

    ##############################
    # Begining of Creator function
    ##############################
    puts $fileId [appendStr "ScsStatus " $InterfaceName "Proxy::Create" $InterfaceName "Proxy(" $IDLInterface "_ptr obj, " $InterfaceName "Proxy*& proxy, ScsPriorityLevels priority)"]
    puts $fileId "\{"
    puts $fileId "  ScsStatus status = ScsValid;"
    puts $fileId ""
    puts $fileId [appendStr "  status = CreateAndOpen" $InterfaceName "Proxy(obj, proxy, 0, priority);"]
    puts $fileId ""
    puts $fileId "  return status;"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId "// ----------------------------------------"

    ##############################
    # Begining of Creator function
    ##############################
    puts $fileId [appendStr "ScsStatus " $InterfaceName "Proxy::CreateAndOpen" $InterfaceName "Proxy(const char* environment, const char* serverName, " $InterfaceName "Proxy*& proxy, const char* physEnv, const char* objectName, ScsPriorityLevels priority)"]
    puts $fileId "\{"
    puts $fileId "  ScsStatus status = ScsValid;"
    puts $fileId ""
    puts $fileId "  // Get connection type (environment is logical or physical)"
    puts $fileId "  AscManager ascManager;"
    puts $fileId "  short      nbPhysicalEnvs = 0;"
    puts $fileId "  char**     hosts          = (char**)NULL;"
    puts $fileId "  char**     physEnvs       = (char**)NULL;"
    puts $fileId "  char*      objectId       = (char*)NULL;"
    puts $fileId "  CORBA::String_var object;"
    puts $fileId "  if (objectName) \{"
    puts $fileId "    object = objectName;"
    puts $fileId "  \} else \{"
    puts $fileId [appendStr "    object = CORBA::string_dup(\"" $IDLInterface "\");"]
    puts $fileId "  \}"
    puts $fileId ""
    puts $fileId "  AscConnectionType connectionType = ascGetConnectionType(&ascManager, environment, physEnvs, hosts, nbPhysicalEnvs);"
    puts $fileId ""
    puts $fileId "  switch (connectionType) \{"
    puts $fileId ""  
    puts $fileId "  case AscExternalSingle:"
    puts $fileId "     objectId = new char\[strlen(serverName) + strlen(physEnvs\[0\]) + strlen(object) + 3\];"
    puts $fileId "     strcpy(objectId, serverName);"
    puts $fileId "     strcat(objectId, \"@\");"
    puts $fileId "     strcat(objectId, physEnvs\[0\]);"
    puts $fileId "     strcat(objectId, \"/\");"
    puts $fileId "     strcat(objectId, object);"
    puts $fileId ""
    puts $fileId [appendStr "     proxy = new S" $InterfaceName "Proxy(objectId, hosts\[0\]);"]
    puts $fileId "     status = proxy->getStatus();"
    puts $fileId "     delete \[\] objectId;"
    puts $fileId "     break;"
    puts $fileId ""
    puts $fileId "  case AscInternalSingle:"
    puts $fileId "  case AscInternalRedundant:"
    puts $fileId "  case AscInternalAsyncRedundant:"
    puts $fileId "     objectId = new char\[strlen(serverName) + strlen(Scadasoft::GetEnv()) + strlen(object) + 3\];"
    puts $fileId "     strcpy(objectId, serverName);"
    puts $fileId "     strcat(objectId, \"@\");"
    puts $fileId "     strcat(objectId, Scadasoft::GetEnv());"
    puts $fileId "     strcat(objectId, \"/\");"
    puts $fileId "     strcat(objectId, object);"
    puts $fileId ""  
    puts $fileId [appendStr "     proxy = new S" $InterfaceName "Proxy(objectId, Scadasoft::GetHost());"]
    puts $fileId "     status = proxy->getStatus();"
    puts $fileId ""
    puts $fileId "     delete \[\] objectId;"
    puts $fileId "     break;"
    puts $fileId ""
    puts $fileId "  case AscExternalRedundant:"
    puts $fileId "     objectId = new char\[strlen(serverName) + strlen(environment) + strlen(object) + 3\];"
    puts $fileId "     strcpy(objectId, serverName);"
    puts $fileId "     strcat(objectId, \"@\");"
    puts $fileId "     strcat(objectId, environment);"
    puts $fileId "     strcat(objectId, \"/\");"
    puts $fileId "     strcat(objectId, object);"
    puts $fileId ""
    puts $fileId [appendStr "     proxy = new RR" $InterfaceName "Proxy(environment, objectId, physEnvs, hosts, nbPhysicalEnvs, physEnv, priority);"]
    puts $fileId "     status = proxy->getStatus();"
    puts $fileId "     delete \[\] objectId;"
    puts $fileId "     break;"
    puts $fileId ""
    puts $fileId "  case AscInternalRedundantSynchronised:"
    puts $fileId "     objectId = new char\[strlen(serverName) + strlen(environment) + strlen(object) + 3\];"
    puts $fileId "     strcpy(objectId, serverName);"
    puts $fileId "     strcat(objectId, \"@\");"
    puts $fileId "     strcat(objectId, environment);"
    puts $fileId "     strcat(objectId, \"/\");"
    puts $fileId "     strcat(objectId, object);"
    puts $fileId ""
    puts $fileId [appendStr "     proxy = new IR" $InterfaceName "Proxy(objectId, priority);"]
    puts $fileId "     status = proxy->getStatus();"
    puts $fileId "     delete \[\] objectId;"
    puts $fileId "     break;"
    puts $fileId ""
    puts $fileId "  case AscExternalAsyncRedundant:"
    puts $fileId "       char *state;"
    puts $fileId "       int i;"
    puts $fileId "       for (i = 0; i < nbPhysicalEnvs; i++) {"
    puts $fileId "         status = ascManager.getPhysState(physEnvs\[i\], \"AscManager\", state);"
    puts $fileId "         if (status.isValid()) {"
    puts $fileId "           if (strncmp(state, \"SCS_ONLINE\", 10) == 0) {"
    puts $fileId "             objectId = new char\[strlen(serverName) + strlen(physEnvs\[i\]) + strlen(object) + 3\];"
    puts $fileId "             strcpy(objectId, serverName);"
    puts $fileId "             strcat(objectId, \"@\");"
    puts $fileId "             strcat(objectId, physEnvs\[i\]);"
    puts $fileId "             strcat(objectId, \"/\");"
    puts $fileId "             strcat(objectId, object);"
    puts $fileId "             free(state);"
    puts $fileId "             break;"
    puts $fileId "           }"
    puts $fileId "           free(state);"
    puts $fileId "         }"
    puts $fileId "       }"
    puts $fileId ""
    puts $fileId "       if (i != nbPhysicalEnvs) {"
    puts $fileId [appendStr "         proxy = new S" $InterfaceName "Proxy(objectId, hosts\[i\]);"]
    puts $fileId "         status = proxy->getStatus();"
    puts $fileId "         delete \[\] objectId;"
    puts $fileId "       } else {"
    puts $fileId "         status = ProxyErrNotConnected(SCS_WARNING);"
    puts $fileId "       }"
    puts $fileId "     break;"
    puts $fileId ""
    puts $fileId "  case AscConnectionTypeError:"
    puts $fileId "     status = ProxyErrImplementation(SCS_FATAL, serverName);"
    puts $fileId "     break;"
    puts $fileId "  \}"
    puts $fileId ""
    puts $fileId "  int counter = 0;"
    puts $fileId "  for (; counter < nbPhysicalEnvs; counter++) \{"
    puts $fileId "     free(physEnvs\[counter\]);"
    puts $fileId "     free(hosts\[counter\]);"
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "  if (nbPhysicalEnvs > 0) \{"
    puts $fileId "    delete \[\] physEnvs;"
    puts $fileId "    delete \[\] hosts;"
    puts $fileId "  \}"
    puts $fileId ""
    puts $fileId "  return status;"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId "// ----------------------------------------"

    ##############################
    # Begining of Creator function
    ##############################
    puts $fileId [appendStr "ScsStatus " $InterfaceName "Proxy::CreateAndOpen" $InterfaceName "Proxy(" $IDLInterface "_ptr obj, " $InterfaceName "Proxy*& proxy, unsigned short needToOpen, ScsPriorityLevels priority)"]
    puts $fileId "\{"
    puts $fileId "  // Get environment name (logical or physical) out of implementation name"
    puts $fileId "  ScsStatus         status         = ScsValid;"
    puts $fileId "  CORBA::String_var objectId       = ScadaORB::inst->GetObjectId(obj);"
    puts $fileId "  CORBA::String_var implementation = ScadaORB::inst->GetImplementation(obj);"
    puts $fileId "  CORBA::String_var envName        = GetLogicalEnvironmentNameFromImplementation(implementation);"
    puts $fileId "  if (strcmp(envName, Scadasoft::GetLogicalEnvironment()) == 0) {"
    puts $fileId "    envName = Scadasoft::GetEnv();"
    puts $fileId "  }"
    puts $fileId ""
    puts $fileId "  // Get connection type (environment is logical or physical)"
    puts $fileId "  AscManager ascManager;"
    puts $fileId "  short      nbPhysicalEnvs = 0;"
    puts $fileId "  char**     hosts          = (char**)NULL;"
    puts $fileId "  char**     physEnvs       = (char**)NULL;"
    puts $fileId "  char *     physEnv        = NULL;" 
    puts $fileId ""
    puts $fileId "  AscConnectionType connectionType = ascGetConnectionType(&ascManager, envName, physEnvs, hosts, nbPhysicalEnvs);"
    puts $fileId ""
    puts $fileId "  switch (connectionType) \{"
    puts $fileId ""  
    puts $fileId "  case AscExternalSingle:"
    puts $fileId "  case AscExternalAsyncRedundant:"
    puts $fileId "  case AscInternalSingle:"
    puts $fileId "  case AscInternalRedundant:"
    puts $fileId "  case AscInternalAsyncRedundant:"
    puts $fileId [appendStr "     proxy = new S" $InterfaceName "Proxy(obj);"]
    puts $fileId "     status = proxy->getStatus();"
    puts $fileId "     break;"
    puts $fileId ""
    puts $fileId "  case AscExternalRedundant:"
    puts $fileId "     if (needToOpen) \{"
    puts $fileId "       physEnv = GetPhysicalEnvironmentNameFromImplementation(implementation);"
    puts $fileId "     \}"
    puts $fileId [appendStr "     proxy = new RR" $InterfaceName "Proxy(envName, objectId, physEnvs, hosts, nbPhysicalEnvs, physEnv, priority);"]
    puts $fileId "     status = proxy->getStatus();"
    puts $fileId "     CORBA::string_free(physEnv);"
    puts $fileId "     break;"
    puts $fileId ""
    puts $fileId "  case AscInternalRedundantSynchronised:"
    puts $fileId [appendStr "     proxy = new IR" $InterfaceName "Proxy(objectId, priority);"]
    puts $fileId "     break;"
    puts $fileId ""
    puts $fileId "  case AscConnectionTypeError:"
    puts $fileId "     status = ProxyErrImplementation(SCS_FATAL, objectId);"
    puts $fileId "     break;"
    puts $fileId "  \}"
    puts $fileId ""
    puts $fileId "  int counter = 0;"
    puts $fileId "  for (; counter < nbPhysicalEnvs; counter++) \{"
    puts $fileId "     free(physEnvs\[counter\]);"
    puts $fileId "     free(hosts\[counter\]);"
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "  if (nbPhysicalEnvs > 0) \{"
    puts $fileId "    delete \[\] physEnvs;"
    puts $fileId "    delete \[\] hosts;"
    puts $fileId "  \}"
    puts $fileId ""
    puts $fileId "  return status;"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId "// ----------------------------------------"


    ##############################
    # Begining of change TimeOut
    ##############################
    puts $fileId ""
    puts $fileId [appendStr "void " $InterfaceName "Proxy::changeTimeout(const unsigned int& timeoutValueInMs)"]
    puts $fileId "\{"
    puts $fileId "  _timeout = timeoutValueInMs;"
    puts $fileId "\}"
    puts $fileId ""

    puts $fileId "// ----------------------------------------"
    puts $fileId ""

    ########################
    # Begining of 'S' class
    ########################

    puts $fileId [appendStr "S" $className "::S" $className "(const char* objectId, const char * host)"]
    puts $fileId "  :_isConnected(0)"
    puts $fileId "\{"
    puts $fileId "   char *implementation = GetImplementationFromObjectId(objectId);"
    puts $fileId "   char *obj     = GetObjectNameFromObjectId(objectId);"
    puts $fileId "   if (obj) \{"
    puts $fileId "     _objectName = obj;"
    puts $fileId "   \} else \{"
    puts $fileId [appendStr "     _objectName = CORBA::string_dup(\"" $IDLInterface "\");"]
    puts $fileId "   \}"
    puts $fileId "   if (implementation) \{"
    puts $fileId "     _implementation = implementation;"
    puts $fileId "   \} else \{"
    puts $fileId "     _implementation = CORBA::string_dup(objectId);"
    puts $fileId "   \}"
    puts $fileId "   _host           = CORBA::string_dup(host);"
    puts $fileId [appendStr "   $IDLInterface" "_var timedOutServer;"]
    puts $fileId ""
    puts $fileId "   try \{"
    puts $fileId "     timedOutServer = bindWithTimeout();"
    puts $fileId "   \} catch(CORBA::SystemException & sysEx) \{"
    puts $fileId "     ProxyErrORB(SCS_WARNING, ScsGetOrbExceptionText(sysEx).c_str());"
    puts $fileId "   \}"
    puts $fileId "\}"
    puts $fileId ""

    # Other ctor
    puts $fileId [appendStr "S" $className "::S" $className "(" $IDLInterface "_ptr obj)"]
    puts $fileId "  :_isConnected(1)"
    puts $fileId "\{"
    puts $fileId "  try \{"
    puts $fileId "    _implementation = ScadaORB::inst->GetImplementation(obj);"
    puts $fileId "    _objectName     = ScadaORB::inst->GetObjectName(obj);"
    puts $fileId "    _host = GetHostNameFromImplementation(_implementation);"
    puts $fileId [appendStr "   _server = " $IDLInterface "::_duplicate(obj);"]
    puts $fileId "  \} catch(CORBA::SystemException& sysEx) \{"
    puts $fileId "     ProxyErrORB(SCS_WARNING, ScsGetOrbExceptionText(sysEx).c_str());"
    puts $fileId "  \}"
    puts $fileId "\}"
    puts $fileId ""

    puts $fileId [appendStr "S" $className "::~S" $className "()"]
    puts $fileId "\{"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId "void"
    puts $fileId [appendStr "S" $className "::changeTimeout(const unsigned int& timeout)"]
    puts $fileId "\{"
    puts $fileId [appendStr "  $className" "::changeTimeout(timeout);"]
    puts $fileId ""
    puts $fileId "  _sLock.lock();"
    puts $fileId "  _isConnected = 0;"
    puts $fileId "  _sLock.unlock();"
    puts $fileId "\}"
    puts $fileId ""

    puts $fileId [appendStr $IDLInterface "_ptr"]
    puts $fileId [appendStr "S" $InterfaceName "Proxy::bindWithTimeout(void)"]
    puts $fileId "\{"
    puts $fileId "  _sLock.lock();"
    puts $fileId ""
    puts $fileId "  if (!_isConnected) \{"
    puts $fileId "    try \{"
    puts $fileId [appendStr "      BIND_WITH_MARKER(" $InterfaceName "Idl, _server, _objectName, _implementation, _host);"]
    puts $fileId "      if(_timeout != ScadaORB::inst->GetORBDefaultTimeout()) \{"
    puts $fileId "        void* result = (void*)NULL;"
    puts $fileId [appendStr "        FIXTIMEOUT((CORBA::ULong)_timeout, " $InterfaceName "Idl, _server, result);"]
    puts $fileId ""
    puts $fileId "        // No need to release the previous value since _server is a _var"
    puts $fileId [appendStr "        _server = (" $InterfaceName "Idl_ptr)result;"]
    puts $fileId "      \}"
    puts $fileId "      _isConnected = 1;"
    puts $fileId "      _status = ScsValid;"
    puts $fileId "    \} catch(CORBA::SystemException&) \{"
    puts $fileId "      _isConnected = 0;"
    puts $fileId "      _status = ProxyNotConnectedError;"
    puts $fileId "      _sLock.unlock();"
    puts $fileId "      throw;"
    puts $fileId "      return NULL;"
    puts $fileId "    \}"
    puts $fileId "  \}"
    puts $fileId ""
    puts $fileId [appendStr "  $IDLInterface" "_ptr toReturn = $IDLInterface" "::_duplicate(_server);"]
    puts $fileId ""
    puts $fileId "  _sLock.unlock();"
    puts $fileId ""
    puts $fileId "  return toReturn;"
    puts $fileId "\}"
    puts $fileId ""

    set toOutput ""

    proc Sbody {operationName} {
        upvar toOutput toOutput
        upvar InterfaceName InterfaceName
        upvar className className
        global IDLOperation IDLInterface

        append toOutput ")\n"
        append toOutput "\{\n"
        append toOutput "\#ifdef _SCS_PROXY_TRACE_\n"
        append toOutput [appendStr "  Trace t(\"   S$className" "::" $operationName "\");\n"]
        append toOutput "\#endif\n"
        append toOutput "\n"
        append toOutput [appendStr "  $IDLInterface" "_var timedOutServer;\n\n"]
        append toOutput "  try \{\n"
        append toOutput "    timedOutServer = bindWithTimeout();\n"
        append toOutput "  \} catch(CORBA::SystemException& sysEx) \{\n"
        append toOutput "    ProxyErrORB(SCS_WARNING, ScsGetOrbExceptionText(sysEx).c_str());\n"
        append toOutput "    return _status;\n"
        append toOutput "  \}\n\n"
        append toOutput "  ScsStatus scsStatus = ScsValid;\n"
        append toOutput "\n"
        append toOutput "  try  \{\n"

        set curLine ""
        
        # Check if there is a need for a return value.
        # if IDL definition specified void as a return value, do not
        # store the result
        if {[string compare [lindex $IDLOperation($operationName) 1] "void"] == 0} {
            set curLine [appendStr "    timedOutServer->" $operationName "("]
        } else {
            append toOutput "    ScsStatusIdl statusIdl;\n\n"
            
            set curLine [appendStr "    statusIdl = timedOutServer->" $operationName "("]
        }
        
        set argumentFirstCharPos [expr [string first "(" $curLine ] + 1]
        
        append toOutput [appendStr $curLine [string trimleft [cxxArgsNoType $operationName $argumentFirstCharPos]] ");\n\n"]
        
        # Do not check the result when no return value is specified.
        if {[string compare [lindex $IDLOperation($operationName) 1] "void"] != 0} {
            append toOutput "    scsStatus = ScsStatus((AntStatus::AntMajor)statusIdl.major, statusIdl.minor);\n"
        }
        
	append toOutput "\#ifdef _SCS_ORBACUS_ \n"
        append toOutput "  \} catch(CORBA::NO_RESPONSE& sysEx) \{\n"
	append toOutput "\#else \n"
        append toOutput "  \} catch(CORBA::TIMEOUT& sysEx) \{\n"
	append toOutput "\#endif \n"
        append toOutput "    ProxyErrORB(SCS_WARNING, ScsGetOrbExceptionText(sysEx).c_str());\n"
        append toOutput "    scsStatus = ScadaORB::inst->GetScsStatusFromException(sysEx);\n"
        append toOutput "    if (sysEx.completed() == CORBA::COMPLETED_NO) {\n"
        append toOutput "       _sLock.lock();\n"
        append toOutput "       _isConnected = 0;\n"
        append toOutput "       _status = ProxyNotConnectedError;\n"
        append toOutput "       _sLock.unlock();\n"
        append toOutput "    }\n"
        append toOutput "  \} catch(CORBA::SystemException& sysEx) \{\n"
        append toOutput "    ProxyErrORB(SCS_WARNING, ScsGetOrbExceptionText(sysEx).c_str());\n"
        append toOutput "    scsStatus = ScadaORB::inst->GetScsStatusFromException(sysEx);\n"
        append toOutput "    _sLock.lock();\n"
        append toOutput "    _isConnected = 0;\n"
        append toOutput "    _status = ProxyNotConnectedError;\n"
        append toOutput "    _sLock.unlock();\n"
        append toOutput "  \}\n"
        append toOutput "\n"
        append toOutput "  return scsStatus;\n"
        append toOutput "\}\n"
        append toOutput "\n"
    }

    foreach {operation} $OrderedOperationList {
        
        if {[string length $toOutput] != 0} {
            Sbody $operationName
        }
        
        set operationName [lindex $operation 1]
        
        set operationFirstLine [appendStr "S$className" "::" $operationName "("]
        set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]
        
        set otherArgs [cxxArgsRef $operationName $argumentFirstCharPos false]
        
        append toOutput "ScsStatus\n"
        append toOutput $operationFirstLine
        append toOutput [string trimleft $otherArgs]
    }

    if {[string length $toOutput] != 0} {
        Sbody $operationName
    }

    puts $fileId $toOutput

    puts $fileId ""
    puts $fileId ""
    puts $fileId "// ----------------------------------------"
    puts $fileId ""

    ########################
    # Begining of 'IR' class
    ########################
    puts $fileId [appendStr "IR" $className "::IR" $className "(const char* objectId, ScsPriorityLevels priority)"]
    puts $fileId "  : _tagProvider((ImgMsgTag*)NULL)"
    puts $fileId "\{"
    puts $fileId "   _status = ScsValid;"
    puts $fileId "   _tagProvider = new ImgMsgTag;"
    puts $fileId "   _priority = (unsigned short)priority;"
    puts $fileId ""
    puts $fileId "   _myPoa = ScadaORB::inst -> GetPOA(1); // Get the multithread POA (1 means multithread)."
    puts $fileId ""
    puts $fileId "   char * srv = GetServerNameFromObjectId(objectId);"
    puts $fileId "   CORBA::String_var serverName;"
    puts $fileId "   if (srv) \{"
    puts $fileId "     serverName = srv;"
    puts $fileId "   \} else \{"
    puts $fileId "     serverName = CORBA::string_dup(objectId);"
    puts $fileId "   \}"
    puts $fileId "   char * obj = GetObjectNameFromObjectId(objectId);"
    puts $fileId "   CORBA::String_var objectName;"
    puts $fileId "\#ifdef SCS_STD"
    puts $fileId "   std::ostringstream fullObjectName;"
    puts $fileId "\#else"
    puts $fileId "   ostrstream fullObjectName;"
    puts $fileId "\#endif"
    puts $fileId "   if (obj) \{"
    puts $fileId "     fullObjectName << obj;"
    puts $fileId "   \} else \{"
    puts $fileId [appendStr "     fullObjectName << \"" $IDLInterface "\";"]
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "   char* service = new char\[strlen(\"InputMgr@\") + strlen(Scadasoft::GetEnv()) + 1\];"
    puts $fileId "   strcpy(service, \"InputMgr@\");"
    puts $fileId "   strcat(service, Scadasoft::GetEnv());"
    puts $fileId ""
    puts $fileId "   InputMgrBindingsIdl_var binder;"
    puts $fileId "   ScsProcessIdl_var imgModule;"
    puts $fileId ""
    puts $fileId "   if (_priority != SCS_PRIORITY_NORMAL) \{"
    puts $fileId "     fullObjectName << '|';"
    puts $fileId "     fullObjectName << _priority;"
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "\#ifdef SCS_STD"
    puts $fileId "   objectName = fullObjectName.str().c_str();"
    puts $fileId "\#else"
    puts $fileId "   fullObjectName << ends;"
    puts $fileId "   objectName = fullObjectName.str();"
    puts $fileId "\#endif"
    puts $fileId ""
    puts $fileId "   try \{"
    puts $fileId ""
    puts $fileId "     BIND(InputMgrBindingsIdl, binder, service, NULL);"
    puts $fileId "     ScsStatusIdl statusIdl = binder->tryBind(serverName, objectName, _server, imgModule);"
    puts $fileId "     ScsStatus scsStatus = ScsStatus((AntStatus::AntMajor)statusIdl.major, statusIdl.minor);"
    puts $fileId ""
    puts $fileId "     if (scsStatus.isValid()) \{"
    puts $fileId [appendStr "       _" $lowIntName "InputMgr = InputMgr_" $InterfaceName "Idl::_narrow(imgModule);"]
    puts $fileId "     \} else \{"
    puts $fileId "       _status = ProxyErrHostServer(SCS_FATAL, serverName);"
    puts $fileId "     \}"
    puts $fileId ""
    puts $fileId "   \} catch (...) \{"
    puts $fileId "     _status = ProxyErrHostServer(SCS_FATAL, serverName);"
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "   if (_status == ScsValid) \{"
    puts $fileId [appendStr "    _" $lowIntName "Reply = new " $InterfaceName "Reply_i(_myPoa, 1);"]
    puts $fileId [appendStr "    _" $lowIntName "Reply->_activate_servant();"]
    puts $fileId "   \} else \{"
    puts $fileId [appendStr "    _" $lowIntName "Reply = 0;"]
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "   delete \[\] service;"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId [appendStr "IR" $className "::~IR" $className "()"]
    puts $fileId "\{"
    puts $fileId [appendStr "   if (_" $lowIntName "Reply != (" $InterfaceName "Reply_i*)NULL) \{"]
    puts $fileId [appendStr "     _" $lowIntName "Reply->_remove_ref();"]
    puts $fileId [appendStr "     _" $lowIntName "Reply = (" $InterfaceName "Reply_i*)NULL;"]
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "   if (_tagProvider != (ImgMsgTag*)NULL) \{"
    puts $fileId "     delete _tagProvider;"
    puts $fileId "     _tagProvider = (ImgMsgTag*)NULL;"
    puts $fileId "   \}"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId [appendStr "ScsStatus IR" $className "::deactivate()"]
    puts $fileId "\{"
    puts $fileId [appendStr "   if (_" $lowIntName "Reply != (" $InterfaceName "Reply_i*)NULL) \{"]
    puts $fileId [appendStr "     _" $lowIntName "Reply->_deactivate_servant();"]
    puts $fileId "   \}"
    puts $fileId "   return ScsValid;"
    puts $fileId "\}"

    set toOutput ""

    proc IRbody {operationName} {
        upvar toOutput toOutput
        upvar InterfaceName InterfaceName
        upvar lowIntName lowIntName
        upvar className className
        global IDLOperation 

        append toOutput ")\n"
        append toOutput "\{\n"
        append toOutput "\#ifdef _SCS_PROXY_TRACE_\n"
        append toOutput [appendStr "   Trace t(\"   IR$className" "::" $operationName "\");\n"]
        append toOutput "\#endif\n\n"
        append toOutput "   if (!_status.isValid()) \{\n"
        append toOutput "     return _status;\n"
        append toOutput "   \}\n\n"
        append toOutput "   ScsMessageTag tag;\n"
        if {[string compare [lindex $IDLOperation($operationName) 1] "void"] == 0} {
            append toOutput "   // IR messages used for synchronization should not modify the static counter of tags' provider\n"
            append toOutput "   _tagProvider->getDummyTag(tag);\n"
        } else {
            append toOutput "   // IR messages should have a nbPhysEnvRunning set to 1 despite being in a redundant environment\n"
            append toOutput "   _tagProvider->getTag(tag, 1);\n"
        }
        append toOutput "   ScsTimeValIdl oTime;\n"
        append toOutput "   oTime.sec  = 0;\n"
        append toOutput "   oTime.usec = 0;\n\n"
        append toOutput "   CORBA::ULong reqTimeout(_timeout);\n\n"

        append toOutput "   try \{\n"
        
        # if function has out args, pass reply reference, else no reply is expected !
        # (Assumes that this method is called for breaking a cycle by an sync call through Input Manager)
        if {[outArgsOrReturnNonVoid $operationName]} {
            append toOutput "\n\n     // Guarantees automatic release of instance created from calling _this()\n"
            append toOutput [appendStr "     $InterfaceName" "ReplyIdl_var tmp$InterfaceName" "ReplyIdl(_$lowIntName" "Reply->_this());\n\n"]
        } else {
            append toOutput "     // No reply is expected !!\n"
            append toOutput "     // Assumes that this method is called for breaking a cycle by an sync call through Input Manager\n"
            append toOutput [appendStr "     $InterfaceName" "ReplyIdl_var tmp$InterfaceName" "ReplyIdl($InterfaceName" "ReplyIdl::_nil());\n\n"]    
        }

        append toOutput "     unsigned short curpriority;\n"
        append toOutput "     if ( s_" $InterfaceName "Priority < 3) {\n"
        append toOutput "       curpriority = s_" $InterfaceName "Priority;\n"
        append toOutput "     } else {\n"
        append toOutput "      curpriority = _priority;\n"
        append toOutput "     }\n"
        append toOutput [appendStr "     _" $lowIntName "InputMgr->" $operationName "(\n"]
        append toOutput	[appendStr "               tmp" $InterfaceName "ReplyIdl, reqTimeout, curpriority, tag, oTime" ]

        if {[getNumberOfInAndInoutArgs $operationName] > 0} {
          append toOutput ",\n"
          append toOutput [cxxInArgsNoType $operationName 10]
        } 
        append toOutput ");\n"

        # if function has out args, call its reply function
        if {[outArgsOrReturnNonVoid $operationName]} {

            append toOutput "   \} catch(CORBA::SystemException& sysEx) \{\n"
            append toOutput "     ProxyErrORB(SCS_WARNING, ScsGetOrbExceptionText(sysEx).c_str());\n"
            append toOutput "     return ScadaORB::inst->GetScsStatusFromException(sysEx);\n"
            append toOutput "   \}\n\n"
            append toOutput "   ScsStatus resultStatus;\n\n"
            append toOutput "   try \{\n"

            # Check if function has out args
            # in else, process the case when there is a return value but no out args
            if {[getNumberOfInoutAndOutArgs $operationName] > 0} {
                set curLine [appendStr "     resultStatus = _" $lowIntName "Reply->get" [string toupper $operationName 0 0] "Result(tag, reqTimeout, "]
                set argumentFirstCharPos [expr [string first "(" $curLine ] + 1]
                append toOutput [appendStr $curLine [string trimleft [cxxArgsOutNoType $operationName $argumentFirstCharPos]] ");\n"]
            } else {
                append toOutput [appendStr "     resultStatus = _" $lowIntName "Reply->getResult(tag, reqTimeout);\n"]
            }

            append toOutput "   \} catch(CORBA::SystemException& sysEx) \{\n"
            append toOutput "      ProxyErrORB(SCS_WARNING, ScsGetOrbExceptionText(sysEx).c_str());\n"
            append toOutput "      return ScadaORB::inst->GetScsStatusFromException(sysEx);\n"
            append toOutput "   \}\n\n"
            append toOutput "   return resultStatus;\n\n"
        } else {

            append toOutput "   \} catch(CORBA::SystemException& sysEx) \{\n"
            append toOutput "      ProxyErrORB(SCS_WARNING, ScsGetOrbExceptionText(sysEx).c_str());\n"
            append toOutput "      return ScadaORB::inst->GetScsStatusFromException(sysEx);\n"
            append toOutput "   \}\n\n"
            append toOutput "   // No getResult() !! (=> no blocking)\n"
            append toOutput "   // Assumes that this method is called for breaking a cycle by an sync call through Input Manager\n"
            append toOutput "   return ScsValid;\n"

        }

        append toOutput "\}\n\n"
    }

    foreach {operation} $OrderedOperationList {

        set operationName [lindex $operation 1]

        set operationFirstLine [appendStr "IR$className" "::" $operationName "("]
        set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]

        set otherArgs [cxxArgsRef $operationName $argumentFirstCharPos false]
        
        append toOutput "ScsStatus\n"
        append toOutput $operationFirstLine
        append toOutput [string trimleft $otherArgs]

        IRbody $operationName
    }

    puts $fileId $toOutput

    puts $fileId ""
    puts $fileId "// ----------------------------------------"
    puts $fileId ""

    ########################
    # Begining of 'RR' class
    ########################
    set interfaceConnection [appendStr $InterfaceName "Connection"]

    puts $fileId [appendStr "RR" $className "::$interfaceConnection" "::$interfaceConnection" "()"]
    puts $fileId "  : _state(FALSE), _subscribeId(-1)"
    puts $fileId "\{"
    puts $fileId [appendStr "   _arg._server = (RR" $className "*)NULL;"]
    puts $fileId "   _arg._number = 0;"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId [appendStr "RR" $className "::$interfaceConnection" "::~$interfaceConnection" "()"]
    puts $fileId "\{"
    puts $fileId [appendStr "   if ((_subscribeId != -1) && (_arg._server != (RR" $className "*)NULL)) \{"]
    puts $fileId "     (_arg._server->getAscManager())->unsubscribePhys(_subscribeId);"
    puts $fileId "   \}"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId [appendStr "int RR" $className "::$interfaceConnection" "::open(unsigned short priority)"]
    puts $fileId "\{"
    puts $fileId ""
    puts $fileId "   InputMgrBindingsIdl_var binder;"
    puts $fileId "   ScsProcessIdl_var imgModule;"	
    puts $fileId "   int state;"
    puts $fileId ""
    puts $fileId "   try \{"
    puts $fileId "     BIND(InputMgrBindingsIdl, binder, _service, _host);"
    puts $fileId [appendStr "     ScsStatusIdl statusIdl = binder->tryBind(_serverName, _objectName, _" $lowIntName "Server, imgModule);"]
    puts $fileId "     ScsStatus scsStatus = ScsStatus((AntStatus::AntMajor)statusIdl.major, statusIdl.minor);"
    puts $fileId ""
    puts $fileId "     if (scsStatus.isValid()) \{"
    puts $fileId [appendStr "       _" $lowIntName "InputMgr = InputMgr_" $InterfaceName "Idl::_narrow(imgModule);"]
    puts $fileId "       state = TRUE;"
    puts $fileId "     \} else \{"
    puts $fileId [appendStr "       _" $lowIntName "InputMgr = InputMgr_" $InterfaceName "Idl::_nil();"]
    puts $fileId "       ProxyErrHostServer(SCS_WARNING, _service);"
    puts $fileId "       state = FALSE;"
    puts $fileId "     \}"
    puts $fileId "   \} catch (...) \{"
    puts $fileId [appendStr "     _" $lowIntName "InputMgr = InputMgr_" $InterfaceName "Idl::_nil();"]
    puts $fileId "     ProxyErrHostServer(SCS_WARNING, _service);"
    puts $fileId "     state = FALSE;"
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "   return state;"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId [appendStr "int RR" $className "::$interfaceConnection" "::isOpenned()"]
    puts $fileId "\{"
    puts $fileId [appendStr "   return (!CORBA::is_nil(_"   $lowIntName "InputMgr.in()));"]
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId "static void"
    puts $fileId "changeStateNotification(const char* environment,"
    puts $fileId "                        const char* process,"
    puts $fileId "                        const char* state,"
    puts $fileId "                        void*       arg)"
    puts $fileId "\{"
    puts $fileId [appendStr "   RR$className" "::ChangeStateNotificationArg* a = "]
    puts $fileId [appendStr "     (RR$className" "::ChangeStateNotificationArg*)arg;"]
    puts $fileId ""
    puts $fileId "     a->_server->changeConnectionState(a->_number, state);"
    puts $fileId "     a->_server->checkConnectionState();"
    puts $fileId "\}"
    puts $fileId ""

    set rrCtor [appendStr "RR$className" "::RR$className" "(const char*       environmentName,"]
    set firstCtorArg [expr [string first "(" $rrCtor] + 1]

    puts $fileId $rrCtor
    puts $fileId [addWhiteSpaces "const char*       objectId," $firstCtorArg]
    puts $fileId [addWhiteSpaces "char**            physEnvs," $firstCtorArg]
    puts $fileId [addWhiteSpaces "char**            hosts," $firstCtorArg]
    puts $fileId [addWhiteSpaces "short             nbPhysicalEnvs," $firstCtorArg]
    puts $fileId [addWhiteSpaces "const char*       physEnv," $firstCtorArg]
    puts $fileId [addWhiteSpaces "ScsPriorityLevels priority)" $firstCtorArg]
    puts $fileId "  : _nbPhysicalEnvs(nbPhysicalEnvs), _tagProvider(new ImgMsgTag)"
    puts $fileId "\{"
    puts $fileId "   _priority = (unsigned short)priority;"
    puts $fileId ""
    puts $fileId "   _myPoa = ScadaORB::inst -> GetPOA(1); // Get the multithread POA (1 means multithread)."
    puts $fileId ""
    puts $fileId "   CORBA::String_var serverName;"
    puts $fileId "   char * srv = GetServerNameFromObjectId(objectId);"
    puts $fileId "   if (srv) \{"
    puts $fileId "     serverName = srv;"
    puts $fileId "   \} else \{"
    puts $fileId "     serverName = CORBA::string_dup(objectId);"
    puts $fileId "   \}"
    puts $fileId "\#ifdef SCS_STD"
    puts $fileId "   std::ostringstream fullObjectName;"
    puts $fileId "\#else"
    puts $fileId "   ostrstream fullObjectName;"
    puts $fileId "\#endif"
    puts $fileId "   char * obj = GetObjectNameFromObjectId(objectId);"
    puts $fileId "   if (obj) \{"
    puts $fileId "      fullObjectName << obj;"
    puts $fileId "   \} else \{"
    puts $fileId [appendStr "     fullObjectName << \"" $IDLInterface "\";"]
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "   if (_priority != SCS_PRIORITY_NORMAL) \{"
    puts $fileId "     fullObjectName << '|';"
    puts $fileId "     fullObjectName << _priority;"
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "\#ifdef SCS_STD"
    puts $fileId "   CORBA::String_var objectName=fullObjectName.str().c_str();"
    puts $fileId "\#else"
    puts $fileId "   fullObjectName << ends;"
    puts $fileId "   CORBA::String_var objectName=fullObjectName.str();"
    puts $fileId "\#endif"
    puts $fileId ""
    puts $fileId [appendStr "   _connections = new $interfaceConnection" "\[_nbPhysicalEnvs\];"]
    puts $fileId "   for (int i = 0; i < _nbPhysicalEnvs; i++) \{"
    puts $fileId ""
    puts $fileId "     $interfaceConnection* connection = &_connections\[i\];"
    puts $fileId "     connection->_host = CORBA::string_dup(hosts\[i\]);"
    puts $fileId ""
    puts $fileId "     char* service = new char\[strlen(\"InputMgr@\") + strlen(physEnvs\[i\]) + 1\];"
    puts $fileId "     strcpy(service, \"InputMgr@\");"
    puts $fileId "     strcat(service, physEnvs\[i\]);"
    puts $fileId ""
    puts $fileId "     connection->_service = CORBA::string_dup(service);"
    puts $fileId "     delete \[\] service;"
    puts $fileId "     connection->_serverName  = CORBA::string_dup(serverName);"
    puts $fileId "     connection->_objectName  = CORBA::string_dup(objectName);"
    puts $fileId "     connection->_arg._server = this;"
    puts $fileId "     connection->_arg._number = i;"
    puts $fileId ""
    puts $fileId "     char* currentState = (char*)NULL;"
    puts $fileId ""
    puts $fileId "     // Subscribe to the state of the Server of the Physical"
    puts $fileId "     // environment"
    puts $fileId "     _ascManager.subscribePhysState(physEnvs\[i\],"
    puts $fileId "                                    environmentName,"
    puts $fileId "                                    (const char*) connection->_serverName,"
    puts $fileId "                                    currentState,"
    puts $fileId "                                    connection->_subscribeId,"
    puts $fileId "                                    changeStateNotification,"
    puts $fileId "                                    &connection->_arg);"
    puts $fileId ""
    puts $fileId "     if (currentState != (char*)NULL) \{"
    puts $fileId "       if (physEnv && strcmp(physEnvs\[i\],physEnv) == 0) \{"
    puts $fileId "         // Open the connection"
    puts $fileId "         changeConnectionState(i, SCS_UP);"
    puts $fileId "       \} else \{"
    puts $fileId "         changeConnectionState(i, currentState);"
    puts $fileId "       \}"
    puts $fileId "       free(currentState);"
    puts $fileId "     \}"
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "   checkConnectionState();"
    puts $fileId ""
    puts $fileId [appendStr "   _" $lowIntName "Reply = new $InterfaceName" "Reply_i(_myPoa, _nbPhysicalEnvs);"]
    puts $fileId [appendStr "   _" $lowIntName "Reply->_activate_servant();"]
    puts $fileId ""
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId [appendStr "RR$className" "::~RR$className" "()"]
    puts $fileId "\{"
    puts $fileId ""
    puts $fileId [appendStr "   if (_" $lowIntName "Reply != (" $InterfaceName "Reply_i*)NULL) \{"]
    puts $fileId [appendStr "     _" $lowIntName "Reply->_remove_ref();"]
    puts $fileId [appendStr "     _" $lowIntName "Reply = (" $InterfaceName "Reply_i*)NULL;"]
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "   if (_connections) \{"
    puts $fileId "     delete \[\] _connections;"
    puts $fileId [appendStr "     _connections = (" $InterfaceName "Connection*)NULL;"] 
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "   if (_tagProvider != (ImgMsgTag*)NULL) \{"
    puts $fileId "     delete _tagProvider;"
    puts $fileId "     _tagProvider = (ImgMsgTag*)NULL;"
    puts $fileId "   \}"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId [appendStr "ScsStatus RR" $className "::deactivate()"]
    puts $fileId "\{"
    puts $fileId ""
    puts $fileId [appendStr "   if (_" $lowIntName "Reply != (" $InterfaceName "Reply_i*)NULL) \{"]
    puts $fileId [appendStr "     _" $lowIntName "Reply->_deactivate_servant();"]
    puts $fileId "   \}"
    puts $fileId "    return ScsValid;"
    puts $fileId "\}"
    puts $fileId ""

    set toOutput ""

    proc RRbody {operationName} {
        upvar toOutput toOutput
        upvar InterfaceName InterfaceName
        upvar interfaceConnection interfaceConnection
        upvar lowIntName lowIntName 
        upvar className className
        global IDLOperation 

        append toOutput ")\n"
        append toOutput "\{\n"
        append toOutput "\#ifdef _SCS_PROXY_TRACE_\n"
        append toOutput "  timeval t = Scadasoft::GetOSTime();\n"
        append toOutput "  affTimeString tString;"
        append toOutput [appendStr "  SCS_SL_STD(cout) << \"-->RR" $className "::" $operationName ": \" << affTime(t, tString) << SCS_SL_STD(endl);"]
        append toOutput "\n\#endif\n\n"
        append toOutput "   if (!_status.isValid()) \{\n"
        append toOutput "     return _status;\n"
        append toOutput "   \}\n\n"
        append toOutput "   ScsStatus scsStatus = ScsValid;\n"
        append toOutput "   ScsMessageTag tag;\n"
        append toOutput "   _tagProvider->getTag(tag);\n"
        append toOutput "   ScsTimeValIdl oTime;\n"
        append toOutput "   oTime.sec  = 0;\n"
        append toOutput "   oTime.usec = 0;\n"
        append toOutput "   int nbErrors(0);\n"
        append toOutput "   CORBA::ULong reqTimeout(_timeout);\n\n"

        append toOutput "   for (int i = 0; i < _nbPhysicalEnvs; i++) \{\n\n"
        append toOutput "     $interfaceConnection* connection = &_connections\[i\];\n\n"
        append toOutput "     if (connection->_state) \{\n"
        append toOutput "\n"
        append toOutput "       // if the connection have not be openned\n"
        append toOutput "       int isOpenned = connection->isOpenned();\n"
        append toOutput "       if(!isOpenned) \{\n"
        append toOutput "         isOpenned = connection->open(_priority);\n"
        append toOutput "       \}\n"
        append toOutput "\n"
        append toOutput "       if (isOpenned) \{\n"
        append toOutput ""
        append toOutput "         try \{\n"

        append toOutput "\n           // Guarantees automatic release of instance created from calling _this()\n"
        append toOutput [appendStr "           " $InterfaceName "ReplyIdl_var tmp" $InterfaceName "ReplyIdl(_" $lowIntName "Reply->_this());\n\n"]

        append toOutput "           unsigned short curpriority;\n"
        append toOutput "           if ( s_" $InterfaceName "Priority < 3) {\n"
        append toOutput "             curpriority = s_" $InterfaceName "Priority;\n"
        append toOutput "           } else {\n"
        append toOutput "            curpriority = _priority;\n"
        append toOutput "           }\n"
        append toOutput [appendStr "           connection->_" $lowIntName "InputMgr->" $operationName "(\n"]
        append toOutput	[appendStr "                     tmp" $InterfaceName "ReplyIdl, reqTimeout, curpriority, tag, oTime" ]
        
        if {[getNumberOfInAndInoutArgs $operationName] > 0} {
          append toOutput ",\n"
          append toOutput [cxxInArgsNoType $operationName 10]
        } 
        
        append toOutput ");\n"

        set curLine [appendStr "           connection->_" $lowIntName "InputMgr->_create_request(CORBA::Context::_nil(),\n"]

        append toOutput "\n"

	append toOutput "\#ifdef _SCS_ORBACUS_ \n"
        append toOutput "         \} catch(CORBA::NO_RESPONSE& sysEx) \{\n"
	append toOutput "\#else \n"
        append toOutput "         \} catch(CORBA::TIMEOUT& sysEx) \{\n"
	append toOutput "\#endif \n"
        append toOutput "           if (sysEx.completed() == CORBA::COMPLETED_NO) {\n"
        append toOutput "             connection->_state = FALSE;\n"
        append toOutput "           }\n"
        append toOutput "           ProxyErrORB(SCS_WARNING, ScsGetOrbExceptionText(sysEx).c_str());\n"
        append toOutput "           scsStatus = ScadaORB::inst->GetScsStatusFromException(sysEx);\n"
        append toOutput "           nbErrors++;\n"
        append toOutput "         \} catch(CORBA::SystemException& sysEx) \{\n"
        append toOutput "           connection->_state = FALSE;\n"	
        append toOutput "           ProxyErrORB(SCS_WARNING, ScsGetOrbExceptionText(sysEx).c_str());\n"
        append toOutput "           scsStatus = ScadaORB::inst->GetScsStatusFromException(sysEx);\n"
        append toOutput "           nbErrors++;\n"
        append toOutput "         \}\n"
        append toOutput "       \} else \{\n"
        append toOutput "         nbErrors++;\n"
        append toOutput "       \}\n"
        append toOutput "     \} else \{\n"
        append toOutput "       nbErrors++;\n"
        append toOutput "     \}\n"
        append toOutput "   \}\n\n"
        
        # wait for result only if not oneway
        if {[outArgsOrReturnNonVoid $operationName]} {
            
            append toOutput "   if (nbErrors < _nbPhysicalEnvs) \{\n"
            append toOutput "     // Waiting for the first response\n"
            append toOutput "     try \{\n"
            # only generate functions if the number of out args is not 0
            if {[getNumberOfInoutAndOutArgs $operationName] != 0} {
                
                set curLine [appendStr "       scsStatus = _" $lowIntName "Reply->get" [string toupper $operationName 0 0] "Result(tag, reqTimeout, "]
                set argumentFirstCharPos [expr [string first "(" $curLine ] + 1]
                append toOutput [appendStr $curLine [string trimleft [cxxArgsOutNoType $operationName $argumentFirstCharPos]] ");\n"]
            } else {
                append toOutput [appendStr "       scsStatus = _" $lowIntName "Reply->getResult(tag, reqTimeout);\n"]
            }
            append toOutput "     \} catch(CORBA::SystemException& sysEx) \{\n"
            append toOutput "      ProxyErrORB(SCS_WARNING, ScsGetOrbExceptionText(sysEx).c_str());\n"
            append toOutput "      scsStatus = ScadaORB::inst->GetScsStatusFromException(sysEx);\n"
            append toOutput "     \}\n"
            append toOutput "   \} else if (scsStatus.isValid())\{\n"
            append toOutput "     // no request sent\n"
            append toOutput "     scsStatus = ProxyNotConnectedError;\n"
            append toOutput "   \}\n\n"
            
        } else {
            append toOutput "   // Never waiting for any response\n"
            append toOutput "   if(nbErrors < _nbPhysicalEnvs) \{\n"
            append toOutput "     // Almost one request sent successfully\n"
            append toOutput "     scsStatus = ScsValid;\n"
            append toOutput "   \} else if (scsStatus.isValid()) \{\n"
            append toOutput "     // no request sent\n"
            append toOutput "     scsStatus = ProxyNotConnectedError;\n"
            append toOutput "   \}\n"
        }
        
        append toOutput "\n\#ifdef _SCS_PROXY_TRACE_\n"
        append toOutput "  t = Scadasoft::GetOSTime();\n"
        append toOutput [appendStr "  SCS_SL_STD(cout) << \"<--RR" $className "::" $operationName ": \" << affTime(t, tString) << SCS_SL_STD(endl);"]
        append toOutput "\n\#endif\n\n"

        append toOutput "   return scsStatus;\n"
        append toOutput "\}\n\n"
    }


    foreach {operation} $OrderedOperationList {

        if {[string length $toOutput] != 0} {
            RRbody $operationName
        }

        set operationName [lindex $operation 1]

        set operationFirstLine [appendStr "RR$className" "::" $operationName "("]
        set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]

        set otherArgs [cxxArgsRef $operationName $argumentFirstCharPos false]
        
        append toOutput "ScsStatus\n"
        append toOutput $operationFirstLine
        append toOutput [string trimleft $otherArgs]
    }

    if {[string length $toOutput] != 0} {
        RRbody $operationName
    }

    puts $fileId $toOutput

    puts $fileId "void"
    puts $fileId [appendStr "RR$className" "::changeConnectionState(short number, const char* state)"]
    puts $fileId "\{"
    puts $fileId "   $interfaceConnection* connection = &_connections\[number\];"
    puts $fileId ""  
    puts $fileId "   if ((! connection->_state) && strcmp(state, SCS_DOWN) != 0 && strcmp(state, SCS_INIT) != 0) \{"
    puts $fileId ""	
    puts $fileId "       connection->_state = TRUE;"
    puts $fileId ""	
    puts $fileId "       // Try to open connection"
    puts $fileId "       connection->open(_priority);"
    puts $fileId ""    
    puts $fileId "   \} else if (connection->_state && strcmp(state, SCS_DOWN) == 0) \{"
    puts $fileId "       connection->_state = FALSE;"
    puts $fileId ""
    puts $fileId "   \}"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId "void"
    puts $fileId [appendStr "RR$className" "::checkConnectionState(void)"]
    puts $fileId "\{"
    puts $fileId "  for (int i = 0; i < _nbPhysicalEnvs; i++) \{"
    puts $fileId "    if (_connections\[i\]._state != FALSE) \{"
    puts $fileId "      // status is valid if at least one connection is established "
    puts $fileId "      _status = ScsValid;"
    puts $fileId "      return;"
    puts $fileId "    \}"
    puts $fileId "  \}"
    puts $fileId ""
    puts $fileId "  _status = ProxyNotConnectedError;"
    puts $fileId "\}"
    
}
