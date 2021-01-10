set __dir__ $dir 
foreach index [glob -nocomplain [file join $dir * pkgIndex.tcl]] {
  set dir [file dirname $index]
  source $index
} 
set dir $__dir__ 
unset __dir__ 

  package ifneeded XOTcl 1.3.4 [list load \
    [file join $dir xotcl134.dll] XOTcl]


