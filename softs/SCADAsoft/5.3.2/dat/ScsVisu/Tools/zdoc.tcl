#
# zdoc.tcl 
# 
# Zdoc is a documentation generator for tcl projects.
#
# See usage and limitations in file "zdoc.html"
#
# Copyright 
# Vincent Wartelle (c) 2001-2003 Oklin.com 
#
# This software comes under BSD license: free for any use, without warranty.
# See license file license.html
# 
# Version: 1.1 2003/03/05
# 
# History : 1.0     2001/09/27 
#           1.01    2001/10/31 - not published - contributions of Patrick Fradin
#                   - omit pkgIndex files
#                   - brace all expressions (optimizing)
#                   - add -nocomplain option in glob command in ::init
#                   - outdir defined as [file join [pwd] zdoc], not as [file join . zdoc] in ::init
#           1.1     2003/03/05
#                   - including 2003/2/28 John McGehee, Voom, Inc.  www.voomtown.com
#                       Fixed file names and links to support file paths where:
#                       _filelist directory != working directory != _outdir
#                       The variable $fname includes the path to the file, but the code
#                       was assuming that $fname was just the file name alone.
#                   - change date format and "generated by zdoc" message position
#                   - added _omitlines option
#                   - admit just one little blank before proc and end accolade
#


namespace eval zdoc {
    # discrete variables
    variable _verbose 0
    variable _state "init"
    variable _tmpcomments ""
    variable _procstate "outside"
    variable _procname ""
    variable _proclist {}
    # parameters
    variable _procsort "alpha"
    variable _codeprint "yes"
    variable _source "yes"
    variable _tabsize 4
    variable _omitlines 1
    # arrays    
    variable _filecomments
    variable _filehasproc
    variable _fileproccount
    variable _proccomments
    variable _proccode
    variable _procnblines
    variable _procuseproc    
    variable _procargs
}

#   set the file list to analyze
proc zdoc::set_filelist { filelist } {
    variable _filelist
    # omit pkgIndex files
    while { [set pkg_pos [lsearch -regexp $filelist "pkgIndex"]] > 0 } {    
        set filelist [lreplace $filelist $pkg_pos $pkg_pos]
    }
    set _filelist $filelist
}

#   SCADAsoft
proc zdoc::set_verbosemode { yesno } {
    variable _verbose
    set _verbose $yesno
}
proc zdoc::get_verbosemode { } {
    variable _verbose
    return $_verbose
}

#   set the output directory
proc zdoc::set_outdir { outdir } {
    variable _outdir
    set _outdir $outdir
}

#   set the order of presentation of procs
#   alpha means alphabetic, asintext means as in the original program
proc zdoc::set_procsort { procsort } {
    variable _procsort
    set _procsort $procsort
}

#   set code print
#   if yes, source code will be printed in detailed doc
proc zdoc::set_codeprint { codeprint } {
    variable _codeprint
    set _codeprint $codeprint
}

#   set source
#   if yes, source code will be sourced by zdoc
#   if no, source code must be sourced by user before
#   analysis
proc zdoc::set_source { yesno } {
    variable _source
    set _source $yesno
}

#   set tab size in number of spaces
proc zdoc::set_tabsize { tabsize } {
    variable _tabsize
    set _tabsize $tabsize
}

#   set omit lines
proc zdoc::set_omitlines { omitlines } {
    variable _omitlines
    set _omitlines $omitlines
}

#   reset contents for a new run
proc zdoc::reset {} {
    # discrete variables
    variable _state
    variable _tmpcomments
    variable _procstate
    variable _procname
    variable _proclist 
    # parameters
    variable _procsort
    variable _codeprint
    variable _source
    variable _tabsize 4
    variable _omitlines 1
    # arrays    
    variable _filecomments
    variable _filehasproc
    variable _fileproccount
    variable _proccomments
    variable _proccode
    variable _procnblines
    variable _procuseproc    
    variable _procargs
    
    set _state "init"        
    set _tmpcomments ""        
    set _proclist {}
    set _procstate "outside"
    set _procname ""        
 
    array unset _filecomments    
    array unset _filehasproc
    array unset _fileproccount
    array unset _proccomments
    array unset _proccode
    array unset _procnblines
    array unset _procuseproc
    array unset _procargs
}

