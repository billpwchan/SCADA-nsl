###
### DSS commands
###


namespace eval Dss {}


variable Dss::X                     "0"                              ;# popup abscissa
variable Dss::Y                     "0"                              ;# popup ordinate
variable Dss::Delay                 "3"                              ;# popup timeout (seconds)
variable Dss::Transient             ":"                              ;# transient graphic path
variable Dss::ImageRectangle        "Image"                          ;# image name
variable Dss::DbPath                "<alias>dssscenarios:Scenario_"  ;# database address
variable Dss::VirtualEnv            ""                               ;# image database virtual environment

variable Dss::ConflictAnswer        "TimeOut"                        ;# **internal**
variable Dss::TerminateStatus       ""                               ;# **internal**
variable Dss::NewThread             ""                               ;# **internal**
variable Dss::NbScenarios           "1"                              ;# **internal**
variable Dss::Abort                 "0"                              ;# **internal**

variable Dss::EventId               "-1"                             ;# **for client application**
variable Dss::ScenarioId            "-1"                             ;# **for client application**
variable Dss::CurrentState          "Unknown"                        ;# **for client application**
variable Dss::AsynchronousResponse  ""                               ;# **for client application**

# FFT TKE 119
variable Dss::MainWindowGraphicPath ""                               ;# **for client application**
variable Dss::MainWindowNamespace   ""                               ;# **for client application**


proc Dss::RestorePreviousScenario { toBeCleared oldScenarioId oldImage } {
    set env "default"
    set tmp "Panel::SetImage ${Dss::Transient}:${Dss::ImageRectangle} Dss/${oldImage} $env"
    Dss::PostEvent $tmp
    set tmp "Animator::Fit ${Dss::Transient}:${Dss::ImageRectangle}"
    Dss::PostEvent $tmp
    set tmp "Database::Connect ${Dss::Transient}:${Dss::ImageRectangle} ${Dss::DbPath}${oldScenarioId} $Dss::VirtualEnv"
    Dss::PostEvent $tmp
    incr Dss::NbScenarios -1
}

proc Dss::CreateSubScenario { masterId newImage callstepNodeId } {
    set slaveId "-1"
    if { [catch { Scs_DssCreateSubScenario $masterId $callstepNodeId } tmp] == "0" } {
        incr Dss::NbScenarios
        set slaveId $tmp
        set env "default"
        set tmp "Panel::SetImage ${Dss::Transient}:${Dss::ImageRectangle} Dss/${newImage} $env"
        Dss::PostEvent $tmp
        set tmp "Animator::Fit ${Dss::Transient}:${Dss::ImageRectangle}"
        Dss::PostEvent $tmp
        set tmp "Database::Connect ${Dss::Transient}:${Dss::ImageRectangle} ${Dss::DbPath}${slaveId} $Dss::VirtualEnv"
        Dss::PostEvent $tmp
    }
    return $slaveId
}

proc Dss::SetResult { scenarioId { value "" } } {
    Scs_DssSetResult $scenarioId $value
}

proc Dss::GetResult { scenarioId } {
    if { [catch { Scs_DssGetResult $scenarioId } value] == 0 } {
        return $value
    }
    return ""
}

proc Dss::ReadAbort { } {
    return $Dss::Abort
}

# For threads coms only
proc Dss::SynchronousReading { command } {
    return [Scs_DssPostEvent $Dss::Transient $command "WaitForResult"]
}

# For threads coms only
proc Dss::PostEvent { command } {
    Scs_DssPostEvent $Dss::Transient $command "DoNotWait"
}

# For HMI only
proc Dss::ShowQuestion { { Force "0" } } {
    Panel::NewPanel "Question" "Dss/DssQuestion" { WS_NoResizeBorder WS_NoSystemMenu } . $Force
    Panel::Show Question Normal 0
}

# For HMI only
proc Dss::AskConfirmation { { Restricted "0" } } {
    Panel::NewPanel "Conflict" "Dss/DssAsk" { WS_NoResizeBorder WS_NoSystemMenu } . $Restricted
    Panel::Show Conflict Normal $Dss::Delay
}

proc Dss::Connect { env { name "DssServer" } } {
    Scs_DssConnect $env $name
}

proc Dss::Disconnect { } {
    Scs_DssDisconnect
}

proc Dss::SetVariable { scenarioId varId varValue } {
    Scs_SetVariable $scenarioId $varId $varValue
}

