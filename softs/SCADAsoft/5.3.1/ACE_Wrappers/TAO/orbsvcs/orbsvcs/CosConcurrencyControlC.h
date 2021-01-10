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

#ifndef _TAO_IDL_COSCONCURRENCYCONTROLC_H_
#define _TAO_IDL_COSCONCURRENCYCONTROLC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "orbsvcs/Concurrency/concurrency_export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/ORB.h"
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
#define TAO_EXPORT_MACRO TAO_Concurrency_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from 
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_root/root_ch.cpp:62

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  class Collocation_Proxy_Broker;
  template<typename T> class Narrow_Utils;
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace CosConcurrencyControl
{
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_enum/enum_ch.cpp:57
  
  enum lock_mode
  {
    read,
    write,
    upgrade,
    intention_read,
    intention_write
  };
  
  typedef lock_mode &lock_mode_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Concurrency_Export ::CORBA::TypeCode_ptr const _tc_lock_mode;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_exception/exception_ch.cpp:53

#if !defined (_COSCONCURRENCYCONTROL_LOCKNOTHELD_CH_)
#define _COSCONCURRENCYCONTROL_LOCKNOTHELD_CH_
  
  class TAO_Concurrency_Export LockNotHeld : public ::CORBA::UserException
  {
  public:
    
    LockNotHeld (void);
    LockNotHeld (const LockNotHeld &);
    ~LockNotHeld (void);

    LockNotHeld &operator= (const LockNotHeld &);
    
    static void _tao_any_destructor (void *);
    
    static LockNotHeld *_downcast ( ::CORBA::Exception *);
    static const LockNotHeld *_downcast ( ::CORBA::Exception const *);
    
    static ::CORBA::Exception *_alloc (void);
    
    virtual ::CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void) const;

    virtual void _tao_encode (TAO_OutputCDR &cdr) const;
    virtual void _tao_decode (TAO_InputCDR &cdr);
    
    
    virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Concurrency_Export ::CORBA::TypeCode_ptr const _tc_LockNotHeld;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:644

#if !defined (_COSCONCURRENCYCONTROL_LOCKSET__VAR_OUT_CH_)
#define _COSCONCURRENCYCONTROL_LOCKSET__VAR_OUT_CH_
  
  class LockSet;
  typedef LockSet *LockSet_ptr;
  
  typedef
    TAO_Objref_Var_T<
        LockSet
      >
    LockSet_var;
  
  typedef
    TAO_Objref_Out_T<
        LockSet
      >
    LockSet_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_COSCONCURRENCYCONTROL_LOCKSET_CH_)
