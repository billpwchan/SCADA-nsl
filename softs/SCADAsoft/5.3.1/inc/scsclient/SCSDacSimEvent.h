// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSDacSimEvent.h
// Date     : 2013/01/15
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSDACSIMEVENT_H
#define SCSCLIENT_SCSDACSIMEVENT_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSEvent.h>
#include <scsclient/SCSDacSimEventListener.h>
// ----------------------------------------------------------------------------
class DacEOV;
// ----------------------------------------------------------------------------
/// \class SCSDacEvent
/// \brief Dac server event.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSDacSimEvent : public SCSEvent {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft event. Its value is unique and identifies this service among all others Scadasoft events.
  enum Type { scs_type = 6 };
  /// \par Description:
  /// Creates a new event
  /// \param[in] nb The size of the EOV table.
  /// \param[in] EOVs The EOV table wich contains data to build the event.
  /// \param[in] own Indicates whether the table must be owned by the event.
  SCSDacSimEvent(int nb, DacEOV* eovs, bool own);
  virtual ~SCSDacSimEvent();
  /// \par Description:
  /// Listener accessor.
  /// \return The associated events listener.
  SCSDacSimEventListener* getDacSimListener() const { return (SCSDacSimEventListener*)getListener(); }
  /// \par Description:
  /// EOV table accessor.
  /// \return The EOV table from which this event was created.
  DacEOV* getDacEOVs() const { return m_EOVs; }
  /// \par Description:
  /// EOV table size.
  /// \return The size of the EOV table.
  int getNbEOV() const { return m_nbEOV; }
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
  virtual int size() const { return m_nbEOV; }
  
private:
  DacEOV* m_EOVs;
  int m_nbEOV;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSDACSIMEVENT_H
