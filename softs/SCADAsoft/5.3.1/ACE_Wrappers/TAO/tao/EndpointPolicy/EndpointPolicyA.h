// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6a_p10 ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:908

#ifndef _TAO_IDL_ENDPOINTPOLICY_ENDPOINTPOLICYA_H_
#define _TAO_IDL_ENDPOINTPOLICY_ENDPOINTPOLICYA_H_

#include /**/ "ace/pre.h"

#include /**/ "tao/EndpointPolicy/EndpointPolicy_Export.h"
#include "tao/EndpointPolicy/EndpointPolicyC.h"
#include "tao/AnyTypeCode/PolicyA.h"
#include "tao/EndpointPolicy/EndpointPolicyTypeA.h"


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:59

namespace EndpointPolicy
{
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_EndpointPolicy_Export ::CORBA::TypeCode_ptr const _tc_EndpointValueBase;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_EndpointPolicy_Export ::CORBA::TypeCode_ptr const _tc_EndpointList;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_EndpointPolicy_Export ::CORBA::TypeCode_ptr const _tc_Policy;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:86

} // module EndpointPolicy


// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:54



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace EndpointPolicy
{
  TAO_EndpointPolicy_Export void operator<<= ( ::CORBA::Any &, EndpointValueBase_ptr); // copying
  TAO_EndpointPolicy_Export void operator<<= ( ::CORBA::Any &, EndpointValueBase_ptr *); // non-copying
  TAO_EndpointPolicy_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, EndpointValueBase_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_EndpointPolicy_Export void operator<<= (::CORBA::Any &, EndpointPolicy::EndpointValueBase_ptr); // copying
TAO_EndpointPolicy_Export void operator<<= (::CORBA::Any &, EndpointPolicy::EndpointValueBase_ptr *); // non-copying
TAO_EndpointPolicy_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, EndpointPolicy::EndpointValueBase_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_sequence/any_op_ch.cpp:53



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_EndpointPolicy_Export void operator<<= ( ::CORBA::Any &, const EndpointPolicy::EndpointList &); // copying version
TAO_EndpointPolicy_Export void operator<<= ( ::CORBA::Any &, EndpointPolicy::EndpointList*); // noncopying version
TAO_EndpointPolicy_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, EndpointPolicy::EndpointList *&); // deprecated
TAO_EndpointPolicy_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const EndpointPolicy::EndpointList *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:54



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace EndpointPolicy
{
  TAO_EndpointPolicy_Export void operator<<= ( ::CORBA::Any &, Policy_ptr); // copying
  TAO_EndpointPolicy_Export void operator<<= ( ::CORBA::Any &, Policy_ptr *); // non-copying
  TAO_EndpointPolicy_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Policy_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_EndpointPolicy_Export void operator<<= (::CORBA::Any &, EndpointPolicy::Policy_ptr); // copying
TAO_EndpointPolicy_Export void operator<<= (::CORBA::Any &, EndpointPolicy::Policy_ptr *); // non-copying
TAO_EndpointPolicy_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, EndpointPolicy::Policy_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

TAO_END_VERSIONED_NAMESPACE_DECL



#include /**/ "ace/post.h"

#endif /* ifndef */
