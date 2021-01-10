###############################
#
# ----- Namespace
#
###############################


namespace eval Trd { }


###############################
#
# ---- Procedures
#
###############################


proc Trd::AddMeasure { trendPath { archive "" } { point "" } { environment "default" } { dataType "Value" } { index "0" } { timeRange "0 0" } { offset "0" } { storageOfPoints "-1" } { flushOperation "1" } { stairsMode "0" }  { sampleRate "0" } { coefficient "1.0" } } {
    if { $storageOfPoints >= 0 } {
	if { $storageOfPoints < 2 } {
	    ;# Min storage should be 2 points
	    set storageOfPoints "-1"
	}
    }
    Tcl_ScsTrdAddMeasure $trendPath $archive $point $environment $dataType $index [lindex $timeRange 0] [lindex $timeRange 1] $offset $storageOfPoints $flushOperation $stairsMode $sampleRate $coefficient
}

proc Trd::RemoveMeasure { trendPath { index "0" } { flushOperation "1" } } {
    Tcl_ScsTrdRemoveMeasure $trendPath $index $flushOperation
}

proc Trd::InsertTclValues { trendPath values { index "0" } } {
    Tcl_ScsInsertTclValues $trendPath $values $index
}

proc Trd::RemoveTclValues { trendPath { index "0" } } {
    Tcl_ScsRemoveTclValues $trendPath $index
}

proc Trd::Flush { trendPath } {
    Tcl_ScsTrdFlush $trendPath
}

proc Trd::ClearData { trendPath { index "-1" } } {
    Tcl_ScsTrdClearData $trendPath $index
}

proc Trd::GetNbCurves { trendPath } {
    return [lindex [Tcl_ScsTrdGetNbCurves $trendPath] 0]
}

proc Trd::GetNbVerticalAxes { trendPath } {
    return [lindex [Tcl_ScsTrdGetNbCurves $trendPath] 1]
}

proc Trd::IsCurveVisible { trendPath { index "0" } } {
    Tcl_ScsTrdIsCurveVisible $trendPath $index
}

proc Trd::SetCurveVisible { trendPath { visible "0" } { index "0" } } {
    Tcl_ScsTrdSetCurveVisible $trendPath $visible $index
}

proc Trd::RefreshTrend { trendPath } {
    Tcl_ScsTrdRefreshTrend $trendPath
}

proc Trd::RefreshLegend { trendPath } {
    Tcl_ScsTrdRefreshLegend $trendPath
}

proc Trd::IsLegendVisible { trendPath } {
    Tcl_ScsTrdIsLegendVisible $trendPath
}

proc Trd::GetLegendName { trendPath } {
    Tcl_ScsTrdGetLegendName $trendPath
}

proc Trd::GetCurveName { trendPath { index "0" } } {
    Tcl_ScsTrdGetCurveName $trendPath $index
}

proc Trd::SetCurveName { trendPath name { index "0" } } {
    Tcl_ScsTrdSetCurveName $trendPath $name $index
}

proc Trd::RemoveLimits { trendPath { index "0" } } {
    Tcl_ScsTrdRemoveLimits $trendPath $index
}

proc Trd::SetLimits { trendPath limit1 limit2 mark inverse { index "0" } } {
    Tcl_ScsTrdSetLimits $trendPath $limit1 $limit2 $mark $inverse $index
}

proc Trd::Scroll { trendPath xOffset yOffset { index "0" } } {
    Tcl_ScsTrdScroll $trendPath $xOffset $yOffset $index
}

proc Trd::Zoom { trendPath xMin xMax yMin yMax { index "0" } } {
    Tcl_ScsTrdZoom $trendPath $xMin $xMax $yMin $yMax $index
}

proc Trd::SetScrollMode { trendPath mode { ratio "0.25" } } {
    ;# Mode: 0 => Stop, 1 => Shift, 2 => Cycle, 3 => SCADA mode (shift when not translated)
    Tcl_ScsTrdSetScrollMode $trendPath $mode $ratio
}

proc Trd::SetCurveStyle { trendPath style { marker "0" } { size "0" } { index "0" } } {
    Tcl_ScsTrdSetCurveStyle $trendPath $style $marker $size $index
}

proc Trd::SetLineStyle { trendPath style { width "1" } { index "0" } } {
    Tcl_ScsTrdSetLineStyle $trendPath $style $width $index
}

proc Trd::SetCurveColors { trendPath foreground background { index "0" } } {
    Tcl_ScsTrdSetCurveColors $trendPath $foreground $background $index
}

proc Trd::SetAbscissaInfo { trendPath label oriented nbMajor nbMinor format } {
    Tcl_ScsTrdSetAbscissaInfo $trendPath $label $oriented $nbMajor $nbMinor $format
}

proc Trd::GetAbscissaInfo { trendPath } {
    Tcl_ScsTrdGetAbscissaInfo $trendPath
}

proc Trd::SetOrdinateInfo { trendPath label showValues oriented nbMajor nbMinor format { index "0" } } {
    Tcl_ScsTrdSetOrdinateInfo $trendPath $label $showValues $oriented $nbMajor $nbMinor $format $index
}

proc Trd::GetOrdinateInfo { trendPath { index "0" } } {
    Tcl_ScsTrdGetOrdinateInfo $trendPath $index
}

proc Trd::RemoveInteractor { trendPath interactorName } {
    Tcl_ScsTrdRemoveInteractor $trendPath $interactorName
}

proc Trd::SetZoomInteractor { trendPath { button "Right" } { steps "0" } } {
    Tcl_ScsTrdSetZoomInteractor $trendPath $button $steps
}

proc Trd::SetPanInteractor { trendPath { index "-1" } { button "Left" } } {
    Tcl_ScsTrdSetPanInteractor $trendPath $button $index
}

proc Trd::SetCrossHairInteractor { trendPath { showAbs "1" } { showOrd "0" } } {
    Tcl_ScsTrdSetCrossHairInteractor $trendPath $showAbs $showOrd
}

proc Trd::SetInfoViewInteractor { trendPath { displayCurveName "1" } { designate "0" } { button "Left" } { xOffset "0" } { yOffset "0" } } {
    Tcl_ScsTrdSetInfoViewInteractor $trendPath $displayCurveName $designate $button $xOffset $yOffset
}

proc Trd::SetSelectInteractor { trendPath { button "Left" } { distance "10" } { index "0" } } {
    Tcl_ScsTrdSetSelectInteractor $trendPath $button $distance $index
}

proc Trd::BeginStickerMode { trendPath { button "Left" } { maxSticker "32"} { width "150"} { height "40"} { background "moccasin"} { closeButton "Right"} { formatDate "%a %d %b %Y %H:%M:%S"} } {
    Tcl_ScsTrdBeginStickerMode $trendPath $button $maxSticker $width $height $background $closeButton $formatDate
}

proc Trd::EndStickerMode { trendPath } {
    Tcl_ScsTrdEndStickerMode $trendPath
}

proc Trd::AllowCallback { trendPath { activate "1" } } {
    Tcl_ScsTrdAllowCallback $trendPath $activate
}

proc Trd::GetXRange { trendPath } {
    Tcl_ScsTrdGetRange $trendPath "X" "0"
}

proc Trd::GetYRange { trendPath { index "0" } } {
    Tcl_ScsTrdGetRange $trendPath "Y" $index
}

proc Trd::SetXMin { trendPath value } {
    Tcl_ScsTrdSetRange $trendPath "X" "Min" $value "0"
}

proc Trd::SetXMax { trendPath value } {
    Tcl_ScsTrdSetRange $trendPath "X" "Max" $value "0"
}

proc Trd::SetYMin { trendPath value { index "0" } } {
    Tcl_ScsTrdSetRange $trendPath "Y" "Min" $value $index
}

