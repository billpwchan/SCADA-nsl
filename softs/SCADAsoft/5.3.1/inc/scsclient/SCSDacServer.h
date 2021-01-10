// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSDacServer.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSJS_SCSDACSERVER_H
#define SCSJS_SCSDACSERVER_H
// ----------------------------------------------------------------------------
#include <vector>
// ----------------------------------------------------------------------------
#include <scsclient/SCSServer.h>
#include <dac.h>
// ----------------------------------------------------------------------------
class DacServer;
class SCSDacEventListener;
// ----------------------------------------------------------------------------
/// \class SCSDacServer
/// \brief Dac server services.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSDacServer : public SCSServer {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft service. Its value is unique and identifies this service among all others Scadasoft services.
  enum Type { scs_type = 5 };
  /// \par Description:
  /// Creates a new Scadasoft server services.
  /// \param[in] envname The Scadasoft server environment name.
  /// \param[in] servername The Scadasoft service name.
  SCSDacServer(const char* envname, const char* servername);
  virtual ~SCSDacServer();
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
  /// Subscription to a set of EIV names through a listener.
  /// \param[in] lstner The listener which contains the set of EIV names.
  /// \return The result of the operation (value -1 means NOK).
  int subscribe(SCSDacEventListener* lstner);
  /// \par Description:
  /// Unsubscription to a set of EIV names through a listener.
  /// \param[in] lstner The listener which contains the set of EIV names.
  /// \return The operation result.
  int unsubscribe(SCSDacEventListener* lstner);
  /// \par Description:
  /// Write EOV values.
  /// \param[in] eovCount The size of the EOV table.
  /// \param[in] eovList The EOV table.
  /// \param[in, out] statusList The list of resulted statuses.
  /// \return The operation result.
  int sendEOV(unsigned int eovCount, DacEOV* eovList, ScsStatus*& statusList);
  /// \par Description:
  /// Read EIV values.
  /// \param[in] evnames The set of EIV names for which the EIV values will be readed.
  /// \param[in, out] eivList The set of retrieved EIV values.
  /// \return The operation result.
  int getEIV(const std::vector<std::string>& evnames, DacEIV*& eivList);
  /// \par Description:
  /// Invalidates the notifications.
  /// \return The operation result.
  int invalidateNotifications();
  /// \par Description:
  /// Revalidates the notifications.
  /// \return The operation result.
  int revalidateNotifications();
  /// \par Description:
  /// Retrieves the set of subscribers.
  /// \param[in, out] clientList The set of subscribers.
  /// \return The operation result.
  int getSubscriber(std::vector<std::string>& clientList);
  /// \par Description:
  /// Returns the type of this Scadasoft service.
  /// \return The value of the type.
  virtual int serverType() const { return scs_type; }
  /// \par Description:
  /// Returns the native SCADAsoft server.
  /// \return The SCADAsoft server.
  DacServer* getDacServer() const;

protected:
  SCSDacServer() {}
  SCSDacServer(const SCSDacServer&) {}
  virtual void changeState();

private:
  class SCSDacServerImpl;
  SCSDacServerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCSJS_SCSDACSERVER_H
