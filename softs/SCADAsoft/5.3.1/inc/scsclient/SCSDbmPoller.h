// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSDbmPoller.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSDBMPOLLER_H
#define SCSCLIENT_SCSDBMPOLLER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSServer.h>
// ----------------------------------------------------------------------------
class DbmPoller;
class SCSDbmEventListener;
// ----------------------------------------------------------------------------
/// \class SCSDbmPoller
/// \brief Dbm poller services.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSDbmPoller : public SCSServer {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft service. Its value is unique and identifies this service among all others Scadasoft services.
  enum Type { scs_type = 3 };
  /// \par Description:
  /// Creates a new Dbm server services.
  /// \param[in] envname The Scadasoft server environment name.
  /// \param[in] servername The Scadasoft service name.
  SCSDbmPoller(const char* envname, const char* servername);
  virtual ~SCSDbmPoller();
  /// \par Description:
  /// Tries to establish a connection to the Scadasoft server.
  /// \param[in] direct Indicates whether or not the connection must be direct.
  /// \return The operation result (true means a success, false otherwise).
  virtual bool connect(bool direct = false);
  /// \par Description:
  /// Tries to close the connection to the Scadasoft server.
  /// \return The operation result (true means a success, false otherwise).
  virtual bool disconnect();
  /// \par Description:
  /// Subscription to a Dbm list name through a listener.
  /// \param[in] lstner The listener which contains the Dbm list name.
  /// \return The result of the operation (value -1 means NOK).
  int subscribe(SCSDbmEventListener* lstner);
  /// \par Description:
  /// Unsubscription to a Dbm list name through a listener.
  /// \param[in] lstner The listener which contains the Dbm list name.
  /// \return The operation result.
  int unsubscribe(SCSDbmEventListener* lstner);
  
  int deleteGroup(const char* groupname);
  /// \par Description:
  /// Returns the type of this Scadasoft service.
  /// \return The value of the type.
  virtual int serverType() const { return scs_type; }
 
protected:
  SCSDbmPoller() {}
  SCSDbmPoller(const SCSDbmPoller&) {}
  virtual void changeState();
      
private:
  class SCSDbmPollerImpl;
  SCSDbmPollerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSDBMPOLLER_H
