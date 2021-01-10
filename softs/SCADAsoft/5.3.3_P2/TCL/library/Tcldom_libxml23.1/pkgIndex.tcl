package ifneeded dom::libxml2 3.1 [list load [file join $dir Tcldom_libxml231.dll] Tcldom_libxml2] 
package ifneeded dom 3.1 [format {package require xml::libxml2; package require dom::libxml2 3.1; source %s; package provide dom 3.1} [list [file join $dir impl.tcl]]] 
