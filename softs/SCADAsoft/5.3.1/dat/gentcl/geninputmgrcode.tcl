################################################################################
#
# Namespace: 
# File name: geninputmgrcode.tcl
# Returns:
# Description: Generates the Input Manager C++ code file.
#
################################################################################
#
# Author: Alain Bartolo
# Creation: 03/11/2000
# Modification:
#
################################################################################

global IDLInterface IDLOperation OrderedOperationList startIdl jPath separator

set outputFile [appendStr $jPath $separator "img" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" ""] "_i.cpp"]

# Create file with the following format: IdlFileNamereply.idl
set fileId [open $outputFile w 0666]

# if no interface was defined in IDL (only typedefs for example)
# create an empty file based on the file name and exit
if {[info exists IDLInterface] == 0} {

    puts $fileId [generateHeader $outputFile "the Input Manager C++ code file" \
		      "Input Manager C++ code file generated from the $startIdl interface" "cxx"]
} else {

    # make sure interface name ends with "Idl" 
    checkInterfaceName $IDLInterface $startIdl "geninputmgrcode"

    # get interfacroxe name (get rid of "Idl" suffix)
    set InterfaceName [getInterfaceName $IDLInterface]

    puts $fileId [generateHeader $outputFile "the Input Manager C++ code file" \
		      "Input Manager C++ code file generated from the $IDLInterface interface" "cxx"]

    puts $fileId "\#include \"scadaorb.h\""
    puts $fileId "\#include \"scsredtype.hh\""
    puts $fileId "\#include \"imgerror.h\""
    puts $fileId [appendStr "\#include \"" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" ".hh"] "\""]
    puts $fileId "\#include \"scs.h\""
    puts $fileId "\#include \"red.h\""
    puts $fileId [appendStr "\#include \"img" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" "_i.hh"] "\""]
    puts $fileId "\#include \"imgmessage.h\""
    puts $fileId "\#include \"inputmgrbindings.hh\""
    puts $fileId "\#include \"scsutils.h\""
    puts $fileId ""
    puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
    puts $fileId "\#include \"trace.h\""
    puts $fileId "\#endif"
    puts $fileId "\#ifdef SCS_STD"
    puts $fileId "\#include <sstream>"
    puts $fileId "\#endif"
    puts $fileId ""

    set className [appendStr "InputMgr_$InterfaceName" "_i"]
    set classPtr  [appendStr "InputMgr_$InterfaceName" "_ptr"]

    puts $fileId ""
    puts $fileId [appendStr "void " $className "::createFunction()"]
    puts $fileId "\{"
    puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
    puts $fileId [appendStr "  Trace t(\"" $className "::createFunction()\");"]
    puts $fileId "\#endif"
    puts $fileId "\}"
    puts $fileId ""

    ##################
    # answer function
    ##################
    puts $fileId "static void answer(CORBA::Request * fromRequest, CORBA::Request * toRequest)"
    puts $fileId "\{"
    puts $fileId "  const ScsStatusIdl * resultIdl;"
    puts $fileId ""
    puts $fileId "  // Extract return value"
    puts $fileId "  *(fromRequest->result()->value()) >>= resultIdl;"
    puts $fileId ""
    puts $fileId "  // Copy return value"
    puts $fileId "  *(toRequest->arguments()->item(1)->value()) <<= *resultIdl;"
    puts $fileId "\}"
    puts $fileId ""

    ##################
    # tryBind function
    ##################
    puts $fileId "ScsImgModule *"
    puts $fileId [appendStr $className "::tryBind(const char * serviceName)"]
    puts $fileId "\{"
    puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
    puts $fileId [appendStr "  RedTraceLevel(8, \"" $className "::tryBind to \" << serviceName);"]
    puts $fileId "\#endif"
    puts $fileId ""
    puts $fileId [appendStr "  " $className "* module = new " $className "(serviceName);"]
    puts $fileId [appendStr "  TIE_SOAP_InputMgr_" $InterfaceName "Idl(" $className ") * tieModule ="]
    puts $fileId [appendStr "      new TIE_SOAP_InputMgr_" $InterfaceName "Idl(" $className ")(module);"]
#
# CBE : ToDo DEACTIVATE SERVANT. Yes, but where it is destroyed !!! Noboby keeps pointer on tieModule !!!
# 
    puts $fileId [appendStr "  tieModule->_activate_servant();"]
    puts $fileId ""
    puts $fileId "  module->setMyModuleIdl(tieModule->_this());"
    puts $fileId ""
    puts $fileId "  return module;"
    puts $fileId "\}"
    puts $fileId ""

    ##################
    # ctor
    ##################
    puts $fileId [appendStr $className "::" $className "(const char* serverName)"]
    puts $fileId "  : ScsImgModule(serverName)"
    puts $fileId "\{"
    puts $fileId "  _remoteImgModule = NULL;"
    puts $fileId "\}"
    puts $fileId ""

    ##################
    # dtor
    ##################
    puts $fileId [appendStr $className "::~" $className "()"]
    puts $fileId "\{"
    puts $fileId "  if (!CORBA::is_nil(_remoteImgModule)) \{"
    puts $fileId "    CORBA::release(_remoteImgModule);"
    puts $fileId "    _remoteImgModule = NULL;"
    puts $fileId "  \}"  
    puts $fileId "\}"
    puts $fileId ""

    ##################
    # setServerUp
    ##################
    puts $fileId "int"
    puts $fileId [appendStr $className "::setServerUp(const unsigned int & timeout)"]
    puts $fileId "\{"
    puts $fileId "  if (ScsImgModule::getDestination(timeout) != NULL) \{"
    puts $fileId "    ScsImgModule::clearDestination(timeout);"
    puts $fileId "  \}"
    puts $fileId ""
    puts $fileId "  int ret = FALSE;"
    puts $fileId ""
    puts $fileId "  char *impl = GetImplementationFromObjectId(_serverName);"
    puts $fileId "  CORBA::String_var implementation;"
    puts $fileId "  if (impl) \{"
    puts $fileId "    implementation = impl;"
    puts $fileId "  \} else \{"
    puts $fileId [appendStr "    implementation = CORBA::string_dup(_serverName);"]
    puts $fileId "  \}"
    puts $fileId "  char *obj = GetObjectNameFromObjectId(_serverName);"
    puts $fileId "  CORBA::String_var objectName;"
    puts $fileId "  if (obj) \{"
    puts $fileId "    objectName = obj;"
    puts $fileId "  \} else \{"
    puts $fileId [appendStr "    objectName = CORBA::string_dup(\"" $IDLInterface "\");"]
    puts $fileId "  \}"
    puts $fileId ""
    puts $fileId "  ScsProcessIdl_var destination;"
    puts $fileId "  try \{"
    puts $fileId [appendStr "    BIND_WITH_MARKER($IDLInterface" ", destination, objectName, implementation, NULL);"]
    puts $fileId ""
    puts $fileId "    void * timedOut;"
    puts $fileId ""
    puts $fileId "    if (timeout != ScadaORB::inst->GetORBDefaultTimeout()) \{"
    puts $fileId "      FIXTIMEOUT(timeout, ScsProcessIdl, destination, timedOut);"
    puts $fileId "      destination = (ScsProcessIdl_ptr)timedOut;"
    puts $fileId "    \}"
    puts $fileId ""
    puts $fileId "    ScsImgModule::addDestination(destination, timeout);"
    puts $fileId ""
    puts $fileId "    ret = TRUE;"
    puts $fileId ""    
    puts $fileId "  \} catch(CORBA::SystemException & sysEx) \{"
    puts $fileId [appendStr "    RedTraceLevel(0, \"Module " $className " failed to connect to local server: \" << _serverName << \"\\n\" << sysEx);"]
    puts $fileId "  \} catch(...) \{"
    puts $fileId [appendStr "    RedTraceLevel(0, \"Module " $className " failed to connect to local server: \" << _serverName);"]
    puts $fileId "  \}"
    puts $fileId ""
    puts $fileId "  return ret;"
    puts $fileId "\}"
    puts $fileId ""

    ##################
    # setStandByUp
    ##################
    puts $fileId "int"
    puts $fileId [appendStr $className "::setStandByUp(const char * remoteService, const char * remoteHost)"]
    puts $fileId "\{"
    puts $fileId [appendStr "  RedTraceLevel(8, \"" $className "::setStandByUp(\" << remoteService << \", \" << remoteHost << \") serverName=\" << _serverName);"]
    puts $fileId ""
    puts $fileId "  char * obj = GetObjectNameFromObjectId(_serverName);"
    puts $fileId "  CORBA::String_var objectName;"
    puts $fileId "  if (obj) \{"
    puts $fileId "    objectName = obj;"
    puts $fileId "  \} else \{"
    puts $fileId [appendStr "    objectName = CORBA::string_dup(\"" $IDLInterface "\");"]
    puts $fileId "  \}"
    puts $fileId ""
    puts $fileId "\#ifdef SCS_STD"
    puts $fileId "  std::ostringstream fullObjectName;"
    puts $fileId "\#else"
    puts $fileId "  ostrstream fullObjectName;"
    puts $fileId "\#endif"
    puts $fileId "  fullObjectName << objectName.in() << \"|\" << _priority;"
    puts $fileId ""
    puts $fileId "  char * srv = GetServerNameFromObjectId(_serverName);"
    puts $fileId "  CORBA::String_var serverName;"
    puts $fileId "  if (srv) \{"
    puts $fileId "    serverName = srv;"
    puts $fileId "  \} else \{"
    puts $fileId "    serverName = CORBA::string_dup(_serverName);"
    puts $fileId "  \}"
    puts $fileId ""
    puts $fileId "  try \{"
    puts $fileId "    InputMgrBindingsIdl_ptr binder = ScsImgModule::getRemoteBindings();"
    puts $fileId ""
    puts $fileId "    ScsProcessIdl_var server;"
    puts $fileId "    ScsProcessIdl_var imgModule;"
    puts $fileId ""    
    puts $fileId [appendStr "    ScsStatusIdl statusIdl = binder->tryBind(serverName, fullObjectName.str().c_str(), server, imgModule);"]
    puts $fileId "    ScsStatus status = ScsStatus((AntStatus::AntMajor)statusIdl.major, statusIdl.minor);"
    puts $fileId ""
    puts $fileId "    if (status.isValid()) \{"
    puts $fileId [appendStr "      _remoteImgModule = InputMgr_" $InterfaceName "Idl::_narrow(imgModule);"]
    puts $fileId "    \} else \{"
    puts $fileId [appendStr "      RedTraceLevel(0, \"Error in tryBind in " $className "::setStandByUp()\");"]
    puts $fileId "    \}"
    puts $fileId ""
    puts $fileId "  \} catch(CORBA::SystemException & sysEx) \{"
    puts $fileId [appendStr "    RedTraceLevel(0, \"Module " $className " failed to connect to remote server: \" << _serverName << \"\\n\" << sysEx);"]
    puts $fileId "    _remoteImgModule = NULL;"
    puts $fileId "  \} catch(...) \{"
    puts $fileId [appendStr "    RedTraceLevel(0, \"Module " $className " failed to connect to remote server: \" << _serverName);"]
    puts $fileId "    _remoteImgModule = NULL;"
    puts $fileId "  \}"
    puts $fileId ""
    puts $fileId "  return (_remoteImgModule != NULL);"
    puts $fileId "\}"
    puts $fileId ""


    #######################
    # 'request_name'Answer
    #######################

    # for each function containing "out" arguments
    foreach {operation} $OrderedOperationList {

	set operationName [lindex $operation 1]

	# only generate functions if the number of out args is not 0
	if {[getNumberOfInoutAndOutArgs $operationName] != 0} {
	    
    	    puts $fileId "static void"
    	    puts $fileId [appendStr $InterfaceName "_" $operationName "Answer(CORBA::Request * fromRequest, CORBA::Request * toRequest)"]
    	    puts $fileId "\{"
	    puts $fileId ""
    	    puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
	    puts $fileId "  timeval t = Scadasoft::GetOSTime();"
	    puts $fileId "  affTimeString tString;"
    	    puts $fileId [appendStr "  SCS_SL_STD(cout) << \"--> " $InterfaceName "_" $operationName "Answer: \" << affTime(t, tString) << SCS_SL_STD(endl);"]
    	    puts $fileId "\#endif"
    	    puts $fileId ""
    	    puts $fileId "  const ScsStatusIdl * resultIdl;"
    	    puts $fileId ""
    	    puts $fileId [initialiseOutArgs $operationName 2]
    	    puts $fileId ""
    	    puts $fileId "  // Extract return value and 'out' arguments"
    	    puts $fileId "  *(fromRequest->result()->value()) >>= resultIdl;"
    	    puts $fileId [decodeArgs $operationName 2]
    	    puts $fileId ""
    	    puts $fileId "  // Copy return value and 'out' args"
    	    puts $fileId "  *(toRequest->arguments()->item(1)->value()) <<= *resultIdl;"
    	    puts $fileId [addToArgListOutArgs $operationName 2]
	    puts $fileId ""
    	    puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
	    puts $fileId "  t = Scadasoft::GetOSTime();"
    	    puts $fileId [appendStr "  SCS_SL_STD(cout) << \"--> " $InterfaceName "_" $operationName "Answer: \" << affTime(t, tString) << SCS_SL_STD(endl);"]
    	    puts $fileId "\#endif"
    	    puts $fileId "\}"
    	    puts $fileId ""	
	}
    }


    #######################
    # 'request_name'
    #######################

    foreach {operation} $OrderedOperationList {
	
    	set operationName [lindex $operation 1]
	
    	puts $fileId "void"
    	set operationFirstLine [appendStr $className "::" $operationName "(ScsProcessIdl_ptr source,"]
    	set argumentFirstCharPos [expr [string first "(" $operationFirstLine ] + 1]
	
    	set otherArgs [cxxInArgsRef $operationName $argumentFirstCharPos]
	
    	puts $fileId $operationFirstLine
    	puts $fileId [addWhiteSpaces "CORBA::ULong timeout," $argumentFirstCharPos]
	puts $fileId [addWhiteSpaces "CORBA::UShort priority," $argumentFirstCharPos]
    	puts $fileId [addWhiteSpaces "const ScsMessageTag & tag," $argumentFirstCharPos]
    	puts $fileId [appendStr [addWhiteSpaces "const ScsTimeValIdl & onlineTime$otherArgs" $argumentFirstCharPos] ")"]
    	puts $fileId "  throw(CORBA::SystemException)"
    	puts $fileId "\{"
    	puts $fileId ""
    	puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
	puts $fileId "  timeval t = Scadasoft::GetOSTime();"
	puts $fileId "  affTimeString tString;"
	puts $fileId [appendStr "  SCS_SL_STD(cout) << \"--> " $className "::" $operationName ": \" << affTime(t, tString) << SCS_SL_STD(endl);"]
    	puts $fileId "\#endif"
    	puts $fileId ""
	puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
    	puts $fileId [appendStr "  RedTraceLevel(8, \"Creation of Message '" $operationName "' for \""]
    	puts $fileId "               << (ScsImgModule::getDestination(timeout) == NULL ? _serverName : SCS_OBJECT_ID(ScsImgModule::getDestination(timeout)))"
    	puts $fileId "               << \" tag=\[\""
    	puts $fileId "               << tag.environment << \" \" << tag.name << \" \""
    	puts $fileId "               << tag.pid << \" \" << tag.time << \" \""
    	puts $fileId "               << tag.index << \" \" << tag.nbPhysEnvRunning << \"\]\");"
	puts $fileId "\#endif"
    	puts $fileId ""
    	puts $fileId ""
    	puts $fileId "  // -----------------------------------"
    	puts $fileId "  // Build arguments for Standby request"
    	puts $fileId "  // -----------------------------------"
    	puts $fileId "  CORBA::NVList_ptr     standByNVList   = NULL;"
    	puts $fileId "  CORBA::NamedValue_ptr standByNVResult = NULL;"
    	puts $fileId ""
    	puts $fileId "  if (this->needStandbyArgs()) \{"
	puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
        puts $fileId [appendStr "    RedTraceLevel(8, \"Create arguments for standby request '" $operationName "'\");"]
	puts $fileId "\#endif"
    	puts $fileId ""
    	puts $fileId "\#ifdef _SCS_TAO_"
    	puts $fileId [appendStr "    ScadaORB::inst->CreateList(0, standByNVList);"]
    	puts $fileId "\#else"
    	puts $fileId [appendStr "    ScadaORB::inst->CreateList(" [expr [getNumberOfInAndInoutArgs $operationName] + 5] ", standByNVList);"]
    	puts $fileId "\#endif"
    	puts $fileId ""
    	puts $fileId [duplicateArgs $operationName 4]
    	puts $fileId ""
    	puts $fileId "    *(standByNVList->add(CORBA::ARG_IN)->value()) <<= source;"
    	puts $fileId "    *(standByNVList->add(CORBA::ARG_IN)->value()) <<= timeout;"
      puts $fileId "    *(standByNVList->add(CORBA::ARG_IN)->value()) <<= priority;"
    	puts $fileId "    *(standByNVList->add(CORBA::ARG_IN)->value()) <<= tag;"
    	puts $fileId "    *(standByNVList->add(CORBA::ARG_IN)->value()) <<= onlineTime;"
    	puts $fileId ""
    	puts $fileId [addToArgListInArgs $operationName 4 standByNVList]
    	puts $fileId ""
    	puts $fileId "    ScadaORB::inst->CreateNamedValue(standByNVResult);"
    	puts $fileId "  \}"
	puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
    	puts $fileId "  else \{"
    	puts $fileId [appendStr "    RedTraceLevel(8, \"No standby request for '" $operationName "' \");"]
    	puts $fileId "  \}"
	puts $fileId "\#endif"
    	puts $fileId ""
    	puts $fileId "  // ----------------------------------"
    	puts $fileId "  // Build arguments for online request"
    	puts $fileId "  // ----------------------------------"
    	puts $fileId "  CORBA::NVList_ptr     onlineNVList   = NULL;"
    	puts $fileId "  CORBA::NamedValue_ptr onlineNVResult = NULL;"
    	puts $fileId ""
	puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
        puts $fileId [appendStr "  RedTraceLevel(8, \"Create arguments for online request '" $operationName "'\");"]
	puts $fileId "\#endif"
    	puts $fileId ""
    	puts $fileId "\#ifdef _SCS_TAO_"
    	puts $fileId [appendStr "  ScadaORB::inst->CreateList(0, onlineNVList);"]
    	puts $fileId "\#else"
    	puts $fileId [appendStr "  ScadaORB::inst->CreateList(" [getNumberOfArgs $operationName] ", onlineNVList);"]
    	puts $fileId "\#endif"
    	puts $fileId ""
      if {[getNumberOfOutArgs $operationName] != 0} {
            puts $fileId "\n     // dummy values for output parameters\n"
            puts $fileId [appendStr [declareOutArgs $operationName 5] ]
            puts $fileId "\n\n"
        }
        
    	puts $fileId [addToArgListAllArgs $operationName 2 onlineNVList]
    	puts $fileId ""
    	puts $fileId "  ScadaORB::inst->CreateNamedValue(onlineNVResult);"
    	puts $fileId ""
    	puts $fileId "  // --------------------"
    	puts $fileId "  // Build answer request"
    	puts $fileId "  // --------------------"
    	puts $fileId "  CORBA::Request_ptr aRequest = NULL;"
	
        if {[string compare [lindex $IDLOperation($operationName) 0] "oneway"] == 0} {
    	    puts $fileId ""
    	    puts $fileId "  // Oneway request => no answer needed"
	    puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
      	    puts $fileId [appendStr "  RedTraceLevel(8, \"No answer request for '" $operationName "' (oneway request)\");"]
	    puts $fileId "\#endif"
	    
        } else {
	    
	    if {([getNumberOfInoutAndOutArgs $operationName] == 0) && ([string compare [lindex $IDLOperation($operationName) 1] "void"] == 0)} {
		puts $fileId ""
		puts $fileId "  // Operation without 'out' or 'inout' args and return value => no answer needed"
		puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
		puts $fileId [appendStr "  RedTraceLevel(8, \"No answer request for '" $operationName "' (no 'out' args request)\");"]
		puts $fileId "\#endif"

	    } else  {
		
		puts $fileId "  if (!CORBA::is_nil(source)) \{"
		puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
		puts $fileId [appendStr "    RedTraceLevel(8, \"Create answer request '" $operationName "Reply' for \" << SCS_OBJECT_ID(source));"]
		puts $fileId "\#endif"
		puts $fileId ""
		puts $fileId "    CORBA::NVList_var     answerNVList;"
		puts $fileId "    CORBA::NamedValue_var answerNVResult;"
		puts $fileId ""
		puts $fileId "    ScsStatusIdl scsResult;"
		puts $fileId "    ScsStatus    status = ImgNoReplyError;"
		puts $fileId "    scsResult.minor = status.getMinor();"
		puts $fileId "    scsResult.major = status.getMajor();"
		puts $fileId ""
		puts $fileId "    ScsMessageTag replyTag = tag;"
		puts $fileId "    replyTag.nbPhysEnvRunning = Scadasoft::GetNbPhysEnvRunning();"
		puts $fileId ""
		puts $fileId "\#ifdef _SCS_TAO_"
		puts $fileId [appendStr "    ScadaORB::inst->CreateList(0, answerNVList);"]
		puts $fileId "\#else"
		puts $fileId [appendStr "    ScadaORB::inst->CreateList(" [expr [getNumberOfInoutAndOutArgs $operationName] + 2] ", answerNVList);"]
		puts $fileId "\#endif"
		puts $fileId ""
		puts $fileId "    *(answerNVList->add(CORBA::ARG_IN)->value()) <<= replyTag;"
		puts $fileId "    *(answerNVList->add(CORBA::ARG_IN)->value()) <<= scsResult;"
		puts $fileId [addToArgListAnswerOutArgs $operationName 4 answerNVList]
		puts $fileId ""
		puts $fileId "    ScadaORB::inst->CreateNamedValue(answerNVResult);"
		puts $fileId ""
		puts $fileId "    try \{"
		puts $fileId "      source->_create_request(CORBA::Context::_nil(),"
		puts $fileId [appendStr "                              \"$operationName" "Reply\","]
		puts $fileId "                              answerNVList,"
		puts $fileId "                              answerNVResult,"
		puts $fileId "                              aRequest,"
		puts $fileId "                              0);"
		puts $fileId ""
		puts $fileId "      aRequest->set_return_type(CORBA::_tc_void);"
		puts $fileId "    \} catch(CORBA::SystemException & sysEx) \{"
		puts $fileId [appendStr "      RedTraceLevel(8, \"ERROR in answer request '" $operationName "Reply'\" << ScadaORB::inst->GetOrbExceptionText(sysEx));"]
		puts $fileId "      source = NULL;"
		puts $fileId "    \} catch(...) \{"
		puts $fileId [appendStr "      RedTraceLevel(8, \"UNKNOWN ERROR in online request '" $operationName "Reply' !!\");"]
		puts $fileId "      source = NULL;"
		puts $fileId "    \}"
		puts $fileId "  \} else \{"
		puts $fileId [appendStr "    RedTraceLevel(8, \"No reply request for '" $operationName "' (Reply object not provided)\");"]
		puts $fileId "  \}"
	    }
        }
        
        puts $fileId ""
    	puts $fileId "  // --------------"
    	puts $fileId "  // Create message"
    	puts $fileId "  // --------------"
    	puts $fileId [appendStr "  ImgMessage * msg = new ImgMessage(\"" $InterfaceName "\",\"" $operationName "\","]
	
        if {[string compare [lindex $IDLOperation($operationName) 0] "oneway"] == 0} {
	    # Special case for TimeClient  
            if {([string compare $InterfaceName "TimeClient"] == 0) && ([string compare $operationName "syncWakeUp"] == 0)} {
                puts $fileId "                                    ImgMessage::OneWay, // case of asynchroneous Timers"
            } else {
    	        puts $fileId "                                    ImgMessage::SyncVoid,"
            }
    	} else {
	    # Special case when an operation returns 'void'
    	    if {[string compare [lindex $IDLOperation($operationName) 1] "void"] == 0} {
		puts $fileId "                                    ImgMessage::SyncVoid,"
	    } else {
		puts $fileId "                                    ImgMessage::Sync,"
	    }
        }

        puts $fileId "                                    tag,"    
    	puts $fileId [appendStr "                                    " [staticFunctionOrAnswer $InterfaceName $operationName] ","]
    	puts $fileId "                                    onlineNVList,"
    	puts $fileId "                                    onlineNVResult,"
    	puts $fileId "                                    standByNVList,"
    	puts $fileId "                                    standByNVResult,"
    	puts $fileId "                                    aRequest,"
	puts $fileId "                                    timeout,"
    	puts $fileId "                                    this);"
    	puts $fileId ""
    	puts $fileId "  this->insertMsg(msg, tag, onlineTime, (ScsPriorityLevels) priority);"
    	puts $fileId ""
    	puts $fileId "\#ifdef _SCS_IMGR_TRACE_"
	puts $fileId "  t = Scadasoft::GetOSTime();"
	puts $fileId [appendStr "  SCS_SL_STD(cout) << \"--> " $className "::" $operationName ": \" << affTime(t, tString) << SCS_SL_STD(endl);"]
    	puts $fileId "\#endif"
	puts $fileId ""
    	puts $fileId "\}"
    	puts $fileId ""
    }
}
