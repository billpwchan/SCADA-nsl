// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSDacSimEventListener.h
// Date     : 2013/01/15
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSDACSIMEVENTLISTENER_H
#define SCSCLIENT_SCSDACSIMEVENTLISTENER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSEventListener.h>
// ----------------------------------------------------------------------------
class SCSDacSimEvent;
// ----------------------------------------------------------------------------
/// \class SCSDacEventListener
/// \brief Abstract class for Dac events listener.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSDacSimEventListener : public SCSEventListener {
public:
  /// \par Description:
  /// Creates a new event listener
  /// \param[in] varSpec Pattern matching EOV to monitor
  SCSDacSimEventListener(const char* varSpec);
  virtual ~SCSDacSimEventListener();
  /// \par Description:
  /// Handles a event.
  /// \param[in] event The event.
  virtual void handleDacSimEvent(SCSDacSimEvent* event) = 0;
  
  const char* getVarSpec() const;

private:
  SCSDacSimEventListener();
  class SCSDacSimEventListenerImpl;
  SCSDacSimEventListenerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSDACSIMEVENTLISTENER_H
