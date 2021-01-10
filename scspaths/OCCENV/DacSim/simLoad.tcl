source common.tcl
set i 0

while { 1 } {
  incr i
  set nb [ extvar get deiSIMUEvtNum*]
  set alarmThr [extvar get deiSIMUAlmThr*]
  set delay [extvar get deiSIMUPeriod*]

  set nbchange $nb
  set nbalarm 0
  set eivList {}
  
  while { $nbchange > 0 } {
    # always modify CAM001 to see image refresh
    modifyCamera "001" "001"
    set bldnum [format "%03d" [expr int(rand() * 5 + 1)]]
  
    # move some doors
    set dnum [format "%03d" [expr int(rand() * 100 + 1)]]
    toggleDoor $bldnum $dnum

    # modify firedetector
    set cnum [format "%03d" [expr int(rand() * 100 + 1)]]
    modifyFDet $bldnum $cnum
    
    # modify camera
    set cnum [format "%03d" [expr int(rand() * 100 + 1)]]
    modifyCamera $bldnum $cnum
    set cnum [format "%03d" [expr int(rand() * 100 + 1)]]
    modifyAlarmCamera $bldnum $cnum
  
    # modify motion detector
    set cnum [format "%03d" [expr int(rand() * 100 + 1)]]
    modifyMotionDet $bldnum $cnum
  
    # modify sprinkler
    set cnum [format "%03d" [expr int(rand() * 100 + 1)]]
    modifySprinkler $bldnum $cnum
  }
  
  setGroup $eivList
  #~ puts "\[$i\] $nb $nbalarm EIV changed after $delay msec alm threshold $alarmThr"
  after $delay
}