#   init to default values
proc zdoc::init {} {
    zdoc::reset
    zdoc::set_filelist ""
    zdoc::set_procsort "alpha"
    zdoc::set_outdir [file join [pwd] zdoc]
    zdoc::set_codeprint "yes"
    zdoc::set_source "yes"
    zdoc::set_tabsize 4
}

#   run the analyze and generate the docs
proc zdoc::run {} {
	variable _verbose
	if { $_verbose } {
		puts "zdoc: start analyze"
	}
    zdoc::analyze
	if { $_verbose } {
		puts "zdoc: end analyze"
		puts "zdoc: start dump"
	}
    zdoc::create_doc
	if { $_verbose } {
		puts "zdoc: end dump"
	}
}

#   run the analyze
proc zdoc::analyze {} {
    variable _filelist
    variable _verbose
	if { !$_verbose } {

		puts -nonewline stderr "zdoc: analyzing"
	}
	foreach fname $_filelist {
		if { !$_verbose } {
			puts -nonewline stderr "."
		}
        zdoc::analyze_file $fname
    }
	if { !$_verbose } {
		puts stderr ""
	}
    zdoc::analyze_procs
}

# SCADAsoft:
# Prepend with namespace name, otherwise all OnInit will refer the same code...
proc isPanelOrList { name } {

	# Test Panel
    set first [lindex [split $name "/"] 2]
    if { $first == "Panels" } {
		return 1
    }
    
	# Test Animator
    if { $first == "Animator" } {
		return 1
    }
    
	# Test ScsList
    set first [lindex [split $name "/"] 0]
    if { $first == "ScsList" } {
		return 2
    }
    
    return 0
}

proc namespaceName { name } {
    return [lindex [split [lindex [split $name "/"] [expr [llength [split $name "/"]] -1]] "."] 0]
}

#   analyze a file
#   to give its head comments,
#   and for each proc, its head comments
proc zdoc::analyze_file { fname } {
    variable _state
    variable _filecomments
    variable _tmpcomments
    variable _filehasproc
    variable _fileproccount
    variable _procstate
    variable _procname
    variable _proccomments
    variable _proccode
    variable _procnblines
    variable _source
    variable _verbose

    set fid [open $fname]
    set _state "init"
    set _procstate "outside"
    set _filecomments($fname) {}
    set _tmpcomments {}

    # source the proc
    if { $_source == "yes" } {
		if { [isPanelOrList $fname] } {
			if { $_verbose } {
				puts "zdoc: now sourcing '$fname'"
			}
			set result [ catch {namespace eval ::[namespaceName $fname]:: [list source $fname]} ]
			if { $result != 0 } {
				if { $_verbose } {
					puts "zdoc: warning, problem when parsing '$fname'"
				}
			}
		} else {
			set result [ catch {namespace eval :: [list source $fname]} ]
			if { $result != 0 } {
				if { $_verbose } {
					puts "zdoc: warning, file '$fname' does not contain procedures"
				}
			}
		}
    }
    
    while {1} {
        # don't put this test just after the gets line: would miss last line
        if {[eof $fid]} {
            close $fid
            return
        }
        set readline [gets $fid]
        set analyzis [zdoc::analyze_line $readline $fname]

        # if in insproc state, wait until outside the proc
        # to change to outproc state
        if { $_state == "insproc" && $_procstate == "outside" } {
            set _state "outproc"
        }
        
        # if in outproc state, wait until inside the proc
        # , accumulating comments of the proc, 
        # then change to insproc state and store comments
        # , and declare in which file the proc is
        if { $_state == "outproc" } {
            if { $_procstate == "outside" } {
                if { [lindex $analyzis 0] == "comment" } {
                    lappend _tmpcomments [lindex $analyzis 1]
                }
            } else {
                set _state "insproc"
                set _proccode($_procname) {}
                set _procnblines($_procname) 0
                set _proccomments($_procname) $_tmpcomments
                # compute procnum, the position of the proc in the file
                if { [info exists _fileproccount($fname)] } {
                    set procnum [incr _fileproccount($fname)]
                } else {
                    set procnum 1
                    set _fileproccount($fname) 1
                }
                set _filehasproc($fname,$_procname) $procnum
                set _tmpcomments {}
            }
        }
        
        # if inside proc, accumulate code lines
        if { $_state == "insproc" } {
            lappend _proccode($_procname) $readline
            incr _procnblines($_procname)
        }
    
        # if in init state, wait until the end of comments, accumulating them,
        # then switch to outproc state
        if { $_state == "init" } {
            if { [lindex $analyzis 0] == "comment" } {
                lappend _filecomments($fname) [lindex $analyzis 1]
            } else {
                set _state "outproc"
                # puts stdout "head comments: $_filecomments($fname)"
            }            
        }
    }    
        
    
}

