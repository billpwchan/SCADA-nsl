// -*- C++ -*-
// $Id: AMH_DSI_Response_Handler.inl 979 2008-12-31 20:22:32Z mitza $

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE TAO_AMH_DSI_Response_Handler_ptr
TAO_AMH_DSI_Response_Handler::_duplicate (TAO_AMH_DSI_Response_Handler_ptr x)
{
  if (x != 0)
    {
      x->_add_ref ();
    }

  return x;
}


// Inline operations for class TAO_AMH_DSI_Response_Handler_var
ACE_INLINE
TAO_AMH_DSI_Response_Handler_var::TAO_AMH_DSI_Response_Handler_var (void)
  : ptr_ (TAO_AMH_DSI_Response_Handler::_nil ())
{
}

ACE_INLINE
TAO_AMH_DSI_Response_Handler_var::TAO_AMH_DSI_Response_Handler_var (TAO_AMH_DSI_Response_Handler_ptr p)
  : ptr_ (p)
{}

ACE_INLINE
TAO_AMH_DSI_Response_Handler_var::~TAO_AMH_DSI_Response_Handler_var (void)
{
  CORBA::release(ptr_);
}

ACE_INLINE TAO_AMH_DSI_Response_Handler_ptr
TAO_AMH_DSI_Response_Handler_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
TAO_AMH_DSI_Response_Handler_var::TAO_AMH_DSI_Response_Handler_var (const TAO_AMH_DSI_Response_Handler_var &p)
  : ptr_ (TAO_AMH_DSI_Response_Handler::_duplicate (p.ptr ()))
{}

ACE_INLINE TAO_AMH_DSI_Response_Handler_var &
TAO_AMH_DSI_Response_Handler_var::operator= (TAO_AMH_DSI_Response_Handler_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE TAO_AMH_DSI_Response_Handler_var &
TAO_AMH_DSI_Response_Handler_var::operator= (const TAO_AMH_DSI_Response_Handler_var &p)
{
  if (this != &p)
    {
      CORBA::release (this->ptr_);
      this->ptr_ = TAO_AMH_DSI_Response_Handler::_duplicate (p.ptr ());
    }
  return *this;
}

ACE_INLINE
TAO_AMH_DSI_Response_Handler_var::operator const TAO_AMH_DSI_Response_Handler_ptr &() const
{
  return this->ptr_;
}

ACE_INLINE
TAO_AMH_DSI_Response_Handler_var::operator TAO_AMH_DSI_Response_Handler_ptr &()
{
  return this->ptr_;
}

ACE_INLINE TAO_AMH_DSI_Response_Handler_ptr
TAO_AMH_DSI_Response_Handler_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE TAO_AMH_DSI_Response_Handler_ptr
TAO_AMH_DSI_Response_Handler_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE TAO_AMH_DSI_Response_Handler_ptr &
TAO_AMH_DSI_Response_Handler_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE TAO_AMH_DSI_Response_Handler_ptr &
TAO_AMH_DSI_Response_Handler_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = TAO_AMH_DSI_Response_Handler::_nil ();
  return this->ptr_;
}

ACE_INLINE TAO_AMH_DSI_Response_Handler_ptr
TAO_AMH_DSI_Response_Handler_var::_retn (void)
{
  // yield ownership
  TAO_AMH_DSI_Response_Handler_ptr val = this->ptr_;
  this->ptr_ = TAO_AMH_DSI_Response_Handler::_nil ();
  return val;
}
TAO_END_VERSIONED_NAMESPACE_DECL
