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

#ifndef _TAO_PIDL_DIFFSERVPOLICY_DIFFSERVPOLICYC_H_
#define _TAO_PIDL_DIFFSERVPOLICY_DIFFSERVPOLICYC_H_

#include /**/ "ace/pre.h"

#ifndef TAO_DIFFSERVPOLICY_SAFE_INCLUDE
#error You should not include DiffServPolicy/DiffServPolicyC.h, use tao/DiffServPolicy/DiffServPolicy.h
#endif /* TAO_DIFFSERVPOLICY_SAFE_INCLUDE */

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/DiffServPolicy/DiffServPolicy_Export.h"
#include "tao/Basic_Types.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/PolicyC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_DiffServPolicy_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace TAO
{
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef ::CORBA::Long DiffservCodepoint;
  typedef ::CORBA::Long_out DiffservCodepoint_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_enum/enum_ch.cpp:57
  
  enum NetworkPriorityModel
  {
    CLIENT_PROPAGATED_NETWORK_PRIORITY,
    SERVER_DECLARED_NETWORK_PRIORITY,
    NO_NETWORK_PRIORITY
  };
  
  typedef NetworkPriorityModel &NetworkPriorityModel_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::PolicyType SERVER_NETWORK_PRIORITY_TYPE = 1413545986U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::PolicyType CLIENT_NETWORK_PRIORITY_TYPE = 1413545987U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::PolicyType NETWORK_PRIORITY_TYPE = 1413545988U;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:644

#if !defined (_TAO_NETWORKPRIORITYPOLICY__VAR_OUT_CH_)
#define _TAO_NETWORKPRIORITYPOLICY__VAR_OUT_CH_
  
  class NetworkPriorityPolicy;
  typedef NetworkPriorityPolicy *NetworkPriorityPolicy_ptr;
  
  typedef
    TAO_Objref_Var_T<
        NetworkPriorityPolicy
      >
    NetworkPriorityPolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        NetworkPriorityPolicy
      >
    NetworkPriorityPolicy_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_TAO_NETWORKPRIORITYPOLICY_CH_)
#define _TAO_NETWORKPRIORITYPOLICY_CH_
  
  class TAO_DiffServPolicy_Export NetworkPriorityPolicy
    : public virtual ::CORBA::Policy
  {
  public:
    typedef NetworkPriorityPolicy_ptr _ptr_type;
    typedef NetworkPriorityPolicy_var _var_type;
    typedef NetworkPriorityPolicy_out _out_type;
    
    // The static operations.
    static NetworkPriorityPolicy_ptr _duplicate (NetworkPriorityPolicy_ptr obj);
    
    static void _tao_release (NetworkPriorityPolicy_ptr obj);
    
    static NetworkPriorityPolicy_ptr _narrow (::CORBA::Object_ptr obj);
    static NetworkPriorityPolicy_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static NetworkPriorityPolicy_ptr _nil (void)
    {
      return static_cast<NetworkPriorityPolicy_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::TAO::NetworkPriorityModel network_priority_model (
        void) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void network_priority_model (
        ::TAO::NetworkPriorityModel network_priority_model) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::TAO::DiffservCodepoint request_diffserv_codepoint (
        void) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void request_diffserv_codepoint (
        ::TAO::DiffservCodepoint request_diffserv_codepoint) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::TAO::DiffservCodepoint reply_diffserv_codepoint (
        void) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void reply_diffserv_codepoint (
        ::TAO::DiffservCodepoint reply_diffserv_codepoint) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Policy_ptr copy (
        void) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void destroy (
        void) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    NetworkPriorityPolicy (void);
    
    virtual ~NetworkPriorityPolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    NetworkPriorityPolicy (const NetworkPriorityPolicy &);
    
    void operator= (const NetworkPriorityPolicy &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

} // module TAO

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:64


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_TAO_NETWORKPRIORITYPOLICY__TRAITS_)
#define _TAO_NETWORKPRIORITYPOLICY__TRAITS_
  
  template<>
  struct TAO_DiffServPolicy_Export Objref_Traits< ::TAO::NetworkPriorityPolicy>
  {
    static ::TAO::NetworkPriorityPolicy_ptr duplicate (
        ::TAO::NetworkPriorityPolicy_ptr p
      );
    static void release (
        ::TAO::NetworkPriorityPolicy_ptr p
      );
    static ::TAO::NetworkPriorityPolicy_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::TAO::NetworkPriorityPolicy_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_enum/cdr_op_ch.cpp:50



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_DiffServPolicy_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, TAO::NetworkPriorityModel _tao_enumerator);
TAO_DiffServPolicy_Export ::CORBA::Boolean operator>> (TAO_InputCDR &strm, TAO::NetworkPriorityModel &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */


