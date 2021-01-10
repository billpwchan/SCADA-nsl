##############################
#
# ----- Namespace
#
###############################
namespace eval Fts { }


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

proc Fts::Connect { pEnv pServer pCallback } {
        Scs_FtsConnect $pEnv $pServer $pCallback
}

proc Fts::Disconnect { } {
        Scs_FtsDisconnect 
}

proc Fts::ListDirInHost { pHost pPath pFile } {
    Scs_FtsListDirInHost $pHost $pPath $pFile $Scs::CurrentGraphicPath
}

proc Fts::ListDirInHostSynchro { pHost pPath pFile } {
    Scs_FtsListDirInHostSynchro $pHost $pPath $pFile 
}

proc Fts::RmDirInHost { pHost pPath } {
        Scs_FtsRmDirInHost $pHost $pPath
}

proc Fts::MkDirInHost { pHost pPath } {
        Scs_FtsMkDirInHost $pHost $pPath
}

proc Fts::DeleteFileInHost { pHost pPath } {
        Scs_FtsDeleteFileInHost $pHost $pPath 
}

proc Fts::PutFileInHost { pHost pFromPath pToPath pDelete } {
        Scs_FtsPutFileInHost $pHost $pFromPath $pToPath $pDelete $Scs::CurrentGraphicPath
}

proc Fts::GetFileFromHost { pHost pFromPath pToPath pDelete } {
        Scs_FtsGetFileFromHost $pHost $pFromPath $pToPath $pDelete $Scs::CurrentGraphicPath
}

proc Fts::GetFilesFromHostSynchro { pHost pFromPath pToPath pDelete } {
        Scs_FtsGetFilesFromHostSynchro $pHost $pFromPath $pToPath $pDelete 
}

proc Fts::ListDirInEnv { pEnv pPath pFile } {
    Scs_FtsListDirInEnv $pEnv $pPath $pFile $Scs::CurrentGraphicPath
}

proc Fts::ListDirInEnvSynchro { pEnv pPath pFile } {
    Scs_FtsListDirInEnvSynchro $pEnv $pPath $pFile 
}

proc Fts::RmDirInEnv { pEnv pPath } {
        Scs_FtsRmDirInEnv $pEnv $pPath
}

proc Fts::MkDirInEnv { pEnv pPath } {
        Scs_FtsMkDirInEnv $pEnv $pPath
}

proc Fts::DeleteFileInEnv { pEnv pPath } {
        Scs_FtsDeleteFileInEnv $pEnv $pPath 
}

proc Fts::PutFileInEnv { pEnv pFromPath pToPath pDelete } {
        Scs_FtsPutFileInEnv $pEnv $pFromPath $pToPath $pDelete $Scs::CurrentGraphicPath
}

proc Fts::GetFileFromEnv { pEnv pFromPath pToPath pDelete } {
        Scs_FtsGetFileFromEnv $pEnv $pFromPath $pToPath $pDelete $Scs::CurrentGraphicPath
}

proc Fts::GetFilesFromEnvSynchro { pEnv pFromPath pToPath pDelete } {
        Scs_FtsGetFilesFromEnvSynchro $pEnv $pFromPath $pToPath $pDelete 
}

proc Fts::PutFileInHostSynchro { pHost pFromPath pToPath pDelete } {
        Scs_FtsPutFileInHostSynchro $pHost $pFromPath $pToPath $pDelete 
}

proc Fts::PutFileInEnvSynchro { pEnv pFromPath pToPath pDelete } {
        Scs_FtsPutFileInEnvSynchro $pEnv $pFromPath $pToPath $pDelete 
}

proc Fts::PutDirInHostSynchro { pHost pFromPath pToPath pDelete } {
        Scs_FtsPutDirInHostSynchro $pHost $pFromPath $pToPath $pDelete 
}

proc Fts::PutDirInEnvSynchro { pEnv pFromPath pToPath pDelete } {
        Scs_FtsPutDirInEnvSynchro $pEnv $pFromPath $pToPath $pDelete 
}

proc Fts::getDirFromHostSynchro { pHost pFromPath pToPath pDelete } {
        Scs_FtsGetDirFromHostSynchro $pHost $pFromPath $pToPath $pDelete 
}

proc Fts::GetDirFromEnvSynchro { pEnv pFromPath pToPath pDelete } {
        Scs_FtsGetDirFromEnvSynchro $pEnv $pFromPath $pToPath $pDelete 
}

proc Fts::GetDirFromOnlineSynchro { pEnv pFromPath pToPath pDelete } {
        Scs_FtsGetDirFromOnlineSynchro $pEnv $pFromPath $pToPath $pDelete
}

proc Fts::GetFilesFromOnlineSynchro { pEnv pFromPath pToPath pDelete } {
        Scs_FtsGetFilesFromOnlineSynchro $pEnv $pFromPath $pToPath $pDelete
}

proc Fts::ListDirInOnlineSynchro { pEnv pPath pFile } {
        Scs_FtsListDirInOnlineSynchro $pEnv $pPath $pFile
}

proc Fts::ListDirInOnline { pEnv pPath pFile } {
        Scs_FtsListDirInOnline $pEnv $pPath $pFile $Scs::CurrentGraphicPath
}

proc Fts::GetFileFromOnline { pEnv pFromPath pToPath pDelete } {
        Scs_FtsGetFileFromOnline $pEnv $pFromPath $pToPath $pDelete $Scs::CurrentGraphicPath
}
