// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSDacEventListener.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSDACEVENTLISTENER_H
#define SCSCLIENT_SCSDACEVENTLISTENER_H
// ----------------------------------------------------------------------------
#include <vector>
#include <string>
// ----------------------------------------------------------------------------
#include <dac.h>
#include <scsclient/SCSEventListener.h>
// ----------------------------------------------------------------------------
class SCSDacEvent;
// ----------------------------------------------------------------------------
/// \class SCSDacEventListener
/// \brief Abstract class for Dac events listener.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSDacEventListener : public SCSEventListener {
public:
  /// \par Description:
  /// Creates a new event listener
  /// \param[in] evnames The set of EIV names for which the listener is created.
  SCSDacEventListener(const std::vector<std::string>& evnames);
  virtual ~SCSDacEventListener();
  /// \par Description:
  /// Handles a event.
  /// \param[in] event The event.
  virtual void handleDacEvent(SCSDacEvent* event) = 0;
  /// \par Description:
  /// Set the subscription ID.
  /// \param[in] id The subscription ID.
  void setSubID(int id);
  /// \par Description:
  /// Get the subscription ID.
  /// \return The subscription ID.
  int getSubID() const;
  /// \par Description:
  /// Get the size of the table of EIV names.
  /// \return The size of the table of EIV names.
  int getEIVCount() const;
  /// \par Description:
  /// Get the table of EIV names.
  /// \return The table of EIV names.
  DacEVName* getEIVNames() const;

private:
  SCSDacEventListener();
  class SCSDacEventListenerImpl;
  SCSDacEventListenerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSDACEVENTLISTENER_H
