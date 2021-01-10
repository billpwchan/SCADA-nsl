// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSCtlServer.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCS_SCSCTLSERVER_H
#define SCS_SCSCTLSERVER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSServer.h>
// ----------------------------------------------------------------------------
class CtlCmdServer;
class SCSCtlEventListener;

// ----------------------------------------------------------------------------
/// \class SCSCtlServer
/// \brief Control command server services.
/// 
/// Standard class for sending commands toward equipments.
/// It provides several methods to send a command.
/// The arguments are one or several points in the database and a value which can be an integer, a float or a string.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSCtlServer : public SCSServer {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft service. Its value is unique and identifies this service among all others Scadasoft services.
  enum Type { scs_type = 7 };
  /// \par Description:
  /// Creates a new Scadasoft server services.
  /// \param[in] envname The Scadasoft server environment name.
  /// \param[in] servername The Scadasoft service name.
  SCSCtlServer(const char* envname, const char* servername);
  virtual ~SCSCtlServer();
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
  /// Sends one or more commands with an integer value.
  /// \param[in] names The commands table.
  /// \param[in] size The commands table size.
  /// \param[in] value The integer value.
  /// \param[in] source The source.
  /// \param userArg The user argument.
  /// \return The operation result.
  int sendCommand(const char* names[],
                  int size,
                  int value,
                  const char* source = NULL,
                  SCSCtlEventListener* listener = NULL);
  int sendCommandExt(const char* names[],
                    int size,
                    int value,
                    int bypassInitCond, int bypassRetCond, int sendAnyway,
                    const char* source = NULL,
                    SCSCtlEventListener* listener = NULL);
                  
                  
  /// \par Description:
  /// Sends one or more commands with a float value.
  /// \param[in] names The commands table.
  /// \param[in] size The commands table size.
  /// \param[in] value The float value.
  /// \param[in] source The source.
  /// \param userArg The user argument.
  /// \return The operation result.
  int sendCommand(const char* names[],
                  int size,
                  float value,
                  const char* source = NULL,
                  SCSCtlEventListener* listener = NULL);
  int sendCommandExt(const char* names[],
                    int size,
                    float value,
                    int bypassInitCond, int bypassRetCond, int sendAnyway,
                    const char* source = NULL,
                    SCSCtlEventListener* listener = NULL);
                    
  /// \par Description:
  /// Sends one or more commands with a string value.
  /// \param[in] names The commands table.
  /// \param[in] size The commands table size.
  /// \param[in] value The string value.
  /// \param[in] len The length of the string value.
  /// \param[in] source The source.
  /// \param userArg The user argument.
  /// \return The operation result.
  int sendCommand(const char* names[],
                  int size,
                  const char* value,
                  int len,
                  const char* source = NULL,
                  SCSCtlEventListener* listener = NULL);
  int sendCommandExt(const char* names[],
                    int size,
                    const char* value,
                    int len,
                    int bypassInitCond, int bypassRetCond, int sendAnyway,
                    const char* source = NULL,
                    SCSCtlEventListener* listener = NULL);
                    
  /// \par Description:
  /// Returns the type of this Scadasoft service.
  /// \return The value of the type.
  virtual int serverType() const { return scs_type; }

protected:
  SCSCtlServer() {}
  SCSCtlServer(const SCSCtlServer&) {}
  virtual void changeState();

private:
  class SCSCtlServerImpl;
  SCSCtlServerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCS_SCSCTLSERVER_H
