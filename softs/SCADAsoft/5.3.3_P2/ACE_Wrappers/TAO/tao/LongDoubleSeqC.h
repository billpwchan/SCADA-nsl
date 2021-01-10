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

#ifndef _TAO_PIDL_LONGDOUBLESEQC_H_
#define _TAO_PIDL_LONGDOUBLESEQC_H_

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
#include /**/ "tao/Versioned_Namespace.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:49

namespace CORBA
{
  
  // TAO_IDL - Generated from
  // a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_ch.cpp:107

#if !defined (_CORBA_LONGDOUBLESEQ_CH_)
#define _CORBA_LONGDOUBLESEQ_CH_
  
  class LongDoubleSeq;
  
  typedef
    TAO_FixedSeq_Var_T<
        LongDoubleSeq
      >
    LongDoubleSeq_var;
  
  typedef
    TAO_Seq_Out_T<
        LongDoubleSeq
      >
    LongDoubleSeq_out;
  
  class TAO_Export LongDoubleSeq
    : public
        TAO::unbounded_value_sequence<
            ::CORBA::LongDouble
          >
  {
  public:
    LongDoubleSeq (void);
    LongDoubleSeq ( ::CORBA::ULong max);
    LongDoubleSeq (
        ::CORBA::ULong max,
        ::CORBA::ULong length,
        ::CORBA::LongDouble* buffer, 
        ::CORBA::Boolean release = false
      );
    LongDoubleSeq (const LongDoubleSeq &);
    virtual ~LongDoubleSeq (void);
    
    static void _tao_any_destructor (void *);
    
    typedef LongDoubleSeq_var _var_type;
    typedef LongDoubleSeq_out _out_type;
    
    
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:78

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
// be\be_visitor_template_export.cpp:44

#if defined ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT
  template class TAO_Export TAO::unbounded_value_sequence<
      ::CORBA::LongDouble
    >;
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT */

// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_CORBA_LongDoubleSeq_H_
#define _TAO_CDR_OP_CORBA_LongDoubleSeq_H_

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_Export ::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::LongDoubleSeq &_tao_sequence
  );
TAO_Export ::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::LongDoubleSeq &_tao_sequence
  );
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif /* _TAO_CDR_OP_CORBA_LongDoubleSeq_H_ */

// TAO_IDL - Generated from
// be\be_codegen.cpp:1228


TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */


