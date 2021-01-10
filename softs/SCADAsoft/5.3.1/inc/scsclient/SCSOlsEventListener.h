// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSOlsEventListener.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSOLSEVENTLISTENER_H
#define SCSCLIENT_SCSOLSEVENTLISTENER_H
// ----------------------------------------------------------------------------
#include <string>
// ----------------------------------------------------------------------------
#include <scsclient/SCSEventListener.h>
#include <olstypes.h>
// ----------------------------------------------------------------------------
class SCSOlsEvent;
class SCSOlsServer;
// ----------------------------------------------------------------------------
/// \class SCSOlsEventListener
/// \brief Abstract class for Ols server events listener.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSOlsEventListener : public SCSEventListener {
public:
  /// \par Description:
  /// Creates a new listener of Dbm events.
  /// \param[in] listName The name of the list for which the listener is created.
  /// \param[in] fieldList list of OlsField to get from server.
  /// \param[in] nbfield size of fieldList array, 0 means all fields
  /// \param[in] filter The filter.
  SCSOlsEventListener(const char* listName, const char** fieldList, int nbfield, const char* filter = NULL);
  virtual ~SCSOlsEventListener();
  
  /// \par Description:
  /// Handles a Ols event.
  /// \param[in] event The Ols event.
  virtual void handleOlsEvent(SCSOlsEvent* event) = 0;
  /// \par Description:
  /// Sets the name of the list.
  /// \param[in] listName The new name of the list.
  void setListName(const char* listName);
  /// \par Description:
  /// Gets the name of the list.
  /// \return The name of the list.
  const char* getListName() const;
  /// \par Description:
  /// Sets the subscription ID.
  /// \param[in] id The new subscription ID.
  void setSubID(int id);
  /// \par Description:
  /// Gets the the subscription ID.
  /// \return The the subscription ID.
  int getSubID() const;
  /// \par Description:
  /// Gets the the object that manage the communication with the OLS server.
  /// \return The OLS communication object.
  SCSOlsServer* getSCSOlsServer() const;
  /// \par Description:
  /// Sets the the object that manage the communication with the OLS server.
  /// \param[in] The OLS communication object.
  void setSCSOlsServer(SCSOlsServer* olsserver);
  /// \par Description:
  /// Gets the filter.
  /// \return The associated filter.
  OlsFilter& getFilter() const;
  /// \par Description:
  /// Sets the fields from which the listener will be configured.
  /// \param[in] fields The fields table.
  /// \param[in] fieldCount The size of the fields table.
  void setFields(const OlsField* fields, int fieldCount);
  /// \par Description:
  /// Gets the number of fields.
  /// \return The number of fields.
  int getNbFields() const;
  /// \par Description:
  /// Gets the name of the field indexed by the given value.
  /// \param[in] idx The field index.
  /// \return The name whether the index is valid, null otherwise.
  const char* getFieldName(int idx) const;
  /// \par Description:
  /// Gets the type of the field indexed by the given value.
  /// \param[in] idx The field index.
  /// \return The type whether the index is valid, ScsUNKNOWN otherwise.
  ScsType getFieldType(int idx) const;
  /// \par Description:
  /// Gets the name of the field indexed by the given value.
  /// \param[in] listName name of OLS list (should be the same as getListName()).
  /// \param[in] id subscription Id (should be the same as getSubID()).
  virtual void badSequenceOrderNotification(const char* listName, int id);
private:
  SCSOlsEventListener();
  class SCSOlsEventListenerImpl;
  SCSOlsEventListenerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSOLSEVENTLISTENER_H
