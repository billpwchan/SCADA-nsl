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

#ifndef _TAO_IDL_ANYTYPECODE_LONGLONGSEQA_H_
#define _TAO_IDL_ANYTYPECODE_LONGLONGSEQA_H_

#include /**/ "ace/pre.h"

#include /**/ "tao/AnyTypeCode/TAO_AnyTypeCode_Export.h"
#include "tao/LongLongSeqC.h"


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:59

namespace CORBA
{
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_LongLongSeq;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:86

} // module CORBA


// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_sequence/any_op_ch.cpp:53



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_AnyTypeCode_Export void operator<<= ( ::CORBA::Any &, const CORBA::LongLongSeq &); // copying version
TAO_AnyTypeCode_Export void operator<<= ( ::CORBA::Any &, CORBA::LongLongSeq*); // noncopying version
TAO_AnyTypeCode_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CORBA::LongLongSeq *&); // deprecated
TAO_AnyTypeCode_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const CORBA::LongLongSeq *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




TAO_END_VERSIONED_NAMESPACE_DECL



#include /**/ "ace/post.h"

#endif /* ifndef */
