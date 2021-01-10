# dacsim_wait.tcl --
#
# Definition of procedures for the simulation scripts.
# Implementation of the wait command.
#

# dacsim::WaitDelay --
#
# Wait for delay.
#
# Parameters:
#   time        the delay time.
#
# Side Effects:
#   Wait for delay time to expire.

proc dacsim::WaitDelay {time} {
    #puts "dacsim::WaitDelay called with time = $time"

    #puts "wait delay started at: [clock format [clock seconds] -format {%x %X}]"
    after $time
    #puts "wait delay completed at: [clock format [clock seconds] -format {%x %X}]"
}
