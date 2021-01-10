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

#ifndef _TAO_PIDL_SERVICESC_H_
#define _TAO_PIDL_SERVICESC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/TAO_Export.h"
#include "tao/Basic_Types.h"
#include "tao/Sequence_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/OctetSeqC.h"

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
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef ::CORBA::UShort ServiceType;
  typedef ::CORBA::UShort_out ServiceType_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef ::CORBA::ULong ServiceOption;
  typedef ::CORBA::ULong_out ServiceOption_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef ::CORBA::ULong ServiceDetailType;
  typedef ::CORBA::ULong_out ServiceDetailType_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:472
  
  typedef OctetSeq ServiceDetailData;
  typedef OctetSeq_var ServiceDetailData_var;
  typedef OctetSeq_out ServiceDetailData_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_sequence/sequence_ch.cpp:107

#if !defined (_CORBA_SERVICEOPTIONSEQ_CH_)
#define _CORBA_SERVICEOPTIONSEQ_CH_
  
  class ServiceOptionSeq;
  
  typedef
    TAO_FixedSeq_Var_T<
        ServiceOptionSeq
      >
    ServiceOptionSeq_var;
  
  typedef
    TAO_Seq_Out_T<
        ServiceOptionSeq
      >
    ServiceOptionSeq_out;
  
  class TAO_Export ServiceOptionSeq
    : public
        TAO::unbounded_value_sequence<
            ServiceOption
          >
  {
  public:
    ServiceOptionSeq (void);
    ServiceOptionSeq ( ::CORBA::ULong max);
    ServiceOptionSeq (
        ::CORBA::ULong max,
        ::CORBA::ULong length,
        ::CORBA::ULong* buffer, 
        ::CORBA::Boolean release = false
      );
    ServiceOptionSeq (const ServiceOptionSeq &);
    virtual ~ServiceOptionSeq (void);
    
    static void _tao_any_destructor (void *);
    
    typedef ServiceOptionSeq_var _var_type;
    typedef ServiceOptionSeq_out _out_type;
    
    
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::ServiceType Security = 1U;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:269
  
  struct ServiceDetail;
  
  typedef
    TAO_Var_Var_T<
        ServiceDetail
      >
    ServiceDetail_var;
  
  typedef
    TAO_Out_T<
        ServiceDetail
      >
    ServiceDetail_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:57
  
  struct TAO_Export ServiceDetail
  {
    typedef ServiceDetail_var _var_type;
    typedef ServiceDetail_out _out_type;
    
    static void _tao_any_destructor (void *);
    CORBA::ServiceDetailType service_detail_type;
    CORBA::ServiceDetailData service_detail;
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_sequence/sequence_ch.cpp:107

#if !defined (_CORBA_SERVICEDETAILSEQ_CH_)
#define _CORBA_SERVICEDETAILSEQ_CH_
  
  class ServiceDetailSeq;
  
  typedef
    TAO_VarSeq_Var_T<
        ServiceDetailSeq
      >
    ServiceDetailSeq_var;
  
  typedef
    TAO_Seq_Out_T<
        ServiceDetailSeq
      >
    ServiceDetailSeq_out;
  
  class TAO_Export ServiceDetailSeq
    : public
        TAO::unbounded_value_sequence<
            ServiceDetail
          >
  {
  public:
    ServiceDetailSeq (void);
    ServiceDetailSeq ( ::CORBA::ULong max);
    ServiceDetailSeq (
        ::CORBA::ULong max,
        ::CORBA::ULong length,
        ServiceDetail* buffer, 
        ::CORBA::Boolean release = false
      );
    ServiceDetailSeq (const ServiceDetailSeq &);
    virtual ~ServiceDetailSeq (void);
    
    static void _tao_any_destructor (void *);
    
    typedef ServiceDetailSeq_var _var_type;
    typedef ServiceDetailSeq_out _out_type;
    
    
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:269
  
  struct ServiceInformation;
  
  typedef
    TAO_Var_Var_T<
        ServiceInformation
      >
    ServiceInformation_var;
  
  typedef
    TAO_Out_T<
        ServiceInformation
      >
    ServiceInformation_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:57
  
  struct TAO_Export ServiceInformation
  {
    typedef ServiceInformation_var _var_type;
    typedef ServiceInformation_out _out_type;
    
    static void _tao_any_destructor (void *);
    CORBA::ServiceOptionSeq service_options;
    CORBA::ServiceDetailSeq service_details;
  };

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
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_CORBA_ServiceOptionSeq_H_
#define _TAO_CDR_OP_CORBA_ServiceOptionSeq_H_

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_Export ::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ServiceOptionSeq &_tao_sequence
  );
TAO_Export ::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ServiceOptionSeq &_tao_sequence
  );
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif /* _TAO_CDR_OP_CORBA_ServiceOptionSeq_H_ */

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:54



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::ServiceDetail &);
TAO_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::ServiceDetail &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_CORBA_ServiceDetailSeq_H_
#define _TAO_CDR_OP_CORBA_ServiceDetailSeq_H_

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_Export ::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ServiceDetailSeq &_tao_sequence
  );
TAO_Export ::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ServiceDetailSeq &_tao_sequence
  );
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif /* _TAO_CDR_OP_CORBA_ServiceDetailSeq_H_ */

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:54



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::ServiceInformation &);
TAO_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::ServiceInformation &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */

