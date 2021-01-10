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

#ifndef _TAO_IDL_LB_ORTC_H_
#define _TAO_IDL_LB_ORTC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "orbsvcs/LoadBalancing/LoadBalancing_export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/Valuetype/ValueBase.h"
#include "tao/Valuetype/Valuetype_Adapter_Factory_Impl.h"
#include "tao/ORB.h"
#include "tao/Basic_Types.h"
#include "tao/Messaging/Messaging.h"
#include "tao/ObjRefTemplate/ObjectReferenceTemplate_includeA.h"
#include "tao/Valuetype/Value_VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/ObjRefTemplate/ObjectReferenceTemplate_includeC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_LoadBalancing_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace TAO_LB
{
  
  // TAO_IDL - Generated from
  // be\be_valuetype.cpp:568
  
  

#if !defined (_TAO_LB_OBJECTREFERENCEFACTORY__VAR_OUT_CH_)
#define _TAO_LB_OBJECTREFERENCEFACTORY__VAR_OUT_CH_
  
  class ObjectReferenceFactory;
  typedef
    TAO_Value_Var_T<
        ObjectReferenceFactory
      >
    ObjectReferenceFactory_var;
  
  typedef
    TAO_Value_Out_T<
        ObjectReferenceFactory
      >
    ObjectReferenceFactory_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_valuetype/valuetype_ch.cpp:61

#if !defined (_TAO_LB_OBJECTREFERENCEFACTORY_CH_)
#define _TAO_LB_OBJECTREFERENCEFACTORY_CH_
  
  class TAO_LoadBalancing_Export ObjectReferenceFactory
    : public virtual PortableInterceptor::ObjectReferenceFactory
  {
  public:
    typedef ObjectReferenceFactory * _ptr_type;
    typedef ObjectReferenceFactory_var _var_type;
    typedef ObjectReferenceFactory_out _out_type;
    
    static ObjectReferenceFactory* _downcast ( ::CORBA::ValueBase *v);
    
    // (TAO extensions or internals)
    static ::CORBA::Boolean _tao_unmarshal (
        TAO_InputCDR &strm,
        ObjectReferenceFactory *&new_object
      );
    
    virtual const char* _tao_obv_repository_id (void) const;
    
    virtual void _tao_obv_truncatable_repo_ids (Repository_Id_List &) const;
    
    static const char* _tao_obv_static_repository_id (void);
    
    static void _tao_any_destructor (void *);
    
    virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_valuetype/valuetype_ch.cpp:257
  
  protected:
    ObjectReferenceFactory (void);
    virtual ~ObjectReferenceFactory (void);
    
    virtual ::CORBA::Boolean _tao_marshal_v (TAO_OutputCDR &) const;
    virtual ::CORBA::Boolean _tao_unmarshal_v (TAO_InputCDR &);
    virtual ::CORBA::Boolean _tao_match_formal_type (ptrdiff_t ) const;
    
  private:
    ObjectReferenceFactory (const ObjectReferenceFactory &);
    void operator= (const ObjectReferenceFactory &);
    
  protected:
    virtual ::CORBA::Boolean
    _tao_marshal__TAO_LB_ObjectReferenceFactory (TAO_OutputCDR &, TAO_ChunkInfo &) const = 0;
    
    virtual ::CORBA::Boolean
    _tao_unmarshal__TAO_LB_ObjectReferenceFactory (TAO_InputCDR &, TAO_ChunkInfo &) = 0;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_LoadBalancing_Export ::CORBA::TypeCode_ptr const _tc_ObjectReferenceFactory;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

} // module TAO_LB

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_valuetype/obv_module.cpp:55

namespace OBV_TAO_LB
{
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_valuetype/valuetype_obv_ch.cpp:58

#if !defined (_TAO_LB_OBJECTREFERENCEFACTORY___OBV_CH_)
#define _TAO_LB_OBJECTREFERENCEFACTORY___OBV_CH_
  
  // OBV_ class
  class TAO_LoadBalancing_Export ObjectReferenceFactory
    : public virtual TAO_LB::ObjectReferenceFactory
  {

protected:
  ObjectReferenceFactory (void);
  virtual ~ObjectReferenceFactory (void);
  
protected:
  virtual ::CORBA::Boolean
  _tao_marshal__TAO_LB_ObjectReferenceFactory (TAO_OutputCDR &, TAO_ChunkInfo &) const;
  
  virtual ::CORBA::Boolean
  _tao_unmarshal__TAO_LB_ObjectReferenceFactory (TAO_InputCDR &, TAO_ChunkInfo &);
  
  ::CORBA::Boolean _tao_marshal_state (TAO_OutputCDR &, TAO_ChunkInfo &) const;
  ::CORBA::Boolean _tao_unmarshal_state (TAO_InputCDR &, TAO_ChunkInfo &);
  virtual void truncation_hook (void);

private:
  CORBA::Boolean require_truncation_;
};

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:64


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_TAO_LB_OBJECTREFERENCEFACTORY__TRAITS_)
#define _TAO_LB_OBJECTREFERENCEFACTORY__TRAITS_
  
  template<>
  struct TAO_LoadBalancing_Export Value_Traits<TAO_LB::ObjectReferenceFactory>
  {
    static void add_ref (TAO_LB::ObjectReferenceFactory *);
    static void remove_ref (TAO_LB::ObjectReferenceFactory *);
    static void release (TAO_LB::ObjectReferenceFactory *);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_valuetype/any_op_ch.cpp:55



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace TAO_LB
{
  TAO_LoadBalancing_Export void operator<<= ( ::CORBA::Any &, ObjectReferenceFactory *); // copying
  TAO_LoadBalancing_Export void operator<<= ( ::CORBA::Any &, ObjectReferenceFactory **); // non-copying
  TAO_LoadBalancing_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ObjectReferenceFactory *&);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_LoadBalancing_Export void operator<<= (::CORBA::Any &, TAO_LB::ObjectReferenceFactory *); // copying
TAO_LoadBalancing_Export void operator<<= (::CORBA::Any &, TAO_LB::ObjectReferenceFactory **); // non-copying
TAO_LoadBalancing_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, TAO_LB::ObjectReferenceFactory *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// be\be_valuetype.cpp:461



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace CORBA
{
  extern TAO_LoadBalancing_Export void add_ref (TAO_LB::ObjectReferenceFactory *);
  extern TAO_LoadBalancing_Export void remove_ref (TAO_LB::ObjectReferenceFactory *);
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_valuetype/cdr_op_ch.cpp:61



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_LoadBalancing_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_LB::ObjectReferenceFactory *);
TAO_LoadBalancing_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, TAO_LB::ObjectReferenceFactory *&);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "LB_ORTC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */


