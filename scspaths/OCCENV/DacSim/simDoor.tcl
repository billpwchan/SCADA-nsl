
set timeDelayMs 2000
set vePrefix "deiB001DO"
set NbDoorPerStep 2

source simCommon.tcl
#------------------------------------------------------------
# Main loop
while { 1 } {

  for {set i 0 } {$i < $NbDoorPerStep} {incr i} {
    set door [ format "%03d" [ RandomInteger 1 999]]
    
    extvar set ${vePrefix}${door}close 0
    extvar set ${vePrefix}${door}open 1
    
  }

  after $timeDelayMs
  
  for {set i 0 } {$i < $NbDoorPerStep} {incr i} {
    set door [ format "%03d" [ RandomInteger 1 999]]
    
    extvar set ${vePrefix}${door}close 1
    extvar set ${vePrefix}${door}open 0
    
  }

  after $timeDelayMs
}

