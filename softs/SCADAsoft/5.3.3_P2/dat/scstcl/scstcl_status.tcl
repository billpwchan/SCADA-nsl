################################################################################
#
# Namespace: ScsStatus
# Returns:
# Description: Load each namespace of the Scadasoft Tcl implementation
#
################################################################################
#
# Author: Pascal GEORGET
# Creation: 19/01/2000
# Modification:
#
################################################################################

namespace eval ScsStatus {

   namespace export getMajor getMinor getText isError isValid print;
   
   variable _major ?;
   variable _minor ?;
   variable _text init;
   variable _iserror ?;
   variable _isvalid ?;
   
################################################################################
#
# Procedure: getMajor
# Returns:
# Description: Get the last major error code
#
################################################################################

   proc getMajor {} {
      variable _major;
      return $_major;
   }
   
################################################################################
#
# Procedure: getMinor
# Returns:
# Description: Get the last minor error code
#
################################################################################

   proc getMinor {} {
      variable _minor;
      return $_minor;
   }
   
################################################################################
#
# Procedure: getText
# Returns:
# Description: Get the last text error
#
################################################################################

   proc getText {} {
      variable _text;
      return $_text;
   }

################################################################################
#
# Procedure: isError
# Returns:
# Description: Get the last text error
#
################################################################################

   proc isError {} {
      variable _iserror;
      if {$_iserror == 1} {
         return True;
      } else {
         return False;
      }
   }

################################################################################
#
# Procedure: isValid
# Returns: 
# Description: Get the last text error
#
################################################################################

   proc isValid {} {
      variable _isvalid;
      if {$_isvalid == 1} {
         return True;
      } else {
         return False;
      }
   }
}
