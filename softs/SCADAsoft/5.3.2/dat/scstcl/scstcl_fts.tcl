################################################################################
#
# Namespace: ScsFts
# Returns:
# Description: Tcl implementation of the Fts Scadasoft component
#
################################################################################
#
# Author: Pascal GEORGET
# Creation: 05/06/2000
# Modification:
#
################################################################################

namespace eval ScsFts {

    namespace export init end;
    namespace export getDirFromEnv getDirFromHost getFileFromEnv getFileFromHost getFilesFromHostSynchro;
    namespace export putDirInEnv putDirInHost putFileInEnv putFileInHost;
    namespace export mkDirInHost deleteFileInHost rmDirInHost listDirInHost listDirInHostSynchro;

################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Fts component
#
################################################################################

   proc init {} {
      ScsTcl_Ftsinit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Fts component
#
################################################################################

   proc end {} {
      ScsTcl_Ftsend
   }

################################################################################
#
# Procedure: getDirFromEnd
# Returns:
# Description: getDirFromEnd Fts implementation
#
################################################################################

    proc getDirFromEnv {EnvName FromPath ToPath Mode DeleteFile {FtsCallback ""}} {
      ScsTcl_FtsgetDirFromEnv $EnvName $FromPath $ToPath $Mode $DeleteFile $FtsCallback
   }

################################################################################
#
# Procedure: getDirFromHost
# Returns:
# Description: getDirFromHost Fts implementation
#
################################################################################

   proc getDirFromHost {HostName FromPath ToPath Mode DeleteFile {FtsCallback ""}} {
      ScsTcl_FtsgetDirFromHost $HostName $FromPath $ToPath $Mode $DeleteFile $FtsCallback
   }

################################################################################
#
# Procedure: getFileFromEnv
# Returns:
# Description: getFileFromEnv Fts implementation
#
################################################################################

   proc getFileFromEnv {EnvName FromPath ToPath Mode DeleteFile {FtsCallback ""}} {
      ScsTcl_FtsgetFileFromEnv $EnvName $FromPath $ToPath $Mode $DeleteFile $FtsCallback
   }

################################################################################
#
# Procedure: getFileFromHost
# Returns:
# Description: getFileFromHost Fts implementation
#
################################################################################

   proc getFileFromHost {HostName FromPath ToPath Mode DeleteFile {FtsCallback ""}} {
      ScsTcl_FtsgetFileFromHost $HostName $FromPath $ToPath $Mode $DeleteFile $FtsCallback
   }

################################################################################
#
# Procedure: getFilesFromHostSynchro
# Returns:
# Description: getFilesFromHostSynchro Fts implementation
#
################################################################################

   proc getFilesFromHostSynchro {HostName FromPath ToPath Mode DeleteFile} {
      ScsTcl_FtsgetFilesFromHostSynchro $HostName $FromPath $ToPath $Mode $DeleteFile
   }

################################################################################
#
# Procedure: putDirInEnd
# Returns:
# Description: putDirInEnd Fts implementation
#
################################################################################

   proc putDirInEnv {EnvName FromPath ToPath Mode DeleteFile {FtsCallback ""}} {
      ScsTcl_FtsputDirInEnv $EnvName $FromPath $ToPath $Mode $DeleteFile $FtsCallback
   }

################################################################################
#
# Procedure: putDirInHost
# Returns:
# Description: putDirInHost Fts implementation
#
################################################################################

   proc putDirInHost {HostName FromPath ToPath Mode DeleteFile {FtsCallback ""}} {
      ScsTcl_FtsputDirInHost $HostName $FromPath $ToPath $Mode $DeleteFile $FtsCallback
   }

################################################################################
#
# Procedure: putFileInEnv
# Returns:
# Description: getFileInEnv Fts implementation
#
################################################################################

   proc putFileInEnv {EnvName FromPath ToPath Mode DeleteFile {FtsCallback ""}} {
      ScsTcl_FtsputFileInEnv $EnvName $FromPath $ToPath $Mode $DeleteFile $FtsCallback
   }

################################################################################
#
# Procedure: putFileInHost
# Returns:
# Description: getFileInHost Fts implementation
#
################################################################################

   proc putFileInHost {HostName FromPath ToPath Mode DeleteFile {FtsCallback ""}} {
      ScsTcl_FtsputFileInHost $HostName $FromPath $ToPath $Mode $DeleteFile $FtsCallback
   }

################################################################################
#
# Procedure: mkDirInHost
# Returns:
# Description: mkDirInHost Fts implementation
#
################################################################################

   proc mkDirInHost {HostName ToPath Mode} {
      ScsTcl_FtsmkDirInHost $HostName $ToPath $Mode
   }

################################################################################
#
# Procedure: deleteFileInHost
# Returns:
# Description: deleteFileInHost Fts implementation
#
################################################################################

   proc deleteFileInHost {HostName ToPath Mode} {
      ScsTcl_FtsdeleteFileInHost $HostName $ToPath $Mode
   }

################################################################################
#
# Procedure: rmDirInHost
# Returns:
# Description: rmDirInHost Fts implementation
#
################################################################################

   proc rmDirInHost {HostName ToPath Mode} {
      ScsTcl_FtsrmDirInHost $HostName $ToPath $Mode
   }

################################################################################
#
# Procedure: listDirInHost
# Returns:
# Description: listDirInHost Fts implementation
#
################################################################################

proc listDirInHost {HostName ToPath Mode FileName {FtsCallback ""}} {
      ScsTcl_FtslistDirInHost $HostName $ToPath $Mode $FileName $FtsCallback
   }

################################################################################
#
# Procedure: listDirInHostSynchro
# Returns:
# Description: listDirInHostSynchro Fts implementation
#
################################################################################

proc listDirInHostSynchro {HostName ToPath Mode FileName} {
      ScsTcl_FtslistDirInHostSynchro $HostName $ToPath $Mode $FileName
   }
}
