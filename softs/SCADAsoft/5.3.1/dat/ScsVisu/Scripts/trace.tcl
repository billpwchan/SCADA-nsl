#
#
# ---- Trace Procedures
#
#

namespace eval ScsTrace {

variable currentTraceLevel
set currentChannelId stdout

proc TraceFunction { Level Message } {
    variable currentChannelId
    
    puts $currentChannelId [format "\[%d\] ScsVisu %s (%s) <<%s>>" $Level [clock format [clock seconds] -format "%m/%d/%y %H:%M:%S"] [info level 1] $Message]    
}

proc SetTrace { LevelMask } {
    variable currentTraceLevel
    for {set i 0} {$i < 32} {incr i} {
	set currentTraceLevel($i) [expr $LevelMask & [expr 1 << $i]]
    }
}

proc Trace { Level Format args } {
    variable currentTraceLevel
    if {[info exists currentTraceLevel($Level)] && $currentTraceLevel($Level)} {
        set erreur [ catch { TraceFunction $Level [eval {format $Format} $args] } erreurtxt ]
        if {$erreur == 1} {
          set message "ScsTrace::Trace failed: $erreurtxt"
          TraceFunction 1 [eval {format $message} $args]
        }
    }    
}

proc SetLogFile { ChannelId } {
    variable currentChannelId
    set currentChannelId $ChannelId
}

}