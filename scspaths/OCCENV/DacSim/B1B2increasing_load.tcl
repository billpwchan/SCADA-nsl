source common.tcl

# increase nbchange by step when count is 0
set step 2
set period 10
set count $period

set nb 0
set alarmThr 0
set delay 1000

set i 0

while { 1 } {
  incr i
  set count [ expr $count - 1 ]

  if { $count == 0 } {
    incr nb $step
    set count $period
  }
  set nbchange $nb
  set nbalarm 0
  set eivList {}
  
  while { $nbchange > 0 } {
    set bldnum [format "%03d" [expr int(rand() * 2 + 1)]]
  
    # move some doors
    set dnum [format "%03d" [expr int(rand() * 100 + 1)]]
    toggleDoor $bldnum $dnum

    # modify camera
    set cnum [format "%03d" [expr int(rand() * 100 + 1)]]
    modifyCamera $bldnum $cnum
    set cnum [format "%03d" [expr int(rand() * 100 + 1)]]
    modifyAlarmCamera $bldnum $cnum
  
    # modify firedetector
    set cnum [format "%03d" [expr int(rand() * 100 + 1)]]
    modifyFDet $bldnum $cnum

    # modify motion detector
    set cnum [format "%03d" [expr int(rand() * 100 + 1)]]
    modifyMotionDet $bldnum $cnum
  
    # modify sprinkler
    set cnum [format "%03d" [expr int(rand() * 100 + 1)]]
    modifySprinkler $bldnum $cnum
  }
  
  setGroup $eivList
  puts "\[$i\] $nb EIV changed after $delay msec"
  after $delay
}

