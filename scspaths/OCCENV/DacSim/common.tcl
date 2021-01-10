global nbchange
set nbchange 0

global nbalarm
set nbalarm 0

global alarmThr
set alarmThr 1

global eivList
set eivList {}

proc changeEIV { ev val } {
  global nbchange
  global eivList
  
  if { $nbchange > 0 } {
    incr nbchange -1
    lappend eivList [subst {$ev $val }]
  }
}

proc getFloor { dnum } {
  set fnum [format "%03d" [expr 1 + ([string trimleft $dnum 0] - 1)/ 10]]
  return $fnum
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

# deiSITE1B001F001ACCESSDO001open
# deiSITE1B001F001ACCESSDO001close
proc toggleDoor { bldnum dnum } {
  global nbchange
  set flrnum [getFloor $dnum]
  
  set curpos [extvar get deiSITE1B${bldnum}F${flrnum}ACCESSDO${dnum}open]
  if { $curpos == 1} {
    # close door
    if { $nbchange > 0 } {
        changeEIV deiSITE1B${bldnum}F${flrnum}ACCESSDO${dnum}open 0
        incr nbchange
        changeEIV deiSITE1B${bldnum}F${flrnum}ACCESSDO${dnum}close 1
    }
  } else {
    # open door
    if { $nbchange > 0 } {
        changeEIV deiSITE1B${bldnum}F${flrnum}ACCESSDO${dnum}close 0
        incr nbchange
        changeEIV deiSITE1B${bldnum}F${flrnum}ACCESSDO${dnum}open 1
    }
  }
}

# aeiSITE1B001F001CCTVCA001angle
proc rotateCamera { bldnum cnum } {
  set flrnum [getFloor $cnum]
  
  set curangle [extvar get aeiSITE1B${bldnum}F${flrnum}CCTVCA${cnum}angle]
  changeEIV aeiSITE1B${bldnum}F${flrnum}CCTVCA${cnum}angle [expr (int($curangle) + 10 ) % 360]
}

# deiSITE1B001F007CCTVCA064rec
proc modifyCamera { bldnum cnum } {
  set flrnum [getFloor $cnum]
  
  set currec [extvar get deiSITE1B${bldnum}F${flrnum}CCTVCA${cnum}rec]
  if { $currec == 1} {
    changeEIV deiSITE1B${bldnum}F${flrnum}CCTVCA${cnum}rec 0
  } else {
    changeEIV deiSITE1B${bldnum}F${flrnum}CCTVCA${cnum}rec 1
  }

  set curangle [extvar get aeiSITE1B${bldnum}F${flrnum}CCTVCA${cnum}angle]
  changeEIV aeiSITE1B${bldnum}F${flrnum}CCTVCA${cnum}angle [expr 1 + [clock seconds] % 60]
}

proc modifyAlarmCamera { bldnum cnum } {
  global alarmThr
  global nbalarm
  
  set flrnum [getFloor $cnum]
  
  set curzoom [extvar get aeiSITE1B${bldnum}F${flrnum}CCTVCA${cnum}zoom]
  
  if { $curzoom <= 10.0 || $curzoom >= 40.0 } {
    changeEIV aeiSITE1B${bldnum}F${flrnum}CCTVCA${cnum}zoom [ expr int(rand() * 20.0) + 11 ]
  } else {
    set v [expr int(rand() * 100.0)]
    if { $v < $alarmThr } {
      incr nbalarm
      changeEIV aeiSITE1B${bldnum}F${flrnum}CCTVCA${cnum}zoom [ expr int(rand() * 9.0) + 0.1]
    }
  }
}

# deiB${bldnum}FD057fault and  deiB${bldnum}FD057smoke
proc modifyFDet { bldnum cnum } {
  set flrnum [getFloor $cnum]
  
  set curfault [extvar get deiSITE1B${bldnum}F${flrnum}FIREFD${cnum}fault]
  set curstate [extvar get deiSITE1B${bldnum}F${flrnum}FIREFD${cnum}smoke]
  
  if { $curfault == 0 } {
    setAlarm deiSITE1B${bldnum}F${flrnum}FIREFD${cnum}fault
  } else {
    changeEIV deiSITE1B${bldnum}F${flrnum}FIREFD${cnum}fault 0
  }
  
  if { $curstate == 0 } {
    setAlarm deiSITE1B${bldnum}F${flrnum}FIREFD${cnum}smoke
  } else {
    changeEIV deiSITE1B${bldnum}F${flrnum}FIREFD${cnum}smoke 0
  }
}

proc toggleFireDet { bldnum cnum } {
  set flrnum [getFloor $cnum]
  
  set curstate [extvar get deiSITE1B${bldnum}F${flrnum}FIREFD${cnum}smoke]
  
  if { $curstate == 0 } {
    changeEIV deiSITE1B${bldnum}F${flrnum}FIREFD${cnum}smoke 1
  } else {
    changeEIV deiSITE1B${bldnum}F${flrnum}FIREFD${cnum}smoke 0
  }
}

# deiB${bldnum}ID009fault and  deiB${bldnum}ID015state
proc modifyMotionDet { bldnum cnum } {
  set flrnum [getFloor $cnum]
  
  set curfault [extvar get deiSITE1B${bldnum}F${flrnum}ACCESSID${cnum}fault]
  set curstate [extvar get deiSITE1B${bldnum}F${flrnum}ACCESSID${cnum}state]
  
  if { $curfault == 0 } {
    setAlarm deiSITE1B${bldnum}F${flrnum}ACCESSID${cnum}fault
  } else {
    changeEIV deiSITE1B${bldnum}F${flrnum}ACCESSID${cnum}fault 0
  }
  
  if { $curstate == 0 } {
    setAlarm deiSITE1B${bldnum}F${flrnum}ACCESSID${cnum}state
  } else {
    changeEIV deiSITE1B${bldnum}F${flrnum}ACCESSID${cnum}state 0
  }
}

proc toggleMotionDet { bldnum cnum } {
  set flrnum [getFloor $cnum]
  
  set curstate [extvar get deiSITE1B${bldnum}F${flrnum}ACCESSID${cnum}state]
  
  if { $curstate == 0 } {
    changeEIV deiSITE1B${bldnum}F${flrnum}ACCESSID${cnum}state 1
  } else {
    changeEIV deiSITE1B${bldnum}F${flrnum}ACCESSID${cnum}state 0
  }
}

# deiB${bldnum}SP009fault and  deiB${bldnum}SP015state
proc modifySprinkler { bldnum cnum } {
  set flrnum [getFloor $cnum]
  
  set curfault [extvar get deiSITE1B${bldnum}F${flrnum}FIRESP${cnum}fault]
  set curstate [extvar get deiSITE1B${bldnum}F${flrnum}FIRESP${cnum}state]
  
  if { $curfault == 0 } {
    setAlarm deiSITE1B${bldnum}F${flrnum}FIRESP${cnum}fault
  } else {
    changeEIV deiSITE1B${bldnum}F${flrnum}FIRESP${cnum}fault 0
  }
  
  if { $curstate == 0 } {
    changeEIV deiSITE1B${bldnum}F${flrnum}FIRESP${cnum}state 1
  } else {
    changeEIV deiSITE1B${bldnum}F${flrnum}FIRESP${cnum}state 0
  }
}

proc toggleSprinkler { bldnum cnum } {
  set flrnum [getFloor $cnum]
  
  set curstate [extvar get deiSITE1B${bldnum}F${flrnum}FIRESP${cnum}state]
  
  if { $curstate == 0 } {
    changeEIV deiSITE1B${bldnum}F${flrnum}FIRESP${cnum}state 1
  } else {
    changeEIV deiSITE1B${bldnum}F${flrnum}FIRESP${cnum}state 0
  }
}

set r [info commands DacSimExtVarGroupSet]
if { [string compare "$r" "DacSimExtVarGroupSe" ] } {
    puts "extvar groupset simulated"
    proc setGroup { eivList } {
      foreach eiv $eivList { 
        extvar set [lindex $eiv 0] [lindex $eiv 1] 
      }
    }
} else {
    puts "extvar groupset can be used"
    proc setGroup { eivList } {
      extvar groupset $eivList 
    }
}
