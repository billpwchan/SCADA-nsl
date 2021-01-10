################################################################################
#
# Namespace: ScsRpl
# Returns:
# Description: Tcl implementation of the Replay Scadasoft component
#
################################################################################
#
# Author: Jerome MARTINET
# Creation: 29/06/2004
# Modification:
#
################################################################################

namespace eval ScsRpl {

   namespace export init end;
   namespace export start stop freeze continue load getInfos snapshotTraining step;
   namespace export activateRecMgr deactivateRecMgr getAvailableRecordedFilesOnRecMgr isRecording;
   
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Rpl component
#
################################################################################

   proc init {} {
      ScsTcl_Rplinit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Rpl component
#
################################################################################

   proc end {} {
      ScsTcl_Rplend
   }
   
################################################################################
#
# Procedure: start
# Returns:
# Description: start the Replay
#
################################################################################

   proc start {EnvName pSpeed } {
      ScsTcl_RplStart $EnvName $pSpeed
   }
   
################################################################################
#
# Procedure: stop
# Returns:
# Description: stop the Replay
#
################################################################################

   proc stop {EnvName} {
      ScsTcl_RplStop $EnvName
   }
   
################################################################################
#
# Procedure: freeze
# Returns:
# Description: freeze the Replay
#
################################################################################

   proc freeze {EnvName} {
      ScsTcl_RplFreeze $EnvName
   }
   
################################################################################
#
# Procedure: continue
# Returns:
# Description: restart the Replay after a freeze
#
################################################################################

   proc continue {EnvName} {
      ScsTcl_RplContinue $EnvName
   }
   
################################################################################
#
# Procedure: load
# Returns:
# Description: load the correct snapshot in order to start the Replay
#
################################################################################

   proc load { EnvName pDate SessionInfo} {
      ScsTcl_RplLoad $EnvName $pDate $SessionInfo
   }

################################################################################
#
# Procedure: step
# Returns:
# Description: increase by step the Replay time
#
################################################################################

   proc step { EnvName stepTime} {
      ScsTcl_RplStep $EnvName $stepTime
   }

################################################################################
#
# Procedure: getInfos
# Returns:
# Description: retreives replay manager informations.
#
################################################################################

   proc getInfos { EnvName RplManagerState RplManagerSpeed RplManagerStartDate RplManagerSessionInfo RplManagerFilesList} {
       upvar $RplManagerState State
       upvar $RplManagerSpeed Speed
       upvar $RplManagerStartDate StartDate
       upvar $RplManagerSessionInfo SessionInfo
       upvar $RplManagerFilesList FilesList
       ScsTcl_RplGetInfos $EnvName State Speed StartDate SessionInfo FilesList
   }

################################################################################
#
# Procedure: activateRecMgr
# Returns:
# Description: activate the record manager
#
################################################################################

   proc activateRecMgr { EnvName } {
      ScsTcl_RplRecordActivate $EnvName 1
   }

################################################################################
#
# Procedure: deactivateRecMgr
# Returns:
# Description: load the correct snapshot in order to start the Replay
#
################################################################################

   proc deactivateRecMgr { EnvName } {
      ScsTcl_RplRecordActivate $EnvName 0
   }
   
################################################################################
#
# Procedure: getRecordedFilesOnRecMgr
# Returns:
# Description: returns the list of recorded files and directories that are available
#
################################################################################

   proc getAvailableRecordedFilesOnRecMgr { EnvName RecMgrFilesList} {
      upvar $RecMgrFilesList FilesList
      ScsTcl_RplgetAvailableRecordedFilesOnRecMgr $EnvName FilesList
   }

################################################################################
#
# Procedure: isRecording
# Returns:
# Description: returns the recording state
#
################################################################################
   proc isRecording { EnvName } {
       ScsTcl_RplRecordIsActivated $EnvName
   }

################################################################################
#
# Procedure: snapshotTraining
# Returns:
# Description: send the snapshot order in training mode
#
################################################################################

   proc snapshotTraining { EnvName SnapPath } {
      ScsTcl_RplsnapshotTraining $EnvName $SnapPath
   }
}