#   analyze a program line
#   - return "comment $content" or "code $content"
#   - if line is not comment, determine _procstate: inside or outside proc
#     and update _proclist
proc zdoc::analyze_line { line fname } {
    variable _procname
    variable _proclist
    variable _procstate

    # puts -nonewline stdout "   $_procstate: "
            
    # if line begins with 0 to N times white space or tab
    # followed by #, then it is a comment line
    # don't make further analyzes
    
    if { [regexp "\^\[ \t\]*\#" $line] } {
        regsub "\^\[ \t\]*\#" $line "" content
        return [list "comment" $content]
    }
  
    # if line begins with no more than one white space 
    # followed by "proc " , then we get the proc name
    # and declare to be inside a proc
       
    if { [regexp "\^ ?proc " $line] } {
		# don't use lindex because $workzone is not a correct list
		if { [isPanelOrList $fname] } {
			regsub "\^ ?proc " $line "" workzone
			set firstblank [string first " " $workzone]
			set _procname [namespaceName $fname]::[string range $workzone 0 [expr {$firstblank - 1}]]
		} else {
			regsub "\^ ?proc " $line "" workzone
			set firstblank [string first " " $workzone]
			set _procname [string range $workzone 0 [expr {$firstblank - 1}]]
		}
		if { [lsearch $_proclist $_procname] == -1 } {
			lappend _proclist $_procname
		}
		set _procstate "inside"
    }
    
    # if line begins with "namespace eval", consider being inside    
    # a proc whose name is the namespace name
    # but don't add it to the _proclist
    if { [regexp "\^namespace eval " $line] } {
        regsub "\^namespace eval " $line "" workzone
        set firstblank [string first " " $workzone]
	# don't use lindex because $workzone is not a correct list     
        set _procname [string range $workzone 0 [expr {$firstblank - 1}]]
        set _procstate "inside"
    }

    # if line begins with no more than one white space 
    # and a closing accolade , we are outside the proc
    if { [regexp "\^ ?\}" $line] } {
        set _procstate "outside"
    }
    
    # default situation: the line is considered as a code line
    return [list "code" "$line"]
}



#   analyze known procs to
#   describe arguments and build cross-reference    
proc zdoc::analyze_procs {} {    
    variable _proclist
    variable _procargs
    variable _procuseproc
    variable _verbose
    
    # chars admissible before or after a proc name    
    set goodprevchars "\ \{\[\t\n"
    set goodnextchars "\ \}\]\t\n"
    foreach procname $_proclist {
		if { $_verbose } {
			puts "zdoc: now analyzing '$procname'"
		}
		
		if [catch {set _procargs($procname) [info args $procname]}] {
			if { $_verbose } {
				puts "      Potential problem when analyzing '$procname'"
			}
		} else {
			foreach usedproc $_proclist {

				# SCADAsoft: remove NS references in order to find **internal** dependencies
				set nsLength [expr [string last ":" $procname]]
				set tmpusedproc $usedproc
				if { $nsLength > 0 } {
					if { [string range $usedproc 0 $nsLength] == [string range $procname 0 $nsLength] } {
						set tmpusedproc [string range $usedproc [expr $nsLength + 1] [string length $usedproc]]
					}
				}

				if {[ set firstchar [string first $tmpusedproc [info body $procname]] ] != -1 } {
									
					# check that the char before is blank, brace or bracket or quote or tab
					set proccontent [info body $procname]            
					set prevchar [string index $proccontent [expr {$firstchar - 1}]]
					if { [string first $prevchar $goodprevchars] == -1 } {
						continue
					}
					# check that the next char is blank, brace or bracket or quote or tab
					set uselength [string length $tmpusedproc]
					set nextchar [string index $proccontent [expr {$firstchar + $uselength}]]
					if { [string first $nextchar $goodnextchars] == -1 } {
						continue
					}
					set _procuseproc($procname,$usedproc) 1
				}
			}
        }        
    }
}


