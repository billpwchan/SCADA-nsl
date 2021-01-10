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

#ifndef _TAO_IDL_DSLOGNOTIFICATIONC_H_
#define _TAO_IDL_DSLOGNOTIFICATIONC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "orbsvcs/Log/log_export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/ORB.h"
#include "tao/Basic_Types.h"
#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/String_Manager_T.h"
#include "tao/VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "DsLogAdminC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Log_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace DsLogNotification
{
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:330
  
  typedef DsLogAdmin::Log Log;
  typedef DsLogAdmin::Log_ptr Log_ptr;
  typedef DsLogAdmin::Log_var Log_var;
  typedef DsLogAdmin::Log_out Log_out;
  
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Log_Export ::CORBA::TypeCode_ptr const _tc_Log;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef DsLogAdmin::LogId LogId;
  typedef DsLogAdmin::LogId_out LogId_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Log_Export ::CORBA::TypeCode_ptr const _tc_LogId;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef DsLogAdmin::Threshold Threshold;
  typedef DsLogAdmin::Threshold_out Threshold_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Log_Export ::CORBA::TypeCode_ptr const _tc_Threshold;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef TimeBase::TimeT TimeT;
  typedef TimeBase::TimeT_out TimeT_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Log_Export ::CORBA::TypeCode_ptr const _tc_TimeT;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef ::CORBA::UShort PerceivedSeverityType;
  typedef ::CORBA::UShort_out PerceivedSeverityType_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Log_Export ::CORBA::TypeCode_ptr const _tc_PerceivedSeverityType;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::PerceivedSeverityType critical = 0U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::PerceivedSeverityType minor = 1U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::PerceivedSeverityType cleared = 2U;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:269
  
  struct ThresholdAlarm;
  
  typedef
    TAO_Var_Var_T<
        ThresholdAlarm
      >
    ThresholdAlarm_var;
  
  typedef
    TAO_Out_T<
        ThresholdAlarm
      >
    ThresholdAlarm_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:57
  
  struct TAO_Log_Export ThresholdAlarm
  {
    typedef ThresholdAlarm_var _var_type;
    typedef ThresholdAlarm_out _out_type;
    
    static void _tao_any_destructor (void *);
    DsLogNotification::Log_var logref;
    DsLogNotification::LogId id;
    DsLogNotification::TimeT time;
    DsLogNotification::Threshold crossed_value;
    DsLogNotification::Threshold observed_value;
    DsLogNotification::PerceivedSeverityType perceived_severity;
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Log_Export ::CORBA::TypeCode_ptr const _tc_ThresholdAlarm;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:269
  
  struct ObjectCreation;
  
  typedef
    TAO_Fixed_Var_T<
        ObjectCreation
      >
    ObjectCreation_var;
  
  typedef
    ObjectCreation &
    ObjectCreation_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:57
  
  struct TAO_Log_Export ObjectCreation
  {
    typedef ObjectCreation_var _var_type;
    typedef ObjectCreation_out _out_type;
    
    static void _tao_any_destructor (void *);
    DsLogNotification::LogId id;
    DsLogNotification::TimeT time;
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Log_Export ::CORBA::TypeCode_ptr const _tc_ObjectCreation;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:269
  
  struct ObjectDeletion;
  
  typedef
    TAO_Fixed_Var_T<
        ObjectDeletion
      >
    ObjectDeletion_var;
  
  typedef
    ObjectDeletion &
    ObjectDeletion_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:57
  
  struct TAO_Log_Export ObjectDeletion
  {
    typedef ObjectDeletion_var _var_type;
    typedef ObjectDeletion_out _out_type;
    
    static void _tao_any_destructor (void *);
    DsLogNotification::LogId id;
    DsLogNotification::TimeT time;
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Log_Export ::CORBA::TypeCode_ptr const _tc_ObjectDeletion;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef ::CORBA::UShort AttributeType;
  typedef ::CORBA::UShort_out AttributeType_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Log_Export ::CORBA::TypeCode_ptr const _tc_AttributeType;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::AttributeType capacityAlarmThreshold = 0U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::AttributeType logFullAction = 1U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::AttributeType maxLogSize = 2U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::AttributeType startTime = 3U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::AttributeType stopTime = 4U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::AttributeType weekMask = 5U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::AttributeType filter = 6U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::AttributeType maxRecordLife = 7U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::AttributeType qualityOfService = 8U;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:269
  
  struct AttributeValueChange;
  
  typedef
    TAO_Var_Var_T<
        AttributeValueChange
      >
    AttributeValueChange_var;
  
  typedef
    TAO_Out_T<
        AttributeValueChange
      >
    AttributeValueChange_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:57
  
  struct TAO_Log_Export AttributeValueChange
  {
    typedef AttributeValueChange_var _var_type;
    typedef AttributeValueChange_out _out_type;
    
    static void _tao_any_destructor (void *);
    DsLogNotification::Log_var logref;
    DsLogNotification::LogId id;
    DsLogNotification::TimeT time;
    DsLogNotification::AttributeType type;
    ::CORBA::Any old_value;
    ::CORBA::Any new_value;
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Log_Export ::CORBA::TypeCode_ptr const _tc_AttributeValueChange;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef ::CORBA::UShort StateType;
  typedef ::CORBA::UShort_out StateType_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Log_Export ::CORBA::TypeCode_ptr const _tc_StateType;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::StateType administrativeState = 0U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::StateType operationalState = 1U;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:52
  
  const DsLogNotification::StateType forwardingState = 2U;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:269
  
  struct StateChange;
  
  typedef
    TAO_Var_Var_T<
        StateChange
      >
    StateChange_var;
  
  typedef
    TAO_Out_T<
        StateChange
      >
    StateChange_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:57
  
  struct TAO_Log_Export StateChange
  {
    typedef StateChange_var _var_type;
    typedef StateChange_out _out_type;
    
    static void _tao_any_destructor (void *);
    DsLogNotification::Log_var logref;
    DsLogNotification::LogId id;
    DsLogNotification::TimeT time;
    DsLogNotification::StateType type;
    ::CORBA::Any new_value;
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Log_Export ::CORBA::TypeCode_ptr const _tc_StateChange;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:269
  
  struct ProcessingErrorAlarm;
  
  typedef
    TAO_Var_Var_T<
        ProcessingErrorAlarm
      >
    ProcessingErrorAlarm_var;
  
  typedef
    TAO_Out_T<
        ProcessingErrorAlarm
      >
    ProcessingErrorAlarm_out;
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:57
  
  struct TAO_Log_Export ProcessingErrorAlarm
  {
    typedef ProcessingErrorAlarm_var _var_type;
    typedef ProcessingErrorAlarm_out _out_type;
    
    static void _tao_any_destructor (void *);
    ::CORBA::Long error_num;
    TAO::String_Manager error_string;
  };
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_Log_Export ::CORBA::TypeCode_ptr const _tc_ProcessingErrorAlarm;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

} // module DsLogNotification

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
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/any_op_ch.cpp:53



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Log_Export void operator<<= (::CORBA::Any &, const DsLogNotification::ThresholdAlarm &); // copying version
TAO_Log_Export void operator<<= (::CORBA::Any &, DsLogNotification::ThresholdAlarm*); // noncopying version
TAO_Log_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, DsLogNotification::ThresholdAlarm *&); // deprecated
TAO_Log_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const DsLogNotification::ThresholdAlarm *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/any_op_ch.cpp:53



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Log_Export void operator<<= (::CORBA::Any &, const DsLogNotification::ObjectCreation &); // copying version
TAO_Log_Export void operator<<= (::CORBA::Any &, DsLogNotification::ObjectCreation*); // noncopying version
TAO_Log_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, DsLogNotification::ObjectCreation *&); // deprecated
TAO_Log_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const DsLogNotification::ObjectCreation *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/any_op_ch.cpp:53



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Log_Export void operator<<= (::CORBA::Any &, const DsLogNotification::ObjectDeletion &); // copying version
TAO_Log_Export void operator<<= (::CORBA::Any &, DsLogNotification::ObjectDeletion*); // noncopying version
TAO_Log_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, DsLogNotification::ObjectDeletion *&); // deprecated
TAO_Log_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const DsLogNotification::ObjectDeletion *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/any_op_ch.cpp:53



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Log_Export void operator<<= (::CORBA::Any &, const DsLogNotification::AttributeValueChange &); // copying version
TAO_Log_Export void operator<<= (::CORBA::Any &, DsLogNotification::AttributeValueChange*); // noncopying version
TAO_Log_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, DsLogNotification::AttributeValueChange *&); // deprecated
TAO_Log_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const DsLogNotification::AttributeValueChange *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/any_op_ch.cpp:53



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Log_Export void operator<<= (::CORBA::Any &, const DsLogNotification::StateChange &); // copying version
TAO_Log_Export void operator<<= (::CORBA::Any &, DsLogNotification::StateChange*); // noncopying version
TAO_Log_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, DsLogNotification::StateChange *&); // deprecated
TAO_Log_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const DsLogNotification::StateChange *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/any_op_ch.cpp:53



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Log_Export void operator<<= (::CORBA::Any &, const DsLogNotification::ProcessingErrorAlarm &); // copying version
TAO_Log_Export void operator<<= (::CORBA::Any &, DsLogNotification::ProcessingErrorAlarm*); // noncopying version
TAO_Log_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, DsLogNotification::ProcessingErrorAlarm *&); // deprecated
TAO_Log_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const DsLogNotification::ProcessingErrorAlarm *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:54



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Log_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const DsLogNotification::ThresholdAlarm &);
TAO_Log_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, DsLogNotification::ThresholdAlarm &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:54



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Log_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const DsLogNotification::ObjectCreation &);
TAO_Log_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, DsLogNotification::ObjectCreation &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:54



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Log_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const DsLogNotification::ObjectDeletion &);
TAO_Log_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, DsLogNotification::ObjectDeletion &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:54



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Log_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const DsLogNotification::AttributeValueChange &);
TAO_Log_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, DsLogNotification::AttributeValueChange &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:54



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Log_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const DsLogNotification::StateChange &);
TAO_Log_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, DsLogNotification::StateChange &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:54



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Log_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const DsLogNotification::ProcessingErrorAlarm &);
TAO_Log_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, DsLogNotification::ProcessingErrorAlarm &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "DsLogNotificationC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */


