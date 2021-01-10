// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSDacEvent.h
// Date     : 2011/12/05
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSDACEVENT_H
#define SCSCLIENT_SCSDACEVENT_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSEvent.h>
#include <scsclient/SCSDacEventListener.h>
// ----------------------------------------------------------------------------
class DacEIV;
// ----------------------------------------------------------------------------
/// \class SCSDacEvent
/// \brief Dac server event.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSDacEvent : public SCSEvent {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft event. Its value is unique and identifies this service among all others Scadasoft events.
  enum Type { scs_type = 5 };
  /// \par Description:
  /// Creates a new event
  /// \param[in] nb The size of the EIV table.
  /// \param[in] eivs The EIV table wich contains data to build the event.
  /// \param[in] own Indicates whether the table must be owned by the event.
  SCSDacEvent(int nb, DacEIV* eivs, bool own = false);
  virtual ~SCSDacEvent();
  /// \par Description:
  /// Listener accessor.
  /// \return The associated events listener.
  SCSDacEventListener* getDACListener() const { return (SCSDacEventListener*)getListener(); }
  /// \par Description:
  /// EIV table accessor.
  /// \return The EIV table from which this event was created.
  DacEIV* getDacEIVs() const { return m_eivs; }
  /// \par Description:
  /// EIV table size.
  /// \return The size of the EIV table.
  int getNbEIV() const { return m_nbEiv; }
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
  DacEIV* m_eivs;
  int m_nbEiv;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSDACEVENT_H
