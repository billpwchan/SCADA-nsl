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

#ifndef _TAO_IDL_DSEVENTLOGADMINS_H_
#define _TAO_IDL_DSEVENTLOGADMINS_H_

#include /**/ "ace/pre.h"

#include "DsEventLogAdminC.h"
#include "CosEventChannelAdminS.h"
#include "DsLogAdminS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

#include /**/ "orbsvcs/Log/eventlog_skel_export.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_EventLog_Skel_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_sh.cpp:49

namespace POA_DsEventLogAdmin
{
  
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class EventLog;
  typedef EventLog *EventLog_ptr;
  
  class TAO_EventLog_Skel_Export EventLog
    : public virtual POA_DsLogAdmin::Log,
      public virtual POA_CosEventChannelAdmin::EventChannel
  {
  protected:
    EventLog (void);
  
  public:
    // Useful for template programming.
    typedef ::DsEventLogAdmin::EventLog _stub_type;
    typedef ::DsEventLogAdmin::EventLog_ptr _stub_ptr_type;
    typedef ::DsEventLogAdmin::EventLog_var _stub_var_type;
    
    EventLog (const EventLog& rhs);
    virtual ~EventLog (void);
    
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
    
    ::DsEventLogAdmin::EventLog *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    my_factory_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    id_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_log_qos_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    set_log_qos_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_max_record_life_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    set_max_record_life_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_max_size_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    set_max_size_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_current_size_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_n_records_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_log_full_action_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    set_log_full_action_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_administrative_state_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    set_administrative_state_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_forwarding_state_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    set_forwarding_state_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_operational_state_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_interval_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    set_interval_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_availability_status_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_capacity_alarm_thresholds_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    set_capacity_alarm_thresholds_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_week_mask_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    set_week_mask_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    query_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    retrieve_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    match_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    delete_records_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    delete_records_by_id_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    write_records_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    write_recordlist_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    set_record_attribute_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    set_records_attribute_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    get_record_attribute_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    copy_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    copy_with_id_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    flush_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    for_consumers_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    for_suppliers_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    destroy_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class EventLogFactory;
  typedef EventLogFactory *EventLogFactory_ptr;
  
  class TAO_EventLog_Skel_Export EventLogFactory
    : public virtual POA_DsLogAdmin::LogMgr,
      public virtual POA_CosEventChannelAdmin::ConsumerAdmin
  {
  protected:
    EventLogFactory (void);
  
  public:
    // Useful for template programming.
    typedef ::DsEventLogAdmin::EventLogFactory _stub_type;
    typedef ::DsEventLogAdmin::EventLogFactory_ptr _stub_ptr_type;
    typedef ::DsEventLogAdmin::EventLogFactory_var _stub_var_type;
    
    EventLogFactory (const EventLogFactory& rhs);
    virtual ~EventLogFactory (void);
    
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
    
    ::DsEventLogAdmin::EventLogFactory *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::DsEventLogAdmin::EventLog_ptr create (
        ::DsLogAdmin::LogFullActionType full_action,
        ::CORBA::ULongLong max_size,
        const ::DsLogAdmin::CapacityAlarmThresholdList & thresholds,
        ::DsLogAdmin::LogId_out id) = 0;
    
    static void create_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::DsEventLogAdmin::EventLog_ptr create_with_id (
        ::DsLogAdmin::LogId id,
        ::DsLogAdmin::LogFullActionType full_action,
        ::CORBA::ULongLong max_size,
        const ::DsLogAdmin::CapacityAlarmThresholdList & thresholds) = 0;
    
    static void create_with_id_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    list_logs_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    find_log_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    list_logs_by_id_skel (
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
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_sh.cpp:80

} // module DsEventLogAdmin

// TAO_IDL - Generated from 
// be\be_codegen.cpp:1290



TAO_END_VERSIONED_NAMESPACE_DECL


#if defined (__ACE_INLINE__)
#include "DsEventLogAdminS.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"
#endif /* ifndef */

