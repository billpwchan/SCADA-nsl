source common.tcl

while { 1 } {

  set nb 200
  set alarmThr 0
  set delay 1000

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
  after $delay
}

