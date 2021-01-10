# dacsim_extvar.tcl --
#
# Definition of procedures for the simulation scripts.
# Implementation of the extvar command.
#

# dacsim::ExtVarSet --
#
# Set each matching variable with the specified value.
#
# Parameters:
#   varSpec     the specification of the variables to change.
#   value       the value to be set.
#
# Side Effects:
#   Changes the value of the matching variables.

proc dacsim::ExtVarSet {varSpec value} {
    #puts "dacsim::ExtVarSet called with varSpec = $varSpec, value = $value"
    if {[catch {::DacSimExtVarSet $varSpec $value}] != 0} {
        puts "Error during DacSimExtVarSet $varSpec $value"
        return
    }
}

# dacsim::ExtVarGet --
#
# Return the value of the variable.
#
# Parameters:
#   varName     the name of the variable to read.
#
# Results:
#   The value of the variable.

proc dacsim::ExtVarGet {varName} {
    #puts "dacsim::ExtVarGet called with varName = $varName"
    set varSpec $varName
    set varName ""
    set value ""
    if {[catch {::DacSimExtVarGet $varSpec varName value}] != 0} {
        puts "Error during DacSimExtVarGet $varSpec"
        return
    }
    set n [llength $varName]
    if {$n > 1} {
        puts "Can't return the value of $varSpec (must be a unique variable)"
        return
    } elseif {$n == 0} {
        puts "Variable $varSpec not found"
        return
    }
    return $value
}

# dacsim::ExtVarDisp --
#
# Display a pretty-printed list of the matching variables with their values.
#
# Parameters:
#   varSpec     (optional) the specification of the variables to list (or all).
#
# Results:
#   A formatted list of variables.

proc dacsim::ExtVarDisp {{varSpec *}} {
    #puts "dacsim::ExtVarDisp called with varSpec = $varSpec"
    set varNames {}
    set values {}
    if {[catch {::DacSimExtVarGet $varSpec varNames values}] != 0} {
        puts "Error during DacSimExtVarGet $varSpec"
        return
    }
    set result {}
    set newline ""
    set n [llength $varNames]
    if {$n == 0} {
        puts "No variables match $varSpec"
        return
    }
    for {set i 0} {$i < $n} {incr i} {
        set varName [lindex $varNames $i]
        set value [lindex $values $i]
        append result $newline[format "%s = %s" $varName $value]
        set newline \n
    }
    return $result
}

# dacsim::ExtVarGroupSet --
#
# Set each variable of the group in one call.
#
# Parameters:
#   varList     list of tuple (variable name, value, [timestamp, [validity]])
#
# Side Effects:
#   Changes the value of the matching variables.

proc dacsim::ExtVarGroupSet {varList} {
    #puts "dacsim::ExtVarGroupSet called with varList = $varList"
    if {[catch {::DacSimExtVarGroupSet $varList}] != 0} {
        puts "Error during DacSimExtVarSet $varList"
        return
    }
}
