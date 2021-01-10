// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright (C) THALES.
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
class OlsDataSet;
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
  /// \return The result of the operation (value 0 means OK).
  virtual int subscribe(SCSOlsEventListener* lstner);
  /// \par Description:
  /// Unsubscription to a Dbm addresses (points) through a listener.
  /// \param[in] lstner The listener which contains the Dbm addresses.
  /// \return The operation result (value 0 means OK).
  virtual int unsubscribe(SCSOlsEventListener* lstner);
  /**
     \par Description:
     read in the remote list all the data matching the filter. If a name is specified in the filter, then the read method will try to retrieve a registered filter. Otherwise, the read method will apply the filter as is.
     \param listName  [in]: name of the remote list,
     \param[in] fieldList list of OlsField to get from server.
     \param[in] nbfields size of fieldList array, 0 means all fields
     \param[in] filter The filter.
     \param result  [out]: set of OlsData objects containing the read values.
     \return The result of the operation (value 0 means OK).
  */
  virtual int read(const char* listName, const char** fieldList, int nbfields, const char* filter, OlsDataSet*& result);
  /**
     \par Description:
     Delete entries in the remote list.
     
     \param[in] listName: name of the remote list,
     \param[in] keyList array of ID of OlsData to be deleted
     \param[in] nbKeys size of keyList array

     \return The result of the operation (value 0 means OK).
  */
  virtual int deleteEntries(const char* listName, int* keyList, int nbKeys);
  /**
     \par Description:
     Update entries in the remote list. This method can update several entries at the same time.
     The fields to be updated are the same for all entries, but value of filed can be different
     for different entries. The size of valueList array is nbKeys x nbFields
     Values are text, so the OlsField real type will be used to convert from text to actual type
     using classical (strtol for int, strtod for float)
     
     \param[in] listName: name of the remote list,
     \param[in] keyList array of ID of OlsData to be updated
     \param[in] nbKeys size of keyList array
     \param[in] fieldList array of OlsFields name to be updated
     \param[in] nbFields size of fieldList array
     \param[in] valueList array of values as text
     
     \return The result of the operation (value 0 means OK).
  */
  virtual int updateEntries(const char* listName, int* keyList, const char** fieldList, const char** valueList, int nbKeys, int nbFields);
  /**
     \par Description:
     Add a new entry in the remote list.
     fieldList and valueList array must have the same size (nbFields).
     For data conversion see updateEntries.
     
     \param[in] listName: name of the remote list,
     \param[in] fieldList array of OlsFields name to be updated
     \param[in] nbFields size of fieldList array
     \param[in] valueList array of values as text
     
     \return The result of the operation (value 0 means OK).
  */
  virtual int createEntry(const char* listName, const char** fieldList, const char** valueList, int nbFields);
  
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
