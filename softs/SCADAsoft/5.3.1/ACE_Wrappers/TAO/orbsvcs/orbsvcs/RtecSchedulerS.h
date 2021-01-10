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

#ifndef _TAO_IDL_RTECSCHEDULERS_H_
#define _TAO_IDL_RTECSCHEDULERS_H_

#include /**/ "ace/pre.h"

#include "RtecSchedulerC.h"
#include "TimeBaseS.h"
#include "RtecBaseS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_sh.cpp:49

namespace POA_RtecScheduler
{
  
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class Scheduler;
  typedef Scheduler *Scheduler_ptr;
  
  class TAO_RTSched_Export Scheduler
    : public virtual PortableServer::ServantBase
  {
  protected:
    Scheduler (void);
  
  public:
    // Useful for template programming.
    typedef ::RtecScheduler::Scheduler _stub_type;
    typedef ::RtecScheduler::Scheduler_ptr _stub_ptr_type;
    typedef ::RtecScheduler::Scheduler_var _stub_var_type;
    
    Scheduler (const Scheduler& rhs);
    virtual ~Scheduler (void);
    
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
    
    ::RtecScheduler::Scheduler *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::RtecScheduler::handle_t create (
        const char * entry_point) = 0;
    
    static void create_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::RtecScheduler::handle_t lookup (
        const char * entry_point) = 0;
    
    static void lookup_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::RtecScheduler::RT_Info * get (
        ::RtecScheduler::handle_t handle) = 0;
    
    static void get_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void set (
        ::RtecScheduler::handle_t handle,
        ::RtecScheduler::Criticality_t criticality,
        ::RtecScheduler::Time wc_time,
        ::RtecScheduler::Time typical_time,
        ::RtecScheduler::Time cached_time,
        ::RtecScheduler::Period_t period,
        ::RtecScheduler::Importance_t importance,
        ::RtecScheduler::Quantum_t quantum,
        ::RtecScheduler::Threads_t threads,
        ::RtecScheduler::Info_Type_t info_type) = 0;
    
    static void set_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void reset (
        ::RtecScheduler::handle_t handle,
        ::RtecScheduler::Criticality_t criticality,
        ::RtecScheduler::Time wc_time,
        ::RtecScheduler::Time typical_time,
        ::RtecScheduler::Time cached_time,
        ::RtecScheduler::Period_t period,
        ::RtecScheduler::Importance_t importance,
        ::RtecScheduler::Quantum_t quantum,
        ::RtecScheduler::Threads_t threads,
        ::RtecScheduler::Info_Type_t info_type) = 0;
    
    static void reset_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void set_seq (
        const ::RtecScheduler::RT_Info_Set & infos) = 0;
    
    static void set_seq_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void reset_seq (
        const ::RtecScheduler::RT_Info_Set & infos) = 0;
    
    static void reset_seq_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void replace_seq (
        const ::RtecScheduler::RT_Info_Set & infos) = 0;
    
    static void replace_seq_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void add_dependency (
        ::RtecScheduler::handle_t handle,
        ::RtecScheduler::handle_t dependency,
        ::CORBA::Long number_of_calls,
        ::RtecScheduler::Dependency_Type_t dependency_type) = 0;
    
    static void add_dependency_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void remove_dependency (
        ::RtecScheduler::handle_t handle,
        ::RtecScheduler::handle_t dependency,
        ::CORBA::Long number_of_calls,
        ::RtecScheduler::Dependency_Type_t dependency_type) = 0;
    
    static void remove_dependency_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void set_dependency_enable_state (
        ::RtecScheduler::handle_t handle,
        ::RtecScheduler::handle_t dependency,
        ::CORBA::Long number_of_calls,
        ::RtecScheduler::Dependency_Type_t dependency_type,
        ::RtecScheduler::Dependency_Enabled_Type_t enabled) = 0;
    
    static void set_dependency_enable_state_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void set_dependency_enable_state_seq (
        const ::RtecScheduler::Dependency_Set & dependencies) = 0;
    
    static void set_dependency_enable_state_seq_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void set_rt_info_enable_state (
        ::RtecScheduler::handle_t handle,
        ::RtecScheduler::RT_Info_Enabled_Type_t enabled) = 0;
    
    static void set_rt_info_enable_state_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void set_rt_info_enable_state_seq (
        const ::RtecScheduler::RT_Info_Enable_State_Pair_Set & pair_set) = 0;
    
    static void set_rt_info_enable_state_seq_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void priority (
        ::RtecScheduler::handle_t handle,
        ::RtecScheduler::OS_Priority_out o_priority,
        ::RtecScheduler::Preemption_Subpriority_t_out p_subpriority,
        ::RtecScheduler::Preemption_Priority_t_out p_priority) = 0;
    
    static void priority_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void entry_point_priority (
        const char * entry_point,
        ::RtecScheduler::OS_Priority_out o_priority,
        ::RtecScheduler::Preemption_Subpriority_t_out p_subpriority,
        ::RtecScheduler::Preemption_Priority_t_out p_priority) = 0;
    
    static void entry_point_priority_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void compute_scheduling (
        ::CORBA::Long minimum_priority,
        ::CORBA::Long maximum_priority,
        ::RtecScheduler::RT_Info_Set_out infos,
        ::RtecScheduler::Dependency_Set_out dependencies,
        ::RtecScheduler::Config_Info_Set_out configs,
        ::RtecScheduler::Scheduling_Anomaly_Set_out anomalies) = 0;
    
    static void compute_scheduling_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void recompute_scheduling (
        ::CORBA::Long minimum_priority,
        ::CORBA::Long maximum_priority,
        ::RtecScheduler::Scheduling_Anomaly_Set_out anomalies) = 0;
    
    static void recompute_scheduling_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void get_rt_info_set (
        ::RtecScheduler::RT_Info_Set_out infos) = 0;
    
    static void get_rt_info_set_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void get_dependency_set (
        ::RtecScheduler::Dependency_Set_out dependencies) = 0;
    
    static void get_dependency_set_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void get_config_info_set (
        ::RtecScheduler::Config_Info_Set_out configs) = 0;
    
    static void get_config_info_set_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void dispatch_configuration (
        ::RtecScheduler::Preemption_Priority_t p_priority,
        ::RtecScheduler::OS_Priority_out o_priority,
        ::RtecScheduler::Dispatching_Type_t_out d_type) = 0;
    
    static void dispatch_configuration_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::RtecScheduler::Preemption_Priority_t last_scheduled_priority (
        void) = 0;
    
    static void last_scheduled_priority_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void get_config_infos (
        ::RtecScheduler::Config_Info_Set_out configs) = 0;
    
    static void get_config_infos_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
  };

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_sh.cpp:80

} // module RtecScheduler

// TAO_IDL - Generated from 
// be\be_codegen.cpp:1290



TAO_END_VERSIONED_NAMESPACE_DECL


#if defined (__ACE_INLINE__)
#include "RtecSchedulerS.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"
#endif /* ifndef */

