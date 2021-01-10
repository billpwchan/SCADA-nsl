
# deoSIMU%s

set l_Cmd $1
set l_Value $2
set l_Var $3

if { ( $l_Cmd != "%init%" ) } {
    puts "-----in simu.tcl -----"
    puts "reac l_Cmd: $l_Cmd"
    puts "reac l_Value: $l_Value"
    puts "reac l_Var: $l_Var"
}

# exec command
switch $l_Cmd {
    %init% {
    }
    set {
       
        extvar set deiSIMU${l_Var} $l_Value
       
    }
}

#~ if { ( $l_Cmd != "%init%" ) } {
    #~ puts "-----end Door_reac -----"
#~ }
