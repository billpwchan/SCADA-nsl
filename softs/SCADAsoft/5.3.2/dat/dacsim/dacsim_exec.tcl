# dacsim_exec.tcl --
#
# Definition of procedures for the simulation scripts.
# Implementation of the exec command.
#

# dacsim::ExecWait --
#
# Wait for end of execution in a namespace.
#
# Parameters:
#   execId      (optional) the execution id (namespace).
#
# Side Effects:
#   Wait for end of execution of activity simulation commands.
#   Delete namespace (if not global) when execution is completed.

proc dacsim::ExecWait {{execId ""}} {
    #puts "dacsim::ExecWait called with execId = $execId"

    if {$execId == ""} {
        set execId [namespace parent]
    }

    if {[info vars ${execId}::dacsim::exeCnt] == ""} {
        puts "Execution $execId is not currently running"
        return
    }

    namespace eval $execId {
        set dacsim::exeMod 1
        #puts "execution wait started at: [clock format [clock seconds] -format {%x %X}]"
        while {$dacsim::exeCnt > 0} {
            #puts "execution wait: $dacsim::exeCnt left"
            vwait [namespace current]::dacsim::exeCnt
        }
        set dacsim::exeMod 0
        #puts "execution wait completed at: [clock format [clock seconds] -format {%x %X}]"

        dacsim::ExecClean [namespace current]
    }
}

# dacsim::ExecClean --
#
# Clean execution in a namespace.
#
# Parameters:
#   execId      the execution id (namespace).
#
# Side Effects:
#   Clean execution of activity simulation commands.
#   Delete all parent namespaces in which execution is completed.

proc dacsim::ExecClean {execId} {
    #puts "dacsim::ExecClean called with execId = $execId"

    if {$execId == ""} {
        set execId [namespace parent]
    }

    if {$execId == "::"} {
        return
    }

    namespace eval $execId {
        #puts "run execution completed at: [clock format [clock seconds] -format {%x %X}]"

        if {($dacsim::exeMod == 0) && ($dacsim::exeCnt == 0) && ($dacsim::exeRun == 0)} {
            set execParentId [namespace parent]

            namespace delete [namespace current]

            set execParentId [namespace parent $execParentId]
            namespace eval $execParentId {
                incr dacsim::exeCnt -1

                dacsim::ExecClean [namespace current]
            }
        }
    }
}
