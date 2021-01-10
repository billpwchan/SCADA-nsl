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

#ifndef _TAO_PIDL_GIOPC_H_
#define _TAO_PIDL_GIOPC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/TAO_Export.h"
#include "tao/Basic_Types.h"
#include "tao/String_Manager_T.h"
#include "tao/VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/IOPC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace GIOP
{
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef ::CORBA::Short AddressingDisposition;
  typedef ::CORBA::Short_out AddressingDisposition_out;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::Short KeyAddr = 0;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::Short ProfileAddr = 1;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::Short ReferenceAddr = 2;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:269
  
  struct Version;
  
  typedef
    TAO_Fixed_Var_T<
        Version
      >
    Version_var;
  
  typedef
    Version &
    Version_out;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:57
  
  struct TAO_Export Version
  {
    typedef Version_var _var_type;
    typedef Version_out _out_type;
    
    static void _tao_any_destructor (void *);
    ::CORBA::Octet major;
    ::CORBA::Octet minor;
  };
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:269
  
  struct IORAddressingInfo;
  
  typedef
    TAO_Var_Var_T<
        IORAddressingInfo
      >
    IORAddressingInfo_var;
  
  typedef
    TAO_Out_T<
        IORAddressingInfo
      >
    IORAddressingInfo_out;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:57
  
  struct TAO_Export IORAddressingInfo
  {
    typedef IORAddressingInfo_var _var_type;
    typedef IORAddressingInfo_out _out_type;
    
    static void _tao_any_destructor (void *);
    ::CORBA::ULong selected_profile_index;
    IOP::IOR ior;
  };
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:269
  
  class TargetAddress;
  
  typedef
    TAO_Var_Var_T<
        TargetAddress
      >
    TargetAddress_var;
  
  typedef
    TAO_Out_T<
        TargetAddress
      >
    TargetAddress_out;

#if !defined (_GIOP_TARGETADDRESS_CH_)
#define _GIOP_TARGETADDRESS_CH_
  
  class TAO_Export TargetAddress
  {
  public:
    TargetAddress (void);
    TargetAddress (const TargetAddress &);
    ~TargetAddress (void);
    static void _tao_any_destructor (void*);
    
    TargetAddress &operator= (const TargetAddress &);
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_union/discriminant_ch.cpp:114
    
    void _d ( ::CORBA::Short);
    ::CORBA::Short _d (void) const;
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_union/union_ch.cpp:113
    
    typedef TargetAddress_var _var_type;
    typedef TargetAddress_out _out_type;
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_union_branch/public_ch.cpp:559
    
    void object_key (const CORBA::OctetSeq &);
    const CORBA::OctetSeq &object_key (void) const;
    CORBA::OctetSeq &object_key (void);
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_union_branch/public_ch.cpp:667
    
    void profile (const IOP::TaggedProfile &);
    const IOP::TaggedProfile &profile (void) const;
    IOP::TaggedProfile &profile (void);
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_union_branch/public_ch.cpp:667
    
    void ior (const GIOP::IORAddressingInfo &);
    const GIOP::IORAddressingInfo &ior (void) const;
    GIOP::IORAddressingInfo &ior (void);
    
    // TAO_IDL - Generated from
    // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_union/union_ch.cpp:149
    
    void _default (void);
  private:
    ::CORBA::Short disc_;
    ::CORBA::Short holder_;
    
    union
    {
      // TAO_IDL - Generated from
      // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_union_branch/private_ch.cpp:455
      CORBA::OctetSeq *object_key_;
      // TAO_IDL - Generated from
      // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_union_branch/private_ch.cpp:530
      IOP::TaggedProfile *profile_;
      // TAO_IDL - Generated from
      // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_union_branch/private_ch.cpp:530
      GIOP::IORAddressingInfo *ior_;
    } u_;
    
    /// TAO extension - frees any allocated storage.
    void _reset (void);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_enum/enum_ch.cpp:57
  
  enum MsgType
  {
    Request,
    Reply,
    CancelRequest,
    LocateRequest,
    LocateReply,
    CloseConnection,
    MessageError,
    Fragment
  };
  
  typedef MsgType &MsgType_out;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_enum/enum_ch.cpp:57
  
  enum ReplyStatusType
  {
    NO_EXCEPTION,
    USER_EXCEPTION,
    SYSTEM_EXCEPTION,
    LOCATION_FORWARD,
    LOCATION_FORWARD_PERM,
    NEEDS_ADDRESSING_MODE
  };
  
  typedef ReplyStatusType &ReplyStatusType_out;
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_enum/enum_ch.cpp:57
  
  enum LocateStatusType
  {
    UNKNOWN_OBJECT,
    OBJECT_HERE,
    OBJECT_FORWARD,
    OBJECT_FORWARD_PERM,
    LOC_SYSTEM_EXCEPTION,
    LOC_NEEDS_ADDRESSING_MODE
  };
  
  typedef LocateStatusType &LocateStatusType_out;

// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

} // module GIOP

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:64


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:54



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const GIOP::Version &);
TAO_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, GIOP::Version &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:54



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const GIOP::IORAddressingInfo &);
TAO_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, GIOP::IORAddressingInfo &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_union/cdr_op_ch.cpp:54



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const GIOP::TargetAddress &);
TAO_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, GIOP::TargetAddress &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_enum/cdr_op_ch.cpp:50



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, GIOP::MsgType _tao_enumerator);
TAO_Export ::CORBA::Boolean operator>> (TAO_InputCDR &strm, GIOP::MsgType &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_enum/cdr_op_ch.cpp:50



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, GIOP::ReplyStatusType _tao_enumerator);
TAO_Export ::CORBA::Boolean operator>> (TAO_InputCDR &strm, GIOP::ReplyStatusType &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_enum/cdr_op_ch.cpp:50



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, GIOP::LocateStatusType _tao_enumerator);
TAO_Export ::CORBA::Boolean operator>> (TAO_InputCDR &strm, GIOP::LocateStatusType &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "GIOPC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */


