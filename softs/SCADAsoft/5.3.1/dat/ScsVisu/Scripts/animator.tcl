#
#
# ---- Animator Instruction Wrappers
#
#

namespace eval Animator {}


#
# ---- Instruction Set
# 
#

proc Animator::NewImage { ShortImageName FileName { pImageType {IT_Default} } { pArguments {} } } {
        set Namespace "Const::"
        set ImageType $$Namespace$pImageType

	Scs_NewFrame Animator $Scs::CurrentGraphicPath $ShortImageName $FileName [expr $ImageType]  ""  0 $pArguments
}

proc Animator::GetImage { ShortImageName FileName { pImageType {IT_Default} } { pArguments {} } } {
        set Namespace "Const::"
        set ImageType $$Namespace$pImageType

	Scs_NewFrame Animator $Scs::CurrentGraphicPath $ShortImageName $FileName [expr $ImageType]  ""  1 $pArguments
}

proc Animator::DeleteImage { ImageName { FreeNamespace "1" } } {
	Scs_Close Animator $ImageName $FreeNamespace
}

proc Animator::Show { { ViewName "" } } {
	Scs_ShowFrame Animator $ViewName "" "0"
}

proc Animator::Hide { ViewName } {
	Scs_HideFrame Animator $ViewName
}

proc Animator::Raise { ViewName } {
	Scs_RaiseFrame Animator $ViewName 
}

proc Animator::Lower { ViewName } {
	Scs_LowerFrame Animator $ViewName 
}

proc Animator::Move { ViewName X Y } {
	Scs_MoveFrame Animator $ViewName $X $Y
}

proc Animator::Resize { ViewName Width Height } {
	Scs_ResizeFrame Animator $ViewName $Width $Height
}

proc Animator::SetTitle { ViewName Title } {
	Scs_SetTitle Animator $Title
}

proc Animator::Exists { ImageName } {
    return [Scs_ExistFrame $ImageName]
}


proc Animator::BeginPaint { { ImageName "" } } {
    Scs_BeginPaint Animator $ImageName
}

proc Animator::EndPaint { { ImageName "" } } {
    Scs_EndPaint Animator $ImageName
}

#
# ---- Animator Specific
#
#
proc Animator::Fit { ViewName { Centered 0 } } {
	Scs_FitView Animator $ViewName $Centered
}

proc Animator::GetImageBoundingBox { { ImageName  "" } } {
    Scs_GetBoundingBox Animator $ImageName
}

proc Animator::Pan { ViewName X Y } {
	Scs_PanView Animator $ViewName $X $Y
}

proc Animator::SetOrigin { ViewName X Y } {
	Scs_SetViewOrigin Animator $ViewName $X $Y
}

proc Animator::Zoom { ViewName ZoomFactor } {
	Scs_ZoomView Animator $ViewName $ZoomFactor
}

proc Animator::SetZoomLevel { ViewName ZoomLevel } {
	Scs_SetViewZoomLevel Animator $ViewName $ZoomLevel 
}

proc Animator::ViewExists { { ViewName "" } } {
        Scs_ViewExists Animator $ViewName
}

proc Animator::AddView { { pImage "" } { pViewName "DefaultView" } { pX 50 } { pY 50 } {
                           pWidth 600 } { pHeight 500 } {Parent "" } } {
	Scs_AddView Animator $pImage $pX $pY $pWidth $pHeight $pViewName $Parent
}

proc Animator::RecomputeFormulas { { ViewName "" } { EnvName "" } { contextId "" } } {
        Scs_RecomputeFormulas Animator $ViewName $EnvName $contextId
}

#
# ---- Layers
#
#
proc Animator::SetLayerVisible { ViewName LayerName Flag } {
    Scs_SetLayerVisible Animator $ViewName $LayerName $Flag
}

proc Animator::IsLayerVisible { ViewName pLayerName } {
    Scs_IsLayerVisible Animator $ViewName $pLayerName
}

#
# ---- View Interactors
#
#
proc Animator::SetViewInteractor { ViewName InteractorName } {
    Scs_SetViewInteractor Animator $ViewName $InteractorName
}

proc Animator::GetViewInteractor { ViewName } {
    Scs_GetViewInteractor Animator $ViewName
}

proc Animator::SetSelectionFilter { ViewName AnimatorClassName UserClassName ObjectName } {
    Scs_SetSelectionFilter Animator $ViewName $AnimatorClassName $UserClassName $ObjectName
}

proc Animator::GetSelectionFilter { ViewName } {
    Scs_GetSelectionFilter Animator $ViewName
}

proc Animator::IgnoreKeyboardActions { ViewName { Ignore 1 } { NavViewOnly 1 } } {
    Scs_IgnoreKbdActions Animator $ViewName $Ignore $NavViewOnly
}

#
# ---- Navigation view management
#
#
proc Animator::ShowNavigationView { Image { Name "Navigation" } { X 0 } { Y 0 } { Width 0 } { Properties WS_Standard } {Parent "" } {useTransparency 1}} {
    set Code 0
    set Namespace "Const::"
    
    set Lenght [ llength $Properties ]
    
    for { set Index 0 } { $Index < $Lenght } { incr Index } {
	set Label [ lindex $Properties $Index ]
	set var $$Namespace$Label
	set Code [ expr $Code + $var  ] 
    }
    Scs_ShowNavigationView Animator $Image $Name $X $Y $Width $Code $Parent $useTransparency
}

proc Animator::HideNavigationView { Image { Name "Navigation" } } {
    Scs_HideNavigationView Animator $Image $Name
}

proc Animator::GetNavigationGeometry { Image { Name "Navigation" } } {
    Scs_GetNavigationGeometry Animator $Image $Name
}

#
# ---- Miscellaneous
#
#
proc Animator::SetCaptionIcon { IconPath { PanelName "" } } {
    Tcl_ScsSetCaptionIcon Animator $PanelName $IconPath
}

#
# ---- Export facilities
#
#
proc Animator::SetupSVGExport { { background 1 } { panZoom 1 } { tooltips 1 } \
 			        { blinking 1 } { flashing 0 } \
			        { cursor 1 } { forceCursor "" } { disableTextCursor 1 } \
			        { renderColors 0 } { renderTexts 0 } { renderShapes 0 } { renderIcons 0 } \
			        { encoding "" } { indent 1 } { comment 1 } } {


    # background:        do (1) / do not (0) generate image background / 
    # panZoom:           enable (1) / disable (0) pan&zoom interactions
    # tooltips:          enable (1) / disable (0) tooltips management
    # blinking:          enable (1) / disable (0) blinking management
    # flashing:          do (1) / do not (0) replace blinking effect by a flashing effect
    # cursor:            enable (1) / disable (0) cursor  management
    # forceCursor:       cursor ref to be forced (check SVG export dialog for values)
    # disableTextCursor: enable (1) / disable (0) default text cursor 
    # renderXxxx:        specify the rendering options for each image part (check SVG export dialog for values)
    # encoding:          specify SVG encoding (def = ISO-8859-1)
    # indent:            enable (1) / disable (0) SVG file indentation
    # comment:           enable (1) / disable (0) SVG file comments

    Scs_SetupSVGExport \
                       $background $panZoom $tooltips \
                       $blinking $flashing $cursor $forceCursor \
                       $disableTextCursor $renderColors $renderTexts $renderShapes $renderIcons \
                       $encoding $indent $comment
}

proc Animator::DumpImageToSVG { ViewName } {
    ;# Image will be dumped to $SCSPATH/ScsVisu/Animator/svg/imagePath/imageName.svg(z)
    Scs_DumpImageToSVG Animator $ViewName
}

