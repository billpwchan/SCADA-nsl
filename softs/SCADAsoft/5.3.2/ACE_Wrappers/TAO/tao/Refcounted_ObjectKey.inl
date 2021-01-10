// -*- C++ -*-
//
// $Id: Refcounted_ObjectKey.inl 14 2007-02-01 15:49:12Z mitza $


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE void
TAO::Refcounted_ObjectKey::incr_refcount (void)
{
  ++this->ref_count_;
}

ACE_INLINE const TAO::ObjectKey &
TAO::Refcounted_ObjectKey::object_key (void) const
{
  return this->object_key_;
}

TAO_END_VERSIONED_NAMESPACE_DECL
