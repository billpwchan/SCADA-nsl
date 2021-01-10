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

#ifndef _TAO_IDL_G__BIN_P530_SRC_IMG_IDL_INPUTMGR_H_
#define _TAO_IDL_G__BIN_P530_SRC_IMG_IDL_INPUTMGR_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/String_Manager_T.h"
#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "scsredtype.hh"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO 

// TAO_IDL - Generated from 
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_root/root_ch.cpp:62
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  class Collocation_Proxy_Broker;
  template<typename T> class Narrow_Utils;
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:413

typedef char * ScsObjectIdl;
typedef ::CORBA::String_var ScsObjectIdl_var;
typedef ::CORBA::String_out ScsObjectIdl_out;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:472

typedef CORBA::LongSeq LongList;
typedef CORBA::LongSeq_var LongList_var;
typedef CORBA::LongSeq_out LongList_out;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:472

typedef CORBA::ULongSeq ULongList;
typedef CORBA::ULongSeq_var ULongList_var;
typedef CORBA::ULongSeq_out ULongList_out;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:472

typedef CORBA::LongLongSeq LongLongList;
typedef CORBA::LongLongSeq_var LongLongList_var;
typedef CORBA::LongLongSeq_out LongLongList_out;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:472

typedef CORBA::ULongLongSeq ULongLongList;
typedef CORBA::ULongLongSeq_var ULongLongList_var;
typedef CORBA::ULongLongSeq_out ULongLongList_out;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:472

typedef CORBA::FloatSeq FloatList;
typedef CORBA::FloatSeq_var FloatList_var;
typedef CORBA::FloatSeq_out FloatList_out;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:472

typedef CORBA::DoubleSeq DoubleList;
typedef CORBA::DoubleSeq_var DoubleList_var;
typedef CORBA::DoubleSeq_out DoubleList_out;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:472

typedef CORBA::StringSeq StringList;
typedef CORBA::StringSeq_var StringList_var;
typedef CORBA::StringSeq_out StringList_out;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:472

typedef CORBA::OctetSeq OctetList;
typedef CORBA::OctetSeq_var OctetList_var;
typedef CORBA::OctetSeq_out OctetList_out;

// TAO_IDL - Generated from
// be\be_type.cpp:269

struct ImgListLength;

typedef
  TAO_Var_Var_T<
      ImgListLength
    >
  ImgListLength_var;

typedef
  TAO_Out_T<
      ImgListLength
    >
  ImgListLength_out;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:57

struct  ImgListLength
{
  typedef ImgListLength_var _var_type;
  typedef ImgListLength_out _out_type;
  
  static void _tao_any_destructor (void *);
  TAO::String_Manager listName;
  ::CORBA::Long listLength;
  StringList contents;
};

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49

extern  ::CORBA::TypeCode_ptr const _tc_ImgListLength;

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_sequence/sequence_ch.cpp:107

#if !defined (_IMGLISTLENGTHLIST_CH_)
#define _IMGLISTLENGTHLIST_CH_

class ImgListLengthList;

typedef
  TAO_VarSeq_Var_T<
      ImgListLengthList
    >
  ImgListLengthList_var;

typedef
  TAO_Seq_Out_T<
      ImgListLengthList
    >
  ImgListLengthList_out;

class  ImgListLengthList
  : public
      TAO::unbounded_value_sequence<
          ImgListLength
        >
{
public:
  ImgListLengthList (void);
  ImgListLengthList ( ::CORBA::ULong max);
  ImgListLengthList (
      ::CORBA::ULong max,
      ::CORBA::ULong length,
      ImgListLength* buffer, 
      ::CORBA::Boolean release = false
    );
  ImgListLengthList (const ImgListLengthList &);
  virtual ~ImgListLengthList (void);
  
  static void _tao_any_destructor (void *);
  
  typedef ImgListLengthList_var _var_type;
  typedef ImgListLengthList_out _out_type;
  
  
};

#endif /* end #if !defined */

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49

extern  ::CORBA::TypeCode_ptr const _tc_ImgListLengthList;

// TAO_IDL - Generated from
// be\be_interface.cpp:644

#if !defined (_INPUTMGRIDL__VAR_OUT_CH_)
#define _INPUTMGRIDL__VAR_OUT_CH_

class InputMgrIdl;
typedef InputMgrIdl *InputMgrIdl_ptr;

typedef
  TAO_Objref_Var_T<
      InputMgrIdl
    >
  InputMgrIdl_var;

typedef
  TAO_Objref_Out_T<
      InputMgrIdl
    >
  InputMgrIdl_out;

#endif /* end #if !defined */

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_INPUTMGRIDL_CH_)
#define _INPUTMGRIDL_CH_

class  InputMgrIdl
  : public virtual ::ScsProcessIdl
{
public:
  friend class TAO::Narrow_Utils<InputMgrIdl>;
  typedef InputMgrIdl_ptr _ptr_type;
  typedef InputMgrIdl_var _var_type;
  typedef InputMgrIdl_out _out_type;
  
  // The static operations.
  static InputMgrIdl_ptr _duplicate (InputMgrIdl_ptr obj);
  
  static void _tao_release (InputMgrIdl_ptr obj);
  
  static InputMgrIdl_ptr _narrow (::CORBA::Object_ptr obj);
  static InputMgrIdl_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
  static InputMgrIdl_ptr _nil (void)
  {
    return static_cast<InputMgrIdl_ptr> (0);
  }
  
  static void _tao_any_destructor (void *);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
  
  virtual ::ScsStatusIdl InputMgr_failOver (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
  
  virtual ::ScsStatusIdl InputMgr_switchOver (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
  
  virtual ::ScsStatusIdl readSnapshot (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
  
  virtual void standbyEnvironmentUp (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
  
  virtual void updateTime (
      ::ScsProcessIdl_ptr source,
      ::ScsProcessIdl_ptr destination,
      const ::ScsMessageTag & tag,
      const ::ScsTimeValIdl & onlineTime);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
  
  virtual void printMsgOn (
      const char * tty);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
  
  virtual void printMsgOff (
      void);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
  
  virtual ::ScsStatusIdl dump (
      ::ImgListLengthList_out valueList,
      ::CORBA::Boolean showContents);
  
  // TAO_IDL - Generated from
  // d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:216
  
  virtual ::CORBA::Boolean _is_a (const char *type_id);
  virtual const char* _interface_repository_id (void) const;
  virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
private:
  TAO::Collocation_Proxy_Broker *the_TAO_InputMgrIdl_Proxy_Broker_;

protected:
  // Concrete interface only.
  InputMgrIdl (void);
  
  // These methods travese the inheritance tree and set the
  // parents piece of the given class in the right mode.
  virtual void InputMgrIdl_setup_collocation (void);
  
  // Concrete non-local interface only.
  InputMgrIdl (
      ::IOP::IOR *ior,
      TAO_ORB_Core *orb_core);
  
  // Non-local interface only.
  InputMgrIdl (
      TAO_Stub *objref,
      ::CORBA::Boolean _tao_collocated = false,
      TAO_Abstract_ServantBase *servant = 0,
      TAO_ORB_Core *orb_core = 0);
  
  virtual ~InputMgrIdl (void);

private:
  // Private and unimplemented for concrete interfaces.
  InputMgrIdl (const InputMgrIdl &);
  
  void operator= (const InputMgrIdl &);
};

#endif /* end #if !defined */

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:49

extern  ::CORBA::TypeCode_ptr const _tc_InputMgrIdl;

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_root/root.cpp:139

extern 
TAO::Collocation_Proxy_Broker *
(*_TAO_InputMgrIdl_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:64

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_INPUTMGRIDL__TRAITS_)
#define _INPUTMGRIDL__TRAITS_
  
  template<>
  struct  Objref_Traits< ::InputMgrIdl>
  {
    static ::InputMgrIdl_ptr duplicate (
        ::InputMgrIdl_ptr p
      );
    static void release (
        ::InputMgrIdl_ptr p
      );
    static ::InputMgrIdl_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::InputMgrIdl_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/any_op_ch.cpp:53


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, const ImgListLength &); // copying version
 void operator<<= (::CORBA::Any &, ImgListLength*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ImgListLength *&); // deprecated
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ImgListLength *&);
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_sequence/any_op_ch.cpp:53


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= ( ::CORBA::Any &, const ImgListLengthList &); // copying version
 void operator<<= ( ::CORBA::Any &, ImgListLengthList*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ImgListLengthList *&); // deprecated
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ImgListLengthList *&);
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:54


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, InputMgrIdl_ptr); // copying
 void operator<<= (::CORBA::Any &, InputMgrIdl_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, InputMgrIdl_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:54


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const ImgListLength &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, ImgListLength &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_ImgListLengthList_H_
#define _TAO_CDR_OP_ImgListLengthList_H_
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



 ::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const ImgListLengthList &_tao_sequence
  );
 ::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    ImgListLengthList &_tao_sequence
  );
TAO_END_VERSIONED_NAMESPACE_DECL



#endif /* _TAO_CDR_OP_ImgListLengthList_H_ */

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:55

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const InputMgrIdl_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, InputMgrIdl_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be\be_codegen.cpp:1228
#if defined (__ACE_INLINE__)
#include "inputmgr.inl"
#endif /* defined INLINE */

#endif /* ifndef */


