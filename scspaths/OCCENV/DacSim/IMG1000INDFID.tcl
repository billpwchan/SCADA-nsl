source common.tcl

# initial state
extvar set dei*ID*fault 0
extvar set dei*ID*state 0

# increase nbchange by step when count is 0
set step 50
set period 300
set count 1
set maxcount 501

set nb 0
set alarmThr 0
set delay 1000

# start simu
set buildingNum 1
set indNum 0

set i 0

while { 1 } {
  incr i
  set count [ expr $count - 1 ]

  if { $count == 0 } {
    incr nb $step
    if { $nb > $maxcount } {
        set step [expr $step * -1]
    }
    if { $nb <= 0 } {
        set step [expr $step * -1]
    }
    set count $period
  }
  set nbchange $nb
  set nbalarm 0
  set eivList {}
  
  set buildingNum 1
  set indNum 0

  while { $nbchange > 0 } {
    incr indNum
    
    if { $indNum == 101 } {
        set indNum 1
        incr buildingNum

        if { $buildingNum == 6 } {
            set buildingNum 1
        }
    }
   
    toggleMotionDet [format "%03d" $buildingNum] [format "%03d" $indNum]
    
  }
  
  setGroup $eivList
  puts "\[$i\] $nb EIV changed after $delay msec"
  after $delay
}

