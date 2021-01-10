if {[catch {package require Tcl 8.4}]} return
if {![info exists ::env(TREECTRL_LIBRARY)]
    && [file exists [file join $dir treectrl.tcl]]} {
    set ::env(TREECTRL_LIBRARY) $dir
}
package ifneeded treectrl 1.1  [list load [file join $dir treectrl11.dll] treectrl]
