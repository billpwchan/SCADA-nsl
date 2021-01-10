// -*- C++ -*-
//
// $Id: Message_Queue_Vx.inl 978 2008-12-31 20:17:52Z mitza $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_VXWORKS)
// Specialization to use native VxWorks Message Queues.

ACE_INLINE MSG_Q_ID
ACE_Message_Queue_Vx::msgq (void)
{
  // Hijack the tail_ field to store the MSG_Q_ID.
  return reinterpret_cast<MSG_Q_ID> (tail_);
}

#endif /* ACE_VXWORKS */

ACE_END_VERSIONED_NAMESPACE_DECL
