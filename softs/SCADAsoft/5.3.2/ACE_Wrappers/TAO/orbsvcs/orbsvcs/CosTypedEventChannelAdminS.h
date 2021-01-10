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
// be\be_codegen.cpp:487

#ifndef _TAO_IDL_COSTYPEDEVENTCHANNELADMINS_H_
#define _TAO_IDL_COSTYPEDEVENTCHANNELADMINS_H_

#include /**/ "ace/pre.h"

#include "CosTypedEventChannelAdminC.h"
#include "CosEventChannelAdminS.h"
#include "CosTypedEventCommS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

#include /**/ "orbsvcs/CosEvent/event_skel_export.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Event_Skel_Export

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_sh.cpp:49

namespace POA_CosTypedEventChannelAdmin
{
  
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class TypedProxyPushConsumer;
  typedef TypedProxyPushConsumer *TypedProxyPushConsumer_ptr;
  
  class TAO_Event_Skel_Export TypedProxyPushConsumer
    : public virtual POA_CosEventChannelAdmin::ProxyPushConsumer,
      public virtual POA_CosTypedEventComm::TypedPushConsumer
  {
  protected:
    TypedProxyPushConsumer (void);
  
  public:
    // Useful for template programming.
    typedef ::CosTypedEventChannelAdmin::TypedProxyPushConsumer _stub_type;
    typedef ::CosTypedEventChannelAdmin::TypedProxyPushConsumer_ptr _stub_ptr_type;
    typedef ::CosTypedEventChannelAdmin::TypedProxyPushConsumer_var _stub_var_type;
    
    TypedProxyPushConsumer (const TypedProxyPushConsumer& rhs);
    virtual ~TypedProxyPushConsumer (void);
    
    virtual ::CORBA::Boolean _is_a (const char* logical_type_id);
    
    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _repository_id_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall);
    
    ::CosTypedEventChannelAdmin::TypedProxyPushConsumer *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    push_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    disconnect_push_consumer_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    connect_push_supplier_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_typed_consumer_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class TypedProxyPullSupplier;
  typedef TypedProxyPullSupplier *TypedProxyPullSupplier_ptr;
  
  class TAO_Event_Skel_Export TypedProxyPullSupplier
    : public virtual POA_CosEventChannelAdmin::ProxyPullSupplier,
      public virtual POA_CosTypedEventComm::TypedPullSupplier
  {
  protected:
    TypedProxyPullSupplier (void);
  
  public:
    // Useful for template programming.
    typedef ::CosTypedEventChannelAdmin::TypedProxyPullSupplier _stub_type;
    typedef ::CosTypedEventChannelAdmin::TypedProxyPullSupplier_ptr _stub_ptr_type;
    typedef ::CosTypedEventChannelAdmin::TypedProxyPullSupplier_var _stub_var_type;
    
    TypedProxyPullSupplier (const TypedProxyPullSupplier& rhs);
    virtual ~TypedProxyPullSupplier (void);
    
    virtual ::CORBA::Boolean _is_a (const char* logical_type_id);
    
    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _repository_id_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall);
    
    ::CosTypedEventChannelAdmin::TypedProxyPullSupplier *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    pull_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    try_pull_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    disconnect_pull_supplier_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    connect_pull_consumer_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_typed_supplier_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class TypedSupplierAdmin;
  typedef TypedSupplierAdmin *TypedSupplierAdmin_ptr;
  
  class TAO_Event_Skel_Export TypedSupplierAdmin
    : public virtual POA_CosEventChannelAdmin::SupplierAdmin
  {
  protected:
    TypedSupplierAdmin (void);
  
  public:
    // Useful for template programming.
    typedef ::CosTypedEventChannelAdmin::TypedSupplierAdmin _stub_type;
    typedef ::CosTypedEventChannelAdmin::TypedSupplierAdmin_ptr _stub_ptr_type;
    typedef ::CosTypedEventChannelAdmin::TypedSupplierAdmin_var _stub_var_type;
    
    TypedSupplierAdmin (const TypedSupplierAdmin& rhs);
    virtual ~TypedSupplierAdmin (void);
    
    virtual ::CORBA::Boolean _is_a (const char* logical_type_id);
    
    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _repository_id_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall);
    
