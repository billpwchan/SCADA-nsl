// $Id: be_visitor_interface.cpp 14 2007-02-01 15:49:12Z mitza $
//
/* -*- c++ -*- */
// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_visitor_interface.cpp
//
// = DESCRIPTION
//    Visitors for generation of code for Interface
//
// = AUTHOR
//    Aniruddha Gokhale and Carlos O'Ryan
//
// ============================================================================

#include "be_argument.h"
#include "be_interface.h"
#include "be_attribute.h"
#include "be_constant.h"
#include "be_enum.h"
#include "be_exception.h"
#include "be_module.h"
#include "be_operation.h"
#include "be_structure.h"
#include "be_structure_fwd.h"
#include "be_union.h"
#include "be_union_fwd.h"
#include "be_typedef.h"
#include "be_predefined_type.h"
#include "be_component.h"
#include "be_helper.h"
#include "be_extern.h"
#include "be_util.h"
#include "be_native.h"
#include "utl_identifier.h"
#include "utl_exceptlist.h"
#include "nr_extern.h"

#include "be_visitor_interface.h"
#include "be_visitor_attribute.h"
#include "be_visitor_constant.h"
#include "be_visitor_enum.h"
#include "be_visitor_exception.h"
#include "be_visitor_structure.h"
#include "be_visitor_structure_fwd.h"
#include "be_visitor_typedef.h"
#include "be_visitor_union.h"
#include "be_visitor_union_fwd.h"
#include "be_visitor_operation.h"
#include "be_visitor_typecode.h"
#include "be_visitor_context.h"
#include "be_visitor_native.h"
#include "ace/Auto_Ptr.h"

#include "be_visitor_interface/interface.cpp"
#include "be_visitor_interface/interface_ch.cpp"
#include "be_visitor_interface/interface_ci.cpp"
#include "be_visitor_interface/interface_cs.cpp"
#include "be_visitor_interface/interface_sh.cpp"
#include "be_visitor_interface/interface_ih.cpp"
#include "be_visitor_interface/interface_si.cpp"
#include "be_visitor_interface/interface_ss.cpp"
#include "be_visitor_interface/interface_is.cpp"
#include "be_visitor_interface/tie_sh.cpp"
#include "be_visitor_interface/tie_ss.cpp"
#include "be_visitor_interface/any_op_ch.cpp"
#include "be_visitor_interface/any_op_cs.cpp"
#include "be_visitor_interface/cdr_op_ch.cpp"
#include "be_visitor_interface/cdr_op_cs.cpp"
#include "be_visitor_interface/smart_proxy_ch.cpp"
#include "be_visitor_interface/smart_proxy_cs.cpp"
#include "be_visitor_interface/ami_interface_ch.cpp"

// Proxy Brokers
#include "be_visitor_interface/strategized_proxy_broker_sh.cpp"
#include "be_visitor_interface/strategized_proxy_broker_ss.cpp"

// Proxy Impls
#include "be_visitor_interface/direct_proxy_impl_sh.cpp"
#include "be_visitor_interface/direct_proxy_impl_ss.cpp"

// AMH
#include "be_visitor_interface/amh_ch.cpp"
#include "be_visitor_interface/amh_ss.cpp"
#include "be_visitor_interface/amh_si.cpp"
#include "be_visitor_interface/amh_sh.cpp"
#include "be_visitor_interface/amh_rh_ss.cpp"
#include "be_visitor_interface/amh_rh_sh.cpp"

ACE_RCSID (be,
           be_visitor_interface,
           "$Id: be_visitor_interface.cpp 14 2007-02-01 15:49:12Z mitza $")