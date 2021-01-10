// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6a_p15 ****
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
// be\be_codegen.cpp:135

#ifndef _TAO_PIDL_PI_FORWARDC_H_
#define _TAO_PIDL_PI_FORWARDC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/TAO_Export.h"
#include "tao/Basic_Types.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/OctetSeqC.h"
#include "tao/StringSeqC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace PortableInterceptor
{
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:413
  
  typedef char * ServerId;
  typedef ::CORBA::String_var ServerId_var;
  typedef ::CORBA::String_out ServerId_out;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:413
  
  typedef char * ORBId;
  typedef ::CORBA::String_var ORBId_var;
  typedef ::CORBA::String_out ORBId_out;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:472
  
  typedef CORBA::StringSeq AdapterName;
  typedef CORBA::StringSeq_var AdapterName_var;
  typedef CORBA::StringSeq_out AdapterName_out;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:472
  
  typedef CORBA::OctetSeq ObjectId;
  typedef CORBA::OctetSeq_var ObjectId_var;
  typedef CORBA::OctetSeq_out ObjectId_out;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:413
  
  typedef char * AdapterManagerId;
  typedef ::CORBA::String_var AdapterManagerId_var;
  typedef ::CORBA::String_out AdapterManagerId_out;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef ::CORBA::Short AdapterState;
  typedef ::CORBA::Short_out AdapterState_out;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef ::CORBA::ULong SlotId;
  typedef ::CORBA::ULong_out SlotId_out;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef ::CORBA::Short ReplyStatus;
  typedef ::CORBA::Short_out ReplyStatus_out;

// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

} // module PortableInterceptor

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:64


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */


