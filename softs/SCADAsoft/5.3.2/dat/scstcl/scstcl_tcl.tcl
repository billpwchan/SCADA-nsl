################################################################################
#
# Namespace: ScsTcl
# Returns:
# Description: Tcl implementation of the Tcl Scadasoft component
#
################################################################################
#
# Author: Pascal GEORGET
# Creation: 19/01/2000
# Modification:
#
################################################################################

namespace eval ScsTcl {

   namespace export init end Remote
   
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Tcl component
#
################################################################################

   proc init {} {
      ScsTcl_Tclinit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Tcl component
#
################################################################################

   proc end {} {
      ScsTcl_Tclend
   }
      
################################################################################
#
# Procedure: Remote 
# Returns:
# Description: Remote Call
#
################################################################################

   proc Remote { pEnv pServer pInstruction {pasyncMode 0}  } {
      ScsTcl_TclRemote $pEnv $pServer $pInstruction $pasyncMode
   }
}
