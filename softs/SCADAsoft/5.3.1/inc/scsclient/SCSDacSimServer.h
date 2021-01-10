// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSDacSimServer.h
// Date     : 2013/01/15
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCS_SCSDACSIMSERVER_H
#define SCS_SCSDACSIMSERVER_H
// ----------------------------------------------------------------------------
#include <vector>
// ----------------------------------------------------------------------------
#include <scsclient/SCSServer.h>
// ----------------------------------------------------------------------------
class DacSimulator;
class DacEIV;
class DacEOV;
class SCSDacSimEventListener;
// ----------------------------------------------------------------------------
/// \class SCSDacSimServer
/// \brief DacSimulator services.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSDacSimServer : public SCSServer {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft service. Its value is unique and identifies this service among all others Scadasoft services.
  enum Type { scs_type = 9 };
  /// \par Description:
  /// Creates a new Scadasoft server services.
  /// \param[in] envname The Scadasoft server environment name.
  /// \param[in] servername The Scadasoft service name.
  SCSDacSimServer(const char* envname, const char* servername);
  virtual ~SCSDacSimServer();
  /// \par Description:
  /// Tries to establish a connection to the Scadasoft server.
  /// \param[in] direct Indicates whether or not the connection must be direct.
  /// \return The operation result (true means a success, false otherwise).
  virtual bool connect(bool direct = false);
  /// \par Description:
  /// Tries to close the connection to the Scadasoft server.
  /// \return The operation result (true means a success, false otherwise).
  virtual bool disconnect();
  
  int readExtVar(const char* varSpec, std::vector<DacEIV*>& eivList, std::vector<DacEOV*>& eovList) const;
                   
#if SCS_INTEGER_VERSION >= 5020001L  
  int writeExtVar(std::vector<DacEIV*> eivList, std::vector<DacEOV*> eovList);
#else
  int writeExtVar(const char* varSpec, const ScsData& data, const unsigned long sec, const unsigned long usec);
#endif
    
  int subscribeEOV(SCSDacSimEventListener* lstner);
  int unSubscribeEOV(SCSDacSimEventListener* lstner);
                         
  /// \par Description:
  /// Returns the type of this Scadasoft service.
  /// \return The value of the type.
  virtual int serverType() const { return scs_type; }
  /// \par Description:
  /// Returns the native SCADAsoft server.
  /// \return The SCADAsoft server.
  DacSimulator* getDacSimServer() const;

protected:
  SCSDacSimServer() {}
  SCSDacSimServer(const SCSDacSimServer&) {}
  virtual void changeState();

private:
  class SCSDacSimServerImpl;
  SCSDacSimServerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCS_SCSDACSIMSERVER_H
