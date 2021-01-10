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

#ifndef _TAO_PIDL_PORTABLESERVER_REQUESTPROCESSINGPOLICYC_H_
#define _TAO_PIDL_PORTABLESERVER_REQUESTPROCESSINGPOLICYC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/PortableServer/portableserver_export.h"
#include "tao/Basic_Types.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/PolicyC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PortableServer_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace PortableServer
{
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_enum/enum_ch.cpp:57
  
  enum RequestProcessingPolicyValue
  {
    USE_ACTIVE_OBJECT_MAP_ONLY,
    USE_DEFAULT_SERVANT,
    USE_SERVANT_MANAGER
  };
  
  typedef RequestProcessingPolicyValue &RequestProcessingPolicyValue_out;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:644

#if !defined (_PORTABLESERVER_REQUESTPROCESSINGPOLICY__VAR_OUT_CH_)
#define _PORTABLESERVER_REQUESTPROCESSINGPOLICY__VAR_OUT_CH_
  
  class RequestProcessingPolicy;
  typedef RequestProcessingPolicy *RequestProcessingPolicy_ptr;
  
  typedef
    TAO_Objref_Var_T<
        RequestProcessingPolicy
      >
    RequestProcessingPolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        RequestProcessingPolicy
      >
    RequestProcessingPolicy_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLESERVER_REQUESTPROCESSINGPOLICY_CH_)
#define _PORTABLESERVER_REQUESTPROCESSINGPOLICY_CH_
  
  class TAO_PortableServer_Export RequestProcessingPolicy
    : public virtual ::CORBA::Policy
  {
  public:
    typedef RequestProcessingPolicy_ptr _ptr_type;
    typedef RequestProcessingPolicy_var _var_type;
    typedef RequestProcessingPolicy_out _out_type;
    
    // The static operations.
    static RequestProcessingPolicy_ptr _duplicate (RequestProcessingPolicy_ptr obj);
    
    static void _tao_release (RequestProcessingPolicy_ptr obj);
    
    static RequestProcessingPolicy_ptr _narrow (::CORBA::Object_ptr obj);
    static RequestProcessingPolicy_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static RequestProcessingPolicy_ptr _nil (void)
    {
      return static_cast<RequestProcessingPolicy_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableServer::RequestProcessingPolicyValue value (
        void) = 0;
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Policy_ptr copy (
        void) = 0;
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void destroy (
        void) = 0;
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    RequestProcessingPolicy (void);
    
    virtual ~RequestProcessingPolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    RequestProcessingPolicy (const RequestProcessingPolicy &);
    
    void operator= (const RequestProcessingPolicy &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

} // module PortableServer

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:64


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLESERVER_REQUESTPROCESSINGPOLICY__TRAITS_)
#define _PORTABLESERVER_REQUESTPROCESSINGPOLICY__TRAITS_
  
  template<>
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::RequestProcessingPolicy>
  {
    static ::PortableServer::RequestProcessingPolicy_ptr duplicate (
        ::PortableServer::RequestProcessingPolicy_ptr p
      );
    static void release (
        ::PortableServer::RequestProcessingPolicy_ptr p
      );
    static ::PortableServer::RequestProcessingPolicy_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::PortableServer::RequestProcessingPolicy_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_enum/cdr_op_ch.cpp:50



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_PortableServer_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, PortableServer::RequestProcessingPolicyValue _tao_enumerator);
TAO_PortableServer_Export ::CORBA::Boolean operator>> (TAO_InputCDR &strm, PortableServer::RequestProcessingPolicyValue &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */


