#
#
# ---- Panels Instruction Wrappers
#
#

namespace eval Panel {}

#
# ---- Instruction Set
#

proc Panel::NewPanel { ShortPanelName FileName { pProperties { WS_Standard } } { pTransient "" } { pArguments {} } } {
    set Code 0
        set Namespace "Const::"

    set Lenght [ llength $pProperties ]
    for { set Index 0 } { $Index < $Lenght } { incr Index } {
                set Label [ lindex $pProperties $Index ]
                set var $$Namespace$Label
        set Code [ expr $Code + $var  ]
    }
    Scs_NewFrame Panels $Scs::CurrentGraphicPath "$ShortPanelName" $FileName $Code $pTransient 0  $pArguments
}

proc Panel::GetPanel { ShortPanelName FileName { pProperties { WS_Standard } } { pTransient "" }  { pArguments {} }  } {
    set Code 0
        set Namespace "Const::"

    set Lenght [ llength $pProperties ]

    for { set Index 0 } { $Index < $Lenght } { incr Index } {
                set Label [ lindex $pProperties $Index ]
                set var $$Namespace$Label
        set Code [ expr $Code + $var  ]
    }
    Scs_NewFrame Panels $Scs::CurrentGraphicPath "$ShortPanelName" $FileName $Code $pTransient 1 $pArguments
}

proc Panel::DeletePanel { { PanelName "" } { FreeNamespace "1" } } {
    Scs_Close Panels $PanelName $FreeNamespace
}

proc Panel::SetFreeNamespaceProperty { { PanelName "" } { FreeNamespace "0" } } {
	Scs_SetFreeNamespaceProperty Panels $PanelName $FreeNamespace
}

proc Panel::Show { { PanelName "" } { ShowMode Normal } {Timeout "0"} } {
    Scs_ShowFrame Panels $PanelName $ShowMode $Timeout
}

proc Panel::Hide { { PanelName  "" } } {
    Scs_HideFrame Panels $PanelName
}

proc Panel::Raise { { PanelName "" } } {
    Scs_RaiseFrame Panels $PanelName
}

proc Panel::Lower { { PanelName "" } } {
    Scs_LowerFrame Panels $PanelName
}

proc Panel::Move { PanelName X Y } {
    Scs_MoveFrame Panels $PanelName $X $Y
}

proc Panel::MoveToPanel { SourcePanel DestinationPanel { Justification 16 } { xOffset 0 } { yOffset 0 } { ensureInScreen 1 } } {
    ;# Justification values:
    ;# Left = 1, Right = 2, Top = 4, Bottom 8, Center = 16
    ;# TopLeft = Left|Top, BottomLeft = Left|Bottom,
    ;# TopRight = Right|Top, BottomRight = Right|Bottom,
    
    Scs_MoveToPanel $DestinationPanel $SourcePanel $Justification $xOffset $yOffset $ensureInScreen
}

proc Panel::Resize { PanelName Width Height } {
    Scs_ResizeFrame Panels $PanelName $Width $Height
}

proc Panel::SetMinimumSize { PanelName Width Height } {
    Scs_MinMaxSize Panels $PanelName Min $Width $Height
}

proc Panel::SetMaximumSize { PanelName Width Height } {
    Scs_MinMaxSize Panels $PanelName Max $Width $Height
}

proc Panel::SetTitle { Title { PanelName "" } } {
    Scs_SetTitle Panels $PanelName "$Title"
}

proc Panel::Iconify { { PanelName "" } } {
    Tcl_ScsIconify $PanelName
}

proc Panel::IsIconified { { PanelName "" } } {
    Tcl_ScsIsIconified $PanelName
}

proc Panel::GetGeometry { PanelName { includeFrame "1" } } {
    Scs_GetGeometry $PanelName $includeFrame
}

proc Panel::SetBackgroundColorCode { ColorCode { PanelName "" } } {
    Scs_SetFrameBackgroundColorCode Panels $PanelName $ColorCode
}

proc Panel::SetImage { ImageObjectName FileName { Zoom "Default" } } {
    # Zoom may be: "Default", "Fit", "FitAndCentered", "FitAndCenteredAsNeeded" or any positive floating value like "1.75" (ie. 175%)
    Scs_ChangeImage $ImageObjectName $FileName $Zoom
}

proc Panel::RecomputeFormulas { { PanelName "" } { EnvName "" } { contextId "" } } {
    Scs_RecomputeFormulas Panels $PanelName $EnvName $contextId
}

proc Panel::Exists { PanelName } {
    return [Scs_ExistFrame $PanelName]
}

proc Panel::EnableTooltip { { enabled "1" } } {
	Scs_EnableTooltip $enabled
}

proc Panel::BeginPaint { { PanelName "" } } {
    Scs_BeginPaint Panels $PanelName
}

proc Panel::EndPaint { { PanelName "" } } {
    Scs_EndPaint Panels $PanelName
}

proc Panel::DumpWindowToPS { PanelName filepath { filename "dump.ps" } { title "" } { landscape "1" } { width "595" } { height "842" } } {
    # STGL 116: AGE 4/9/2007: dimension format A4 (595/842) et format ANSI A Letter (612/792)
    Scs_DumpWindow $PanelName $filepath $filename $title $landscape $width $height
}

proc Panel::DumpObjectToPS { ObjectPath filepath { filename "dump.ps" } { title "" } { landscape "0"} { width "595" } { height "842" } } {
    # STGL 116: AGE 4/9/2007: dimension format A4 (595/842) et format ANSI A Letter (612/792)
    Scs_DumpObject $ObjectPath $filepath $filename $title $landscape $width $height
}

proc Panel::DumpImageToPS { ImagePath filepath { filename "dump.ps" } { title "" } { landscape "1" } { withBackground "0" } } {
    Scs_DumpImage Animator $ImagePath $filepath $filename $title $landscape $withBackground
}

proc Panel::PrintArea { printerName { x "0" } { y "0" } { w "" } { h "" } } {
    if ![string length $w] {
        set w $Scs::ScreenWidth
    }
    if ![string length $h] {
        set h $Scs::ScreenHeight
    }
    Scs_PrintArea $printerName $x $y $w $h
}

proc Panel::PrintWindow { printerName { winGraphicPath "" } } {
    if ![string length $winGraphicPath] {
        set winGraphicPath $Scs::CurrentGraphicPath
    }
    Scs_PrintWindow $printerName $winGraphicPath
}

proc Panel::PrintObject { printerName { objGraphicPath "" } } {
    Scs_PrintObject $printerName $objGraphicPath
}

proc Panel::CopyArea { filename { x "0" } { y "0" } { w "" } { h "" } } {
    if ![string length $w] {
        set w $Scs::ScreenWidth
    }
    if ![string length $h] {
        set h $Scs::ScreenHeight
    }
    Tcl_ScsCopyAreaToBitmap $filename $x $y $w $h
}

proc Panel::CopyWindow { filename { winGraphicPath "" } } {
    if ![string length $winGraphicPath] {
        set winGraphicPath $Scs::CurrentGraphicPath
    }
    Tcl_ScsCopyWindowToBitmap $filename $winGraphicPath
}

proc Panel::CopyObject { filename { objGraphicPath "" } } {
    Tcl_ScsCopyObjectToBitmap $filename $objGraphicPath
}

proc Panel::PrintBitmap { printerName bitmapName } {
	Tcl_ScsPrintBitmap $printerName $bitmapName
}

proc Panel::SetCaptionIcon { IconPath { PanelName "" } } {
    Tcl_ScsSetCaptionIcon Panels $PanelName $IconPath
}

proc Panel::FocusImage { ImageObjectName } {
    Tcl_ScsSetFocus $ImageObjectName
}

proc Panel::DrawSight { Panel ObjectName x1 y1 x2 y2 \
			    { colorCode 0 } { diagonal 1 } { drawMode 0 } \
			    { linewidth 1 } { linestyle "solid" } { drawOnly 0 } } {
    Tcl_ScsDisplaySight $Panel $ObjectName $x1 $y1 $x2 $y2 $colorCode $diagonal $drawMode $linewidth $linestyle $drawOnly
}

proc Panel::EraseSight { Panel ObjectName } {
    Tcl_ScsEraseSight $Panel $ObjectName
}

proc Panel::WriteLogFile { Panel LogFileName} {
    Tcl_ScsWriteLog Panels $Panel $LogFileName
}

proc Panel::ResetLogFile { Panel } {
    Tcl_ScsResetLog Panels $Panel
}
