// -*- C++ -*-
//
// $Id: Buffering_Constraint_Policy.inl 979 2008-12-31 20:22:32Z mitza $

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE void
TAO_Buffering_Constraint_Policy::get_buffering_constraint (TAO::BufferingConstraint &bc) const
{
  bc = this->buffering_constraint_;
}

TAO_END_VERSIONED_NAMESPACE_DECL
