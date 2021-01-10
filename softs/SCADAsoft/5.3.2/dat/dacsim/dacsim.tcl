# dacsim.tcl --
#
# Definition of procedures for the simulation scripts.
#
# Arguments:
#   $argc: number of script's arguments plus 1
#   $argv: script ?arg arg ...?
#

namespace eval dacsim {
    variable exeMod 1
    variable exeCnt 0
    variable exeRun 0
}

variable wait 1

source $env(SCSHOME)/dat/dacsim/dacsim_activity.tcl
source $env(SCSHOME)/dat/dacsim/dacsim_config.tcl
source $env(SCSHOME)/dat/dacsim/dacsim_delay.tcl
source $env(SCSHOME)/dat/dacsim/dacsim_exec.tcl
source $env(SCSHOME)/dat/dacsim/dacsim_extvar.tcl
source $env(SCSHOME)/dat/dacsim/dacsim_reaction.tcl
source $env(SCSHOME)/dat/dacsim/dacsim_run.tcl
source $env(SCSHOME)/dat/dacsim/dacsim_wait.tcl

# activity --
#
# This is the main activity command.  See the man page for its interface.
# This does argument checking and calls helper procedures in the
# dacsim namespace.

proc activity {args} {
    set len [llength $args]
    if {$len < 1} {
        return -code error "wrong # args: should be \"activity ?option? ?arg arg ...?\""
    }
    set key [lindex $args 0]
    if {(![string match $key* on]) && (![string match $key* off]) && (![string match $key* display])} {
        set key display
        set args [linsert $args 0 $key]
        incr len 1
    }
    set options "on off, or display"
    switch -glob -- $key {
        on* { # activity on
            if {![string match $key* on]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {($len < 2) || ($len > 2)} {
                return -code error "wrong # args: should be \"activity on varSpec\""
            }
            set varSpec [lindex $args 1]
            dacsim::ActivitySet $varSpec "on"
            return [dacsim::ActivityDisp $varSpec]
        }
        of* { # activity off
            if {![string match $key* off]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {($len < 2) || ($len > 2)} {
                return -code error "wrong # args: should be \"activity off varSpec\""
            }
            set varSpec [lindex $args 1]
            dacsim::ActivitySet $varSpec "off"
            return [dacsim::ActivityDisp $varSpec]
        }
        d* { # activity display
            if {![string match $key* display]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {$len > 2} {
                return -code error "wrong # args: should be \"activity display ?varSpec?\""
            }
            if {$len > 1} {
                set varSpec [lindex $args 1]
                return [dacsim::ActivityDisp $varSpec]
            } else {
                return [dacsim::ActivityDisp]
            }
        }
        default {
            return -code error "bad option \"$key\": must be $options"
        }
    }
}

# configure --
#
# This is the main configure command.  See the man page for its interface.
# This does argument checking and calls helper procedures in the
# dacsim namespace.

proc configure {args} {
    set len [llength $args]
    if {$len < 0} {
        return -code error "wrong # args: should be \"configure\""
    }
    set key ""
    set options ""
    switch -glob -- $key {
        * { # configure
            if {![string match $key* ""]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {$len > 0} {
                return -code error "wrong # args: should be \"configure\""
            }
            return [dacsim::Config]
        }
        default {
            return -code error "bad option \"$key\": must be $options"
        }
    }
}

# delay --
#
# This is the main delay command.  See the man page for its interface.
# This does argument checking and calls helper procedures in the
# dacsim namespace.

proc delay {args} {
    set len [llength $args]
    if {$len < 1} {
        return -code error "wrong # args: should be \"delay ?option? ?arg arg ...?\""
    }
    set key [lindex $args 0]
    if {(![string match $key* execution])} {
        set key execution
        set args [linsert $args 0 $key]
        incr len 1
    }
    set options "execution"
    switch -glob -- $key {
        e* { # delay execution
            if {![string match $key* execution]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {($len < 3) || ($len > 3)} {
                return -code error "wrong # args: should be \"delay execution time commandList\""
            }
            if {([catch {set time [expr ([lindex $args 1]) * 1000]}]) || ($time < 0)} {
                return -code error "bad time \"[lindex $args 1]\": must be a positive number of seconds"
            }
            set commandList [lindex $args 2]
            return [dacsim::DelayExec $time $commandList]
        }
        default {
            return -code error "bad option \"$key\": must be $options"
        }
    }
}

# extvar --
#
# This is the main extvar command.  See the man page for its interface.
# This does argument checking and calls helper procedures in the
# dacsim namespace.

proc extvar {args} {
    set len [llength $args]
    if {$len < 1} {
        return -code error "wrong # args: should be \"extvar ?option? ?arg arg ...?\""
    }
    set key [lindex $args 0]
    if {(![string match $key* set]) && (![string match $key* get]) && (![string match $key* display]) && (![string match $key* groupset])} {
        set key display
        set args [linsert $args 0 $key]
        incr len 1
    }
    
    set options "set get, groupset or display"
    switch -glob -- $key {
        s* { # extvar set
            if {![string match $key* set]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {($len < 3) || ($len > 3)} {
                return -code error "wrong # args: should be \"extvar set varSpec value\""
            }
            set varSpec [lindex $args 1]
            set value [lindex $args 2]
            if {[dacsim::ExtVarSet $varSpec $value] != ""} {
		return [dacsim::ExtVarDisp $varSpec]
	    }
	    return;
        }
        ge* { # extvar get
            if {![string match $key* get]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {($len < 2) || ($len > 2)} {
                return -code error "wrong # args: should be \"extvar get varName\""
            }
            set varName [lindex $args 1]
            return [dacsim::ExtVarGet $varName]
        }
        gr* { # extvar groupset
            if {![string match $key* groupset]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {($len < 2) || ($len > 2)} {
                return -code error "wrong # args: should be \"extvar groupset varList\""
            }
            set varList [lindex $args 1]
            return [dacsim::ExtVarGroupSet $varList]
        }
        d* { # extvar display
            if {![string match $key* display]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {($len < 1) || ($len > 2)} {
                return -code error "wrong # args: should be \"extvar display ?varSpec?\""
            }
            if {$len > 1} {
                set varSpec [lindex $args 1]
                return [dacsim::ExtVarDisp $varSpec]
            } else {
                return [dacsim::ExtVarDisp]
            }
        }
        default {
            return -code error "bad option \"$key\": must be $options"
        }
    }
}

# reaction --
#
# This is the main reaction command.  See the man page for its interface.
# This does argument checking and calls helper procedures in the
# dacsim namespace.

proc reaction {args} {
    set len [llength $args]
    if {$len < 1} {
        return -code error "wrong # args: should be \"reaction ?option? ?arg arg ...?\""
    }
    set key [lindex $args 0]
    if {(![string match $key* on]) && (![string match $key* off]) && (![string match $key* display])} {
        set key display
        set args [linsert $args 0 $key]
        incr len 1
    }
    set options "on off, or display"
    switch -glob -- $key {
        on* { # reaction on
            if {![string match $key* on]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {($len < 2) || ($len > 2)} {
                return -code error "wrong # args: should be \"reaction on varSpec\""
            }
            set varSpec [lindex $args 1]
            dacsim::ReactionSet $varSpec "on"
            return [dacsim::ReactionDisp $varSpec]
        }
        of* { # reaction off
            if {![string match $key* off]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {($len < 2) || ($len > 2)} {
                return -code error "wrong # args: should be \"reaction off varSpec\""
            }
            set varSpec [lindex $args 1]
            dacsim::ReactionSet $varSpec "off"
            return [dacsim::ReactionDisp $varSpec]
        }
        d* { # reaction display
            if {![string match $key* display]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {$len > 2} {
                return -code error "wrong # args: should be \"reaction display ?varSpec?\""
            }
            if {$len > 1} {
                set varSpec [lindex $args 1]
                return [dacsim::ReactionDisp $varSpec]
            } else {
                return [dacsim::ReactionDisp]
            }
        }
        default {
            return -code error "bad option \"$key\": must be $options"
        }
    }
}

# run --
#
# This is the main run command.  See the man page for its interface.
# This does argument checking and calls helper procedures in the
# dacsim namespace.

proc run {args} {
    set len [llength $args]
    if {$len < 1} {
        return -code error "wrong # args: should be \"run ?option? ?arg arg ...?\""
    }
    set key [lindex $args 0]
    if {(![string match $key* wait]) && (![string match $key* nowait])} {
        variable wait
        if {$wait} {
            set key wait
        } else {
            set key nowait
        }
        set args [linsert $args 0 $key]
        incr len 1
    }
    set options "wait or nowait"
    switch -glob -- $key {
        w* { # run wait
            if {![string match $key* wait]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {$len < 2} {
                return -code error "wrong # args: should be \"run wait scriptName ?arg arg ...?\""
            }
            set scriptName [lindex $args 1]
            set scriptArgs [lrange $args 2 end]
            return [dacsim::RunExec 1 $scriptName $scriptArgs]
        }
        n* { # run nowait
            if {![string match $key* nowait]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {$len < 2} {
                return -code error "wrong # args: should be \"run nowait scriptName ?arg arg ...?\""
            }
            set scriptName [lindex $args 1]
            set scriptArgs [lrange $args 2 end]
            return [dacsim::RunExec 0 $scriptName $scriptArgs]
        }
        default {
            return -code error "bad option \"$key\": must be $options"
        }
    }
}

# wait --
#
# This is the main wait command.  See the man page for its interface.
# This does argument checking and calls helper procedures in the
# dacsim namespace.

proc wait {args} {
    set len [llength $args]
    if {$len < 1} {
        return -code error "wrong # args: should be \"wait ?option? ?arg arg ...?\""
    }
    set key [lindex $args 0]
    if {(![string match $key* delay]) && (![string match $key* condition]) && (![string match $key* execution])} {
        set key delay
        set args [linsert $args 0 $key]
        incr len 1
    }
    set options "delay, condition or execution"
    switch -glob -- $key {
        d* { # wait delay
            if {![string match $key* delay]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {($len < 2) || ($len > 2)} {
                return -code error "wrong # args: should be \"wait delay time\""
            }
            if {([catch {set time [expr ([lindex $args 1]) * 1000]}]) || ($time < 0)} {
                return -code error "bad time \"[lindex $args 1]\": must be a positive number of seconds"
            }
            return [dacsim::WaitDelay $time]
        }
        c* { # wait condition
            if {![string match $key* condition]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {($len < 3) || ($len > 5)} {
                return -code error "wrong # args: should be \"wait condition booleanExpr commandList ?timeOut? ?commandList?\""
            }
            set condition [lindex $args 1]
            set commandList [lindex $args 2]
            if {$len > 3} {
                if {([catch {set timeOut [expr ([lindex $args 3]) * 1000]}]) || ($timeOut < 0)} {
                    return -code error "bad timeout \"[lindex $args 3]\": must be a positive number of seconds"
                }
            } else {
                set timeOut {}
            }
            if {$len > 4} {
                set timeOutList [lindex $args 4]
            } else {
                set timeOutList {}
            }
            return [dacsim::DelayCond $condition $commandList $timeOut $timeOutList]
        }
        e* { # wait execution
            if {![string match $key* execution]} {
                return -code error "bad option \"$key\": must be $options"
            }
            if {($len < 1) || ($len > 2)} {
                return -code error "wrong # args: should be \"wait execution ?name?\""
            }
            if {$len > 1} {
                set name [lindex $args 1]
                return [dacsim::ExecWait $name]
            } else {
                return [dacsim::ExecWait]
            }
        }
        default {
            return -code error "bad option \"$key\": must be $options"
        }
    }
}

if {("[info vars argc]" != "") && ($argc > 0)} {
    dacsim::RunExec $wait [lindex $argv 0] [join [lrange $argv 1 end]]
}

return
