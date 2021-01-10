# resources.tcl --
#
#	XSLT extension providing access to resources.
#
# Copyright (c) 2005 Explain
# http://www.explain.com.au/
# Copyright (c) 2001-2004 Zveno Pty Ltd
# http://www.zveno.com/
#
# See the file "LICENSE" in this distribution for information on usage and
# redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES.
#
# $Id: resources.tcl,v 1.2 2005/11/04 06:41:56 balls Exp $

package provide xslt::resources 1.2

namespace eval xslt::resources {
    namespace export list type exists modified
}

# xslt::resources::list --
#
#	List the resources available at a given location
#
# Arguments:
#	locn	Resource path to list
#	basedir	Base directory
#	args	not needed
#
# Results:
#	Returns list of resources

proc xslt::resources::list {locnNd {baseNd {}} args} {
    # What kind of resource is this?  file, http, ftp, etc?

    if {[llength $args]} {
	return -code error "too many arguments"
    }

    set locn $locnNd
    # The resource may be passed in as a nodeset
    catch {set locn [dom::node stringValue [lindex $locnNd 0]]}
    set base $baseNd
    catch {set base [dom::node stringValue [lindex $baseNd 0]]}

    if {[string match /* $base]} {
	regsub {^(/)} $locn {} locn
    }

    set result {}
    foreach entry [glob -nocomplain [file join $base $locn *]] {
	lappend result [file tail $entry]
    }

    return $result
}

# xslt::resources::type --
#
#	Gives the type of the resource
#
# Arguments:
#	locn	Resource path to type
#	args	not needed
#
# Results:
#	Returns string describing resource

proc xslt::resources::type {locnNd args} {

    if {[llength $args]} {
	return -code error "too many arguments"
    }

    set locn $locnNd
    catch {set locn [dom::node stringValue [lindex $locnNd 0]]}

    if {[file isdir $locn]} {
	return directory
    } elseif {[file isfile $locn]} {
	return file
    } else {
	return other
    }
}

# xslt::resources::exists --
#
#	Check whether a resource exists
#
# Arguments:
#	locn	Resource path to type
#	args	not needed
#
# Results:
#	Returns boolean

proc xslt::resources::exists {locnNd args} {

    if {[llength $args]} {
	return -code error "too many arguments"
    }

    set locn $locnNd
    catch {set locn [dom::node stringValue [lindex $locnNd 0]]}

    if {[file exists $locn]} {
	return 1
    } else {
	return 0
    }
}

# xslt::resources::modified --
#
#	Report last modification time of a resource
#
# Arguments:
#	locn	Resource path
#	args	not needed
#
# Results:
#	Returns ISO standard date-time string

proc xslt::resources::modified {locnNd args} {

    if {[llength $args]} {
	return -code error "too many arguments"
    }

    set locn $locnNd
    catch {set locn [dom::node stringValue [lindex $locnNd 0]]}

    if {[file exists $locn]} {
	return [clock format [file mtime $locn] -format {%Y-%m-%dT%H:%M:%S}]
    } else {
	return {}
    }
}

# xslt::resources::mkdir --
#
#	Create a directory hierarchy.
#
# Arguments:
#	locn	Resource path for directory
#	args	not needed
#
# Results:
#	Returns directory created or empty string if unsuccessful

proc xslt::resources::mkdir {locnNd args} {

    if {[llength $args]} {
	return {}
    }

    set locn $locnNd
    catch {set locn [dom::node stringValue [lindex $locnNd 0]]}

    set dir [file split $locn]
    set current [lindex $dir 0]
    set remaining [lrange $dir 1 end]
    while {[llength $remaining]} {
	set current [file join $current [lindex $remaining 0]]
	set remaining [lrange $remaining 1 end]
	if {[file exists $current]} {
	    if {![file isdir $current]} {
		return {}
	    }
	} else {
	    file mkdir $current
	}
    }

    return $locn
}

# xslt::resources::copy --
#
#	Copy a resource.
#
# Arguments:
#	src	Resource to copy
#	dest	Destination for resource
#	args	not needed
#
# Results:
#	Resource copied

proc xslt::resources::copy {srcNd destNd args} {
    set src $srcNd
    catch {set src [dom::node stringValue [lindex $srcNd 0]]}
    set dest $destNd
    catch {set dest [dom::node stringValue [lindex $destNd 0]]}

    if {[catch {file copy $src $dest}]} {
	return 0
    } else {
	return 1
    }
}

# xslt::resources::move --
#
#	Move (rename) a resource.
#
# Arguments:
#	src	Resource to move
#	dest	Destination for resource
#	args	not needed
#
# Results:
#	Resource renamed

proc xslt::resources::move {srcNd destNd args} {
    set src $srcNd
    catch {set src [dom::node stringValue [lindex $srcNd 0]]}
    set dest $destNd
    catch {set dest [dom::node stringValue [lindex $destNd 0]]}

    if {[catch {file rename $src $dest}]} {
	return 0
    } else {
	return 1
    }
}
