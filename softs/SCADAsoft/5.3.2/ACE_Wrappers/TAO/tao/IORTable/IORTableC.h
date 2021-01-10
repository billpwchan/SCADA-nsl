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

#ifndef _TAO_PIDL_IORTABLE_IORTABLEC_H_
#define _TAO_PIDL_IORTABLE_IORTABLEC_H_

#include /**/ "ace/pre.h"

#ifndef TAO_IORTABLE_SAFE_INCLUDE
#error You should not include IORTable/IORTableC.h, use tao/IORTable/IORTable.h
#endif /* TAO_IORTABLE_SAFE_INCLUDE */

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/IORTable/iortable_export.h"
#include "tao/SystemException.h"
#include "tao/UserException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_IORTable_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace IORTable
{
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:644

#if !defined (_IORTABLE_LOCATOR__VAR_OUT_CH_)
#define _IORTABLE_LOCATOR__VAR_OUT_CH_
  
  class Locator;
  typedef Locator *Locator_ptr;
  
  typedef
    TAO_Objref_Var_T<
        Locator
      >
    Locator_var;
  
  typedef
    TAO_Objref_Out_T<
        Locator
      >
    Locator_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_exception/exception_ch.cpp:53

#if !defined (_IORTABLE_ALREADYBOUND_CH_)
#define _IORTABLE_ALREADYBOUND_CH_
  
  class TAO_IORTable_Export AlreadyBound : public ::CORBA::UserException
  {
  public:
    
    AlreadyBound (void);
    AlreadyBound (const AlreadyBound &);
    ~AlreadyBound (void);

    AlreadyBound &operator= (const AlreadyBound &);
    
    static AlreadyBound *_downcast ( ::CORBA::Exception *);
    static const AlreadyBound *_downcast ( ::CORBA::Exception const *);
    
    static ::CORBA::Exception *_alloc (void);
    
    virtual ::CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void) const;

    virtual void _tao_encode (TAO_OutputCDR &cdr) const;
    virtual void _tao_decode (TAO_InputCDR &cdr);
    
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_exception/exception_ch.cpp:53

#if !defined (_IORTABLE_NOTFOUND_CH_)
#define _IORTABLE_NOTFOUND_CH_
  
  class TAO_IORTable_Export NotFound : public ::CORBA::UserException
  {
  public:
    
    NotFound (void);
    NotFound (const NotFound &);
    ~NotFound (void);

    NotFound &operator= (const NotFound &);
    
    static NotFound *_downcast ( ::CORBA::Exception *);
    static const NotFound *_downcast ( ::CORBA::Exception const *);
    
    static ::CORBA::Exception *_alloc (void);
    
    virtual ::CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void) const;

    virtual void _tao_encode (TAO_OutputCDR &cdr) const;
    virtual void _tao_decode (TAO_InputCDR &cdr);
    
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:644

#if !defined (_IORTABLE_TABLE__VAR_OUT_CH_)
#define _IORTABLE_TABLE__VAR_OUT_CH_
  
  class Table;
  typedef Table *Table_ptr;
  
  typedef
    TAO_Objref_Var_T<
        Table
      >
    Table_var;
  
  typedef
    TAO_Objref_Out_T<
        Table
      >
    Table_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_IORTABLE_TABLE_CH_)
#define _IORTABLE_TABLE_CH_
  
  class TAO_IORTable_Export Table
    : public virtual ::CORBA::Object
  {
  public:
    typedef Table_ptr _ptr_type;
    typedef Table_var _var_type;
    typedef Table_out _out_type;
    
    // The static operations.
    static Table_ptr _duplicate (Table_ptr obj);
    
    static void _tao_release (Table_ptr obj);
    
    static Table_ptr _narrow (::CORBA::Object_ptr obj);
    static Table_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static Table_ptr _nil (void)
    {
      return static_cast<Table_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void bind (
        const char * object_key,
        const char * IOR) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void rebind (
        const char * object_key,
        const char * IOR) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void unbind (
        const char * object_key) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void set_locator (
        ::IORTable::Locator_ptr the_locator) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    Table (void);
    
    virtual ~Table (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Table (const Table &);
    
    void operator= (const Table &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_IORTABLE_LOCATOR_CH_)
#define _IORTABLE_LOCATOR_CH_
  
  class TAO_IORTable_Export Locator
    : public virtual ::CORBA::Object
  {
  public:
    typedef Locator_ptr _ptr_type;
    typedef Locator_var _var_type;
    typedef Locator_out _out_type;
    
    // The static operations.
    static Locator_ptr _duplicate (Locator_ptr obj);
    
    static void _tao_release (Locator_ptr obj);
    
    static Locator_ptr _narrow (::CORBA::Object_ptr obj);
    static Locator_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static Locator_ptr _nil (void)
    {
      return static_cast<Locator_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual char * locate (
        const char * object_key) = 0;
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    Locator (void);
    
    virtual ~Locator (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Locator (const Locator &);
    
    void operator= (const Locator &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

} // module IORTable

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:64


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_IORTABLE_TABLE__TRAITS_)
#define _IORTABLE_TABLE__TRAITS_
  
  template<>
  struct TAO_IORTable_Export Objref_Traits< ::IORTable::Table>
  {
    static ::IORTable::Table_ptr duplicate (
        ::IORTable::Table_ptr p
      );
    static void release (
        ::IORTable::Table_ptr p
      );
    static ::IORTable::Table_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::IORTable::Table_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_IORTABLE_LOCATOR__TRAITS_)
#define _IORTABLE_LOCATOR__TRAITS_
  
  template<>
  struct TAO_IORTable_Export Objref_Traits< ::IORTable::Locator>
  {
    static ::IORTable::Locator_ptr duplicate (
        ::IORTable::Locator_ptr p
      );
    static void release (
        ::IORTable::Locator_ptr p
      );
    static ::IORTable::Locator_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::IORTable::Locator_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_exception/cdr_op_ch.cpp:52

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_IORTable_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const IORTable::AlreadyBound &);
TAO_IORTable_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, IORTable::AlreadyBound &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_exception/cdr_op_ch.cpp:52

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_IORTable_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const IORTable::NotFound &);
TAO_IORTable_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, IORTable::NotFound &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */


