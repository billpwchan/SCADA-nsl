################################################################################
#
# Namespace: ScsDac
# Returns:
# Description: Tcl implementation of the Dac Scadasoft component
#
################################################################################
#
# Author: Pascal GEORGET
# Creation: 24/01/2000
# Modification:
#
################################################################################

namespace eval ScsDac {

   namespace export init end sendEOV subscribeEIV unsubscribeEIV;
   
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Dac component
#
################################################################################

   proc init {} {
      ScsTcl_Dacinit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Dac component
#
################################################################################

   proc end {} {
      ScsTcl_Dacend
   }
   
################################################################################
#
# Procedure: sendCommand
# Returns:
# Description: DacServer::sendEOV Tcl implementation
#
################################################################################

   proc sendEOV {EnvName VariableName VariableType VariableValue} {
      ScsTcl_DacsendEOV $EnvName $VariableName $VariableType $VariableValue
   }

################################################################################
#
# Procedure: subscribeEIV
# Returns:
# Description: DacServer::subscribeEIV Tcl implementation
#
################################################################################

   proc subscribeEIV {EnvName SubscriptionId IdList VariableNameList Callback} {
      upvar $SubscriptionId SubId
      upvar $IdList EivList
      ScsTcl_DacsubscribeEIV $EnvName SubId EivList $VariableNameList $Callback
   }

################################################################################
#
# Procedure: unsubscribeEIV
# Returns:
# Description: DacServer::unsubscribeEIV Tcl implementation
#
################################################################################

   proc unsubscribeEIV {EnvName SubscriptionId} {
      ScsTcl_DacunsubscribeEIV $EnvName $SubscriptionId
   }
}

namespace eval ScsDacSim {

   namespace export end init getEV setEV setGroupOfEV;
   
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Dac component
#
################################################################################

   proc init {} {
      ScsTcl_Dacinit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Dac component
#
################################################################################

   proc end {} {
      ScsTcl_Dacend
   }
   
   proc getEV {EnvName VarName} {
      ScsTcl_DacsimgetEV $EnvName $VarName
   }
   proc setEV {EnvName VarName VarType VarValue} {
      ScsTcl_DacsimsetEV $EnvName $VarName $VarType $VarValue
   }
   proc setGroupOfEV {EnvName VarList} {
      ScsTcl_DacsimsetGroupOfEV $EnvName $VarList
   }
}
