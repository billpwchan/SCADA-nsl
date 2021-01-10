// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSServerStateEventListener.h
// Date     : 2012/12/14
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSSERVERSTATEEVENTLISTENER_H
#define SCSCLIENT_SCSSERVERSTATEEVENTLISTENER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSEventListener.h>

// ----------------------------------------------------------------------------
class SCSServerStateEvent;

// ----------------------------------------------------------------------------
/// \class SCSServerStateEventListener
/// \brief Abstract class for State events listener.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSServerStateEventListener : public SCSEventListener {
public:
  /// \par Description:
  /// Creates a new listener of Server state change events.
  SCSServerStateEventListener();
  virtual ~SCSServerStateEventListener();
  /// \par Description:
  /// Handles a Server state event.
  /// \param[in] event The State event.
  virtual void handleStateEvent(SCSServerStateEvent* event) = 0;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSSERVERSTATEEVENTLISTENER_H
