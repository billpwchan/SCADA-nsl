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

#ifndef _TAO_PIDL_PI_SERVER_SERVERREQUESTINFOC_H_
#define _TAO_PIDL_PI_SERVER_SERVERREQUESTINFOC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/PI_Server/pi_server_export.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/String_Manager_T.h"
#include "tao/Objref_VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/PI/PI_includeC.h"
#include "tao/Policy_ForwardC.h"
#include "tao/orb_typesC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PI_Server_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace PortableInterceptor
{
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:644

#if !defined (_PORTABLEINTERCEPTOR_SERVERREQUESTINFO__VAR_OUT_CH_)
#define _PORTABLEINTERCEPTOR_SERVERREQUESTINFO__VAR_OUT_CH_
  
  class ServerRequestInfo;
  typedef ServerRequestInfo *ServerRequestInfo_ptr;
  
  typedef
    TAO_Objref_Var_T<
        ServerRequestInfo
      >
    ServerRequestInfo_var;
  
  typedef
    TAO_Objref_Out_T<
        ServerRequestInfo
      >
    ServerRequestInfo_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLEINTERCEPTOR_SERVERREQUESTINFO_CH_)
#define _PORTABLEINTERCEPTOR_SERVERREQUESTINFO_CH_
  
  class TAO_PI_Server_Export ServerRequestInfo
    : public virtual ::PortableInterceptor::RequestInfo
  {
  public:
    typedef ServerRequestInfo_ptr _ptr_type;
    typedef ServerRequestInfo_var _var_type;
    typedef ServerRequestInfo_out _out_type;
    
    // The static operations.
    static ServerRequestInfo_ptr _duplicate (ServerRequestInfo_ptr obj);
    
    static void _tao_release (ServerRequestInfo_ptr obj);
    
    static ServerRequestInfo_ptr _narrow (::CORBA::Object_ptr obj);
    static ServerRequestInfo_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static ServerRequestInfo_ptr _nil (void)
    {
      return static_cast<ServerRequestInfo_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Any * sending_exception (
        void) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual char * server_id (
        void) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual char * orb_id (
        void) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableInterceptor::AdapterName * adapter_name (
        void) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableInterceptor::ObjectId * object_id (
        void) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::OctetSeq * adapter_id (
        void) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual char * target_most_derived_interface (
        void) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Policy_ptr get_server_policy (
        ::CORBA::PolicyType type) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void set_slot (
        ::PortableInterceptor::SlotId id,
        const ::CORBA::Any & data) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Boolean target_is_a (
        const char * id) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void add_reply_service_context (
        const ::IOP::ServiceContext & service_context,
        ::CORBA::Boolean replace) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    ServerRequestInfo (void);
    
    virtual ~ServerRequestInfo (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ServerRequestInfo (const ServerRequestInfo &);
    
    void operator= (const ServerRequestInfo &);
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

#if !defined (_PORTABLEINTERCEPTOR_SERVERREQUESTINFO__TRAITS_)
#define _PORTABLEINTERCEPTOR_SERVERREQUESTINFO__TRAITS_
  
  template<>
  struct TAO_PI_Server_Export Objref_Traits< ::PortableInterceptor::ServerRequestInfo>
  {
    static ::PortableInterceptor::ServerRequestInfo_ptr duplicate (
        ::PortableInterceptor::ServerRequestInfo_ptr p
      );
    static void release (
        ::PortableInterceptor::ServerRequestInfo_ptr p
      );
    static ::PortableInterceptor::ServerRequestInfo_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::PortableInterceptor::ServerRequestInfo_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */


