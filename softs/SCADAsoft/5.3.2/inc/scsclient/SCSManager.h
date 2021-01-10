// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSManager.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSAPI_SCSMANAGER_H
#define SCSAPI_SCSMANAGER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSDef.h>
#include <scstimer.h>
// ----------------------------------------------------------------------------
class AscManager;
class SCSTimerEventListener;
class SCSFactory;
class SCSServer;
class SCSServerStateEventListener;

// ----------------------------------------------------------------------------
/// \class SCSManager
/// \brief Scadasoft services manager.
/// 
/// There is only one instance of  this class (singleton).
/// Provides several methods for life cycle of services.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSManager {
public:
  /// \par Description:
  /// Instance accessor
  /// \return The single instance.
  static SCSManager* Instance();
  /// \par Description:
  /// Service key generation. The key is unique and is used to retrieve a service.
  /// \param[in] remEnvName The Scadasoft server environment name.
  /// \param[in] remSrvName The Scadasoft service name.
  /// \param[in] remSrvType The type of service (see class #SCSServer and its descendents).
  /// \return The key corresponding to the service parameters.
  static std::string GetServerKey(const char* remEnvName, const char* remSrvName, int remSrvType);
  virtual ~SCSManager();
  
  class ASCStateListener {
  public:
    /// \par Description:
    /// Class
    /// \param[in] srv The service for which the state changed.
    virtual void changeState(const char* newState) = 0;
  };
  /// \par Description:
  /// Creates and initializes the client connection to the Scadasoft server.
  /// \param[in] locEnvName The physical client environment name.
  /// \param[in] locSrvName The logical client name.
  /// \return The Scadasoft service.
  void initAsServer(const char* locEnvName, const char* locSrvName, ASCStateListener* lstner);
  /// \par Description:
  /// Retrieves a service. The service is created if it not yet exists.
  /// \param[in] remEnvName The Scadasoft server environment name.
  /// \param[in] remSrvName The Scadasoft service name.
  /// \param[in] remSrvType The type of service (see class #SCSServer and its descendents).
  /// \return The Scadasoft service or null whether the parameters are invalid.
  SCSServer* getServer(const char* remEnvName, const char* remSrvName, int remSrvType);
  /// \par Description:
  /// Removes a service. The service is disconnected if needed.
  /// \param[in] remEnvName The Scadasoft server environment name.
  /// \param[in] remSrvName The Scadasoft service name.
  /// \param[in] remSrvType The type of service (see class #SCSServer and its descendents).
  /// \return True if operation success, false otherwise.
  bool removeServer(const char* remEnvName, const char* remSrvName, int remSrvType);
  /// \par Description:
  /// Disconnects the client from the Scadasoft server.
  void exit();
  /// \par Description:
  /// Start the listening Scadasoft events loop.
  void mainloop();
  /// \par Description:
  /// Stop the listening Scadasoft events loop.
  void stopLoop();
  /// \par Description:
  /// Treats the first Scadasoft event (if any).
  /// return false if event loop has been stopped
  bool updateEventLoop();
  /// \par Description:
  /// Sets the Scadasoft service factory.
  void setFactory(SCSFactory* factory);
  /// \par Description:
  /// Gets the associated AscManager.
  /// \return The associated AscManager.
  AscManager* getAscManager() const;
  /// \par Description:
  /// Creates a timer event and links it to the given listener.
  /// \param delay The delay to wait before triggering the timer.
  /// \param period The period of time in seconds before adding a new timer event.
  /// \param lstner The associated listener which treats the timer events.
  void createTimer(unsigned int delay, unsigned int period, SCSTimerEventListener* lstner);

  const char* getState() const;
  const char* addStateListener(const char* env, const char* srvname, SCSServerStateEventListener* l);
  void removeStateListener(const char* env, const char* srvname, SCSServerStateEventListener* l);
  
protected:
  SCSManager();
  
private:
  class SCSManagerImpl;
  SCSManagerImpl* m_impl;
  SCSFactory* m_factory;
};
// ----------------------------------------------------------------------------
#endif // SCSAPI_SCSMANAGER_H
