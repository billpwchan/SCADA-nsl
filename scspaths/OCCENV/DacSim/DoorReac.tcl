
# deo%19sDO%3sopen
# deoSITE1B001F001ACCESSDO001open

set l_Cmd $1
set l_Value $2
set l_Building $3
set l_Door $4

if { ( $l_Cmd != "%init%" ) } {
    puts "-----in DoorReac.tcl -----"
    puts "reac l_Cmd: $l_Cmd"
    puts "reac l_Value: $l_Value"
    puts "reac l_Building: $l_Building"
    puts "reac l_Door: $l_Door"
}

# exec command
switch $l_Cmd {
    %init% {
    }
    open {
        # move door
        #~ puts "Door moving"
        extvar set dei${l_Building}DO${l_Door}open 0
        extvar set dei${l_Building}DO${l_Door}close 0
        delay execution 3 {
            #~ puts "Door open"
            extvar set dei${l_Building}DO${l_Door}open 1
        }
    }
    close {
        # move door
        #~ puts "Door moving"
        extvar set dei${l_Building}DO${l_Door}open 0
        extvar set dei${l_Building}DO${l_Door}close 0
        delay execution 3 {
            #~ puts "Door closed"
            extvar set dei${l_Building}DO${l_Door}close 1
        }
    }
    
    unlock {
        puts "password $l_Value"
        
        set v [extvar get dei${l_Building}DO${l_Door}lock]
        if { $v == 0 } {
            extvar set dei${l_Building}DO${l_Door}lock 1
        } else {
            extvar set dei${l_Building}DO${l_Door}lock 0
        }
    }
}

#~ if { ( $l_Cmd != "%init%" ) } {
    #~ puts "-----end Door_reac -----"
#~ }
