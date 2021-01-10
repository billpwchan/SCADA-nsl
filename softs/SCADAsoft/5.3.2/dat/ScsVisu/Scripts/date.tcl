#####################################
#
# ---- Date instructions
#
#####################################

namespace eval Date {}

#
# ---- Instructions
#
#

proc Date::GmtDate { pSeconds pFormat } {
    Scs_GmtDate $pSeconds $pFormat
}

proc Date::GmtDateC { pSeconds pFormat } {
    Scs_GmtDateC $pSeconds $pFormat
}
