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

#ifndef _TAO_IDL_EVENT_FORWARDERC_H_
#define _TAO_IDL_EVENT_FORWARDERC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "orbsvcs/Notify/notify_export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/ORB.h"
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

#include "CosNotificationC.h"
#include "CosNotifyChannelAdminC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Notify_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from 
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_root/root_ch.cpp:62

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  class Collocation_Proxy_Broker;
  template<typename T> class Narrow_Utils;
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace Event_Forwarder
{
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:644

#if !defined (_EVENT_FORWARDER_STRUCTUREDPROXYPUSHSUPPLIER__VAR_OUT_CH_)
#define _EVENT_FORWARDER_STRUCTUREDPROXYPUSHSUPPLIER__VAR_OUT_CH_
  
  class StructuredProxyPushSupplier;
  typedef StructuredProxyPushSupplier *StructuredProxyPushSupplier_ptr;
  
  typedef
    TAO_Objref_Var_T<
        StructuredProxyPushSupplier
      >
    StructuredProxyPushSupplier_var;
  
  typedef
    TAO_Objref_Out_T<
        StructuredProxyPushSupplier
      >
    StructuredProxyPushSupplier_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_EVENT_FORWARDER_STRUCTUREDPROXYPUSHSUPPLIER_CH_)
#define _EVENT_FORWARDER_STRUCTUREDPROXYPUSHSUPPLIER_CH_
  
  class TAO_Notify_Export StructuredProxyPushSupplier
    : public virtual ::CosNotifyChannelAdmin::StructuredProxyPushSupplier
  {
  public:
    friend class TAO::Narrow_Utils<StructuredProxyPushSupplier>;
    typedef StructuredProxyPushSupplier_ptr _ptr_type;
    typedef StructuredProxyPushSupplier_var _var_type;
    typedef StructuredProxyPushSupplier_out _out_type;
    
    // The static operations.
    static StructuredProxyPushSupplier_ptr _duplicate (StructuredProxyPushSupplier_ptr obj);
    
    static void _tao_release (StructuredProxyPushSupplier_ptr obj);
    
    static StructuredProxyPushSupplier_ptr _narrow (::CORBA::Object_ptr obj);
    static StructuredProxyPushSupplier_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static StructuredProxyPushSupplier_ptr _nil (void)
    {
      return static_cast<StructuredProxyPushSupplier_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void forward_structured (
        const ::CosNotification::StructuredEvent & event);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void forward_structured_no_filtering (
        const ::CosNotification::StructuredEvent & event);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void forward_any (
        const ::CORBA::Any & event);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void forward_any_no_filtering (
        const ::CORBA::Any & event);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_StructuredProxyPushSupplier_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    StructuredProxyPushSupplier (void);
    
    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void Event_Forwarder_StructuredProxyPushSupplier_setup_collocation (void);
    
    // Concrete non-local interface only.
    StructuredProxyPushSupplier (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    StructuredProxyPushSupplier (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);
    
    virtual ~StructuredProxyPushSupplier (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    StructuredProxyPushSupplier (const StructuredProxyPushSupplier &);
    
    void operator= (const StructuredProxyPushSupplier &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Notify_Export ::CORBA::TypeCode_ptr const _tc_StructuredProxyPushSupplier;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:644

#if !defined (_EVENT_FORWARDER_PROXYPUSHSUPPLIER__VAR_OUT_CH_)
#define _EVENT_FORWARDER_PROXYPUSHSUPPLIER__VAR_OUT_CH_
  
  class ProxyPushSupplier;
  typedef ProxyPushSupplier *ProxyPushSupplier_ptr;
  
  typedef
    TAO_Objref_Var_T<
        ProxyPushSupplier
      >
    ProxyPushSupplier_var;
  
  typedef
    TAO_Objref_Out_T<
        ProxyPushSupplier
      >
    ProxyPushSupplier_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_EVENT_FORWARDER_PROXYPUSHSUPPLIER_CH_)
#define _EVENT_FORWARDER_PROXYPUSHSUPPLIER_CH_
  
  class TAO_Notify_Export ProxyPushSupplier
    : public virtual ::CosNotifyChannelAdmin::ProxyPushSupplier
  {
  public:
    friend class TAO::Narrow_Utils<ProxyPushSupplier>;
    typedef ProxyPushSupplier_ptr _ptr_type;
    typedef ProxyPushSupplier_var _var_type;
    typedef ProxyPushSupplier_out _out_type;
    
    // The static operations.
    static ProxyPushSupplier_ptr _duplicate (ProxyPushSupplier_ptr obj);
    
    static void _tao_release (ProxyPushSupplier_ptr obj);
    
    static ProxyPushSupplier_ptr _narrow (::CORBA::Object_ptr obj);
    static ProxyPushSupplier_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static ProxyPushSupplier_ptr _nil (void)
    {
      return static_cast<ProxyPushSupplier_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void forward_structured (
        const ::CosNotification::StructuredEvent & event);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void forward_structured_no_filtering (
        const ::CosNotification::StructuredEvent & event);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void forward_any (
        const ::CORBA::Any & event);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void forward_any_no_filtering (
        const ::CORBA::Any & event);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_ProxyPushSupplier_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    ProxyPushSupplier (void);
    
    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void Event_Forwarder_ProxyPushSupplier_setup_collocation (void);
    
    // Concrete non-local interface only.
    ProxyPushSupplier (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    ProxyPushSupplier (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);
    
    virtual ~ProxyPushSupplier (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ProxyPushSupplier (const ProxyPushSupplier &);
    
    void operator= (const ProxyPushSupplier &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Notify_Export ::CORBA::TypeCode_ptr const _tc_ProxyPushSupplier;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

} // module Event_Forwarder

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_root/root.cpp:139

extern TAO_Notify_Export
TAO::Collocation_Proxy_Broker *
(*Event_Forwarder__TAO_StructuredProxyPushSupplier_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj
  );

extern TAO_Notify_Export
TAO::Collocation_Proxy_Broker *
(*Event_Forwarder__TAO_ProxyPushSupplier_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:64


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_EVENT_FORWARDER_STRUCTUREDPROXYPUSHSUPPLIER__TRAITS_)
#define _EVENT_FORWARDER_STRUCTUREDPROXYPUSHSUPPLIER__TRAITS_
  
  template<>
  struct TAO_Notify_Export Objref_Traits< ::Event_Forwarder::StructuredProxyPushSupplier>
  {
    static ::Event_Forwarder::StructuredProxyPushSupplier_ptr duplicate (
        ::Event_Forwarder::StructuredProxyPushSupplier_ptr p
      );
    static void release (
        ::Event_Forwarder::StructuredProxyPushSupplier_ptr p
      );
    static ::Event_Forwarder::StructuredProxyPushSupplier_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::Event_Forwarder::StructuredProxyPushSupplier_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_EVENT_FORWARDER_PROXYPUSHSUPPLIER__TRAITS_)
#define _EVENT_FORWARDER_PROXYPUSHSUPPLIER__TRAITS_
  
  template<>
  struct TAO_Notify_Export Objref_Traits< ::Event_Forwarder::ProxyPushSupplier>
  {
    static ::Event_Forwarder::ProxyPushSupplier_ptr duplicate (
        ::Event_Forwarder::ProxyPushSupplier_ptr p
      );
    static void release (
        ::Event_Forwarder::ProxyPushSupplier_ptr p
      );
    static ::Event_Forwarder::ProxyPushSupplier_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::Event_Forwarder::ProxyPushSupplier_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:54



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace Event_Forwarder
{
  TAO_Notify_Export void operator<<= ( ::CORBA::Any &, StructuredProxyPushSupplier_ptr); // copying
  TAO_Notify_Export void operator<<= ( ::CORBA::Any &, StructuredProxyPushSupplier_ptr *); // non-copying
  TAO_Notify_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, StructuredProxyPushSupplier_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Notify_Export void operator<<= (::CORBA::Any &, Event_Forwarder::StructuredProxyPushSupplier_ptr); // copying
TAO_Notify_Export void operator<<= (::CORBA::Any &, Event_Forwarder::StructuredProxyPushSupplier_ptr *); // non-copying
TAO_Notify_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Event_Forwarder::StructuredProxyPushSupplier_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:54



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace Event_Forwarder
{
  TAO_Notify_Export void operator<<= ( ::CORBA::Any &, ProxyPushSupplier_ptr); // copying
  TAO_Notify_Export void operator<<= ( ::CORBA::Any &, ProxyPushSupplier_ptr *); // non-copying
  TAO_Notify_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ProxyPushSupplier_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Notify_Export void operator<<= (::CORBA::Any &, Event_Forwarder::ProxyPushSupplier_ptr); // copying
TAO_Notify_Export void operator<<= (::CORBA::Any &, Event_Forwarder::ProxyPushSupplier_ptr *); // non-copying
TAO_Notify_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Event_Forwarder::ProxyPushSupplier_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:55


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Notify_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const Event_Forwarder::StructuredProxyPushSupplier_ptr );
TAO_Notify_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, Event_Forwarder::StructuredProxyPushSupplier_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:55


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Notify_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const Event_Forwarder::ProxyPushSupplier_ptr );
TAO_Notify_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, Event_Forwarder::ProxyPushSupplier_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "Event_ForwarderC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */


