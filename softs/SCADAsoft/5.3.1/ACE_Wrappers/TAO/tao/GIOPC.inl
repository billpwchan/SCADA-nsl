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


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union/union_ci.cpp:51

// *************************************************************
// Inline operations for union GIOP::TargetAddress
// *************************************************************

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union/discriminant_ci.cpp:165

ACE_INLINE
void 
GIOP::TargetAddress::_default ()
{
  this->_reset ();
  this->disc_ = -32768;
}

// Accessor to set the discriminant.
ACE_INLINE
void
GIOP::TargetAddress::_d ( ::CORBA::Short discval)
{
  this->disc_ = discval;
}

// Accessor to get the discriminant.
ACE_INLINE
::CORBA::Short
GIOP::TargetAddress::_d (void) const
{
  return this->disc_;
}

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:785

/// Accessor to set the member.
ACE_INLINE
void
GIOP::TargetAddress::object_key (const CORBA::OctetSeq &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 0;
  ACE_NEW (
      this->u_.object_key_,
      CORBA::OctetSeq (val)
    );
}

/// Readonly get method.
ACE_INLINE
const CORBA::OctetSeq &
GIOP::TargetAddress::object_key (void) const
{
  return *this->u_.object_key_;
}

/// Read/write get method.
ACE_INLINE
CORBA::OctetSeq &
GIOP::TargetAddress::object_key (void)
{
  return *this->u_.object_key_;
}

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:1058

/// Accessor to set the member.
ACE_INLINE
void
GIOP::TargetAddress::profile (const IOP::TaggedProfile &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 1;
  ACE_NEW (
      this->u_.profile_,
      IOP::TaggedProfile (val)
    );
}

// Readonly get method.
ACE_INLINE
const IOP::TaggedProfile &
GIOP::TargetAddress::profile (void) const
{
  return *this->u_.profile_;
}

// Read/write get method.
ACE_INLINE
IOP::TaggedProfile &
GIOP::TargetAddress::profile (void)
{
  return *this->u_.profile_;
}

// TAO_IDL - Generated from
// d:\softs\ace_wrappers_vc10\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:1058

/// Accessor to set the member.
ACE_INLINE
void
GIOP::TargetAddress::ior (const GIOP::IORAddressingInfo &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 2;
  ACE_NEW (
      this->u_.ior_,
      GIOP::IORAddressingInfo (val)
    );
}

// Readonly get method.
ACE_INLINE
const GIOP::IORAddressingInfo &
GIOP::TargetAddress::ior (void) const
{
  return *this->u_.ior_;
}

// Read/write get method.
ACE_INLINE
GIOP::IORAddressingInfo &
GIOP::TargetAddress::ior (void)
{
  return *this->u_.ior_;
}


TAO_END_VERSIONED_NAMESPACE_DECL


