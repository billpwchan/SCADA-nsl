// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSServerStateEvent.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSSERVERSTATEEVENT_H
#define SCSCLIENT_SCSSERVERSTATEEVENT_H
// ----------------------------------------------------------------------------
#include <string>
// ----------------------------------------------------------------------------
#include <scsclient/SCSEvent.h>
#include <scsclient/SCSServerStateEventListener.h>
// ----------------------------------------------------------------------------
/// \class SCSServerStateEvent
/// \brief Server connection state event.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSServerStateEvent : public SCSEvent
{
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft event. Its value is unique and identifies this service among all others Scadasoft events.
  enum Type { scs_type = 14 };
  /// \par Description:
  /// Creates an event defined by the given service parameters.
  /// \param[in] envname The Scadasoft server environment name.
  /// \param[in] srvname The Scadasoft service name.
  /// \param[in] srvtype The type of service (see class #SCSServer and its descendents).
  SCSServerStateEvent(const char* envname, const char* srvname);
  virtual ~SCSServerStateEvent();
  /// \par Description:
  /// Sets the service state.
  /// \param[in] state The new state.
  void setState(const char* state) { if (state != NULL) m_state = state; }
  /// \par Description:
  /// Gives the Scadasoft service state.
  /// \return The Scadasoft service state.
  const char* getState() const { return m_state.c_str(); }
  /// \par Description:
  /// Executes the treatment of this event.
  void execute();
  /// \par Description:
  /// Returns the type of this Scadasoft event.
  /// \return The value of the type.
  virtual int eventType() const { return scs_type; }
  /// \par Description:
  /// Listener accessor.
  /// \return The associated events listener.
  SCSServerStateEventListener* getStateListener() const { return (SCSServerStateEventListener*)getListener(); }
  /// \par Description:
  /// Returns the size of the event in number of element.
  /// \return event size.
  virtual int size() const { return 1; }

private:
  std::string m_state;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSSERVERSTATEEVENT_H
