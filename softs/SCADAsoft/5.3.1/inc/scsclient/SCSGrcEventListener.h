// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSGrcEventListener.h
// Date     : 2015/10/12
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSGRCEVENTLISTENER_H
#define SCSCLIENT_SCSGRCEVENTLISTENER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSEventListener.h>
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
class SCSGrcEvent;

// ----------------------------------------------------------------------------
/// \class SCSGrcEventListener
/// \brief Abstract class for Grc events listener.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSGrcEventListener : public SCSEventListener {
public:
  /// \par Description:
  /// Creates a new listener of Grc events.
  SCSGrcEventListener() {}
  virtual ~SCSGrcEventListener() {}
  /// \par Description:
  /// Handles a Grc event.
  /// \param[in] event The Grc event.
  virtual void handleGRCEvent(SCSGrcEvent* event) = 0;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSGRCEVENTLISTENER_H
