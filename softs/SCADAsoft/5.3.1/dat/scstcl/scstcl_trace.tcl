################################################################################
#
# Namespace: ScsTrace
# Returns:
# Description: ScsTrace Scadasoft Tcl implementation
#
################################################################################
#
# Author: Pascal GEORGET
# Creation: /01/2000
# Modification:
#
################################################################################

namespace eval ScsTrace {

   namespace export setLogFile setTrace trace;
   
   variable _channelId
   set _channelId stdout;
   variable _currentTraceLevel
   
################################################################################
#
# Procedure: setLogFile
# Returns:
# Description: Assigne a new output channel for the traces
#
################################################################################

   proc setLogFile {{ChannelId stdout}} {
      variable _channelId;
      set _channelId $ChannelId
   }
   
################################################################################
#
# Procedure: setTrace
# Returns:
# Description: Assign trace level
#
################################################################################

   proc setTrace {LevelMask} {
      variable _currentTraceLevel
      for {set i 0} {$i < 32} {incr i 1} {
         set _currentTraceLevel($i) [expr $LevelMask & [expr 1 << $i]]
      }
   }
   
################################################################################
#
# Procedure: trace
# Returns:
# Description: output trace
#
################################################################################

   proc trace {Level Format args} {
      variable _currentTraceLevel
      if {[info exists _currentTraceLevel($Level)] && $_currentTraceLevel($Level)} {
         _TraceFunction $Level [eval {format $Format} $args]
      }
   }
   
   proc _TraceFunction {Level Message} {
      variable _channelId
      set procName [lindex [info level 1] 0]
      if {$procName == "ScsTrace::trace"} {
         set procName "Main"
      }
      puts $_channelId \
         [format "\[%d\]  %s@%s %s \n     (%s) <<%s>>" \
         $Level $Scs::_serverName $Scs::_envName \
         [clock format [clock seconds]] $procName $Message]
   }
}
