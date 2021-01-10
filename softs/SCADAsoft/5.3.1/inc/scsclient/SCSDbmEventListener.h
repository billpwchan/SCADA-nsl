// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSDbmEventListener.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSDATABASEEVENTLISTENER_H
#define SCSCLIENT_SCSDATABASEEVENTLISTENER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSEventListener.h>
// ----------------------------------------------------------------------------
#include <vector>
// ----------------------------------------------------------------------------
class SCSDbmEvent;
class DbmDataSet;
// ----------------------------------------------------------------------------
/// \class SCSDbmEventListener
/// \brief Abstract class for Dbm events listener.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSDbmEventListener : public SCSEventListener {
public:
  /// \struct SCSDbmEventListener::DBConnection
  /// \par Description:
  /// Data base connection parameters.
  /// \li m_address is the data base address (point) for which a connection will be established.
  /// \li m_id is the connection identification.
  struct DBConnection {
    std::string m_address;
    int m_id;
  };
  /// \par Description:
  /// Creates a new listener of Dbm events.
  /// \param[in] groupName The name of the group which identifies the subscription.
  /// \param[in] period The waiting time in seconds before triggering a new comparison.
  /// \param[in] dataset A set of Dbm points for which a subscription will be made.
  /// \param[in] resetGroup Indicates whether the group must be removed if already exists.
  SCSDbmEventListener(const char* groupName, int period, const std::vector<DBConnection*>& dataset, bool resetGroup);
  virtual ~SCSDbmEventListener();
  /// \par Description:
  /// Handles a Dbm event.
  /// \param[in] event The Dbm event.
  virtual void handleDBEvent(SCSDbmEvent* event) = 0;
  /// \par Description:
  /// Set the group name.
  /// \param[in] groupName The new group name.
  void setName(const char* groupName);
  /// \par Description:
  /// Get the group name.
  /// \return The group name.
  const char* getName() const;
  
#if SCS_INTEGER_VERSION >= 5030000L
  /// \par Description:
  /// Set subscription period in milliseconds.
  /// This call must be made before the call to SCSDbmPoller::subscribe
  /// \param[in] period The new period in milliseconds.
  void setPeriodMS(unsigned int period);
  /// \par Description:
  /// Get subscription period in milliseconds.
  /// \return period in ms.
  unsigned int getPeriodMS() const;
#else
  /// \par Description:
  /// Set subscription period in seconds.
  /// This call must be made before the call to SCSDbmPoller::subscribe
  /// \param[in] period The new period in seconds.
  void setPeriod(unsigned int period);
  /// \par Description:
  /// Get subscription period in seconds.
  /// \return period in ms.
  unsigned int getPeriod() const;
#endif
  
  /// \par Description:
  /// Get the associated dataset.
  /// \return The dataset.
  DbmDataSet* getDataSet();
  /// \par Description:
  /// Indicates whether the group must be removed before the subscription.
  /// \return True is the group must be removed, false otherwise.
  bool isResetGroup() const { return m_resetGroup; }
 
private:
  SCSDbmEventListener();
  class SCSDbmEventListenerImpl;
  SCSDbmEventListenerImpl* m_impl;
  bool m_resetGroup;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSDATABASEEVENTLISTENER_H
