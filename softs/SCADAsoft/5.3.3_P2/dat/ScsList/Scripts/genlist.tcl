namespace eval Scs {}
namespace eval ScsList {}

proc ScsList::SortBy {ColumnName {Order ""} {Name ""} {graphicPath ""}} {

    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

    set SortOrder ""
    if [string compare $Order ""] then {
        set SortOrder $Order
    } else {
        set SortOrder $Scs::SortingOrder
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsSortBy $ColumnName $SortOrder $ListName $graphicPath
}

proc ScsList::SortByColumns {ColumnsName {Order ""} {Name ""} {graphicPath ""}} {

    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

    set SortOrder ""
    if [string compare $Order ""] then {
        set SortOrder $Order
    } else {
        set SortOrder $Scs::SortingOrder
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsSortBy $ColumnsName $SortOrder $ListName $graphicPath
}

proc ScsList::Select {Row {Name ""} {graphicPath ""} {ShowSelectedRow "YES"} } {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsSelect $Row $ListName $graphicPath $ShowSelectedRow
}

proc ScsList::FilterSelect {Criteria {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsSelectWithFilter $Criteria $ListName $graphicPath
}

proc ScsList::AddFilterSelect {Criteria {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsAddSelectWithFilter $Criteria $ListName $graphicPath
}

proc ScsList::AddSelect {Row {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsAddSelect $Row $ListName $graphicPath
}

proc ScsList::GroupSelect {Row {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsGroupSelect $Row $ListName $graphicPath
}

proc ScsList::GroupDeSelect {Row {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsGroupDeSelect $Row $ListName $graphicPath
}

proc ScsList::DeselectAll { {Name ""} {graphicPath ""} } {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsDeSelectAll $ListName $graphicPath
}

proc ScsList::SelectAll { {Name ""} {graphicPath ""} } {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}
	
	ScsList::Select 1 $ListName $graphicPath
	ScsList::GroupSelect [ScsList::GetCount] $ListName $graphicPath
}

proc ScsList::CellZoom {Row Column {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsCellZoom $Row $Column $ListName $graphicPath
}

proc ScsList::SetClientFilter {Filter {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsSetClientFilter $Filter $ListName $graphicPath
}

proc ScsList::GetClientFilter {{Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsGetClientFilter $ListName $graphicPath
}

proc ScsList::SetServerFilter {Filter {Server ""} {List ""} {graphicPath ""} {logicalEnv ""}} {
    set ListName ""
    if [string compare $List ""] then {
        set ListName $List
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsSetServerFilter $Filter $Server $ListName $graphicPath $logicalEnv
}

proc ScsList::GetCount {{Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsGetListCount $ListName $graphicPath
}

proc ScsList::GetTotalCount {{Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsGetListCountWithoutFilter $ListName $graphicPath
}


proc ScsList::GetNbSelectedRows {{Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsGetNbSelectedRows $ListName $graphicPath
}

proc ScsList::isRowSelected { Row {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsIsRowSelected $Row $ListName $graphicPath
}

proc ScsList::GetInternalValue {ColumnName RowNumber {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
	    set ListName $Name
    } else {
    	set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsGetInternalValue $ColumnName $RowNumber $ListName $graphicPath
}

proc ScsList::GetKeyId {RowNumber {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
	    set ListName $Name
    } else {
    	set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsGetKeyId $RowNumber $ListName $graphicPath
}


proc ScsList::GetInternalSelectedValues  {ColumnName {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
	    set ListName $Name
    } else {
    	set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}
	
	Tcl_ScsGetInternalSelectedValues $ColumnName $ListName $graphicPath
}

proc ScsList::GetInternalSelectedIndexes  { {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
	    set ListName $Name
    } else {
    	set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}
	
	Tcl_ScsGetInternalSelectedIndexes $ListName $graphicPath
}

proc ScsList::GetSelectedKeyIds  { {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
	    set ListName $Name
    } else {
    	set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}
	
	Tcl_ScsGetSelectedKeyIds $ListName $graphicPath
}

proc ScsList::IsVSBInInitialPosition { {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
	    set ListName $Name
    } else {
    	set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	Tcl_ScsListIsVSBInInitialPosition $ListName $graphicPath
}

proc ScsList::SetVSBInInitialPosition {{Name "" } {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
	    set ListName $Name
    } else {
    	set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsListSetVSBInInitialPosition $ListName $graphicPath
}

proc ScsList::ChangeColumnFont {ColumnName Font {ApplicationCell "BOTH"} {Name ""} {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
	    set ListName $Name
    } else {
    	set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsChangeColumnFont $ColumnName $Font $ApplicationCell $ListName $graphicPath
}

proc ScsList::ColumnsCorrespondence {{ Name "" } {graphicPath ""}} {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    return [Tcl_ScsColumnsCorrespondence $ListName $graphicPath]
}

proc ScsList::GetFirstVisibleColumn { {Name "" } {graphicPath ""} } {
    set ListName ""
    if [string compare $Name ""] then {
	    set ListName $Name
    } else {
    	set ListName $Scs::CurrentList
    }

    if ![string compare $graphicPath ""] then {
        set graphicPath $Scs::CurrentGraphicPath
    }    
    
    return [Tcl_ScsListGetFirstVisibleColumn $ListName $graphicPath]
}  

proc ScsList::GetColumnsCount { {Name "" } {graphicPath ""} } {
    set ListName ""
    if [string compare $Name ""] then {
	    set ListName $Name
    } else {
    	set ListName $Scs::CurrentList
    }

    if ![string compare $graphicPath ""] then {
        set graphicPath $Scs::CurrentGraphicPath
    }

    return [Tcl_ScsListGetColumnsCount $ListName $graphicPath]
}


proc ScsList::SetHSBFirstVisibleColumn { { col 0}  {Name "" } {graphicPath ""} } {
    set ListName ""
    if [string compare $Name ""] then {
	    set ListName $Name
    } else {
    	set ListName $Scs::CurrentList
    }

    if ![string compare $graphicPath ""] then {
        set graphicPath $Scs::CurrentGraphicPath
    }

    Tcl_ScsListSetHSBFirstVisibleColumn $col $ListName $graphicPath
}

proc ScsList::SetItemForeground { Name ColorCode ColumnNo RowNo  {graphicPath ""}} {
	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsSetItemFg $Name $graphicPath $ColorCode $ColumnNo $RowNo
}

proc ScsList::SetItemBackground { Name ColorCode ColumnNo RowNo  {graphicPath ""}} {
	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    Tcl_ScsSetItemBg $Name $graphicPath $ColorCode $ColumnNo $RowNo
}

proc ScsList::ReadElement { IndexElt { Name "" } {graphicPath ""} } {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    return [Tcl_ScsReadElement $ListName $graphicPath $IndexElt]
}

proc ScsList::ReadVisibleElements { {Name ""} {graphicPath ""} } {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

    return [Tcl_ScsReadVisibleElements $ListName $graphicPath]
}

proc ScsList::ReadSubscribedElement { IndexElt { Name "" } {graphicPath ""} { ColumnsList ""} } {
    set ListName ""
    if [string compare $Name ""] then {
        set ListName $Name
    } else {
        set ListName $Scs::CurrentList
    }

	if ![string compare $graphicPath ""] then {
		set graphicPath $Scs::CurrentGraphicPath
	}

	if ![string compare $ColumnsList ""] then {
		return [Tcl_ScsReadElement $ListName $graphicPath $IndexElt]
	} else {
		return [Tcl_ScsReadSubscribedElement $ListName $graphicPath $IndexElt $ColumnsList]
	}
}
