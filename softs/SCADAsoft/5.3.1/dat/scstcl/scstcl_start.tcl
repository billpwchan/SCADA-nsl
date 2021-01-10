################################################################################
#
# Namespace: ScsStart
# Returns:
# Description: Tcl implementation of the Start Scadasoft component
#
################################################################################
#
# Author: Marc ALTER
# Creation: 06/07/2001
# Modification:
#
################################################################################

namespace eval ScsStart {

   namespace export init end startProcessInfo;
   
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Start component
#
################################################################################

   proc init {} {
      ScsTcl_Startinit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Start component
#
################################################################################

   proc end {} {
      ScsTcl_Startend
   }
   
################################################################################
#
# Procedure: startProcessInfo
# Returns:
# Description: AscAgent::startProcessInfo Tcl implementation
#
################################################################################

   proc startProcessInfo {} {
      ScsTcl_StartProcessInfo
   }

}
