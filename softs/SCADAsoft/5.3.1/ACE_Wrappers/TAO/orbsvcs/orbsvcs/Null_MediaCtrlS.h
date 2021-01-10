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

#ifndef _TAO_IDL_NULL_MEDIACTRLS_H_
#define _TAO_IDL_NULL_MEDIACTRLS_H_

#include /**/ "ace/pre.h"

#include "Null_MediaCtrlC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87

class POA_Null_MediaCtrl;
typedef POA_Null_MediaCtrl *POA_Null_MediaCtrl_ptr;

class TAO_AV_Export POA_Null_MediaCtrl
  : public virtual PortableServer::ServantBase
{
protected:
  POA_Null_MediaCtrl (void);

public:
  // Useful for template programming.
  typedef ::Null_MediaCtrl _stub_type;
  typedef ::Null_MediaCtrl_ptr _stub_ptr_type;
  typedef ::Null_MediaCtrl_var _stub_var_type;
  
  POA_Null_MediaCtrl (const POA_Null_MediaCtrl& rhs);
  virtual ~POA_Null_MediaCtrl (void);
  
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
  
  ::Null_MediaCtrl *_this (void);
  
  virtual const char* _interface_repository_id (void) const;
};

// TAO_IDL - Generated from 
// be\be_codegen.cpp:1290



TAO_END_VERSIONED_NAMESPACE_DECL


#if defined (__ACE_INLINE__)
#include "Null_MediaCtrlS.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"
#endif /* ifndef */
