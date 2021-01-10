################################################################################
#
# Namespace: ScsOls
# Returns:
# Description: Tcl implementation of the Replay Scadasoft component
#
################################################################################
#
# Author: Jerome MARTINET
# Creation: 15/11/2004
# Modification:
#
################################################################################

namespace eval ScsOls {

   namespace export init end;
   namespace export insertData updateData deleteData readData;
   
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Ols component
#
################################################################################

   proc init {} {
      ScsTcl_Olsinit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Ols component
#
################################################################################

   proc end {} {
      ScsTcl_Olsend
   }
   
################################################################################
#
# Procedure: insertData
# Returns:
# Description: insert an OlsData in a datalist
#
################################################################################

   proc insertData {pEnvName pServerName pListName pOlsDataList } {
      global SCSOLS_CREATION
      ScsTcl_OlsModifyData $pEnvName $pServerName $pListName $SCSOLS_CREATION $pOlsDataList
   }
   
################################################################################
#
# Procedure: updateData
# Returns:
# Description: update an OlsData in a datalist
#
################################################################################

   proc updateData {pEnvName pServerName pListName pOlsDataList } {
      global SCSOLS_UPDATE
      ScsTcl_OlsModifyData $pEnvName $pServerName $pListName $SCSOLS_UPDATE $pOlsDataList
   }

################################################################################
#
# Procedure: deleteData
# Returns:
# Description: delete an OlsData in a datalist
#
################################################################################

   proc deleteData {pEnvName pServerName pListName pKeyList } {
      ScsTcl_OlsDeleteData $pEnvName $pServerName $pListName $pKeyList
   }
   
################################################################################
#
# Procedure: readData
# Returns:
# Description: read OlsData in a datalist
#
################################################################################
   
   proc readData {pEnvName pServerName pListName { pColumnsList {} } {pFilter ""} {group 0} } {
       set result1 [ScsTcl_OlsReadData $pEnvName $pServerName $pListName $pColumnsList $pFilter $group]
       return $result1
   }
   
}
