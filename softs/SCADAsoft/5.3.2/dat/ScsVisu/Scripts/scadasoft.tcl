#
# ---- Perform Initialisation
#

source $env(SCSHOME)/dat/ScsVisu/Scripts/constants.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/scs.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/accessors.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/scsvisu.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/panels.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/animator.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/namespace.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/database.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/lists.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/trace.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/opm.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/tsc.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/dss.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/threads.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/trends.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/fts.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/lst.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/his.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/player.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/timezone.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/pie.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/date.tcl
source $env(SCSHOME)/dat/ScsVisu/Scripts/sound.tcl


#
# ---- Perform List Initialisation
#

source $env(SCSHOME)/dat/ScsList/Scripts/genlist.tcl
source $env(SCSHOME)/dat/ScsList/Scripts/almlist.tcl


#
# ---- Specific modules
#

# PIDS
source $env(SCSHOME)/dat/ScsVisu/Scripts/pids.tcl

# OCX (WIN32 only)
set os [lindex [set ::tcl_platform(os)] 0]
if { $os == "Windows" } {
	source $env(SCSHOME)/dat/ScsVisu/Scripts/ocx.tcl
}


#
# ---- Removes all the variables of a namespace
#

proc ScsClearNamespace { pNameSpace } {
    set scsMatching [ format "::%s::*" $pNameSpace ]
    foreach scsVarName [ info vars $scsMatching ] {
        if { [ info exists $scsVarName ] } {
            unset $scsVarName
        }
    }
}

proc ScsDeleteNamespace { pNameSpace } {
    namespace delete [ format "::%s" $pNameSpace ]
}
