source common.tcl

# close all doors
extvar set deiB*DO*open 0
extvar set deiB*DO*close 1

# start simu
set buildingNum 1
set doorNum 0
set delay 1000

while { 1 } {
  set eivList {}
  incr doorNum
  set nbchange 2
  if { $doorNum == 101 } {
    set doorNum 1
    incr buildingNum
    
    if { $buildingNum == 6 } {
        set buildingNum 1
    }
  }
  
  toggleDoor [format "%03d" $buildingNum] [format "%03d" $doorNum]
  
  setGroup $eivList
  after $delay
}