    ::CosTypedEventChannelAdmin::TypedSupplierAdmin *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::CosTypedEventChannelAdmin::TypedProxyPushConsumer_ptr obtain_typed_push_consumer (
        const char * supported_interface) = 0;
    
    static void obtain_typed_push_consumer_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::CosEventChannelAdmin::ProxyPullConsumer_ptr obtain_typed_pull_consumer (
        const char * uses_interface) = 0;
    
    static void obtain_typed_pull_consumer_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    obtain_push_consumer_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    obtain_pull_consumer_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class TypedConsumerAdmin;
  typedef TypedConsumerAdmin *TypedConsumerAdmin_ptr;
  
  class TAO_Event_Skel_Export TypedConsumerAdmin
    : public virtual POA_CosEventChannelAdmin::ConsumerAdmin
  {
  protected:
    TypedConsumerAdmin (void);
  
  public:
    // Useful for template programming.
    typedef ::CosTypedEventChannelAdmin::TypedConsumerAdmin _stub_type;
    typedef ::CosTypedEventChannelAdmin::TypedConsumerAdmin_ptr _stub_ptr_type;
    typedef ::CosTypedEventChannelAdmin::TypedConsumerAdmin_var _stub_var_type;
    
    TypedConsumerAdmin (const TypedConsumerAdmin& rhs);
    virtual ~TypedConsumerAdmin (void);
    
    virtual ::CORBA::Boolean _is_a (const char* logical_type_id);
    
    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _repository_id_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall);
    
    ::CosTypedEventChannelAdmin::TypedConsumerAdmin *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::CosTypedEventChannelAdmin::TypedProxyPullSupplier_ptr obtain_typed_pull_supplier (
        const char * supported_interface) = 0;
    
    static void obtain_typed_pull_supplier_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::CosEventChannelAdmin::ProxyPushSupplier_ptr obtain_typed_push_supplier (
        const char * uses_interface) = 0;
    
    static void obtain_typed_push_supplier_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    obtain_push_supplier_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    obtain_pull_supplier_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class TypedEventChannel;
  typedef TypedEventChannel *TypedEventChannel_ptr;
  
  class TAO_Event_Skel_Export TypedEventChannel
    : public virtual PortableServer::ServantBase
  {
  protected:
    TypedEventChannel (void);
  
  public:
    // Useful for template programming.
    typedef ::CosTypedEventChannelAdmin::TypedEventChannel _stub_type;
    typedef ::CosTypedEventChannelAdmin::TypedEventChannel_ptr _stub_ptr_type;
    typedef ::CosTypedEventChannelAdmin::TypedEventChannel_var _stub_var_type;
    
    TypedEventChannel (const TypedEventChannel& rhs);
    virtual ~TypedEventChannel (void);
    
    virtual ::CORBA::Boolean _is_a (const char* logical_type_id);
    
    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant
      );
    
    static void _repository_id_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall);
    
    ::CosTypedEventChannelAdmin::TypedEventChannel *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::CosTypedEventChannelAdmin::TypedConsumerAdmin_ptr for_consumers (
        void) = 0;
    
    static void for_consumers_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::CosTypedEventChannelAdmin::TypedSupplierAdmin_ptr for_suppliers (
        void) = 0;
    
    static void for_suppliers_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void destroy (
        void) = 0;
    
    static void destroy_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
  };

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_sh.cpp:80

} // module CosTypedEventChannelAdmin

// TAO_IDL - Generated from 
// be\be_codegen.cpp:1290

#include "CosTypedEventChannelAdminS_T.h"

#if defined (__ACE_INLINE__)
#include "CosTypedEventChannelAdminS.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"
#endif /* ifndef */

