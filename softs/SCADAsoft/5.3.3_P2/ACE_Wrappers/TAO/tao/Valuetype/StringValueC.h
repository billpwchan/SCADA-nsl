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

#ifndef _TAO_PIDL_VALUETYPE_STRINGVALUEC_H_
#define _TAO_PIDL_VALUETYPE_STRINGVALUEC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/Valuetype/valuetype_export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/Valuetype/ValueBase.h"
#include "tao/CDR.h"
#include "tao/Valuetype/Valuetype_Adapter_Factory_Impl.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Valuetype/Value_VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Valuetype_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace CORBA
{
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ch.cpp:52

#if !defined (_CORBA_STRINGVALUE_CH_)
#define _CORBA_STRINGVALUE_CH_
  
  class StringValue;
  
  typedef
    TAO_Value_Var_T<
        StringValue
      >
    StringValue_var;
  
  typedef
    TAO_Value_Out_T<
        StringValue
      >
    StringValue_out;
  
  class TAO_Valuetype_Export StringValue
    : public virtual ::CORBA::DefaultValueRefCountBase
  {
  public:
    typedef StringValue * _ptr_type;
    typedef StringValue_var _var_type;
    typedef StringValue_out _out_type;
    
    static StringValue* _downcast ( ::CORBA::ValueBase *);
    ::CORBA::ValueBase * _copy_value (void);
    
    virtual const char* _tao_obv_repository_id (void) const;
    
    virtual void _tao_obv_truncatable_repo_ids (Repository_Id_List &ids) const;
    
    static const char* _tao_obv_static_repository_id (void);
    
    static ::CORBA::Boolean _tao_unmarshal (
        TAO_InputCDR &,
        StringValue *&
      );
    
    virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
    
    
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ch.cpp:427
    
    // constructors
    StringValue (void);
    StringValue (CORBA::Char * val);
    StringValue (const CORBA::Char * val);
    StringValue (const ::CORBA::String_var& var);
    StringValue (const StringValue& val);
    // assignment operators
    StringValue& operator= (CORBA::Char * val);
    
    StringValue& operator= (const CORBA::Char * val);
    
    StringValue& operator= (const ::CORBA::String_var& var);
    
    // accessor
    const CORBA::Char * _value (void) const;
    
    // modifiers
    void _value (CORBA::Char * val);
    void _value (const CORBA::Char * val);
    void _value (const ::CORBA::String_var& var);
    
    // access to the boxed value for method signatures
    const CORBA::Char * _boxed_in (void) const;
    CORBA::Char *& _boxed_inout (void);
    CORBA::Char *& _boxed_out (void);
    // allows access and modification using a slot.
    char & operator[] ( ::CORBA::ULong slot);
    
    // allows only accessing thru a slot.
    char operator[] ( ::CORBA::ULong slot) const;
    
  private:
    ::CORBA::String_var _pd_value;
    
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ch.cpp:133
  
  protected:
    virtual ~StringValue (void);
    virtual ::CORBA::Boolean _tao_marshal_v (TAO_OutputCDR &) const;
    virtual ::CORBA::Boolean _tao_unmarshal_v (TAO_InputCDR &);
    virtual ::CORBA::Boolean _tao_match_formal_type (ptrdiff_t ) const;
    
  private:
    void operator= (const StringValue & val);
    
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Valuetype_Export ::CORBA::TypeCode_ptr const _tc_StringValue;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ch.cpp:52

#if !defined (_CORBA_WSTRINGVALUE_CH_)
#define _CORBA_WSTRINGVALUE_CH_
  
  class WStringValue;
  
  typedef
    TAO_Value_Var_T<
        WStringValue
      >
    WStringValue_var;
  
  typedef
    TAO_Value_Out_T<
        WStringValue
      >
    WStringValue_out;
  
  class TAO_Valuetype_Export WStringValue
    : public virtual ::CORBA::DefaultValueRefCountBase
  {
  public:
    typedef WStringValue * _ptr_type;
    typedef WStringValue_var _var_type;
    typedef WStringValue_out _out_type;
    
    static WStringValue* _downcast ( ::CORBA::ValueBase *);
    ::CORBA::ValueBase * _copy_value (void);
    
    virtual const char* _tao_obv_repository_id (void) const;
    
    virtual void _tao_obv_truncatable_repo_ids (Repository_Id_List &ids) const;
    
    static const char* _tao_obv_static_repository_id (void);
    
    static ::CORBA::Boolean _tao_unmarshal (
        TAO_InputCDR &,
        WStringValue *&
      );
    
    virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
    
    
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ch.cpp:427
    
    // constructors
    WStringValue (void);
    WStringValue (CORBA::WChar * val);
    WStringValue (const CORBA::WChar * val);
    WStringValue (const ::CORBA::WString_var& var);
    WStringValue (const WStringValue& val);
    // assignment operators
    WStringValue& operator= (CORBA::WChar * val);
    
    WStringValue& operator= (const CORBA::WChar * val);
    
    WStringValue& operator= (const ::CORBA::WString_var& var);
    
    // accessor
    const CORBA::WChar * _value (void) const;
    
    // modifiers
    void _value (CORBA::WChar * val);
    void _value (const CORBA::WChar * val);
    void _value (const ::CORBA::WString_var& var);
    
    // access to the boxed value for method signatures
    const CORBA::WChar * _boxed_in (void) const;
    CORBA::WChar *& _boxed_inout (void);
    CORBA::WChar *& _boxed_out (void);
    // allows access and modification using a slot.
    ::CORBA::WChar & operator[] ( ::CORBA::ULong slot);
    
    // allows only accessing thru a slot.
    ::CORBA::WChar operator[] ( ::CORBA::ULong slot) const;
    
  private:
    ::CORBA::WString_var _pd_value;
    
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ch.cpp:133
  
  protected:
    virtual ~WStringValue (void);
    virtual ::CORBA::Boolean _tao_marshal_v (TAO_OutputCDR &) const;
    virtual ::CORBA::Boolean _tao_unmarshal_v (TAO_InputCDR &);
    virtual ::CORBA::Boolean _tao_match_formal_type (ptrdiff_t ) const;
    
  private:
    void operator= (const WStringValue & val);
    
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Valuetype_Export ::CORBA::TypeCode_ptr const _tc_WStringValue;

// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

} // module CORBA

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:64


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_CORBA_STRINGVALUE__TRAITS_)
#define _CORBA_STRINGVALUE__TRAITS_
  
  template<>
  struct TAO_Valuetype_Export Value_Traits<CORBA::StringValue>
  {
    static void add_ref (CORBA::StringValue *);
    static void remove_ref (CORBA::StringValue *);
    static void release (CORBA::StringValue *);
  };

#endif /* end #if !defined */

#if !defined (_CORBA_WSTRINGVALUE__TRAITS_)
#define _CORBA_WSTRINGVALUE__TRAITS_
  
  template<>
  struct TAO_Valuetype_Export Value_Traits<CORBA::WStringValue>
  {
    static void add_ref (CORBA::WStringValue *);
    static void remove_ref (CORBA::WStringValue *);
    static void release (CORBA::WStringValue *);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/cdr_op_ch.cpp:50



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Valuetype_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::StringValue *);
TAO_Valuetype_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::StringValue *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/cdr_op_ch.cpp:50



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Valuetype_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::WStringValue *);
TAO_Valuetype_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::WStringValue *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "StringValueC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */


