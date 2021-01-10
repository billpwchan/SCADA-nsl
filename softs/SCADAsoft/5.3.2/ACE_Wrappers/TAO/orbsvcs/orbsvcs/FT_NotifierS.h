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

#ifndef _TAO_IDL_FT_NOTIFIERS_H_
#define _TAO_IDL_FT_NOTIFIERS_H_

#include /**/ "ace/pre.h"

#include "FT_NotifierC.h"
#include "orbsvcs/FT_CORBA_ORBS.h"
#include "orbsvcs/FT_ReplicaS.h"
#include "orbsvcs/CosNamingS.h"
#include "orbsvcs/CosNotificationS.h"
#include "orbsvcs/CosNotifyFilterS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

#include /**/ "tao/PortableServer/PolicyS.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_FT_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_sh.cpp:49

namespace POA_FT
{
  
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class FaultNotifier;
  typedef FaultNotifier *FaultNotifier_ptr;
  
  class TAO_FT_Export FaultNotifier
    : public virtual POA_FT::PullMonitorable
  {
  protected:
    FaultNotifier (void);
  
  public:
    // Useful for template programming.
    typedef ::FT::FaultNotifier _stub_type;
    typedef ::FT::FaultNotifier_ptr _stub_ptr_type;
    typedef ::FT::FaultNotifier_var _stub_var_type;
    
    FaultNotifier (const FaultNotifier& rhs);
    virtual ~FaultNotifier (void);
    
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
    
    ::FT::FaultNotifier *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void push_structured_fault (
        const ::CosNotification::StructuredEvent & event) = 0;
    
    static void push_structured_fault_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void push_sequence_fault (
        const ::CosNotification::EventBatch & events) = 0;
    
    static void push_sequence_fault_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::CosNotifyFilter::Filter_ptr create_subscription_filter (
        const char * constraint_grammar) = 0;
    
    static void create_subscription_filter_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::FT::FaultNotifier::ConsumerId connect_structured_fault_consumer (
        ::CosNotifyComm::StructuredPushConsumer_ptr push_consumer,
        ::CosNotifyFilter::Filter_ptr filter) = 0;
    
    static void connect_structured_fault_consumer_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::FT::FaultNotifier::ConsumerId connect_sequence_fault_consumer (
        ::CosNotifyComm::SequencePushConsumer_ptr push_consumer,
        ::CosNotifyFilter::Filter_ptr filter) = 0;
    
    static void connect_sequence_fault_consumer_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void disconnect_consumer (
        ::FT::FaultNotifier::ConsumerId connection) = 0;
    
    static void disconnect_consumer_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    is_alive_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
  };

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_sh.cpp:80

} // module FT

// TAO_IDL - Generated from 
// be\be_codegen.cpp:1290



TAO_END_VERSIONED_NAMESPACE_DECL


#if defined (__ACE_INLINE__)
#include "FT_NotifierS.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"
#endif /* ifndef */
