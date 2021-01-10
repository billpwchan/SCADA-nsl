# dacsim_config.tcl --
#
# Definition of procedures for the simulation scripts.
# Implementation of the config command.
#

# dacsim::Config --
#
# Reconfigure the reaction specifications.
#
# Parameters:
#
# Side Effects:
#   Changes the reaction specifications for the output variables.

proc dacsim::Config {} {
    #puts "dacsim::Config called"
    if {[catch {::DacSimConfig}] != 0} {
        puts "Error during DacSimConfig"
    }
}
