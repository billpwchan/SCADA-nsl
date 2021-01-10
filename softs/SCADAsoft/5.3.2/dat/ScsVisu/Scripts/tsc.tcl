
###############################
#
# ----- Namespace
#
###############################

namespace eval Tsc { }


###############################
#
# ---- Procedures
#
###############################


proc Tsc::Connect { pEnv { pServer "TscServer" } } {
    Scs_TscConnect $pEnv $pServer
}

proc Tsc::Disconnect { } {
    Scs_TscDisconnect 
}

proc Tsc::GetDayGroupNamesAndIds { } {
    Scs_TscGetDayGroupNamesAndIds
}

proc Tsc::GetDates { daygroupId } {
    Scs_TscGetDates $daygroupId
}

proc Tsc::SetDates { daygroupId datesList } {
    Scs_TscSetDates $daygroupId $datesList
}

proc Tsc::GetTaskNames { } {
    Scs_TscGetTaskNames
}

proc Tsc::AddTask { taskName {taskDescription ""} {command ""} {type ""} {argument ""} {startTime "*"} {endTime "*"} {interval 0} {filter "* * * * * *"} {inhibited 0} {log 0} {removeAtEnd 0} {source ""} } {
  if { $type == "" } {
# If the small API is used, taskdescription contains the source parameter
    Scs_TscAddTask $taskName $taskDescription
  } else {
    Scs_TscAddTask $taskName $taskDescription $command $type $argument $startTime $endTime $interval $filter $inhibited $log $removeAtEnd $source
  }
}

proc Tsc::RemoveTask { taskName {source ""} } {
    Scs_TscRemoveTask $taskName $source
}

proc Tsc::DisableTask { taskName {source ""} } {
    Scs_TscDisableTask $taskName $source
}

proc Tsc::EnableTask { taskName {source ""} } {
    Scs_TscEnableTask $taskName $source
}

proc Tsc::IsEnabled { taskName } {
    Scs_TscIsEnabled $taskName
}

proc Tsc::SetInterval { taskName interval {source ""} } {
    Scs_TscSetInterval $taskName $interval $source
}

proc Tsc::GetInterval { taskName } {
    Scs_TscGetInterval $taskName
}

proc Tsc::SetFilter { taskName filterString {source ""} } {
    Scs_TscSetFilter $taskName $filterString $source
}

proc Tsc::GetFilter { taskName } {
    Scs_TscGetFilter $taskName
}

proc Tsc::SetArguments { taskName arguments {argType ""} {source ""} } {
    Scs_TscSetArguments $taskName $arguments $argType $source
}

proc Tsc::GetArguments { taskName {argType ""} } {
    Scs_TscGetArguments $taskName $argType
}

proc Tsc::SetEndTime { taskName endTime {source ""} } {
    Scs_TscSetEndTime $taskName $endTime $source
}

proc Tsc::SetStartTime { taskName startTime {source ""} } {
    Scs_TscSetStartTime $taskName $startTime $source
}

proc Tsc::GetEndTime { taskName } {
    Scs_TscGetEndTime $taskName
}

proc Tsc::GetStartTime { taskName } {
    Scs_TscGetStartTime $taskName
}

proc Tsc::GetCommand { taskName } {
    Scs_TscGetCommand $taskName
}

proc Tsc::SetCommand { taskName command {source ""} } {
    Scs_TscSetCommand $taskName $command $source
}

proc Tsc::GetDescription { taskName } {
    Scs_TscGetDescription $taskName
}

proc Tsc::SetDescription { taskName description {source ""} } {
    Scs_TscSetDescription $taskName $description $source
}

proc Tsc::GetTaskType { taskName } {
    Scs_TscGetTaskType $taskName
}

proc Tsc::GetLog { taskName } {
    Scs_TscGetLog $taskName
}

proc Tsc::GetRemoveAtEnd { taskName } {
    Scs_TscGetRemoveAtEnd $taskName
}
