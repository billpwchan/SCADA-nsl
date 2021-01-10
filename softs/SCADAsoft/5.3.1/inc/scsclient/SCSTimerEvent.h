// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSTimerEvent.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSTIMEREVENT_H
#define SCSCLIENT_SCSTIMEREVENT_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSEvent.h>
#include <scsclient/SCSTimerEventListener.h>
// ----------------------------------------------------------------------------
/// \class SCSTimerEvent
/// \brief Timer event.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSTimerEvent : public SCSEvent {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft event. Its value is unique and identifies this service among all others Scadasoft events.
  enum Type { scs_type = 2 };
  /// \par Description:
  /// Creates a new event
  SCSTimerEvent();
  virtual ~SCSTimerEvent();
  /// \par Description:
  /// Listener accessor.
  /// \return The associated events listener.
  SCSTimerEventListener* getTimerListener() const { return (SCSTimerEventListener*)getListener(); }
  /// \par Description:
  /// Executes the treatment of this event.
  virtual void execute();
  /// \par Description:
  /// Returns the type of this Scadasoft event.
  /// \return The value of the type.
  virtual int eventType() const { return scs_type; }
  /// \par Description:
  /// Returns the size of the event in number of element.
  /// \return event size.
  virtual int size() const { return 1; }
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSTIMEREVENT_H
