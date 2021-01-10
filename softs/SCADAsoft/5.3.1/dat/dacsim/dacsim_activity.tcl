# dacsim_activity.tcl --
#
# Definition of procedures for the simulation scripts.
# Implementation of the activity command.
#

# dacsim::ActivitySet --
#
# Set the activity state of each matching input variable with the specified value.
#
# Parameters:
#   varSpec     the specification of the input variables to change.
#   state       the activity state ("on" or "off") to be set.
#
# Side Effects:
#   Changes the activity state of the matching variables.

proc dacsim::ActivitySet {varSpec state} {
    #puts "dacsim::ActivitySet called with varSpec = $varSpec, state = $state"
    if {$state == "on"} {
        set value 1
    } else {
        set value 0
    }
    if {[catch {::DacSimActivitySet $varSpec $value}] != 0} {
        puts "Error during DacSimActivitySet $varSpec $value"
        return
    }
}

# dacsim::ActivityDisp --
#
# Display a pretty-printed list of the matching variables with their activity state values.
#
# Parameters:
#   varSpec     (optional) the specification of the variables to list (or all).
#
# Results:
#   A formatted list of variables with their activity state values.

proc dacsim::ActivityDisp {{varSpec *}} {
    #puts "dacsim::ActivityDisp called with varSpec = $varSpec"
    set varNames {}
    set values {}
    if {[catch {::DacSimActivityGet $varSpec varNames values}] != 0} {
        puts "Error during DacSimActivityGet $varSpec"
        return
    }
    set result {}
    set newline ""
    set n [llength $varNames]
    if {$n == 0} {
        puts "No input variables match $varSpec"
        return
    }
    for {set i 0} {$i < $n} {incr i} {
        set varName [lindex $varNames $i]
        set value [lindex $values $i]
        if {$value != 0} {
            set state "on"
        } else {
            set state "off"
        }
        append result $newline[format "%s: %s" $varName $state]
        set newline \n
    }
    return $result
}
