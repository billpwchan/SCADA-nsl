#############################################
#
# ---- TKE PIDS
#
#############################################

namespace eval Pids {}

proc Pids::GenerateBitmap { ParametersList Width Height BgdColorCode Directory Filename {xOffset 0} {yOffset 0} } {
   return [ Scs_GenerateBitmap $ParametersList $Width $Height $BgdColorCode $Directory $Filename $xOffset $yOffset ]
}

proc Pids::SplitBitmap { BitmapPath Height Directory Filename } {
   return [ Scs_SplitBitmap $BitmapPath $Height $Directory $Filename ]
}

proc Pids::DisplayBitmap { ContainerPath BitmapPath Page Height { ZoomRatio "2.0" } } {
   return [ Scs_DisplayBitmap $ContainerPath $BitmapPath $Page $Height $ZoomRatio ]
}
