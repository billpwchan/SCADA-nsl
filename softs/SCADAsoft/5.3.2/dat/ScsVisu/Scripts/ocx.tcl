#
#
# ---- OCX/ActiveX Instruction Wrappers
#
#

namespace eval OCX {}

#
# ---- Instruction Set
#

proc OCX::Insert { PanelName OCXname OCXx OCXy OCXw OCXh {OCXid ""} } {
	Tcl_ScsInsertOCX $PanelName $OCXname $OCXx $OCXy $OCXw $OCXh $OCXid
}

proc OCX::Remove { GraphicPath OCXname } {
	Tcl_ScsRemoveOCX $GraphicPath $OCXname
}

proc OCX::SetVisibility { GraphicPath OCXname { Visible "0" } } {
	Tcl_ScsSetVisibilityOCX $GraphicPath $OCXname $Visible
}

proc OCX::GetInterface { GraphicPath OCXname } {
	Tcl_ScsGetInterfaceOCX $GraphicPath $OCXname
}

proc OCX::GetFunctionDescriptor { GraphicPath OCXname FunctionName } {
	Tcl_ScsGetFunctionDescriptorOCX $GraphicPath $OCXname $FunctionName
}

proc OCX::Invoke { GraphicPath OCXname FunctionID Parameters } {
	Tcl_ScsInvokeOCX $GraphicPath $OCXname $FunctionID $Parameters
}