proc Trd::SetYMax { trendPath value { index "0" } } {
    Tcl_ScsTrdSetRange $trendPath "Y" "Max" $value $index
}

proc Trd::GetVisibleMinMaxValues { trendPath { yAxisIndex "0" } } {
    Tcl_ScsTrdGetVisibleMinMaxValues $trendPath $yAxisIndex
}

proc Trd::IsXAutoMode { trendPath } {
    Tcl_ScsTrdIsAutoMode $trendPath "X" "0"
}

proc Trd::IsYAutoMode { trendPath { index "0" } } {
    Tcl_ScsTrdIsAutoMode $trendPath "Y" $index
}

proc Trd::SetXAutoMode { trendPath { automatic "1" } } {
    Tcl_ScsTrdSetAutoMode $trendPath "X" "0" $automatic
}

proc Trd::SetYAutoMode { trendPath { automatic "1" } { index "0" } } {
    Tcl_ScsTrdSetAutoMode $trendPath "Y" $index $automatic
}

proc Trd::SetVerticalAxisShape { trendPath { vAxisIndex "0" } { side "Left" } { offset "0" } { labelOffset "0" } } {
    Tcl_ScsSetVerticalAxisShape $trendPath $vAxisIndex $side $offset $labelOffset
}

proc Trd::GetVerticalAxisShape { trendPath { vAxisIndex "0" } } {
    Tcl_ScsGetVerticalAxisShape $trendPath $vAxisIndex
}

proc Trd::SetVerticalAxisVisible { trendPath { visible "0" } { vAxisIndex "0" } } {
    Tcl_ScsSetVerticalAxisVisible $trendPath $visible $vAxisIndex
}

proc Trd::IsVerticalAxisVisible { trendPath { vAxisIndex "0" } } {
    Tcl_ScsIsVerticalAxisVisible $trendPath $vAxisIndex
}

proc Trd::GetVerticalAxisNameFromCurveIndex { trendPath curveIndex } {
    Tcl_ScsGetVerticalAxisNameFromCurveIndex $trendPath $curveIndex
}

proc Trd::GetVerticalAxisIndexFromCurveName { trendPath curveName } {
    Tcl_ScsGetVerticalAxisIndexFromCurveName $trendPath $curveName
}

proc Trd::Notify { trendPath { activate "1" } } {
	Tcl_ScsTrdNotify $trendPath $activate
}

proc Trd::SetGrid { trendPath axisIndex majorVisible minorVisible lineStyle } {
	Tcl_ScsTrdSetGrid $trendPath $axisIndex $majorVisible $minorVisible $lineStyle
}

proc Trd::Test { trendPath rating { index "0" } } {
    ;# Testing function: for internal use only
    Tcl_ScsTrdTest $trendPath $rating $index
}

# Specific to ScsTrendArray

proc Trd::SetQualityTextPerMeasure { trendPath { index "0" } textList } {
    Tcl_ScsTrdArraySetCustomTextPerMeasure Quality $trendPath $index $textList 
}

proc Trd::SetValuesTextPerMeasure  { trendPath { index "0" } textList } {
    Tcl_ScsTrdArraySetCustomTextPerMeasure Values $trendPath  $index $textList
}


proc Trd::SetQualityText { trendPath textList } {
    Tcl_ScsTrdArraySetCustomText Quality $trendPath $textList
}

proc Trd::SetValuesText { trendPath textList } {
    Tcl_ScsTrdArraySetCustomText Values $trendPath $textList
}

proc Trd::GetCurveTimestamp { trendPath { index "0" } } {
    Tcl_ScsTrdArrayGetTimestamp $trendPath $index
}

proc Trd::SetCurveTimestamp { trendPath name { index "0" } } {
    Tcl_ScsTrdArraySetTimestamp $trendPath $name $index
}

proc Trd::SetDesignateInteractor { trendPath { button "Left" } { activate "1" } } {
    Tcl_ScsTrdArraySetDesignate $trendPath $button $activate
}

