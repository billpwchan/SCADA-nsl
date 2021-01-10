source common.tcl

# initial state
# close all doors
extvar set dei*DO*fault 0
extvar set dei*DO*open 0
extvar set dei*DO*close 1
extvar set dei*DO*lock 1
# reset cam
extvar set dei*CA*fault 0
extvar set dei*CA*state 1
extvar set dei*CA*rec 0
extvar set aei*CA*angle 45
extvar set aei*CA*zoom 25

# increase nbchange by step when count is 0
set step 40
set period 300
set count 1
set maxcount 501

set nb 0
set alarmThr 0
set delay 1000

# start simu
set buildingNum 1
set doorNum 0
set camNum 0

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
  set doorNum 0
  set camNum 0

  while { $nbchange > 0 } {
    incr doorNum
    incr camNum
    if { $doorNum == 101 } {
        set doorNum 1
        set camNum 1
        incr buildingNum

        if { $buildingNum == 6 } {
            set buildingNum 1
        }
    }
   
    toggleDoor [format "%03d" $buildingNum] [format "%03d" $doorNum]
    rotateCamera [format "%03d" $buildingNum] [format "%03d" $camNum]
  }
  
  setGroup $eivList
  puts "\[$i\] $nb EIV changed after $delay msec"
  after $delay
}

