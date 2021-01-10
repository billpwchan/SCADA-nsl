#####################################################################
# Constants for the parsing of the ScsEnvTable.
#####################################################################

global DEFINE_ENV ;             set DEFINE_ENV "Define Environment"
global DEFINE_SERVER ;          set DEFINE_SERVER "Define Server"

global PHASE ;                  set PHASE "Phase"
global PHASE_DEFAULT ;          set PHASE_DEFAULT "0"

global TERMINATION ;            set TERMINATION "Termination"
global TERMINATION_VALUES ;     set TERMINATION_VALUES { NONE SHUTDOWN RETRY }
global TERMINATION_DEFAULT ;    set TERMINATION_DEFAULT "NONE"

global SNAPSHOT ;               set SNAPSHOT "Snapshot"
global SNAPSHOT_VALUES ;        set SNAPSHOT_VALUES { NONE BACKGROUND FOREGROUND }
global SNAPSHOT_DEFAULT ;       set SNAPSHOT_DEFAULT "NONE"

global NOTIFICATION ;           set NOTIFICATION "Notification"
global NOTIFICATION_VALUES ;    set NOTIFICATION_VALUES { YES NO }
global NOTIFICATION_DEFAULT ;   set NOTIFICATION_DEFAULT "NO"

global SHUTDOWN_ORDER ;         set SHUTDOWN_ORDER "Shutdown order"
global SHUTDOWN_ORDER_DEFAULT ; set SHUTDOWN_ORDER_DEFAULT "LAST"

global SUPERVISION ;            set SUPERVISION "Supervision"
global SUPERVISION_VALUES ;     set SUPERVISION_VALUES { NONE CORBA RTAP UNIX PUSH }
global SUPERVISION_DEFAULT ;    set SUPERVISION_DEFAULT "NONE"

global PRIORITY ;               set PRIORITY "Priority"
global PRIORITY_VALUES ;        set PRIORITY_VALUES { HIGHEST ABOVE_NORMAL NORMAL BELOW_NORMAL LOWEST }
global PRIORITY_DEFAULT ;       set PRIORITY_DEFAULT "NORMAL"

global INIT_TIMEOUT ;           set INIT_TIMEOUT "Init timeout"
global INIT_TIMEOUT_DEFAULT ;   set INIT_TIMEOUT_DEFAULT "15"

global SHUTDOWN_TIMEOUT ;       set SHUTDOWN_TIMEOUT "Shutdown timeout"
global SHUTDOWN_TIMEOUT_DEFAULT ; set SHUTDOWN_TIMEOUT_DEFAULT "10"

global PROCESSOR ;              set PROCESSOR "Processor"
global PROCESSOR_DEFAULT ;      set PROCESSOR_DEFAULT "-1"

global RUN_STRING ;             set RUN_STRING "Run string"
global RUN_STRING_DEFAULT ;     set RUN_STRING_DEFAULT ""

global SET_Filename
set    SET_Filename ""

global ListServers
set    ListServers {}


#####################################################################
# Match if the word in parameter match the define server
#####################################################################
proc MatchDefineServer { pWord } {
    global DEFINE_SERVER
    
    set l_word [string range $pWord 0 [expr [string length "$DEFINE_SERVER"] - 1]]
    if { ![string compare $l_word "$DEFINE_SERVER"] } {
        return 1
    } else {
        return 0
    }
}

#####################################################################
# Match if the word in parameter match the define Env
#####################################################################
proc MatchDefineEnv { pWord } {
    global DEFINE_ENV

    if { ![string compare $pWord $DEFINE_ENV] } {
        return 1
    } else {
        return 0
    }
}

#####################################################################
# Match if the word in parameter is correct.
#####################################################################
proc MatchWord { pWord } {
    global PHASE
    global TERMINATION
    global SNAPSHOT
    global NOTIFICATION
    global SHUTDOWN_ORDER
    global SHUTDOWN_TIMEOUT
    global SUPERVISION
    global PRIORITY
    global INIT_TIMEOUT
    global PROCESSOR
    global RUN_STRING
    
    set l_Words [subst { {$PHASE} {$TERMINATION} {$SNAPSHOT} {$NOTIFICATION} {$SHUTDOWN_ORDER} {$SHUTDOWN_TIMEOUT} {$SUPERVISION} {$PRIORITY} {$INIT_TIMEOUT} {$PROCESSOR} {$RUN_STRING} } ]
    for {set i 0} {$i < [llength $l_Words]} {incr i} {
        if { ![string compare $pWord [lindex $l_Words $i]]} { 
            return 1
        }
    }
    
    return 0
}

#####################################################################
# Match if the word in parameter has the correct value.
# return values :
#       0 : no word matched
#       1 : word AND value matched
#       2 : word matched BUT no value matched
#####################################################################
proc MatchValue { pWord pValue } {

    global TERMINATION
    global TERMINATION_VALUES
    global SNAPSHOT
    global SNAPSHOT_VALUES
    global NOTIFICATION
    global NOTIFICATION_VALUES
    global SUPERVISION
    global SUPERVISION_VALUES
    global PRIORITY
    global PRIORITY_VALUES
    global PHASE
    global RUN_STRING
    global INIT_TIMEOUT
    global PROCESSOR
    global SHUTDOWN_ORDER
    global SHUTDOWN_ORDER_DEFAULT
    global SHUTDOWN_TIMEOUT
    global SHUTDOWN_TIMEOUT_DEFAULT
    
    set l_Words [subst { {$TERMINATION} {$SNAPSHOT} {$NOTIFICATION} {$SUPERVISION} {$PRIORITY} }]
    set l_Values [subst { {$TERMINATION_VALUES} {$SNAPSHOT_VALUES} {$NOTIFICATION_VALUES} {$SUPERVISION_VALUES} {$PRIORITY_VALUES} } ]

    for {set l_index_word 0} {$l_index_word < [llength $l_Words]} {incr l_index_word} {
        if { ![string compare $pWord [lindex $l_Words $l_index_word]] } {
            for {set l_index_value 0} { $l_index_value < [llength [lindex $l_Values $l_index_word]]} {incr l_index_value} {
                if { ![string compare $pValue [lindex [lindex $l_Values $l_index_word] $l_index_value]] } {
                    return 1
                }
            }
            return 2
        }
    }
    
    # particular cases
    set l_Words [subst { {$PHASE} {$INIT_TIMEOUT} {$PROCESSOR} {$SHUTDOWN_TIMEOUT}}]
    for {set l_index_word 0} {$l_index_word < [llength $l_Words]} {incr l_index_word} {
        if { ![string compare $pWord [lindex $l_Words $l_index_word]] } {
            if { [string is integer -strict $pValue] == 1} {
                return 1
            } else {
                return 2
            }
        }
    }
    
    # RUN_STRING
    if { ![string compare $pWord $RUN_STRING]} {
        return 1
    }
    
    # SHUTDOWN_ORDER
    if { ![string compare $pWord "$SHUTDOWN_ORDER"] } {
        if { [string is integer -strict $pValue] == 1} {
            return 1
        } elseif { ![string compare $pValue $SHUTDOWN_ORDER_DEFAULT] } {
            return 1
        } elseif { [string match "*$SHUTDOWN_ORDER_DEFAULT*" $pValue] == 1 } {
            set l_parts [split $pValue "-"]
            if { [llength $l_parts] != 2} {
                return 2
            } else {
                if { ![string compare [string trim [lindex $l_parts 0]] $SHUTDOWN_ORDER_DEFAULT] } {
                    if { [string is integer -strict [string trim [lindex $l_parts 1]]] == 1} {
                        return 1
                    } else {
                        return 2
                    }
                } else {
                    return 2
                }
            }
        } else {
            return 2
        }
    }
    
    return 0
}

#####################################################################
# Get the server name of the "define Server" line
#####################################################################
proc GetServerName { pLine } {
    global DEFINE_SERVER
    
    set l_servername [string range $pLine [expr [string length "$DEFINE_SERVER"] + 1] [string length $pLine]]
    set l_servername [string range $l_servername 1 [expr [string length $l_servername] - 2]]
    return $l_servername
}

#####################################################################
# Get the parts of the line
#####################################################################
proc GetPartsOfLine { pLine } {
    set l_parts [split $pLine "="]
    set l_part1 [string trim [lindex $l_parts 0]]
    set l_part2 [string trim [lindex $l_parts 1]]
    
    return [list $l_part1 $l_part2]
}

#####################################################################
# Find if a word exists in the server item
#####################################################################
proc FindIndexWordInServerItem { pServerItem pWord } {

    set l_count [llength $pServerItem]
    for {set i 1} {$i < $l_count} {incr i} {
        if { ![string compare $pWord [lindex [lindex $pServerItem $i] 0]] } {
            return $i
        }
    }
    
    return -1
}

#####################################################################
# Reorder the list and complete with default values
#####################################################################
proc ReOrderAndCompleteListServers {} {
    global ListServers

    global DEFINE_SERVER
    global PHASE
    global PHASE_DEFAULT
    global TERMINATION
    global TERMINATION_DEFAULT
    global SNAPSHOT
    global SNAPSHOT_DEFAULT
    global NOTIFICATION
    global NOTIFICATION_DEFAULT
    global SHUTDOWN_ORDER
    global SHUTDOWN_ORDER_DEFAULT
    global SHUTDOWN_TIMEOUT
    global SHUTDOWN_TIMEOUT_DEFAULT
    global SUPERVISION
    global SUPERVISION_DEFAULT
    global PRIORITY
    global PRIORITY_DEFAULT
    global INIT_TIMEOUT
    global INIT_TIMEOUT_DEFAULT
    global PROCESSOR
    global PROCESSOR_DEFAULT
    global RUN_STRING
    global RUN_STRING_DEFAULT

    set l_Words [subst { {$PHASE} {$TERMINATION} {$SNAPSHOT} {$NOTIFICATION} {$SHUTDOWN_ORDER} {$SUPERVISION} {$PRIORITY} {$INIT_TIMEOUT} {$SHUTDOWN_TIMEOUT} {$PROCESSOR} {$RUN_STRING} }]
    set l_nbWords [llength $l_Words]
    set l_DefaultValues [subst { {$PHASE_DEFAULT} {$TERMINATION_DEFAULT} {$SNAPSHOT_DEFAULT} {$NOTIFICATION_DEFAULT} {$SHUTDOWN_ORDER_DEFAULT} {$SUPERVISION_DEFAULT} {$PRIORITY_DEFAULT} {$INIT_TIMEOUT_DEFAULT} {$SHUTDOWN_TIMEOUT_DEFAULT} {$PROCESSOR_DEFAULT} {$RUN_STRING_DEFAULT} }]
    
    set ReOrderedList {}
    set l_count [llength $ListServers]
    
    for {set i 0} {$i < $l_count} {incr i} {
        set l_newServerItem {}
        set l_serverItem [lindex $ListServers $i]
        lappend l_newServerItem [list [lindex $l_serverItem 0]]
        
        for {set j 0} {$j < $l_nbWords} {incr j} {
            set l_index [FindIndexWordInServerItem $l_serverItem [lindex $l_Words $j]]
            
            if { $l_index == -1} {
                lappend l_newServerItem [list [lindex $l_Words $j] [lindex $l_DefaultValues $j]]
            } else {
                lappend l_newServerItem [lindex $l_serverItem $l_index]
            }
        }
        
        lappend ReOrderedList $l_newServerItem
    }
    
    set ListServers $ReOrderedList
}


#####################################################################
# Read the ScsEnvTable file in parameter
#####################################################################
proc ReadEnvTable { pFileName } {
    global ListServers
    set ListServers {}

    set fileId [open $pFileName r]
    
    set l_init_define_env 0
    set l_init_define_server 0
    set l_index_servers -1
    
    set l_serverItem {}
    
    while { [gets $fileId line] !=-1 } {
        if { [string compare $line ""] == 0 } {
            continue
        }
        
        if { [string index $line 0] == "#" } {
            continue
        }
        
        set line [string trim $line]
        set line [string trim $line]
        set line [string trim $line "\{"]
        set line [string trim $line]
        
        if { $l_init_define_env == 0 } {
            set l_init_define_env [MatchDefineEnv $line]
            continue
        }
    
        if { $l_init_define_server == 0 } {
            set l_init_define_server [MatchDefineServer $line]
            if { $l_init_define_server == 0 } {
                continue
            } else {
                incr l_index_servers
                set l_serverName [GetServerName $line]
                set l_serverItem [list $l_serverName]
                continue
            }       
        }
        
        if { ![string compare $line "\}"]} {
            set l_init_define_server 0
            lappend ListServers $l_serverItem
            continue
        }
        
        set l_parts [GetPartsOfLine $line]
        set l_matchWord [MatchWord [lindex $l_parts 0]]
        if { $l_matchWord == 0} {
            puts "--- (MatchWord) Parsing error with ([lindex $l_parts 0]) in server ($l_serverName)"
            break
        }
        
        set l_matchValue [MatchValue [lindex $l_parts 0] [lindex $l_parts 1]]
        if { $l_matchValue == 2} {
            puts "--- (MatchValue) Parsing error with the value ([lindex $l_parts 1]) of ([lindex $l_parts 0]) in server ($l_serverName)"
            break
        } elseif { $l_matchValue == 0 } {
            puts "--- (MatchValue) Parsing error with ([lindex $l_parts 0]) in server ($l_serverName)"
            break
        } else {
            lappend l_serverItem $l_parts
        }
    }
    
    close $fileId

    ReOrderAndCompleteListServers
}



    

#####################################################################
# Print the list of servers
#####################################################################
proc PrintEnvTable {} {
    global ListServers

    set count [llength $ListServers]
    puts "-------------------------------------- \nNumber of valid servers = $count"
    
    for {set i 0} {$i < $count } {incr i} {
        set l_serverItem [lindex $ListServers $i]
        puts "Name = [lindex $l_serverItem 0]"
        for {set j 1} {$j<[llength $l_serverItem]} {incr j} {
            set l_line [lindex $l_serverItem $j]
            puts "\t[lindex $l_line 0]=[lindex $l_line 1]"
        }
    }
}


#####################################################################
# Returns the value if exists in server informations, "" otherwise
#####################################################################
proc CheckIfValueExists { pServerItem pWord} {

    set l_count [llength $pServerItem]
    
    for {set i 1} {$i<$l_count} {incr i} {
        if { ![string compare $pWord [lindex [lindex $pServerItem $i] 0]] } {
            return [lindex [lindex $pServerItem $i] 1]
        }
    }
    
    return ""
}

#####################################################################
# Write Server in the file in parameter
#####################################################################
proc WriteItemServer { pServerItem pFileId } {
    global DEFINE_SERVER
    global PHASE
    global PHASE_DEFAULT
    global TERMINATION
    global TERMINATION_DEFAULT
    global SNAPSHOT
    global SNAPSHOT_DEFAULT
    global NOTIFICATION
    global NOTIFICATION_DEFAULT
    global SHUTDOWN_ORDER
    global SHUTDOWN_ORDER_DEFAULT
    global SHUTDOWN_TIMEOUT
    global SHUTDOWN_TIMEOUT_DEFAULT
    global SUPERVISION
    global SUPERVISION_DEFAULT
    global PRIORITY
    global PRIORITY_DEFAULT
    global INIT_TIMEOUT
    global INIT_TIMEOUT_DEFAULT
    global PROCESSOR
    global PROCESSOR_DEFAULT
    global RUN_STRING
    global RUN_STRING_DEFAULT

    set l_Words [subst { {$PHASE} {$TERMINATION} {$SNAPSHOT} {$NOTIFICATION} {$SHUTDOWN_ORDER} {$SHUTDOWN_TIMEOUT} {$SUPERVISION} {$PRIORITY} {$INIT_TIMEOUT} {$PROCESSOR} {$RUN_STRING} }]
    set l_DefaultValues [subst { {$PHASE_DEFAULT} {$TERMINATION_DEFAULT} {$SNAPSHOT_DEFAULT} {$NOTIFICATION_DEFAULT} {$SHUTDOWN_ORDER_DEFAULT} {$SHUTDOWN_TIMEOUT_DEFAULT} {$SUPERVISION_DEFAULT} {$PRIORITY_DEFAULT} {$INIT_TIMEOUT_DEFAULT} {$PROCESSOR_DEFAULT} {$RUN_STRING_DEFAULT} }]

    puts $pFileId "\t$DEFINE_SERVER \"[lindex $pServerItem 0]\" \{"

    for {set j 0} {$j<[llength $l_Words]} {incr j} {
        
        set l_Value [CheckIfValueExists $pServerItem [lindex $l_Words $j]]

        if { ![string compare $l_Value ""] } {
            puts $pFileId "\t\t[lindex $l_Words $j] = [lindex $l_DefaultValues $j]"
        } else {
            puts $pFileId "\t\t[lindex $l_Words $j] = $l_Value"
        }
    }
    
    puts $pFileId "\t\}\n"
}

#####################################################################
# Write the list of servers in the file in parameter
#####################################################################
proc WriteEnvTable { pFileName } {
    global ListServers
    global DEFINE_ENV
    
    set fileId    [open $pFileName w]
	set timestamp [clock format [clock seconds] -format "%H:%M %d/%m/%Y"]

    puts $fileId "##################################################################################"
    puts $fileId "# This 'ScsEnvTable' was generated by SCADAsoft"
    puts $fileId "# File generated on $timestamp from [info hostname] ($::tcl_platform(os) $::tcl_platform(osVersion))"
    puts $fileId "##################################################################################"
    puts $fileId "# Table of processes to be launched:"
    puts $fileId "#   Phase = <number>                                                              "
    puts $fileId "#   Termination = NONE | SHUTDOWN | RETRY                                         "
    puts $fileId "#   Snapshot = NONE | BACKGROUND | FOREGROUND                                     "
    puts $fileId "#   Notification = YES | NO                                                       "
    puts $fileId "#   Shutdown order = <number> | LAST | LAST - <number>                            "
    puts $fileId "#   Shutdown timeout = <number>                                                   "
    puts $fileId "#   Supervision = CORBA | NONE | RTAP | UNIX | PUSH                               "
    puts $fileId "#   Priority = LOWEST | BELOW_NORMAL | NORMAL | ABOVE_NORMAL | HIGHEST            "
    puts $fileId "#   Init timeout = <number>                                                       "
    puts $fileId "#   Processor = <number>                                                          "
    puts $fileId "#   Run string = <string>                                                         "
    puts $fileId "##################################################################################"
    puts $fileId "\n"
    puts $fileId "$DEFINE_ENV \{\n"

    set l_count [llength $ListServers]

    for {set i 0} {$i < $l_count } {incr i} {

        set l_serverItem [lindex $ListServers $i]
        WriteItemServer $l_serverItem $fileId
    }
    
    puts $fileId "\}"
    
    close $fileId
}
