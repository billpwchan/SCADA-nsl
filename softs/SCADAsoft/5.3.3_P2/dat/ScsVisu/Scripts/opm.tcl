###############################
#
# ----- Namespace
#
###############################
namespace eval Opm { }


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

proc Opm::Connect { pEnv pServer } {
        Scs_OpmConnect $pEnv $pServer
}

proc Opm::Disconnect { } {
        Scs_OpmDisconnect 
}

proc Opm::Load { profile } {
        Scs_OpmLoad $profile
}

proc Opm::Unload { profile } {
        Scs_OpmUnload $profile
}

proc Opm::IsLoaded { profile } {
        Scs_OpmIsLoaded $profile
}

proc Opm::GetNames { type } {
        Scs_OpmGetNames $type
}

proc Opm::GetAttribute { type name attributeName } {
        Scs_OpmGetAttribute $type $name $attributeName
}

proc Opm::SetOperatorAttribute { name attr value } {
        Scs_OpmSetOperatorAttribute $name $attr $value
}

proc Opm::Subscribe { profile callback } {
        Scs_OpmSubscribe $Scs::CurrentGraphicPath $profile $callback
}

proc Opm::Unsubscribe { profile } {
        Scs_OpmUnsubscribe $profile 
}

proc Opm::Restore { type } {
        Scs_OpmRestore $type
}

proc Opm::SetMaskMode { maskMode } {
        Scs_OpmSetMaskMode $maskMode
}

proc Opm::SetMask { profile location function mode mask } {
        Scs_OpmSetMask $profile $location $function $mode $mask
}

proc Opm::SetLocalMask { profile location function mode mask } {
        Scs_OpmSetLocalMask $profile $location $function $mode $mask
}

proc Opm::SaveProfiles { } {
        Scs_OpmSaveProfiles 
}

proc Opm::GetMask { profile location function } {
        Scs_OpmGetMask $profile $location $function
}

proc Opm::CheckAccess { profile location function reqmask } {
        Scs_OpmCheckAccess $profile $location $function $reqmask
}

proc Opm::GetMasks {} {
    Scs_OpmGetMasks
}

proc Opm::ChangePassword { operator oldPassword newPassword } {
    Scs_OpmChangePassword $operator $newPassword $oldPassword ""
}

proc Opm::ForceChangePassword { operator newPassword } {
    Scs_OpmForceChangePassword $operator $newPassword
}

proc Opm::IsPasswordValid { operator password } {
    Scs_OpmIsPasswordValid $operator $password
}

proc Opm::IsPasswordExpired { operator } {
    Scs_OpmIsPasswordExpired $operator 
}

proc Opm::CreateOperator { operator } {
    Scs_OpmCreateOperator $operator
}
proc Opm::RemoveOperator { operator } {
    Scs_OpmRemoveOperator $operator
}
proc Opm::AddOperatorProfile { operator profile } {
    Scs_OpmAddOperatorProfile $operator $profile
}
proc Opm::RemoveOperatorProfile { operator profile } {
    Scs_OpmRemoveOperatorProfile $operator $profile
}
