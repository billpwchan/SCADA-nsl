#############################################
#
# ---- Name Space
#
#############################################

namespace eval List { }

#############################################
#
# ---- List
#
#############################################

proc List::NewDataList { pFileName { pWithCounters "True" } { remoteNames "" } { userId "" } { dataListName "" } } {
    Scs_DataList $pFileName $pWithCounters $remoteNames $userId $dataListName
}

proc List::NewDisplayList { pFileName { pGraphicPath "" } { dataListName "" } } {
    Scs_DisplayList $pFileName $pGraphicPath $dataListName
}

proc List::DeleteDisplayList { pFileName { pGraphicPath "" } } {
    Scs_DeleteDisplayList $pFileName $pGraphicPath
}

proc List::DeleteDataList { listName { dataListName "" } } {
    Scs_DeleteDataList $listName $dataListName
}

proc List::ReadDataList { listName { filter  "" } { field  "" } { dataListName "" } { group 0 } } {
    if { [catch { set result1 [Scs_ReadDataList $listName $filter $field $dataListName $group] } message] } {
	return $message
    }
    return $result1
}

proc List::GetValueByKey { listName key field { dataListName "" } } {
    return [Scs_GetValueByKey $listName $key $field $dataListName]
}

proc List::GetValueByIndex { listName index field { dataListName "" } } {
    return [Scs_GetValueByIndex $listName $index $field $dataListName]
}

proc List::DumpList { GraphicPath Path File MaxLineSize ColFeatures { VisibleOnly "0" } { DumpTitle "1" } { DumpMultiLineTitle "0" } { InsertSeparator "" } } {
    Scs_DumpList $GraphicPath $Path $File $MaxLineSize $ColFeatures $VisibleOnly $DumpTitle $DumpMultiLineTitle $InsertSeparator
}

proc List::SetUserId { listName userId } {
    set resultSetUserId ""
    set resultSetUserId [ catch { Scs_SetUserId $listName $userId } message ]
    if { $resultSetUserId } {
	puts $message
    }
    return $resultSetUserId
}

proc List::UnSetUserId { listName } {
    set resultUnSetUserId ""
    set resultUnSetUserId [ catch { Scs_UnSetUserId $listName } message ]
    if { $resultUnSetUserId } {
	puts $message
    }
    return $resultUnSetUserId
}

proc List::GetUserVisibilityRank { listName } {
    set resultGetUserVisibilityRank ""
    set resultGetUserVisibilityRank [ catch { Scs_GetUserVisibilityRank $listName } message ]
    if ($resultGetUserVisibilityRank) {
	puts $message
	return ($resultGetUserVisibilityRank)
    }
    
    return $message
}

proc List::CreateUserAlarmDI { listName scsAddress limits limitsSize {valueAutomatonName ""} {ackAutomatonName ""} userId  {env ""} } {
    set resultCreateUserAlarmDI ""
    set resultCreateUserAlarmDI [ catch { Scs_CreateUserAlarmDI $listName $scsAddress $limits $limitsSize $valueAutomatonName $ackAutomatonName $userId $env } message ]
    return $message
}

proc List::CreateUserAlarmAI { listName scsAddress limits limitsSize {valueAutomatonName ""} {ackAutomatonName ""} userId {env ""} } {
    set resultCreateUserAlarmAI ""
    set resultCreateUserAlarmAI [ catch { Scs_CreateUserAlarmAI $listName $scsAddress $limits $limitsSize $valueAutomatonName $ackAutomatonName $userId $env } message ]
    return $message
}

proc List::DeleteUserAlarm { listName scsAddress userId {env ""} } {
    set resultDeleteUserAlarm ""
    set resultDeleteUserAlarm [ catch { Scs_DeleteUserAlarm $listName $scsAddress $userId $env } message ]
    if { $resultDeleteUserAlarm } {
	puts $message
    }
    return $resultDeleteUserAlarm
}

proc List::NewListCounter { listName counterName clientFilter callbackName {userId "-1"}} {
    Scs_NewListCounter $listName $counterName $clientFilter $callbackName $userId
}

proc List::DeleteListCounter { counterName } {
	Scs_DeleteListCounter $counterName
}

proc List::SetClientFilterListCounter { counterName newFilter } {
	Scs_SetClientFilterListCounter $counterName $newFilter
}

proc List::ResetNewToAckAlarmsListCounter { counterName } {
	Scs_ResetNewToAckAlarmsListCounter $counterName
}

proc List::GetNbAlarmsBySeverity { counterName } {
	return [Scs_GetNbAlarmsBySeverityListCounter $counterName]
}

proc List::GetNbUnAckAlarmsBySeverity { counterName } {
	return [Scs_GetNbUnAckAlarmsBySeverityListCounter $counterName]
}

proc List::GetNbNewUnAckAlarmsBySeverity { counterName } {
	return [Scs_GetNbNewUnAckAlarmsBySeverityListCounter $counterName]
}

proc List::GetNbAlarms { counterName } {
	return [Scs_GetNbAlarmsListCounter $counterName]
}

proc List::GetNbUnAckAlarms { counterName } {
	return [Scs_GetNbUnAckAlarmsListCounter $counterName]
}

proc List::GetNbNewUnAckAlarms { counterName } {
	return [Scs_GetNbNewUnAckAlarmsListCounter $counterName]
}

proc List::DecrementNewUnAckAlarms { counterName DecrArgs } {
	Scs_DecrementNewUnAckAlarmsListCounter $counterName $DecrArgs
}

proc List::GetNbVisibleRows { GraphicPath } {
	Scs_GetNbVisibleRows $GraphicPath
}

proc List::EnsureVisible { GraphicPath Index } {
	Scs_EnsureVisible $GraphicPath $Index
}

proc List::FindNextDisplayedValue { GraphicPath String InternalIndex { ColFeatures "-1"} {CaseCompare "1"} } {
	Scs_FindNextDisplayedValue $GraphicPath $String $InternalIndex $ColFeatures $CaseCompare
}

proc List::FindPreviousDisplayedValue { GraphicPath String InternalIndex { ColFeatures "-1"} {CaseCompare "1"} } {
	Scs_FindPreviousDisplayedValue $GraphicPath $String $InternalIndex $ColFeatures $CaseCompare
}

proc List::GetInternalIndex { GraphicPath Row } {
	Scs_GetInternalIndex $GraphicPath $Row
}