#   get the procs of a file as a list, sorted within the option
#   given by _procsort ("alpha" or "asintext")
proc zdoc::get_proclist { fname } {
    variable _filehasproc
    variable _procsort
    
    # "array get" returns a list of "$fname,$procname $procorder"
    # transform it to a list of {$procname $procorder}
    set bilist [array get zdoc::_filehasproc $fname*]
    set list1 {}
    set part 0
    foreach elem $bilist {
        if { $part == 0 } {
            regsub "^$fname," $elem "" elemlist
            set part 1
        } else {
            set elemlist [list $elemlist $elem]
            lappend list1 $elemlist
            set part 0
        }
    }
    # sort the list
    if { $_procsort == "alpha" } {
        set list2 [lsort -index 0 $list1 ]
    } else {
        set list2 [lsort -index 1 -integer $list1 ]
    }
    # constitue return list
    set retlist {}
    foreach elem $list2 {
        lappend retlist [lindex $elem 0]
    }
    return $retlist
}

#   identify the file in which a proc is stored
proc zdoc::get_procfile { procname } {
    variable _filehasproc
    
    #   
    set procfile [array get zdoc::_filehasproc *,$procname]
    set fname [ lindex [split $procfile ","] 0]
    
    return $fname
}
        
#   transform a list of comment lines to html code
proc zdoc::comments_tohtml { comments } {
    variable _omitlines
    set htmltext ""
    foreach textline $comments {
        # omit dash lines made with a unique char repeated
        # to do this, count how many chars in lines longer than 20 chars
        if { $_omitlines && [string length $textline] > 20 } {      
            set howmanychars [llength [lsort -unique [split $textline ""]]]
            if { $howmanychars < 4 } {
                continue
            }
        }
        if { $htmltext != "" } {
            set htmltext "$htmltext<BR>$textline"
        } else {
            set htmltext $textline
        }
    }
    return $htmltext
}

#   transform a list of code lines to html code
#   keep white space visible
proc zdoc::code_tohtml { lines } {
    variable _tabsize
    set htmltext ""
    foreach textline $lines {
        # replace & by &amp; to avoid html interpretation
        regsub -all "\&" $textline "\\&amp;" textline
        # replace < and > by &lt; and &gt; to avoid html interpretation      
        regsub -all "\<" $textline "\\&lt;" textline
        regsub -all "\>" $textline "\\&gt;" textline
        
        # if a comment line show it in green
        # (won't colorize end of line comments, nor comment lines continuations)
        if { [regexp "\^\[ \t\]*\#" $textline] } {
            set textline "<font color=\"#13920D\">$textline</font>"
        }
                
        # replace each double blank by a double html blank (&nbsp;)
        regsub -all "\ \ " $textline "\\&nbsp;\\&nbsp;" textline  
        # replace tabs by white space
        set blanks [string repeat "\\&nbsp;" $_tabsize]
        regsub -all "\\t" $textline $blanks textline
        # append line to result
        if { $htmltext != "" } {
            set htmltext "$htmltext<BR>$textline"
        } else {
            set htmltext $textline
        }
    }
    return $htmltext
}   


#   files and procs being analyzed, create the documentation
proc zdoc::create_doc {} {
    variable _filelist
    variable _outdir
    variable _filecomments
    variable _proccomments
    variable _procargs
    variable _verbose

	if { !$_verbose } {
		puts -nonewline stderr "zdoc: generating HTML"
	}

    set fdindex [open [file join $_outdir zdoc_index.html] w]
    puts $fdindex "<html><a name=__PageTop__>"
    puts $fdindex "<head><title>zdoc:zdoc_index.html</title></head><body bgcolor=\"\#E3E4FA\">"
    puts $fdindex "<h2>SCADAsoft's TCL documentation</h2>"
    puts $fdindex "<h3>General index (generated from \"${::env(SCSPATH)}\")</h3>"
    
    set sortedlist [lsort $_filelist]
    foreach fname $sortedlist {
        
		if { !$_verbose } {
			puts -nonewline stderr "."
		}
        
        #   1. write a html table in index file for each source file
        zdoc::write_fileindexheader $fdindex $fname
        
        #   2. create a html file for each source file
        set fdproc [open [file join $_outdir [file tail ${fname}.html]] w] ;# rev 1.1b
        zdoc::write_filedetailheader $fdproc $fname
        
        set proclist [zdoc::get_proclist $fname]
        foreach procname $proclist {
            
            # 1.  write a html line in index for each proc, with comments and args of the proc
            zdoc::write_procindextext $fdindex $procname
            
            # 2. write a html table for proc in doc file corresponding to each source
            zdoc::write_procdetailtext $fdproc $procname
            
            # close proc table
            puts $fdproc "</table>"
            zdoc::close_procdetailtext $fdproc $procname
            
        }        
        
        zdoc::close_fileindexheader $fdindex $fname        
        
        # close doc file corresponding to source
        zdoc::close_filedetailheader $fdproc $fname        
    }
    set dday [clock format [clock seconds] -format "%Y-%m-%d %H:%M:%S"]
    puts $fdindex "<br><br><center><font size=\"-1\">Generated by zdoc.tcl on $dday</font></center>"
    puts $fdindex "<center><font size=\"-1\">Modified by and for SCADAsoft (c) THALES Information Systems</font></center>"
    
    # close index file
    puts $fdindex "</body></html>"
    close $fdindex
	if { !$_verbose } {
		puts stderr ""
	}
}

