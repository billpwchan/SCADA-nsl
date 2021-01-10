
# deo%4sSP%3soff
# deoB001SP001off

set l_Cmd $1
set l_Value $2
set l_Building $3
set l_SPK $4

if { ( $l_Cmd != "%init%" ) } {
    puts "-----in SprinklerReac.tcl -----"
    puts "reac l_Cmd: $l_Cmd"
    puts "reac l_Value: $l_Value"
    puts "reac l_Building: $l_Building"
    puts "reac l_SPK: $l_SPK"
}

# exec command
switch $l_Cmd {
    %init% {
    }
    on {
        # 
        extvar set dei${l_Building}SP${l_SPK}state 1
    }
    off {
        # 
        extvar set dei${l_Building}SP${l_SPK}state 0
    }
}

