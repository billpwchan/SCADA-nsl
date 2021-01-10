source common.tcl

# initial state
extvar set dei*SP*fault 0
extvar set dei*SP*state 0

# increase nbchange by step when count is 0
set step 10
set period 300
set count 1
set maxcount 501

set nb 0
set alarmThr 0
set delay 1000

# start simu
set buildingNum 1
set spkNum 0

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
  set spkNum 0
 
  while { $nbchange > 0 } {
    incr spkNum
    
    if { $spkNum == 101 } {
        set spkNum 1
        incr buildingNum

        if { $buildingNum == 6 } {
            set buildingNum 1
        }
    }
   
    toggleSprinkler [format "%03d" $buildingNum] [format "%03d" $spkNum]
  }
  
  setGroup $eivList
  puts "\[$i\] $nb EIV changed after $delay msec"
  after $delay
}