#   write the file header of the index file
proc zdoc::write_fileindexheader { fdout fname } {
    puts $fdout "<br><br>"
    puts $fdout "<table border=\"1\" cellpadding=\"3\" cellspacing=\"0\" width=\"100%\">"
    puts $fdout "<tr bgcolor=\"#8CAAE6\">" 
    puts $fdout "<td width =\"40%\"><b>$fname</b></font></td>"
    puts $fdout "<td width =\"5%\">Lines</td>"
    puts $fdout "<td width =\"40%\">Comments</td>"
    puts $fdout "<td width =\"15%\">Arguments</td>"
}

#   close the file documentation in the index file
proc zdoc::close_fileindexheader { fdout fname } {
    puts $fdout "</table><font size=\"-1\"><a href=\#__PageTop__>Top of the page</a></font>"
}

#   write the file header of the detailed file
proc zdoc::write_filedetailheader { fdout fname } {
    variable _filecomments
    puts $fdout "<html><a name=__PageTop__>"
    puts $fdout "<head><title>zdoc:$fname</title></head><body bgcolor=\"\#E3E4FA\">"
    puts $fdout "<h2>$fname</h2>"
    if {[info exists _filecomments($fname)] && $_filecomments($fname) != "" } {
        set filecomment [zdoc::comments_tohtml $_filecomments($fname)]
        puts $fdout "<blockquote>" 
        puts $fdout $filecomment
        puts $fdout "</blockquote>"
    }
}

#   close the detailed documentation file of a file
proc zdoc::close_filedetailheader { fdout fname } {
    set dday [clock format [clock seconds] -format "%Y-%m-%d %H:%M:%S"]
    puts $fdout "<br><br><center><font size=\"-1\">Generated by zdoc.tcl on $dday</font></center>"
    puts $fdout "<center><font size=\"-1\">Modified by and for SCADAsoft (c) THALES Information Systems</font></center>"
    puts $fdout "</body></html>"
    close $fdout
}
        
#   write the proc line of the index file        
proc zdoc::write_procindextext { fdout procname } {
    variable _proccomments  
    variable _procnblines
    variable _procargs

    puts $fdout "<tr bgcolor=\"white\">"

    # proc name, and link to detail documentation, and procname as anchor name
    set fname [zdoc::get_procfile $procname]    
    set linkname [file tail ${fname}.html#${procname}]    ; # rev 1.1b

	set tmp [string range $procname [expr [string last ":" $procname ] + 1] [string length $procname]]
    puts $fdout "<td width =\"40%\"><a name=\"$procname\"></a><a href=\"$linkname\">$tmp</a></td>"
    
    # number of code lines
    puts $fdout "<td  width =\"5%\" align=\"right\">"
    if { [info exists _procnblines($procname)] } {
        puts $fdout $_procnblines($procname)
    } else {
        puts $fdout 0
    }
    puts $fdout "</td>"

    
    # proc comments
    puts $fdout "<td width =\"40%\">"
    if {[info exists _proccomments($procname)] && $_proccomments($procname) != "" } {
        set proccomment [zdoc::comments_tohtml $_proccomments($procname)]                       
    } else {
        set proccomment "\&nbsp;"
    }
    puts $fdout $proccomment
    puts $fdout "</td>"

    
    # proc args
    puts $fdout "<td width =\"15%\">"
    if {[info exists _procargs($procname)] && $_procargs($procname) != "" } {
        set procarg "$_procargs($procname)"
    } else {
        set procarg "\&nbsp;"                
    }
    puts $fdout $procarg

    puts $fdout "</td>"
    puts $fdout "</tr>"
}                    

#   write the detail proc documentation
proc zdoc::write_procdetailtext  { fdout procname } {
    variable _proccomments
    variable _procargs
    variable _procuseproc
    variable _proccode
    variable _codeprint

    # proc name, and link to index documentation, and procname as anchor name   
    set linkname "zdoc_index.html#$procname"

    puts $fdout "<br><br>"
    puts $fdout "<table border=\"1\" cellpadding=\"3\" cellspacing=\"0\" width=\"100%\">"
    puts $fdout "<tr bgcolor=\"#8CAAE6\">"
    puts $fdout "<td colspan=2><a name=$procname></a>" 
    puts $fdout "<font size=\"+1\"><b><a href=\"$linkname\">$procname</a></b></font>"
    puts $fdout "</td>"
    puts $fdout "</tr>"

    # proc comments
    if {[info exists _proccomments($procname)] && $_proccomments($procname) != "" } {
        set proccomment [zdoc::comments_tohtml $_proccomments($procname)]                
    } else {
        set proccomment "\&nbsp;"
    }
    
    puts $fdout "<tr bgcolor=\"white\">"
    puts $fdout "<td width =\"20%\">Comments</td>"
    puts $fdout "<td width =\"80%\"><font color=\"blue\">$proccomment</font></td>"
    puts $fdout "</tr>"

    # proc args
    if {[info exists _procargs($procname)] && $_procargs($procname) != "" } {
        set procarg $_procargs($procname)
    } else {
        set procarg "\&nbsp;"                
    }   
    puts $fdout "<tr bgcolor=\"white\">"
    puts $fdout "<td width =\"20%\">Arguments</td>"            
    regsub -all "\ "  $procarg <br> multilinearg
    puts $fdout "<td width =\"80%\">$multilinearg</td>"

    # this proc is used by...
    set usedbylist [array get zdoc::_procuseproc *,$procname]
    set userproclinks {}
    foreach usedbyitem $usedbylist {
        set nbsub [regsub -all "\,\.*" $usedbyitem "" userprocname ]
        if {$nbsub == 1 } {
            set fname [zdoc::get_procfile $userprocname]
            set linkname [file tail ${fname}.html#${userprocname}] ; # rev 1.1b
            set link "<a href=\"$linkname\">$userprocname" ; # rev 1.1b        
            if { $userproclinks != {} } { set userproclinks "$userproclinks<br>" }
            set userproclinks "$userproclinks$link"
        }
    }
    if { $userproclinks == "" } { set userproclinks "\&nbsp;" }
    puts $fdout "<tr bgcolor=\"white\">"
    puts $fdout "<td width =\"20%\">Internally used by</td>"  
    puts $fdout "<td width =\"80%\">$userproclinks</td>"
    puts $fdout "</tr>"

    # this proc uses...
    # regsub -all "\.*\," $usedbyitem "" userprocname
    set usedlist [array get zdoc::_procuseproc $procname,*]
    set usedproclinks {}
    foreach useditem $usedlist {
        set nbsub [regsub -all "\.*\," $useditem "" usedprocname]
        if {$nbsub == 1} {
            set fname [zdoc::get_procfile $usedprocname]    
            set linkname [file tail ${fname}.html#${usedprocname}] ; # rev 1.1b
            set link "<a href=\"$linkname\">$usedprocname" ; # rev 1.1b           
            if { $usedproclinks != {} } { set usedproclinks "$usedproclinks<br>" }
            set usedproclinks "$usedproclinks$link"
        }
    }
    if { $usedproclinks == "" } { set usedproclinks "\&nbsp;" }
    puts $fdout "<tr bgcolor=\"white\">"
    puts $fdout "<td width =\"20%\">Internally uses</td>" 
    puts $fdout "<td width =\"80%\">$usedproclinks</td>"
    puts $fdout "</tr>"
    
    # and now the code
    if { $_codeprint == "yes" } {
        set proccode [zdoc::code_tohtml $_proccode($procname)]
        puts $fdout "<tr bgcolor=\"white\">"
        puts $fdout "<td align=left colspan=2><code>"
        puts $fdout $proccode
        puts $fdout "<br>\}"
        puts $fdout "</code></td>"
        puts $fdout "</tr>" 
    }
    
}

#   close the detailed proc documentation
proc zdoc::close_procdetailtext  { fdout procname } {
    puts $fdout "</table><font size=\"-1\"><a href=\#__PageTop__>Top of the page</a></font>"
}
