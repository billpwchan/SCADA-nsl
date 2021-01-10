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

#ifndef _TAO_IDL_G__BIN_P530_SRC_ASC2_IDL_ASCAGENT_SKEL_TIE_H_
#define _TAO_IDL_G__BIN_P530_SRC_ASC2_IDL_ASCAGENT_SKEL_TIE_H_



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:87

// TIE class: Refer to CORBA v2.2, Section 20.34.4
template <class T>
class  POA_AscAgentIdl_tie : public POA_AscAgentIdl
{
public:
  /// the T& ctor
  POA_AscAgentIdl_tie (T &t);
  /// ctor taking a POA
  POA_AscAgentIdl_tie (T &t, PortableServer::POA_ptr poa);
  /// ctor taking pointer and an ownership flag
  POA_AscAgentIdl_tie (T *tp, ::CORBA::Boolean release = true);
  /// ctor with T*, ownership flag and a POA
  POA_AscAgentIdl_tie (
      T *tp,
      PortableServer::POA_ptr poa,
      ::CORBA::Boolean release = true
    );
  /// dtor
  
  ~POA_AscAgentIdl_tie (void);
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
  
  ::ScsStatusIdl subscribe (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getState (
      const char *,
      ::CORBA::String_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getRemoteState (
      const char *,
      ::CORBA::String_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl setState (
      const char *,
      const char *);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl specifyState (
      const char *,
      const char *);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl startProcessInfo (
      ::CORBA::String_out,
      ::CORBA::Short_out,
      ::CORBA::Short_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl runCmd (
      const char *,
      const char *,
      const char *,
      const char *,
      const char *,
      const char *,
      const char *);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl runCommand (
      const char *,
      const char *);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl synchroniseStandby (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl switchover (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getSnapshot (
      ::AscAgentIdl_ptr);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl forceSnapshot (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl forceSnapshotIn (
      const char *);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl forceSnapshotWithStatus (
      const char *,
      ::AscIdl_ptr);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void snapshotCompleted (
      const char *);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void endSnapshotCompleted (
      ::CORBA::Boolean);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl foregroundSnapshot (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl endBackgroundSnapshot (
      const ::ScsStatusIdl &);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  void foregroundSnapshotReply (
      const ::ScsMessageTag &,
      const ::ScsStatusIdl &);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl testWatchdog (
      ::CORBA::Short_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getWatchdogLastLifeTime (
      ::ScsTimeValIdl_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getWatchdogMode (
      ::CORBA::Short_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getNet1SendState (
      ::CORBA::Short_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getLastNet1SendStateTime (
      ::ScsTimeValIdl_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getNet1RecvState (
      ::CORBA::Short_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getLastNet1RecvStateTime (
      ::ScsTimeValIdl_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getNet2SendState (
      ::CORBA::Short_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getLastNet2SendStateTime (
      ::ScsTimeValIdl_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getNet2RecvState (
      ::CORBA::Short_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getLastNet2RecvStateTime (
      ::ScsTimeValIdl_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getSerSendState (
      ::CORBA::Short_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getLastSerSendStateTime (
      ::ScsTimeValIdl_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getSerRecvState (
      ::CORBA::Short_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getLastSerRecvStateTime (
      ::ScsTimeValIdl_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getOSTime (
      ::ScsTimeValIdl_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getRemoteOSTime (
      ::ScsTimeValIdl_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getProcessInfos (
      ::ScsProcessInfosIdl &,
      ::CORBA::Short_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl getProcessArguments (
      const char *,
      ::StringList_out);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl refreshEnvList (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl authorizedExternalClientConnection (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:60
  
  ::ScsStatusIdl Shutdown (
      void);

private:
  T *ptr_;
  PortableServer::POA_var poa_;
  ::CORBA::Boolean rel_;
  
  // copy and assignment are not allowed
  POA_AscAgentIdl_tie (const POA_AscAgentIdl_tie &);
  void operator= (const POA_AscAgentIdl_tie &);
};

// TAO_IDL - Generated from 
// be\be_codegen.cpp:1391


#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ascagent_skel_tie.cpp"
#endif /* defined REQUIRED SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("ascagent_skel_tie.cpp")
#endif /* defined REQUIRED PRAGMA */

#endif /* ifndef */

