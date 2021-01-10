// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSDbmEvent.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSDBMEVENT_H
#define SCSCLIENT_SCSDBMEVENT_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSEvent.h>
#include <scsclient/SCSDbmEventListener.h>
// ----------------------------------------------------------------------------
class DbmDataSet;
// ----------------------------------------------------------------------------
/// \class SCSDbmEvent
/// \brief Dbm server event.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSDbmEvent : public SCSEvent {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft event. Its value is unique and identifies this service among all others Scadasoft events.
  enum Type { scs_type = 3 };
  /// \par Description:
  /// Creates a new event
  /// \param[in] dataSet The dataset for which the event is created.
  SCSDbmEvent(const DbmDataSet& dataSet);
  virtual ~SCSDbmEvent();
  /// \par Description:
  /// Listener accessor.
  /// \return The associated events listener.
  SCSDbmEventListener* getDBListener() const { return (SCSDbmEventListener*)getListener(); }
  /// \par Description:
  /// Dbm dataset accessor.
  /// \return The Dbm dataset from which this event was created.
  DbmDataSet* getDataSet() const { return m_dataset; }
  /// \par Description:
  /// Executes the treatment of this event.
  virtual void execute();
  /// \par Description:
  /// Returns the type of this Scadasoft event.
  /// \return The value of the type.
  virtual int eventType() const { return scs_type; }

  /// \par Description:
  /// Returns the size of the event in number of element.
  /// \return event size.
  virtual int size() const;
  
private:
  DbmDataSet* m_dataset;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSDBMEVENT_H
