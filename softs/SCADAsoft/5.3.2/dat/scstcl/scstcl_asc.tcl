################################################################################
#
# Namespace: ScsAsc
# Returns:
# Description: Tcl implementation of the Asc Scadasoft component
#
################################################################################
#
# Author: Pascal GEORGET
# Creation: 19/01/2000
# Modification:
#
################################################################################

namespace eval ScsAsc {

    namespace export init end subscribeState unsubscribe runCmd;
    namespace export getProcessInfos shutdown;
   
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Asc component
#
################################################################################

   proc init {} {
      ScsTcl_Ascinit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Asc component
#
################################################################################

   proc end {} {
      ScsTcl_Ascend
   }
   
################################################################################
#
# Procedure: subscribeState
# Returns:
# Description: AscManager::subscribeState Tcl implementation
#
################################################################################

   proc subscribeState {EnvName ServerName CallbackProcedure} {
      ScsTcl_AscMsubscribeState $EnvName $ServerName $CallbackProcedure
   }
################################################################################
#
# Procedure: unubscribe
# Returns:
# Description: AscManager::unsubscribe Tcl implementation
#
################################################################################

   proc unsubscribe {EnvName ServerName} {
      ScsTcl_AscMunsubscribe $EnvName $ServerName
   }

################################################################################
#
# Procedure: runCmd
# Returns:
# Description: AscAgent::runCmd Tcl implementation
#
################################################################################

   proc runCmd {ServerName Termination Notification Supervision Prio Snapshot {RunString ""}} {
      ScsTcl_AscRunCmd $ServerName $Termination $Notification \
	  $Supervision $Prio $Snapshot $RunString
   }

################################################################################
#
# Procedure: getProcessInfos
# Returns:
# Description: AscAgent::getProcessInfos Tcl implementation
#
################################################################################

   proc getProcessInfos {} {
      ScsTcl_AscGetProcessInfos
   }

################################################################################
#
# Procedure: shutdown
# Returns:
# Description: AscAgent::shutdown Tcl implementation
#
################################################################################

   proc shutdown {} {
      ScsTcl_AscShutdown
   }


################################################################################
#
# Procedure: getHosts
# Returns:
# Description: AscManager::getHosts Tcl implementation
#
################################################################################

   proc getHosts { pEnvName } {
      ScsTcl_AscGetHosts $pEnvName
   }

}
