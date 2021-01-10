# dacsim_run.tcl --
#
# Definition of procedures for the simulation scripts.
# Implementation of the run command.
#

# dacsim::RunExec --
#
# Run execution of simulation script.
#
# Parameters:
#   execMode    the execution mode (0 = no wait, 1 = wait)
#   scriptName  the name of the script to run.
#   scriptArgs  the arguments to be passed to the script.
#
# Side Effects:
#   Execute activity simulation commands.
#   In wait mode, wait for all commands to be executed.
#
# Results:
#   In no wait mode, return namespace in which the commands are executed.

proc dacsim::RunExec {execMode scriptName scriptArgs} {
    #puts "dacsim::RunExec called with execMode = $execMode, scriptName = $scriptName, scriptArgs = $scriptArgs"

    variable exeCnt
    variable script $scriptName
    variable argCnt [llength $scriptArgs]
    variable argTab $scriptArgs
    variable isWait $execMode

    set execId $scriptName
    for {set i 0} {$i < $argCnt} {incr i} {
        set execId $execId\_[lindex $argTab $i]
    }

    if {[info vars ${execId}::dacsim::exeCnt] != ""} {
        puts "Can't run $execId twice (execution already running)"
        return
    }

    incr exeCnt 1
    #puts "run execution started at: [clock format [clock seconds] -format {%x %X}]"

    namespace eval $execId {
        set argc 0
        set argv ""

        global env
        source $env(SCSHOME)/dat/dacsim/dacsim.tcl

        eval "
            variable argc \[expr $[namespace parent]::argCnt + 1\]
            variable argv \"$[namespace parent]::script $[namespace parent]::argTab\"
            variable wait \[expr $[namespace parent]::isWait\]
            #variable wait 0
        "

        for {set i 0} {$i < $argc} {incr i} {
            variable $i [lindex $argv $i]
        }

        set dacsim::exeMod $wait
        set dacsim::exeCnt 0
        set dacsim::exeRun 1

        if {[catch {source [lindex $argv 0].tcl}] != 0} {
            puts "Error executing script [lindex $argv 0].tcl - $errorInfo"
        }

        set dacsim::exeRun 0
	dacsim::ExecClean [namespace current]
    }

    if {$execMode == 1} {
        ExecWait $execId
    } else {
        return $execId
    }
}
