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
// be\be_codegen.cpp:135

#ifndef _TAO_PIDL_PI_PIFORWARDREQUESTC_H_
#define _TAO_PIDL_PI_PIFORWARDREQUESTC_H_

#include /**/ "ace/pre.h"

#ifndef TAO_PI_SAFE_INCLUDE
#error You should not include PI/PIForwardRequestC.h, use tao/PI/PI.h
#endif /* TAO_PI_SAFE_INCLUDE */

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/PI/pi_export.h"
#include "tao/UserException.h"
#include "tao/Basic_Types.h"
#include "tao/Object.h"
#include "tao/VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PI_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace PortableInterceptor
{
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_exception/exception_ch.cpp:53

#if !defined (_PORTABLEINTERCEPTOR_FORWARDREQUEST_CH_)
#define _PORTABLEINTERCEPTOR_FORWARDREQUEST_CH_
  
  class TAO_PI_Export ForwardRequest : public ::CORBA::UserException
  {
  public:
    
    ::CORBA::Object_var forward;
    ForwardRequest (void);
    ForwardRequest (const ForwardRequest &);
    ~ForwardRequest (void);

    ForwardRequest &operator= (const ForwardRequest &);
    
    static void _tao_any_destructor (void *);
    
    static ForwardRequest *_downcast ( ::CORBA::Exception *);
    static const ForwardRequest *_downcast ( ::CORBA::Exception const *);
    
    static ::CORBA::Exception *_alloc (void);
    
    virtual ::CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void) const;

    virtual void _tao_encode (TAO_OutputCDR &cdr) const;
    virtual void _tao_decode (TAO_InputCDR &cdr);
    
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_exception/exception_ctor.cpp:66
    
    ForwardRequest (
        const ::CORBA::Object_ptr  _tao_forward
      );
    
    virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

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
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_exception/cdr_op_ch.cpp:52

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_PI_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const PortableInterceptor::ForwardRequest &);
TAO_PI_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, PortableInterceptor::ForwardRequest &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */


