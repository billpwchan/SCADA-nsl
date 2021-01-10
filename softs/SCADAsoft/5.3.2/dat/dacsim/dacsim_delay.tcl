# dacsim_delay.tcl --
#
# Definition of procedures for the simulation scripts.
# Implementation of the delay command.
#

# dacsim::DelayExec --
#
# Delay execution of commands for a specified time.
#
# Parameters:
#   time        the delay time.
#   commandList the list of commands to be executed.
#
# Side Effects:
#   Wait for delay time to expire and then execute activity simulation commands.

proc dacsim::DelayExec {time commandList} {
    #puts "dacsim::DelayExec called with time = $time"

    variable exeCnt
    incr exeCnt 1
    #puts "delay execution started at: [clock format [clock seconds] -format {%x %X}]"
    after $time "
        namespace eval [namespace parent] {
            \#puts \"delay execution completed at: \[clock format \[clock seconds\] -format {%x %X}\]\"
            incr dacsim::exeCnt -1
            catch \{ $commandList \}
            dacsim::ExecClean \[namespace current\]
        }
    "
}

# dacsim::DelayCond --
#
# Delay execution of commands for a condition to complete.
#
# Parameters:
#   condition   the condition.
#   commandList the list of commands to be executed.
#   timeOut     the time-out (optional).
#   timeOutList the list of commands to be executed on time-out (optional).
#
# Side Effects:
#   Wait for condition to be verified and then execute activity simulation commands.
#   Don't execute commands if time-out expires before condition is verified.

proc dacsim::DelayCond {condition commandList timeOut timeOutList} {
    #puts "dacsim::DelayCond called with condition = $condition, timeOut = $timeOut"

    variable exeCnt
    #puts "wait condition started at: [clock format [clock seconds] -format {%x %X}]"
    if {$timeOut != {}} {
        incr timeOut -1000
    }
    incr exeCnt 1
    #puts "wait condition sleeped at: [clock format [clock seconds] -format {%x %X}]"
    after 1000 "
        namespace eval [namespace parent] {
            \#puts \"wait condition awakened at: \[clock format \[clock seconds\] -format {%x %X}]\"
            incr dacsim::exeCnt -1
            set condval 0
            catch {set condval \[expr $condition\]}
            if {\[set condval\]} {
                \#puts \"wait condition completed at: \[clock format \[clock seconds\] -format {%x %X}\]\"
                if { \[catch \{ $commandList \} errorText\] } {
                    puts \[concat \"Delayed commands '\" \{$commandList\} \"' :\" \[set errorText\]\]
                }
            } else {
                if {(\"$timeOut\" == {}) || (\"$timeOut\" > 0)} {
                    dacsim::DelayCond {$condition} {$commandList} {$timeOut} {$timeOutList}
                } else {
                    \#puts \"wait condition timed out at: \[clock format \[clock seconds\] -format {%x %X}\]\"
                    if { \[catch \{ $timeOutList \} errorText\] } {
                        puts \[concat \"Timeout commands '\" \{$timeOutList\} \"':\" \[set errorText\]\]
                    }
                }
            }
            dacsim::ExecClean \[namespace current\]
        }
    "
}
