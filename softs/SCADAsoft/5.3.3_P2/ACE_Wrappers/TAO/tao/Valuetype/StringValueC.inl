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


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ci.cpp:300

ACE_INLINE
CORBA::StringValue::StringValue (void)
{}

ACE_INLINE 
CORBA::StringValue::StringValue (CORBA::Char * val)
{
  this->_pd_value = val;
}

ACE_INLINE 
CORBA::StringValue::StringValue (const CORBA::StringValue& val)
  : ::CORBA::ValueBase (val),
    ::CORBA::DefaultValueRefCountBase (val)
{
  this->_pd_value = val._pd_value;
}

ACE_INLINE CORBA::StringValue &
CORBA::StringValue::operator= (CORBA::Char * val)
{
  this->_pd_value = val;
  return *this;
}

ACE_INLINE 
CORBA::StringValue::StringValue (const CORBA::Char * val)
{
  this->_pd_value = val;
}

ACE_INLINE
CORBA::StringValue::StringValue (const ::CORBA::String_var& var)
{
  this->_pd_value = var;
}

ACE_INLINE CORBA::StringValue &
CORBA::StringValue::operator= (const CORBA::Char * val)
{
  this->_pd_value = val;
  return *this;
}

ACE_INLINE CORBA::StringValue &
CORBA::StringValue::operator= (const ::CORBA::String_var& var)
{
  this->_pd_value = var;
  return *this;
}

ACE_INLINE const CORBA::Char *
CORBA::StringValue::_value (void) const
{
  return this->_pd_value.in ();
}

ACE_INLINE void
CORBA::StringValue::_value (CORBA::Char * val)
{
  this->_pd_value = val;
}

ACE_INLINE void
CORBA::StringValue::_value (const CORBA::Char * val)
{
  this->_pd_value = val;
}

ACE_INLINE void
CORBA::StringValue::_value (const ::CORBA::String_var& var)
{
  this->_pd_value = var;
}

ACE_INLINE const CORBA::Char *
CORBA::StringValue::_boxed_in (void) const
{
  return this->_pd_value.in ();
}

ACE_INLINE CORBA::Char *&
CORBA::StringValue::_boxed_inout (void)
{
  return this->_pd_value.inout ();
}

ACE_INLINE CORBA::Char *&
CORBA::StringValue::_boxed_out (void)
{
  return this->_pd_value.out ();
}

ACE_INLINE ::CORBA::Char &
CORBA::StringValue::operator[] ( ::CORBA::ULong slot)
{
  return this->_pd_value[slot];
}

ACE_INLINE ::CORBA::Char
CORBA::StringValue::operator[] ( ::CORBA::ULong slot) const
{
  return this->_pd_value[slot];
}



// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ci.cpp:60
ACE_INLINE const char* 
CORBA::StringValue::_tao_obv_static_repository_id ()
{
  return "IDL:omg.org/CORBA/StringValue:1.0";
}



// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ci.cpp:300

ACE_INLINE
CORBA::WStringValue::WStringValue (void)
{}

ACE_INLINE 
CORBA::WStringValue::WStringValue (CORBA::WChar * val)
{
  this->_pd_value = val;
}

ACE_INLINE 
CORBA::WStringValue::WStringValue (const CORBA::WStringValue& val)
  : ::CORBA::ValueBase (val),
    ::CORBA::DefaultValueRefCountBase (val)
{
  this->_pd_value = val._pd_value;
}

ACE_INLINE CORBA::WStringValue &
CORBA::WStringValue::operator= (CORBA::WChar * val)
{
  this->_pd_value = val;
  return *this;
}

ACE_INLINE 
CORBA::WStringValue::WStringValue (const CORBA::WChar * val)
{
  this->_pd_value = val;
}

ACE_INLINE
CORBA::WStringValue::WStringValue (const ::CORBA::WString_var& var)
{
  this->_pd_value = var;
}

ACE_INLINE CORBA::WStringValue &
CORBA::WStringValue::operator= (const CORBA::WChar * val)
{
  this->_pd_value = val;
  return *this;
}

ACE_INLINE CORBA::WStringValue &
CORBA::WStringValue::operator= (const ::CORBA::WString_var& var)
{
  this->_pd_value = var;
  return *this;
}

ACE_INLINE const CORBA::WChar *
CORBA::WStringValue::_value (void) const
{
  return this->_pd_value.in ();
}

ACE_INLINE void
CORBA::WStringValue::_value (CORBA::WChar * val)
{
  this->_pd_value = val;
}

ACE_INLINE void
CORBA::WStringValue::_value (const CORBA::WChar * val)
{
  this->_pd_value = val;
}

ACE_INLINE void
CORBA::WStringValue::_value (const ::CORBA::WString_var& var)
{
  this->_pd_value = var;
}

ACE_INLINE const CORBA::WChar *
CORBA::WStringValue::_boxed_in (void) const
{
  return this->_pd_value.in ();
}

ACE_INLINE CORBA::WChar *&
CORBA::WStringValue::_boxed_inout (void)
{
  return this->_pd_value.inout ();
}

ACE_INLINE CORBA::WChar *&
CORBA::WStringValue::_boxed_out (void)
{
  return this->_pd_value.out ();
}

ACE_INLINE ::CORBA::WChar &
CORBA::WStringValue::operator[] ( ::CORBA::ULong slot)
{
  return this->_pd_value[slot];
}

ACE_INLINE ::CORBA::WChar
CORBA::WStringValue::operator[] ( ::CORBA::ULong slot) const
{
  return this->_pd_value[slot];
}



// TAO_IDL - Generated from
// a:\softs\softs_5_3\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_ci.cpp:60
ACE_INLINE const char* 
CORBA::WStringValue::_tao_obv_static_repository_id ()
{
  return "IDL:omg.org/CORBA/WStringValue:1.0";
}




TAO_END_VERSIONED_NAMESPACE_DECL


