################################################################################
#
# Namespace: ScsTsc
# Returns:
# Description: Tcl implementation of the Tsc Scadasoft component
#
################################################################################
#
# Author: Pascal GEORGET
# Creation: 24/01/2000
# Modification:
#
################################################################################

namespace eval ScsTsc {

   namespace export init end;
   
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Tsc component
#
################################################################################

   proc init {} {
      ScsTcl_Tscinit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Tsc component
#
################################################################################

   proc end {} {
      ScsTcl_Tscend
   }
   
}