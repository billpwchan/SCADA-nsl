;
; ### Check mandatory variables
;
set error 0
if [catch {set dummy $::env(SCSHOME)}] {
	puts "zdoc: SCSHOME not defined"
	set error 1
}

if [catch {set dummy $::env(SCSPATH)}] {
	puts "zdoc: SCSPATH not defined"
	set error 1
} 
if { $error } {
	return
}


;
;### Source ZDOC namespace
;
puts "zdoc: sourcing"
if [catch {source $::env(SCSHOME)/dat/ScsVisu/Tools/zdoc.tcl}] {
	puts "zdoc: could not find 'zdoc.tcl' or file is damaged"
	return
}


;
;### Init ZDOC
;

puts "zdoc: initializing"
set previousPwd [pwd]
cd $::env(SCSPATH)
zdoc::init


;########################
;### Begin ZDOC setup ###
;

;# Procedures sorting [*alpha|asintext]
zdoc::set_procsort alpha

;# Include source? [*yes|no]
zdoc::set_codeprint yes

;# Auto-sourcing? [*yes|no]
zdoc::set_source yes

;# Tabulations size [*4|N>=0]
zdoc::set_tabsize 4

;# Ignore dummy comments? [*1|0]
zdoc::set_omitlines 1

;# Verbose? [*0|1]
zdoc::set_verbosemode 0

;
;###  End ZDOC setup  ###
;########################


;
;### ZDOC's output directory [*$PWD/zdoc|any path]
;
puts "zdoc: defining output (\$SCSPATH/zdoc)"
set outDir $::env(SCSPATH)/zdoc
if { ![file exists $outDir] } {
	puts "zdoc: creating output directory"
	if [catch {file mkdir $outDir}] {
		puts "      Could not create output directory"
		return
	}
}
zdoc::set_outdir $outDir


;
;### Directories to be browsed (related to $::env(SCSPATH)/ScsVisu/Scripts)
;
puts "zdoc: defining input  (\$SCSPATH/zdoc/zdoc.ini)"
if { ![file exists $outDir/zdoc.ini] } {
	puts "zdoc: could not found '$outDir/zdoc.ini'"
	return
}
source $outDir/zdoc.ini
set inDir {}
for { set i 0 } { $i < [llength $inDirList] } { incr i } {
	set result [catch {set inDir "$inDir [glob [lindex $inDirList $i]/*.tcl]"}]
	if { $result && [zdoc::get_verbosemode] } {
		puts "zdoc: Warning, no files match '[lindex $inDirList $i]/*.tcl'"
	}
}

if { [zdoc::get_verbosemode] } {
	puts "\n_________________________________________"
	puts "zdoc: will analyze the following files"
	for { set i 0 } { $i < [llength $inDir] } { incr i } {
		puts [format "%5d: $::env(SCSPATH)/ScsVisu/Scripts/%s" [expr $i + 1] [lindex $inDir $i]] 
	}
	puts "_________________________________________\n"
}
zdoc::set_filelist $inDir


;
;### Run ZDOC
;
puts "zdoc: running"
zdoc::run
cd $previousPwd 
puts "zdoc: completed! (check '$outDir/zdoc_index.html')\n"
