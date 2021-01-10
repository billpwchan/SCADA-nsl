// SV_Message.cpp
// $Id: SV_Message.cpp 14 2007-02-01 15:49:12Z mitza $

#include "ace/SV_Message.h"

#if !defined (__ACE_INLINE__)
#include "ace/SV_Message.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, SV_Message, "$Id: SV_Message.cpp 14 2007-02-01 15:49:12Z mitza $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_SV_Message)

void
ACE_SV_Message::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SV_Message::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL
