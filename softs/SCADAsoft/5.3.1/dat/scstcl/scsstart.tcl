#!scswish -f
# -- scsstart.tcl --
#
# This script displays informations on starting of Scadasoft environment.
#
# M. Alter


######################################################################
# Initializations
######################################################################

if {$argc != 2} {
    error "scswish scsstart.tcl <scadasoft_version> <scadasoft_env>"
}

set version [lindex $argv 0]
set envname [lindex $argv 1]
set hostname [info hostname]
set servername "StartServer"
set scshome $env(SCSHOME)
set init [clock seconds]
set pourcent 0
set starting "No process starting."
set processname ""
set lastprocessname ""
set phase 0
set nbprocesstostart 1
set stopped 0
set nbsec 10
set polling 500
set nbprocess 0
set curr 0

######################################################################
# Graphics
######################################################################

# window parameters

set w .mywin
set wwidth 40
set wheight 8 

catch {destroy $w}
toplevel $w
set hcenter [expr ([winfo screenheight $w] - $wheight*10) / 2 -$wheight*20]
set wcenter [expr ([winfo screenwidth $w] - $wwidth) / 2 - $wwidth*2]
wm withdraw .
wm title $w "Starting SCADASoft v$version environment $envname on $hostname ..."
wm iconname $w "Starting"
wm resizable $w false false
wm geometry $w =$wwidth\x$wheight+$wcenter+$hcenter

# buttons parameters for Exit and Stop

frame $w.buttons 
pack $w.buttons -side bottom -fill x -pady 2m
button $w.buttons.dismiss -text "Exit" -command { b_exit }
button $w.buttons.code -text "Stop" -command { b_stop }
pack $w.buttons.dismiss $w.buttons.code -side left -expand 1

# tick parameters

label $w.counter -text 00.00.00 -relief raised -width 10
pack $w.counter -fill both

# image parameters 

catch {image delete image_scada ; exit}
image create photo image_scada -file [file join $scshome dat scstcl scada.gif] -height 200 -width 300
label $w.l1 -image image_scada -bd 1 -relief sunken

pack $w.l1 -side top -padx .5m -pady .5m

# event parameters

bind $w <Control-c> { destroy $w }
bind $w <Control-q> { destroy $w }
bind $w <Escape> { destroy $w }
bind $w <Destroy> { b_exit }
focus .

# frame parameters

frame $w.frame -borderwidth 10
pack $w.frame -side top -fill x

# label parameters for starting informations

label $w.frame.label -wraplength 5i -justify left -text $starting
pack $w.frame.label -side top

# canvas parameters for progress bar

canvas $w.frame.canvas -width 50 -height 15 -bd 0 -highlightthickness 0
$w.frame.canvas create polygon -fill DeepSkyBlue3 -tags poly
$w.frame.canvas create line -fill black -tags line
$w.frame.canvas create line -fill black -tags cadre
$w.frame.canvas coords cadre 1 5 167 5 167 5 167 10 167 10 1 10 1 5

label $w.frame.pourcent -wraplength 5i -justify left -text "($pourcent %)"
pack $w.frame.pourcent -side right

pack $w.frame.canvas -side top -expand yes -anchor s -fill x  -padx 15

# text with scrollbar parameters

text $w.text -yscrollcommand "$w.scroll set" -setgrid true \
	-width 50 -height 10 -wrap word
scrollbar $w.scroll -command "$w.text yview"
pack $w.scroll -side right -fill y
pack $w.text -expand yes -fill both

# set up display styles for text
$w.text tag configure font1 -background #a0b7ce
$w.text tag configure font2 -background black -foreground red -offset 2p -font {Courier 7}
$w.text tag configure font3 -background black -foreground green -offset 2p -font {Courier 7}
$w.text tag configure font4 -background black -foreground yellow -offset 2p -font {Courier 7}
$w.text tag configure font5 -background black -foreground magenta -offset 2p -font {Courier 7}
$w.text tag configure font6 -background white -foreground black -offset 2p -font {Courier 8}
$w.text tag configure font7 -background black -foreground white -offset 2p -font {Courier 8}
$w.text configure -state disabled


#############################################################################
# Procedures
#############################################################################

# Waiting AscManager

proc waitAsc {} {
    set ErrorCode [catch {ScsAsc::init} ErrorText]
    if { $ErrorCode == 1 } {
	waitAsc
    } else {
	puts "Initialization of ScsAsc successful"
    }
}

# Exit button

proc b_exit {} {
    global stopped
    set stopped 1
    Exit
}

# Stop button

proc b_stop {} {
    global stopped
    set stopped 1
    ScsAsc::shutdown
    Exit
}

# change label and progress bar

proc process_started {} {
    global pourcent starting processname w stopped nbprocesstostart nbprocess phase
    if $stopped return

    if { $nbprocess<$nbprocesstostart-1 } {
	incr nbprocess 1
	set starting "Starting process $processname ( Phase $phase ) ** $nbprocess / $nbprocesstostart **"
    } else {
	set nbprocess $nbprocesstostart
	set processname ""
 	set starting "All processes started."
    }
    
    set pourcent [expr int(100.0 * ($nbprocess.0 / $nbprocesstostart.0))]
    set x2 [expr ($pourcent + 1) * 1.65 ]
    $w.frame.canvas coords poly 1 5 $x2 5 $x2 5 $x2 10 $x2 10 1 10 1 5
    $w.frame.canvas coords line 1 5 $x2 5 $x2 5 $x2 10 $x2 10 1 10 1 5
    $w.frame.label configure -text $starting
    $w.frame.pourcent configure -text "($pourcent %)"
}

