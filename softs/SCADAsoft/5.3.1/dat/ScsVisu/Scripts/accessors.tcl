# ---------------------------------------------------------
#
#      Default Gadgets Wrapper: uses main accessor
#
# ---------------------------------------------------------

proc ScsSet { Path Value } {
    Scs_Set $Path $Value
}

proc ScsGet { Path } {
    Scs_Get $Path
}


# ---------------------------------------------------------
#
#       Default Sheet Wrapper: uses main accessor
#
# ---------------------------------------------------------

proc ScsSheetSet { Path ColumnNo RowNo Attribute Value } {
    Scs_SheetSet $Path $ColumnNo $RowNo $Attribute $Value
}

proc ScsSheetGet { Path ColumnNo RowNo Attribute } {
    Scs_SheetGet $Path $ColumnNo $RowNo $Attribute
}


# ---------------------------------------------------------
#
#      Gadgets Geometry
#
# ---------------------------------------------------------

proc ScsMoveGadget { GadgetPath X Y } {
    Tcl_TransformGadget $GadgetPath Move $X $Y
}

proc ScsResizeGadget { GadgetPath W H } {
    Tcl_TransformGadget $GadgetPath Resize $W $H
}


# ---------------------------------------------------------
#
#  Wrapper functions for all Animator and Panel accessors
#
# ---------------------------------------------------------

proc ScsSetStringListFirstVisibleItem {path itemIndex} {
    Scs_SetStringListFirstVisibleItem  $path $itemIndex
}

proc ScsAddItem {path value} {
    Scs_Set $path.AddItem $value
}

proc ScsEnsureItemVisible { path value } {
    Scs_Set $path.EnsureVisible $value
}

proc ScsSetActive {path value} {
    Scs_Set $path.Active $value
}

proc ScsGetActive {path} {
    Scs_Get $path.Active
}

proc ScsSetAlarmState {path value} {
    Scs_Set $path.AlarmState $value
}

proc ScsGetAlarmState {path} {
    Scs_Get $path.AlarmState
}

proc ScsSetAlignment {path value} {
    Scs_Set $path.Alignment $value
}

proc ScsGetAlignment {path} {
    Scs_Get $path.Alignment
}

proc ScsSetFont {path font} {
    Scs_Set $path.Font $font
}

proc ScsSetBackgroundColorCode {path value} {
    Scs_Set $path.BackgroundColorCode $value
}

proc ScsGetBackgroundColorCode {path} {
    Scs_Get $path.BackgroundColorCode
}

proc ScsSetBackgroundColorName {path value} {
    Scs_Set $path.BackgroundColorName $value
}

proc ScsGetBackgroundColorName {path} {
    Scs_Get $path.BackgroundColorName
}

proc ScsSetBlinkingRate {path value} {
    Scs_Set $path.BlinkingRate $value
}

proc ScsGetBlinkingRate {path} {
    Scs_Get $path.BlinkingRate
}

proc ScsSetBlinkingState {path value} {
    Scs_Set $path.BlinkingState $value
}

proc ScsGetBlinkingState {path} {
    Scs_Get $path.BlinkingState
}

proc ScsSetColorNumber {path value} {
    Scs_Set $path.ColorNumber $value
}

proc ScsGetColorNumber {path} {
    Scs_Get $path.ColorNumber
}

proc ScsSetDay {path value} {
    Scs_Set $path.Day $value
}

proc ScsGetDay {path} {
    Scs_Get $path.Day
}

proc ScsSetDirection {path value} {
    Scs_Set $path.Direction $value
}

proc ScsGetDirection {path} {
    Scs_Get $path.Direction
}

proc ScsSetEditable {path value} {
    Scs_Set $path.Editable $value
}

proc ScsGetEditable {path} {
    Scs_Get $path.Editable
}

proc ScsSetExclusive {path value} {
    Scs_Set $path.Exclusive $value
}

proc ScsGetExclusive {path} {
    Scs_Get $path.Exclusive
}

proc ScsSetFillingValue {path value} {
    Scs_Set $path.FillingValue $value
}

proc ScsGetFillingValue {path} {
    Scs_Get $path.FillingValue
}

proc ScsSetFloatValue {path value} {
    Scs_Set $path.FloatValue $value
}

proc ScsGetFloatValue {path} {
    Scs_Get $path.FloatValue
}

proc ScsSetForegroundColorCode {path value} {
    Scs_Set $path.ForegroundColorCode $value
}

proc ScsGetForegroundColorCode {path} {
    Scs_Get $path.ForegroundColorCode
}

proc ScsSetForegroundColorName {path value} {
    Scs_Set $path.ForegroundColorName $value
}

proc ScsGetForegroundColorName {path} {
    Scs_Get $path.ForegroundColorName
}

proc ScsSetHighlight { path value } {
    Scs_Set $path.Highlight $value
}

proc ScsGetHightlight { path value } {
    Scs_Get $path.Highlight
}

proc ScsSetIntegerValue {path value} {
    Scs_Set $path.IntegerValue $value
}

proc ScsGetIntegerValue {path} {
    Scs_Get $path.IntegerValue
}

proc ScsSetLabel {path value} {
    Scs_Set $path.Label $value
}

proc ScsGetLabel {path} {
    Scs_Get $path.Label
}

proc ScsSetListVisible {path value} {
    Scs_Set $path.ListVisible $value
}

proc ScsGetListVisible {path} {
    Scs_Get $path.ListVisible
}

proc ScsGetStringList {path} {
    Scs_GetStringList $path
}

proc ScsSetStringList { path args } {
    Scs_SetStringList $path $args
}

proc ScsSetMaskChar {path value} {
    Scs_Set $path.MaskChar $value
}

proc ScsGetMaskChar {path} {
    Scs_Get $path.MaskChar
}

proc ScsSetMax {path value} {
    Scs_Set $path.Max $value
}

proc ScsGetMax {path} {
    Scs_Get $path.Max
}

proc ScsSetMaxInt { path value } {
    Scs_Set $path.MaxInt $value
}

proc ScsGetMaxInt { path } {
    Scs_Get $path.MaxInt
}

proc ScsSetMaxFloat { path value } {
    Scs_Set $path.MaxFloat $value
}

proc ScsGetMaxFloat { path } {
    Scs_Get $path.MaxFloat
}

proc ScsSetMin {path value} {
    Scs_Set $path.Min $value
}

proc ScsSetMinInt { path value } {
    Scs_Set $path.MinInt $value
}

proc ScsGetMinInt { path } {
    Scs_Get $path.MinInt
}

proc ScsSetMinFloat { path value } {
    Scs_Set $path.MinFloat $value
}

proc ScsGetMinFloat { path } {
    Scs_Get $path.MinFloat
}

proc ScsGetMin {path} {
    Scs_Get $path.Min
}

proc ScsSetMonth {path value} {
    Scs_Set $path.Month $value
}

proc ScsGetMonth {path} {
    Scs_Get $path.Month
}

proc ScsSetMobileValue {path value} {
    Scs_Set $path.MobileValue $value
}

proc ScsGetMobileValue {path} {
    Scs_Get $path.MobileValue
}

proc ScsSetPassword {path value} {
    Scs_Set $path.Password $value
}

proc ScsGetPassword {path} {
    Scs_Get $path.Password
}

proc ScsSetNumberValue {path value} {
    Scs_Set $path.NumberValue $value
}

proc ScsGetNumberValue {path} {
    Scs_Get $path.NumberValue
}

proc ScsRemoveItem {path value} {
    Scs_Set $path.RemoveItem $value
}

proc ScsVScrollBar {path value} {
    Scs_Set $path.VScrollBar $value
}

proc ScsHScrollBar {path value} {
    Scs_Set $path.HScrollBar $value
}

proc ScsSetSelect {path value} {
    Scs_Set $path.Select $value
}

proc ScsSetSelectAt {path value} {
    Scs_Set $path.SelectAt $value
}

proc ScsGetSelectAt {path} {
    Scs_Get $path.SelectAt
}

proc ScsSetDeselect {path value} {
    Scs_Set $path.Deselect $value
}

proc ScsGetMultiSelect { path } {
    Scs_Get $path.MultiSelect
}

proc ScsSetMultiSelect { path Liste } {
    set NbLines [ llength $Liste ]

    for { set i 0} { $i < $NbLines } { incr i 1 } {
    set Line [ lindex $Liste $i ]
        ScsSetSelect $path $Line
    }
}

proc ScsGetSelect {path} {
    Scs_Get $path.Select
}

proc ScsSetSensitive { path value } {
    Scs_Set $path.Sensitive $value
}

proc ScsIsSensitive { path } {
    Scs_Get $path.Sensitive
}

proc ScsSetState {path value} {
    Scs_Set $path.State $value
}

proc ScsGetState {path} {
    Scs_Get $path.State
}

proc ScsSetString {path value} {
    Scs_Set $path.String $value
}

proc ScsGetString {path} {
    Scs_Get $path.String
}

proc ScsSetSymbolNumber {path value} {
    Scs_Set $path.SymbolNumber $value
}

proc ScsGetSymbolNumber {path} {
    Scs_Get $path.SymbolNumber
}

proc ScsSetText {path value} {
    Scs_Set $path.Text $value
}

proc ScsGetText {path} {
    Scs_Get $path.Text
}

proc ScsSetTextFromFloat {path value} {
    Scs_Set $path.TextFromFloat $value
}

proc ScsGetTextFromFloat {path} {
    Scs_Get $path.TextFromFloat
}

proc ScsSetValue {path value} {
    Scs_Set $path.Value $value
}

proc ScsGetValue {path} {
    Scs_Get $path.Value
}

proc ScsSetVisibleItem {path value} {
    Scs_Set $path.VisibleItem $value
}

proc ScsGetVisibleItem {path} {
    Scs_Get $path.VisibleItem
}

proc ScsSetVisible { path value } {
    Scs_Set $path.Visible $value
}

proc ScsIsVisible { path } {
    Scs_Get $path.Visible
}

proc ScsSetX {path value} {
    Scs_Set $path.X $value
}

proc ScsGetX {path} {
    Scs_Get $path.X
}

proc ScsSetY {path value} {
    Scs_Set $path.Y $value
}

proc ScsGetY {path} {
    Scs_Get $path.Y
}

proc ScsSetYear {path value} {
    Scs_Set $path.Year $value
}

proc ScsGetYear {path} {
    Scs_Get $path.Year
}

proc ScsReplaceItem {path itemIndex label} {
    Scs_Method ReplaceItem $path $itemIndex $label
}

proc ScsStringListRemoveItem {path itemIndex} {
    Scs_Method StringListRemoveItem  $path $itemIndex
}

proc ScsExistAccessor {path accessor} {
    Scs_Method ExistAccessor $path $accessor
}

proc ScsGetMaxChar {path} {
    Scs_Get $path.MaxChar
}

proc ScsSetMaxChar {path value} {
    Scs_Set $path.MaxChar $value
}

proc ScsGetCursorPosition {path} {
    Scs_Get $path.CursorPosition
}

proc ScsSetCursorPosition {path value} {
    Scs_Set $path.CursorPosition $value
}

proc ScsSetTrigger {path value} {
    Scs_SetTrigger $path $value
}


# ---------------------------------------------------------
#
#      Wrapper functions for interactors on graphics
#
# ---------------------------------------------------------

proc ScsSetDefaultInteractor { path } {
    Scs_Method SetDefaultInteractor $path
}

proc ScsSetButtonInteractor { path } {
    Scs_Method SetButtonInteractor $path
}

proc ScsSetToggleInteractor { path } {
    Scs_Method SetToggleInteractor $path
}


# ---------------------------------------------------------
#
#             Wrapper function for containers
#
# ---------------------------------------------------------

proc ScsContainerSetPanel { path fileName { pArguments {} } } {
    Scs_Method SetPanel $path $fileName $pArguments
}

proc ScsContainerReplacePanel { path fileName { FreeNamespace "1" } { pArguments {} } } {
    Scs_Method SetPanel $path $fileName $pArguments
    if { $fileName != "NoFile" } {
	Panel::SetFreeNamespaceProperty $path $FreeNamespace
    }
}


# ---------------------------------------------------------
#
#           Wrapper function for a notebooks
#
# ---------------------------------------------------------

proc ScsAddPage { Path Tag File { Position Last } { Bitmap NULL } { Message TheSameAsTag } { pArguments {} }   { viewType SCROLLEDVIEW } }  {
    if { $Message == "" } {
    set Message "TheSameAsTag"
    }
    # viewTYpe maybe ELASTICVIEW
    Scs_Method Add $Path $Tag $File $Position $Bitmap $Message $pArguments $viewType
}

proc ScsChangePage { Path Tag File { Message TheSameAsTag } { pArguments {} } { viewType SCROLLEDVIEW } } {
    set Bitmap [ ScsGetBitmapPage $Path $Tag ]
    if { $Bitmap == "" } {
		set Bitmap "NULL"
	}
    set Position [ ScsRemovePage $Path $Tag ]
    Scs_Method Add $Path $Tag $File $Position $Bitmap $Message $pArguments $viewType
}

proc ScsSetPage { Path Tag File { pArguments {} } { viewType SCROLLEDVIEW } } {
    set Message [ ScsGetLabelPage $Path $Tag ]
    set Bitmap [ ScsGetBitmapPage $Path $Tag ]
    set Position [ ScsRemovePage $Path $Tag ]
    Scs_Method Add $Path $Tag $File $Position $Bitmap $Message $pArguments $viewType
}

proc ScsGetBitmapPage { Path Tag } {
    Scs_Method GetBitmap $Path $Tag
}

proc ScsGetLabelPage { Path Tag } {
    Scs_Method GetLabel $Path $Tag
}

proc ScsGetPageSensitive {path index} {
    Scs_Method PageGetSensitive $path $index
}

proc ScsSelectPage { Path Tag } {
    Scs_Method SelectPage $Path $Tag
}

proc ScsRemovePage { Path Tag } {
    Scs_Method Remove $Path $Tag
}

proc ScsSetPageSensitive {path index sensitive} {
    Scs_Method PageSetSensitive $path $index $sensitive
}


# ---------------------------------------------------------
#
#           Wrapper function for tree gadgets
#
# ---------------------------------------------------------

proc ScsSetTreeIndent {path value} {
    Scs_Set $path.Indent $value
}

proc ScsGetTreeIndent {path} {
    Scs_Get $path.Indent
}

proc ScsSetTreeLinesAtRoot {path value} {
    Scs_Set $path.LinesAtRoot $value
}

proc ScsGetTreeLinesAtRoot {path} {
    Scs_Get $path.LinesAtRoot
}

proc ScsSetTreeLinesVisible {path value} {
    Scs_Set $path.LinesVisible $value
}

proc ScsGetTreeLinesVisible {path} {
    Scs_Get $path.LinesVisible
}

proc ScsSetTreeLinkRoots {path value} {
    Scs_Set $path.LinkRoots $value
}

proc ScsGetTreeLinkRoots {path} {
    Scs_Get $path.LinkRoots
}

proc ScsSetTreeSelectionMode {path value} {
    Scs_Set $path.SelectionMode $value
}

proc ScsGetTreeSelectionMode {path} {
    Scs_Get $path.SelectionMode
}

proc ScsGetTreeSelectionUserKey {path} {
    Scs_Get $path.SelectionUserKey
}

#
# ---- Methods with the item name
#

proc ScsTreeAddItem {path item {label ""} {index -1} {userKey ""} {parentUserKey ""}} {
    Scs_Method Add $path $item $label $index $userKey $parentUserKey
}

proc ScsTreeRemoveItem {path item {userKey ""}} {
    Scs_Method Remove $path $item $userKey
}

proc ScsSetTreeItemLabel {path item label {userKey ""}} {
    Scs_Method SetLabel $path $item $label $userKey
}

proc ScsSetTreeItemBitmap {path item bitmap {userKey ""}} {
    Scs_Method SetBitmap $path $item $bitmap $userKey
}

proc ScsTreeSelect {path item {userKey ""} {deselectAll 1}} {
    Scs_Method Select $path $item $userKey $deselectAll
}

proc ScsTreeShrink {path item {userKey ""}} {
    Scs_Method Shrink $path $item $userKey
}

proc ScsTreeExpand {path item {userKey ""}} {
    Scs_Method Expand $path $item $userKey
}

#
# ---- Methods on selection
#

proc ScsTreeAddItemSelection {path {label ""} {index -1}} {
    Scs_Method AddSelection $path $label $index
}

proc ScsTreeRemoveItemSelection {path} {
    Scs_Method RemoveSelection $path
}

proc ScsSetTreeItemLabelSelection {path label} {
    Scs_Method SetLabelSelection $path $label
}

proc ScsTreeShrinkSelection {path} {
    Scs_Method ShrinkSelection $path
}

proc ScsTreeExpandSelection {path} {
    Scs_Method ExpandSelection $path
}

proc ScsTreeGetPathSelection {path} {
    Scs_Get $path.SelectionPath
}

#
# ---- Other Methods
#

proc ScsTreeDeselectAll {path} {
    Scs_Method DeselectAll $path
}

proc ScsTreeRemoveAll {path} {
    Scs_Method RemoveAll $path
}

proc ScsTreeGetSelection {path} {
    Scs_Method GetSelection $path
}


# ---------------------------------------------------------
#
#            Wrapper functions for text gadgets
#
# ---------------------------------------------------------

proc ScsAddLine { path label } {
    Scs_Method AddLine $path $label
}

proc ScsAddLines { path Liste } {
    set NbLines [ llength $Liste ]
    for { set i 0} { $i < $NbLines } { incr i 1 } {
        set Line [ lindex $Liste $i ]
            ScsAddLine $path $Line
    }
}

proc ScsCleanLines { path  } {
    Scs_Method CleanAll $path
}

proc ScsReadFile { path label } {
    Scs_Method Read $path $label
}

proc ScsWriteFile { path label } {
    Scs_Method Write $path $label
}


# ---------------------------------------------------------
#
#         Wrapper function for selector gadgets
#
# ---------------------------------------------------------

proc ScsSetSensitiveSelector { path Index State } {
    Scs_Method SetSensitive $path $Index $State
}

proc ScsGetSensitiveSelector { path Index } {
    Scs_Method GetSensitive $path $Index
}


# ---------------------------------------------------------
#
#            Wrapper function for sheet gadgets
#
# ---------------------------------------------------------

proc ScsSheetScrollTo { path row column } {
    Scs_SheetScrollTo $path $row  $column
}

proc ScsSheetSetSensitiveCell { path row column value } {
    Scs_SheetSetSensitiveItem $path $row $column $value
}

proc ScsSetSheetNbRows { path value } {
    Scs_Set $path.Rows  $value
}

proc  ScsGetSheetNbRows { path } {
    Scs_Get $path.Rows
}

proc ScsSetSheetNbColumns { path value } {
    Scs_Set $path.Columns  $value
}

proc  ScsGetSheetNbColumns { path } {
    Scs_Get $path.Columns
}

proc ScsSetSheetFirstFixedRowActive { path value } {
    Scs_Set $path.FirstFixedRow   $value
}

proc  ScsGetSheetFirstFixedRowActive {path} {
    Scs_Get $path.FirstFixedRow
}

proc ScsSetSheetFirstFixedColumnActive { path value } {
    Scs_Set  $path.FirstFixedColumn   $value
}

proc  ScsGetSheetFirstFixedColumnActive {path} {
    Scs_Get $path.FirstFixedColumn
}

proc ScsGetSheetVisibleArea { path } {
    Scs_Get $path.VisibleArea
}

proc ScsSetSheetRowsSize { path value } {
    Scs_Set $path.RowsSize $value
}

proc  ScsGetSheetRowsSize { path } {
    Scs_Get $path.RowsSize
}

proc ScsSetSheetColumnsSize { path value } {
    Scs_Set $path.ColumnsSize $value
}

proc  ScsGetSheetColumnsSize { path }  {
    Scs_Get $path.ColumnsSize
}

proc ScsSheetInsertRows { path { index "0" } { count "1" } } {
    Scs_Method SheetModify $path Insert Rows $index $count
}

proc ScsSheetReinitialize { path { Rows "1" } { Columns "1" } } {
    Scs_Method SheetModify $path Reinitialize Rows $Rows $Columns
}


# 'sizes' must be the size of all added columns or a split list of size of each column:
# 2 samples:
# - ScsSheetInsertColumns path index 3 20  : Added 3 columns wich size is 20 
# - ScsSheetInsertColumns path index 3 { 5 15 10 }  : Added 3 columns with respective size 5, 15 and 10
# - ScsSheetInsertColumns path index 3 { 5 15 }  : Error, sizes are ignored.

proc ScsSheetInsertColumns { path { index "0" } { count "1" } { sizes { -1 } }  } { 
    Scs_Method SheetModify $path Insert Columns $index $count $sizes
}

proc ScsSheetRemoveRows { path { index "0" } { count "1" } } {
    Scs_Method SheetModify $path Remove Rows $index $count
}

proc ScsSheetRemoveColumns { path { index "0" } { count "1" } } {
    Scs_Method SheetModify $path Remove Columns $index $count
}

;# *** This function is now OBSOLETE (replaced by 'ScsSheetGetSelection') ***
proc ScsGetSheetCurrentItemSelection { path { restrict "All" } } {
    ;# Restrict can be: "All", "Rows" or "Columns"
    if { $restrict == "All" } {
        set liste [join [Scs_Get $path.CurrentItemSelection] ""]
    } else {
        set liste [Scs_Get $path.CurrentItemSelection]
        set newlist ""
        if { $restrict == "Rows" } {
            for { set i 0 } { $i < [llength $liste] } { incr i } {
                 lappend newlist [lindex [lindex $liste $i] 1]
            }
        } elseif { $restrict == "Columns" } {
            for { set i 0 } { $i < [llength $liste] } { incr i } {
                 lappend newlist [lindex [lindex $liste $i] 0]
            }
        }
        set tmp ""
		;# Remove doubloons
        foreach i $newlist {
            if { [lsearch $tmp $i] == -1 } {
                lappend tmp $i
            }
        }
        set liste $tmp
    }
    return $liste
}

