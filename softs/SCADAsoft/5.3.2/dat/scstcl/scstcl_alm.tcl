################################################################################
#
# Namespace: ScsAlm
# Returns:
# Description: Tcl implementation of the Alm Scadasoft component
#
################################################################################
#
# Author: Jerome MARTINET
# Creation: 13/10/2004
# Modification:
#
################################################################################

namespace eval ScsAlm {

   namespace export init end;
   namespace export notifyExternalAlarm notifyExternalEvent getExtAlmFormatMessage getExtEventFormatMessage;
   namespace export setExtToNormal;
   namespace export acknowledgeAlarms shelveAlarms unshelveAlarms;
   namespace export updateExtAlarm;
   
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Alm component
#
################################################################################

   proc init {} {
      ScsTcl_Alminit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Alm component
#
################################################################################

   proc end {} {
      ScsTcl_Almend
   }
   

################################################################################
#
# Procedure: notifyExternalAlarm
# Returns:
# Description: 
#
################################################################################

   proc notifyExternalAlarm { EnvName FileName EquipmentId ClassId PointAlias SourceId State Message } {
      ScsTcl_ScsAlmNotifyExternalAlarm $EnvName $FileName $EquipmentId $ClassId $PointAlias $SourceId $State $Message
   }
   
################################################################################
#
# Procedure: notifyExternalAlarm
# Returns:
# Description: 
#
################################################################################
   proc setExtToNormal { EnvName EquipmentId MessageOfReset FileName SourceId } {
      ScsTcl_ScsAlmSetExtToNormal $EnvName $EquipmentId $MessageOfReset $FileName $SourceId
   }

################################################################################
#
# Procedure: getMessageFormat
# Returns:
# Description: 
#
################################################################################

   proc getExtAlmFormatMessage { EnvName FileName EquipmentId ClassId State } {
      ScsTcl_ScsAlmExtGetMessageFormat $EnvName $FileName $EquipmentId $ClassId $State
   }
   

################################################################################
#
# Procedure: getMessageFormat
# Returns:
# Description: 
#
################################################################################

   proc getExtEventFormatMessage { EnvName FileName EquipmentId ClassId } {
      ScsTcl_ScsAlmExtGetMessageFormat $EnvName $FileName $EquipmentId $ClassId 0
   }

################################################################################
#
# Procedure: notifyExternalEvent
# Returns:
# Description: 
#
################################################################################

   proc notifyExternalEvent { EnvName FileName EquipmentId ClassId PointAlias SourceId Message } {
      ScsTcl_ScsAlmNotifyExternalEvent $EnvName $FileName $EquipmentId $ClassId $PointAlias $SourceId $Message
   }

################################################################################
#
# Procedure: acknowledgeAlarms
# Returns:
# Description: 
#
################################################################################

   proc acknowledgeAlarms { EnvName IdList { UserId 0 } } {
      ScsTcl_ScsAlmAcknowledgeAlarmsWithinAlmId $EnvName $IdList $UserId
   }

################################################################################
#
# Procedure: shelveAlarms
# Returns:
# Description: 
#
################################################################################

   proc shelveAlarms { EnvName IdList { UserId 0 } } {
      ScsTcl_ScsAlmShelveAlarmsWithinAlmId $EnvName $IdList $UserId
   }

################################################################################
#
# Procedure: unshelveAlarms
# Returns:
# Description: 
#
################################################################################

   proc unshelveAlarms { EnvName IdList { UserId 0 } } {
      ScsTcl_ScsAlmUnShelveAlarmsWithinAlmId $EnvName $IdList $UserId
   }
   
################################################################################
#
# Procedure: updateExtAlarm
# Returns:
# Description: 
#
################################################################################
   
   proc updateExtAlarm { EnvName ExtAutoId State Severity EqpName ValueAutomaton AckAutomaton Message {FuncCat 0} {GeoCat 0} {EqpDate 0} {AcqDate 0} {User1 ""} {User2 ""} {LowThreshold  0} {HighThreshold 0} } {
   
    if { $EqpDate == 0 } {
      set EqpDate [clock seconds]
    }
    
    if { $AcqDate == 0 } {
      set AcqDate $EqpDate
    }
    
    ScsTcl_ScsAlmExtUpdate $EnvName $ExtAutoId $State $ValueAutomaton $AckAutomaton $EqpDate $AcqDate $Severity $FuncCat $GeoCat $EqpName $Message $User1 $User2 $LowThreshold $HighThreshold
   }
}
