
set l_Cmd $1
set l_Value $2
set l_Building $3
set l_RTUID $4

# deoSITE1%4sF000SYSTEM%5sspy: daccomreac spy
# deoSITE1%4sF000SYSTEM%5scomsta: daccomreac state


if { ( $l_Cmd != "%init%" ) } {
    puts "-----in daccomreac.tcl -----"
    puts "reac l_Cmd: $l_Cmd"
    puts "reac l_Value: $l_Value"
    puts "reac l_Building: $l_Building"
    puts "reac l_RTUID: $l_RTUID"
}

# exec command
switch $l_Cmd {
    %init% {
    }
    spy {
        # spy  deiSITE1B003F000SYSTEMRT003spy
        extvar set deiSITE1${l_Building}F000SYSTEM${l_RTUID}spy $l_Value
    }
    state {
        set curstate [ extvar get deiSITE1${l_Building}F000SYSTEM${l_RTUID}comsta ]
        
        if { $curstate != $l_Value } {
            # state deiSITE1B003F000SYSTEMRT003comsta
            if { $l_Value == 3 } {
                source ReacInit.tcl
            } else {
                extvar set deiSITE1${l_Building}F000SYSTEM${l_RTUID}comsta $l_Value
            }
        }
    }
}
