###############################
#
# ----- Namespace
#
###############################
namespace eval His {
    variable secondaryEnvironments {}
}


###############################
#
# ----- Variables
#
###############################



###############################
#
# ---- Procedure
#
###############################

proc His::Connect { pEnv pServer args} {
    variable secondaryEnvironments
    set secondaryEnvironments [ concat $pEnv $args ]
    eval {Scs_HisConnect $pEnv $pServer} $args
}
proc His::Disconnect { {pResetOptProxyOnly False} } {
    Scs_HisDisconnect $pResetOptProxyOnly
}

proc His::GetContextId { pArchiveName pDate pCallback {pEnvironment ""} } {
    variable secondaryEnvironments
    if { $pEnvironment == "" } {
	set lockId 0
    } else {
	set lockId [ lsearch $secondaryEnvironments $pEnvironment]
	if { $lockId == -1 } {
	    error "Bad environment name $pEnvironment."
	    return
	}
    }
    Scs_HisGetContextId $pArchiveName $pDate $pCallback $lockId $Scs::CurrentGraphicPath
}

proc His::UnlockContext {pLockId} {
    Scs_HisUnlockContext $pLockId
}

proc His::SaveArchive { pArchiveName pStartDate pEndDate pPath pCallback } {
    Scs_HisSaveArchive $pArchiveName $pStartDate $pEndDate $pPath $pCallback $Scs::CurrentGraphicPath
}

proc His::LoadArchive { pArchiveName pPath pEnvironment pCallback } {
    variable secondaryEnvironments
    set lockId [ lsearch $secondaryEnvironments $pEnvironment ]
    if { $lockId != -1 } {
	Scs_HisLoadArchive $pArchiveName $pPath $lockId $pCallback $Scs::CurrentGraphicPath
    } else {
	error "Bad environment name $pEnvironment."
    }
}

proc His::UnloadArchive { pEnvironment } {
    variable secondaryEnvironments
    set lockId [ lsearch $secondaryEnvironments $pEnvironment ]
    if { $lockId != -1 } {
	Scs_HisUnloadArchive $lockId
    } else {
	error "Bad environment name $pEnvironment."
    }
}

proc His::ReadArchiveEventList { pArchiveName pStartDate pEndDate pLockId pCallback } {
    Scs_HisReadArchiveEventList $pArchiveName $pStartDate $pEndDate $pLockId $pCallback $Scs::CurrentGraphicPath
}

proc His::UnReadArchiveEventList { pArchiveName pStartDate pEndDate } {
    Scs_HisUnReadArchiveEventList $pArchiveName $pStartDate $pEndDate $Scs::CurrentGraphicPath
}

proc His::SnapshotArchive { pArchiveName pDate pPath pCallback {pEnvironment ""} } {
    variable secondaryEnvironments
    if { $pEnvironment == "" } {
	set lockId 0
    } else {
	set lockId [ lsearch $secondaryEnvironments $pEnvironment]
	if { $lockId == -1 } {
	    error "Bad environment name $pEnvironment."
	    return
	}
    }
    Scs_HisSnapshotArchive $pArchiveName $pDate $pPath $pCallback $lockId $Scs::CurrentGraphicPath
}
