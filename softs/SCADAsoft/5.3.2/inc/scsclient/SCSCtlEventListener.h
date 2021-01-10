// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSCtlEventListener.h
// Date     : 2012/03/20
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSCTLEVENTLISTENER_H
#define SCSCLIENT_SCSCTLEVENTLISTENER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSEventListener.h>
// ----------------------------------------------------------------------------
#include <vector>
// ----------------------------------------------------------------------------
class SCSCtlEvent;

// ----------------------------------------------------------------------------
/// \class SCSCtlEventListener
/// \brief Abstract class for Ctl events listener.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSCtlEventListener : public SCSEventListener {
public:
  /// \par Description:
  /// Creates a new listener of Dbm events.
  /// \param[in] groupName The name of the group which identifies the subscription.
  /// \param[in] period The waiting time in seconds before triggering a new comparison.
  /// \param[in] dataset A set of Dbm points for which a subscription will be made.
  /// \param[in] resetGroup Indicates whether the group must be removed if already exists.
  SCSCtlEventListener() {}
  virtual ~SCSCtlEventListener() {}
  /// \par Description:
  /// Handles a Dbm event.
  /// \param[in] event The Dbm event.
  virtual void handleCTLEvent(SCSCtlEvent* event) = 0;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSCTLEVENTLISTENER_H
