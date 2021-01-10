if {[catch {package require Tcl 8.4}]} return
package ifneeded tile 0.5  [list load [file join $dir tile05.dll] tile]
