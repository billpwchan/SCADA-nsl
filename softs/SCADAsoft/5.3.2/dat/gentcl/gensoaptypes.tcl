################################################################################
#
# Namespace: 
# File name: gensoaptypes.tcl
# Returns:
# Description: Generates the SOAP types file.
#              Generates CORBA 2.3 C++ types for out parameters
#
################################################################################
#
# Author: Alain Bartolo
# Creation: 09 Jan 2001
# Modification:
#
################################################################################

global IDLInterface OrderedOperationList startIdl outputPath separator

set outputFile [appendStr $outputPath $separator [replace [file tail [replace $startIdl "\\" "/"] ] ".idl" "_types.hh"]]

# Create file with the following format: idlFileName_types.hh
set fileId [open $outputFile w 0666]

# if no interface was defined in IDL (only typedefs for example)
# create an empty file based on the file name and exit
if {[info exists IDLInterface] == 0} {

    puts $fileId [generateHeader $outputFile "the SOAP types file" \
		      "Generates typedefs for out parameters to comply with CORBA2.3 spec." "cxx"]

} else {

    # make sure interface name ends with "Idl" 
    checkInterfaceName $IDLInterface $startIdl "gensoaptypes"

    # get interface name (get rid of "Idl" suffix)
    set InterfaceName [getInterfaceName $IDLInterface]

    puts [appendStr "Generating C++ SOAP types              " $outputFile]

    puts $fileId [generateHeader $outputFile "the SOAP types file" \
		      "Generates typedefs for out parameters to comply with CORBA2.3 spec." "cxx"]

    puts $fileId [appendStr "\#ifndef _SCS_" [string toupper $InterfaceName] "_TYPES_H_"]
    puts $fileId [appendStr "\#define _SCS_" [string toupper $InterfaceName] "_TYPES_H_"]
    puts $fileId ""

    puts $fileId [appendStr "using namespace CORBA;"]
    puts $fileId ""

    puts $fileId ""
    puts $fileId "\#endif"
}