proc Trd::SetFormat { trendPath format { index "0" } } {
    Tcl_ScsTrdArraySetFormat $trendPath $format $index
}

proc Trd::SetFont { trendPath font { index "0" } } {
    Tcl_ScsTrdArraySetFont $trendPath $font $index
}

proc Trd::SetTitlePalette { trendPath foreground background font { index "0" } } {
    Tcl_ScsTrdArraySetTitlePalette $trendPath $foreground $background $font $index
}

proc Trd::SetAbscissa { trendPath startingTime period nbPoints } {
    Tcl_ScsTrdArraySetAbscissa $trendPath $startingTime $period $nbPoints
}

proc Trd::BeginPaint { trendPath } {
    Tcl_ScsTrdBeginPaint $trendPath
}

proc Trd::EndPaint { trendPath } {
    Tcl_ScsTrdEndPaint $trendPath
}

proc Trd::SetShiftOrdinate { trendPath offset { index 0 } } {
    Tcl_ScsTrdSetShiftOrdinates $trendPath $index $offset
}

proc Trd::GetShiftOrdinate { trendPath { index 0 } } {
    Tcl_ScsTrdGetShiftOrdinates $trendPath $index
}

proc Trd::CompleteMeasure { trendPath abscissa { withQuality 0} { index 0 } } {
    Tcl_ScsTrdCompleteMeasure $trendPath $abscissa $withQuality $index
}

# define in ilv.h
#  IlvMarkerSquare		0x0001
#  IlvMarkerDiamond	        0x0002
#  IlvMarkerCircle		0x0004
#  IlvMarkerCross		0x0008
#  IlvMarkerPlus		0x0010
#  IlvMarkerFilledSquare	0x0020
#  IlvMarkerFilledCircle	0x0040
#  IlvMarkerFilledDiamond	0x0080
#  IlvMarkerTriangle	        0x0100
#  IlvMarkerFilledTriangle      0x0200
#  IlvDefaultMarkerSize	             4


# SPSE EVOL: Quality Marquer
set Trd::NoMarker               0
set Trd::MarkerSquare           1
set Trd::MarkerDiamond          2
set Trd::MarkerCircle           4
set Trd::MarkerCross            8
set Trd::MarkerPlus            16
set Trd::MarkerFilledSquare    32
set Trd::MarkerFilledCircle    64
set Trd::MarkerFilledDiamond  128
set Trd::MarkerTriangle       256
set Trd::MarkerFilledTriangle 512

set Trd::DefaultMarkerSize   4

proc Trd::SetMarkerForQuality { trendPath { QualityValue 0 } { MarkerType NoMarker } { MarkerSize  DefaultMarkerSize } { index 0 } } {
    Tcl_ScsTrdSetMarkerForQuality $trendPath $QualityValue $MarkerType $MarkerSize $index
}

proc Trd::GetCountOfQualityMarkersForMeasure { trendPath { index 0 } } {
    return [Tcl_ScsTrdGetCountOfQualityMarkersForMeasure $trendPath $index]
}

proc Trd::GetMarkerTypeForQuality { trendPath { quality 0} { index 0 } } {
    return [Tcl_ScsTrdGetMarkerTypeForQuality $trendPath $quality $index]
}

proc Trd::GetMarkerSizeForQuality { trendPath { quality 0} { index 0 } } {
    return [Tcl_ScsTrdGetMarkerSizeForQuality $trendPath $quality $index]
}

proc Trd::GetQualityMarkersForMeasure { trendPath { index 0 } } {
    return [Tcl_ScsTrdGetQualityMarkersForMeasure $trendPath $index]
}


proc Trd::SetInvalidQualityAndValue { trendPath { index 0 } { invalidValue 0.0 } { invalidQuality 1} } {
   Tcl_ScsSetInvalidQualityAndValue $trendPath $index $invalidValue $invalidQuality
}

proc Trd::ResetInvalidQualityAndValue { trendPath { index 0 }  } {
   Tcl_ScsResetInvalidQualityAndValue $trendPath $index
}