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

#ifndef _TAO_PIDL_IORINTERCEPTOR_IORINTERCEPTORC_H_
#define _TAO_PIDL_IORINTERCEPTOR_IORINTERCEPTORC_H_

#include /**/ "ace/pre.h"

#ifndef TAO_IORINTERCEPTOR_SAFE_INCLUDE
#error You should not include IORInterceptor/IORInterceptorC.h, use tao/IORInterceptor/IORInterceptor.h
#endif /* TAO_IORINTERCEPTOR_SAFE_INCLUDE */

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/IORInterceptor/iorinterceptor_export.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/String_Manager_T.h"
#include "tao/Objref_VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/PI/InterceptorC.h"
#include "tao/IORInterceptor/IORInfoC.h"
#include "tao/ObjRefTemplate/ObjectReferenceTemplateC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_IORInterceptor_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace PortableInterceptor
{
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:644

#if !defined (_PORTABLEINTERCEPTOR_IORINTERCEPTOR__VAR_OUT_CH_)
#define _PORTABLEINTERCEPTOR_IORINTERCEPTOR__VAR_OUT_CH_
  
  class IORInterceptor;
  typedef IORInterceptor *IORInterceptor_ptr;
  
  typedef
    TAO_Objref_Var_T<
        IORInterceptor
      >
    IORInterceptor_var;
  
  typedef
    TAO_Objref_Out_T<
        IORInterceptor
      >
    IORInterceptor_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLEINTERCEPTOR_IORINTERCEPTOR_CH_)
#define _PORTABLEINTERCEPTOR_IORINTERCEPTOR_CH_
  
  class TAO_IORInterceptor_Export IORInterceptor
    : public virtual ::PortableInterceptor::Interceptor
  {
  public:
    typedef IORInterceptor_ptr _ptr_type;
    typedef IORInterceptor_var _var_type;
    typedef IORInterceptor_out _out_type;
    
    // The static operations.
    static IORInterceptor_ptr _duplicate (IORInterceptor_ptr obj);
    
    static void _tao_release (IORInterceptor_ptr obj);
    
    static IORInterceptor_ptr _narrow (::CORBA::Object_ptr obj);
    static IORInterceptor_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static IORInterceptor_ptr _nil (void)
    {
      return static_cast<IORInterceptor_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void establish_components (
        ::PortableInterceptor::IORInfo_ptr info) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    IORInterceptor (void);
    
    virtual ~IORInterceptor (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    IORInterceptor (const IORInterceptor &);
    
    void operator= (const IORInterceptor &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:644

#if !defined (_PORTABLEINTERCEPTOR_IORINTERCEPTOR_3_0__VAR_OUT_CH_)
#define _PORTABLEINTERCEPTOR_IORINTERCEPTOR_3_0__VAR_OUT_CH_
  
  class IORInterceptor_3_0;
  typedef IORInterceptor_3_0 *IORInterceptor_3_0_ptr;
  
  typedef
    TAO_Objref_Var_T<
        IORInterceptor_3_0
      >
    IORInterceptor_3_0_var;
  
  typedef
    TAO_Objref_Out_T<
        IORInterceptor_3_0
      >
    IORInterceptor_3_0_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLEINTERCEPTOR_IORINTERCEPTOR_3_0_CH_)
#define _PORTABLEINTERCEPTOR_IORINTERCEPTOR_3_0_CH_
  
  class TAO_IORInterceptor_Export IORInterceptor_3_0
    : public virtual ::PortableInterceptor::IORInterceptor
  {
  public:
    typedef IORInterceptor_3_0_ptr _ptr_type;
    typedef IORInterceptor_3_0_var _var_type;
    typedef IORInterceptor_3_0_out _out_type;
    
    // The static operations.
    static IORInterceptor_3_0_ptr _duplicate (IORInterceptor_3_0_ptr obj);
    
    static void _tao_release (IORInterceptor_3_0_ptr obj);
    
    static IORInterceptor_3_0_ptr _narrow (::CORBA::Object_ptr obj);
    static IORInterceptor_3_0_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static IORInterceptor_3_0_ptr _nil (void)
    {
      return static_cast<IORInterceptor_3_0_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void components_established (
        ::PortableInterceptor::IORInfo_ptr info) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void adapter_manager_state_changed (
        const char * id,
        ::PortableInterceptor::AdapterState state) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void adapter_state_changed (
        const ::PortableInterceptor::ObjectReferenceTemplateSeq & templates,
        ::PortableInterceptor::AdapterState state) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    IORInterceptor_3_0 (void);
    
    virtual ~IORInterceptor_3_0 (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    IORInterceptor_3_0 (const IORInterceptor_3_0 &);
    
    void operator= (const IORInterceptor_3_0 &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

} // module PortableInterceptor

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:64


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLEINTERCEPTOR_IORINTERCEPTOR__TRAITS_)
#define _PORTABLEINTERCEPTOR_IORINTERCEPTOR__TRAITS_
  
  template<>
  struct TAO_IORInterceptor_Export Objref_Traits< ::PortableInterceptor::IORInterceptor>
  {
    static ::PortableInterceptor::IORInterceptor_ptr duplicate (
        ::PortableInterceptor::IORInterceptor_ptr p
      );
    static void release (
        ::PortableInterceptor::IORInterceptor_ptr p
      );
    static ::PortableInterceptor::IORInterceptor_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::PortableInterceptor::IORInterceptor_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_IORINTERCEPTOR_3_0__TRAITS_)
#define _PORTABLEINTERCEPTOR_IORINTERCEPTOR_3_0__TRAITS_
  
  template<>
  struct TAO_IORInterceptor_Export Objref_Traits< ::PortableInterceptor::IORInterceptor_3_0>
  {
    static ::PortableInterceptor::IORInterceptor_3_0_ptr duplicate (
        ::PortableInterceptor::IORInterceptor_3_0_ptr p
      );
    static void release (
        ::PortableInterceptor::IORInterceptor_3_0_ptr p
      );
    static ::PortableInterceptor::IORInterceptor_3_0_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::PortableInterceptor::IORInterceptor_3_0_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */

