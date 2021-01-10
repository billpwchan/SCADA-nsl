###############################
#
# ----- Namespace
#
###############################


namespace eval Pie { }


###############################
#
# ---- Procedures
#
###############################


proc Pie::Initialize { pieName startingAngle range margins sliceSpace labelFont labelColour \
                       offsetTheta offsetRho legend legendAutoResize } {
	Scs_PieInitialize $pieName $startingAngle $range $margins $sliceSpace $labelFont $labelColour \
                      $offsetTheta $offsetRho $legend $legendAutoResize
}

proc Pie::Draw { pieName pieData } {
	Scs_PieDraw $pieName $pieData
}
