// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSOlsEvent.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSOLSEVENT_H
#define SCSCLIENT_SCSOLSEVENT_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSEvent.h>
#include <scsclient/SCSOlsEventListener.h>
// ----------------------------------------------------------------------------
class OlsDataSet;
// ----------------------------------------------------------------------------
/// \class SCSOlsEvent
/// \brief Ols server event.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSOlsEvent : public SCSEvent {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft event. Its value is unique and identifies this service among all others Scadasoft events.
  enum Type { scs_type = 4 };
  /// \par Description:
  /// Creates a new event defined by a dataset.
  /// \param dataset The dataSet from which the event keeps a copy.
  SCSOlsEvent(const OlsDataSet& dataset);
  /// \par Description:
  /// Creates a new event without dataset to notify that the list must emptied.
  /// This happens in case the notification dataset is lost (bas sequence).
  /// The client must clean its list, and wait for a refresh
  SCSOlsEvent();
  /// \par Description:
  /// Destructor
  virtual ~SCSOlsEvent();
  /// \par Description:
  /// Listener accessor.
  /// \return The associated events listener.
  SCSOlsEventListener* getOLSListener() const { return (SCSOlsEventListener*)getListener(); }
  /// \par Description:
  /// Dataset accessor.
  /// \return The dataset associated with this event.
  OlsDataSet* getDataSet() const { return m_dataset; }
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
  OlsDataSet* m_dataset;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSOLSEVENT_H
