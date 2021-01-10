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

#ifndef _TAO_IDL_LIFECYCLESERVICES_H_
#define _TAO_IDL_LIFECYCLESERVICES_H_

#include /**/ "ace/pre.h"

#include "LifeCycleServiceC.h"
#include "CosLifeCycleS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

#include /**/ "orbsvcs/LifeCycle/lifecycle_skel_export.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_LifeCycle_Skel_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_sh.cpp:49

namespace POA_LifeCycleService
{
  
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class Life_Cycle_Service;
  typedef Life_Cycle_Service *Life_Cycle_Service_ptr;
  
  class TAO_LifeCycle_Skel_Export Life_Cycle_Service
    : public virtual POA_CosLifeCycle::GenericFactory
  {
  protected:
    Life_Cycle_Service (void);
  
  public:
    // Useful for template programming.
    typedef ::LifeCycleService::Life_Cycle_Service _stub_type;
    typedef ::LifeCycleService::Life_Cycle_Service_ptr _stub_ptr_type;
    typedef ::LifeCycleService::Life_Cycle_Service_var _stub_var_type;
    
    Life_Cycle_Service (const Life_Cycle_Service& rhs);
    virtual ~Life_Cycle_Service (void);
    
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
    
    ::LifeCycleService::Life_Cycle_Service *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void register_factory (
        const char * name,
        const char * location,
        const char * description,
        ::CORBA::Object_ptr object) = 0;
    
    static void register_factory_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    supports_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // be\be_interface.cpp:2044
    
    static void
    create_object_skel (
        TAO_ServerRequest & server_request, 
        void * servant_upcall,
        void * servant
      );
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class Criteria_Evaluator;
  typedef Criteria_Evaluator *Criteria_Evaluator_ptr;
  
  class TAO_LifeCycle_Skel_Export Criteria_Evaluator
    : public virtual PortableServer::ServantBase
  {
  protected:
    Criteria_Evaluator (void);
  
  public:
    // Useful for template programming.
    typedef ::LifeCycleService::Criteria_Evaluator _stub_type;
    typedef ::LifeCycleService::Criteria_Evaluator_ptr _stub_ptr_type;
    typedef ::LifeCycleService::Criteria_Evaluator_var _stub_var_type;
    
    Criteria_Evaluator (const Criteria_Evaluator& rhs);
    virtual ~Criteria_Evaluator (void);
    
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
    
    ::LifeCycleService::Criteria_Evaluator *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::LifeCycleService::Criteria_Evaluator::SeqNamedValuePair * getInitialization (
        void) = 0;
    
    static void getInitialization_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual char * getFilter (
        void) = 0;
    
    static void getFilter_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::LifeCycleService::Criteria_Evaluator::SeqNamedValuePair * getLogicalLocation (
        void) = 0;
    
    static void getLogicalLocation_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual char * getPreferences (
        void) = 0;
    
    static void getPreferences_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void setCriteria (
        const ::LifeCycleService::Criteria_Evaluator::Criteria & criteria_) = 0;
    
    static void setCriteria_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
  };

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_sh.cpp:80

} // module LifeCycleService

// TAO_IDL - Generated from 
// be\be_codegen.cpp:1290



TAO_END_VERSIONED_NAMESPACE_DECL


#if defined (__ACE_INLINE__)
#include "LifeCycleServiceS.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"
#endif /* ifndef */

