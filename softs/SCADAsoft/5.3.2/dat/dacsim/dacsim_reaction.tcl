# dacsim_reaction.tcl --
#
# Definition of procedures for the simulation scripts.
# Implementation of the reaction command.
#

# dacsim::ReactionSet --
#
# Set the reaction state of each matching output variable with the specified value.
#
# Parameters:
#   varSpec     the specification of the output variables to change.
#   state       the reaction state ("on" or "off") to be set.
#
# Side Effects:
#   Changes the reaction state of the matching variables.

proc dacsim::ReactionSet {varSpec state} {
    #puts "dacsim::ReactionSet called with varSpec = $varSpec, state = $state"
    if {$state == "on"} {
        set value 1
    } else {
        set value 0
    }
    if {[catch {::DacSimReactionSet $varSpec $value}] != 0} {
        puts "Error during DacSimReactionSet $varSpec $value"
        return
    }
}

# dacsim::ReactionDisp --
#
# Display a pretty-printed list of the matching variables with their reaction state values.
#
# Parameters:
#   varSpec     (optional) the specification of the variables to list (or all).
#
# Results:
#   A formatted list of variables with their reaction state values.

proc dacsim::ReactionDisp {{varSpec *}} {
    #puts "dacsim::ReactionDisp called with varSpec = $varSpec"
    set varNames {}
    set values {}
    if {[catch {::DacSimReactionGet $varSpec varNames values}] != 0} {
        puts "Error during DacSimReactionGet $varSpec"
        return
    }
    set result {}
    set newline ""
    set n [llength $varNames]
    if {$n == 0} {
        puts "No output variables match $varSpec"
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
