################################################################################
#
# Namespace: ScsWdg
# Returns:
# Description: Tcl implementation of the Wdg Scadasoft component
#
################################################################################
#
# Author: Marc ALTER
# Creation: 19/01/2000
# Modification:
#
################################################################################

namespace eval ScsWdg {

   namespace export init end testWatchdog getWatchdogLastLifeTime getWatchdogMode \
 getNet1SendState getLastNet1SendStateTime getNet1RecvState getLastNet1RecvStateTime \
 getNet2SendState getLastNet2SendStateTime getNet2RecvState getLastNet2RecvStateTime \
 getSerSendState getLastSerSendStateTime getSerRecvState getLastSerRecvStateTime;
   
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Wdg component
#
################################################################################

   proc init {} {
      ScsTcl_Wdginit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Wdg component
#
################################################################################

   proc end {} {
      ScsTcl_Wdgend
   }
   
################################################################################
#
# Procedure: testWatchdog
# Returns:
# Description: AscAgent::testWatchdog Tcl implementation
#
################################################################################

   proc testWatchdog {} {
      ScsTcl_WdgtestWatchdog
   }

################################################################################
#
# Procedure: getWatchdogLastLifeTime
# Returns:
# Description: AscAgent::getWatchdogLastLifeTime Tcl implementation
#
################################################################################

   proc getWatchdogLastLifeTime {} {
      ScsTcl_WdggetWatchdogLastLifeTime
   }

################################################################################
#
# Procedure: getWatchdogMode
# Returns:
# Description: AscAgent::getWatchdogMode Tcl implementation
#
################################################################################

   proc getWatchdogMode {} {
      ScsTcl_WdggetWatchdogMode
   }

################################################################################
#
# Procedure: getNet1SendState
# Returns:
# Description: AscAgent::getNet1SendState Tcl implementation
#
################################################################################

   proc getNet1SendState {} {
      ScsTcl_WdggetNet1SendState
   }

################################################################################
#
# Procedure: getLastNet1SendStateTime
# Returns:
# Description: AscAgent::getLastNet1SendStateTime Tcl implementation
#
################################################################################

   proc getLastNet1SendStateTime {} {
      ScsTcl_WdggetLastNet1SendStateTime
   }

################################################################################
#
# Procedure: getNet1RecvState
# Returns:
# Description: AscAgent::getNet1RecvState Tcl implementation
#
################################################################################

   proc getNet1RecvState {} {
      ScsTcl_WdggetNet1RecvState
   }

################################################################################
#
# Procedure: getLastNet1RecvStateTime
# Returns:
# Description: AscAgent::getLastNet1RecvStateTime Tcl implementation
#
################################################################################

   proc getLastNet1RecvStateTime {} {
      ScsTcl_WdggetLastNet1RecvStateTime
   }

################################################################################
#
# Procedure: getNet2SendState
# Returns:
# Description: AscAgent::getNet2SendState Tcl implementation
#
################################################################################

   proc getNet2SendState {} {
      ScsTcl_WdggetNet2SendState
   }

################################################################################
#
# Procedure: getLastNet2SendStateTime
# Returns:
# Description: AscAgent::getLastNet2SendStateTime Tcl implementation
#
################################################################################

   proc getLastNet2SendStateTime {} {
      ScsTcl_WdggetLastNet2SendStateTime
   }

################################################################################
#
# Procedure: getNet2RecvState
# Returns:
# Description: AscAgent::getNet2RecvState Tcl implementation
#
################################################################################

   proc getNet2RecvState {} {
      ScsTcl_WdggetNet2RecvState
   }

################################################################################
#
# Procedure: getLastNet2RecvStateTime
# Returns:
# Description: AscAgent::getLastNet2RecvStateTime Tcl implementation
#
################################################################################

   proc getLastNet2RecvStateTime {} {
      ScsTcl_WdggetLastNet2RecvStateTime
   }

################################################################################
#
# Procedure: getSerSendState
# Returns:
# Description: AscAgent::getSerSendState Tcl implementation
#
################################################################################

   proc getSerSendState {} {
      ScsTcl_WdggetSerSendState
   }

################################################################################
#
# Procedure: getLastSerSendStateTime
# Returns:
# Description: AscAgent::getLastSerSendStateTime Tcl implementation
#
################################################################################

   proc getLastSerSendStateTime {} {
      ScsTcl_WdggetLastSerSendStateTime
   }

################################################################################
#
# Procedure: getSerRecvState
# Returns:
# Description: AscAgent::getSerRecvState Tcl implementation
#
################################################################################

   proc getSerRecvState {} {
      ScsTcl_WdggetSerRecvState
   }

################################################################################
#
# Procedure: getLastSerRecvStateTime
# Returns:
# Description: AscAgent::getLastSerRecvStateTime Tcl implementation
#
################################################################################

   proc getLastSerRecvStateTime {} {
      ScsTcl_WdggetLastSerRecvStateTime
   }

}