# troncature string 

proc tronc { str max } {
    set result ""
    set str [string trim $str]
    set length [string length $str] 
    if {$length > $max} {
	set ends [expr $max - 1] 
	append result [string range $str 0 $ends]
    } else {
	set count [expr $max - $length]
	append result $str [string repeat " " $count]
    }
    return $result
}

# regrep scsps equivalent command  

proc scsps {} {
    global w processname curr
    set pinfos [ScsAsc::getProcessInfos]
    set lpinfos [llength $pinfos]
    if {$lpinfos > 0} {
	for {set i 0} {$i<$lpinfos} {incr i} {
	    set current [lindex $pinfos $i]
	    set name [lindex $current 0]
	    set state [lindex $current 1]
	    set phase [lindex $current 2]
	    set termination [lindex $current 3]
	    set notification [lindex $current 4]
	    set shutdown [lindex $current 5]
	    set supervision [lindex $current 6]
	    set priority [lindex $current 7]
	    set runstring [lindex $current 8]
	    set snapshot [lindex $current 9]
	    set inittimeout [lindex $current 10]
	    set pid [lindex $current 11]
	    if { [string trim $name] == [string trim $processname] } {
		if {$curr == 1} {
		    $w.text insert end [tronc $name 17] font6
		    set curr 0
		} else {
		    $w.text insert end [tronc $name 17] font7
		    set curr 1
		}  
	    } else {
		$w.text insert end [tronc $name 17] font6
	    }

	    if { $state == "SCS_DOWN" } {
		$w.text insert end [tronc $state 24] font2
	    } elseif { $state == "SCS_UP" } {
		$w.text insert end [tronc $state 24] font3
	    } elseif { $state == "SCS_INIT" } {
		$w.text insert end [tronc $state 24] font4
	    } else {
		$w.text insert end [tronc $state 24] font5
	    }
	    $w.text insert end "\n"    
	}
    }
}

# text informations with scsps

proc process_infos {} {
    global w stopped
    if $stopped return    
    $w.text configure -state normal
    $w.text delete 0.0 end
    $w.text insert end "Name                              State                     \n" font1
    scsps
    $w.text configure -state disabled    
}

# Tick information

proc tick {} {
    global w stopped current init
    if $stopped return
    set diffcurrent [expr $current - $init]
    set hours [expr [clock format $diffcurrent -format "%H"] - 1]
    set minutes [clock format $diffcurrent -format "%M"]
    set seconds [clock format $diffcurrent -format "%S"]
    $w.counter config -text [format "%s:%s:%s" $hours $minutes $seconds]
}

# MainLoop

proc Run {} {
    global stopped current polling nbsec processname lastprocessname phase nbprocesstostart nbprocess
    if $stopped return
    after $polling Run
    set current [clock seconds]
    if {$nbprocess < $nbprocesstostart} {
	tick
	if {[expr $current % ($nbsec * 1000)]} {
	    set cinfos [lindex [ScsStart::startProcessInfo] 0]
	    set processname [lindex $cinfos 0]
	    set phase [lindex $cinfos 1]
	    set nbprocesstostart [lindex $cinfos 2]
	    if { $processname != "" } {
		if { $processname != $lastprocessname } {
		    set lastprocessname $processname
#		    puts "Received info : processname = $processname | phase = $phase | nbprocesstostart = $nbprocesstostart"
		    process_started
		} else {
#		    puts "Waiting infos..."
		}
	    }
	}
    }
    process_infos
}

# Exit

proc Exit {} {
    global servername envname hostname
    set cmd "scskillit $servername@$envname\_$hostname"
    eval exec $cmd &
}

# Init

proc Init {} {
    global servername envname hostname version
    
    # Initialization of Scadasoft
    set ErrorCode [catch {
	Scs::initializeWithMainLoop ${servername} ${envname}_${hostname}
    } ErrorText]
    if { $ErrorCode == 1 } {
	puts "Initialization of Scadasoft failed : $ErrorText"
	if { [ScsStatus::isError] == "True" } {
	    puts "SCADAsoft reason : [ScsStatus::getText]"
	}
	puts "<Control+C> to quit..."
	while { 1 } { }
	Exit
    } else {
	puts "Initialization of Scadasoft successful"
    }
    
    # Initialization of ScsAsc
    set ErrorCode [catch {ScsAsc::init} ErrorText]
    if { $ErrorCode == 1 } {
	puts "Initialization of ScsAsc failed : $ErrorText"
	if { [ScsStatus::isError] == "True" } {
	    puts "SCADAsoft reason : [ScsStatus::getText]"
	}
	puts "Waiting AscManager (<Control+C> to quit)..."
	waitAsc
    } else {
	puts "Initialization of ScsAsc successful"
    }
    
    # Initialization of ScsStart
    set ErrorCode [catch {ScsStart::init} ErrorText]
    if { $ErrorCode == 1 } {
	puts "Initialization of ScsStart failed : $ErrorText"
	if { [ScsStatus::isError] == "True" } {
	    puts "SCADAsoft reason : [ScsStatus::getText]"
	}
	puts "<Control+C> to quit..."
	while { 1 } { }
	Exit
    } else {
	puts "Initialization of ScsStart successful"
    }
    
    puts "Starting SCADASoft v$version environment $envname on $hostname ..."
}

#############################################################################
# Main
#############################################################################

Init

bell -display $w

tkwait visibility $w

# launch Main Loop

Run
