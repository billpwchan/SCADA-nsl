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

#ifndef _TAO_IDL_COSLIFECYCLES_H_
#define _TAO_IDL_COSLIFECYCLES_H_

#include /**/ "ace/pre.h"

#include "CosLifeCycleC.h"
#include "CosNamingS.h"

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

namespace POA_CosLifeCycle
{
  
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class FactoryFinder;
  typedef FactoryFinder *FactoryFinder_ptr;
  
  class TAO_LifeCycle_Skel_Export FactoryFinder
    : public virtual PortableServer::ServantBase
  {
  protected:
    FactoryFinder (void);
  
  public:
    // Useful for template programming.
    typedef ::CosLifeCycle::FactoryFinder _stub_type;
    typedef ::CosLifeCycle::FactoryFinder_ptr _stub_ptr_type;
    typedef ::CosLifeCycle::FactoryFinder_var _stub_var_type;
    
    FactoryFinder (const FactoryFinder& rhs);
    virtual ~FactoryFinder (void);
    
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
    
    ::CosLifeCycle::FactoryFinder *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::CosLifeCycle::Factories * find_factories (
        const ::CosLifeCycle::Key & factory_key) = 0;
    
    static void find_factories_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class LifeCycleObject;
  typedef LifeCycleObject *LifeCycleObject_ptr;
  
  class TAO_LifeCycle_Skel_Export LifeCycleObject
    : public virtual PortableServer::ServantBase
  {
  protected:
    LifeCycleObject (void);
  
  public:
    // Useful for template programming.
    typedef ::CosLifeCycle::LifeCycleObject _stub_type;
    typedef ::CosLifeCycle::LifeCycleObject_ptr _stub_ptr_type;
    typedef ::CosLifeCycle::LifeCycleObject_var _stub_var_type;
    
    LifeCycleObject (const LifeCycleObject& rhs);
    virtual ~LifeCycleObject (void);
    
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
    
    ::CosLifeCycle::LifeCycleObject *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::CosLifeCycle::LifeCycleObject_ptr copy (
        ::CosLifeCycle::FactoryFinder_ptr there,
        const ::CosLifeCycle::Criteria & the_criteria) = 0;
    
    static void copy_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void move (
        ::CosLifeCycle::FactoryFinder_ptr there,
        const ::CosLifeCycle::Criteria & the_criteria) = 0;
    
    static void move_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void remove (
        void) = 0;
    
    static void remove_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class GenericFactory;
  typedef GenericFactory *GenericFactory_ptr;
  
  class TAO_LifeCycle_Skel_Export GenericFactory
    : public virtual PortableServer::ServantBase
  {
  protected:
    GenericFactory (void);
  
  public:
    // Useful for template programming.
    typedef ::CosLifeCycle::GenericFactory _stub_type;
    typedef ::CosLifeCycle::GenericFactory_ptr _stub_ptr_type;
    typedef ::CosLifeCycle::GenericFactory_var _stub_var_type;
    
    GenericFactory (const GenericFactory& rhs);
    virtual ~GenericFactory (void);
    
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
    
    ::CosLifeCycle::GenericFactory *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::CORBA::Boolean supports (
        const ::CosLifeCycle::Key & k) = 0;
    
    static void supports_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::CORBA::Object_ptr create_object (
        const ::CosLifeCycle::Key & k,
        const ::CosLifeCycle::Criteria & the_criteria) = 0;
    
    static void create_object_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
  };

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_sh.cpp:80

} // module CosLifeCycle

// TAO_IDL - Generated from 
// be\be_codegen.cpp:1290



TAO_END_VERSIONED_NAMESPACE_DECL


#if defined (__ACE_INLINE__)
#include "CosLifeCycleS.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"
#endif /* ifndef */
