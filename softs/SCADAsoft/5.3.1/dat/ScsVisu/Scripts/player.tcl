#
#
# ---- Event Player Procedures
#
#

namespace eval Player {}

proc Player::StartSequence { } {
	Tcl_ScsPlayerStart
}

proc Player::AbortSequence { } {
	Tcl_ScsPlayerStop
}

proc Player::SaveSequence { filename { removeLast "0" } } {
	Tcl_ScsPlayerSave $filename $removeLast
}

proc Player::ReplaySequence { filename { speed "500" } { pointer "1" } { loop "1" } { cb "" } { improvedPlayer 1 } } {
	Tcl_ScsPlayerReplay $filename $speed $pointer $loop $cb $Scs::CurrentGraphicPath $improvedPlayer
}

proc Player::AbortReplay { { immediately "0" } } {
	Tcl_ScsPlayerAbort $immediately
}
