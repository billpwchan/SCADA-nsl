
# deoSITE1B001F001POWERVA002close
# deoSITE1B001F001POWERVA002open
# deoSITE1B001F001POWERVA002lock

set l_Cmd $1
set l_Value $2
set l_Building $3
set l_Valve $4

if { ( $l_Cmd != "%init%" ) } {
    puts "-----in ValveReac.tcl -----"
    puts "reac l_Cmd: $l_Cmd"
    puts "reac l_Value: $l_Value"
    puts "reac l_Building: $l_Building"
    puts "reac l_Valve: $l_Valve"
}

# exec command
switch $l_Cmd {
    %init% {
    }
    open {
        # move door
        
        extvar set dei${l_Building}VA${l_Valve}open 0
        extvar set dei${l_Building}VA${l_Valve}close 0
        delay execution 3 {
            
            extvar set dei${l_Building}VA${l_Valve}open 1
        }
    }
    close {
        # move door
       
        extvar set dei${l_Building}VA${l_Valve}open 0
        extvar set dei${l_Building}VA${l_Valve}close 0
        delay execution 3 {
           
            extvar set dei${l_Building}VA${l_Valve}close 1
        }
    }
    
    lock {
        extvar set dei${l_Building}VA${l_Valve}lock ${l_Value}
    }
}

if { ( $l_Cmd != "%init%" ) } {
   puts "-----end Valve_reac -----"
}
