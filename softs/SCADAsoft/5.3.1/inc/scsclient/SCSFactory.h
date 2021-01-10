// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSFactory.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_FACTORY_H
#define SCSCLIENT_FACTORY_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSDef.h>
// ----------------------------------------------------------------------------
class SCSServer;
// ----------------------------------------------------------------------------
/// \class SCSFactory
/// \brief Scadasoft client servers factory.
/// 
/// Standard class for the creation of instances of services classes.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSFactory {
public:
  /// \par Description:
  /// Creates a new factory.
  SCSFactory();
  /// \par Description:
  /// Creates a Scadasoft service.
  /// \param[in] envname The Scadasoft server environment name.
  /// \param[in] servername The Scadasoft service name.
  /// \param[in] type The type of service (see class #SCSServer and its descendents).
  /// \return The Scadasoft service.
  virtual SCSServer* createServer(const char* envname, const char* servername, int type);
};
// ----------------------------------------------------------------------------
#endif /* ! SCSCLIENT_FACTORY_H */