proc ScsSheetGetSelection { path { restrict "All" } } {
    ;# Restrict can be: "All", "Rows" or "Columns"
    if { $restrict == "All" } {
        set liste [join [Scs_Get $path.CurrentItemSelection] ""]
    } else {
        set liste [Scs_Get $path.CurrentItemSelection]
        set newlist ""
        if { $restrict == "Rows" } {
            for { set i 0 } { $i < [llength $liste] } { incr i } {
                 lappend newlist [lindex [lindex $liste $i] 1]
            }
        } elseif { $restrict == "Columns" } {
            for { set i 0 } { $i < [llength $liste] } { incr i } {
                 lappend newlist [lindex [lindex $liste $i] 0]
            }
        }
        set tmp ""
		;# Remove doubloons
        foreach i $newlist {
            if { [lsearch $tmp $i] == -1 } {
                lappend tmp $i
            }
        }
        set liste $tmp
    }
    return $liste
}

proc ScsSetSheetExclusive { path value } {
    Scs_Set $path.Exclusive $value
}

proc  ScsGetSheetExclusive { path }  {
    Scs_Get $path.Exclusive
}

proc ScsSetSheetHSB { path value } {
    Scs_Set $path.HSBVisible $value
}

proc  ScsGetSheetHSB  { path }  {
    Scs_Get $path.HSBVisible
}

proc ScsSetSheetVSB { path value } {
    Scs_Set $path.VSBVisible $value
}

proc  ScsGetSheetVSB  { path }  {
    Scs_Get $path.VSBVisible
}

proc ScsSetSheetEditable { path value } {
    Scs_Set $path.Editable $value
}

proc  ScsGetSheetEditable  { path }  {
    Scs_Get $path.Editable
}

proc ScsSetAutoRowsSelect { path value } {
    Scs_Set $path.AutoRowsSelect $value
}

proc  ScsGetAutoRowsSelect  { path }  {
    Scs_Get $path.AutoRowsSelect
}

proc ScsSetAutoColumnsSelect { path value } {
    Scs_Set $path.AutoColumnsSelect $value
}

proc  ScsGetAutoRowsSelect  { path }  {
    Scs_Get $path.AutoColumnsSelect
}

proc ScsSetBrowseMode { path value } {
    Scs_Set $path.BrowseMode $value
}

proc  ScsGetBrowseMode  { path }  {
    Scs_Get $path.BrowseMode
}

proc ScsSheetEnsureVisible { path ColNo RowNo} {
    Scs_Method EnsureVisible $path $ColNo $RowNo
}

proc ScsSheetScrollToRow { path RowNo } {
    Scs_Method ScrollToRow $path $RowNo
}

proc ScsSheetScrollToColumn { path ColumnNo } {
    Scs_Method ScrollToColumn $path $ColumnNo
}

proc ScsSheetHighlightRow { path RowNo { BackgroundColorCode "" } { ForegroundColorCode "" } } {
    Scs_Method Highlight $path Row $RowNo $BackgroundColorCode $ForegroundColorCode
}

proc ScsSheetHighlightColumn { path ColumnNo { BackgroundColorCode "" } { ForegroundColorCode "" } } {
    Scs_Method Highlight $path Column $ColumnNo $BackgroundColorCode $ForegroundColorCode
}

proc ScsSetSheetRowSelectable { path RowSelectable } {
    Scs_Method SetRowSelectable $path $RowSelectable
}

proc ScsSetSheetColumnSelectable { path ColumnSelectable } {
    Scs_Method SetColumnSelectable $path $ColumnSelectable
}

proc ScsSheetInsertLabel { path ColumnNo RowNo Label { Font "" } { Align "" } { Filled 1 } { fgColor "" } { bgColor ""}  } {
    Scs_Method InsertLabel  $path $ColumnNo $RowNo $Label $Font $Align $Filled $fgColor $bgColor
}

proc ScsSheetInsertLabels { path RowNo  Labels Fonts  Align  Filled fgColors  bgColors } {
    Scs_Method InsertLabel $path -1 $RowNo $Labels $Fonts $Align $Filled $fgColors $bgColors
}


