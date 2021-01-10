################################################################################
#
# Namespace: 
# File name: genreplycode.tcl
# Returns:
# Description: Generates the C++ reply code file.
#
################################################################################
#
# Author: Alain Bartolo
# Creation: 03/11/2000
# Modification:
#
################################################################################

global IDLInterface OrderedOperationList startIdl lPath separator

set outputFile [appendStr $lPath $separator [replace [file tail [replace $startIdl "\\" "/"]] ".idl" ""] "reply_i.cpp"]

# Create file with the following format: IdlFileNamereply.idl
set fileId [open $outputFile w 0666]

# if no interface was defined in IDL (only typedefs for example)
# create an empty file based on the file name and exit
if {[info exists IDLInterface] == 0} {

    puts $fileId [generateHeader $outputFile "the Reply C++ code file" \
		      "Reply C++ code file generated from the $startIdl interface" "cxx"]

} else {

    # make sure interface name ends with "Idl" 
    checkInterfaceName $IDLInterface $startIdl "genreplycode"

    # get interface name (get rid of "Idl" suffix)
    set InterfaceName [getInterfaceName $IDLInterface]
    set className [appendStr $InterfaceName "Reply_i"]

    puts $fileId [generateHeader $outputFile "the Reply C++ code file" \
		      "Reply C++ code file generated from the $IDLInterface interface" "cxx"]

    puts $fileId "\#include \"scadaorb.h\""
    puts $fileId [appendStr "\#include \"" [replace [file tail [replace $startIdl "\\" "/"]] ".idl" "reply_i.hh"] "\""]
    puts $fileId "\#include <proxyerror.h>"
    puts $fileId "\#include \"scsutils.h\""
    puts $fileId ""
    puts $fileId [appendStr $className "::" $className "(int nbMaxReplies)"]
    puts $fileId [appendStr " :" $InterfaceName "ReplySOAP(1),"]
    puts $fileId "  _filter(nbMaxReplies)"
    puts $fileId "\{"
    puts $fileId "\#ifdef _SCS_REPLY_TRACE_"
    puts $fileId "  timeval t = Scadasoft::GetOSTime();"
    puts $fileId "  affTimeString tString;"
    puts $fileId [appendStr "  SCS_SL_STD(cout) << \"-->" $className "::" $className ": \" << affTime(t, tString) << SCS_SL_STD(endl);"]
    puts $fileId "\#endif"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId [appendStr $className "::" $className "(PortableServer::POA_var & poa, int nbMaxReplies)"]
    puts $fileId [appendStr " :" $InterfaceName "ReplySOAP(poa),"]
    puts $fileId "  _filter(nbMaxReplies)"
    puts $fileId "\{"
    puts $fileId "\#ifdef _SCS_REPLY_TRACE_"
    puts $fileId "  timeval t = Scadasoft::GetOSTime();"
    puts $fileId "  affTimeString tString;"
    puts $fileId [appendStr "  SCS_SL_STD(cout) << \"-->" $className "::" $className ": \" << affTime(t, tString) << SCS_SL_STD(endl);"]
    puts $fileId "\#endif"
    puts $fileId "\}"
    puts $fileId ""
    puts $fileId [appendStr $className "::~" $className "(void)"]
    puts $fileId "\{"
    puts $fileId "\#ifdef _SCS_REPLY_TRACE_"
    puts $fileId "  timeval t = Scadasoft::GetOSTime();"
    puts $fileId "  affTimeString tString;"
    puts $fileId [appendStr "  SCS_SL_STD(cout) << \"<--" $className "::~" $className ": \" << affTime(t, tString) << SCS_SL_STD(endl);"]
    puts $fileId "\#endif"
    puts $fileId "\}"
    puts $fileId ""

    foreach {operation} $OrderedOperationList {

	set operationName [lindex $operation 1]

	set operationFirstLine [appendStr "void " $className "::" $operationName "Reply(const ScsMessageTag & tag,"]
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

	puts $fileId "  throw(CORBA::SystemException)"
	puts $fileId "\{"
	puts $fileId ""
	puts $fileId "\#ifdef _SCS_REPLY_TRACE_"
	puts $fileId "  timeval t = Scadasoft::GetOSTime();"
	puts $fileId "  affTimeString tString;"
	puts $fileId [appendStr "  SCS_SL_STD(cout) << \"-->" $className "::" $operationName "Reply: \" << affTime(t, tString) << SCS_SL_STD(endl);"]
	puts $fileId "\#endif"
	puts $fileId ""
	puts $fileId "   if(_filter.addMessageNoOrderControl(tag) == 1) \{"
	puts $fileId ""
	puts $fileId "\#ifdef _SCS_REPLY_TRACE_"
	puts $fileId "     t = Scadasoft::GetOSTime();"
	puts $fileId [appendStr "     SCS_SL_STD(cout) << \"-->" $className "::" $operationName "Reply.filterMessage: \" << affTime(t, tString) << SCS_SL_STD(endl);"]
	puts $fileId "\#endif"
	puts $fileId ""

	puts $fileId "     _replyLock.lock();"
	puts $fileId "     _replyTag = tag;"
	puts $fileId "     _result   = scsStatusIdlResult;"

	# only generate functions if the number of out args is not 0
	if {[getNumberOfInoutAndOutArgs $operationName] != 0} {
	    puts $fileId [uniqueOutArgsSet $operationName 5]
	}

	puts $fileId "     _filter.signalFirstMessage();"
	puts $fileId "     _replyLock.unlock();"
	puts $fileId "   \}"
	puts $fileId ""
	puts $fileId "\#ifdef _SCS_REPLY_TRACE_"
	puts $fileId "  t = Scadasoft::GetOSTime();"
	puts $fileId [appendStr "  SCS_SL_STD(cout) << \"<--" $className "::" $operationName "Reply: \" << affTime(t, tString) << SCS_SL_STD(endl);"]
	puts $fileId "\#endif"
	puts $fileId ""

	puts $fileId "\}"
	puts $fileId ""
    }

    puts $fileId "ScsStatus"
    puts $fileId [appendStr $className "::getResult(const ScsMessageTag & tag, const unsigned int & timeout)"]
    puts $fileId "\{"
    puts $fileId "   ScsStatus result;"
    puts $fileId ""
    puts $fileId "   // Wait for the right reply"
    puts $fileId "   int signaled;"
    puts $fileId "   do \{"
    puts $fileId "     signaled = (_filter.waitForFirstMessage(timeout) == SCS_SIGNALED);"
    puts $fileId "   \} while ( (signaled) && ( (_replyTag.time != tag.time) || (_replyTag.index != tag.index) || (strcmp((const char*) _replyTag.environment, (const char*) tag.environment) != 0) || (strcmp((const char*) _replyTag.name, (const char*) tag.name) != 0) || (_replyTag.pid != tag.pid) ) );"
    puts $fileId ""
    puts $fileId "   if(signaled) \{"
    puts $fileId "     result = ScsStatus((AntStatus::AntMajor)_result.major, _result.minor);"
    puts $fileId ""
    puts $fileId "     // This will throw an exception only if the status contains an exception code"
    puts $fileId "     ScadaORB::inst->ThrowExceptionFromScsStatus(result);"
    puts $fileId "   \} else \{"
    puts $fileId [appendStr "     result = ProxyErrTimeout(SCS_WARNING, \"" $className "::getResult()\");"]
    puts $fileId "   \}"
    puts $fileId ""
    puts $fileId "   return result;"
    puts $fileId "\}"
    puts $fileId ""

    foreach {operation} $OrderedOperationList {

	set operationName [lindex $operation 1]

	# only generate functions if the number of out args is not 0
	if {[getNumberOfInoutAndOutArgs $operationName] != 0} {
	    
	    puts $fileId "ScsStatus"
	    set firstOutLine [appendStr $className "::get" [string toupper $operationName 0 0] "Result(const ScsMessageTag & tag, const unsigned int & timeout, "]
	    set argumentFirstCharPos [expr [string first "(" $firstOutLine ] + 1]
	    puts $fileId [appendStr $firstOutLine [string trimleft [cxxArgsResult $operationName $argumentFirstCharPos false ]] ")"]
	    puts $fileId "\{"
	    puts $fileId ""
	    puts $fileId "\#ifdef _SCS_REPLY_TRACE_"
	    puts $fileId "  timeval t = Scadasoft::GetOSTime();"
            puts $fileId "  affTimeString tString;"
	    puts $fileId [appendStr "  SCS_SL_STD(cout) << \"-->" $className "::get" [string toupper $operationName 0 0] "Result: \" << affTime(t, tString) << SCS_SL_STD(endl);"]
	    puts $fileId "\#endif"
	    puts $fileId ""
	    puts $fileId "   ScsStatus scsStatusResult;"
	    puts $fileId ""
            puts $fileId "   // Wait for the right reply "
            puts $fileId "   int signaled;"
            puts $fileId "   do \{"
            puts $fileId "     signaled = (_filter.waitForFirstMessage(timeout) == SCS_SIGNALED);"
            puts $fileId "   \} while ( (signaled) && ( (_replyTag.time != tag.time) || (_replyTag.index != tag.index) || (strcmp((const char*) _replyTag.environment, (const char*) tag.environment) != 0) || (strcmp((const char*) _replyTag.name, (const char*) tag.name) != 0) || (_replyTag.pid != tag.pid) ) );"
            puts $fileId ""
            puts $fileId "   if(signaled) \{"
	    puts $fileId [uniqueOutArgsPutBack $operationName 5]
	    puts $fileId "     scsStatusResult = ScsStatus((AntStatus::AntMajor)_result.major, _result.minor);"
            puts $fileId ""
            puts $fileId "     // This will throw an exception only if the status contains an exception code"
            puts $fileId "     ScadaORB::inst->ThrowExceptionFromScsStatus(scsStatusResult);"

	    puts $fileId "   \} else \{"
	    puts $fileId [allocateOrInitOutReplyArgs $operationName 5]
	    puts $fileId [appendStr "     scsStatusResult = ProxyErrTimeout(SCS_WARNING, \"" $className "::get" [string toupper $operationName 0 0] "Result\");"]
	    puts $fileId "   \}"
	    puts $fileId ""
	    puts $fileId "\#ifdef _SCS_REPLY_TRACE_"
	    puts $fileId "  t = Scadasoft::GetOSTime();"
	    puts $fileId [appendStr "  SCS_SL_STD(cout) << \"<--" $className "::get" [string toupper $operationName 0 0] "Result: \" << affTime(t, tString) << SCS_SL_STD(endl);"]
	    puts $fileId "\#endif"
	    puts $fileId ""
	    puts $fileId "   return scsStatusResult;"
	    puts $fileId "\}"
	    puts $fileId ""
	}
    }
}
