# pkgIndex.tcl --
#
#       Handcrafted for TclXSLT.
#
# Copyright (c) 2001-2004 Zveno Pty Ltd
# http://ww.zveno.com/
#
# $Id: pkgIndex.tcl.in,v 1.10 2004/10/24 08:11:50 balls Exp $

package ifneeded xslt 3.1 [format {
    load %s Xslt
    source %s
} [list [file join $dir Tclxslt31.dll]] [list [file join $dir tclxslt.tcl]]]

package ifneeded xslt::cache 3.1 [list source [file join $dir xsltcache.tcl]]
package ifneeded xslt::resources 1.1 [list source [file join $dir resources.tcl]]
package ifneeded xslt::process 1.1 [list source [file join $dir process.tcl]]
package ifneeded xslt::utilities 1.0 [list source [file join $dir utilities.tcl]]


