######################
# ETCDS Section command  #
######################
#deoSITE1B001F001POWERSE002enable
# deo%18sSE%3senable: ETCDSSectionReac enable
# deoSITE1B001F001POWERSE002reset
# deo%18sSE%3sreset: ETCDSSectionReac reset
# deoSITE1B001F001POWERSE002switch
# deo%18sSE%3sswitch: ETCDSSectionReac mode
# deoSITE1B001F001POWERSE002trip
# deo%18sSE%3strip: ETCDSSectionReac trip

set l_Cmd $1
set l_Value $2
set l_EqpLoc $3
set l_Section $4

if { ( $l_Cmd != "%init%" ) } {
    puts "-----in ETCDSSectionReac.tcl -----"
    puts "reac l_Cmd: $l_Cmd"
    puts "reac l_Value: $l_Value"
    puts "reac l_EqpLoc: $l_EqpLoc"
    puts "reac l_Section: $l_Section"
}

# exec command
switch $l_Cmd {
    %init% {
    }
    enable {
        # 
        delay execution 1 {
          extvar set dei${l_EqpLoc}SE${l_Section}enable ${l_Value}
        }
    }
    reset {
        # 
        delay execution 1 {
          extvar set dei${l_EqpLoc}SE${l_Section}reset ${l_Value}
        }
    }
    mode {
        # 
        delay execution 1 {
          extvar set dei${l_EqpLoc}SE${l_Section}switch ${l_Value}
        }
    }
    trip {
        # 
        delay execution 1 {
          extvar set dei${l_EqpLoc}SE${l_Section}state ${l_Value}
        }
    }
}

