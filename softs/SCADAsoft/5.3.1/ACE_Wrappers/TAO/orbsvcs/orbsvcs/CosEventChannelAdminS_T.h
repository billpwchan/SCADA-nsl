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
// be\be_codegen.cpp:645

#ifndef _TAO_IDL_COSEVENTCHANNELADMINS_T_H_
#define _TAO_IDL_COSEVENTCHANNELADMINS_T_H_

#include /**/ "ace/pre.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from 
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_root/root_sth.cpp:116

namespace POA_CosEventChannelAdmin
{
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:87
  
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  ProxyPushConsumer_tie : public ProxyPushConsumer
  {
  public:
    /// the T& ctor
    ProxyPushConsumer_tie (T &t);
    /// ctor taking a POA
    ProxyPushConsumer_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    ProxyPushConsumer_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    ProxyPushConsumer_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor
    
    ~ProxyPushConsumer_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership
    
    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    void push (
        const ::CORBA::Any &);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    void disconnect_push_consumer (
        void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    void connect_push_supplier (
        ::CosEventComm::PushSupplier_ptr);
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;
    
    // copy and assignment are not allowed
    ProxyPushConsumer_tie (const ProxyPushConsumer_tie &);
    void operator= (const ProxyPushConsumer_tie &);
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:87
  
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  ProxyPushSupplier_tie : public ProxyPushSupplier
  {
  public:
    /// the T& ctor
    ProxyPushSupplier_tie (T &t);
    /// ctor taking a POA
    ProxyPushSupplier_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    ProxyPushSupplier_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    ProxyPushSupplier_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor
    
    ~ProxyPushSupplier_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership
    
    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    void disconnect_push_supplier (
        void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    void connect_push_consumer (
        ::CosEventComm::PushConsumer_ptr);
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;
    
    // copy and assignment are not allowed
    ProxyPushSupplier_tie (const ProxyPushSupplier_tie &);
    void operator= (const ProxyPushSupplier_tie &);
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:87
  
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  ProxyPullSupplier_tie : public ProxyPullSupplier
  {
  public:
    /// the T& ctor
    ProxyPullSupplier_tie (T &t);
    /// ctor taking a POA
    ProxyPullSupplier_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    ProxyPullSupplier_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    ProxyPullSupplier_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor
    
    ~ProxyPullSupplier_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership
    
    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    ::CORBA::Any * pull (
        void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    ::CORBA::Any * try_pull (
        ::CORBA::Boolean_out);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    void disconnect_pull_supplier (
        void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    void connect_pull_consumer (
        ::CosEventComm::PullConsumer_ptr);
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;
    
    // copy and assignment are not allowed
    ProxyPullSupplier_tie (const ProxyPullSupplier_tie &);
    void operator= (const ProxyPullSupplier_tie &);
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:87
  
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  ProxyPullConsumer_tie : public ProxyPullConsumer
  {
  public:
    /// the T& ctor
    ProxyPullConsumer_tie (T &t);
    /// ctor taking a POA
    ProxyPullConsumer_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    ProxyPullConsumer_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    ProxyPullConsumer_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor
    
    ~ProxyPullConsumer_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership
    
    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    void disconnect_pull_consumer (
        void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    void connect_pull_supplier (
        ::CosEventComm::PullSupplier_ptr);
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;
    
    // copy and assignment are not allowed
    ProxyPullConsumer_tie (const ProxyPullConsumer_tie &);
    void operator= (const ProxyPullConsumer_tie &);
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:87
  
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  ConsumerAdmin_tie : public ConsumerAdmin
  {
  public:
    /// the T& ctor
    ConsumerAdmin_tie (T &t);
    /// ctor taking a POA
    ConsumerAdmin_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    ConsumerAdmin_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    ConsumerAdmin_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor
    
    ~ConsumerAdmin_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership
    
    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    ::CosEventChannelAdmin::ProxyPushSupplier_ptr obtain_push_supplier (
        void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    ::CosEventChannelAdmin::ProxyPullSupplier_ptr obtain_pull_supplier (
        void);
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;
    
    // copy and assignment are not allowed
    ConsumerAdmin_tie (const ConsumerAdmin_tie &);
    void operator= (const ConsumerAdmin_tie &);
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:87
  
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  SupplierAdmin_tie : public SupplierAdmin
  {
  public:
    /// the T& ctor
    SupplierAdmin_tie (T &t);
    /// ctor taking a POA
    SupplierAdmin_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    SupplierAdmin_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    SupplierAdmin_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor
    
    ~SupplierAdmin_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership
    
    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    ::CosEventChannelAdmin::ProxyPushConsumer_ptr obtain_push_consumer (
        void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    ::CosEventChannelAdmin::ProxyPullConsumer_ptr obtain_pull_consumer (
        void);
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;
    
    // copy and assignment are not allowed
    SupplierAdmin_tie (const SupplierAdmin_tie &);
    void operator= (const SupplierAdmin_tie &);
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:87
  
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  EventChannel_tie : public EventChannel
  {
  public:
    /// the T& ctor
    EventChannel_tie (T &t);
    /// ctor taking a POA
    EventChannel_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    EventChannel_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    EventChannel_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor
    
    ~EventChannel_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership
    
    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    ::CosEventChannelAdmin::ConsumerAdmin_ptr for_consumers (
        void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    ::CosEventChannelAdmin::SupplierAdmin_ptr for_suppliers (
        void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
    
    void destroy (
        void);
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;
    
    // copy and assignment are not allowed
    EventChannel_tie (const EventChannel_tie &);
    void operator= (const EventChannel_tie &);
  };
} // module CosEventChannelAdmin

// TAO_IDL - Generated from 
// be\be_codegen.cpp:1391


TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "CosEventChannelAdminS_T.cpp"
#endif /* defined REQUIRED SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("CosEventChannelAdminS_T.cpp")
#endif /* defined REQUIRED PRAGMA */

#include /**/ "ace/post.h"
#endif /* ifndef */

