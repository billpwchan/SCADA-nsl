// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSDpcServer.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSDPCSERVER_H
#define SCSCLIENT_SCSDPCSERVER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSServer.h>
// ----------------------------------------------------------------------------
class DpcEqpServer;
// ----------------------------------------------------------------------------
/// \class SCSDpcServer
/// \brief Dpc server services.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSDpcServer : public SCSServer {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft service. Its value is unique and identifies this service among all others Scadasoft services.
  enum Type { scs_type = 8 };
  /// \par Description:
  /// Creates a new Scadasoft server services.
  /// \param[in] envname The Scadasoft server environment name.
  /// \param[in] servername The Scadasoft service name.
  SCSDpcServer(const char* envname, const char* servername);
  virtual ~SCSDpcServer();
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
  /// Changing the integer value of a variable.
  /// \param[in] variableName The name of the variable to be modified.
  /// \param[in] newStatus The new status value.
  /// \param[in] newValue The new integer value.
  /// \param[in] source The source.
  /// \return The operation result.
  int changeVarForce(const char* variableName,
                    unsigned int newStatus,
                    int newValue,
                    const char* source = NULL);
  /// \par Description:
  /// Changing the float value of a variable.
  /// \param[in] variableName The name of the variable to be modified.
  /// \param[in] newStatus The new status value.
  /// \param[in] newValue The new float value.
  /// \param[in] source The source.
  /// \return The operation result.
  int changeVarForce(const char* variableName,
                    unsigned int newStatus,
                    float newValue,
                    const char* source = NULL);
  /// \par Description:
  /// Changing the string value of a variable.
  /// \param[in] variableName The name of the variable to be modified.
  /// \param[in] newStatus The new status value.
  /// \param[in] newValue The new string value.
  /// \param[in] valueSize The length of the string value.
  /// \param[in] source The source.
  /// \return The operation result.
  int changeVarForce(const char* variableName,
                    unsigned int newStatus,
                    unsigned char* newValue,
                    int valueSize,
                    const char* source = NULL);
  /// \par Description:
  /// Changing the status of a variable.
  /// \param[in] variableName The name of the variable to be modified.
  /// \param[in] newStatus The new status value.
  /// \param[in] source The source.
  /// \return The operation result.
  int changeVarStatus(const char* variableName,
                    unsigned int newStatus,
                    const char* source = NULL);
  /// \par Description:
  /// Changing the status of an equipment.
  /// \param[in] equipmentName The name of the equipment to be modified.
  /// \param[in] newStatus The new status value.
  /// \param[in] source The source.
  /// \return The operation result.
  int changeEqpStatus(const char* equipmentName,
                    unsigned int newStatus,
                    const char* source = NULL);
                    
  int changeEqpTag(const char    *equipmentName,
                   unsigned int  newStatus,
                   const char* source = NULL,
                   const char* taggingLabel1 = NULL,
                   const char* taggingLabel2 = NULL);
                         
  /// \par Description:
  /// Returns the type of this Scadasoft service.
  /// \return The value of the type.
  virtual int serverType() const { return scs_type; }

protected:
  SCSDpcServer() {}
  SCSDpcServer(const SCSDpcServer&) {}
  virtual void changeState();

private:
  class SCSDpcServerImpl;
  SCSDpcServerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSDPCSERVER_H
