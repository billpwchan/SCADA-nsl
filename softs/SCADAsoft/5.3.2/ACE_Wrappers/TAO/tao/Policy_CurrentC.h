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

#ifndef _TAO_PIDL_POLICY_CURRENTC_H_
#define _TAO_PIDL_POLICY_CURRENTC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/TAO_Export.h"
#include "tao/Basic_Types.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/Policy_ManagerC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace CORBA
{
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:644

#if !defined (_CORBA_POLICYCURRENT__VAR_OUT_CH_)
#define _CORBA_POLICYCURRENT__VAR_OUT_CH_
  
  class PolicyCurrent;
  typedef PolicyCurrent *PolicyCurrent_ptr;
  
  typedef
    TAO_Objref_Var_T<
        PolicyCurrent
      >
    PolicyCurrent_var;
  
  typedef
    TAO_Objref_Out_T<
        PolicyCurrent
      >
    PolicyCurrent_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_CORBA_POLICYCURRENT_CH_)
#define _CORBA_POLICYCURRENT_CH_
  
  class TAO_Export PolicyCurrent
    : public virtual ::CORBA::PolicyManager,
      public virtual ::CORBA::Current
  {
  public:
    typedef PolicyCurrent_ptr _ptr_type;
    typedef PolicyCurrent_var _var_type;
    typedef PolicyCurrent_out _out_type;
    
    // The static operations.
    static PolicyCurrent_ptr _duplicate (PolicyCurrent_ptr obj);
    
    static void _tao_release (PolicyCurrent_ptr obj);
    
    static PolicyCurrent_ptr _narrow (::CORBA::Object_ptr obj);
    static PolicyCurrent_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static PolicyCurrent_ptr _nil (void)
    {
      return static_cast<PolicyCurrent_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    PolicyCurrent (void);
    
    virtual ~PolicyCurrent (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    PolicyCurrent (const PolicyCurrent &);
    
    void operator= (const PolicyCurrent &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

} // module CORBA

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:64


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_CORBA_POLICYCURRENT__TRAITS_)
#define _CORBA_POLICYCURRENT__TRAITS_
  
  template<>
  struct TAO_Export Objref_Traits< ::CORBA::PolicyCurrent>
  {
    static ::CORBA::PolicyCurrent_ptr duplicate (
        ::CORBA::PolicyCurrent_ptr p
      );
    static void release (
        ::CORBA::PolicyCurrent_ptr p
      );
    static ::CORBA::PolicyCurrent_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::CORBA::PolicyCurrent_ptr p,
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


