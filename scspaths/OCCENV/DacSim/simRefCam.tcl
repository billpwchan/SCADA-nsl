
set timeDelayMs 1000

source simCommon.tcl
#------------------------------------------------------------
# Declare EIV

set velist { aeiSITE1B001F001CCTVCA001angle }

global measureMap

#  Measure Object  list of { baseValue range step printformat currentValue }

foreach ve $velist {
    set v [expr $pi * rand()]
    set measureMap($ve) [list 180 180 [expr 0.01 * rand()] "%06.2f" $v ]
}

proc nextVal { p } {
  global measureMap
  
  set b [lindex $measureMap($p) 0]
  set r [lindex $measureMap($p) 1]
  set s [lindex $measureMap($p) 2]
  set f [lindex $measureMap($p) 3]
  set v [lindex $measureMap($p) 4]
  
  set v [ expr $v + $s]
  
  set measureMap($p) [list $b $r $s $f $v]
  
  set nv [expr $b + $r * sin($v) ]
  
  set ret $nv
  
  return $ret
}

#------------------------------------------------------------
# Main loop
while { 1 } {
  foreach n [ array names measureMap] {
    set nv [nextVal $n]
    extvar set $n $nv
  }
  after $timeDelayMs
}