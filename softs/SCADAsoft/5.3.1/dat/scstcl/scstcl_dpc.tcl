################################################################################
#
# Namespace: ScsDpc
# Returns:
# Description: Tcl implementation of the Dpc Scadasoft component
#
################################################################################
#
# Author: Pascal GEORGET
# Creation: 19/01/2000
# Modification:
#
################################################################################

namespace eval ScsDpc {
   namespace export init end changeEqpStatus changeVarForce changeVarStatus;
   namespace export changeEqpTag;
    namespace export isVarStatusValid isVarStatusForced isVarStatusAlaInhEqp isVarStatusInvChattering;
    namespace export isVarStatusAlaInh isVarStatusInvEqp isVarStatusInvOperator;
    namespace export isVarStatusInvCom isVarStatusInvConc isVarStatusInvOperand;
    namespace export isVarStatusInvApplication isEqpStatusNormal isEqpStatusAlarm;
    namespace export isEqpStatusCtrlInh isEqpStatusMonInh isEqpTagStatusNormal;
    namespace export isEqpTagStatusTag1 isEqpTagStatusTag2;
   
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Dpc component
#
################################################################################

   proc init {} {
      ScsTcl_Dpcinit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Dpc component
#
################################################################################

   proc end {} {
      ScsTcl_Dpcend
   }
   
################################################################################
#
# Procedure: changeEqpTag
# Returns:
# Description: DpcServer::changeEqpStatus Tcl implementation
#
################################################################################

    proc changeEqpTag {EnvName EqpName WorkingStatus {Source ""} {TagLabel1 ""} {TagLabel2 ""} } {
      ScsTcl_DpcchangeEqpTag $EnvName $EqpName $WorkingStatus $Source $TagLabel1 $TagLabel2
   }
     
################################################################################
#
# Procedure: changeEqpStatus
# Returns:
# Description: DpcServer::changeEqpStatus Tcl implementation
#
################################################################################

    proc changeEqpStatus {EnvName EqpName EqpStatus {Source ""} } {
      ScsTcl_DpcchangeEqpStatus $EnvName $EqpName $EqpStatus $Source
   }
     
################################################################################
#
# Procedure: changeVarForce
# Returns:
# Description: DpcServer::changeVarForce Tcl implementation
#
################################################################################

    proc changeVarForce {EnvName VarName VarForce {VarType ?} {VarValue ?} {Source ""}} {
      ScsTcl_DpcchangeVarForce $EnvName $VarName $VarForce $VarType $VarValue $Source
   }
     
################################################################################
#
# Procedure: changeVarStatus
# Returns:
# Description: DpcServer::changeVarStatus Tcl implementation
#
################################################################################

    proc changeVarStatus {EnvName VarName VarStatus {Source ""}} {
      ScsTcl_DpcchangeVarStatus $EnvName $VarName $VarStatus $Source
   }

################################################################################
#
# Procedure: isVarStatusxxx
# Returns:
# Description: DpcServer::isVarStatusxxxx Tcl implementation
#
################################################################################

    proc isVarStatusValid {VarStatus} {
	global DPC_K_STATUS_VALID
	return [expr $VarStatus & $DPC_K_STATUS_VALID]
    }
     
    proc isVarStatusForced {VarStatus} {
	global DPC_K_STATUS_VALID_FORCED
	return [expr $VarStatus & $DPC_K_STATUS_VALID_FORCED]
    }
     
    proc isVarStatusAlaInhEqp {VarStatus} {
	global DPC_K_STATUS_ALARM_INHIBIT_BY_EQP
	return [expr $VarStatus & $DPC_K_STATUS_ALARM_INHIBIT_BY_EQP]
    }
     
    proc isVarStatusAlaInh {VarStatus} {
	global DPC_K_STATUS_ALARM_INHIBIT
	return [expr $VarStatus & $DPC_K_STATUS_ALARM_INHIBIT]
    }
     
    proc isVarStatusInvEqp {VarStatus} {
	global DPC_K_STATUS_INVALID_EQUIPMENT
	return [expr $VarStatus & $DPC_K_STATUS_INVALID_EQUIPMENT]
    }
     
    proc isVarStatusInvOperator {VarStatus} {
	global DPC_K_STATUS_INVALID_OPERATOR
	return [expr $VarStatus & $DPC_K_STATUS_INVALID_OPERATOR]
    }
     
    proc isVarStatusInvCom {VarStatus} {
	global DPC_K_STATUS_INVALID_COMM
	return [expr $VarStatus & $DPC_K_STATUS_INVALID_COMM]
    }
     
    proc isVarStatusInvConc {VarStatus} {
	global DPC_K_STATUS_INVALID_CONCENTR
	return [expr $VarStatus & $DPC_K_STATUS_INVALID_CONCENTR]
    }
     
    proc isVarStatusInvOperand {VarStatus} {
	global DPC_K_STATUS_INVALID_OPERAND
	return [expr $VarStatus & $DPC_K_STATUS_INVALID_OPERAND]
    }
     
    proc isVarStatusInvApplication {VarStatus} {
	global DPC_K_STATUS_INVALID_APPLICATION
	return [expr $VarStatus & $DPC_K_STATUS_INVALID_APPLICATION]
    }
    
    proc isVarStatusInvChattering {VarStatus} {
	global DPC_K_STATUS_INVALID_CHATTERING
	return [expr $VarStatus & $DPC_K_STATUS_INVALID_CHATTERING]
    }
     
################################################################################
#
# Procedure: isEqpStatusxxx
# Returns:
# Description: DpcServer::isVarStatusxxxx Tcl implementation
#
################################################################################

    proc isEqpStatusNormal {EqpStatus} {
	global DPC_K_EQPSTATUS_NORMAL
	return [expr $EqpStatus & $DPC_K_EQPSTATUS_NORMAL]
    }
     
    proc isEqpStatusAlarm {EqpStatus} {
	global DPC_K_EQPSTATUS_ALARM
	return [expr $EqpStatus & $DPC_K_EQPSTATUS_ALARM]
    }
     
    proc isEqpStatusCtrlInh {EqpStatus} {
	global DPC_K_EQPSTATUS_CONTROL_INHIBITED
	return [expr $EqpStatus & $DPC_K_EQPSTATUS_CONTROL_INHIBITED]
    }
     
    proc isEqpStatusMonInh {EqpStatus} {
	global DPC_K_EQPSTATUS_MONITOR_INHIBITED
	return [expr $EqpStatus & $DPC_K_EQPSTATUS_MONITOR_INHIBITED]
    }
     
    proc isEqpTagStatusNormal {EqpStatus} {
	global DPC_K_TAGSTATUS_NORMAL
	return [expr $EqpStatus & $DPC_K_TAGSTATUS_NORMAL]
    }
     
    proc isEqpTagStatusTag1 {EqpStatus} {
	global DPC_K_TAGSTATUS_TAG1
	return [expr $EqpStatus & $DPC_K_TAGSTATUS_TAG1]
    }
     
    proc isEqpTagStatusTag2 {EqpStatus} {
	global DPC_K_TAGSTATUS_TAG2
	return [expr $EqpStatus & $DPC_K_TAGSTATUS_TAG2]
    }
     
}
