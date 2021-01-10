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

#ifndef _TAO_PIDL_PORTABLESERVER_SERVANTMANAGERC_H_
#define _TAO_PIDL_PORTABLESERVER_SERVANTMANAGERC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/PortableServer/portableserver_export.h"
#include "tao/Basic_Types.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

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

#if !defined (_PORTABLESERVER_SERVANTMANAGER__VAR_OUT_CH_)
#define _PORTABLESERVER_SERVANTMANAGER__VAR_OUT_CH_
  
  class ServantManager;
  typedef ServantManager *ServantManager_ptr;
  
  typedef
    TAO_Objref_Var_T<
        ServantManager
      >
    ServantManager_var;
  
  typedef
    TAO_Objref_Out_T<
        ServantManager
      >
    ServantManager_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLESERVER_SERVANTMANAGER_CH_)
#define _PORTABLESERVER_SERVANTMANAGER_CH_
  
  class TAO_PortableServer_Export ServantManager
    : public virtual ::CORBA::Object
  {
  public:
    typedef ServantManager_ptr _ptr_type;
    typedef ServantManager_var _var_type;
    typedef ServantManager_out _out_type;
    
    // The static operations.
    static ServantManager_ptr _duplicate (ServantManager_ptr obj);
    
    static void _tao_release (ServantManager_ptr obj);
    
    static ServantManager_ptr _narrow (::CORBA::Object_ptr obj);
    static ServantManager_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static ServantManager_ptr _nil (void)
    {
      return static_cast<ServantManager_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
    
    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    ServantManager (void);
    
    virtual ~ServantManager (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ServantManager (const ServantManager &);
    
    void operator= (const ServantManager &);
  };

#endif /* end #if !defined */

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

#if !defined (_PORTABLESERVER_SERVANTMANAGER__TRAITS_)
#define _PORTABLESERVER_SERVANTMANAGER__TRAITS_
  
  template<>
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::ServantManager>
  {
    static ::PortableServer::ServantManager_ptr duplicate (
        ::PortableServer::ServantManager_ptr p
      );
    static void release (
        ::PortableServer::ServantManager_ptr p
      );
    static ::PortableServer::ServantManager_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::PortableServer::ServantManager_ptr p,
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