proc ScsSheetInsertListLabel { path ColumnNo RowNo Labels { Font "" } { Align "" } } {
    Scs_Method InsertListLabel $path $ColumnNo $RowNo $Labels $Font $Align
}

proc ScsSheetInsertMessageLabel { path ColumnNo RowNo { Font "" } { WithBackground "" }} {
    if { $WithBackground == "" } {
       Scs_Method InsertMessageLabel  $path $ColumnNo $RowNo $Font
    } else {
       Scs_Method InsertMessageLabel  $path $ColumnNo $RowNo $Font $WithBackground
    }
}

proc ScsSheetInsertTextField { path ColumnNo RowNo { Font "" } } {
    Scs_Method InsertTextField $path $ColumnNo $RowNo $Font
}

proc ScsSheetInsertNumberField { path ColumnNo RowNo { Font "" } } {
    Scs_Method InsertNumberField $path $ColumnNo $RowNo $Font
}

proc ScsSheetInsertButton { path ColumnNo RowNo { Font "" } } {
    Scs_Method InsertButton  $path $ColumnNo $RowNo $Font
}

proc ScsSheetInsertToggle { path ColumnNo RowNo { Font "" } } {
    Scs_Method InsertToggle $path $ColumnNo $RowNo $Font
}

proc ScsSheetInsertRadio { path ColumnNo RowNo { Font "" } } {
    Scs_Method InsertRadio $path $ColumnNo $RowNo $Font
}

proc ScsSheetInsertScComboBox { path ColumnNo RowNo { Font "" } } {
    Scs_Method InsertScComboBox  $path $ColumnNo $RowNo $Font
}

proc ScsSheetInsertBitmap { path ColumnNo RowNo File { Transparent "0" } } {
    Scs_Method InsertBitmap $path $ColumnNo $RowNo $File $Transparent
}

proc ScsSheetGadgetLabelSet { path ColumnNo RowNo GadgetLabel { Tooltip "" } }  {
    # Tooltip used only for sheet item Gadget
    Scs_Method SetGadgetLabel  $path $ColumnNo $RowNo $GadgetLabel $Tooltip
}

proc ScsSheetComboLabelInsert { path ColumnNo RowNo GadgetLabel } {
    Scs_Method ComboLabelInsert  $path $ColumnNo $RowNo $GadgetLabel
}

proc ScsSheetComboLabelRemove { path ColumnNo RowNo GadgetLabel } {
    Scs_Method ComboLabelRemove  $path $ColumnNo $RowNo $GadgetLabel
}

proc ScsSetSheetGadgetFg { path ColorCode ColumnNo RowNo  } {
    Scs_Method SetGadgetFg  $path $ColorCode $ColumnNo $RowNo
}

proc ScsSetSheetGadgetBg { path ColorCode ColumnNo RowNo  } {
    Scs_Method SetGadgetBg  $path $ColorCode $ColumnNo $RowNo
}

proc ScsSetSheetItemForeground { path ColorCode ColumnNo RowNo  } {
    Scs_Method SetItemFg  $path $ColorCode $ColumnNo $RowNo
}

proc ScsSetSheetItemBackground { path ColorCode ColumnNo RowNo  } {
    Scs_Method SetItemBg  $path $ColorCode $ColumnNo $RowNo
}

proc ScsSetSheetItemFont { Path ColumnNo RowNo Font } {
    Scs_Method SetItemFont $Path $ColumnNo $RowNo $Font
}

proc ScsSetEditableItem  { path ColumnNo RowNo  State } {
    Scs_Method SetEditableItem  $path $ColumnNo $RowNo $State
}

proc ScsGetEditableItem  { path ColumnNo RowNo  } {
    Scs_Method GetEditableItem  $path $ColumnNo $RowNo
}

proc ScsSetSelectedItem  { path ColumnNo RowNo  State } {
    Scs_Method SetSelectedItem  $path $ColumnNo $RowNo $State
}

proc ScsGetSelectedItem  { path ColumnNo RowNo  } {
    Scs_Method GetSelectedItem  $path $ColumnNo $RowNo
}

proc ScsSetActiveItem  { path ColumnNo RowNo  State } {
    Scs_Method SetActiveItem  $path $ColumnNo $RowNo $State
}

proc ScsGetActiveItem  { path ColumnNo RowNo  } {
    Scs_Method GetActiveItem  $path $ColumnNo $RowNo
}

proc ScsSetSensitiveItem  { path ColumnNo RowNo  State } {
    Scs_Method SetSensitiveItem  $path $ColumnNo $RowNo $State
}

proc ScsGetSensitiveItem  { path ColumnNo RowNo  } {
    Scs_Method GetSensitiveItem  $path $ColumnNo $RowNo
}

proc ScsSetAlignmentItem  { path ColumnNo RowNo Position } {
    Scs_Method SetAlignmentItem  $path $ColumnNo $RowNo $Position
}


# ---------------------------------------------------------
#
#         Specific wrapper function for ScsSheet
#
# ---------------------------------------------------------

proc ScsSetRowsResizable { path value } {
    Scs_Set $path.RowsResizable $value
}

proc  ScsGetRowsResizable  { path }  {
    Scs_Get $path.RowsResizable
}

proc ScsSetColumnsResizable { path value } {
    Scs_Set $path.ColumnsResizable $value
}

proc  ScsGetColumnsResizable  { path }  {
    Scs_Get $path.ColumnsResizable
}


# ---------------------------------------------------------
#
#            Wrapper function for spinbix gadgets
#
# ---------------------------------------------------------

proc ScsSetSpinBoxValue { path value } {
    Scs_Set $path.Value $value
}

proc ScsGetSpinBoxValue { path } {
    Scs_Get $path.Value
}

proc ScsSetSpinBoxFieldEditable { path value } {
    Scs_Set $path.FieldEditable $value
}

proc ScsGetSpinBoxFieldEditable { path } {
    Scs_Get $path.FieldEditable
}


# ---------------------------------------------------------
#
#            Wrapper function for ScsTextField  gadgets
#
# ---------------------------------------------------------

proc ScsGetGlobalEditionMode { } {
    Scs_GetGlobalEditionMode
}

proc ScsSetGlobalEditionMode { { newMode "SwapAll" } } {
    Scs_SetGlobalEditionMode $newMode
}


# ---------------------------------------------------------
#
#     Wrapper function for toolbar & menubar gadgets
#
# ---------------------------------------------------------

proc ScsSetBar { barPath entryPath { attribute "Sensitive" } { value "0" } } {
    # Attribute must be "Sensitive" or "State"
    Scs_SetBar $barPath $attribute $entryPath $value
}

proc ScsGetBar { barPath entryPath { attribute "Sensitive" } } {
    # Attribute must be "Sensitive" or "State"
    Scs_GetBar $barPath $attribute $entryPath
}


# ---------------------------------------------------------
#
#        Wrapper function to affect a set of gadgets
#
# ---------------------------------------------------------

proc ScsApplyObjects { Attribute value { PanelName "" } } {
    Scs_ApplyAttributeToObjects Panels $PanelName $Attribute $value
}

proc ScsApplyObjectsSetSensitive { value { PanelName "" } }  {
    set Attribute "Sensitive"
    ScsApplyObjects  $Attribute $value $PanelName
}


# ---------------------------------------------------------
#
#      Wrapper functions for events modifiers
#
# ---------------------------------------------------------

#define IlvShiftModifier  ((IlvUShort)0x0100) =   256
#define IlvCtrlModifier   ((IlvUShort)0x0200) =   512
#define IlvAltModifier    ((IlvUShort)0x0400) =  1024
#define IlvMetaModifier   ((IlvUShort)0x0800) =  2048
#define IlvNumModifier    ((IlvUShort)0x1000) =  4096
#define IlvLockModifier   ((IlvUShort)0x2000) =  8192
#define IlvAltGModifier   ((IlvUShort)0x4000) = 16384
#define IlvAnyModifier    ((IlvUShort)0x7F00) =
#define IlvForgetModifier ((IlvUShort)0x8000) =

proc ScsExistAnyModifier { modifiers } {
    expr $modifiers != 0
}

proc ScsExistShiftModifier { modifiers } {
    expr $modifiers & 256
}

proc ScsExistCtrlModifier { modifiers } {
    expr $modifiers & 512
}

proc ScsExistAltModifier { modifiers } {
    expr $modifiers & 1024
}

proc ScsExistMetaModifier { modifiers } {
    expr $modifiers & 2048
}

proc ScsExistNumModifier { modifiers } {
    expr $modifiers & 4096
}

proc ScsExistLockModifier { modifiers } {
    expr $modifiers & 8192
}

proc ScsExistAltGModifier { modifiers } {
    expr $modifiers & 16384
}
