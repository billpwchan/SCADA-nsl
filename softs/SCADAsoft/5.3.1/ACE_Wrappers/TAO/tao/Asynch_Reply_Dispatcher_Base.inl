// -*- C++ -*-
//
// $Id: Asynch_Reply_Dispatcher_Base.inl 935 2008-12-10 21:47:27Z mitza $

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  ACE_INLINE void
  ARDB_Refcount_Functor::operator () (
      TAO_Asynch_Reply_Dispatcher_Base *ardb) throw ()
  {
    (void) ardb->decr_refcount ();
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL