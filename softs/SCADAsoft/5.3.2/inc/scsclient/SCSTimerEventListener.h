// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSTimerEventListener.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSTIMEREVENTLISTENER_H
#define SCSCLIENT_SCSTIMEREVENTLISTENER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSEventListener.h>
// ----------------------------------------------------------------------------
class SCSTimerEvent;
class ScsTimer;
// ----------------------------------------------------------------------------
/// \class SCSTimerEventListener
/// \brief Timer events listener.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSTimerEventListener : public SCSEventListener {
public:
  /// \par Description:
  /// Creates a new listener of timer events.
  SCSTimerEventListener();
  virtual ~SCSTimerEventListener();
  /// \par Description:
  /// Handles a timer event.
  /// \param[in] event A timer event to treat. 
  virtual void handleTimerEvent(SCSTimerEvent* event) = 0;
  /// \par Description:
  /// Sets the timer.
  /// \param[in] timer The associated timer. 
  void setTimer(ScsTimer* timer);
  /// \par Description:
  /// Stops and removes the timer.
  void cancelTimer();
 
private:
  ScsTimer* m_timer;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSTIMEREVENTLISTENER_H
