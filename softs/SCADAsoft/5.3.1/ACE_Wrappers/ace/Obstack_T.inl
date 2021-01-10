// -*- C++ -*-
//
// $Id: Obstack_T.inl 1424 2010-01-28 18:25:37Z cleeland $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class ACE_CHAR_T> ACE_INLINE size_t
ACE_Obstack_T<ACE_CHAR_T>::length () const
{
  return this->size_ / sizeof (ACE_CHAR_T);
}

template <class ACE_CHAR_T> ACE_INLINE size_t
ACE_Obstack_T<ACE_CHAR_T>::size () const
{
  return this->size_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
