#!/bin/sh
# the next line restarts using wish\
exec wish "$0" "$@" 

if {![info exists vTcl(sourcing)]} {

    package require Tk
    switch $tcl_platform(platform) {
	windows {
            option add *Button.padY 0
	}
	default {
            option add *Scrollbar.width 10
            option add *Scrollbar.highlightThickness 0
            option add *Scrollbar.elementBorderWidth 2
            option add *Scrollbar.borderWidth 2
	}
    }
    
}

#############################################################################
# Visual Tcl v1.60 Project
#


#################################
# VTCL LIBRARY PROCEDURES
#

if {![info exists vTcl(sourcing)]} {
#############################################################################
## Library Procedure:  Window

proc ::Window {args} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    global vTcl
    foreach {cmd name newname} [lrange $args 0 2] {}
    set rest    [lrange $args 3 end]
    if {$name == "" || $cmd == ""} { return }
    if {$newname == ""} { set newname $name }
    if {$name == "."} { wm withdraw $name; return }
    set exists [winfo exists $newname]
    switch $cmd {
        show {
            if {$exists} {
                wm deiconify $newname
            } elseif {[info procs vTclWindow$name] != ""} {
                eval "vTclWindow$name $newname $rest"
            }
            if {[winfo exists $newname] && [wm state $newname] == "normal"} {
                vTcl:FireEvent $newname <<Show>>
            }
        }
        hide    {
            if {$exists} {
                wm withdraw $newname
                vTcl:FireEvent $newname <<Hide>>
                return}
        }
        iconify { if $exists {wm iconify $newname; return} }
        destroy { if $exists {destroy $newname; return} }
    }
}
#############################################################################
## Library Procedure:  ::mclistbox::AdjustColumns

namespace eval ::mclistbox {
proc AdjustColumns {w {height {}}} {
    upvar ::mclistbox::${w}::widgets widgets
    upvar ::mclistbox::${w}::options options
    upvar ::mclistbox::${w}::misc    misc

    if {[string length $height] == 0} {
	set height [winfo height $widgets(text)]
    }

    # resize the height of each column so it matches the height
    # of the text widget, minus a few pixels. 
    incr height -4
    foreach id $misc(columns) {
	$widgets(frame$id) configure -height $height
    }
    
    # if we have a fillcolumn, change its width accordingly
    if {$options(-fillcolumn) != ""} {

	# make sure the column has been defined. If not, bail (?)
	if {![info exists widgets(frame$options(-fillcolumn))]} {
	    return
	}
	set frame $widgets(frame$options(-fillcolumn))
	set minwidth $misc(min-$frame)

	# compute current width of all columns
	set colwidth 0
	set col 0
	foreach id $misc(columns) {
	    if {![ColumnIsHidden $w $id] && $id != $options(-fillcolumn)} {
		incr colwidth [winfo reqwidth $widgets(frame$id)]
	    }
	}

	# this is just shorthand for later use...
	set id $options(-fillcolumn)

	# compute optimal width
	set optwidth [expr {[winfo width $widgets(text)] -  (2 * [$widgets(text) cget -padx])}]

	# compute the width of our fill column
	set newwidth [expr {$optwidth - $colwidth}]

	if {$newwidth < $minwidth} {
	    set newwidth $minwidth
	}

	# adjust the width of our fill column frame
	$widgets(frame$id) configure -width $newwidth
	    
    }
    InvalidateScrollbars $w
}
}
#############################################################################
## Library Procedure:  ::mclistbox::Build

namespace eval ::mclistbox {
proc Build {w args} {
    variable widgetOptions

    # create the namespace for this instance, and define a few
    # variables
    namespace eval ::mclistbox::$w {

	variable options
	variable widgets
	variable misc 
    }

    # this gives us access to the namespace variables within
    # this proc
    upvar ::mclistbox::${w}::widgets widgets
    upvar ::mclistbox::${w}::options options
    upvar ::mclistbox::${w}::misc    misc

    # initially we start out with no columns
    set misc(columns) {}

    # this is our widget -- a frame of class Mclistbox. Naturally,
    # it will contain other widgets. We create it here because
    # we need it to be able to set our default options.
    set widgets(this)   [frame  $w -class Mclistbox -takefocus 1]

    # this defines all of the default options. We get the
    # values from the option database. Note that if an array
    # value is a list of length one it is an alias to another
    # option, so we just ignore it
    foreach name [array names widgetOptions] {
	if {[llength $widgetOptions($name)] == 1} continue
	set optName  [lindex $widgetOptions($name) 0]
	set optClass [lindex $widgetOptions($name) 1]
	set options($name) [option get $w $optName $optClass]
    }

    # now apply any of the options supplied on the command
    # line. This may overwrite our defaults, which is OK
    if {[llength $args] > 0} {
	array set options $args
    }
    
    # the columns all go into a text widget since it has the 
    # ability to scroll.
    set widgets(text) [text $w.text  -width 0  -height 0  -padx 0  -pady 0  -wrap none  -borderwidth 0  -highlightthickness 0  -takefocus 0  -cursor {}  ]

    $widgets(text) configure -state disabled

    # here's the tricky part (shhhh... don't tell anybody!)
    # we are going to create column that completely fills
    # the base frame. We will use it to control the sizing
    # of the widget. The trick is, we'll pack it in the frame 
    # and then place the text widget over it so it is never
    # seen.

    set columnWidgets [NewColumn $w {__hidden__}]
    set widgets(hiddenFrame)   [lindex $columnWidgets 0]
    set widgets(hiddenListbox) [lindex $columnWidgets 1]
    set widgets(hiddenLabel)   [lindex $columnWidgets 2]

    # by default geometry propagation is turned off, but for this
    # super-secret widget we want it turned on. The idea is, we 
    # resize the listbox which resizes the frame which resizes the
    # whole shibang.
    pack propagate $widgets(hiddenFrame) on

    pack $widgets(hiddenFrame) -side top -fill both -expand y
    place $widgets(text) -x 0 -y 0 -relwidth 1.0 -relheight 1.0
    raise $widgets(text)

    # we will later rename the frame's widget proc to be our
    # own custom widget proc. We need to keep track of this
    # new name, so we'll define and store it here...
    set widgets(frame) ::mclistbox::${w}::$w

    # this moves the original frame widget proc into our
    # namespace and gives it a handy name
    rename ::$w $widgets(frame)

    # now, create our widget proc. Obviously (?) it goes in
    # the global namespace. All mclistbox widgets will actually
    # share the same widget proc to cut down on the amount of
    # bloat. 
    proc ::$w {command args}  "eval ::mclistbox::WidgetProc {$w} \$command \$args"

    # ok, the thing exists... let's do a bit more configuration. 
    if {[catch "Configure $widgets(this) [array get options]" error]} {
	catch {destroy $w}
    }

    # and be prepared to handle selections.. (this, for -exportselection
    # support)
    selection handle $w [list ::mclistbox::SelectionHandler $w get]

    return $w
}
}
#############################################################################
## Library Procedure:  ::mclistbox::Canonize

namespace eval ::mclistbox {
proc Canonize {w object opt} {
    variable widgetOptions
    variable columnOptions
    variable widgetCommands
    variable columnCommands
    variable labelCommands

    switch $object {
	command {
	    if {[lsearch -exact $widgetCommands $opt] >= 0} {
		return $opt
	    }

	    # command names aren't stored in an array, and there
	    # isn't a way to get all the matches in a list, so
	    # we'll stuff the columns in a temporary array so
	    # we can use [array names]
	    set list $widgetCommands
	    foreach element $list {
		set tmp($element) ""
	    }
	    set matches [array names tmp ${opt}*]
	}

	{label command} {
	    if {[lsearch -exact $labelCommands $opt] >= 0} {
		return $opt
	    }

	    # command names aren't stored in an array, and there
	    # isn't a way to get all the matches in a list, so
	    # we'll stuff the columns in a temporary array so
	    # we can use [array names]
	    set list $labelCommands
	    foreach element $list {
		set tmp($element) ""
	    }
	    set matches [array names tmp ${opt}*]
	}

	{column command} {
	    if {[lsearch -exact $columnCommands $opt] >= 0} {
		return $opt
	    }

	    # command names aren't stored in an array, and there
	    # isn't a way to get all the matches in a list, so
	    # we'll stuff the columns in a temporary array so
	    # we can use [array names]
	    set list $columnCommands
	    foreach element $list {
		set tmp($element) ""
	    }
	    set matches [array names tmp ${opt}*]
	}

	option {
	    if {[info exists widgetOptions($opt)]  && [llength $widgetOptions($opt)] == 3} {
		return $opt
	    }
	    set list [array names widgetOptions]
	    set matches [array names widgetOptions ${opt}*]
	}

	{column option} {
	    if {[info exists columnOptions($opt)]} {
		return $opt
	    }
	    set list [array names columnOptions]
	    set matches [array names columnOptions ${opt}*]
	}

	column {
	    upvar ::mclistbox::${w}::misc    misc

	    if {[lsearch -exact $misc(columns) $opt] != -1} {
		return $opt
	    }
	    
	    # column names aren't stored in an array, and there
	    # isn't a way to get all the matches in a list, so
	    # we'll stuff the columns in a temporary array so
	    # we can use [array names]
	    set list $misc(columns)
	    foreach element $misc(columns) {
		set tmp($element) ""
	    }
	    set matches [array names tmp ${opt}*]
	}
    }
    if {[llength $matches] == 0} {
	set choices [HumanizeList $list]
	return -code error "unknown $object \"$opt\"; must be one of $choices"

    } elseif {[llength $matches] == 1} {
	# deal with option aliases
	set opt [lindex $matches 0]
	switch $object {
	    option {
		if {[llength $widgetOptions($opt)] == 1} {
		    set opt $widgetOptions($opt)
		}
	    }

	    {column option} {
		if {[llength $columnOptions($opt)] == 1} {
		    set opt $columnOptions($opt)
		}
	    }
	}

	return $opt

    } else {
	set choices [HumanizeList $list]
	return -code error "ambiguous $object \"$opt\"; must be one of $choices"
    }
}
}
#############################################################################
## Library Procedure:  ::mclistbox::CheckColumnID

namespace eval ::mclistbox {
proc CheckColumnID {w id} {
    upvar ::mclistbox::${w}::misc    misc

    set id [::mclistbox::Canonize $w column $id]
    set index [lsearch -exact $misc(columns) $id]
    return $index
}
}
#############################################################################
## Library Procedure:  ::mclistbox::Column-add

namespace eval ::mclistbox {
proc Column-add {w args} {
    upvar ::mclistbox::${w}::widgets widgets
    upvar ::mclistbox::${w}::options options
    upvar ::mclistbox::${w}::misc    misc

    variable widgetOptions

    set id "column-[llength $misc(columns)]" ;# a suitable default

    # if the first argument doesn't have a "-" as the first
    # character, it is an id to associate with this column
    if {![string match {-*} [lindex $args 0]]} {
	# the first arg must be an id.
	set id [lindex $args 0]
	set args [lrange $args 1 end]
	if {[lsearch -exact $misc(columns) $id] != -1} {
	    return -code error "column \"$id\" already exists"
	}
    }

    # define some reasonable defaults, then add any specific
    # values supplied by the user
    set opts(-bitmap)     {}
    set opts(-image)      {}
    set opts(-labelrelief) raised
    set opts(-visible)    1
    set opts(-resizable)  1
    set opts(-position)   "end"
    set opts(-width)      20
    set opts(-background) $options(-background)
    set opts(-foreground) $options(-foreground)
    set opts(-font)       $options(-font)
    set opts(-label)      $id

    if {[expr {[llength $args]%2}] == 1} {
	# hmmm. An odd number of elements in args
	# if the last item is a valid option we'll give a different
	# error than if its not
	set option [::mclistbox::Canonize $w "column option" [lindex $args end]]
	return -code error "value for \"[lindex $args end]\" missing"
    }
    array set opts $args

    # figure out if we have any data in the listbox yet; we'll need
    # this information in a minute...
    if {[llength $misc(columns)] > 0} {
	set col0 [lindex $misc(columns) 0]
	set existingRows [$widgets(listbox$col0) size]
    } else {
	set existingRows 0
    }

    # create the widget and assign the associated paths to our array
    set widgetlist [NewColumn $w $id]

    set widgets(frame$id)   [lindex $widgetlist 0]
    set widgets(listbox$id) [lindex $widgetlist 1]
    set widgets(label$id)   [lindex $widgetlist 2]
    
    # add this column to the list of known columns
    lappend misc(columns) $id

    # configure the options. As a side effect, it will be inserted
    # in the text widget
    eval ::mclistbox::Column-configure {$w} {$id} [array get opts]

    # now, if there is any data already in the listbox, we need to
    # add a corresponding number of blank items. At least, I *think*
    # that's the right thing to do.
    if {$existingRows > 0} {
	set blanks {}
	for {set i 0} {$i < $existingRows} {incr i} {
	    lappend blanks {}
	}
	eval {$widgets(listbox$id)} insert end $blanks
    }

    InvalidateScrollbars $w
    return $id
}
}
#############################################################################
## Library Procedure:  ::mclistbox::Column-configure

namespace eval ::mclistbox {
proc Column-configure {w id args} {
    variable widgetOptions
    variable columnOptions

    upvar ::mclistbox::${w}::widgets widgets
    upvar ::mclistbox::${w}::options options
    upvar ::mclistbox::${w}::misc    misc

    # bail if they gave us a bogus id
    set index [CheckColumnID $w $id]

    # define some shorthand
    set listbox $widgets(listbox$id)
    set frame   $widgets(frame$id)
    set label   $widgets(label$id)

    if {[llength $args] == 0} {
	# hmmm. User must be wanting all configuration information
	# note that if the value of an array element is of length
	# one it is an alias, which needs to be handled slightly
	# differently
	set results {}
	foreach opt [lsort [array names columnOptions]] {
	    if {[llength $columnOptions($opt)] == 1} {
		set alias $columnOptions($opt)
		set optName $columnOptions($alias)
		lappend results [list $opt $optName]
	    } else {
		set optName  [lindex $columnOptions($opt) 0]
		set optClass [lindex $columnOptions($opt) 1]
		set default [option get $frame $optName $optClass]
		lappend results [list $opt $optName $optClass  $default $options($id:$opt)]
	    }
	}

	return $results


    } elseif {[llength $args] == 1} {

	# the user must be querying something... I need to get this
	# to return a bona fide list like the "real" configure 
	# command, but it's not a priority at the moment. I still
	# have to work on the option database support foo.
	set option [::mclistbox::Canonize $w "column option" [lindex $args 0]]

	set value $options($id:$option)
	set optName  [lindex $columnOptions($option) 0]
	set optClass [lindex $columnOptions($option) 1]
	set default  [option get $frame $optName $optClass]
	set results  [list $option $optName $optClass $default $value]
	return $results

    }

    # if we have an odd number of values, bail. 
    if {[expr {[llength $args]%2}] == 1} {
	# hmmm. An odd number of elements in args
	return -code error "value for \"[lindex $args end]\" missing"
    }
    
    # Great. An even number of options. Let's make sure they 
    # are all valid before we do anything. Note that Canonize
    # will generate an error if it finds a bogus option; otherwise
    # it returns the canonical option name
    foreach {name value} $args {
	set name [::mclistbox::Canonize $w "column option" $name]
	set opts($name) $value
    }

    # if we get to here, the user is wanting to set some options
    foreach option [array names opts] {
	set value $opts($option)
	set options($id:$option) $value

	switch -- $option {
	    -label {
		$label configure -text $value
	    }
	    
	    -image -
	    -bitmap {
		$label configure $option $value
	    }

	    -width {
		set font [$listbox cget -font]
		set factor [font measure $options(-font) "0"]
		set width [expr {$value * $factor}]

		$widgets(frame$id) configure -width $width
		set misc(min-$widgets(frame$id)) $width
		AdjustColumns $w
	    }
	    -font -
	    -foreground -
	    -background {
		if {[string length $value] == 0} {set value $options($option)}
		$listbox configure $option $value
	    }

	    -labelrelief {
		$widgets(label$id) configure -relief $value
	    }

	    -resizable {
		if {[catch {
		    if {$value} {
			set options($id:-resizable) 1
		    } else {
			set options($id:-resizable) 0
		    }
		} msg]} {
		    return -code error "expected boolean but got \"$value\""
		}
	    }

	    -visible {
		if {[catch {
		    if {$value} {
			set options($id:-visible) 1
			$widgets(text) configure -state normal
			$widgets(text) window configure 1.$index -window $frame
			$widgets(text) configure -state disabled

		    } else {
			set options($id:-visible) 0
			$widgets(text) configure -state normal
			$widgets(text) window configure 1.$index -window {}
			$widgets(text) configure -state disabled
		    }
		    InvalidateScrollbars $w
		} msg]} {
		    return -code error "expected boolean but got \"$value\""
		}

	    }

	    -position {
		if {[string compare $value "start"] == 0} {
		    set position 0

		} elseif {[string compare $value "end"] == 0} {

		    set position [expr {[llength $misc(columns)] -1}]
		} else {

		    # ought to check for a legal value here, but I'm 
		    # lazy
		    set position $value
		}

		if {$position >= [llength $misc(columns)]} {
		    set max [expr {[llength $misc(columns)] -1}]
		    return -code error "bad position; must be in the range of 0-$max"
		}

		# rearrange misc(columns) to reflect the new ordering
		set current [lsearch -exact $misc(columns) $id]
		set misc(columns) [lreplace $misc(columns) $current $current]
		set misc(columns) [linsert $misc(columns) $position $id]
		
		set frame $widgets(frame$id)
		$widgets(text) configure -state normal
		$widgets(text) window create 1.$position  -window $frame -stretch 1
		$widgets(text) configure -state disabled
 	    }

	}
    }
}
}
#############################################################################
## Library Procedure:  ::mclistbox::ColumnIsHidden

namespace eval ::mclistbox {
proc ColumnIsHidden {w id} {
    upvar ::mclistbox::${w}::widgets widgets
    upvar ::mclistbox::${w}::misc    misc
    
    set retval 1
    set col [lsearch -exact $misc(columns) $id]

    if {$col != ""} {
	set index "1.$col"
	catch {
	    set window [$widgets(text) window cget $index -window]
	    if {[string length $window] > 0 && [winfo exists $window]} {
		set retval 0
	    }
	}
    }
    return $retval
}
}
#############################################################################
## Library Procedure:  ::mclistbox::Configure

namespace eval ::mclistbox {
proc Configure {w args} {
    variable widgetOptions

    upvar ::mclistbox::${w}::widgets widgets
    upvar ::mclistbox::${w}::options options
    upvar ::mclistbox::${w}::misc    misc
    
    if {[llength $args] == 0} {
	# hmmm. User must be wanting all configuration information
	# note that if the value of an array element is of length
	# one it is an alias, which needs to be handled slightly
	# differently
	set results {}
	foreach opt [lsort [array names widgetOptions]] {
	    if {[llength $widgetOptions($opt)] == 1} {
		set alias $widgetOptions($opt)
		set optName $widgetOptions($alias)
		lappend results [list $opt $optName]
	    } else {
		set optName  [lindex $widgetOptions($opt) 0]
		set optClass [lindex $widgetOptions($opt) 1]
		set default [option get $w $optName $optClass]
		lappend results [list $opt $optName $optClass  $default $options($opt)]
	    }
	}

	return $results
    }
    
    # one argument means we are looking for configuration
    # information on a single option
    if {[llength $args] == 1} {
	set opt [::mclistbox::Canonize $w option [lindex $args 0]]

	set optName  [lindex $widgetOptions($opt) 0]
	set optClass [lindex $widgetOptions($opt) 1]
	set default [option get $w $optName $optClass]
	set results [list $opt $optName $optClass  $default $options($opt)]
	return $results
    }

    # if we have an odd number of values, bail. 
    if {[expr {[llength $args]%2}] == 1} {
	# hmmm. An odd number of elements in args
	return -code error "value for \"[lindex $args end]\" missing"
    }
    
    # Great. An even number of options. Let's make sure they 
    # are all valid before we do anything. Note that Canonize
    # will generate an error if it finds a bogus option; otherwise
    # it returns the canonical option name
    foreach {name value} $args {
	set name [::mclistbox::Canonize $w option $name]
	set opts($name) $value
    }

    # process all of the configuration options
    foreach option [array names opts] {

	set newValue $opts($option)
	if {[info exists options($option)]} {
	    set oldValue $options($option)
#	    set options($option) $newValue
	}

	switch -- $option {
	    -exportselection {
		if {$newValue} {
		    SelectionHandler $w own
		    set options($option) 1
		} else {
		    set options($option) 0
		}
	    }

	    -fillcolumn {
		# if the fill column changed, we need to adjust
		# the columns.
		AdjustColumns $w
		set options($option) $newValue
	    }

	    -takefocus {
		$widgets(frame) configure -takefocus $newValue
		set options($option) [$widgets(frame) cget $option]
	    }

	    -background {
		foreach id $misc(columns) {
		    $widgets(listbox$id) configure -background $newValue
		    $widgets(frame$id) configure   -background $newValue
		}
		$widgets(frame) configure -background $newValue

		$widgets(text) configure -background $newValue
		set options($option) [$widgets(frame) cget $option]
	    }

	    # { the following all must be applied to each listbox }
	    -foreground -
	    -font -
	    -selectborderwidth -
	    -selectforeground -
	    -selectbackground -
	    -setgrid {
		foreach id $misc(columns) {
		    $widgets(listbox$id) configure $option $newValue
		}
		$widgets(hiddenListbox) configure $option $newValue
		set options($option) [$widgets(hiddenListbox) cget $option]
	    }

	    # { the following all must be applied to each listbox and frame }
	    -cursor {
		foreach id $misc(columns) {
		    $widgets(listbox$id) configure $option $newValue
		    $widgets(frame$id) configure -cursor $newValue
		}

		# -cursor also needs to be applied to the 
		# frames of each column
		foreach id $misc(columns) {
		    $widgets(frame$id) configure -cursor $newValue
		}

		$widgets(hiddenListbox) configure $option $newValue
		set options($option) [$widgets(hiddenListbox) cget $option]
	    }

	    # { this just requires to pack or unpack the labels }
	    -labels {
		if {$newValue} {
		    set newValue 1
		    foreach id $misc(columns) {
			pack $widgets(label$id)  -side top -fill x -expand n  -before $widgets(listbox$id)
		    }
		    pack $widgets(hiddenLabel)  -side top -fill x -expand n  -before $widgets(hiddenListbox)

		} else {
		    set newValue 
		    foreach id $misc(columns) {
			pack forget $widgets(label$id)
		    }
		    pack forget $widgets(hiddenLabel)
		}
		set options($option) $newValue
	    }

	    -height {
		$widgets(hiddenListbox) configure -height $newValue
		InvalidateScrollbars $w
		set options($option) [$widgets(hiddenListbox) cget $option]
	    }

	    -width {
		if {$newValue == 0} {
		    return -code error "a -width of zero is not supported. "
		}

		$widgets(hiddenListbox) configure -width $newValue
		InvalidateScrollbars $w
		set options($option) [$widgets(hiddenListbox) cget $option]
	    }

	    # { the following all must be applied to each column frame }
	    -columnborderwidth -
	    -columnrelief {
		regsub {column} $option {} listboxoption
		foreach id $misc(columns) {
		    $widgets(listbox$id) configure $listboxoption $newValue
		}
		$widgets(hiddenListbox) configure $listboxoption $newValue
		set options($option) [$widgets(hiddenListbox) cget  $listboxoption]
	    }

	    -resizablecolumns {
		if {$newValue} {
		    set options($option) 1
		} else {
		    set options($option) 0
		}
	    }
	    
	    # { the following all must be applied to each column header }
	    -labelimage -
	    -labelheight -
	    -labelrelief -
	    -labelfont -
	    -labelanchor -
	    -labelbackground -
	    -labelforeground -
	    -labelborderwidth {
		regsub {label} $option {} labeloption
		foreach id $misc(columns) {
		    $widgets(label$id) configure $labeloption $newValue
		}
		$widgets(hiddenLabel) configure $labeloption $newValue
		set options($option) [$widgets(hiddenLabel) cget $labeloption]
	    }

	    # { the following apply only to the topmost frame}
	    -borderwidth -
	    -highlightthickness -
	    -highlightcolor -
	    -highlightbackground -
	    -relief {
		$widgets(frame) configure $option $newValue
		set options($option) [$widgets(frame) cget $option]
	    }

	    -selectmode {
		set options($option) $newValue
	    }

	    -selectcommand {
		set options($option) $newValue
	    }

	    -xscrollcommand {
		InvalidateScrollbars $w
		set options($option) $newValue
	    }

	    -yscrollcommand {
		InvalidateScrollbars $w
		set options($option) $newValue
	    }
	}
    }
}
}
#############################################################################
## Library Procedure:  ::mclistbox::DestroyHandler

namespace eval ::mclistbox {
proc DestroyHandler {w} {

    # kill off any idle event we might have pending
    if {[info exists ::mclistbox::${w}::misc(afterid)]} {
	catch {
	    after cancel $::mclistbox::${w}::misc(afterid)
	    unset ::mclistbox::${w}::misc(afterid)
	}
    }

    # if the widget actually being destroyed is of class Mclistbox,
    # crush the namespace and kill the proc. Get it? Crush. Kill. 
    # Destroy. Heh. Danger Will Robinson! Oh, man! I'm so funny it
    # brings tears to my eyes.
    if {[string compare [winfo class $w] "Mclistbox"] == 0} {
	namespace delete ::mclistbox::$w
	rename $w {}
    }

}
}
#############################################################################
## Library Procedure:  ::mclistbox::FindResizableNeighbor

namespace eval ::mclistbox {
proc FindResizableNeighbor {w id {direction right}} {
    upvar ::mclistbox::${w}::widgets       widgets
    upvar ::mclistbox::${w}::options       options
    upvar ::mclistbox::${w}::misc          misc


    if {$direction == "right"} {
	set incr 1
	set stop [llength $misc(columns)]
	set start [expr {[lsearch -exact $misc(columns) $id] + 1}]
    } else {
	set incr -1
	set stop -1
	set start [expr {[lsearch -exact $misc(columns) $id] - 1}]
    } 

    for {set i $start} {$i != $stop} {incr i $incr} {
	set col [lindex $misc(columns) $i]
	if {![ColumnIsHidden $w $col] && $options($col:-resizable)} {
	    return $col
	}
    }
    return ""
}
}
#############################################################################
## Library Procedure:  ::mclistbox::HumanizeList

namespace eval ::mclistbox {
proc HumanizeList {list} {

    if {[llength $list] == 1} {
	return [lindex $list 0]
    } else {
	set list [lsort $list]
	set secondToLast [expr {[llength $list] -2}]
	set most [lrange $list 0 $secondToLast]
	set last [lindex $list end]

	return "[join $most {, }] or $last"
    }
}
}
#############################################################################
## Library Procedure:  ::mclistbox::Init

namespace eval ::mclistbox {
proc Init {} {
    variable widgetOptions
    variable columnOptions
    variable itemConfigureOptions
    variable widgetCommands
    variable columnCommands
    variable labelCommands

    # here we match up command line options with option database names
    # and classes. As it turns out, this is a handy reference of all of the
    # available options. Note that if an item has a value with only one
    # item (like -bd, for example) it is a synonym and the value is the
    # actual item.

    array set widgetOptions [list  -background          {background          Background}  -bd                  -borderwidth  -bg                  -background  -borderwidth         {borderWidth         BorderWidth}  -columnbd            -columnborderwidth  -columnborderwidth   {columnBorderWidth   BorderWidth}  -columnrelief        {columnRelief        Relief}  -cursor              {cursor              Cursor}  -exportselection     {exportSelection     ExportSelection}  -fg                  -foreground  -fillcolumn          {fillColumn          FillColumn}  -font                {font                Font}  -foreground          {foreground          Foreground}  -height              {height              Height}  -highlightbackground {highlightBackground HighlightBackground}  -highlightcolor      {highlightColor      HighlightColor}  -highlightthickness  {highlightThickness  HighlightThickness}  -labelanchor         {labelAnchor         Anchor}  -labelbackground     {labelBackground     Background}  -labelbd             -labelborderwidth  -labelbg             -labelbackground  -labelborderwidth    {labelBorderWidth    BorderWidth}  -labelfg             -labelforeground  -labelfont           {labelFont           Font}  -labelforeground     {labelForeground     Foreground}  -labelheight         {labelHeight         Height}  -labelimage          {labelImage          Image}  -labelrelief         {labelRelief         Relief}  -labels              {labels              Labels}  -relief              {relief              Relief}  -resizablecolumns    {resizableColumns    ResizableColumns}  -selectbackground    {selectBackground    Foreground}  -selectborderwidth   {selectBorderWidth   BorderWidth}  -selectcommand       {selectCommand       Command}  -selectforeground    {selectForeground    Background}  -selectmode          {selectMode          SelectMode}  -setgrid             {setGrid             SetGrid}  -takefocus           {takeFocus           TakeFocus}  -width               {width               Width}  -xscrollcommand      {xScrollCommand      ScrollCommand}  -yscrollcommand      {yScrollCommand      ScrollCommand}  ]

    # and likewise for column-specific stuff. 
    array set columnOptions [list  -background         {background           Background}  -bitmap		{bitmap               Bitmap}  -font               {font                 Font}  -foreground         {foreground           Foreground}  -image              {image                Image}  -label 		{label                Label}  -position           {position             Position}  -labelrelief        {labelrelief          Labelrelief}  -resizable          {resizable            Resizable}  -visible            {visible              Visible}  -width              {width                Width}  ]

    # and likewise for item-specific stuff. 
    array set itemConfigureOptions [list  -background         {background           Background}  -foreground         {foreground           Foreground}  -selectbackground   {selectbackground     SelectBackground}  -selectforeground   {selectforeground     SelectForeground}  ]
	    
    # this defines the valid widget commands. It's important to
    # list them here; we use this list to validate commands and
    # expand abbreviations.
    set widgetCommands [list  activate	 bbox       cget     column    configure   curselection delete     get      index     insert	itemconfigure  label        nearest    scan     see       selection   size         xview      yview
    ]

    set columnCommands [list add cget configure delete names nearest]
    set labelCommands  [list bind]

    ######################################################################
    #- this initializes the option database. Kinda gross, but it works
    #- (I think). 
    ######################################################################

    set packages [package names]

    # why check for the Tk package? This lets us be sourced into 
    # an interpreter that doesn't have Tk loaded, such as the slave
    # interpreter used by pkg_mkIndex. In theory it should have no
    # side effects when run 
    if {[lsearch -exact [package names] "Tk"] != -1} {

	# compute a widget name we can use to create a temporary widget
	set tmpWidget ".__tmp__"
	set count 0
	while {[winfo exists $tmpWidget] == 1} {
	    set tmpWidget ".__tmp__$count"
	    incr count
	}

	# steal options from the listbox
	# we want darn near all options, so we'll go ahead and do
	# them all. No harm done in adding the one or two that we
	# don't use.
	listbox $tmpWidget
		
	foreach foo [$tmpWidget configure] {
	    if {[llength $foo] == 5} {
		set option [lindex $foo 1]
		set value [lindex $foo 4]
				
		option add *Mclistbox.$option $value widgetDefault

		# these options also apply to the individual columns...
		if {[string compare $option "foreground"] == 0  || [string compare $option "background"] == 0  || [string compare $option "font"] == 0} {
		    option add *Mclistbox*MclistboxColumn.$option $value  widgetDefault
		}
	    }
	}
	destroy $tmpWidget

	# steal some options from label widgets; we only want a subset
	# so we'll use a slightly different method. No harm in *not*
	# adding in the one or two that we don't use... :-)
	label $tmpWidget
	foreach option [list Anchor Background Font  Foreground Height Image  ] {
	    set values [$tmpWidget configure -[string tolower $option]]
	    option add *Mclistbox.label$option [lindex $values 3]
	}
	destroy $tmpWidget

	# these are unique to us...
	option add *Mclistbox.columnBorderWidth   0      widgetDefault
	option add *Mclistbox.columnRelief        flat   widgetDefault
	option add *Mclistbox.labelBorderWidth    1      widgetDefault
	option add *Mclistbox.labelRelief         raised widgetDefault
	option add *Mclistbox.labels              1      widgetDefault
	option add *Mclistbox.resizableColumns    1      widgetDefault
	option add *Mclistbox.selectcommand       {}     widgetDefault
	option add *Mclistbox.fillcolumn          {}     widgetDefault

	# column options
	option add *Mclistbox*MclistboxColumn.visible       1      widgetDefault
	option add *Mclistbox*MclistboxColumn.resizable     1      widgetDefault
	option add *Mclistbox*MclistboxColumn.position      end    widgetDefault
	option add *Mclistbox*MclistboxColumn.label         ""     widgetDefault
	option add *Mclistbox*MclistboxColumn.width         0      widgetDefault
	option add *Mclistbox*MclistboxColumn.bitmap        ""     widgetDefault
	option add *Mclistbox*MclistboxColumn.image         ""     widgetDefault
    }

    ######################################################################
    # define the class bindings
    ######################################################################
    
    SetClassBindings

}
}
#############################################################################
## Library Procedure:  ::mclistbox::Insert

namespace eval ::mclistbox {
proc Insert {w index arglist} {

    upvar ::mclistbox::${w}::widgets widgets
    upvar ::mclistbox::${w}::options options
    upvar ::mclistbox::${w}::misc    misc

    foreach list $arglist {
	# make sure we have enough elements for each column
	for {set i [llength $list]} {$i < [llength $misc(columns)]} {incr i} {
	    lappend list {}
	}

	set column 0
	foreach id $misc(columns) {
	    $widgets(listbox$id) insert $index [lindex $list $column]
	    incr column
	}

	# we also want to add a bogus item to the hidden listbox. Why?
	# For standard listboxes, if you specify a height of zero the
	# listbox will resize to be just big enough to hold all the lines.
	# Since we use a hidden listbox to regulate the size of the widget
	# and we want this same behavior, this listbox needs the same number
	# of elements as the visible listboxes
	#
	# (NB: we might want to make this listbox contain the contents
	# of all columns as a properly formatted list; then the get 
	# command can query this listbox instead of having to query
	# each individual listbox. The disadvantage is that it doubles
	# the memory required to hold all the data)
	$widgets(hiddenListbox) insert $index "x"
    }
    return ""
}
}
#############################################################################
## Library Procedure:  ::mclistbox::InvalidateScrollbars

namespace eval ::mclistbox {
proc InvalidateScrollbars {w} {

    upvar ::mclistbox::${w}::widgets widgets
    upvar ::mclistbox::${w}::options options
    upvar ::mclistbox::${w}::misc    misc

    if {![info exists misc(afterid)]} {
	set misc(afterid)  [after idle "catch {::mclistbox::UpdateScrollbars $w}"]
    }
}
}
#############################################################################
## Library Procedure:  ::mclistbox::ItemConfigure

namespace eval ::mclistbox {
proc ItemConfigure {w args} {
    variable itemConfigureOptions

    upvar ::mclistbox::${w}::widgets widgets
    upvar ::mclistbox::${w}::options options
    upvar ::mclistbox::${w}::misc    misc
    
    if {[llength $args] == 0} {
	# hmmm. User must be wanting all configuration information
	# note that if the value of an array element is of length
	# one it is an alias, which needs to be handled slightly
	# differently
	#
	# Broken! This seems to return options from hidden listbox. Not the
	# changed item. 
	#
	set results {}
	foreach opt [lsort [array names itemConfigureOptions]] {
	    if {[llength $itemConfigureOptions($opt)] == 1} {
		set alias $itemConfigureOptions($opt)
		set optName $itemConfigureOptions($alias)
		lappend results [list $opt $optName]
	    } else {
		set optName  [lindex $itemConfigureOptions($opt) 0]
		set optClass [lindex $itemConfigureOptions($opt) 1]
		set default [option get $w $optName $optClass]
		lappend results [list $opt $optName $optClass  $default $options($opt)]
	    }
	}
	return $results
    }
    
    # one argument means we are looking for configuration
    # information on a single option
    #
    # Broken! This seems to return options from hidden listbox. Not the
    # changed item. 
    #
    if {[llength $args] == 2} {
	set opt [::mclistbox::Canonize $w option [lindex $args 1]]

	set optName  [lindex $itemConfigureOptions($opt) 0]
	set optClass [lindex $itemConfigureOptions($opt) 1]
	set default [option get $w $optName $optClass]
	set results [list $opt $optName $optClass  $default $options($opt)]
	return $results
    }

    # The itemconfigure option should have an odd number of options. 
    if {[expr {[llength $args]%2}] == 1} {
	# hmmm. An odd number of elements in args
	
	set itemIndex [lindex $args 0 ]
	set newArgs [ lrange $args 1 end ]
    }
    
    # Great. An odd number of options. Let's make sure they 
    # are all valid before we do anything. Note that Canonize
    # will generate an error if it finds a bogus option; otherwise
    # it returns the canonical option name
    foreach {name value} $newArgs {
	set name [::mclistbox::Canonize $w option $name]
	set opts($name) $value
    }

    # process all of the configuration options
    foreach option [array names opts] {

	set newValue $opts($option)
	if {[info exists options($option)]} {
	    set oldValue $options($option)
	}

	switch -- $option {
	    -exportselection {
		if {$newValue} {
		    SelectionHandler $w own
		    set options($option) 1
		} else {
		    set options($option) 0
		}
	    }

	    # { the following all must be applied to each listbox }
	    -background -
	    -foreground -
	    -selectforeground -
	    -selectbackground {
		foreach id $misc(columns) {
		    $widgets(listbox$id) itemconfigure $itemIndex $option $newValue
		}
		$widgets(hiddenListbox) itemconfigure $itemIndex $option $newValue
		set options($option) [$widgets(hiddenListbox) cget $option]
	    }
	}
    }
}
}
#############################################################################
## Library Procedure:  ::mclistbox::LabelEvent

namespace eval ::mclistbox {
proc LabelEvent {w id code} {
    upvar ::mclistbox::${w}::widgets widgets
    upvar ::mclistbox::${w}::options options

    # only fire the binding if the cursor is our default cursor
    # (ie: if we aren't in a "resize zone")
    set cursor [$widgets(label$id) cget -cursor]
    if {[string compare $cursor $options(-cursor)] == 0} {
	uplevel \#0 $code
    }
}
}
#############################################################################
## Library Procedure:  ::mclistbox::MassageIndex

namespace eval ::mclistbox {
proc MassageIndex {w index} {
    upvar ::mclistbox::${w}::widgets   widgets
    upvar ::mclistbox::${w}::misc      misc

    if {[regexp {@([0-9]+),([0-9]+)} $index matchvar x y]} {
	set id [lindex $misc(columns) 0]
	
	incr y -[winfo y $widgets(listbox$id)]
	incr y -[winfo y $widgets(frame$id)]
	incr x [winfo x $widgets(listbox$id)]
	incr x [winfo x $widgets(frame$id)]

	set index @${x},${y}
    }

    return $index
}
}
#############################################################################
## Library Procedure:  ::mclistbox::NewColumn

namespace eval ::mclistbox {
proc NewColumn {w id} {
    upvar ::mclistbox::${w}::widgets   widgets
    upvar ::mclistbox::${w}::options   options
    upvar ::mclistbox::${w}::misc      misc
    upvar ::mclistbox::${w}::columnID  columnID

    # the columns are all children of the text widget we created... 
    set frame      [frame $w.frame$id  -takefocus 0  -highlightthickness 0  -class MclistboxColumn  -background $options(-background)  ]

    set listbox    [listbox $frame.listbox  -takefocus 0  -bd 0  -setgrid $options(-setgrid)  -exportselection false  -selectmode $options(-selectmode)  -highlightthickness 0  ]

    set label      [label $frame.label  -takefocus 0  -relief raised  -bd 1  -highlightthickness 0  ]

    # define mappings from widgets to columns
    set columnID($label) $id
    set columnID($frame) $id
    set columnID($listbox) $id

    # we're going to associate a new bindtag for the label to
    # handle our resize bindings. Why? We want the bindings to
    # be specific to this widget but we don't want to use the
    # widget name. If we use the widget name then the bindings
    # could get mixed up with user-supplied bindigs (via the 
    # "label bind" command). 
    set tag MclistboxLabel
    bindtags $label  [list MclistboxMouseBindings $label]

    # reconfigure the label based on global options
    foreach option [list bd image height relief font anchor  background foreground borderwidth] {
	if {[info exists options(-label$option)]  && $options(-label$option) != ""} {
	    $label configure -$option $options(-label$option)
	}
    }

    # reconfigure the column based on global options
    foreach option [list borderwidth relief] {
	if {[info exists options(-column$option)]  && $options(-column$option) != ""} {
	    $frame configure -$option $options(-column$option)
	}
    }

    # geometry propagation must be off so we can control the size
    # of the listbox by setting the size of the containing frame
    pack propagate $frame off

    pack $label   -side top -fill x -expand n
    pack $listbox -side top -fill both -expand y -pady 2

    # any events that happen in the listbox gets handled by the class
    # bindings. This has the unfortunate side effect 
    bindtags $listbox [list $w Mclistbox all]

    # return a list of the widgets we created.
    return [list $frame $listbox $label]
}
}
#############################################################################
## Library Procedure:  ::mclistbox::ResizeEvent

namespace eval ::mclistbox {
proc ResizeEvent {w type widget x X Y} {

    upvar ::mclistbox::${w}::widgets       widgets
    upvar ::mclistbox::${w}::options       options
    upvar ::mclistbox::${w}::misc          misc
    upvar ::mclistbox::${w}::columnID      columnID

    # if the widget doesn't allow resizable cursors, there's
    # nothing here to do...
    if {!$options(-resizablecolumns)} {
	return
    }

    # this lets us keep track of some internal state while
    # the user is dragging the mouse
    variable drag

    # this lets us define a small window around the edges of
    # the column. 
    set threshold [expr {$options(-labelborderwidth) + 4}]

    # this is what we use for the "this is resizable" cursor
    set resizeCursor sb_h_double_arrow

    # if we aren't over an area that we care about, bail.
    if {![info exists columnID($widget)]} {
	return
    }

    # id refers to the column name
    set id $columnID($widget)

    switch $type {

	buttonpress {
	    # we will do all the work of initiating a drag only if
	    # the cursor is not the defined cursor. In theory this
	    # will only be the case if the mouse moves over the area
	    # in which a drag can happen.
	    if {[$widgets(label$id) cget -cursor] == $resizeCursor} {
		if {$x <= $threshold} {
		    set lid [::mclistbox::FindResizableNeighbor $w $id left]
		    if {$lid == ""} return
		    set drag(leftFrame)  $widgets(frame$lid)
		    set drag(rightFrame) $widgets(frame$id)

		    set drag(leftListbox)  $widgets(listbox$lid)
		    set drag(rightListbox) $widgets(listbox$id)

		} else {
		    set rid [::mclistbox::FindResizableNeighbor $w $id right]
		    if {$rid == ""} return
		    set drag(leftFrame)  $widgets(frame$id)
		    set drag(rightFrame) $widgets(frame$rid)

		    set drag(leftListbox)  $widgets(listbox$id)
		    set drag(rightListbox) $widgets(listbox$rid)

		}
		

		set drag(leftWidth)  [winfo width $drag(leftFrame)]
		set drag(rightWidth) [winfo width $drag(rightFrame)]

		# it seems to be a fact that windows can never be 
		# less than one pixel wide. So subtract that one pixel
		# from our max deltas...
		set drag(maxDelta)   [expr {$drag(rightWidth) - 1}]
		set drag(minDelta)  -[expr {$drag(leftWidth) - 1}]

		set drag(x) $X
	    }
	}

	motion {
	    if {[info exists drag(x)]} {return}

	    # this is just waaaaay too much work for a motion 
	    # event, IMO.

	    set resizable 0

	    # is the column the user is over resizable?
	    if {!$options($id:-resizable)} {return}

	    # did the user click on the left of a column? 
	    if {$x < $threshold} {
		set leftColumn [::mclistbox::FindResizableNeighbor $w $id left]
		if {$leftColumn != ""} {
		    set resizable 1
		}

	    } elseif {$x > [winfo width $widget] - $threshold} {
		set rightColumn [::mclistbox::FindResizableNeighbor $w $id  right]
		if {$rightColumn != ""} {
		    set resizable 1
		}
	    }

	    # if it's resizable, change the cursor 
	    set cursor [$widgets(label$id) cget -cursor]
	    if {$resizable && $cursor != $resizeCursor} {
		$widgets(label$id) configure -cursor $resizeCursor

	    } elseif {!$resizable && $cursor == $resizeCursor} {
		$widgets(label$id) configure -cursor $options(-cursor)
	    }
	}

	drag {
	    # if the state is set up, do the drag...
	    if {[info exists drag(x)]} {

		set delta [expr {$X - $drag(x)}]
		if {$delta >= $drag(maxDelta)} {
		    set delta $drag(maxDelta)

		} elseif {$delta <= $drag(minDelta)} {
		    set delta $drag(minDelta)
		}

		set lwidth [expr {$drag(leftWidth) + $delta}]
		set rwidth [expr {$drag(rightWidth) - $delta}]

		$drag(leftFrame)   configure -width $lwidth
		$drag(rightFrame)  configure -width $rwidth

	    }
	}

	buttonrelease {
	    set fillColumnID $options(-fillcolumn)
	    if {[info exists drag(x)] && $fillColumnID != {}} {
		set fillColumnFrame $widgets(frame$fillColumnID)
		if {[string compare $drag(leftFrame) $fillColumnFrame] == 0  || [string compare $drag(rightFrame) $fillColumnFrame] == 0} {
		    set width [$fillColumnFrame cget -width]
		    set misc(minFillColumnSize) $width
		}
		set misc(min-$drag(leftFrame))  [$drag(leftFrame) cget -width]
		set misc(min-$drag(rightFrame)) [$drag(rightFrame) cget -width]
	    }

	    # reset the state and the cursor
	    catch {unset drag}
	    $widgets(label$id) configure -cursor $options(-cursor)

	}
    }
}
}
#############################################################################
## Library Procedure:  ::mclistbox::SelectionHandler

namespace eval ::mclistbox {
proc SelectionHandler {w type {offset {}} {length {}}} {
    upvar ::mclistbox::${w}::options   options
    upvar ::mclistbox::${w}::misc      misc
    upvar ::mclistbox::${w}::widgets   widgets

    switch -exact $type {

	own {
	    selection own  -command [list ::mclistbox::SelectionHandler $w lose]  -selection PRIMARY  $w
	}

	lose {
	    if {$options(-exportselection)} {
		foreach id $misc(columns) {
		    $widgets(listbox$id) selection clear 0 end
		}
	    }
	}

	get {
	    set end [expr {$length + $offset - 1}]

	    set column [lindex $misc(columns) 0]
	    set curselection [$widgets(listbox$column) curselection]

	    # this is really, really slow (relatively speaking).
	    # but the only way I can think of to speed this up
	    # is to duplicate all the data in our hidden listbox,
	    # which I really don't want to do because of memory
	    # considerations.
	    set data ""
	    foreach index $curselection {
		set rowdata [join [::mclistbox::WidgetProc-get $w $index]  "\t"]
		lappend data $rowdata
	    }
	    set data [join $data "\n"]
	    return [string range $data $offset $end]
	}

    }
}
}
#############################################################################
## Library Procedure:  ::mclistbox::SetBindings

namespace eval ::mclistbox {
proc SetBindings {w} {
    upvar ::mclistbox::${w}::widgets widgets
    upvar ::mclistbox::${w}::options options
    upvar ::mclistbox::${w}::misc    misc

    # we must do this so that the columns fill the text widget in
    # the y direction
    bind $widgets(text) <Configure>  [list ::mclistbox::AdjustColumns $w %h]

}
}
#############################################################################
## Library Procedure:  ::mclistbox::SetClassBindings

namespace eval ::mclistbox {
proc SetClassBindings {} {
    # this allows us to clean up some things when we go away
    bind Mclistbox <Destroy> [list ::mclistbox::DestroyHandler %W]

    # steal all of the standard listbox bindings. Note that if a user
    # clicks in a column, %W will return that column. This is bad,
    # so we have to make a substitution in all of the bindings to
    # compute the real widget name (ie: the name of the topmost 
    # frame)
    foreach event [bind Listbox] {
	set binding [bind Listbox $event]
	regsub -all {%W} $binding {[::mclistbox::convert %W -W]} binding
	regsub -all {%x} $binding {[::mclistbox::convert %W -x %x]} binding
	regsub -all {%y} $binding {[::mclistbox::convert %W -y %y]} binding
	bind Mclistbox $event $binding
    }

    # these define bindings for the column labels for resizing. Note
    # that we need both the name of this widget (calculated by $this)
    # as well as the specific widget that the event occured over.
    # Also note that $this is a constant string that gets evaluated
    # when the binding fires.
    # What a pain.
    set this {[::mclistbox::convert %W -W]}
    bind MclistboxMouseBindings <ButtonPress-1>  "::mclistbox::ResizeEvent $this buttonpress %W %x %X %Y"
    bind MclistboxMouseBindings <ButtonRelease-1>  "::mclistbox::ResizeEvent $this buttonrelease %W %x %X %Y"
    bind MclistboxMouseBindings <Enter>  "::mclistbox::ResizeEvent $this motion %W %x %X %Y"
    bind MclistboxMouseBindings <Motion>  "::mclistbox::ResizeEvent $this motion %W %x %X %Y"
    bind MclistboxMouseBindings <B1-Motion>  "::mclistbox::ResizeEvent $this drag %W %x %X %Y"
}
}
#############################################################################
## Library Procedure:  ::mclistbox::UpdateScrollbars

namespace eval ::mclistbox {
proc UpdateScrollbars {w} {
    upvar ::mclistbox::${w}::widgets widgets
    upvar ::mclistbox::${w}::options options
    upvar ::mclistbox::${w}::misc    misc

    if {![winfo ismapped $w]} {
	catch {unset misc(afterid)}
	return
    }

    update idletasks
    if {[llength $misc(columns)] > 0} {
	if {[string length $options(-yscrollcommand)] != 0} {
	    set col0 [lindex $misc(columns) 0]
	    set yview [$widgets(listbox$col0) yview]
	    uplevel #0 $options(-yscrollcommand) $yview
	}

	if {[string length $options(-xscrollcommand)] != 0} {
	    set col0 [lindex $misc(columns) 0]
	    set xview [$widgets(text) xview]
	    uplevel #0 $options(-xscrollcommand) $xview
	}
    }
    catch {unset misc(afterid)}
}
}
#############################################################################
## Library Procedure:  ::mclistbox::WidgetProc

namespace eval ::mclistbox {
proc WidgetProc {w command args} {
    variable widgetOptions

    upvar ::mclistbox::${w}::widgets   widgets
    upvar ::mclistbox::${w}::options   options
    upvar ::mclistbox::${w}::misc      misc
    upvar ::mclistbox::${w}::columnID  columnID

    set command [::mclistbox::Canonize $w command $command]

    # some commands have subcommands. We'll check for that here 
    # and mung the command and args so that we can treat them as 
    # distinct commands in the following switch statement
    if {[string compare $command "column"] == 0} {
	set subcommand [::mclistbox::Canonize $w "column command"  [lindex $args 0]]
	set command "$command-$subcommand"
	set args [lrange $args 1 end]

    } elseif {[string compare $command "label"] == 0} {
	set subcommand [::mclistbox::Canonize $w "label command"  [lindex $args 0]]
	set command "$command-$subcommand"
	set args [lrange $args 1 end]
    }

    set result ""
    catch {unset priorSelection}

    # here we go. Error checking be damned!
    switch $command {
	xview {
	    # note that at present, "xview <index>" is broken. I'm
	    # not even sure how to do it. Unless I attach our hidden
	    # listbox to the scrollbar and use it. Hmmm..... I'll
	    # try that later. (FIXME)
	    set result [eval {$widgets(text)} xview $args]
	    InvalidateScrollbars $w
	}

	yview {
	    if {[llength $args] == 0} {
		# length of zero means to fetch the yview; we can
		# get this from a single listbox
		set result [$widgets(hiddenListbox) yview]

	    } else {

		# if it's one argument, it's an index. We'll pass that 
		# index through the index command to properly translate
		# @x,y indicies, and place the value back in args
		if {[llength $args] == 1} {
		    set index [::mclistbox::MassageIndex $w [lindex $args 0]]
		    set args [list $index]
		}

		# run the yview command on every column.
		foreach id $misc(columns) {
		    eval {$widgets(listbox$id)} yview $args
		}
		eval {$widgets(hiddenListbox)} yview $args

		InvalidateScrollbars $w

		set result ""
	    }
	}

	activate {
	    if {[llength $args] != 1} {
		return -code error "wrong \# of args: should be $w activate index"
	    }
	    set index [::mclistbox::MassageIndex $w [lindex $args 0]]

	    foreach id $misc(columns) {
		$widgets(listbox$id) activate $index
	    }
	    set result ""
	}

	bbox {
	    if {[llength $args] != 1} {
		return -code error "wrong \# of args: should be $w bbox index"
	    }
	    # get a real index. This will adjust @x,y indicies
	    # to account for the label, if any.
	    set index [::mclistbox::MassageIndex $w [lindex $args 0]]

	    set id [lindex $misc(columns) 0]

	    # we can get the x, y, and height from the first 
	    # column.
	    set bbox [$widgets(listbox$id) bbox $index]
	    if {[string length $bbox] == 0} {return ""}

	    foreach {x y w h} $bbox {}
	    
	    # the x and y coordinates have to be adjusted for the
	    # fact that the listbox is inside a frame, and the 
	    # frame is inside a text widget. All of those add tiny
	    # offsets. Feh.
	    incr y [winfo y $widgets(listbox$id)]
	    incr y [winfo y $widgets(frame$id)]
	    incr x [winfo x $widgets(listbox$id)]
	    incr x [winfo x $widgets(frame$id)]

	    # we can get the width by looking at the relative x 
	    # coordinate of the right edge of the last column
	    set id [lindex $misc(columns) end]
	    set w [expr {[winfo width $widgets(frame$id)] +  [winfo x $widgets(frame$id)]}]
	    set bbox [list $x $y [expr {$x + $w}] $h]
	    set result $bbox
	}

	label-bind {
	    # we are just too clever for our own good. (that's a 
	    # polite way of saying this is more complex than it
	    # needs to be)

	    set id [lindex $args 0]
	    set index [CheckColumnID $w $id]

	    set args [lrange $args 1 end]
	    if {[llength $args] == 0} {
		set result [bind $widgets(label$id)]
	    } else {

		# when we create a binding, we'll actually have the 
		# binding run our own command with the user's command
		# as an argument. This way we can do some sanity checks
		# before running the command. So, when querying a binding
		# we need to only return the user's code
		set sequence [lindex $args 0]
		if {[llength $args] == 1} {
		    set result [lindex [bind $widgets(label$id) $sequence] end]
		} else {
		
		    # replace %W with our toplevel frame, then
		    # do the binding
		    set code [lindex $args 1]
		    regsub -all {%W} $code $w code
		    
		    set result [bind $widgets(label$id) $sequence  [list ::mclistbox::LabelEvent $w $id $code]]
		}
	    }
	}

	column-add {
	    eval ::mclistbox::Column-add {$w} $args
	    AdjustColumns $w
	    set result ""
	}

	column-delete {
	    foreach id $args {
		set index [CheckColumnID $w $id]

		# remove the reference from our list of columns
		set misc(columns) [lreplace $misc(columns) $index $index]

		# whack the widget
		destroy $widgets(frame$id)

		# clear out references to the individual widgets
		unset widgets(frame$id)
		unset widgets(listbox$id)
		unset widgets(label$id)
	    }
	    InvalidateScrollbars $w
	    set result ""
	}

	column-cget {
	    if {[llength $args] != 2} {
		return -code error "wrong # of args: should be \"$w column cget name option\""
	    }
	    set id [::mclistbox::Canonize $w column [lindex $args 0]]
	    set option [lindex $args 1]
	    set data [::mclistbox::Column-configure $w $id $option]
	    set result [lindex $data 4]
	}

	column-configure {
	    set id [::mclistbox::Canonize $w column [lindex $args 0]]
	    set args [lrange $args 1 end]
	    set result [eval ::mclistbox::Column-configure {$w} {$id} $args]
	}

	column-names {
	    if {[llength $args] != 0} {
		return -code error "wrong # of args: should be \"$w column names\""
	    }
	    set result $misc(columns)
	}

	column-nearest {
	    if {[llength $args] != 1} {
		return -code error "wrong # of args: should be \"$w column nearest x\""
	    }

	    set x [lindex $args 0]
	    set tmp [$widgets(text) index @$x,0]
	    set tmp [split $tmp "."]
	    set index [lindex $tmp 1]

	    set result [lindex $misc(columns) $index]
	}

	cget {
	    if {[llength $args] != 1} {
		return -code error "wrong # args: should be $w cget option"
	    }
	    set opt [::mclistbox::Canonize $w option [lindex $args 0]]

	    set result $options($opt)
	}


	configure {
	    set result [eval ::mclistbox::Configure {$w} $args]

	}
	
	itemconfigure {
	    set result [eval ::mclistbox::ItemConfigure {$w} $args]
	    
	}

	curselection {
	    set id [lindex $misc(columns) 0]
	    set result [$widgets(listbox$id) curselection]
	}

	delete {
	    if {[llength $args] < 1 || [llength $args] > 2} {
		return -code error "wrong \# of args: should be $w delete first ?last?"
	    }

	    # it's possible that the selection will change because
	    # of something we do. So, grab the current selection before
	    # we do anything. Just before returning we'll see if the
	    # selection has changed. If so, we'll call our selectcommand
	    if {$options(-selectcommand) != ""} {
		set col0 [lindex $misc(columns) 0]
		set priorSelection [$widgets(listbox$col0) curselection]
	    }

	    set index1 [::mclistbox::MassageIndex $w [lindex $args 0]]
	    if {[llength $args] == 2} {
		set index2 [::mclistbox::MassageIndex $w [lindex $args 1]]
	    } else {
		set index2 ""
	    }

	    # note we do an eval here to make index2 "disappear" if it
	    # is set to an empty string.
	    foreach id $misc(columns) {
		eval {$widgets(listbox$id)} delete $index1 $index2
	    }
	    eval {$widgets(hiddenListbox)} delete $index1 $index2

	    InvalidateScrollbars $w

	    set result ""
	}

	get {
	    if {[llength $args] < 1 || [llength $args] > 2} {
		return -code error "wrong \# of args: should be $w get first ?last?"
	    }
	    set index1 [::mclistbox::MassageIndex $w [lindex $args 0]]
	    if {[llength $args] == 2} {
		set index2 [::mclistbox::MassageIndex $w [lindex $args 1]]
	    } else {
		set index2 ""
	    }

	    set result [eval ::mclistbox::WidgetProc-get {$w} $index1 $index2]

	}

	index {

	    if {[llength $args] != 1} {
		return -code error "wrong \# of args: should be $w index index"
	    }

	    set index [::mclistbox::MassageIndex $w [lindex $args 0]]
	    set id [lindex $misc(columns) 0]

	    set result [$widgets(listbox$id) index $index]
	}

	insert {
	    if {[llength $args] < 1} {
		return -code error "wrong \# of args: should be $w insert ?element  element...?"
	    }

	    # it's possible that the selection will change because
	    # of something we do. So, grab the current selection before
	    # we do anything. Just before returning we'll see if the
	    # selection has changed. If so, we'll call our selectcommand
	    if {$options(-selectcommand) != ""} {
		set col0 [lindex $misc(columns) 0]
		set priorSelection [$widgets(listbox$col0) curselection]
	    }

	    set index [::mclistbox::MassageIndex $w [lindex $args 0]]

	    ::mclistbox::Insert $w $index [lrange $args 1 end]

	    InvalidateScrollbars $w
	    set result ""
	}

	nearest {
	    if {[llength $args] != 1} {
		return -code error "wrong \# of args: should be $w nearest y"
	    }

	    # translate the y coordinate into listbox space
	    set id [lindex $misc(columns) 0]
	    set y [lindex $args 0]
	    incr y -[winfo y $widgets(listbox$id)]
	    incr y -[winfo y $widgets(frame$id)]

	    set col0 [lindex $misc(columns) 0]

	    set result [$widgets(listbox$col0) nearest $y]
	}

	scan {
	    foreach {subcommand x y} $args {}
	    switch $subcommand {
		mark {
		    # we have to treat scrolling in x and y differently;
		    # scrolling in the y direction affects listboxes and
		    # scrolling in the x direction affects the text widget.
		    # to facilitate that, we need to keep a local copy
		    # of the scan mark.
		    set misc(scanmarkx) $x
		    set misc(scanmarky) $y
		    
		    # set the scan mark for each column
		    foreach id $misc(columns) {
			$widgets(listbox$id) scan mark $x $y
		    }

		    # we can't use the x coordinate given us, since it 
		    # is relative to whatever column we are over. So,
		    # we'll just usr the results of [winfo pointerx].
		    $widgets(text) scan mark [winfo pointerx $w]  $y
		}
		dragto {
		    # we want the columns to only scan in the y direction,
		    # so we'll force the x componant to remain constant
		    foreach id $misc(columns) {
			$widgets(listbox$id) scan dragto $misc(scanmarkx) $y
		    }

		    # since the scan mark of the text widget was based
		    # on the pointer location, so must be the x
		    # coordinate to the dragto command. And since we
		    # want the text widget to only scan in the x
		    # direction, the y componant will remain constant
		    $widgets(text) scan dragto  [winfo pointerx $w] $misc(scanmarky)

		    # make sure the scrollbars reflect the changes.
		    InvalidateScrollbars $w
		}

		set result ""
	    }
	}

	see {
	    if {[llength $args] != 1} {
		return -code error "wrong \# of args: should be $w see index"
	    }
	    set index [::mclistbox::MassageIndex $w [lindex $args 0]]

	    foreach id $misc(columns) {
		$widgets(listbox$id) see $index
	    }
	    InvalidateScrollbars $w
	    set result {}
	}

	selection {
	    # it's possible that the selection will change because
	    # of something we do. So, grab the current selection before
	    # we do anything. Just before returning we'll see if the
	    # selection has changed. If so, we'll call our selectcommand
	    if {$options(-selectcommand) != ""} {
		set col0 [lindex $misc(columns) 0]
		set priorSelection [$widgets(listbox$col0) curselection]
	    }

	    set subcommand [lindex $args 0]
	    set args [lrange $args 1 end]

	    set prefix "wrong \# of args: should be $w"
	    switch $subcommand {
		includes {
		    if {[llength $args] != 1} {
			return -code error "$prefix selection $subcommand index"
		    }
		    set index [::mclistbox::MassageIndex $w [lindex $args 0]]
		    set id [lindex $misc(columns) 0]
		    set result [$widgets(listbox$id) selection includes $index]
		}

		set {
		    switch [llength $args] {
			1 {
			    set index1 [::mclistbox::MassageIndex $w  [lindex $args 0]]
			    set index2 ""
			}
			2 {
			    set index1 [::mclistbox::MassageIndex $w  [lindex $args 0]]
			    set index2 [::mclistbox::MassageIndex $w  [lindex $args 1]]
			}
			default {
			    return -code error "$prefix selection clear first ?last?"
			}
		    }

		    if {$options(-exportselection)} {
			SelectionHandler $w own
		    }
		    if {$index1 != ""} {
			foreach id $misc(columns) {
			    eval {$widgets(listbox$id)} selection set  $index1 $index2
			}
		    }

		    set result ""
		}

		anchor {
		    if {[llength $args] != 1} {
			return -code error "$prefix selection $subcommand index"
		    }
		    set index [::mclistbox::MassageIndex $w [lindex $args 0]]

		    if {$options(-exportselection)} {
			SelectionHandler $w own
		    }
		    foreach id $misc(columns) {
			$widgets(listbox$id) selection anchor $index
		    }
		    set result ""
		}

		clear {
		    switch [llength $args] {
			1 {
			    set index1 [::mclistbox::MassageIndex $w  [lindex $args 0]]
			    set index2 ""
			}
			2 {
			    set index1 [::mclistbox::MassageIndex $w  [lindex $args 0]]
			    set index2 [::mclistbox::MassageIndex $w  [lindex $args 1]]
			}
			default {
			    return -code error "$prefix selection clear first ?last?"
			}
		    }

		    if {$options(-exportselection)} {
			SelectionHandler $w own
		    }
		    foreach id $misc(columns) {
			eval {$widgets(listbox$id)} selection clear  $index1 $index2
		    }
		    set result ""
		}
	    }
	}

	size {
	    set id [lindex $misc(columns) 0]
	    set result [$widgets(listbox$id) size]
	}
    }

    # if the user has a selectcommand defined and the selection changed,
    # run the selectcommand
    if {[info exists priorSelection] && $options(-selectcommand) != ""} {
	set column [lindex $misc(columns) 0]
	set currentSelection [$widgets(listbox$column) curselection]
	if {[string compare $priorSelection $currentSelection] != 0} {
	    # this logic keeps us from getting into some sort of
	    # infinite loop of the selectcommand changes the selection
	    # (not particularly well tested, but it seems like the
	    # right thing to do...)
	    if {![info exists misc(skipRecursiveCall)]} {
		set misc(skipRecursiveCall) 1
		uplevel \#0 $options(-selectcommand) $currentSelection
		catch {unset misc(skipRecursiveCall)}
	    }
	}
    }

    return $result
}
}
#############################################################################
## Library Procedure:  ::mclistbox::WidgetProc-get

namespace eval ::mclistbox {
proc WidgetProc-get {w args} {
    upvar ::mclistbox::${w}::widgets widgets
    upvar ::mclistbox::${w}::options options
    upvar ::mclistbox::${w}::misc    misc

    set returnType "list"
    # the listbox "get" command returns different things
    # depending on whether it has one or two args. Internally
    # we *always* want a valid list, so we'll force a second
    # arg which in turn forces the listbox to return a list,
    # even if its a list of one element
    if {[llength $args] == 1} {
	lappend args [lindex $args 0]
	set returnType "listOfLists"
    }

    # get all the data from each column
    foreach id $misc(columns) {
	set data($id) [eval {$widgets(listbox$id)} get $args]
    }

    # now join the data together one row at a time. Ugh.
    set result {}
    set rows [llength $data($id)]
    for {set i 0} {$i < $rows} {incr i} {
	set this {}
	foreach column $misc(columns) {
	    lappend this [lindex $data($column) $i]
	}
	lappend result $this
    }
    
    # now to unroll the list if necessary. If the user gave
    # us only one indicie we want to return a single list
    # of values. If they gave use two indicies we want to return
    # a list of lists.
    if {[string compare $returnType "list"] == 0} {
	return $result
    } else {
	return [lindex $result 0]
    }
}
}
#############################################################################
## Library Procedure:  ::mclistbox::convert

namespace eval ::mclistbox {
proc convert {w args} {
    set result {}
    if {![winfo exists $w]} {
	return -code error "window \"$w\" doesn't exist"
    }

    while {[llength $args] > 0} {
	set option [lindex $args 0]
	set args [lrange $args 1 end]

	switch -exact -- $option {
	    -x {
		set value [lindex $args 0]
		set args [lrange $args 1 end]
		set win $w
		while {[winfo class $win] != "Mclistbox"} {
		    incr value [winfo x $win]
		    set win [winfo parent $win]
		    if {$win == "."} break
		}
		lappend result $value
	    }

	    -y {
		set value [lindex $args 0]
		set args [lrange $args 1 end]
		set win $w
		while {[winfo class $win] != "Mclistbox"} {
		    incr value [winfo y $win]
		    set win [winfo parent $win]
		    if {$win == "."} break
		}
		lappend result $value
	    }

	    -w -
	    -W {
		set win $w
		while {[winfo class $win] != "Mclistbox"} {
		    set win [winfo parent $win]
		    if {$win == "."} break;
		}
		lappend result $win
	    }
	}
    }
    return $result
}
}
#############################################################################
## Library Procedure:  ::mclistbox::mclistbox

namespace eval ::mclistbox {
proc mclistbox {args} {
    variable widgetOptions

    # perform a one time initialization
    if {![info exists widgetOptions]} {
      __mclistbox_Setup
	Init
    }

    # make sure we at least have a widget name
    if {[llength $args] == 0} {
	return -code error "wrong # args: should be \"mclistbox pathName ?options?\""
    }

    # ... and make sure a widget doesn't already exist by that name
    if {[winfo exists [lindex $args 0]]} {
	return -code error "window name \"[lindex $args 0]\" already exists"
    }

    # and check that all of the args are valid
    foreach {name value} [lrange $args 1 end] {
	Canonize [lindex $args 0] option $name
    }

    # build it...
    set w [eval Build $args]

    # set some bindings...
    SetBindings $w

    # and we are done!
    return $w
}
}
#############################################################################
## Library Procedure:  __mclistbox_Setup

proc ::__mclistbox_Setup {} {

    namespace eval ::mclistbox {

        # this is the public interface
        namespace export mclistbox

        # these contain references to available options
        variable widgetOptions
        variable columnOptions
	variable itemConfigureOptions

        # these contain references to available commands and subcommands
        variable widgetCommands
        variable columnCommands
        variable labelCommands
    }
}
#############################################################################
## Library Procedure:  vTcl:DefineAlias

proc ::vTcl:DefineAlias {target alias widgetProc top_or_alias cmdalias} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    global widget
    set widget($alias) $target
    set widget(rev,$target) $alias
    if {$cmdalias} {
        interp alias {} $alias {} $widgetProc $target
    }
    if {$top_or_alias != ""} {
        set widget($top_or_alias,$alias) $target
        if {$cmdalias} {
            interp alias {} $top_or_alias.$alias {} $widgetProc $target
        }
    }
}
#############################################################################
## Library Procedure:  vTcl:DoCmdOption

proc ::vTcl:DoCmdOption {target cmd} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    ## menus are considered toplevel windows
    set parent $target
    while {[winfo class $parent] == "Menu"} {
        set parent [winfo parent $parent]
    }

    regsub -all {\%widget} $cmd $target cmd
    regsub -all {\%top} $cmd [winfo toplevel $parent] cmd

    uplevel #0 [list eval $cmd]
}
#############################################################################
## Library Procedure:  vTcl:FireEvent

proc ::vTcl:FireEvent {target event {params {}}} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    ## The window may have disappeared
    if {![winfo exists $target]} return
    ## Process each binding tag, looking for the event
    foreach bindtag [bindtags $target] {
        set tag_events [bind $bindtag]
        set stop_processing 0
        foreach tag_event $tag_events {
            if {$tag_event == $event} {
                set bind_code [bind $bindtag $tag_event]
                foreach rep "\{%W $target\} $params" {
                    regsub -all [lindex $rep 0] $bind_code [lindex $rep 1] bind_code
                }
                set result [catch {uplevel #0 $bind_code} errortext]
                if {$result == 3} {
                    ## break exception, stop processing
                    set stop_processing 1
                } elseif {$result != 0} {
                    bgerror $errortext
                }
                break
            }
        }
        if {$stop_processing} {break}
    }
}
#############################################################################
## Library Procedure:  vTcl:Toplevel:WidgetProc

proc ::vTcl:Toplevel:WidgetProc {w args} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    if {[llength $args] == 0} {
        ## If no arguments, returns the path the alias points to
        return $w
    }
    set command [lindex $args 0]
    set args [lrange $args 1 end]
    switch -- [string tolower $command] {
        "setvar" {
            foreach {varname value} $args {}
            if {$value == ""} {
                return [set ::${w}::${varname}]
            } else {
                return [set ::${w}::${varname} $value]
            }
        }
        "hide" - "show" {
            Window [string tolower $command] $w
        }
        "showmodal" {
            ## modal dialog ends when window is destroyed
            Window show $w; raise $w
            grab $w; tkwait window $w; grab release $w
        }
        "startmodal" {
            ## ends when endmodal called
            Window show $w; raise $w
            set ::${w}::_modal 1
            grab $w; tkwait variable ::${w}::_modal; grab release $w
        }
        "endmodal" {
            ## ends modal dialog started with startmodal, argument is var name
            set ::${w}::_modal 0
            Window hide $w
        }
        default {
            uplevel $w $command $args
        }
    }
}
#############################################################################
## Library Procedure:  vTcl:WidgetProc

proc ::vTcl:WidgetProc {w args} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    if {[llength $args] == 0} {
        ## If no arguments, returns the path the alias points to
        return $w
    }

    set command [lindex $args 0]
    set args [lrange $args 1 end]
    uplevel $w $command $args
}
#############################################################################
## Library Procedure:  vTcl:toplevel

proc ::vTcl:toplevel {args} {
    ## This procedure may be used free of restrictions.
    ##    Exception added by Christian Gavin on 08/08/02.
    ## Other packages and widget toolkits have different licensing requirements.
    ##    Please read their license agreements for details.

    uplevel #0 eval toplevel $args
    set target [lindex $args 0]
    namespace eval ::$target {set _modal 0}
}
}


if {[info exists vTcl(sourcing)]} {

proc vTcl:project:info {} {
    set base .top17
    namespace eval ::widgets::$base {
        set set,origin 1
        set set,size 0
        set runvisible 1
    }
    namespace eval ::widgets::$base.fra57 {
        array set save {-borderwidth 1 -height 1 -relief 1 -width 1}
    }
    set site_3_0 $base.fra57
    namespace eval ::widgets::$site_3_0.mcl65 {
        array set save {-background 1 -columnborderwidth 1 -cursor 1 -exportselection 1 -foreground 1 -height 1 -labelheight 1 -resizablecolumns 1 -setgrid 1 -width 1 -yscrollcommand 1}
        namespace eval subOptions {
            array set save {-font 1 -foreground 1 -label 1 -labelrelief 1 -width 1}
        }
    }
    namespace eval ::widgets::$site_3_0.scr66 {
        array set save {-command 1}
    }
    namespace eval ::widgets::$site_3_0.cpd48 {
        array set save {-borderwidth 1 -height 1}
    }
    set site_4_0 $site_3_0.cpd48
    namespace eval ::widgets::$site_4_0.01 {
        array set save {-anchor 1 -text 1 -width 1}
    }
    namespace eval ::widgets::$site_4_0.02 {
        array set save {-cursor 1 -font 1 -foreground 1}
    }
    namespace eval ::widgets::$site_3_0.cpd47 {
        array set save {-borderwidth 1 -height 1}
    }
    set site_4_0 $site_3_0.cpd47
    namespace eval ::widgets::$site_4_0.01 {
        array set save {-anchor 1 -text 1 -width 1}
    }
    namespace eval ::widgets::$site_4_0.02 {
        array set save {-cursor 1}
    }
    namespace eval ::widgets::$site_3_0.but47 {
        array set save {-command 1 -pady 1 -text 1 -wraplength 1}
    }
    namespace eval ::widgets::$site_3_0.but48 {
        array set save {-command 1 -pady 1 -state 1 -text 1 -wraplength 1}
    }
    namespace eval ::widgets::$site_3_0.but49 {
        array set save {-command 1 -pady 1 -state 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.but60 {
        array set save {-command 1 -pady 1 -state 1 -text 1 -wraplength 1}
    }
    namespace eval ::widgets::$site_3_0.but50 {
        array set save {-activeforeground 1 -anchor 1 -command 1 -pady 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.fra51 {
        array set save {-borderwidth 1 -height 1 -relief 1 -width 1}
    }
    namespace eval ::widgets::$site_3_0.but52 {
        array set save {-command 1 -pady 1 -state 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.but53 {
        array set save {-command 1 -pady 1 -state 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.mes63 {
        array set save {-foreground 1 -text 1 -width 1}
    }
    namespace eval ::widgets::$site_3_0.fra64 {
        array set save {-borderwidth 1 -height 1 -relief 1 -width 1}
    }
    namespace eval ::widgets::$site_3_0.scr71 {
        array set save {-command 1}
    }
    namespace eval ::widgets::$site_3_0.tex47 {
        array set save {-background 1 -foreground 1 -yscrollcommand 1}
    }
    namespace eval ::widgets::$base.cpd58 {
        array set save {-font 1 -foreground 1 -highlightthickness 1 -text 1 -width 1}
    }
    namespace eval ::widgets::$base.fra49 {
        array set save {-borderwidth 1 -height 1 -relief 1 -width 1}
    }
    set site_3_0 $base.fra49
    namespace eval ::widgets::$site_3_0.cpd55 {
        array set save {-activeforeground 1 -anchor 1 -command 1 -pady 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd56 {
        array set save {-command 1 -pady 1 -state 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd57 {
        array set save {-_tooltip 1 -command 1 -pady 1 -state 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd58 {
        array set save {-borderwidth 1 -height 1 -relief 1 -width 1}
    }
    namespace eval ::widgets::$site_3_0.cpd59 {
        array set save {-foreground 1 -text 1 -width 1}
    }
    namespace eval ::widgets::$site_3_0.cpd61 {
        array set save {-borderwidth 1 -height 1 -relief 1 -width 1}
    }
    namespace eval ::widgets::$site_3_0.cpd62 {
        array set save {-command 1}
    }
    namespace eval ::widgets::$site_3_0.spi50 {
        array set save {-from 1 -increment 1 -justify 1 -to 1}
    }
    namespace eval ::widgets::$site_3_0.lab51 {
        array set save {-text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd53 {
        array set save {-background 1 -columnborderwidth 1 -cursor 1 -exportselection 1 -height 1 -labelheight 1 -resizablecolumns 1 -setgrid 1 -width 1 -xscrollcommand 1 -yscrollcommand 1}
        namespace eval subOptions {
            array set save {-background 1 -font 1 -foreground 1 -label 1 -labelrelief 1 -resizable 1 -visible 1 -width 1}
        }
    }
    namespace eval ::widgets::$site_3_0.cpd54 {
        array set save {-command 1}
    }
    namespace eval ::widgets::$site_3_0.scr55 {
        array set save {-command 1 -orient 1}
    }
    namespace eval ::widgets::$site_3_0.cpd64 {
        array set save {-text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd65 {
        array set save {-text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd67 {
        array set save {-text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd68 {
        array set save {-text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd69 {
        array set save {-text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd70 {
        array set save {-text 1}
    }
    namespace eval ::widgets::$site_3_0.men72 {
        array set save {-background 1 -disabledforeground 1 -foreground 1 -menu 1 -padx 1 -pady 1 -relief 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.men72.m {
        array set save {-activeborderwidth 1 -borderwidth 1 -font 1 -tearoff 1}
        namespace eval subOptions {
            array set save {-command 1 -label 1 -value 1 -variable 1}
        }
    }
    namespace eval ::widgets::$site_3_0.che47 {
        array set save {-text 1 -variable 1}
    }
    namespace eval ::widgets::$site_3_0.cpd48 {
        array set save {-background 1 -foreground 1 -yscrollcommand 1}
    }
    namespace eval ::widgets::$site_3_0.men48 {
        array set save {-background 1 -disabledforeground 1 -foreground 1 -menu 1 -padx 1 -pady 1 -relief 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.men48.m {
        array set save {-activeborderwidth 1 -borderwidth 1 -font 1 -tearoff 1}
        namespace eval subOptions {
            array set save {-command 1 -label 1 -underline 1 -value 1 -variable 1}
        }
    }
    namespace eval ::widgets::$site_3_0.men50 {
        array set save {-background 1 -disabledforeground 1 -foreground 1 -menu 1 -padx 1 -pady 1 -relief 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.men50.m {
        array set save {-activeborderwidth 1 -borderwidth 1 -font 1 -tearoff 1}
        namespace eval subOptions {
            array set save {-command 1 -label 1 -underline 1 -value 1 -variable 1}
        }
    }
    namespace eval ::widgets::$site_3_0.men51 {
        array set save {-background 1 -disabledforeground 1 -foreground 1 -menu 1 -padx 1 -pady 1 -relief 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.men51.m {
        array set save {-activeborderwidth 1 -borderwidth 1 -font 1 -tearoff 1}
        namespace eval subOptions {
            array set save {-command 1 -label 1 -underline 1 -value 1 -variable 1}
        }
    }
    namespace eval ::widgets::$site_3_0.cpd52 {
        array set save {-from 1 -justify 1 -to 1}
    }
    namespace eval ::widgets::$site_3_0.cpd60 {
        array set save {-text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd63 {
        array set save {-from 1 -justify 1 -to 1 -wrap 1}
    }
    namespace eval ::widgets::$site_3_0.men47 {
        array set save {-background 1 -menu 1 -padx 1 -pady 1 -relief 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.men47.m {
        array set save {-activeborderwidth 1 -borderwidth 1 -font 1 -tearoff 1}
        namespace eval subOptions {
            array set save {-command 1 -label 1 -value 1 -variable 1}
        }
    }
    namespace eval ::widgets::$site_3_0.spi48 {
        array set save {-from 1 -justify 1 -to 1}
    }
    namespace eval ::widgets::$site_3_0.cpd50 {
        array set save {-borderwidth 1 -height 1}
    }
    set site_4_0 $site_3_0.cpd50
    namespace eval ::widgets::$site_4_0.02 {
        array set save {-cursor 1}
    }
    namespace eval ::widgets::$site_3_0.cpd49 {
        array set save {-command 1 -pady 1 -text 1 -wraplength 1}
    }
    namespace eval ::widgets::$site_3_0.cpd51 {
        array set save {-command 1 -pady 1 -state 1 -text 1 -wraplength 1}
    }
    namespace eval ::widgets::$site_3_0.cpd66 {
        array set save {-command 1 -pady 1 -state 1 -text 1 -wraplength 1}
    }
    namespace eval ::widgets::$site_3_0.cpd71 {
        array set save {-command 1 -pady 1 -state 1 -text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd47 {
        array set save {-borderwidth 1 -height 1}
    }
    set site_4_0 $site_3_0.cpd47
    namespace eval ::widgets::$site_4_0.01 {
        array set save {-anchor 1 -text 1 -width 1}
    }
    namespace eval ::widgets::$site_4_0.02 {
        array set save {-cursor 1 -font 1 -foreground 1 -justify 1}
    }
    namespace eval ::widgets::$site_3_0.cpd72 {
        array set save {-from 1 -justify 1 -to 1}
    }
    namespace eval ::widgets::$site_3_0.cpd73 {
        array set save {-text 1}
    }
    namespace eval ::widgets::$site_3_0.cpd74 {
        array set save {-text 1}
    }
    namespace eval ::widgets::$base.cpd50 {
        array set save {-font 1 -foreground 1 -text 1}
    }
    namespace eval ::widgets::$base.but54 {
        array set save {-background 1 -command 1 -font 1 -foreground 1 -highlightcolor 1 -pady 1 -text 1 -width 1}
    }
    namespace eval ::widgets::$base.lab52 {
        array set save {-_tooltip 1 -text 1}
    }
    namespace eval ::widgets::$base.cpd47 {
        array set save {-_tooltip 1 -background 1 -command 1 -font 1 -foreground 1 -highlightcolor 1 -pady 1 -state 1 -text 1 -width 1}
    }
    namespace eval ::widgets_bindings {
        set tagslist {_TopLevel cdscds {SelectLogEnv pFrom pTo} _vTclBalloon <Key-F1> {_vTclBalloon "tottotototo"}}
    }
    namespace eval ::vTcl::modules::main {
        set procs {
            init
            main
            vTclWindow.
            vTclWindow.top17
            On_SEL_BtnAdd
            On_SEL_BtnEmpty
            SEL_FillEnvList
            SEL_NewMessage
            On_SEL_BtnLoad
            On_SEL_BtnRemove
            On_SEL_BtnSaveAs
            On_SEL_SelectElement
            SEL_SetButtonsState
            SEL_CleanSelectedElement
            On_SEL_CleanLastMessage
            On_SEL_BtnSave
            On_SEL_BtnReplace
            SEL_CheckEnvs
            On_SEL_ContextualMenu
            On_SEL_MenuSort
            On_SEL_MenuHighlightDoubloon
            On_SET_BtnLoad
            SET_NewMessage
            SET_SetButtonsState
            SET_FillEnvTable
            On_SET_BtnSave
            On_SET_BtnSaveAs
            On_SET_SelectElement
            On_SET_ContextualMenu
            On_SET_MenuSort
            On_SET_BtnAdd
            On_SET_BtnEmpty
            On_SET_BtnRemove
            On_SET_BtnReplace
            On_SET_CleanLastMessage
            SET_CleanSelectedElement
            On_SET_MenuButtonPressed
            On_SET_MenuHighlightDoubloon
            SET_GetTableElement
            SET_GetNumericShutdownOrder
            On_SEL_MenuOrder
            On_SET_MenuOrder
        }
        set compounds {
        }
        set projectType single
    }
}
}

#################################
# USER DEFINED PROCEDURES
#
#############################################################################
## Procedure:  main

proc ::main {argc argv} {
    global firstSEL
    set firstSEL 1
    global firstSET
    set firstSET 1

    global SEL_index
    set SEL_index "-1"
    global SET_index
    set SET_index "-1"
    
    global widget
    
    global SHUTDOWN_LAST
    set SHUTDOWN_LAST 32759

    $widget(SEL_Messages) config -state "disabled"
    SEL_FillEnvList
    $widget(SET_Messages) config -state "disabled"
    SET_FillEnvTable
    
    # SET, menu-buttons states
    global SET_MenuTermination
    set SET_MenuTermination     "NONE"
    global SET_MenuSnapshot    
    set SET_MenuSnapshot        "NONE"    
    global SET_MenuShutdown    
    set SET_MenuShutdown        "ORDER ="    
    global SET_MenuSupervision 
    set SET_MenuSupervision     "NONE"    
    global SET_MenuPriority    
    set SET_MenuPriority        "NORMAL"
    global SET_ToggleNotification
    set SET_ToggleNotification  "0"

    # Sorting options
    global SEL_Sorting
    set SEL_Sorting             "increasing"
    global SET_Sorting
    set SET_Sorting             "increasing"
    
    # Sorting fields
    global SEL_Field
    set SEL_Field               ""
    global SET_Field
    set SET_Field               ""
    
    # SCS icon
	global env
    image create photo ScadaIcon -file $env(SCSHOME)/dat/ScsVisu/Tools/ScsEnvEditor/scs.gif
    $widget(SCS_Icon) config -image ScadaIcon
    
    ### Initial load
    
    global env

    # SEL
	global SEL_Filename
	set SEL_Filename "${::env(SCSPATH)}/ScsEnvList"
	if { [catch {ReadEnvList $SEL_Filename}] == 0 } {
		SEL_FillEnvList
		SEL_SetButtonsState
		SEL_CleanSelectedElement
		SEL_NewMessage "ScsEnvList '$SEL_Filename' loaded..."
		set SEL_Filename "ScsEnvList"
	} else {
		set SEL_Filename ""
	}
	
	# SET
	global SET_Filename
	set SET_Filename "${::env(SCSPATH)}/ScsEnvTable"
	if { [catch {ReadEnvTable $SET_Filename}] == 0 } {
		SET_FillEnvTable
		SET_SetButtonsState
		SET_CleanSelectedElement
		SET_NewMessage "ScsEnvTable '$SET_Filename' loaded..."
		set SET_Filename "ScsEnvTable"
	} else {
		set SET_Filename ""
	}
}
#############################################################################
## Procedure:  On_SEL_BtnAdd

proc ::On_SEL_BtnAdd {} {
global widget

    # Read user's new entries
    # Read user's new entries
    set LogEnv  [$widget(SEL_LogEnv) get]
    set PhysEnv [$widget(SEL_PhysEnv) get]
   
    # Check parameters
    set result [SEL_CheckEnvs $LogEnv $PhysEnv]
    if { $result == "" } {
        # Add them to logical list
        global ListEnvs
        lappend ListEnvs [subst {{$LogEnv} {$PhysEnv}}]
        
        # Add them to displayed list
        $widget(SEL_EnvList) insert end [list [string trim $LogEnv] [string trim $PhysEnv]]
        $widget(SEL_EnvList) selection clear 0 end
        $widget(SEL_EnvList) selection set end

        # Prompt info
        SEL_NewMessage "Added association '[string trim $LogEnv]' -> '[string trim $PhysEnv]'"
        
    } else {
        # Prompt error
        SEL_NewMessage "$result environment is not defined !"
    }
    
    SEL_SetButtonsState
}
#############################################################################
## Procedure:  On_SEL_BtnEmpty

proc ::On_SEL_BtnEmpty {} {
    global widget
    global SEL_Filename

    global ListEnvs
    set ListEnvs {}

    SEL_FillEnvList
    SEL_CleanSelectedElement
    SEL_SetButtonsState
    
    # Prompt info
    set current ""
    if { $SEL_Filename != "" } {
         set current " ($SEL_Filename)"
    }
    SEL_NewMessage "Current env list$current emptied"
 
}
#############################################################################
## Procedure:  SEL_FillEnvList

proc ::SEL_FillEnvList {} {
    global widget
    global ListEnvs
 
    set widgetName $widget(SEL_EnvList)
    $widgetName column configure col1 -label "Logical environments"
    $widgetName column configure col2 -label "Physical environments"
    $widgetName delete 0 end

    foreach item $ListEnvs {
        $widgetName insert end [list [lindex $item 0] [lindex $item 1]]
    }
}
#############################################################################
## Procedure:  SEL_NewMessage

proc ::SEL_NewMessage {message} {
global widget

    $widget(SEL_Messages) config -state "normal"
    $widget(SEL_Messages) delete "insert linestart" "insert lineend +1 char"
    $widget(SEL_Messages) insert 0.end "$message"
    $widget(SEL_Messages) config -state "disabled"
    
}
#############################################################################
## Procedure:  On_SEL_BtnLoad

proc ::On_SEL_BtnLoad {} {
    global widget
    global SEL_Filename
    global SEL_Field
    global firstSEL
    global env

    set initialDir ""
    if { $firstSEL == 1 } {
	set initialDir "$::env(SCSPATH)"
    }
     
    set types {
        {"ScsEnvList files" {"ScsEnvList*"}}
        {"All files" {*}}
    }
    set title "Open env list..."
    set fileName [tk_getOpenFile -initialdir $initialDir -filetypes $types -title $title]
    if { $fileName != ""} {
	set firstSEL 0
        set SEL_Field ""
        set SEL_Filename $fileName
        ReadEnvList $SEL_Filename   
        SEL_FillEnvList
        SEL_SetButtonsState
        SEL_CleanSelectedElement
        SEL_NewMessage "ScsEnvList '$SEL_Filename' loaded..."
    } else {
        SEL_NewMessage "No env list loaded !"
    }
    
}
#############################################################################
## Procedure:  On_SEL_BtnRemove

proc ::On_SEL_BtnRemove {} {
global widget

    set selectedIndex [lindex [$widget(SEL_EnvList) curselection] 0]
    if { $selectedIndex != "" } {
        # Get current selection
        set selectedStrings [$widget(SEL_EnvList) get $selectedIndex]

        # Remove association within logical env list
        global ListEnvs
        set ListEnvs [lreplace $ListEnvs $selectedIndex $selectedIndex]
        
        # Prompt message
        SEL_NewMessage "Association '[lindex $selectedStrings 0]' -> '[lindex $selectedStrings 1]' removed"

        # Deselect and update list
        SEL_FillEnvList
    }
    
    SEL_CleanSelectedElement
    SEL_SetButtonsState
}
#############################################################################
## Procedure:  On_SEL_BtnSaveAs

proc ::On_SEL_BtnSaveAs {} {
    global widget
    global SEL_Filename
    
    set types {
        {"ScsEnvList files" {"ScsEnvList*"}}
        {"All files" {*}}
    }
    
    set title "Save env list..."
    set fileName [tk_getSaveFile -filetypes $types -title $title -initialfile $SEL_Filename]
    if { $fileName != ""} {
        set SEL_Filename $fileName
        WriteEnvList $SEL_Filename
        SEL_NewMessage "Current env list saved as '$SEL_Filename'..."
        return 1
    } else {
        SEL_NewMessage "Current env list NOT saved !"
        return 0
    }
    
}
#############################################################################
## Procedure:  On_SEL_SelectElement

proc ::On_SEL_SelectElement {pWidget} {
    global widget
    global SEL_selectedIndex

    set SEL_selectedIndex [lindex [$widget(SEL_EnvList) curselection] 0]
    if { $SEL_selectedIndex != "" } {
        set selectedStrings [$widget(SEL_EnvList) get $SEL_selectedIndex]
        set logicalEnv      [lindex $selectedStrings 0]
        set physicalEnv     [lindex $selectedStrings 1]
    
        $widget(SEL_LogEnv)  delete 0 end
        $widget(SEL_LogEnv)  insert end $logicalEnv
    
        $widget(SEL_PhysEnv) delete 0 end
        $widget(SEL_PhysEnv) insert end $physicalEnv
    }
    
    SEL_SetButtonsState
    
    
}
#############################################################################
## Procedure:  SEL_SetButtonsState

proc ::SEL_SetButtonsState {} {
global widget

    global ListEnvs
    set state "normal"
    if { $ListEnvs == "" } {
        set state "disabled"
    }
    
    $widget(SEL_BtnSave)   config -state $state
    $widget(SEL_BtnSaveAs) config -state $state
    $widget(SEL_BtnEmpty)  config -state $state
    
    set selected [lindex [$widget(SEL_EnvList) curselection] 0]
    set state "disabled"
    if { $selected != "" } {
        set state "normal"
    }
    $widget(SEL_BtnReplace) config -state $state
    $widget(SEL_BtnRemove)  config -state $state
    
}
#############################################################################
## Procedure:  SEL_CleanSelectedElement

proc ::SEL_CleanSelectedElement {} {
    global widget

    $widget(SEL_LogEnv) delete 0 end
    $widget(SEL_LogEnv) insert end ""
    
    $widget(SEL_PhysEnv) delete 0 end
    $widget(SEL_PhysEnv) insert end ""
    
   
}
#############################################################################
## Procedure:  On_SEL_CleanLastMessage

proc ::On_SEL_CleanLastMessage {} {
global widget

SEL_NewMessage ""
}
#############################################################################
## Procedure:  On_SEL_BtnSave

proc ::On_SEL_BtnSave {} {
global widget
global SEL_Filename

if { $SEL_Filename == "" } {
    On_SEL_BtnSaveAs
} else {
    WriteEnvList $SEL_Filename
    SEL_NewMessage "Current env list '$SEL_Filename' saved..."
}
}
#############################################################################
## Procedure:  On_SEL_BtnReplace

proc ::On_SEL_BtnReplace {} {
global widget

    # Read user's new entries
    set LogEnv  [$widget(SEL_LogEnv) get]
    set PhysEnv [$widget(SEL_PhysEnv) get]
   
    # Check parameters
    set result [SEL_CheckEnvs $LogEnv $PhysEnv]
    if { $result == "" } {
        set selectedIndex [lindex [$widget(SEL_EnvList) curselection] 0]
        if { $selectedIndex != "" } {
            # Get current selection
            set selectedStrings [$widget(SEL_EnvList) get $selectedIndex]

            # Remove association within logical env list
            global ListEnvs
            set ListEnvs [lreplace $ListEnvs $selectedIndex $selectedIndex [subst {{$LogEnv} {$PhysEnv}}]]
        
            # Prompt message
            SEL_NewMessage "Association '[lindex $selectedStrings 0]' -> '[lindex $selectedStrings 1] 'replaced by association '$LogEnv' -> '$PhysEnv'"

            # Deselect and update list
            SEL_FillEnvList
            $widget(SEL_EnvList) selection set $selectedIndex
        }
    } else {
        # Prompt error
        SEL_NewMessage "$result environment is not defined !"
    }

    SEL_SetButtonsState
}
#############################################################################
## Procedure:  SEL_CheckEnvs

proc ::SEL_CheckEnvs {LogEnv PhysEnv} {
global widget

    # Check parameters
    if { [expr {[string trim $LogEnv] != ""} && {[string trim $PhysEnv] != ""}] } {
        return ""        
    } else {
        set missing "PHYSICAL"
        if { [string trim $LogEnv] == "" } {
            set missing "LOGICAL"
        }
        return $missing
}
}
#############################################################################
## Procedure:  On_SEL_ContextualMenu

proc ::On_SEL_ContextualMenu {pWidget xMouse yMouse} {
global widget

    global ListEnvs
    set sensitive "normal"
    if { $ListEnvs == {} } {
        set sensitive "disabled"
    }
    
    global SEL_Menu
    if ![info exists SEL_Menu] {
        set SEL_Menu [menu ${pWidget}.myMenu]
        $SEL_Menu configure -tearoff "false"

        $SEL_Menu add command -label " Highlight next doubloon"        -command On_SEL_MenuHighlightDoubloon
        $SEL_Menu add separator
        $SEL_Menu add radio -label " Sort by logical environment"    -variable SEL_Field -command {On_SEL_MenuSort LOG}
        $SEL_Menu add radio -label " Sort by physical environment"   -variable SEL_Field -command {On_SEL_MenuSort PHYS}
        $SEL_Menu add separator
        $SEL_Menu add radio -label " Increasing sort" -variable SEL_Sorting -value "increasing" -command {On_SEL_MenuOrder increasing}
        $SEL_Menu add radio -label " Decreasing sort" -variable SEL_Sorting -value "decreasing" -command {On_SEL_MenuOrder decreasing}
    }

    $SEL_Menu entryconfigure 0 -state $sensitive
    $SEL_Menu entryconfigure 2 -state $sensitive
    $SEL_Menu entryconfigure 3 -state $sensitive
    
    tk_popup $SEL_Menu $xMouse $yMouse
    
}
#############################################################################
## Procedure:  On_SEL_MenuSort

proc ::On_SEL_MenuSort {sortingKey} {
global widget

    set index 0
    set info "logical"
    if { $sortingKey == "PHYS" } {
        set index 1
        set info "physical"
    }
    
    global SEL_index
    set SEL_index $index

    global ListEnvs
    global SEL_Sorting
    set ListEnvs [lsort -$SEL_Sorting -dictionary -index $index $ListEnvs]

    SEL_NewMessage "The list has been sorted by $info environments..."
    SEL_FillEnvList
    SEL_CleanSelectedElement
    SEL_SetButtonsState
    
}
#############################################################################
## Procedure:  On_SEL_MenuHighlightDoubloon

proc ::On_SEL_MenuHighlightDoubloon {} {
global widget

    set selectedIndex [lindex [$widget(SEL_EnvList) curselection] 0]
    if { $selectedIndex != "" } {
        $widget(SEL_EnvList) selection clear 0 end
    }
    SEL_CleanSelectedElement

    global ListEnvs

    set listSize [llength $ListEnvs]
    set doubloonIndex ""

    # 1st level loop
    for { set i 0 } { $i < $listSize } { incr i } {
        set currentKey [lindex [lindex $ListEnvs $i] 0]
    
        # 2nd level loop
        for { set j [expr $i + 1] } { $j < $listSize } { incr j } {
            set nextKey [lindex [lindex $ListEnvs $j] 0]
            if { $nextKey == $currentKey } {
                set doubloonIndex $j
                break
            }
        }
        
        if { $doubloonIndex != "" } {
            $widget(SEL_EnvList) selection set $doubloonIndex             
            SEL_SetButtonsState
            SEL_NewMessage "Doubloon detected and highlighted..."
            break
        }
    }
    
    if { $doubloonIndex == "" } {
        SEL_NewMessage "No doubloons detected !"
    }
    SEL_SetButtonsState
    
}
#############################################################################
## Procedure:  On_SET_BtnLoad

proc ::On_SET_BtnLoad {} {
    global widget
    global SET_Filename
    global SET_Field
    global firstSET
    global env
    
    set initialDir ""
    if { $firstSET == 1 } {
	set initialDir "$::env(SCSPATH)"
    }
     
    set types {
        {"ScsEnvTable files" {"ScsEnvTable*"}}
        {"All files" {*}}
    }
    set title "Open env table..."
    set fileName [tk_getOpenFile -initialdir $initialDir -filetypes $types -title $title]
    if { $fileName != ""} {
	set firstSET 0
        set SET_Field ""
        set SET_Filename $fileName
        ReadEnvTable $SET_Filename   
        SET_FillEnvTable
        SET_SetButtonsState
        SET_CleanSelectedElement
        SET_NewMessage "ScsEnvTable '$SET_Filename' loaded..."
    } else {
        SET_NewMessage "No env table loaded !"
    }
    
}
#############################################################################
## Procedure:  SET_NewMessage

proc ::SET_NewMessage {message} {
global widget

    $widget(SET_Messages) config -state "normal"
    $widget(SET_Messages) delete "insert linestart" "insert lineend +1 char"
    $widget(SET_Messages) insert 0.end "$message"
    $widget(SET_Messages) config -state "disabled"
    
}
#############################################################################
## Procedure:  SET_SetButtonsState

proc ::SET_SetButtonsState {} {
global widget

    global ListServers
    set state "normal"
    if { $ListServers == "" } {
        set state "disabled"
    }
    
    $widget(SET_BtnSave)   config -state $state
    $widget(SET_BtnSaveAs) config -state $state
    $widget(SET_BtnEmpty)  config -state $state
    
    set selected [lindex [$widget(SET_EnvTable) curselection] 0]
    set state "disabled"
    if { $selected != "" } {
        set state "normal"
    }
    $widget(SET_BtnReplace) config -state $state
    $widget(SET_BtnRemove)  config -state $state
}
#############################################################################
## Procedure:  SET_FillEnvTable

proc ::SET_FillEnvTable {} {
    global widget
    global ListServers
 
    set widgetName $widget(SET_EnvTable)
    $widgetName delete 0 end

    foreach item $ListServers {
        $widgetName insert end [list [lindex $item 0]  [lindex [lindex $item 1] 1]  [lindex [lindex $item 2] 1]  [lindex [lindex $item 3] 1]  [lindex [lindex $item 4] 1]  [lindex [lindex $item 5] 1] [lindex [lindex $item 6] 1]  [lindex [lindex $item 7] 1]  [lindex [lindex $item 8] 1]  [lindex [lindex $item 9] 1]  [lindex [lindex $item 10] 1]  [lindex [lindex [lindex $item 11] 1] 0]]
    }
    
}
#############################################################################
## Procedure:  On_SET_BtnSave

proc ::On_SET_BtnSave {} {
global widget
global SET_Filename

if { $SET_Filename == "" } {
    On_SET_BtnSaveAs
} else {
    WriteEnvTable $SET_Filename
    SET_NewMessage "Current env table '$SET_Filename' saved..."
}
}
#############################################################################
## Procedure:  On_SET_BtnSaveAs

proc ::On_SET_BtnSaveAs {} {
    global widget
    global SET_Filename
    
    set types {
        {"ScsEnvTable files" {"ScsEnvTable*"}}
        {"All files" {*}}
    }
    
    set title "Save env table..."
    set fileName [tk_getSaveFile -filetypes $types -title $title -initialfile $SET_Filename]
    if { $fileName != ""} {
        set SET_Filename $fileName
        WriteEnvTable $SET_Filename
        SET_NewMessage "Current env table saved as '$SET_Filename'..."
        return 1
    } else {
        SET_NewMessage "Current env table NOT saved !"
        return 0
    }
    
}
#############################################################################
## Procedure:  On_SET_SelectElement

proc ::On_SET_SelectElement {pWidget} {
    global widget
    global SET_selectedIndex

    set SET_selectedIndex [lindex [$widget(SET_EnvTable) curselection] 0]
    if { $SET_selectedIndex != "" } {
        set selectedStrings [$widget(SET_EnvTable) get $SET_selectedIndex]

        global SET_MenuTermination
        global SET_MenuSnapshot    
        global SET_MenuShutdown    
        global SET_MenuSupervision 
        global SET_MenuPriority    
        global SET_ToggleNotification

        $widget(SET_CommandID)   delete 0 end
        $widget(SET_CommandID)   insert end [lindex $selectedStrings 0]

        $widget(SET_Phase)       delete 0 end
        $widget(SET_Phase)       insert end [lindex $selectedStrings 1]

        $widget(SET_Termination) configure -text [lindex $selectedStrings 2]
        set SET_MenuTermination  [lindex $selectedStrings 2]

        $widget(SET_Snapshot)    configure -text [lindex $selectedStrings 3]
        set SET_MenuSnapshot     [lindex $selectedStrings 3]
        
        set SET_ToggleNotification "0"
        if { [lindex $selectedStrings 4] != "NO" } {
            set SET_ToggleNotification "1"
        }
        
        set tmpOrder [lindex $selectedStrings 5]
        if { [llength $tmpOrder] == 1 } {
            if { $tmpOrder == "LAST" } {
                $widget(SET_Shutdown) configure -text "LAST -"
                $widget(SET_Order)    delete 0 end
                $widget(SET_Order)    insert end "0"
                set SET_MenuShutdown  "LAST -"
            } else {
                $widget(SET_Shutdown) configure -text "ORDER ="
                $widget(SET_Order)    delete 0 end
                $widget(SET_Order)    insert end $tmpOrder
                set SET_MenuShutdown  "ORDER ="
            }
        } else {
            $widget(SET_Shutdown) configure -text "LAST -"
            $widget(SET_Order)    delete 0 end
            $widget(SET_Order)    insert end [lindex $tmpOrder 2]
            set SET_MenuShutdown  "LAST -"
        }
        
        $widget(SET_Supervision) configure -text [lindex $selectedStrings 6]
        set SET_MenuSupervision  [lindex $selectedStrings 6]
        
        $widget(SET_Priority)    configure -text [lindex $selectedStrings 7]
        set SET_MenuPriority     [lindex $selectedStrings 7]

        $widget(SET_Timeout)     delete 0 end
        $widget(SET_Timeout)     insert end [lindex $selectedStrings 8]

        $widget(SET_Timeout2)    delete 0 end
        $widget(SET_Timeout2)    insert end [lindex $selectedStrings 9]

        $widget(SET_Processor)   delete 0 end
        $widget(SET_Processor)   insert end [lindex $selectedStrings 10]

        $widget(SET_RunString)   delete 0 end
        $widget(SET_RunString)   insert end [lindex $selectedStrings 11]
    }
   
    SET_SetButtonsState
    
}
#############################################################################
## Procedure:  On_SET_ContextualMenu

proc ::On_SET_ContextualMenu {pWidget xMouse yMouse} {
global widget

    global ListServers
    set sensitive "normal"
    if { $ListServers == {} } {
        set sensitive "disabled"
    }
    
    global SET_Menu
    if ![info exists SET_Menu] {
        set SET_Menu [menu ${pWidget}.myMenu]
        $SET_Menu configure -tearoff "false"
        $SET_Menu add command -label " Highlight next doubloon" -command {On_SET_MenuHighlightDoubloon}
        $SET_Menu add separator
        $SET_Menu add radio -label " Sort by ID"               -variable SET_Field -command {On_SET_MenuSort ID}
        $SET_Menu add radio -label " Sort by phase"            -variable SET_Field -command {On_SET_MenuSort phase}
        $SET_Menu add radio -label " Sort by termination"      -variable SET_Field -command {On_SET_MenuSort termination}
        $SET_Menu add radio -label " Sort by snapshot"         -variable SET_Field -command {On_SET_MenuSort snapshot}
        $SET_Menu add radio -label " Sort by notification"     -variable SET_Field -command {On_SET_MenuSort notification}
        $SET_Menu add radio -label " Sort by shutdown"         -variable SET_Field -command {On_SET_MenuSort shutdown}
        $SET_Menu add radio -label " Sort by supervision"      -variable SET_Field -command {On_SET_MenuSort supervision}
        $SET_Menu add radio -label " Sort by priority"         -variable SET_Field -command {On_SET_MenuSort priority}
        $SET_Menu add radio -label " Sort by init timeout"     -variable SET_Field -command {On_SET_MenuSort timeout}
        $SET_Menu add radio -label " Sort by shutdown timeout" -variable SET_Field -command {On_SET_MenuSort timeout2}
        $SET_Menu add radio -label " Sort by processor"        -variable SET_Field -command {On_SET_MenuSort processor}
        $SET_Menu add radio -label " Sort by command"          -variable SET_Field -command {On_SET_MenuSort command}
        $SET_Menu add separator
        $SET_Menu add radio -label " Increasing sort" -variable SET_Sorting -value "increasing" -command {On_SET_MenuOrder increasing}
        $SET_Menu add radio -label " Decreasing sort" -variable SET_Sorting -value "decreasing" -command {On_SET_MenuOrder decreasing}
    }

    $SET_Menu entryconfigure  0 -state $sensitive
    $SET_Menu entryconfigure  2 -state $sensitive
    $SET_Menu entryconfigure  3 -state $sensitive
    $SET_Menu entryconfigure  4 -state $sensitive
    $SET_Menu entryconfigure  5 -state $sensitive
    $SET_Menu entryconfigure  6 -state $sensitive
    $SET_Menu entryconfigure  7 -state $sensitive
    $SET_Menu entryconfigure  8 -state $sensitive
    $SET_Menu entryconfigure  9 -state $sensitive
    $SET_Menu entryconfigure 10 -state $sensitive
    $SET_Menu entryconfigure 11 -state $sensitive
    $SET_Menu entryconfigure 12 -state $sensitive
    $SET_Menu entryconfigure 13 -state $sensitive
        
    tk_popup $SET_Menu $xMouse $yMouse
   
    
}
#############################################################################
## Procedure:  On_SET_MenuSort

proc ::On_SET_MenuSort {sortingKey} {
global widget

    set index     0
    if { $sortingKey == "phase" } {
        set index 1
    } elseif { $sortingKey == "termination" } {
        set index 2
    } elseif { $sortingKey == "snapshot" } {
        set index 3
    } elseif { $sortingKey == "notification" } {
        set index 4
    } elseif { $sortingKey == "shutdown" } {
        set index 5
    } elseif { $sortingKey == "supervision" } {
        set index 6
    } elseif { $sortingKey == "priority" } {
        set index 7
    } elseif { $sortingKey == "timeout" } {
        set index 8
    } elseif { $sortingKey == "timeout2" } {
        set index 9
    } elseif { $sortingKey == "processor" } {
        set index 10
    } elseif { $sortingKey == "command" } {
        set index 11
    }
    
    global SET_index
    set SET_index $index

    global ListServers
    global SET_Sorting
    if { $index != 5 } {
        # Alphabetical sorting
        set ListServers [lsort -$SET_Sorting -dictionary -index $index $ListServers]
    } else {
        # Numerical sorting
        set tmpList {}
        foreach row $ListServers {
            # Create a tmp lis like this: { {numericOrder1 row1} ... }
            set numOrder [SET_GetNumericShutdownOrder [lindex [lindex $row 5] 1]]
            lappend tmpList [subst { $numOrder { $row } }]
        }
        # Now sort the tmp list...
        set tmpList [lsort -$SET_Sorting -dictionary -index 0 $tmpList]
        # Then create back the real list
        set ListServers {}
        foreach item $tmpList {
            lappend ListServers [lindex $item 1]
        }
    }
   
    SET_NewMessage "The list has been sorted by $sortingKey..."
    SET_FillEnvTable
    SET_CleanSelectedElement
    SET_SetButtonsState
 
}
#############################################################################
## Procedure:  On_SET_BtnAdd

proc ::On_SET_BtnAdd {} {
global widget

    if { [$widget(SET_CommandID) get] == "" } {
        SET_NewMessage "Invalid command ID"
        return
    }

    set newCommand [SET_GetTableElement]

    global ListServers
    lappend ListServers $newCommand
        
    # Add them to displayed list
    $widget(SET_EnvTable) insert end [list [lindex $newCommand 0]  [lindex [lindex $newCommand 1] 1]  [lindex [lindex $newCommand 2] 1]  [lindex [lindex $newCommand 3] 1]  [lindex [lindex $newCommand 4] 1]  [lindex [lindex $newCommand 5] 1]  [lindex [lindex $newCommand 6] 1]  [lindex [lindex $newCommand 7] 1]  [lindex [lindex $newCommand 8] 1]  [lindex [lindex $newCommand 9] 1]  [lindex [lindex [lindex $newCommand 10] 1] 0]]
    $widget(SET_EnvTable) selection clear 0 end
    $widget(SET_EnvTable) selection set end

    # Prompt info
    SET_NewMessage "Added command ID '[$widget(SET_CommandID) get]'"
}
#############################################################################
## Procedure:  On_SET_BtnEmpty

proc ::On_SET_BtnEmpty {} {
    global widget
    global SET_Filename

    global ListServers
    set ListServers {}

    SET_FillEnvTable
    SET_CleanSelectedElement
    SET_SetButtonsState
    
    # Prompt info
    set current ""
    if { $SET_Filename != "" } {
         set current " ($SET_Filename)"
    }
    SET_NewMessage "Current env table$current emptied"
 
}
#############################################################################
## Procedure:  On_SET_BtnRemove

proc ::On_SET_BtnRemove {} {
global widget

    set selectedIndex [lindex [$widget(SET_EnvTable) curselection] 0]
    if { $selectedIndex != "" } {
        # Get current selection
        set selectedStrings [$widget(SET_EnvTable) get $selectedIndex]

        # Remove association within logical env list
        global ListServers
        set ListServers [lreplace $ListServers $selectedIndex $selectedIndex]
        
        # Prompt message
        SET_NewMessage "Command ID '[lindex $selectedStrings 0]' removed"

        # Deselect and update list
        SET_FillEnvTable
    }
    
    SET_CleanSelectedElement
    SET_SetButtonsState
}
#############################################################################
## Procedure:  On_SET_BtnReplace

proc ::On_SET_BtnReplace {} {
global widget

    if { [$widget(SET_CommandID) get] == "" } {
        SET_NewMessage "Invalid command ID"
        return
    }

    set selectedIndex [lindex [$widget(SET_EnvTable) curselection] 0]
    if { $selectedIndex == "" } {
        return
    }
    
    set newCommand [SET_GetTableElement]

    global ListServers
    set ListServers [lreplace $ListServers $selectedIndex $selectedIndex $newCommand]
        
    # Deselect and update list
    SET_FillEnvTable
    $widget(SET_EnvTable) selection set $selectedIndex

    # Prompt info
    SET_NewMessage "Command replaced with '[$widget(SET_CommandID) get]'"
    
}
#############################################################################
## Procedure:  On_SET_CleanLastMessage

proc ::On_SET_CleanLastMessage {} {
global widget

SET_NewMessage ""
}
#############################################################################
## Procedure:  SET_CleanSelectedElement

proc ::SET_CleanSelectedElement {} {
    global widget

   
   
}
#############################################################################
## Procedure:  On_SET_MenuButtonPressed

proc ::On_SET_MenuButtonPressed {value} {
global widget

global SET_Menu$value
$widget(SET_$value) configure -text [set SET_Menu$value]
}
#############################################################################
## Procedure:  On_SET_MenuHighlightDoubloon

proc ::On_SET_MenuHighlightDoubloon {} {
global widget

    set selectedIndex [lindex [$widget(SET_EnvTable) curselection] 0]
    if { $selectedIndex != "" } {
        $widget(SET_EnvTable) selection clear 0 end
    }
    SET_CleanSelectedElement

    global ListServers

    set listSize [llength $ListServers]
    set doubloonIndex ""

    # 1st level loop
    for { set i 0 } { $i < $listSize } { incr i } {
        set currentKey [lindex [lindex $ListServers $i] 0]
    
        # 2nd level loop
        for { set j [expr $i + 1] } { $j < $listSize } { incr j } {
            set nextKey [lindex [lindex $ListServers $j] 0]
            if { $nextKey == $currentKey } {
                set doubloonIndex $j
                break
            }
        }
        
        if { $doubloonIndex != "" } {
            $widget(SET_EnvTable) selection set $doubloonIndex
            SET_SetButtonsState
            SET_NewMessage "Doubloon detected and highlighted..."
            break
        }
    }
    
    if { $doubloonIndex == "" } {
        SET_NewMessage "No doubloons detected !"
    }
    SET_SetButtonsState
    
}
#############################################################################
## Procedure:  SET_GetTableElement

proc ::SET_GetTableElement {} {
global widget

    global PHASE 
    global TERMINATION 
    global SNAPSHOT 
    global NOTIFICATION 
    global SHUTDOWN_ORDER 
    global SUPERVISION 
    global PRIORITY 
    global INIT_TIMEOUT 
    global SHUTDOWN_TIMEOUT 
    global PROCESSOR 
    global RUN_STRING

    global SET_MenuTermination
    global SET_MenuSnapshot    
    global SET_MenuShutdown    
    global SET_MenuSupervision 
    global SET_MenuPriority    
    global SET_ToggleNotification

    # Get data
    set ID         [$widget(SET_CommandID) get]
    set phase      [$widget(SET_Phase)     get]
    set timeout    [$widget(SET_Timeout)   get]
    set timeout2   [$widget(SET_Timeout2)  get]
    set processor  [$widget(SET_Processor) get]
    set command    [$widget(SET_RunString) get]

    set notification "NO"
    if { $SET_ToggleNotification == "1" } {
        set notification YES
    }

    set shutdown "LAST"
    if { $SET_MenuShutdown == "ORDER =" } {
        set shutdown [$widget(SET_Order) get]
    } else {
        set order [$widget(SET_Order) get]
        if { $order != "0" } {
            set shutdown "$shutdown - $order"
        }
    }
            
    # Prepare new cell to be added
    return [subst {$ID 
                   \{$PHASE $phase\} 
                   \{$TERMINATION $SET_MenuTermination\}  
                   \{$SNAPSHOT $SET_MenuSnapshot\} 
                   \{$NOTIFICATION $notification\}  
                   \{\{$SHUTDOWN_ORDER\} \{$shutdown\}\}  
                   \{$SUPERVISION $SET_MenuSupervision\} 
                   \{$PRIORITY $SET_MenuPriority\}  
                   \{\{$INIT_TIMEOUT\} $timeout\} 
                   \{\{$SHUTDOWN_TIMEOUT\} $timeout2\} 
                   \{$PROCESSOR $processor\}  
                   \{\{$RUN_STRING\} \{\"$command\"\}\}}]
}
#############################################################################
## Procedure:  SET_GetNumericShutdownOrder

proc ::SET_GetNumericShutdownOrder {alphabeticShutdownOrder} {
global widget

    global SHUTDOWN_LAST
    set numOrder $SHUTDOWN_LAST

    if { [llength $alphabeticShutdownOrder] == 1 } {
        if { $alphabeticShutdownOrder != "LAST" } {
            set numOrder $alphabeticShutdownOrder
        }
    } else {
        set numOrder [expr $SHUTDOWN_LAST - [lindex $alphabeticShutdownOrder 2]]
    }

    return $numOrder
    
}
#############################################################################
## Procedure:  On_SEL_MenuOrder

proc ::On_SEL_MenuOrder {order} {
global widget

    global SEL_Sorting
    set SEL_Sorting $order
    
    global SEL_Field
    if { $SEL_Field != "" } {
        global SEL_index
        global ListEnvs
        set ListEnvs [lsort -$SEL_Sorting -dictionary -index $SEL_index $ListEnvs]
         
        SEL_NewMessage "The list has been reordered $order..."
        SEL_FillEnvList
        SEL_CleanSelectedElement
        SEL_SetButtonsState    
    } else {
        SEL_NewMessage "Sorting order set to $order, but no sorting field choose yet..."
    }
}
#############################################################################
## Procedure:  On_SET_MenuOrder

proc ::On_SET_MenuOrder {order} {
global widget

    global SET_Sorting
    set SET_Sorting $order
    
    global SET_Field
    if { $SET_Field != "" } {
        global SET_index
        global ListServers
        
        if { $SET_index != "" } {
            if { $SET_index != 5 } {
                # Alphabetical sorting
                set ListServers [lsort -$SET_Sorting -dictionary -index $SET_index $ListServers]
            } else {
                # Numerical sorting
                set tmpList {}
                foreach row $ListServers {
                    # Create a tmp lis like this: { {numericOrder1 row1} ... }
                    set numOrder [SET_GetNumericShutdownOrder [lindex [lindex $row 5] 1]]
                    lappend tmpList [subst { $numOrder { $row } }]
                }
                # Now sort the tmp list...
                set tmpList [lsort -$SET_Sorting -dictionary -index 0 $tmpList]
                # Then create back the real list
                set ListServers {}
                foreach item $tmpList {
                    lappend ListServers [lindex $item 1]
                }
         
            }
            SET_NewMessage "The list has been reorder $order..."
            SET_FillEnvTable
            SET_CleanSelectedElement
            SET_SetButtonsState
        }
    } else {
        SET_NewMessage "Sorting order set to $order, but no sorting field choose yet..."
    }
}

#############################################################################
## Initialization Procedure:  init

proc ::init {argc argv} {

}

init $argc $argv

#################################
# VTCL GENERATED GUI PROCEDURES
#

proc vTclWindow. {base} {
    if {$base == ""} {
        set base .
    }
    ###################
    # CREATING WIDGETS
    ###################
    wm focusmodel $top passive
    wm geometry $top 200x200+88+88; update
    wm maxsize $top 1156 849
    wm minsize $top 104 1
    wm overrideredirect $top 0
    wm resizable $top 1 1
    wm withdraw $top
    wm title $top "vtcl"
    bindtags $top "$top Vtcl all"
    vTcl:FireEvent $top <<Create>>
    wm protocol $top WM_DELETE_WINDOW "vTcl:FireEvent $top <<DeleteWindow>>"

    ###################
    # SETTING GEOMETRY
    ###################

    vTcl:FireEvent $base <<Ready>>
}

proc vTclWindow.top17 {base} {
    if {$base == ""} {
        set base .top17
    }
    if {[winfo exists $base]} {
        wm deiconify $base; return
    }
    set top $base
    ###################
    # CREATING WIDGETS
    ###################
    vTcl:toplevel $top -class Toplevel
    wm focusmodel $top passive
    wm geometry $top +231+23; update
    wm grid $top 20 10 6 14
    wm maxsize $top 120 50
    wm minsize $top 120 50
    wm overrideredirect $top 0
    wm resizable $top 1 1
    wm deiconify $top
    wm title $top "ScsEnvEditor 1.1"
    vTcl:DefineAlias "$top" "EnvListPanel" vTcl:Toplevel:WidgetProc "" 1
    bindtags $top "$top Toplevel all _TopLevel"
    bind $top <Alt-Key-X> {
        exit
    }
    bind $top <Alt-Key-x> {
        exit
    }
    bind $top <Key-F1> {
        On_SEL_BtnLoad
    }
    bind $top <Key-F2> {
        global widget
		if { [$widget(SEL_BtnSave) cget -state] == "normal" } {
			On_SEL_BtnSave
		} else {
			bell
		}
    }
    bind $top <Key-F3> {
        global widget
		if { [$widget(SEL_BtnSaveAs) cget -state] == "normal" } {
			On_SEL_BtnSaveAs
		} else {
			bell
		}
    }
    bind $top <Key-F4> {
        On_SET_BtnLoad
    }
    bind $top <Key-F5> {
        global widget
		if { [$widget(SET_BtnSave) cget -state] == "normal" } {
			On_SET_BtnSave
		} else {
			bell
		}
    }
    bind $top <Key-F6> {
        global widget
		if { [$widget(SET_BtnSaveAs) cget -state] == "normal" } {
			On_SET_BtnSaveAs
		} else {
			bell
		}
    }
    bind $top <Shift-Key-F1> {
        global widget
		if { [$widget(SEL_BtnAdd) cget -state] == "normal" } {
			On_SEL_BtnAdd
		} else {
			bell
		}
    }
    bind $top <Shift-Key-F2> {
        global widget
		if { [$widget(SEL_BtnReplace) cget -state] == "normal" } {
			On_SEL_BtnReplace
		} else {
			bell
		}
    }
    bind $top <Shift-Key-F3> {
        global widget
		if { [$widget(SEL_BtnRemove) cget -state] == "normal" } {
			On_SEL_BtnRemove
		} else {
			bell
		}
    }
    bind $top <Shift-Key-F4> {
        global widget
		if { [$widget(SET_BtnAdd) cget -state] == "normal" } {
			On_SET_BtnAdd
		} else {
			bell
		}
    }
    bind $top <Shift-Key-F5> {
        global widget
		if { [$widget(SET_BtnReplace) cget -state] == "normal" } {
			On_SET_BtnReplace
		} else {
			bell
		}
    }
    bind $top <Shift-Key-F6> {
        global widget
		if { [$widget(SET_BtnRemove) cget -state] == "normal" } {
			On_SET_BtnRemove
		} else {
			bell
		}
    }
    vTcl:FireEvent $top <<Create>>
    wm protocol $top WM_DELETE_WINDOW "vTcl:FireEvent $top <<DeleteWindow>>"

    frame $top.fra57 \
        -borderwidth 2 -height 308 -relief groove -width 782 
    vTcl:DefineAlias "$top.fra57" "Frame4" vTcl:WidgetProc "EnvListPanel" 1
    set site_3_0 $top.fra57
    ::mclistbox::mclistbox $site_3_0.mcl65 \
        -background #e47affffdfff -columnborderwidth 0 -cursor {} \
        -exportselection 0 -foreground #000000 -height 165 -labelheight 1 \
        -resizablecolumns 1 -setgrid 1 -width 729 \
        -yscrollcommand "$site_3_0.scr66 set" 
    vTcl:DefineAlias "$site_3_0.mcl65" "SEL_EnvList" vTcl:WidgetProc "EnvListPanel" 1
    bind $site_3_0.mcl65 <ButtonRelease-1> {
        On_SEL_SelectElement %W
    }
    bind $site_3_0.mcl65 <ButtonRelease-3> {
        On_SEL_ContextualMenu %W %X %Y
    }
    $site_3_0.mcl65 column add col1 \
        -font {{MS Sans Serif} 8 bold} -foreground #000099 \
        -label {Logical environments} -labelrelief raised -width 61 
    $site_3_0.mcl65 column add col2 \
        -font {{MS Sans Serif} 8} -foreground SystemButtonText \
        -label {Physical environments} -labelrelief raised -width 60 
    scrollbar $site_3_0.scr66 \
        -command "$site_3_0.mcl65 yview" 
    vTcl:DefineAlias "$site_3_0.scr66" "Scrollbar1" vTcl:WidgetProc "EnvListPanel" 1
    frame $site_3_0.cpd48 \
        -borderwidth 1 -height 25 
    vTcl:DefineAlias "$site_3_0.cpd48" "Frame5" vTcl:WidgetProc "EnvListPanel" 1
    set site_4_0 $site_3_0.cpd48
    label $site_4_0.01 \
        -anchor w -text {Logical environment :} -width 18 
    vTcl:DefineAlias "$site_4_0.01" "Label2" vTcl:WidgetProc "EnvListPanel" 1
    entry $site_4_0.02 \
        -cursor {} -font {{MS Sans Serif} 8 bold} -foreground #000099 
    vTcl:DefineAlias "$site_4_0.02" "SEL_LogEnv" vTcl:WidgetProc "EnvListPanel" 1
    pack $site_4_0.01 \
        -in $site_4_0 -anchor w -expand 0 -fill none -padx 2 -pady 2 \
        -side left 
    pack $site_4_0.02 \
        -in $site_4_0 -anchor w -expand 1 -fill x -padx 2 -pady 2 -side right 
    frame $site_3_0.cpd47 \
        -borderwidth 1 -height 25 
    vTcl:DefineAlias "$site_3_0.cpd47" "Frame6" vTcl:WidgetProc "EnvListPanel" 1
    set site_4_0 $site_3_0.cpd47
    label $site_4_0.01 \
        -anchor w -text {Physical environment :} -width 18 
    vTcl:DefineAlias "$site_4_0.01" "Label3" vTcl:WidgetProc "EnvListPanel" 1
    entry $site_4_0.02 \
        -cursor {} 
    vTcl:DefineAlias "$site_4_0.02" "SEL_PhysEnv" vTcl:WidgetProc "EnvListPanel" 1
    pack $site_4_0.01 \
        -in $site_4_0 -anchor center -expand 0 -fill none -padx 2 -pady 2 \
        -side left 
    pack $site_4_0.02 \
        -in $site_4_0 -anchor center -expand 1 -fill x -padx 2 -pady 2 \
        -side right 
    button $site_3_0.but47 \
        -command On_SEL_BtnAdd -pady 0 -text {Add [Shift+F1]} -wraplength 50 
    vTcl:DefineAlias "$site_3_0.but47" "SEL_BtnAdd" vTcl:WidgetProc "EnvListPanel" 1
    button $site_3_0.but48 \
        -command On_SEL_BtnRemove -pady 0 -state disabled \
        -text {Remove  [Shift+F3]} -wraplength 50 
    vTcl:DefineAlias "$site_3_0.but48" "SEL_BtnRemove" vTcl:WidgetProc "EnvListPanel" 1
    button $site_3_0.but49 \
        -command On_SEL_BtnEmpty -pady 0 -state disabled -text Empty 
    vTcl:DefineAlias "$site_3_0.but49" "SEL_BtnEmpty" vTcl:WidgetProc "EnvListPanel" 1
    button $site_3_0.but60 \
        -command On_SEL_BtnReplace -pady 0 -state disabled \
        -text {Replace [Shift+F2]} -wraplength 50 
    vTcl:DefineAlias "$site_3_0.but60" "SEL_BtnReplace" vTcl:WidgetProc "EnvListPanel" 1
    button $site_3_0.but50 \
        -activeforeground SystemButtonText -anchor center \
        -command On_SEL_BtnLoad -pady 0 -text {Load... [F1]} 
    vTcl:DefineAlias "$site_3_0.but50" "SEL_BtnLoad" vTcl:WidgetProc "EnvListPanel" 1
    frame $site_3_0.fra51 \
        -borderwidth 2 -height 11 -relief groove -width 125 
    vTcl:DefineAlias "$site_3_0.fra51" "Frame2" vTcl:WidgetProc "EnvListPanel" 1
    button $site_3_0.but52 \
        -command On_SEL_BtnSave -pady 0 -state disabled -text {Save [F2]} 
    vTcl:DefineAlias "$site_3_0.but52" "SEL_BtnSave" vTcl:WidgetProc "EnvListPanel" 1
    button $site_3_0.but53 \
        -command On_SEL_BtnSaveAs -pady 0 -state disabled \
        -text {Save as... [F3]} 
    vTcl:DefineAlias "$site_3_0.but53" "SEL_BtnSaveAs" vTcl:WidgetProc "EnvListPanel" 1
    message $site_3_0.mes63 \
        -foreground #000099 -text {Messages :} -width 58 
    vTcl:DefineAlias "$site_3_0.mes63" "SEL_Message" vTcl:WidgetProc "EnvListPanel" 1
    bind $site_3_0.mes63 <ButtonRelease-1> {
        On_SEL_CleanLastMessage
    }
    frame $site_3_0.fra64 \
        -borderwidth 2 -height 85 -relief groove -width 115 
    vTcl:DefineAlias "$site_3_0.fra64" "Frame1" vTcl:WidgetProc "EnvListPanel" 1
    scrollbar $site_3_0.scr71 \
        -command "$site_3_0.tex47 yview" 
    vTcl:DefineAlias "$site_3_0.scr71" "Scrollbar2" vTcl:WidgetProc "EnvListPanel" 1
    text $site_3_0.tex47 \
        -background #666666 -foreground #ffffff \
        -yscrollcommand "$site_3_0.scr71 set" 
    vTcl:DefineAlias "$site_3_0.tex47" "SEL_Messages" vTcl:WidgetProc "EnvListPanel" 1
    bindtags $site_3_0.tex47 "Text $top all"
    place $site_3_0.mcl65 \
        -x 18 -y 15 -width 729 -height 165 -anchor nw -bordermode ignore 
    place $site_3_0.scr66 \
        -x 747 -y 35 -width 16 -height 145 -anchor nw -bordermode ignore 
    place $site_3_0.cpd48 \
        -x 10 -y 185 -width 360 -height 25 -anchor nw 
    place $site_3_0.cpd47 \
        -x 10 -y 210 -width 360 -height 25 -anchor nw 
    place $site_3_0.but47 \
        -x 385 -y 190 -width 80 -height 46 -anchor nw -bordermode ignore 
    place $site_3_0.but48 \
        -x 585 -y 190 -width 80 -height 46 -anchor nw -bordermode ignore 
    place $site_3_0.but49 \
        -x 685 -y 190 -width 80 -height 46 -anchor nw -bordermode ignore 
    place $site_3_0.but60 \
        -x 485 -y 190 -width 79 -height 46 -anchor nw -bordermode ignore 
    place $site_3_0.but50 \
        -x 15 -y 260 -width 79 -height 31 -anchor nw -bordermode ignore 
    place $site_3_0.fra51 \
        -x 15 -y 245 -width 752 -height 2 -anchor nw -bordermode ignore 
    place $site_3_0.but52 \
        -x 105 -y 260 -width 79 -height 31 -anchor nw -bordermode ignore 
    place $site_3_0.but53 \
        -x 195 -y 260 -width 79 -height 31 -anchor nw -bordermode ignore 
    place $site_3_0.mes63 \
        -x 300 -y 265 -width 58 -height 21 -anchor nw -bordermode ignore 
    place $site_3_0.fra64 \
        -x 288 -y 255 -width 2 -height 42 -anchor nw -bordermode ignore 
    place $site_3_0.scr71 \
        -x 750 -y 260 -width 16 -height 33 -anchor nw -bordermode ignore 
    place $site_3_0.tex47 \
        -x 365 -y 260 -width 386 -height 33 -anchor nw -bordermode ignore 
    label $top.cpd58 \
        -font {{MS Sans Serif} 10 bold} -foreground #000099 \
        -highlightthickness 0 -text ScsEnvList -width 90 
    vTcl:DefineAlias "$top.cpd58" "Label1" vTcl:WidgetProc "EnvListPanel" 1
    frame $top.fra49 \
        -borderwidth 2 -height 380 -relief groove -width 782 
    vTcl:DefineAlias "$top.fra49" "Frame3" vTcl:WidgetProc "EnvListPanel" 1
    set site_3_0 $top.fra49
    button $site_3_0.cpd55 \
        -activeforeground SystemButtonText -anchor center \
        -command On_SET_BtnLoad -pady 0 -text {Load... [F4]} 
    vTcl:DefineAlias "$site_3_0.cpd55" "SET_BtnLoad" vTcl:WidgetProc "EnvListPanel" 1
    button $site_3_0.cpd56 \
        -command On_SET_BtnSave -pady 0 -state disabled -text {Save [F5]} 
    vTcl:DefineAlias "$site_3_0.cpd56" "SET_BtnSave" vTcl:WidgetProc "EnvListPanel" 1
    button $site_3_0.cpd57 \
        -command On_SET_BtnSaveAs -pady 0 -state disabled \
        -text {Save as... [F6]} 
    vTcl:DefineAlias "$site_3_0.cpd57" "SET_BtnSaveAs" vTcl:WidgetProc "EnvListPanel" 1
    bindtags $site_3_0.cpd57 "$site_3_0.cpd57 Button $top all _vTclBalloon"
    bind $site_3_0.cpd57 <<SetBalloon>> {
        set ::vTcl::balloon::%W {aaaaaaaaaaa}
    }
    frame $site_3_0.cpd58 \
        -borderwidth 2 -height 85 -relief groove -width 115 
    vTcl:DefineAlias "$site_3_0.cpd58" "Frame7" vTcl:WidgetProc "EnvListPanel" 1
    message $site_3_0.cpd59 \
        -foreground #000099 -text {Messages :} -width 58 
    vTcl:DefineAlias "$site_3_0.cpd59" "SET_Message" vTcl:WidgetProc "EnvListPanel" 1
    bind $site_3_0.cpd59 <ButtonRelease-1> {
        On_SET_CleanLastMessage
    }
    frame $site_3_0.cpd61 \
        -borderwidth 2 -height 11 -relief groove -width 125 
    vTcl:DefineAlias "$site_3_0.cpd61" "Frame8" vTcl:WidgetProc "EnvListPanel" 1
    scrollbar $site_3_0.cpd62 \
        -command "$site_3_0.cpd48 yview" 
    vTcl:DefineAlias "$site_3_0.cpd62" "Scrollbar3" vTcl:WidgetProc "EnvListPanel" 1
    spinbox $site_3_0.spi50 \
        -from 0.0 -increment 10.0 -justify center -to 99999.0 
    vTcl:DefineAlias "$site_3_0.spi50" "SET_Phase" vTcl:WidgetProc "EnvListPanel" 1
    label $site_3_0.lab51 \
        -text {Phase :} 
    vTcl:DefineAlias "$site_3_0.lab51" "Label4" vTcl:WidgetProc "EnvListPanel" 1
    ::mclistbox::mclistbox $site_3_0.cpd53 \
        -background #fd21ffffdc28 -columnborderwidth 0 -cursor {} \
        -exportselection 0 -height 165 -labelheight 1 -resizablecolumns 1 \
        -setgrid 1 -width 745 -xscrollcommand "$site_3_0.scr55 set" \
        -yscrollcommand "$site_3_0.cpd54 set" 
    vTcl:DefineAlias "$site_3_0.cpd53" "SET_EnvTable" vTcl:WidgetProc "EnvListPanel" 1
    bind $site_3_0.cpd53 <ButtonRelease-1> {
        On_SET_SelectElement %W
    }
    bind $site_3_0.cpd53 <ButtonRelease-3> {
        On_SET_ContextualMenu %W %X %Y
    }
    $site_3_0.cpd53 column add col1 \
        -background #fd21ffffdc28 -font {{MS Sans Serif} 8 bold} \
        -foreground #000099 -label {Command ID} -labelrelief raised \
        -resizable 1 -visible 1 -width 18 
    $site_3_0.cpd53 column add col2 \
        -background #fd21ffffdc28 -font {{MS Sans Serif} 8} \
        -foreground SystemButtonText -label Phase -labelrelief raised \
        -resizable 1 -visible 1 -width 6 
    $site_3_0.cpd53 column add col3 \
        -background #fd21ffffdc28 -font {{MS Sans Serif} 8} \
        -foreground SystemButtonText -label Termination -labelrelief raised \
        -resizable 1 -visible 1 -width 14 
    $site_3_0.cpd53 column add col4 \
        -background #fd21ffffdc28 -font {{MS Sans Serif} 8} \
        -foreground SystemButtonText -label Snapshot -labelrelief raised \
        -resizable 1 -visible 1 -width 16 
    $site_3_0.cpd53 column add col5 \
        -background #fd21ffffdc28 -font {{MS Sans Serif} 8} \
        -foreground SystemButtonText -label Notif. -labelrelief raised \
        -resizable 1 -visible 1 -width 6 
    $site_3_0.cpd53 column add col6 \
        -background #fd21ffffdc28 -font {{MS Sans Serif} 8} \
        -foreground SystemButtonText -label Shutdown -labelrelief raised \
        -resizable 1 -visible 1 -width 12 
    $site_3_0.cpd53 column add col7 \
        -background #fd21ffffdc28 -font {{MS Sans Serif} 8} \
        -foreground SystemButtonText -label Supervision -labelrelief raised \
        -resizable 1 -visible 1 -width 12 
    $site_3_0.cpd53 column add col8 \
        -background #fd21ffffdc28 -font {{MS Sans Serif} 8} \
        -foreground SystemButtonText -label Priority -labelrelief raised \
        -resizable 1 -visible 1 -width 18 
    $site_3_0.cpd53 column add col9 \
        -background #fd21ffffdc28 -font {{MS Sans Serif} 8} \
        -foreground SystemButtonText -label {Timeout i.} -labelrelief raised \
        -resizable 1 -visible 1 -width 9 
    $site_3_0.cpd53 column add col10 \
        -background #fd21ffffdc28 -font {{MS Sans Serif} 8} \
        -foreground SystemButtonText -label {Timeout s.} -labelrelief raised \
        -resizable 1 -visible 1 -width 9 
    $site_3_0.cpd53 column add col11 \
        -background #fd21ffffdc28 -font {{MS Sans Serif} 8} \
        -foreground SystemButtonText -label Proc. -labelrelief raised \
        -resizable 1 -visible 1 -width 6 
    $site_3_0.cpd53 column add col12 \
        -background #fd21ffffdc28 -font {{MS Sans Serif} 8} \
        -foreground SystemButtonText -label {Run string} -labelrelief raised \
        -resizable 1 -visible 1 -width 80 
    scrollbar $site_3_0.cpd54 \
        -command "$site_3_0.cpd53 yview" 
    vTcl:DefineAlias "$site_3_0.cpd54" "Scrollbar4" vTcl:WidgetProc "EnvListPanel" 1
    scrollbar $site_3_0.scr55 \
        -command "$site_3_0.cpd53 xview" -orient horizontal 
    vTcl:DefineAlias "$site_3_0.scr55" "Scrollbar5" vTcl:WidgetProc "EnvListPanel" 1
    label $site_3_0.cpd64 \
        -text {Termination :} 
    vTcl:DefineAlias "$site_3_0.cpd64" "Label5" vTcl:WidgetProc "EnvListPanel" 1
    label $site_3_0.cpd65 \
        -text {Snapshot :} 
    vTcl:DefineAlias "$site_3_0.cpd65" "Label7" vTcl:WidgetProc "EnvListPanel" 1
    label $site_3_0.cpd67 \
        -text {Supervision :} 
    vTcl:DefineAlias "$site_3_0.cpd67" "Label9" vTcl:WidgetProc "EnvListPanel" 1
    label $site_3_0.cpd68 \
        -text {Shutdown :} 
    vTcl:DefineAlias "$site_3_0.cpd68" "Label10" vTcl:WidgetProc "EnvListPanel" 1
    label $site_3_0.cpd69 \
        -text {Priority :} 
    vTcl:DefineAlias "$site_3_0.cpd69" "Label11" vTcl:WidgetProc "EnvListPanel" 1
    label $site_3_0.cpd70 \
        -text Init: 
    vTcl:DefineAlias "$site_3_0.cpd70" "Label12" vTcl:WidgetProc "EnvListPanel" 1
    menubutton $site_3_0.men72 \
        -background SystemWindow -disabledforeground SystemButtonFace \
        -foreground SystemWindowText -menu "$site_3_0.men72.m" -padx 5 \
        -pady 4 -relief sunken -text NONE 
    vTcl:DefineAlias "$site_3_0.men72" "SET_Termination" vTcl:WidgetProc "EnvListPanel" 1
    menu $site_3_0.men72.m \
        -activeborderwidth 1 -borderwidth 1 -font {Tahoma 8} -tearoff 0 
    $site_3_0.men72.m add radiobutton \
        -value NONE -variable SET_MenuTermination \
        -command {On_SET_MenuButtonPressed Termination} -label { NONE} 
    $site_3_0.men72.m add radiobutton \
        -value SHUTDOWN -variable SET_MenuTermination \
        -command {On_SET_MenuButtonPressed Termination} -label { SHUTDOWN} 
    $site_3_0.men72.m add radiobutton \
        -value RETRY -variable SET_MenuTermination \
        -command {On_SET_MenuButtonPressed Termination} -label { RETRY} 
    checkbutton $site_3_0.che47 \
        -text Notification -variable SET_ToggleNotification 
    vTcl:DefineAlias "$site_3_0.che47" "SET_Notification" vTcl:WidgetProc "EnvListPanel" 1
    text $site_3_0.cpd48 \
        -background #666666 -foreground #ffffff \
        -yscrollcommand "$site_3_0.cpd62 set" 
    vTcl:DefineAlias "$site_3_0.cpd48" "SET_Messages" vTcl:WidgetProc "EnvListPanel" 1
    menubutton $site_3_0.men48 \
        -background SystemWindow -disabledforeground SystemButtonFace \
        -foreground SystemWindowText -menu "$site_3_0.men48.m" -padx 5 \
        -pady 4 -relief sunken -text NONE 
    vTcl:DefineAlias "$site_3_0.men48" "SET_Snapshot" vTcl:WidgetProc "EnvListPanel" 1
    menu $site_3_0.men48.m \
        -activeborderwidth 1 -borderwidth 1 -font {Tahoma 8} -tearoff 0 
    $site_3_0.men48.m add radiobutton \
        -value NONE -variable SET_MenuSnapshot \
        -command {On_SET_MenuButtonPressed Snapshot} -label { NONE} \
        -underline -1 
    $site_3_0.men48.m add radiobutton \
        -value BACKGROUND -variable SET_MenuSnapshot \
        -command {On_SET_MenuButtonPressed Snapshot} -label { BACKGROUND} \
        -underline -1 
    $site_3_0.men48.m add radiobutton \
        -value FOREGROUND -variable SET_MenuSnapshot \
        -command {On_SET_MenuButtonPressed Snapshot} -label { FOREGROUND} \
        -underline -1 
    menubutton $site_3_0.men50 \
        -background SystemWindow -disabledforeground SystemButtonFace \
        -foreground SystemWindowText -menu "$site_3_0.men50.m" -padx 5 \
        -pady 4 -relief sunken -text NONE 
    vTcl:DefineAlias "$site_3_0.men50" "SET_Supervision" vTcl:WidgetProc "EnvListPanel" 1
    menu $site_3_0.men50.m \
        -activeborderwidth 1 -borderwidth 1 -font {Tahoma 8} -tearoff 0 
    $site_3_0.men50.m add radiobutton \
        -value NONE -variable SET_MenuSupervision \
        -command {On_SET_MenuButtonPressed Supervision} -label { NONE} \
        -underline -1 
    $site_3_0.men50.m add radiobutton \
        -value CORBA -variable SET_MenuSupervision \
        -command {On_SET_MenuButtonPressed Supervision} -label { CORBA} \
        -underline -1 
    $site_3_0.men50.m add radiobutton \
        -value RTAP -variable SET_MenuSupervision \
        -command {On_SET_MenuButtonPressed Supervision} -label { RTAP} \
        -underline -1 
    $site_3_0.men50.m add radiobutton \
        -value UNIX -variable SET_MenuSupervision \
        -command {On_SET_MenuButtonPressed Supervision} -label { UNIX} \
        -underline -1 
    $site_3_0.men50.m add radiobutton \
        -value PUSH -variable SET_MenuSupervision \
        -command {On_SET_MenuButtonPressed Supervision} -label { PUSH} \
        -underline -1 
    menubutton $site_3_0.men51 \
        -background SystemWindow -disabledforeground SystemButtonFace \
        -foreground SystemWindowText -menu "$site_3_0.men51.m" -padx 5 \
        -pady 4 -relief sunken -text NORMAL 
    vTcl:DefineAlias "$site_3_0.men51" "SET_Priority" vTcl:WidgetProc "EnvListPanel" 1
    menu $site_3_0.men51.m \
        -activeborderwidth 1 -borderwidth 1 -font {Tahoma 8} -tearoff 0 
    $site_3_0.men51.m add radiobutton \
        -value HIGHEST -variable SET_MenuPriority \
        -command {On_SET_MenuButtonPressed Priority} -label { HIGHEST} \
        -underline -1 
    $site_3_0.men51.m add radiobutton \
        -value ABOVE_NORMAL -variable SET_MenuPriority \
        -command {On_SET_MenuButtonPressed Priority} -label { ABOVE_NORMAL} \
        -underline -1 
    $site_3_0.men51.m add radiobutton \
        -value NORMAL -variable SET_MenuPriority \
        -command {On_SET_MenuButtonPressed Priority} -label { NORMAL} \
        -underline -1 
    $site_3_0.men51.m add radiobutton \
        -value BELOW_NORMAL -variable SET_MenuPriority \
        -command {On_SET_MenuButtonPressed Priority} -label { BELOW_NORMAL} \
        -underline -1 
    $site_3_0.men51.m add radiobutton \
        -value LOWEST -variable SET_MenuPriority \
        -command {On_SET_MenuButtonPressed Priority} -label { LOWEST} \
        -underline -1 
    spinbox $site_3_0.cpd52 \
        -from 0.0 -justify center -to 1000000.0 
    vTcl:DefineAlias "$site_3_0.cpd52" "SET_Timeout" vTcl:WidgetProc "EnvListPanel" 1
    label $site_3_0.cpd60 \
        -text {Processor :} 
    vTcl:DefineAlias "$site_3_0.cpd60" "Label14" vTcl:WidgetProc "EnvListPanel" 1
    spinbox $site_3_0.cpd63 \
        -from -1.0 -justify center -to 32.0 -wrap 1 
    vTcl:DefineAlias "$site_3_0.cpd63" "SET_Processor" vTcl:WidgetProc "EnvListPanel" 1
    menubutton $site_3_0.men47 \
        -background SystemWindow -menu "$site_3_0.men47.m" -padx 5 -pady 4 \
        -relief sunken -text {ORDER =} 
    vTcl:DefineAlias "$site_3_0.men47" "SET_Shutdown" vTcl:WidgetProc "EnvListPanel" 1
    menu $site_3_0.men47.m \
        -activeborderwidth 1 -borderwidth 1 -font {Tahoma 8} -tearoff 0 
    $site_3_0.men47.m add radiobutton \
        -value {ORDER =} -variable SET_MenuShutdown \
        -command {On_SET_MenuButtonPressed Shutdown} -label { ORDER =} 
    $site_3_0.men47.m add radiobutton \
        -value {LAST -} -variable SET_MenuShutdown \
        -command {On_SET_MenuButtonPressed Shutdown} -label { LAST -} 
    spinbox $site_3_0.spi48 \
        -from 0.0 -justify center -to 9999.0 
    vTcl:DefineAlias "$site_3_0.spi48" "SET_Order" vTcl:WidgetProc "EnvListPanel" 1
    frame $site_3_0.cpd50 \
        -borderwidth 1 -height 25 
    vTcl:DefineAlias "$site_3_0.cpd50" "Frame9" vTcl:WidgetProc "EnvListPanel" 1
    set site_4_0 $site_3_0.cpd50
    entry $site_4_0.02 \
        -cursor {} 
    vTcl:DefineAlias "$site_4_0.02" "SET_RunString" vTcl:WidgetProc "EnvListPanel" 1
    pack $site_4_0.02 \
        -in $site_4_0 -anchor center -expand 1 -fill x -padx 2 -pady 2 \
        -side right 
    button $site_3_0.cpd49 \
        -command On_SET_BtnAdd -pady 0 -text {Add  [Shift+F4]} -wraplength 50 
    vTcl:DefineAlias "$site_3_0.cpd49" "SET_BtnAdd" vTcl:WidgetProc "EnvListPanel" 1
    button $site_3_0.cpd51 \
        -command On_SET_BtnReplace -pady 0 -state disabled \
        -text {Replace [Shift+F5]} -wraplength 50 
    vTcl:DefineAlias "$site_3_0.cpd51" "SET_BtnReplace" vTcl:WidgetProc "EnvListPanel" 1
    button $site_3_0.cpd66 \
        -command On_SET_BtnRemove -pady 0 -state disabled \
        -text {Remove [Shift+F6]} -wraplength 50 
    vTcl:DefineAlias "$site_3_0.cpd66" "SET_BtnRemove" vTcl:WidgetProc "EnvListPanel" 1
    button $site_3_0.cpd71 \
        -command On_SET_BtnEmpty -pady 0 -state disabled -text Empty 
    vTcl:DefineAlias "$site_3_0.cpd71" "SET_BtnEmpty" vTcl:WidgetProc "EnvListPanel" 1
    frame $site_3_0.cpd47 \
        -borderwidth 1 -height 25 
    vTcl:DefineAlias "$site_3_0.cpd47" "Frame10" vTcl:WidgetProc "EnvListPanel" 1
    set site_4_0 $site_3_0.cpd47
    label $site_4_0.01 \
        -anchor w -text {Command ID :} -width 11 
    vTcl:DefineAlias "$site_4_0.01" "Label8" vTcl:WidgetProc "EnvListPanel" 1
    entry $site_4_0.02 \
        -cursor {} -font {{MS Sans Serif} 8 bold} -foreground #000099 \
        -justify center 
    vTcl:DefineAlias "$site_4_0.02" "SET_CommandID" vTcl:WidgetProc "EnvListPanel" 1
    pack $site_4_0.01 \
        -in $site_4_0 -anchor center -expand 0 -fill none -padx 2 -pady 2 \
        -side left 
    pack $site_4_0.02 \
        -in $site_4_0 -anchor center -expand 1 -fill x -padx 2 -pady 2 \
        -side right 
    spinbox $site_3_0.cpd72 \
        -from 0.0 -justify center -to 1000000.0 
    vTcl:DefineAlias "$site_3_0.cpd72" "SET_Timeout2" vTcl:WidgetProc "EnvListPanel" 1
    label $site_3_0.cpd73 \
        -text Shutdown: 
    vTcl:DefineAlias "$site_3_0.cpd73" "Label13" vTcl:WidgetProc "EnvListPanel" 1
    label $site_3_0.cpd74 \
        -text Timeout... 
    vTcl:DefineAlias "$site_3_0.cpd74" "Label15" vTcl:WidgetProc "EnvListPanel" 1
    place $site_3_0.cpd55 \
        -x 15 -y 330 -width 79 -height 31 -anchor nw 
    place $site_3_0.cpd56 \
        -x 105 -y 330 -width 79 -height 31 -anchor nw 
    place $site_3_0.cpd57 \
        -x 195 -y 330 -width 79 -height 31 -anchor nw 
    place $site_3_0.cpd58 \
        -x 15 -y 315 -width 752 -height 2 -anchor nw 
    place $site_3_0.cpd59 \
        -x 300 -y 335 -width 58 -height 21 -anchor nw 
    place $site_3_0.cpd61 \
        -x 288 -y 325 -width 2 -height 42 -anchor nw 
    place $site_3_0.cpd62 \
        -x 750 -y 330 -width 16 -height 33 -anchor nw 
    place $site_3_0.spi50 \
        -x 20 -y 225 -width 50 -height 25 -anchor nw -bordermode ignore 
    place $site_3_0.lab51 \
        -x 20 -y 203 -width 50 -height 19 -anchor nw -bordermode ignore 
    place $site_3_0.cpd53 \
        -x 15 -y 15 -width 737 -height 165 -anchor nw 
    place $site_3_0.cpd54 \
        -x 752 -y 37 -width 16 -height 138 -anchor nw 
    place $site_3_0.scr55 \
        -x 18 -y 180 -width 735 -height 16 -anchor nw -bordermode ignore 
    place $site_3_0.cpd64 \
        -x 80 -y 205 -width 85 -height 19 -anchor nw -bordermode ignore 
    place $site_3_0.cpd65 \
        -x 175 -y 205 -width 85 -height 19 -anchor nw -bordermode ignore 
    place $site_3_0.cpd67 \
        -x 400 -y 205 -width 65 -height 19 -anchor nw -bordermode ignore 
    place $site_3_0.cpd68 \
        -x 270 -y 205 -width 117 -height 19 -anchor nw -bordermode ignore 
    place $site_3_0.cpd69 \
        -x 475 -y 205 -width 105 -height 19 -anchor nw -bordermode ignore 
    place $site_3_0.cpd70 \
        -x 590 -y 212 -width 50 -height 12 -anchor nw -bordermode ignore 
    place $site_3_0.men72 \
        -x 80 -y 225 -width 85 -height 25 -anchor nw -bordermode ignore 
    place $site_3_0.che47 \
        -x 295 -y 258 -width 81 -height 25 -anchor nw -bordermode ignore 
    place $site_3_0.cpd48 \
        -x 365 -y 330 -width 386 -height 33 -anchor nw 
    place $site_3_0.men48 \
        -x 175 -y 225 -width 85 -height 25 -anchor nw -bordermode ignore 
    place $site_3_0.men50 \
        -x 400 -y 225 -width 65 -height 25 -anchor nw -bordermode ignore 
    place $site_3_0.men51 \
        -x 475 -y 225 -width 105 -height 25 -anchor nw -bordermode ignore 
    place $site_3_0.cpd52 \
        -x 590 -y 225 -width 50 -height 25 -anchor nw -bordermode ignore 
    place $site_3_0.cpd60 \
        -x 705 -y 205 -width 60 -height 19 -anchor nw -bordermode ignore 
    place $site_3_0.cpd63 \
        -x 705 -y 225 -width 60 -height 25 -anchor nw -bordermode ignore 
    place $site_3_0.men47 \
        -x 270 -y 225 -width 65 -height 25 -anchor nw -bordermode ignore 
    place $site_3_0.spi48 \
        -x 335 -y 225 -width 55 -height 25 -anchor nw -bordermode ignore 
    place $site_3_0.cpd50 \
        -x 15 -y 285 -width 364 -height 25 -anchor nw -bordermode ignore 
    place $site_3_0.cpd49 \
        -x 385 -y 260 -width 80 -height 46 -anchor nw 
    place $site_3_0.cpd51 \
        -x 485 -y 260 -width 80 -height 46 -anchor nw 
    place $site_3_0.cpd66 \
        -x 585 -y 260 -width 80 -height 46 -anchor nw 
    place $site_3_0.cpd71 \
        -x 685 -y 262 -width 80 -height 46 -anchor nw -bordermode ignore 
    place $site_3_0.cpd47 \
        -x 14 -y 258 -width 268 -height 25 -anchor nw -bordermode ignore 
    place $site_3_0.cpd72 \
        -x 640 -y 223 -width 50 -height 25 -anchor nw 
    place $site_3_0.cpd73 \
        -x 639 -y 210 -width 50 -height 12 -anchor nw 
    place $site_3_0.cpd74 \
        -x 588 -y 196 -width 103 -height 12 -anchor nw 
    label $top.cpd50 \
        -font {{MS Sans Serif} 10 bold} -foreground #000099 -text ScsEnvTable 
    vTcl:DefineAlias "$top.cpd50" "Label6" vTcl:WidgetProc "EnvListPanel" 1
    button $top.but54 \
        -background SystemButtonFace -command exit \
        -font {{MS Sans Serif} 10 bold} -foreground #000099 \
        -highlightcolor #000000 -pady 0 -text {Exit [Alt-X]} -width 84 
    vTcl:DefineAlias "$top.but54" "SEL_BtnExit" vTcl:WidgetProc "EnvListPanel" 1
    label $top.lab52 \
        -text ICON 
    vTcl:DefineAlias "$top.lab52" "SCS_Icon" vTcl:WidgetProc "EnvListPanel" 1
    bindtags $top.lab52 "$top.lab52 Label $top all _vTclBalloon"
    bind $top.lab52 <<SetBalloon>> {
        set ::vTcl::balloon::%W {SCADAsoft's env List & Table editor}
    }
    button $top.cpd47 \
        -background SystemButtonFace -command exit \
        -font {{MS Sans Serif} 10 bold} -foreground #000099 \
        -highlightcolor #000000 -pady 0 -state disabled \
        -text {Deploy [Alt-D]} -width 97 
    vTcl:DefineAlias "$top.cpd47" "SEL_BtnExit1" vTcl:WidgetProc "EnvListPanel" 1
    bindtags $top.cpd47 "$top.cpd47 Button $top all _vTclBalloon"
    bind $top.cpd47 <<SetBalloon>> {
        set ::vTcl::balloon::%W {This facility is not available yet!}
    }
    ###################
    # SETTING GEOMETRY
    ###################
    place $top.fra57 \
        -x 10 -y 10 -width 782 -height 308 -anchor nw 
    place $top.cpd58 \
        -x 20 -y 1 -width 90 -height 20 -anchor nw 
    place $top.fra49 \
        -x 10 -y 330 -width 782 -height 380 -anchor nw -bordermode ignore 
    place $top.cpd50 \
        -x 20 -y 320 -width 104 -height 22 -anchor nw 
    place $top.but54 \
        -x 670 -y 720 -width 120 -height 31 -anchor nw -bordermode ignore 
    place $top.lab52 \
        -x 10 -y 720 -width 32 -height 32 -anchor nw -bordermode ignore 
    place $top.cpd47 \
        -x 540 -y 720 -width 120 -height 31 -anchor nw 

    vTcl:FireEvent $base <<Ready>>
}

#############################################################################
## Binding tag:  _TopLevel

bind "_TopLevel" <<Create>> {
    if {![info exists _topcount]} {set _topcount 0}; incr _topcount
}
bind "_TopLevel" <<DeleteWindow>> {
    if {[set ::%W::_modal]} {
                vTcl:Toplevel:WidgetProc %W endmodal
            } else {
                destroy %W; if {$_topcount == 0} {exit}
            }
}
bind "_TopLevel" <Destroy> {
    if {[winfo toplevel %W] == "%W"} {incr _topcount -1}
}
#############################################################################
## Binding tag:  cdscds

#############################################################################
## Binding tag:  SelectLogEnv pFrom pTo

#############################################################################
## Binding tag:  _vTclBalloon


if {![info exists vTcl(sourcing)]} {
}
#############################################################################
## Binding tag:  <Key-F1>

#############################################################################
## Binding tag:  _vTclBalloon "tottotototo"


Window show .
Window show .top17

main $argc $argv
