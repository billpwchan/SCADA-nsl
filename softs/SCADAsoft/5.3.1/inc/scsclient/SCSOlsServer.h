// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSOlsServer.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSJS_SCSOLSSERVER_H
#define SCSJS_SCSOLSSERVER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSServer.h>
// ----------------------------------------------------------------------------
class OlsServer;
class SCSOlsEventListener;
// ----------------------------------------------------------------------------
/// \class SCSOlsServer
/// \brief Ols server services.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSOlsServer : public SCSServer {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft service. Its value is unique and identifies this service among all others Scadasoft services.
  enum Type { scs_type = 4 };
  /// \par Description:
  /// Creates a new Scadasoft server services.
  /// \param[in] envname The Scadasoft server environment name.
  /// \param[in] servername The Scadasoft service name.
  SCSOlsServer(const char* envname, const char* servername);
  virtual ~SCSOlsServer();
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
  /// Subscription to a Dbm addresses (points) through a listener.
  /// \param[in] lstner The listener which contains the Dbm addresses.
  /// \return The result of the operation (value -1 means NOK).
  virtual int subscribe(SCSOlsEventListener* lstner);
  /// \par Description:
  /// Unsubscription to a Dbm addresses (points) through a listener.
  /// \param[in] lstner The listener which contains the Dbm addresses.
  /// \return The operation result.
  virtual int unsubscribe(SCSOlsEventListener* lstner);
  /// \par Description:
  /// Returns the type of this Scadasoft service.
  /// \return The value of the type.
  virtual int serverType() const { return scs_type; }
 
protected:
  SCSOlsServer() {}
  SCSOlsServer(const SCSOlsServer&) {}
  virtual void changeState();
      
private:
  class SCSOlsServerImpl;
  SCSOlsServerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCSJS_SCSOLSSERVER_H
