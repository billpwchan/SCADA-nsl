# 

set l_Cmd $1
set l_Value $2
set l_Building $3
set l_Camera $4

if { ( $l_Cmd != "%init%" ) } {
    puts "-----in CameraReac.tcl -----"
    puts "reac l_Cmd: $l_Cmd"
    puts "reac l_Value: $l_Value"
    puts "reac l_Building: $l_Building"
    puts "reac l_Camera: $l_Camera"
}

# exec command
switch $l_Cmd {
    %init% {
    
    }
    on {
        # 
        extvar set dei${l_Building}CA${l_Camera}state 1
    }
    off {
        # 
        extvar set dei${l_Building}CA${l_Camera}state 0
    }
    angle {
        extvar set aei${l_Building}CA${l_Camera}angle $l_Value
    }
    zoom {
        extvar set aei${l_Building}CA${l_Camera}zoom $l_Value
    }
    recording {
        extvar set dei${l_Building}CA${l_Camera}rec $l_Value
    }
}

