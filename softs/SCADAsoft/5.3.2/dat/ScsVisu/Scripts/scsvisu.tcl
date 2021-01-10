#
#
# ---- Common Procedures
#
#

namespace eval ScsVisu {}


#########################################
#
# ---- Version information
#
#########################################

proc ScsVisu::GetInfo { { infos "Visu" } } {
	if { $infos == "TclLibrary" } {
		set TclVersion "TCL v[info patchlevel]"
	    if { [info commands Threads] != {} } {
			set step1 [catch {set newThread [Threads create]}]
			if { $step1 == "0" } {
				set step2 [catch {Threads send -async $newThread {Threads exit}}]
				if { $step2 == "0" } {
					set TclVersion "$TclVersion (MultiThreaded)"
				}
			}
		}
		return $TclVersion
	} else {
		Scs_TclGetVisuVersion $infos
	}
}


#########################################
#
# ---- Message Boxes
#
#########################################

proc ScsVisu::ShowError { X Y Message { Title "Error" } { Label "Ok" } { Transient "" } } {
    Scs_Trace Error $X $Y $Message $Title $Label $Transient
}

proc ScsVisu::ShowWarning { X Y Message  { Title "Warning" } { Label "Ok" } { Transient "" } } {
    Scs_Trace Warning $X $Y $Message $Title $Label $Transient
}

proc ScsVisu::ShowInfo { X Y Message  { Title "Information" } { Label "Ok" } { Transient "" } } {
    Scs_Trace Information $X $Y $Message $Title $Label $Transient
}

proc ScsVisu::ShowTrace { X Y Message { Title "Trace" } { Label "Ok" } { Transient "" } } {
    Scs_Trace Trace $X $Y $Message $Title $Label $Transient
}

proc ScsVisu::ShowQuestion { X Y Message { Title "Question" } { Apply "Ok" } { Cancel "Cancel" } { Transient "" } } {
    Scs_Trace Question $X $Y $Message $Title $Apply $Cancel $Transient
}

proc ScsVisu::ShowFileSelector { X Y Directory { Title "FileSelector" } { Apply "Ok" } { Cancel "Cancel" } { Transient "" } } {
    Scs_Trace FileSelector $X $Y $Directory $Title $Apply $Cancel $Transient
}


#########################################
#
# ---- Module Control
#
#########################################

proc ScsVisu::Exit {} {
    Scs_Exit
}

proc ScsVisu::Suspend { { pEnvName "" } } {
    Scs_Suspend $pEnvName
}

proc ScsVisu::ReStart { pEnvName } {
    Scs_ReStart $pEnvName
}

proc ScsVisu::ShutDown { } {
    Scs_Exit
}


proc ScsVisu::ChangeCursor { CursorName { PanelName  "" } } {
    Scs_ChangeCursor Panels $PanelName $CursorName
}

#############################################
#
# ---- Adds an item to the menu
#
#############################################

proc ScsVisu::AddItem { pMenu pItem pIndex} {
    set ItemName [ lindex $pItem 0 ]
    set ItemCB [ lindex $pItem 1 ]
    set ItemRO [ lindex $pItem 2 ]
    set ItemBitmap [ lindex $pItem 3 ]
    set IsToggle [  lindex $pItem 4 ]

    Scs_AddMenuItem $pMenu $ItemName $ItemCB $ItemRO $ItemBitmap $IsToggle

    set ItemLength [ llength $pItem ]
    if { $ItemLength == 6 } {
    set subDesc [ lindex $pItem 5 ]
    set Length [ llength $subDesc ]
    set SubMenu [ Scs_NewPopUp ]

    for { set Index 0 } { $Index < $Length } { incr Index } {

        ScsVisu::AddItem $SubMenu [ lindex $subDesc $Index ] $Index
    }
    Scs_AddSubMenu $pIndex $pMenu $SubMenu
    }

}

#############################################
#
# ---- Pop Up
#      Creates a Popup and add all items one
#      after another
#
#############################################

proc ScsVisu::PopUp { font pDesc {pX ""} {pY ""} { bgColorCode ""} { modal "1" } } {

    #
    # ---- A menu is:
    # PopUp{ { Item CB ReadOnly Bitmap IsToggle {{ Item CB Readonly Bitmap IsToggle} ...}} ... { Item CB Readonly Bitmap IsToggle } }
    #

    if { $pX == "" } {
        set pX $Scs::MouseGlobalX
    }

    if { $pY == "" } {
        set pY $Scs::MouseGlobalY
    }

    set Menu [ Scs_NewPopUp $font $bgColorCode]

    set Length [ llength $pDesc ]

    for { set Index 0 } { $Index < $Length } { incr Index } {
        ScsVisu::AddItem $Menu [ lindex $pDesc $Index ] $Index
    }

    Scs_GetPopUp $Menu $pX $pY [uplevel {namespace current}] $modal
}

proc ScsVisu::CloseAllPopUp { } {
    Scs_CloseAllPopUp
}

#############################################
#
# ---- ChangeItemMenuBar
#      Creates a Popup and change all items one
#      after another to a menu of the menu bar
#
#############################################

proc ScsVisu::ChangeItemMenuBar { MenuBar InsertIndex font pDesc { bgColorCode ""}} {

    #
    # ---- A menu is:
    # { { Item CB ReadOnly Bitmap IsToggle {{ Item CB Readonly Bitmap IsToggle} ...}} ... { Item CB Readonly Bitmap IsToggle } }
    #
    Scs_ChangeMenuItemMenuBar $MenuBar $InsertIndex $font $pDesc $bgColorCode
}


#############################################
#
# ---- Message Database Control
#
#############################################

proc ScsVisu::ReadMessageDatabase { pFileName } {
    set NbFiles [llength $pFileName]
    for { set i 0 } { $i < $NbFiles } { incr i } {
	Scs_ReadMessageDB [lindex $pFileName $i]
    }
}

proc ScsVisu::AddDBMessage { pMessageID pLang pString } {
    Scs_AddDBMessage $pMessageID $pLang $pString
}

proc ScsVisu::GetDBMessage { pMessageID { pLang "" } } {
    Scs_GetDBMessage $pMessageID $pLang
}

proc ScsVisu::RemoveDBMessage { pMessageID } {
    Scs_RemoveDBMessage $pMessageID
}

proc ScsVisu::SetLanguage { dbmFile language } {
    set ErrorCode [ catch { ScsVisu::ReadMessageDatabase $dbmFile} ErrorText ]
    if { $ErrorCode == 0 } {
      ScsVisu::ActivateLanguage $language
    }
}

proc ScsVisu::ActivateLanguage { language } {
    Tcl_ScsActivateLanguage $language
}

#############################################
#
# ---- Message Timer
#
#############################################

proc ScsVisu::After { pDelay pCallback { pGraphicPath "" }} {
	if { $pGraphicPath == "" } {
		set pGraphicPath $Scs::CurrentGraphicPath
	}
    Scs_After "$pGraphicPath" $pDelay $pCallback 0
}

proc ScsVisu::Every { pPeriod pCallback { pGraphicPath "" }} {
	if { $pGraphicPath == "" } {
		set pGraphicPath $Scs::CurrentGraphicPath
	}
    Scs_After "$pGraphicPath" $pPeriod $pCallback $pPeriod
}

proc ScsVisu::CancelTimer { pTimerId { pGraphicPath "" }} {
    if { $pGraphicPath == "" } {
		set pGraphicPath $Scs::CurrentGraphicPath
    }
    Scs_CancelTimer "$pGraphicPath" $pTimerId
}

proc ScsVisu::GetTime {} {
    Scs_GetTime
}

#############################################
#
# ---- Display
#
#############################################

proc ScsVisu::FlushDisplay {} {
    Scs_DisplayFlush
}

proc ScsVisu::CopyIntoClipBoard { string } {
   Scs_CopyIntoClipBoard $string
}

#############################################
#
# ---- SplitterGadget
#
#############################################
#########################################
# 
# - MakeSplitterGadget : creates splitter on a existing guide
# - SetSplitterMousePos : changes splitter position
# - SetSplitterSensitive : prevents user events to interact with splitter
#
# The splitter key used to identified gadget is defined by :
# - graphic path of the panel
# - orientation
# - index of the associated guide
# - index of the starting guide
# - index of the ending guide
# Note that splitter key is the identification given in MakeSplitter call in the same order :

# Example :
# # Create splitter
# ScsVisu::MakeSplitterGadget $Scs::CurrentGraphicPath HORIZONTAL 1 1 2 5
# # move it
# ScsVisu::SetSplitterMousePos $Scs::CurrentGraphicPath HORIZONTAL 1 1 2 $x $y
# # desactivate it
# ScsVisu::SetSplitterSensitive $Scs::CurrentGraphicPath HORIZONTAL 1 1 2 $Cst::FALSE

# 
proc ScsVisu::MakeSplitterGadget { GraphicPath Direction Index { From {0}} { To {1}} { Size {6}} } {
   Scs_MakeSplitterGadget $GraphicPath $Direction $Index $From $To $Size
}
proc ScsVisu::SetSplitterMousePos { GraphicPath Direction Index StartingIndex EndingIndex X Y } {
   Scs_SetSplitterMousePos $GraphicPath $Direction $Index $StartingIndex $EndingIndex $X $Y
}
proc ScsVisu::SetSplitterSensitive { GraphicPath Direction Index StartingIndex EndingIndex Sensitve } {
   Scs_SetSplitterSensitive $GraphicPath $Direction $Index $StartingIndex $EndingIndex $Sensitve
}

#############################################
#
# ---- Change the operator name that will be logged on server side
#
#############################################

proc ScsVisu::SetOperatorName { operatorName } {
    Scs_SetOperatorName $operatorName
}

#############################################
#
# ---- Set messages priorities (only usefull towards a redundant environment)
#
#############################################

proc ScsVisu::SetMessagePriorities { args } {
    eval Scs_SetMessagePriorities $args
}


#
# Exit On Error
proc ScsVisu::SetExitOnError { value  } {
     # value is True or False
     Scs_SetExitOnError $value
}

proc ScsVisu::GetExitOnError {  } {
    # return is True or False 
    Scs_GetExitOnError
}

proc ScsVisu::TestExitOnError { numtest } {
    # numtest :
    # 0 nothing
    # 1 break point
    # 2 divison by zero
    # 3 free uninitialized memory
    # 4 infinite malloc
    # 5 timer callback on error.
    # 6 array bound write
    # 7 array bound read
    
    Scs_TestExitOnError $numtest
}
