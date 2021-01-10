###################################################################
#
# ---- General
#
###################################################################


###################################################################
#
# ---- The creation script is called through the "OnInit" procedure. 
# This procedure is compulsory and should always be present. 
# If nothing has to be done, this procedure may be empty.
#
###################################################################
proc OnInit {} {
    Panel::Show
}

###################################################################
#
# ---- A destruction script is called through the "OnKill" procedure.
# The procedure is compulsory and should always be present. 
# If nothing has to be done, this procedure may be empty.
#
###################################################################
proc OnKill {} {
}

###################################################################
#
# ---- When an SCADAsoft server becomes alive (resp. dead), the 
# "OnServerUp" (resp. "OnServerDown") procedure is called. 
# If nothing has to be done, these procedures may be empty.
#
###################################################################
proc OnServerUp { pEnvName } {
}

proc OnServerDown { pEnvName } {
}

###################################################################
#
# ---- Procedure invoked by the "OnEventClose" procedure when a 
# panel is closed.
#
###################################################################
proc OnClose {} {
    Panel::DeletePanel
}

###################################################################
#
# ---- When an error occurs in a TCL script relative to a panel,
# the procedure "OnError" defined within this script is automatically 
# triggered.
# 
###################################################################
proc OnError { {Message "Unknown" } } {
    puts $Message
}

###################################################################
#
# ---- The procedure "OnEventClose" is called when you close 
# the panel : when you declare this callback, it’s up to you to 
# explicitly decide about closing the panel or not.
#
###################################################################
proc OnEventClose { view } {
    OnClose # invoke your own procedure/callback
}

###################################################################
#
# ---- The procedure "OnEventResize" is called when you resize or 
# move the panel.
#
# WARNING : Be careful of this procedure because of the amount of
# calls it causes when it is used.
###################################################################
# proc OnEventResize { View X Y W H } {
# }

###################################################################
#
# ---- The procedure "OnEventInput" is called for all others panel 
#      events.
#
# WARNING : Be careful of this procedure because of the amount of
# calls it causes when it is used.
###################################################################
# proc OnEventInput { view event x y xx yy w h btn key mod } {
# }


