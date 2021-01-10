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
// be\be_codegen.cpp:645

#ifndef _TAO_IDL_G__BIN_P530_SRC_ASC2_IDL_ASC_SKEL_TIE_H_
#define _TAO_IDL_G__BIN_P530_SRC_ASC2_IDL_ASC_SKEL_TIE_H_



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:87

// TIE class: Refer to CORBA v2.2, Section 20.34.4
template <class T>
class  POA_AscIdl_tie : public POA_AscIdl
{
public:
  /// the T& ctor
  POA_AscIdl_tie (T &t);
  /// ctor taking a POA
  POA_AscIdl_tie (T &t, PortableServer::POA_ptr poa);
  /// ctor taking pointer and an ownership flag
  POA_AscIdl_tie (T *tp, ::CORBA::Boolean release = true);
  /// ctor with T*, ownership flag and a POA
  POA_AscIdl_tie (
      T *tp,
      PortableServer::POA_ptr poa,
      ::CORBA::Boolean release = true
    );
  /// dtor
  
  ~POA_AscIdl_tie (void);
  // TIE specific functions
  /// return the underlying object
  T *_tied_object (void);
  /// set the underlying object
  void _tied_object (T &obj);
  /// set the underlying object and the ownership flag
  void _tied_object (T *obj, ::CORBA::Boolean release = true);
  /// do we own it
  ::CORBA::Boolean _is_owner (void);
  /// set the ownership
  
  void _is_owner ( ::CORBA::Boolean b);
  // overridden ServantBase operations
  PortableServer::POA_ptr _default_POA (void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  char * scs_implementation (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  char * scs_host (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void isAlive (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void getState (
      ::CORBA::String_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void setState (
      const char *);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void setTrace (
      ::CORBA::Long,
      ::CORBA::Long);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void setTraceOutput (
      ::CORBA::Long,
      const char *);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void setUserTrace (
      ::CORBA::Long,
      ::CORBA::Long);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void dump (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl foregroundSnapshot (
      const char *);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl backgroundSnapshot (
      ::AscAgentIdl_ptr,
      const char *);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void snapshotCompleted (
      const ::ScsStatusIdl &);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void sendEvent (
      ::CORBA::Long,
      ::CORBA::Long,
      const char *,
      const char *,
      const char *);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void sendAsyncEvent (
      ::CORBA::Long,
      ::CORBA::Long,
      const char *,
      const char *,
      const char *);

private:
  T *ptr_;
  PortableServer::POA_var poa_;
  ::CORBA::Boolean rel_;
  
  // copy and assignment are not allowed
  POA_AscIdl_tie (const POA_AscIdl_tie &);
  void operator= (const POA_AscIdl_tie &);
};

// TAO_IDL - Generated from 
// be\be_codegen.cpp:1391


#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "asc_skel_tie.cpp"
#endif /* defined REQUIRED SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("asc_skel_tie.cpp")
#endif /* defined REQUIRED PRAGMA */

#endif /* ifndef */
