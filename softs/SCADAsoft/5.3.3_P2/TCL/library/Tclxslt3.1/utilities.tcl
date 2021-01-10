# utilities.tcl --
#
#	Miscellaneous extension functions for XSLT.
#
# Copyright (c) 2004 Zveno Pty Ltd
# http://www.zveno.com/
#
# See the file "LICENSE" in this distribution for information on usage and
# redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# $Id: utilities.tcl,v 1.1 2004/09/29 23:51:57 balls Exp $

package provide xslt::utilities 1.1

namespace eval xslt::utilities {
    namespace export character-first
}

# xslt::utilities::character-first --
#
#	Returns the character that occurs first from a string
#	of possible characters.
#
# Arguments:
#	src	source string
#	chars	characters to find
#	args	not needed
#
# Results:
#	Returns a character or empty string.

proc xslt::utilities::character-first {srcNd charsNd args} {
    if {[llength $args]} {
	return -code error "too many arguments"
    }

    set src $srcNd
    catch {set src [dom::node stringValue [lindex $srcNd 0]]}
    set chars $charsNd
    catch {set chars [dom::node stringValue [lindex $charsNd 0]]}

    regsub -all {([\\\[\]^$-])} $chars {\\\1} chars
    if {[regexp [format {([%s])} $chars] $src dummy theChar]} {
	return $theChar
    }

    return {}
}


