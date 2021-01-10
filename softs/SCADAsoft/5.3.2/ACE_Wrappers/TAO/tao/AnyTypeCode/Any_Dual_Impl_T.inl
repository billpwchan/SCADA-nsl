// -*- C++ -*-
//
// $Id: Any_Dual_Impl_T.inl 14 2007-02-01 15:49:12Z mitza $


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

template<typename T> 
ACE_INLINE 
CORBA::Boolean
TAO::Any_Dual_Impl_T<T>::demarshal_value (TAO_InputCDR &cdr)
{
  return (cdr >> *this->value_);
}

TAO_END_VERSIONED_NAMESPACE_DECL
