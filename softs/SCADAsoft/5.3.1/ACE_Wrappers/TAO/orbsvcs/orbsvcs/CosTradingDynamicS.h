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

#ifndef _TAO_IDL_COSTRADINGDYNAMICS_H_
#define _TAO_IDL_COSTRADINGDYNAMICS_H_

#include /**/ "ace/pre.h"

#include "CosTradingDynamicC.h"
#include "tao/BooleanSeqS.h"
#include "tao/CharSeqS.h"
#include "tao/DoubleSeqS.h"
#include "tao/FloatSeqS.h"
#include "tao/LongDoubleSeqS.h"
#include "tao/LongSeqS.h"
#include "tao/OctetSeqS.h"
#include "tao/ShortSeqS.h"
#include "tao/StringSeqS.h"
#include "tao/ULongSeqS.h"
#include "tao/UShortSeqS.h"
#include "tao/WCharSeqS.h"
#include "tao/WStringSeqS.h"
#include "tao/LongLongSeqS.h"
#include "tao/ULongLongSeqS.h"
#include "tao/PolicyS.h"
#include "tao/Policy_ManagerS.h"
#include "tao/Policy_CurrentS.h"
#include "tao/ServicesS.h"
#include "tao/ParameterModeS.h"
#include "tao/orb_typesS.h"
#include "tao/Typecode_typesS.h"
#include "tao/WrongTransactionS.h"
#include "CosTradingS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

#include /**/ "orbsvcs/Trader/trading_skel_export.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Trading_Skel_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_sh.cpp:49

namespace POA_CosTradingDynamic
{
  
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87
  
  class DynamicPropEval;
  typedef DynamicPropEval *DynamicPropEval_ptr;
  
  class TAO_Trading_Skel_Export DynamicPropEval
    : public virtual PortableServer::ServantBase
  {
  protected:
    DynamicPropEval (void);
  
  public:
    // Useful for template programming.
    typedef ::CosTradingDynamic::DynamicPropEval _stub_type;
    typedef ::CosTradingDynamic::DynamicPropEval_ptr _stub_ptr_type;
    typedef ::CosTradingDynamic::DynamicPropEval_var _stub_var_type;
    
    DynamicPropEval (const DynamicPropEval& rhs);
    virtual ~DynamicPropEval (void);
    
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
    
    ::CosTradingDynamic::DynamicPropEval *_this (void);
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual ::CORBA::Any * evalDP (
        const char * name,
        ::CORBA::TypeCode_ptr returned_type,
        const ::CORBA::Any & extra_info) = 0;
    
    static void evalDP_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant
      );
  };

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_sh.cpp:80

} // module CosTradingDynamic

// TAO_IDL - Generated from 
// be\be_codegen.cpp:1290



TAO_END_VERSIONED_NAMESPACE_DECL


#if defined (__ACE_INLINE__)
#include "CosTradingDynamicS.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"
#endif /* ifndef */

