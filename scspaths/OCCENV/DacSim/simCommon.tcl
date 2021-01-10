#------------------------------------------------------------
# init random number
expr srand([clock seconds])

#------------------------------------------------------------
# declare constants
set pi [expr acos(-1.0)]

#------------------------------------------------------------
# Functions
#------------------------------------------------------------
# generate random integer number in the range [min,max]
proc RandomInteger {min max} {
  return [expr {int(rand()*($max-$min+1)+$min)}]
}

