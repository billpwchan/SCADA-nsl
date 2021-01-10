################################################################################
#
# Namespace: ScsDbm
# Returns:
# Description: Tcl implementation of the Dbm Scadasoft component
#
################################################################################
#
# Author: Pascal GEORGET
# Creation: 19/01/2000
# Modification:
#
################################################################################

namespace eval ScsDbm {
   namespace export init end read oldRead readBit subscribe subscribeAndUpdate unsubscribe deleteGroup;
   namespace export writeFloat writeInteger writeString writeTime writeReference;
   namespace export getChildrenNames getChildrenAliases getAttributes getAttributeStructure;
   namespace export getClassName getClassId getInstancesWithId getInstancesWithName;
   namespace export getUserClassId getInstancesWithUserClassId queryByName
  
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Dbm component
#
################################################################################

   proc init {} {
      ScsTcl_Dbminit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Dbm component
#
################################################################################

   proc end {} {
      ScsTcl_Dbmend
   }
   
################################################################################
#
# Procedure: deleteGroup
# Returns:
# Description: DbmPoller::deleteGroup Tcl implementation
#
################################################################################

   proc deleteGroup {EnvName GroupName} {
      ScsTcl_DbmdeleteGroup $EnvName $GroupName
   }
   
################################################################################
#
# Procedure: getChildrenAliases
# Returns:
# Description: DbmServer::getChildrenAndAliases Tcl implementation
#
################################################################################

   proc getChildrenAliases {EnvName DbFatherPath} {
      ScsTcl_DbmgetChildrenAliases $EnvName $DbFatherPath
   }
   
################################################################################
#
# Procedure: getChildrenNames
# Returns:
# Description: DbmServer::getChildren Tcl implementation
#
################################################################################

   proc getChildrenNames {EnvName DbFatherPath} {
      ScsTcl_DbmgetChildrenNames $EnvName $DbFatherPath
   }
################################################################################
#
# Procedure: getClassName
# Returns:
# Description: DbmServer::getClassName Tcl implementation
#
################################################################################

   proc getClassName {EnvName PointPath} {
      ScsTcl_DbmgetClassName $EnvName $PointPath
   }
   
################################################################################
#
# Procedure: getClassId
# Returns:
# Description: DbmServer::getClassId Tcl implementation
#
################################################################################

   proc getClassId {EnvName PointPath} {
      ScsTcl_DbmgetClassId $EnvName $PointPath
   }

   proc getUserClassId {EnvName PointPath} {
      ScsTcl_DbmgetUserClassId $EnvName $PointPath
   }

################################################################################
#
# Procedure: getInstancesWith
# Returns:
# Description: DbmServer::getClassId Tcl implementation
#
################################################################################

   proc getInstancesWithId {EnvName ClassName {subTree ""}} {
      ScsTcl_DbmgetInstances $EnvName I $ClassName $subTree
   }
   
   proc getInstancesWithUserClassId {EnvName ClassName {subTree ""}} {
      ScsTcl_DbmgetInstances $EnvName U $ClassName $subTree
   }
   
   proc getInstancesWithName {EnvName ClassId {subTree ""}} {
      ScsTcl_DbmgetInstances $EnvName N $ClassId $subTree
   }
   
################################################################################
#
# Procedure: getAttributes
# Returns:
# Description: DbmServer::getAttributes Tcl implementation
#
################################################################################

   proc getAttributes {EnvName DbPointPath} {
      ScsTcl_DbmgetAttributes $EnvName $DbPointPath
   }
   
################################################################################
#
# Procedure: getAttributeStructure
# Returns:
# Description: DbmServer::getAttributeStructure Tcl implementation
#
################################################################################

   proc getAttributeStructure {EnvName DbPointPath} {
      ScsTcl_DbmgetAttributeStructure $EnvName $DbPointPath
   }
################################################################################
#
# Procedure: getAttributeStructure
# Returns:
# Description: DbmServer::getAttributeStructure Tcl implementation
#
################################################################################

   proc getTableAttributeStructure {EnvName DbPointPath} {
      ScsTcl_DbmgetTableAttributeStructure $EnvName $DbPointPath
   }
   
################################################################################
#
# Procedure: read
# Returns:
# Description: DbmServer::read Tcl implementation
#
################################################################################

   proc read {EnvName args} {
      ScsTcl_Dbmread $EnvName $args
   }

################################################################################
#
# Procedure: oldRead
# Returns:
# Description: DbmServer::oldRead Tcl implementation
#
################################################################################

   proc oldRead {EnvName args} {
       ScsTcl_Dbmoldread $EnvName $args
   }
     
################################################################################
#
# Procedure: readBit
# Returns:
# Description: DbmServer::read Tcl implementation for ScsBIT attribute type
#
################################################################################

   proc readBit {EnvName args} {
      ScsTcl_DbmreadBit $EnvName $args
   }
   
################################################################################
#
# Procedure: subscribe
# Returns:
# Description: DbmPoller:subscribe Tcl implementation
#
################################################################################

   proc subscribe {EnvName GroupId ChangeStateCallback args} {
      ScsTcl_Dbmsubscribe $EnvName $GroupId $ChangeStateCallback $args
   }
   
   proc subscribeAndUpdate {EnvName GroupId ChangeStateCallback args} {
      ScsTcl_DbmsubscribeAndUpdate $EnvName $GroupId $ChangeStateCallback $args
   }
   
################################################################################
#
# Procedure: unsubscribe
# Returns:
# Description: DbmPoller:unsubscribe Tcl implementation
#
################################################################################

   proc unsubscribe {EnvName GroupId} {
      ScsTcl_Dbmunsubscribe $EnvName $GroupId
   }
   
################################################################################
#
# Procedure: writeFloat
# Returns:
# Description: DbmServer::write Tcl implementation
#
################################################################################

   proc writeFloat {EnvName FloatValue DatabasePath} {
      global ScsFLOAT
      ScsTcl_Dbmwrite $EnvName $ScsFLOAT $FloatValue $DatabasePath
   }
     
################################################################################
#
# Procedure: writeInteger
# Returns:
# Description: DbmServer::write Tcl implementation
#
################################################################################

   proc writeInteger {EnvName IntegerValue DatabasePath} {
      global ScsINTEGER
      ScsTcl_Dbmwrite $EnvName $ScsINTEGER $IntegerValue $DatabasePath
   }
     
################################################################################
#
# Procedure: writeString
# Returns:
# Description: DbmServer::write Tcl implementation
#
################################################################################

   proc writeString {EnvName StringValue DatabasePath} {
      global ScsSTRING
      ScsTcl_Dbmwrite $EnvName $ScsSTRING $StringValue $DatabasePath
   }
     
################################################################################
#
# Procedure: writeTime
# Returns:
# Description: DbmServer::write Tcl implementation
#
################################################################################

   proc writeTime {EnvName TimeValue DatabasePath} {
      global ScsTIME
      ScsTcl_Dbmwrite $EnvName $ScsTIME $TimeValue $DatabasePath
   }
     
################################################################################
#
# Procedure: write
# Returns:
# Description: DbmServer::write Tcl implementation
#
################################################################################

   proc writeReference {EnvName ReferenceValue DatabasePath} {
      global ScsREFERENCE
      ScsTcl_Dbmwrite $EnvName $ScsREFERENCE $ReferenceValue $DatabasePath
   }
   ## Wraps DbmServer::getFullPath
   proc getFullPath { EnvName Alias } {
      ScsTcl_DbmgetFullPath $EnvName $Alias
   }
   proc getAlias { EnvName AbsolutePath } {
      ScsTcl_DbmgetAlias $EnvName $AbsolutePath
   }
  proc getCEOper { EnvName Addresses} {
      ScsTcl_DbmgetCEOper $EnvName $Addresses
  }
   proc controlCE { EnvName Addresses CEModes } {
      ScsTcl_DbmcontrolCE $EnvName $Addresses $CEModes
   }
   proc getClasses { EnvName } {
      ScsTcl_DbmgetClasses $EnvName
   }
  ## multiple write
  proc write { EnvName Types Values Addresses} {
      ScsTcl_Dbmwrite $EnvName $Types $Values $Addresses
  }
  proc queryByName { EnvName StartingPoint RegExp} {
      ScsTcl_DbmqueryByName $EnvName $StartingPoint $RegExp
  }
}