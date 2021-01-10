###############################
#
# ----- Namespace
#
###############################
namespace eval Scs { }


###############################
#
# ----- Variables
#
###############################
set Scs::CurrentGraphicPath ":"
set Scs::CurrentImage       ""


###############################
#
# ---- Procedure
#
###############################

proc Scs::Remote { pEnv pServer pInstruction {pasyncMode 0} } {
    Scs_Call $pEnv $pServer $pInstruction $pasyncMode
}