proc Dss::AfterNode { scenarioId oldNodeId outputLinkId newNodeId } {
    Scs_AfterNode $scenarioId $oldNodeId $outputLinkId $newNodeId
}

proc Dss::BeforeNode { scenarioId inputLinkId nodeId } {
    Scs_BeforeNode $scenarioId $inputLinkId $nodeId
}

proc Dss::ForceLink { scenarioId oldNodeId linkId } {
    Scs_ForceLink $scenarioId $oldNodeId $linkId
}

proc Dss::CancelForcing { scenarioId conflictingLinkId } {
    Scs_CancelForcing $scenarioId $conflictingLinkId
}

proc Dss::AcceptForcing { scenarioId linkId otherLinkId } {
    Scs_AcceptForcing $scenarioId $linkId $otherLinkId
}

proc Dss::ChangeMode { scenarioId newMode } {
    set mode 2
    if { $newMode != "Manual" } {
        set mode 0
    }
    Scs_ChangeMode $scenarioId $mode
}

proc Dss::NodeError { scenarioId nodeId } {
    Scs_NodeError $scenarioId $nodeId
}

proc Dss::CreateScenario { scenarioName  eventId  mode argName  } {
    set Dss::NbScenarios "1"
    Scs_CreateScenario $scenarioName $eventId $mode $argName
}

proc Dss::CreateVirtualScenario { scenarioName eventType eqpName  mode argName } {
    set Dss::NbScenarios "1"
    Scs_CreateVirtualScenario $scenarioName $eventType $eqpName $mode $argName
}

proc Dss::CreateEvent { scenarioId eventType } {
    Scs_CreateEvent $scenarioId $eventType
}

proc Dss::RemoveEvent { eventDssId } {
    Scs_RemoveEvent $eventDssId
}

proc Dss::Success { scenarioId } {
    Dss::UnlockScenario $scenarioId
    Scs_Success $scenarioId
    if { $Dss::NbScenarios == 1 } {
        Dss::PostEvent { Panel::NewPanel Message "dss/DssMessage" {WS_NoSystemMenu WS_NoResizeBorder} $Dss::Transient { "Info" "End of scenario" $Dss::X $Dss::Y "  Scenario successfully completed." } }
        set Dss::NewThread ""
        Threads exit
    }
}

proc Dss::Cancel { scenarioId } {
    Dss::PostEvent { Panel::NewPanel Message "dss/DssMessage" {WS_NoSystemMenu WS_NoResizeBorder} $Dss::Transient { "Warning" "End of scenario" $Dss::X $Dss::Y "  Scenario aborted by user." } }
    Dss::UnlockScenario $scenarioId
    Scs_Cancel $scenarioId
    set Dss::NewThread ""
    Threads exit
}

proc Dss::Failure { scenarioId } {
    Dss::PostEvent { Panel::NewPanel Message "dss/DssMessage" {WS_NoSystemMenu WS_NoResizeBorder} $Dss::Transient { "Error" "End of scenario" $Dss::X $Dss::Y "  Scenario failed." } }
    Dss::UnlockScenario $scenarioId
    Scs_Failure $scenarioId
    set Dss::NewThread ""
    Threads exit
}

proc Dss::GetApplicableScenarios { { eventType  "" } } {
    Scs_GetProcedures $eventType
}

proc Dss::LockScenario { scenarioId ownerId } {
    Scs_LockScenario $scenarioId $ownerId
}

proc Dss::UnlockScenario { scenarioId } {
    Scs_UnlockScenario $scenarioId
}

proc Dss::InitModes { scenarioId nodeModes } {
    Scs_InitModes $scenarioId $nodeModes
}

proc Dss::Clear { scenarioId { clearAll "0" } } {
    Scs_Clear $scenarioId $clearAll
}

proc Dss::GetEventTypeList { } {
    Scs_GetEventTypeList
}

proc Dss::GetCurrentState { scenarioId } {
    Scs_GetCurrentSate $scenarioId
}

proc Dss::GetEventId { scenarioId } {
    Scs_GetEventId $scenarioId
}

proc Dss::SetCallstepNodeId { subScenarioId callstepNodeId } {
    Scs_SetCallstepNodeId $subScenarioId $callstepNodeId
}

proc Dss::GetOldSubScenarioId { parentScenarioId callstepNodeId } {
    Scs_GetOldSubScenarioId $parentScenarioId $callstepNodeId
}

proc Dss::SetCallstepNodeId { subScenarioId callstepNodeId } {
    Scs_SetCallstepNodeId $subScenarioId $callstepNodeId
}
