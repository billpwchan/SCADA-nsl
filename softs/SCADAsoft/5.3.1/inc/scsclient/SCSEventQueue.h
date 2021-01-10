// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSEventQueue.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSEVENTQUEUE_H
#define SCSCLIENT_SCSEVENTQUEUE_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSDef.h>
#include <scsclient/SCSEvent.h>
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
/// \class SCSEventQueue
/// \brief Singleton dedicated to the storage of incoming events.
/// 
/// This class is the receptor of all the incoming events.
/// Maintains a collection of events and provides several methods to add new events or remove treated ones.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSEventQueue {
public:
  /// \par Description:
  /// Instance accessor
  /// \return The single instance.
  static SCSEventQueue* Instance();
  /// \par Description:
  /// Stores a new event to the bottom of the queue.
  /// \param[in] evt The event which has to be Stored.
  virtual void pushEvent(SCSEvent* evt, unsigned short priority);
  /// \par Description:
  /// Removes the first event from the top of the queue and returns it.
  /// \return The first event of the queue whether exists or null otherwise.
  virtual SCSEvent* popEvent();
  /// \par Description:
  /// Gets the number of stocked events.
  /// \return The number of the stocked events.
  virtual unsigned int nbEvent();
  /// \par Description:
  /// Executes the treatment of the first event (if any).
  virtual bool processOneEvent();
  /// \par Description:
  /// Waits during a given time before trying to treat a new event.
  /// \param[in] ms The time in milliseconds to wait. 
  virtual void waitForEvent(long ms = 0);

  void printStat();
protected:
  SCSEventQueue();
  SCSEventQueue(const SCSEventQueue&);
  virtual ~SCSEventQueue();

private:
  class SCSEventQueueImpl;    
  SCSEventQueueImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSEVENTQUEUE_H
