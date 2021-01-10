// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6a_p15 ****
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

#ifndef _TAO_PIDL_PORTABLESERVER_PS_CURRENTC_H_
#define _TAO_PIDL_PORTABLESERVER_PS_CURRENTC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/PortableServer/portableserver_export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/SystemException.h"
#include "tao/UserException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/PortableServer/PS_ForwardA.h"
#include "tao/AnyTypeCode/CurrentA.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/PortableServer/PS_ForwardC.h"
#include "tao/CurrentC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PortableServer_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace PortableServer
{
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:644

#if !defined (_PORTABLESERVER_CURRENT__VAR_OUT_CH_)
#define _PORTABLESERVER_CURRENT__VAR_OUT_CH_
  
  class Current;
  typedef Current *Current_ptr;
  
  typedef
    TAO_Objref_Var_T<
        Current
      >
    Current_var;
  
  typedef
    TAO_Objref_Out_T<
        Current
      >
    Current_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLESERVER_CURRENT_CH_)
#define _PORTABLESERVER_CURRENT_CH_
  
  class TAO_PortableServer_Export Current
    : public virtual ::CORBA::Current
  {
  public:
    typedef Current_ptr _ptr_type;
    typedef Current_var _var_type;
    typedef Current_out _out_type;
    
    // The static operations.
    static Current_ptr _duplicate (Current_ptr obj);
    
    static void _tao_release (Current_ptr obj);
    
    static Current_ptr _narrow (::CORBA::Object_ptr obj);
    static Current_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static Current_ptr _nil (void)
    {
      return static_cast<Current_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_exception/exception_ch.cpp:53

#if !defined (_PORTABLESERVER_CURRENT_NOCONTEXT_CH_)
#define _PORTABLESERVER_CURRENT_NOCONTEXT_CH_
    
    class TAO_PortableServer_Export NoContext : public ::CORBA::UserException
    {
    public:
      
      NoContext (void);
      NoContext (const NoContext &);
      ~NoContext (void);

      NoContext &operator= (const NoContext &);
      
      static void _tao_any_destructor (void *);
      
      static NoContext *_downcast ( ::CORBA::Exception *);
      static const NoContext *_downcast ( ::CORBA::Exception const *);
      
      static ::CORBA::Exception *_alloc (void);
      
      virtual ::CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void) const;

      virtual void _tao_encode (TAO_OutputCDR &cdr) const;
      virtual void _tao_decode (TAO_InputCDR &cdr);
      
      
      virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
    };
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
    
    static ::CORBA::TypeCode_ptr const _tc_NoContext;

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableServer::POA_ptr get_POA (
        void) = 0;
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableServer::ObjectId * get_object_id (
        void) = 0;
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Object_ptr get_reference (
        void) = 0;
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableServer::Servant get_servant (
        void) = 0;
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    Current (void);
    
    virtual ~Current (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Current (const Current &);
    
    void operator= (const Current &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_PortableServer_Export ::CORBA::TypeCode_ptr const _tc_Current;

// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

} // module PortableServer

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:64


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLESERVER_CURRENT__TRAITS_)
#define _PORTABLESERVER_CURRENT__TRAITS_
  
  template<>
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::Current>
  {
    static ::PortableServer::Current_ptr duplicate (
        ::PortableServer::Current_ptr p
      );
    static void release (
        ::PortableServer::Current_ptr p
      );
    static ::PortableServer::Current_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::PortableServer::Current_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:54



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace PortableServer
{
  TAO_PortableServer_Export void operator<<= ( ::CORBA::Any &, Current_ptr); // copying
  TAO_PortableServer_Export void operator<<= ( ::CORBA::Any &, Current_ptr *); // non-copying
  TAO_PortableServer_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Current_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_PortableServer_Export void operator<<= (::CORBA::Any &, PortableServer::Current_ptr); // copying
TAO_PortableServer_Export void operator<<= (::CORBA::Any &, PortableServer::Current_ptr *); // non-copying
TAO_PortableServer_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, PortableServer::Current_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_exception/any_op_ch.cpp:53

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_PortableServer_Export void operator<<= (::CORBA::Any &, const PortableServer::Current::NoContext &); // copying version
TAO_PortableServer_Export void operator<<= (::CORBA::Any &, PortableServer::Current::NoContext*); // noncopying version
TAO_PortableServer_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, PortableServer::Current::NoContext *&); // deprecated
TAO_PortableServer_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const PortableServer::Current::NoContext *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */


