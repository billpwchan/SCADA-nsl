################################################################################
#
# Namespace: ScsCtl
# Returns:
# Description: Tcl implementation of the Ctl Scadasoft component
#
################################################################################
#
# Author: Pascal GEORGET
# Creation: 24/01/2000
# Modification:
#
################################################################################

namespace eval ScsCtl {
    
    namespace export init end sendCommand sendMultiCommand; # CtlCmd interface
    namespace export prepareGrc abortGrcPreparation launchGrc launchGrcStep launchGrcAtStep launchGrcSkippingSteps launchGrcWithOpts abortGrc suspendGrc resumeGrc; # CtlGrc interface
    
################################################################################
#
# Procedure: init
# Returns:
# Description: Initialize the Ctl component
#
################################################################################

   proc init {} {
      ScsTcl_Ctlinit
   }
   
################################################################################
#
# Procedure: end
# Returns:
# Description: end the Ctl component
#
################################################################################

   proc end {} {
      ScsTcl_Ctlend
   }
   
################################################################################
#
# Procedure: sendCommand
# Returns:
# Description: CtlCmdServer::sendCommand Tcl implementation
#
################################################################################

    proc sendCommand {EnvName CommandPath CommandType CommandValue BpInit BpReturn SendB CallbackProcedure {Source ""}} {
      ScsTcl_CtlsendCommand $EnvName $CommandPath $CommandType $CommandValue $BpInit $BpReturn $SendB $CallbackProcedure $Source;
   }

################################################################################
#
# Procedure: sendMultiCommand
# Returns:
# Description: CtlCmdServer::sendCommand Tcl implementation
#
################################################################################

   proc sendMultiCommand {EnvName CommandsList Mode CallbackProcedure {Source ""}} {
      ScsTcl_CtlsendMultiCommand $EnvName $CommandsList $Mode $CallbackProcedure $Source
   }

################################################################################
#
# Procedure: prepareGrc
# Returns:
# Description: CtlGrcServer::prepareGrc Tcl implementation
#
################################################################################

   proc prepareGrc {EnvName GrcName GrcStartStep {Source ""}} {
      ScsTcl_CtlprepareGrc $EnvName "$GrcName:$GrcStartStep" $Source
   }

################################################################################
#
# Procedure: abortGrcPreparation
# Returns:
# Description: CtlGrcServer::abortGrcPreparation Tcl implementation
#
################################################################################

    proc abortGrcPreparation {EnvName GrcName {Source ""}} {
      ScsTcl_CtlabortGrcPreparation $EnvName $GrcName $Source
   }

################################################################################
#
# Procedure: launchGrc
# Returns:
# Description: CtlGrcServer::launchGrc Tcl implementation
#
################################################################################

   proc launchGrc {EnvName GrcName GrcMode CallbackProcedure {Source ""}} {
      ScsTcl_CtlrunGrc $EnvName $GrcName $GrcMode $CallbackProcedure $Source;
   }

################################################################################
#
# Procedure: launchGrcStep
# Returns:
# Description: CtlGrcServer::launchGrcStep Tcl implementation
#
################################################################################

   proc launchGrcStep {EnvName GrcName StepNumber CallbackProcedure {Source ""}} {
      ScsTcl_CtlrunGrcStep $EnvName $GrcName $StepNumber $CallbackProcedure $Source;
   }

################################################################################
#
# Procedure: launchGrcAtStep
# Returns:
# Description: CtlGrcServer::launchGrcAtStep Tcl implementation
#
################################################################################

   proc launchGrcAtStep {EnvName GrcName GrcStep CallbackProcedure {Source ""}} {
      ScsTcl_CtlrunGrcAtStep $EnvName $GrcName $GrcStep $CallbackProcedure $Source;
   }

################################################################################
#
# Procedure: launchGrcSkippingSteps
# Returns:
# Description: CtlGrcServer::launchGrcSkippingSteps Tcl implementation
#
################################################################################

   proc launchGrcSkippingSteps {EnvName GrcName GrcStepsToSkip CallbackProcedure {Source ""}} {
      ScsTcl_CtlrunGrcSkippingSteps $EnvName $GrcName $GrcStepsToSkip $CallbackProcedure $Source;
   }

################################################################################
#
# Procedure: launchGrcWithOpts
# Returns:
# Description: CtlGrcServer::launchGrc Tcl implementation
#
################################################################################

   proc launchGrcWithOpts {EnvName GrcName GrcMode GrcStep GrcStepsToSkip CallbackProcedure {Source ""}} {
       ScsTcl_CtlrunGrcWithOpts $EnvName $GrcName $GrcMode $GrcStep $GrcStepsToSkip $CallbackProcedure $Source;
   }

################################################################################
#
# Procedure: abortGrc
# Returns:
# Description: CtlGrcServer::abortGrc Tcl implementation
#
################################################################################

   proc abortGrc {EnvName GrcName {Source ""}} {
      ScsTcl_CtlabortGrc $EnvName $GrcName $Source;
   }

################################################################################
#
# Procedure: suspendGrc
# Returns:
# Description: CtlGrcServer::suspendGrc Tcl implementation
#
################################################################################

   proc suspendGrc {EnvName GrcName {Source ""}} {
      ScsTcl_CtlsuspendGrc $EnvName $GrcName $Source;
   }

################################################################################
#
# Procedure: resumeGrc
# Returns:
# Description: CtlGrcServer::resumeGrc Tcl implementation
#
################################################################################

   proc resumeGrc {EnvName GrcName {Source ""}} {
      ScsTcl_CtlresumeGrc $EnvName $GrcName $Source;
   }
   
}
