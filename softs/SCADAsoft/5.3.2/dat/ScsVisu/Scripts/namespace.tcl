############################################
#
# --- Animator classes namespaces
#
############################################

namespace eval ActiveNumber {}
namespace eval ActiveBackdrop {}
namespace eval ActiveSymbol {}
namespace eval ActiveText {}
namespace eval Bargraph {}
namespace eval FillingSymbol {}

############################################
#
# --- Formulas namespace
#
############################################

namespace eval ::Formulas {
proc OnError { message } {
        puts "Error in script..."
        puts "------------------"
        puts $message
}
}
