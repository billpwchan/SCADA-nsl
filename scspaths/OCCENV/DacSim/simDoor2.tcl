global nbchange
set nbchange 0

global nbalarm
set nbalarm 0

global alarmThr
set alarmThr 1

proc changeEIV { ev val } {
  global nbchange
  
  if { $nbchange > 0 } {
    incr nbchange -1
    extvar set $ev $val
  }
}

proc setAlarm { ev } {
  global alarmThr
  global nbalarm
  
  set v [expr int(rand() * 100.0)]
  if { $v < $alarmThr } {
    incr nbalarm
    changeEIV ${ev} 1
  }
}

proc toggleDoor { bldnum dnum } {
  set curpos [extvar get deiB${bldnum}DO${dnum}open]
  if { $curpos == 1} {
    # close door
    changeEIV deiB${bldnum}DO${dnum}open 0
    changeEIV deiB${bldnum}DO${dnum}close 1
  } else {
    # open door
    changeEIV deiB${bldnum}DO${dnum}close 0
    changeEIV deiB${bldnum}DO${dnum}open 1
  }
}

proc modifyCamera { bldnum cnum } {
  set currec [extvar get deiB${bldnum}CA${cnum}rec]
  if { $currec == 1} {
    changeEIV deiB${bldnum}CA${cnum}rec 0
  } else {
    changeEIV deiB${bldnum}CA${cnum}rec 1
  }

  set curangle [extvar get aeiB${bldnum}CA${cnum}angle]
  changeEIV aeiB${bldnum}CA${cnum}angle [expr 1 + [clock seconds] % 60]
}

proc modifyAlarmCamera { bldnum cnum } {
  global alarmThr
  global nbalarm
  
  set curzoom [extvar get aeiB${bldnum}CA${cnum}zoom]
  
  if { $curzoom <= 10.0 || $curzoom >= 40.0 } {
    changeEIV aeiB${bldnum}CA${cnum}zoom [ expr int(rand() * 20.0) + 11 ]
  } else {
    set v [expr int(rand() * 100.0)]
    if { $v < $alarmThr } {
      incr nbalarm
      changeEIV aeiB${bldnum}CA${cnum}zoom [ expr int(rand() * 9.0) + 0.1]
    }
  }
}

# deiB${bldnum}FD057fault and  deiB${bldnum}FD057smoke
proc modifyFDet { bldnum cnum } {
  set curfault [extvar get deiB${bldnum}FD${cnum}fault]
  set curstate [extvar get deiB${bldnum}FD${cnum}smoke]
  
  if { $curfault == 0 } {
    setAlarm deiB${bldnum}FD${cnum}fault
  } else {
    changeEIV deiB${bldnum}FD${cnum}fault 0
  }
  
  if { $curstate == 0 } {
    setAlarm deiB${bldnum}FD${cnum}smoke
  } else {
    changeEIV deiB${bldnum}FD${cnum}smoke 0
  }
}

# deiB${bldnum}ID009fault and  deiB${bldnum}ID015state
proc modifyMotionDet { bldnum cnum } {
  set curfault [extvar get deiB${bldnum}ID${cnum}fault]
  set curstate [extvar get deiB${bldnum}ID${cnum}state]
  
  if { $curfault == 0 } {
    setAlarm deiB${bldnum}ID${cnum}fault
  } else {
    changeEIV deiB${bldnum}ID${cnum}fault 0
  }
  
  if { $curstate == 0 } {
    setAlarm deiB${bldnum}ID${cnum}state
  } else {
    changeEIV deiB${bldnum}ID${cnum}state 0
  }
}

# deiB${bldnum}SP009fault and  deiB${bldnum}SP015state
proc modifySprinkler { bldnum cnum } {
  set curfault [extvar get deiB${bldnum}SP${cnum}fault]
  set curstate [extvar get deiB${bldnum}SP${cnum}state]
  
  if { $curfault == 0 } {
    setAlarm deiB${bldnum}SP${cnum}fault
  } else {
    changeEIV deiB${bldnum}SP${cnum}fault 0
  }
  
  if { $curstate == 0 } {
    changeEIV deiB${bldnum}SP${cnum}state 1
  } else {
    changeEIV deiB${bldnum}SP${cnum}state 0
  }
}

while { 1 } {

  set nb [ extvar get deiSIMUEvtNum]
  set alarmThr [extvar get deiSIMUAlmThr]
  set delay [extvar get deiSIMUPeriod]

  set nbchange $nb
  set nbalarm 0
  
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
  
  puts "$nb $nbalarm EIV changed after $delay msec alm threshold $alarmThr"
  after $delay
}

