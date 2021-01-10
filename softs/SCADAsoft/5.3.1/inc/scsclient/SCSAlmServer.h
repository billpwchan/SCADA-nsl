// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSAlmServer.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSALMSERVER_H
#define SCSCLIENT_SCSALMSERVER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSServer.h>
// ----------------------------------------------------------------------------
class ScsAlmServer;
// ----------------------------------------------------------------------------
/// \class SCSAlmServer
/// \brief Alarms server services.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSAlmServer : public SCSServer {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft service. Its value is unique and identifies this service among all others Scadasoft services.
  enum Type { scs_type = 6 };
  /// \par Description:
  /// Creates a new Scadasoft server services.
  /// \param[in] envname The Scadasoft server environment name.
  /// \param[in] servername The Scadasoft service name.
  SCSAlmServer(const char* envname, const char* servername);
  virtual ~SCSAlmServer();
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
  /// Acknowledgment of alarms.
  /// \param[in] alarmIdList The identities table of alarms which have to be acknowledged.
  /// \param[in] idCount The alarms identities table size.
  /// \param[in] source The source.
  /// \param[in] inUserId The user identification.
  /// \return The operation result. 
  int acknowledgeAlarm(int* alarmIdList, short idCount, const char* source, int inUserId = 0);
  /// \par Description:
  /// Shelve alarms.
  /// \param[in] alarmIdList The identities table of alarms which have to be shelved.
  /// \param[in] idCount The alarms identities table size.
  /// \param[in] source The source.
  /// \param[in] inUserId The user identification.
  /// \return The operation result. 
  int shelveAlarm(int*  alarmIdList, short idCount, const char* source, int inUserId = 0);
  
#if SCS_INTEGER_VERSION >= 5020001L
  /// \par Description:
  /// Unshelving alarms.
  /// \param[in] alarmIdList The identities table of alarms which have not to be shelved any longer.
  /// \param[in] idCount The alarms identities table size.
  /// \param[in] source The source.
  /// \param[in] inUserId The user identification.
  /// \return The operation result. 
  int unshelveAlarm(int*  alarmIdList, short idCount, const char* source, int inUserId = 0);
#endif
  
  /// \par Description:
  /// Returns the type of this Scadasoft service.
  /// \return The value of the type.
  virtual int serverType() const { return scs_type; }
  /// \par Description:
  /// User name accessor.
  /// \return The user name.
  const char* getUserName();
  /// \par Description:
  /// Set the user name.
  /// \param[in] newName The user name.
  void setUserName(const char* newName);

  /// \par Description:
  /// API to notify external alarms.
  /// \param[in] configFileName The configuration file name.
  /// \param[in] classId The external alarm class identifier.
  /// \param[in] pointAlias Equipment address in RTDB
  /// \param[in] objectId used if pointAlias is "" for alarm not linked to RTDB equipment
  /// \param[in] extSourceId (default 0)
  ///            identification number (0-31) of the client application component 
  ///            (used to elaborate the unique external alarm identification number)
  /// \param[in] isAlarm Alarm state 0:Normal 1:Alarm
  /// \param[in] message Alarm text (for i18n this is only the parameters part used to format message at HMI level)
  /// \return The operation result. 
  int notifyExternalAlarm(const char* configFileName, int classId, const char* pointAlias,
                          int objectId, int extSourceId, int isAlarm, const char* message);

  /// \par Description:
  ///  API to notify external events.
  /// \param[in] almserverHandle handle to C++ Alarm Server client object
  /// \param[in] configFileName The configuration file name.
  /// \param[in] classId The external event class identifier.
  /// \param[in] pointAlias Equipment address in RTDB
  /// \param[in] objectId used if pointAlias is "" for alarm not linked to RTDB equipment
  /// \param[in] extSourceId (default 0)
  ///            identification number (0-31) of the client application component 
  ///            (used to elaborate the unique external alarm identification number)
  /// \param[in] message Event text (for i18n this is only the parameters part used to format message at HMI level)
  /// \return The operation result. 
  int notifyExternalEvent(const char* configFileName, int classId, const char* pointAlias,
                          int objectId, int extSourceId, const char* message);
  
  /**
     this function gets the format of the message.
     Do not use this function, it is not documented and not supported function (for affairs). Internal use is authorized only for SCADAsoft.
     classId : identification number (0-999) of the alarm class (used to elaborate the unique external alarm identification number),
     objectState : object state (ALMEXT_OBJ_STATE_NORMAL or ALMEXT_OBJ_STATE_ERROR) determining which alarm attributes of the configuration file will be used,
     message : the alarm message to return.

     return:
     ScsValid : success.
     AlmBadParamError : the value of an input parameter is not correct.
     AlmInternalError : no configuration data were found for specified alarm class.
     AlmRtapFunctionError : error reading database using Rtap.
     AlmScadasoftFunctionError : error reading database using DbmServer or calling <em>notify()</em> function of alarm server.
  */
  const char* getMessageFormat(const char* configFileName, int classId, int isAlarm);

protected:
  SCSAlmServer() {}
  SCSAlmServer(const SCSAlmServer&) {}
  virtual void changeState();

private:
  class SCSAlmServerImpl;
  SCSAlmServerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSALMSERVER_H
