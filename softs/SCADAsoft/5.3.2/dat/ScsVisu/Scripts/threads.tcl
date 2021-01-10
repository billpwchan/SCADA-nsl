############################################
#
# --- TCL threads cleaning
#
############################################

if {[info commands Threads] != {}} {
	variable MainThread [Threads id]
}

proc ::ThreadsReap {} {
    if {[info commands Threads] != {}} {

	variable MainThread
	Threads errorproc ThreadNullError
	while {[llength [Threads names]] > 1} {
	    foreach tid [Threads names] {
		if {$tid != $MainThread} {
		    catch {Threads send -async $tid {Threads exit}}
		}
	    }
	    ## Enter a bit a sleep to give the threads enough breathing
	    ## room to kill themselves off, otherwise the end up with a
	    ## massive queue of repeated events
	    after 1
	}
	Threads errorproc ThreadError
	return [llength [Threads names]]
    }
}

