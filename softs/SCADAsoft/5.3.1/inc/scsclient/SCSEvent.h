// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSEvent.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSEVENT_H
#define SCSCLIENT_SCSEVENT_H
// ----------------------------------------------------------------------------
// timeval definition
#ifdef WIN32
#include <WinSock2.h>
#else
#include <sys/time.h>
#endif

// ----------------------------------------------------------------------------
#include <string>
// ----------------------------------------------------------------------------
#include <scsclient/SCSDef.h>
#include <scsclient/SCSResource.h>
// ----------------------------------------------------------------------------
class SCSEventListener;
// ----------------------------------------------------------------------------
/// \class SCSEvent
/// \brief Abstract class for events.
/// 
/// All sub classes have to implement the execute method.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSEvent  : public SCSResource {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft event. Its value is unique and identifies this service among all others Scadasoft events.
  enum Type { scs_type = 1 };
  /// \enum EventState
  /// \par Description:
  /// Defines the state of the event.
  enum EventState {
    EventInit = 0,
    EventWaiting = 1,
    EventProcessing = 2,
    EventExecuted = 3
  };
  /// \par Description:
  /// Creates a new event
  SCSEvent();
  /// \par Description:
  /// Set the environment name from which the event is triggered.
  /// \param[in] envname The environment name.
  void setEnvironmentName(const char* envname);
  /// \par Description:
  /// Return the environment name from which the event is triggered.
  const char* getEnvironmentName() const { return m_envname.c_str(); }
  /// \par Description:
  /// Set the service name from which the event is triggered.
  /// \param[in] srvname The service name.
  void setServerName(const char* srvname);
  /// \par Description:
  /// Return the service name from which the event is triggered.
  const char* getServerName() const { return m_srvname.c_str(); }
  /// \par Description:
  /// Set the service type from which the event is triggered.
  /// \param[in] srvtype The service type. (see class #SCSServer and its descendents).
  void setServerType(int srvtype);
  /// \par Description:
  /// Return the service type from which the event is triggered.
  int getServerType() const { return m_srvtype; }
  /// \par Description:
  /// Set the events listener.
  /// \param[in] lstner The new events listener.
  void setListener(SCSEventListener* lstner);
  /// \par Description:
  /// Listener accessor.
  /// \return The associated events listener.
  SCSEventListener* getListener() const { return m_listener; }
  /// \par Description:
  /// Set the time of this event.
  /// \param[in] tv The new time.
  void setTime(timeval tv);
  /// \par Description:
  /// Get the time.
  /// \return The time of this event.
  timeval getTime() const { return m_time; }
  /// \par Description:
  /// Set the state of this event.
  /// \param[in] state The new state.
  void setState(EventState state) { m_state = state; }
  /// \par Description:
  /// Get the state.
  /// \return The state of this event.
  EventState getState() const { return m_state; }
  /// \par Description:
  /// Executes the treatment of this event. Set the state to EventExecuted.
  virtual void execute() = 0;
  /// \par Description:
  /// Returns the type of this Scadasoft event.
  /// \return The value of the type.
  virtual int eventType() const { return scs_type; }

  /// \par Description:
  /// Returns the size of the event in number of element.
  /// \return event size.
  virtual int size() const = 0;
  
protected:
  virtual ~SCSEvent();

private:
  SCSEventListener* m_listener;
  std::string m_envname;
  std::string m_srvname;
  int m_srvtype;
  timeval m_time;
  EventState m_state;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSEVENT_H
