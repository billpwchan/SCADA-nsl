// $Id: Abstract_Servant_Base.inl 979 2008-12-31 20:22:32Z mitza $

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
TAO_Abstract_ServantBase::TAO_Abstract_ServantBase (void)
{
  // No-Op.
}

ACE_INLINE
TAO_Abstract_ServantBase::TAO_Abstract_ServantBase
  (const TAO_Abstract_ServantBase &)
{
  // No-Op
}

ACE_INLINE
TAO_Abstract_ServantBase &
TAO_Abstract_ServantBase::operator= (const TAO_Abstract_ServantBase&)
{
  return *this;
}

TAO_END_VERSIONED_NAMESPACE_DECL
