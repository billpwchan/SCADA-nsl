// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSServer.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSSERVER_H
#define SCSCLIENT_SCSSERVER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSDef.h>
#include <scsclient/SCSResource.h>
// ----------------------------------------------------------------------------
/// \class SCSServer
/// \brief Abstract class for Scadasoft services.
/// 
///  The methods connect and disconnect have to be implemented by the sub classes.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSServer : public SCSResource {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft service. Its value is unique and identifies this service among all others Scadasoft services.
  enum Type { scs_type = 1 };
  /// \enum State
  /// \par Description:
  /// Defines the state of the Scadasoft service.
  enum State {
    /// The service is not initialized.
    NotInitialized,
    /// The service is connected.
    Up,
    /// The service is disconnected.
    Down
  };
  /// \class StateListener
  /// \par Description:
  /// State listener for Scadasoft service.
  class StateListener {
  public:
    /// \par Description:
    /// Treats the state change.
    /// \param[in] srv The service for which the state changed.
    virtual void changeState(SCSServer* srv) = 0;
  };
  /// \par Description:
  /// Gives the service name.
  /// \return The service name.
  const char* getServerName() const;
  /// \par Description:
  /// Gives the environment name.
  /// \return The environment name.
  const char* getEnvironmentName() const;
  /// \par Description:
  /// Gives the service state.
  /// \return The service state.
  SCSServer::State getState() const;
  /// \par Description:
  /// Gives the name of the service state.
  /// \return The name of the service state.
  const char* getStateName() const;
  /// \par Description:
  /// Adds a state listener.
  /// \param[in] lstner The state listener to add.
  void addStateListener(SCSServer::StateListener* lstner);
  /// \par Description:
  /// Removes a state listener.
  /// \param[in] lstner The state listener to remove.
  void removeStateListener(SCSServer::StateListener* lstner);
  /// \par Description:
  /// Tries to establish a connection to the Scadasoft server.
  /// \param[in] direct Indicates whether or not the connection must be direct.
  /// \return The operation result (true means a success, false otherwise).
  virtual bool connect(bool direct = false) = 0;
  /// \par Description:
  /// Tries to close the connection to the Scadasoft server.
  /// \return The operation result (true means a success, false otherwise).
  virtual bool disconnect() = 0;
  /// \par Description:
  /// Returns the type of this Scadasoft service.
  /// \return The value of the type.
  virtual int serverType() const { return scs_type; }

protected:
  SCSServer() {}
  SCSServer(const SCSServer&) {}
  SCSServer(const char* envname, const char* servername);
  virtual ~SCSServer();
    
  void setState(SCSServer::State s);
  void setStateName(const char* n);

  State subscribeState();
  void unsubscribeState();
  virtual void changeState() = 0;

private:
  class SCSServerImpl;
  friend class SCSServer::SCSServerImpl;
  SCSServerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSSERVER_H
