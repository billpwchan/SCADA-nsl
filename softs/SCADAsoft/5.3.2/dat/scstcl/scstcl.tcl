################################################################################
#
# Namespace: Scs
# Returns:
# Description: Load each namespace of the Scadasoft Tcl implementation
#
################################################################################
#
# Author: Pascal GEORGET
# Creation: 19/01/2000
# Modification:
#
################################################################################

namespace eval Scs {

   namespace export initialize initializeWithMainLoop onError timerOrbixEvent;
   namespace export After Every CancelTimer;
   variable _serverName;
   variable _envName;
   set _serverName init;
   set _envName init;
   
################################################################################
#
# Procedure: initialize
# Returns:
# Description: Initialize the current Tcl script
#
################################################################################

   proc initialize {ServerName {EnvName ""}} {
      ScsTcl_initialize False $ServerName $EnvName
   }
   
   proc initializeWithMainLoop {ServerName {EnvName ""}} {
      ScsTcl_initialize True $ServerName $EnvName
      ScsTcl_acceptIncReq
   }
   
   proc exit {} {
      ScsTcl_Exit 
   }
   
################################################################################
#
# Procedure: onError
# Returns:
# Description: Assign new way of error treatment
#
################################################################################

   proc onError {OnErrorType} {
      ScsTcl_onError $OnErrorType
   }

################################################################################
#
# Procedure: After 
# Returns:
# Description: Timer oneshot
#
################################################################################

   proc After {pDelay pCallback {pArg ""}} {
      ScsTcl_Timer $pDelay 0 $pCallback $pArg
   }

################################################################################
#
# Procedure: Every 
# Returns:
# Description: Timer cyclic
#
################################################################################

   proc Every {pPeriod pCallback {pArg ""}} {
      ScsTcl_Timer $pPeriod $pPeriod $pCallback $pArg
   }

################################################################################
#
# Procedure: CancelTimer 
# Returns:
# Description: Cancel a Timer
#
################################################################################

   proc CancelTimer {pTimerId} {
      ScsTcl_CancelTimer $pTimerId
   }

}
