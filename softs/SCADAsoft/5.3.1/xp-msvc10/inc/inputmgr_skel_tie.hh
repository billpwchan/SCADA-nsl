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

#ifndef _TAO_IDL_G__BIN_P530_SRC_IMG_IDL_INPUTMGR_SKEL_TIE_H_
#define _TAO_IDL_G__BIN_P530_SRC_IMG_IDL_INPUTMGR_SKEL_TIE_H_



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:87

// TIE class: Refer to CORBA v2.2, Section 20.34.4
template <class T>
class  POA_InputMgrIdl_tie : public POA_InputMgrIdl
{
public:
  /// the T& ctor
  POA_InputMgrIdl_tie (T &t);
  /// ctor taking a POA
  POA_InputMgrIdl_tie (T &t, PortableServer::POA_ptr poa);
  /// ctor taking pointer and an ownership flag
  POA_InputMgrIdl_tie (T *tp, ::CORBA::Boolean release = true);
  /// ctor with T*, ownership flag and a POA
  POA_InputMgrIdl_tie (
      T *tp,
      PortableServer::POA_ptr poa,
      ::CORBA::Boolean release = true
    );
  /// dtor
  
  ~POA_InputMgrIdl_tie (void);
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
  
  ::ScsStatusIdl InputMgr_failOver (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl InputMgr_switchOver (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl readSnapshot (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void standbyEnvironmentUp (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void updateTime (
      ::ScsProcessIdl_ptr,
      ::ScsProcessIdl_ptr,
      const ::ScsMessageTag &,
      const ::ScsTimeValIdl &);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void printMsgOn (
      const char *);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void printMsgOff (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl dump (
      ::ImgListLengthList_out,
      ::CORBA::Boolean);

private:
  T *ptr_;
  PortableServer::POA_var poa_;
  ::CORBA::Boolean rel_;
  
  // copy and assignment are not allowed
  POA_InputMgrIdl_tie (const POA_InputMgrIdl_tie &);
  void operator= (const POA_InputMgrIdl_tie &);
};

// TAO_IDL - Generated from 
// be\be_codegen.cpp:1391


#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "inputmgr_skel_tie.cpp"
#endif /* defined REQUIRED SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("inputmgr_skel_tie.cpp")
#endif /* defined REQUIRED PRAGMA */

#endif /* ifndef */

