#####################################
#
# ---- List Server Instructions
#
#####################################

namespace eval Lst {}

#
# ---- Instructions
#
#

proc Lst::Activate { pListName { ServerName ""}  } {
    Scs_LstActivate $pListName $ServerName
}

proc Lst::Deactivate { pListName { ServerName ""}  } {
    Scs_LstDeactivate $pListName $ServerName
}

proc Lst::IsActivated { pListName { ServerName ""}  } {
    Scs_LstIsActivated $pListName $ServerName
}

proc Lst::GetListCreationPercentage { pListName { ServerName ""}  } {
    Scs_LstGetListCreationPercentage $pListName $ServerName
}

proc Lst::GetMode { pListName { ServerName ""}  } {
    Scs_LstGetMode $pListName $ServerName
}

proc Lst::GetCreator { pListName { ServerName ""}  } {
    Scs_LstGetCreator $pListName $ServerName
}

proc Lst::GetComment { pListName { ServerName ""}  } {
    Scs_LstGetComment $pListName $ServerName
}

proc Lst::Save { pListName pCreatorId  { ServerName ""}  } {
    Scs_LstSave $pListName $pCreatorId $ServerName
}

proc Lst::DeleteStateList { pListName pCreatorId  { ServerName ""}  } {
    Scs_LstDeleteStateList $pListName $pCreatorId $ServerName
}

proc Lst::DeleteUserList { pListName pCreatorId  { ServerName ""}  } {
    Scs_LstDeleteUserList $pListName $pCreatorId $ServerName
}

proc Lst::CreateStateList { pListName pCreatorId pDescription pAttributes pConditionClause pComment  { ServerName ""}  } {
    Scs_LstCreateStateList $pListName $pCreatorId $pDescription $pAttributes $pConditionClause $pComment $ServerName
}

proc Lst::CreateStateListWithNotification { pListName pCreatorId pDescription pAttributes pConditionClause pComment pCallback  { ServerName ""} } {
    Scs_LstCreateStateListWithNotification $pListName $pCreatorId $pDescription $pAttributes $pConditionClause $pComment $pCallback $Scs::CurrentGraphicPath $ServerName
}

proc Lst::ModifyStateListCondition { pListName pCreatorId pConditionClause  { ServerName ""}  } {
    Scs_LstModifyStateListCondition $pListName $pCreatorId $pConditionClause $ServerName
}

proc Lst::ModifyStateList { pListName pCreatorId pDescription pAttributes pConditionClause pComment  { ServerName ""}  } {
    Scs_LstModifyStateList $pListName $pCreatorId $pDescription $pAttributes $pConditionClause $pComment $ServerName
}

proc Lst::CreateUserList { pListName pCreatorId pDescription  { ServerName ""}  } {
    Scs_LstCreateUserList $pListName $pCreatorId $pDescription $ServerName
}

proc Lst::AddUserListEntry { pListName pCreatorId pAddresses  { ServerName ""}  } {
    Scs_LstAddUserListEntry $pListName $pCreatorId $pAddresses $ServerName
}

proc Lst::DeleteUserListEntry { pListName pCreatorId pIndex { ServerName ""}} {
    Scs_LstDeleteUserListEntry $pListName $pCreatorId $pIndex $ServerName
}


proc Lst::CreateMultiStateList { pListName pCreatorId pDescription  pAttributes pConditionClauses pComments { pColumnNames "" }  { ServerName ""}  } {
    Scs_LstCreateMultiStateList $pListName $pCreatorId $pDescription $pAttributes $pConditionClauses $pComments $pColumnNames $ServerName
}

proc Lst::CreateMultiStateListWithNotification { pListName pCreatorId pDescription  pAttributes pConditionClauses pComments { pColumnNames "" } pCallback  { ServerName ""}  } {
    Scs_LstCreateMultiStateListWithNotification $pListName $pCreatorId $pDescription $pAttributes $pConditionClauses $pComments $pColumnNames $pCallback $Scs::CurrentGraphicPath $ServerName
}

proc Lst::GetDescription { pListName  { ServerName ""}  } {
    Scs_LstGetDescription $pListName $ServerName
}

proc Lst::SetDescription { pListName pCreatorId pDescription  { ServerName ""}  } {
    Scs_LstSetDescription $pListName $pCreatorId $pDescription $ServerName
}

proc Lst::Connect { pLogicalEnv pServerName } {
    Scs_LstConnect $pLogicalEnv $pServerName
}

proc Lst::Disconnect {  { ServerName ""}  } {
    Scs_LstDisconnect $ServerName
}

proc Lst::ListLists {  { ServerName ""}  } {
   Scs_LstListLists $ServerName
}

proc Lst::GetInfo { pListName  { ServerName ""}  } {
   Scs_LstGetInfo $pListName $ServerName
}
