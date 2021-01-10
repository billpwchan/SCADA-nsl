################################################################################
#
# Namespace: ScsHis
# Returns:
# Description: Tcl implementation of the His Scadasoft component
#
################################################################################
#
# Author: Pascal GEORGET
# Creation: 05/06/2001
# Modification:
#
################################################################################

namespace eval ScsHis {

    namespace export init end;
    namespace export getAttributeNames getArchiveNames;
   
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the His component
#
################################################################################

   proc init {} {
      ScsTcl_Hisinit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the His component
#
################################################################################

   proc end {} {
      ScsTcl_Hisend
   }

################################################################################
#
# Procedure: getArchiveNames
# Returns:
# Description: getArchiveNames His implementation
#
################################################################################

    proc getArchiveNames {EnvName} {
      ScsTcl_HisgetArchName $EnvName
    }

################################################################################
#
# Procedure: getAttributeNames
# Returns:
# Description: getAttributeNames His implementation
#
################################################################################

    proc getAttributeNames {EnvName ArchiveName} {
      ScsTcl_HisgetAttName $EnvName $ArchiveName
   }
}
