#####################################
#
# ---- Database Instructions
#
#####################################

namespace eval Database {}

#
# ---- Instructions
#
#

proc Database::WriteInteger { pValue pAddress { pEnv "" } } {
    Scs_WriteValue ScsINTEGER $pValue $pAddress $pEnv
}

proc Database::WriteFloat { pValue pAddress { pEnv "" } } {
    Scs_WriteValue ScsFLOAT $pValue $pAddress $pEnv
}

proc Database::WriteString { pValue pAddress { pEnv "" } } {
    Scs_WriteValue ScsSTRING $pValue $pAddress $pEnv
}

proc Database::WriteTime { pValue pAddress { pEnv "" } } {
    Scs_WriteValue ScsTIME $pValue $pAddress $pEnv
}

proc Database::WriteReference { pValue pAddress { pEnv "" } } {
    Scs_WriteValue ScsTIME $pValue $pAddress $pEnv
}

proc Database::MultiWriteValue { pAddresses { pEnv "" } } {
    Scs_MultiWriteValue $pAddresses $pEnv
}

proc Database::ReadValue { pAddress { pEnv "" } { pUserContext 0 } } {
    Scs_ReadValue $pAddress $pEnv $pUserContext
}

proc Database::MultiReadValue { pAddresses { pEnv "" } { pUserContext 0 } } {
    Scs_MultiReadValue $pAddresses $pEnv $pUserContext
}

proc Database::GetDatabasePath { pGraphicPath } {
    Scs_GetDBPath $pGraphicPath
}

proc Database::GetDatabaseType { pGraphicPath } {
    Scs_GetDBType $pGraphicPath
}

proc Database::Write { pGraphicPath { pEnv "" } } {
    set DBPath [ Database::GetDatabasePath $pGraphicPath ]
    set DBType [ Database::GetDatabaseType $pGraphicPath ]
    set Value [ ScsGet $pGraphicPath ]

    Scs_WriteValue $DBType $Value $DBPath $pEnv
}

proc Database::Connect { { pGraphicPath "" } { pAddress "" } { pEnv "" } { numContext "" } { deleteGroup "False" } } {
    Scs_Connect $pGraphicPath $pAddress $pEnv $numContext $deleteGroup
}

proc Database::Reconnect { { pGraphicPath "" } { pEnv ""} numContext } {
    Scs_Reconnect $pGraphicPath $pEnv $numContext
}

proc Database::MapEnvironments { args } {
    eval Scs_MapEnvironments $args
}
proc Database::GetStateEnvironment { args } {
    eval Scs_GetStateEnvironment $args
}

proc Database::Refresh { {pGraphicPath "" } } {
    Scs_DbRefresh $pGraphicPath
}

proc Database::Subscribe { pName pCallback args } {
    eval {Scs_PollerSubscribe $Scs::CurrentGraphicPath $pName $pCallback} $args
}

proc Database::SubscribeToContext { pName pContextId pCallback args } {
    eval {Scs_PollerSubscribeToContext $Scs::CurrentGraphicPath $pName $pContextId $pCallback} $args
}

proc Database::SubscribeFromFile { pName pCallback pFile { pEnv "" } } {
    Scs_PollerSubscribeFromFile $Scs::CurrentGraphicPath $pName $pCallback $pFile $pEnv
}

proc Database::SubscribeToContextFromFile { pName pContextId pCallback pFile { pEnv "" } } {
    Scs_PollerSubscribeToContextFromFile $Scs::CurrentGraphicPath $pName $pContextId $pCallback $pFile $pEnv
}

proc Database::UnSubscribe { pName { pEnv "" } } {
    Scs_PollerUnSubscribe $pName $pEnv
}

proc Database::UnSubscribeToContext { pName pContextId { pEnv "" } } {
    Scs_PollerUnSubscribeToContext $pName $pContextId $pEnv
}

proc Database::ForceSnapshot { { pType "Binary" } { pPath "" } { pEnv "" } } {
    Scs_ForceSnapshot $pType $pPath $pEnv
}

proc Database::GetInstancesWithClassId {classId { pEnv "" } { subTree "" } } {
   Scs_GetInstances I $classId $pEnv $subTree
}

proc Database::GetInstancesWithClassName {className { pEnv "" } { subTree "" } } {
   Scs_GetInstances N $className $pEnv $subTree
}

proc Database::GetClassName {address { pEnv "" } } {
   Scs_GetClassName $address $pEnv
}

# Evolution 05/03/02 YLO
proc Database::ReadVector { pAddress { pEnv "" } { pUserContext 0 } } {
    Scs_ReadAttribute ScsVECTOR $pAddress $pEnv $pUserContext
}

proc Database::ReadTable { pAddress { pEnv "" } { pUserContext 0 } } {
    Scs_ReadAttribute ScsTABLE $pAddress $pEnv $pUserContext
}

proc Database::WriteVector { pType pValue pAddress { pEnv "" } } {
    Scs_WriteAttribute $pType $pValue $pAddress $pEnv
}

proc Database::WriteTable { pType pValue pAddress { pEnv "" } } {
    Scs_WriteAttribute $pType $pValue $pAddress $pEnv
}

proc Database::GetChildrenAliases { pAddress { pEnv "" } } {
    Scs_GetChildrenAliases $pAddress $pEnv
}

proc Database::GetChildrenNames { pAddress { pEnv "" } } {
    Scs_GetChildrenNames $pAddress $pEnv
}

proc Database::SetAttributeFormula { pAddress NewFormula { pEnv "" } } {
    Scs_SetAttributeFormula $pAddress $NewFormula $pEnv
}

proc Database::DeleteGroup { GroupName { Env "" } } {
    Scs_DeleteGroup $GroupName $Env
}

proc Database::GetFullPath { pAlias { pEnv "" } } {
    Scs_GetFullPath $pAlias $pEnv
}

proc Database::CEControl { CEs { pEnv "" } } {
    Scs_ControlCE $CEs $pEnv
}

