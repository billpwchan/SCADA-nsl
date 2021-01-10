// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSEventListener.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSEVENTLISTENER_H
#define SCSCLIENT_SCSEVENTLISTENER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSDef.h>
#include <scsclient/SCSResource.h>
// ----------------------------------------------------------------------------
/// \class SCSEventListener
/// \brief Main class for events listeners.
/// 
/// All sub classes have to implement an handleEvent method to treat the events.
// ----------------------------------------------------------------------------
class SCSEventListener : public SCSResource {
public:
  /// \par Description:
  /// Creates a new listener of events.
  SCSEventListener() : m_sync(false) {}
  /// \par Description:
  /// Creates a new listener of events.
  /// \param[in] sync Indicates whether the listener must be synchronized.
  SCSEventListener(bool sync) : m_sync(sync) {}
  /// \par Description:
  /// Indicates whether the listener is synchronized.
  /// \return True if the listener is synchronized, false otherwise.
  bool isSync() const { return m_sync; }

  /// \par Description:
  /// Set the environment name from which the event is triggered.
  /// \param[in] envname The environment name.
  void setEnvironmentName(const char* envname) { if (envname) m_envname = envname; }
  /// \par Description:
  /// Return the environment name from which the event is triggered.
  const char* getEnvironmentName() const { return m_envname.c_str(); }
  /// \par Description:
  /// Set the service name from which the event is triggered.
  /// \param[in] srvname The service name.
  void setServerName(const char* srvname) { if (srvname) m_srvname = srvname; }
  /// \par Description:
  /// Return the service name from which the event is triggered.
  const char* getServerName() const { return m_srvname.c_str(); }
  
protected:
  virtual ~SCSEventListener() {}

private:
  bool m_sync;
  std::string m_envname;
  std::string m_srvname;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSEVENTLISTENER_H