#define _COSCONCURRENCYCONTROL_LOCKSET_CH_
  
  class TAO_Concurrency_Export LockSet
    : public virtual ::CORBA::Object
  {
  public:
    friend class TAO::Narrow_Utils<LockSet>;
    typedef LockSet_ptr _ptr_type;
    typedef LockSet_var _var_type;
    typedef LockSet_out _out_type;
    
    // The static operations.
    static LockSet_ptr _duplicate (LockSet_ptr obj);
    
    static void _tao_release (LockSet_ptr obj);
    
    static LockSet_ptr _narrow (::CORBA::Object_ptr obj);
    static LockSet_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static LockSet_ptr _nil (void)
    {
      return static_cast<LockSet_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void lock (
        ::CosConcurrencyControl::lock_mode mode);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Boolean try_lock (
        ::CosConcurrencyControl::lock_mode mode);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void unlock (
        ::CosConcurrencyControl::lock_mode mode);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void change_mode (
        ::CosConcurrencyControl::lock_mode held_mode,
        ::CosConcurrencyControl::lock_mode new_mode);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_LockSet_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    LockSet (void);
    
    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void CosConcurrencyControl_LockSet_setup_collocation (void);
    
    // Concrete non-local interface only.
    LockSet (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    LockSet (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);
    
    virtual ~LockSet (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    LockSet (const LockSet &);
    
    void operator= (const LockSet &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Concurrency_Export ::CORBA::TypeCode_ptr const _tc_LockSet;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:644

#if !defined (_COSCONCURRENCYCONTROL_LOCKSETFACTORY__VAR_OUT_CH_)
#define _COSCONCURRENCYCONTROL_LOCKSETFACTORY__VAR_OUT_CH_
  
  class LockSetFactory;
  typedef LockSetFactory *LockSetFactory_ptr;
  
  typedef
    TAO_Objref_Var_T<
        LockSetFactory
      >
    LockSetFactory_var;
  
  typedef
    TAO_Objref_Out_T<
        LockSetFactory
      >
    LockSetFactory_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_COSCONCURRENCYCONTROL_LOCKSETFACTORY_CH_)
#define _COSCONCURRENCYCONTROL_LOCKSETFACTORY_CH_
  
  class TAO_Concurrency_Export LockSetFactory
    : public virtual ::CORBA::Object
  {
  public:
    friend class TAO::Narrow_Utils<LockSetFactory>;
    typedef LockSetFactory_ptr _ptr_type;
    typedef LockSetFactory_var _var_type;
    typedef LockSetFactory_out _out_type;
    
    // The static operations.
    static LockSetFactory_ptr _duplicate (LockSetFactory_ptr obj);
    
    static void _tao_release (LockSetFactory_ptr obj);
    
    static LockSetFactory_ptr _narrow (::CORBA::Object_ptr obj);
    static LockSetFactory_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static LockSetFactory_ptr _nil (void)
    {
      return static_cast<LockSetFactory_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CosConcurrencyControl::LockSet_ptr create (
        void);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CosConcurrencyControl::LockSet_ptr create_related (
        ::CosConcurrencyControl::LockSet_ptr which);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_LockSetFactory_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    LockSetFactory (void);
    
    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void CosConcurrencyControl_LockSetFactory_setup_collocation (void);
    
    // Concrete non-local interface only.
    LockSetFactory (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    LockSetFactory (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);
    
    virtual ~LockSetFactory (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    LockSetFactory (const LockSetFactory &);
    
    void operator= (const LockSetFactory &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Concurrency_Export ::CORBA::TypeCode_ptr const _tc_LockSetFactory;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

} // module CosConcurrencyControl

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_root/root.cpp:139

extern TAO_Concurrency_Export
TAO::Collocation_Proxy_Broker *
(*CosConcurrencyControl__TAO_LockSet_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj
  );

extern TAO_Concurrency_Export
TAO::Collocation_Proxy_Broker *
(*CosConcurrencyControl__TAO_LockSetFactory_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:64


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_COSCONCURRENCYCONTROL_LOCKSET__TRAITS_)
#define _COSCONCURRENCYCONTROL_LOCKSET__TRAITS_
  
  template<>
  struct TAO_Concurrency_Export Objref_Traits< ::CosConcurrencyControl::LockSet>
  {
    static ::CosConcurrencyControl::LockSet_ptr duplicate (
        ::CosConcurrencyControl::LockSet_ptr p
      );
    static void release (
        ::CosConcurrencyControl::LockSet_ptr p
      );
    static ::CosConcurrencyControl::LockSet_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::CosConcurrencyControl::LockSet_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_COSCONCURRENCYCONTROL_LOCKSETFACTORY__TRAITS_)
#define _COSCONCURRENCYCONTROL_LOCKSETFACTORY__TRAITS_
  
  template<>
  struct TAO_Concurrency_Export Objref_Traits< ::CosConcurrencyControl::LockSetFactory>
  {
    static ::CosConcurrencyControl::LockSetFactory_ptr duplicate (
        ::CosConcurrencyControl::LockSetFactory_ptr p
      );
    static void release (
        ::CosConcurrencyControl::LockSetFactory_ptr p
      );
    static ::CosConcurrencyControl::LockSetFactory_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::CosConcurrencyControl::LockSetFactory_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_enum/any_op_ch.cpp:52

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_Concurrency_Export void operator<<= (::CORBA::Any &, CosConcurrencyControl::lock_mode);
TAO_Concurrency_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CosConcurrencyControl::lock_mode &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_exception/any_op_ch.cpp:53

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_Concurrency_Export void operator<<= (::CORBA::Any &, const CosConcurrencyControl::LockNotHeld &); // copying version
TAO_Concurrency_Export void operator<<= (::CORBA::Any &, CosConcurrencyControl::LockNotHeld*); // noncopying version
TAO_Concurrency_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CosConcurrencyControl::LockNotHeld *&); // deprecated
TAO_Concurrency_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const CosConcurrencyControl::LockNotHeld *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:54



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CosConcurrencyControl
{
  TAO_Concurrency_Export void operator<<= ( ::CORBA::Any &, LockSet_ptr); // copying
  TAO_Concurrency_Export void operator<<= ( ::CORBA::Any &, LockSet_ptr *); // non-copying
  TAO_Concurrency_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, LockSet_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Concurrency_Export void operator<<= (::CORBA::Any &, CosConcurrencyControl::LockSet_ptr); // copying
TAO_Concurrency_Export void operator<<= (::CORBA::Any &, CosConcurrencyControl::LockSet_ptr *); // non-copying
TAO_Concurrency_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CosConcurrencyControl::LockSet_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:54



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CosConcurrencyControl
{
  TAO_Concurrency_Export void operator<<= ( ::CORBA::Any &, LockSetFactory_ptr); // copying
  TAO_Concurrency_Export void operator<<= ( ::CORBA::Any &, LockSetFactory_ptr *); // non-copying
  TAO_Concurrency_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, LockSetFactory_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Concurrency_Export void operator<<= (::CORBA::Any &, CosConcurrencyControl::LockSetFactory_ptr); // copying
TAO_Concurrency_Export void operator<<= (::CORBA::Any &, CosConcurrencyControl::LockSetFactory_ptr *); // non-copying
TAO_Concurrency_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CosConcurrencyControl::LockSetFactory_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_enum/cdr_op_ch.cpp:50



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Concurrency_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, CosConcurrencyControl::lock_mode _tao_enumerator);
TAO_Concurrency_Export ::CORBA::Boolean operator>> (TAO_InputCDR &strm, CosConcurrencyControl::lock_mode &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_exception/cdr_op_ch.cpp:52

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_Concurrency_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const CosConcurrencyControl::LockNotHeld &);
TAO_Concurrency_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, CosConcurrencyControl::LockNotHeld &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:55


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Concurrency_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const CosConcurrencyControl::LockSet_ptr );
TAO_Concurrency_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, CosConcurrencyControl::LockSet_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:55


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Concurrency_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const CosConcurrencyControl::LockSetFactory_ptr );
TAO_Concurrency_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, CosConcurrencyControl::LockSetFactory_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "CosConcurrencyControlC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */


