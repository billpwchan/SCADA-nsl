// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSGenericServer.h
// Date     : 2014/01/28
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSGENERICSERVER_H
#define SCSCLIENT_SCSGENERICSERVER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSServer.h>
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
/// \class SCSGenericServer
/// \brief Connect to any server just to monitor its state.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSGenericServer : public SCSServer {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft service. Its value is unique and identifies this service among all others Scadasoft services.
  enum Type { scs_type = 10 };
  /// \par Description:
  /// Creates a new Scadasoft server services.
  /// \param[in] envname The Scadasoft server environment name.
  /// \param[in] servername The Scadasoft service name.
  SCSGenericServer(const char* envname, const char* servername);
  virtual ~SCSGenericServer();
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
  /// Returns the type of this Scadasoft service.
  /// \return The value of the type.
  virtual int serverType() const { return scs_type; }
  
protected:
  SCSGenericServer() {}
  SCSGenericServer(const SCSGenericServer&) {}
  virtual void changeState();

private:
  class SCSGenericServerImpl;
  SCSGenericServerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSGENERICSERVER_H
