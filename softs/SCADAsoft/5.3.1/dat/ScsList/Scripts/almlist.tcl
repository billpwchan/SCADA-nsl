namespace eval ScsAlarmList {}

proc ScsAlarmList::AcknowledgeAll {{Name ""} {graphicPath ""} {userId ""}} {

	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Scsalm_AcknowledgeAll $ListName $graphicPath $userId
}

proc ScsAlarmList::AcknowledgeAlarms { pIdList {Name ""} {graphicPath ""} {userId ""}} {

	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Scsalm_AcknowledgeAlarms $ListName $graphicPath $pIdList $userId
}

proc ScsAlarmList::AcknowledgeSelection {{Name ""} {graphicPath ""} {userId ""}} {

	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Scsalm_AcknowledgeSelection $ListName $graphicPath $userId
}

proc ScsAlarmList::AcknowledgeEquipment {EquipmentName {Name ""} {graphicPath ""} {userId ""}} {

	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Scsalm_AcknowledgeEquipment $EquipmentName $ListName $graphicPath $userId
}

proc ScsAlarmList::GetCount {{Name ""} {graphicPath ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Tcl_ScsGetListCount $ListName $graphicPath
}

proc ScsAlarmList::GetTotalCount {{Name ""} {graphicPath ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Tcl_ScsGetTotalListCount $ListName $graphicPath
}

proc ScsAlarmList::GetToAckCount {{Name ""} {graphicPath ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Tcl_ScsGetUnacknowledgedAlarmListCount $ListName $graphicPath
}

proc ScsAlarmList::GetTotalToAckCount {{Name ""} {graphicPath ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Tcl_ScsGetUnacknowledgedAlarmListTotalCount $ListName $graphicPath
}

proc ScsAlarmList::GetNewToAckCount {{Name ""} {graphicPath ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Tcl_ScsGetNewToAcknowledged $ListName $graphicPath
}

proc ScsAlarmList::GetToAckBySeverity {{Name ""} {graphicPath ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Tcl_ScsGetToAckBySeverity $ListName $graphicPath
}

proc ScsAlarmList::GetCountBySeverity {{Name ""} {graphicPath ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Tcl_ScsGetCountBySeverity $ListName $graphicPath
}

proc ScsAlarmList::GetTotalToAckBySeverity {{Name ""} {graphicPath ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Tcl_ScsGetTotalToAckBySeverity $ListName $graphicPath
}

proc ScsAlarmList::GetNewToAckBySeverity {{Name ""} {graphicPath ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Tcl_ScsGetNewToAckBySeverity $ListName $graphicPath
}

proc ScsAlarmList::GetTotalBySeverity {{Name ""} {graphicPath ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Tcl_ScsGetTotalBySeverity $ListName $graphicPath
}

proc ScsAlarmList::ShelveAll {{Name ""} {graphicPath ""} {userId ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Scsalm_ShelveAll $ListName $graphicPath $userId
}

proc ScsAlarmList::ShelveAlarms { pIdList {Name ""} {graphicPath ""} {userId ""}} {

	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Scsalm_ShelveAlarms $ListName $graphicPath $pIdList $userId
}

proc ScsAlarmList::ShelveSelection {{Name ""} {graphicPath ""} {userId ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Scsalm_ShelveSelection $ListName $graphicPath $userId
}

proc ScsAlarmList::ShelveEquipment {EquipmentName {Name ""} {graphicPath ""} {userId ""}} {
        set ListName ""
        if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Scsalm_ShelveEquipment $EquipmentName $ListName $graphicPath $userId
}

proc ScsAlarmList::UnShelveAll {{Name ""} {graphicPath ""} {userId ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Scsalm_UnShelveAll $ListName $graphicPath $userId
}

proc ScsAlarmList::UnShelveAlarms { pIdList {Name ""} {graphicPath ""} {userId ""}} {

	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Scsalm_UnShelveAlarms $ListName $graphicPath $pIdList $userId
}

proc ScsAlarmList::UnShelveSelection {{Name ""} {graphicPath ""} {userId ""}} {
	set ListName ""
	if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Scsalm_UnShelveSelection $ListName $graphicPath $userId
}

proc ScsAlarmList::UnShelveEquipment {EquipmentName {Name ""} {graphicPath ""} {userId ""}} {
        set ListName ""
        if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Scsalm_UnShelveEquipment $EquipmentName $ListName $graphicPath $userId
}

proc ScsAlarmList::SetUserId {{Name ""} {graphicPath ""} userId} {
    set ListName ""
    
    if [string compare $Name ""] then {
	set ListName $Name
    } else {
	set ListName $Scs::CurrentList
    }
    
    if ![string compare $graphicPath ""] then {
	set graphicPath $Scs::CurrentGraphicPath
    }


    set resultSetUserId ""
    set resultSetUserId [ catch { Scsalm_SetUserId $Name $graphicPath $userId } message ]
    if { $resultSetUserId } {
	puts $message
    }
    return $resultSetUserId
}

proc ScsAlarmList::CreateUserAlarmDI {{Name ""} {graphicPath ""} scsAddress limits limitsSize {valueAutomatonName ""} {ackAutomatonName ""} userId} {
    set ListName ""

    if [string compare $Name ""] then {
	set ListName $Name
    } else {
	set ListName $Scs::CurrentList
    }
    
    if ![string compare $graphicPath ""] then {
	set graphicPath $Scs::CurrentGraphicPath
    }

    set resultCreateUserAlarmDI ""
    set resultCreateUserAlarmDI [ catch { Scsalm_CreateUserAlarmDI $Name $graphicPath $scsAddress $limits $limitsSize $valueAutomatonName $ackAutomatonName $userId } message ]
    return $message
}

proc ScsAlarmList::CreateUserAlarmAI {{Name ""} {graphicPath ""} scsAddress limits limitsSize {valueAutomatonName ""} {ackAutomatonName ""} userId} {
        set ListName ""
        if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    set resultCreateUserAlarmAI ""
    set resultCreateUserAlarmAI [ catch { Scsalm_CreateUserAlarmAI $Name $graphicPath $scsAddress $limits $limitsSize $valueAutomatonName $ackAutomatonName $userId } message ]
    return $message
}

proc ScsAlarmList::DeleteUserAlarm {{Name ""} {graphicPath ""} scsAddress userId} {
        set ListName ""
        if [string compare $Name ""] then {
		set ListName $Name
	} else {
		set ListName $Scs::CurrentList
	}

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    set resultDeleteUserAlarm ""
    set resultDeleteUserAlarm [ catch { Scsalm_DeleteUserAlarm $Name $graphicPath $scsAddress $userId } message ]
    if { $resultDeleteUserAlarm } {
	puts $message
    }
    return $resultDeleteUserAlarm
}

proc ScsAlarmList::GetUserVisibilityRank {{Name ""} {graphicPath ""} userId} {
    set ListName ""
    set userVisibilityRank ""

    if [string compare $Name ""] then {
	set ListName $Name
    } else {
	set ListName $Scs::CurrentList
    }
    
    if ![string compare $graphicPath ""] then {
	set graphicPath $Scs::CurrentGraphicPath
    }
    
    set resultUserVisibilityRank [ catch { Scsalm_GetUserVisibilityRank $Name $graphicPath $userId } userVisibilityRank ]

    return $userVisibilityRank
}

