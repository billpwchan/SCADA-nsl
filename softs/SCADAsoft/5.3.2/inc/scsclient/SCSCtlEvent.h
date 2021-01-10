// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSCtlEvent.h
// Date     : 2012/03/20
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSCTLEVENT_H
#define SCSCLIENT_SCSCTLEVENT_H
// ----------------------------------------------------------------------------
#include <vector>
#include <string>

#include <scs.h>
#include <scsclient/SCSEvent.h>
#include <scsclient/SCSCtlEventListener.h>

// ----------------------------------------------------------------------------
/// \class SCSCtlEvent
/// \brief Ctl server event.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSCtlEvent : public SCSEvent {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft event. Its value is unique and identifies this 
  /// service among all others Scadasoft events.
  enum Type { scs_type = 4 };
  
  /// \par Description:
  /// Creates a new event
  /// \param[in] dataSet The dataset for which the event is created.
  SCSCtlEvent(const char *commandName,
              ScsStatus returnStatus, long nbInfo,
              long *valStatus, char **textStatus);
  virtual ~SCSCtlEvent();
  
  /// \par Description:
  /// Listener accessor.
  /// \return The associated events listener.
  SCSCtlEventListener* getCtlListener() const { return (SCSCtlEventListener*)getListener(); }
  
  const char* getCommandName() const { return m_commandName.c_str(); }
  
  ScsStatus getStatus() const { return m_returnStatus; }
  
  std::vector<std::string>& getTextStatusList() { return m_textStatus; }
  
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
  virtual int size() const { return 1; }
  
private:
  std::string m_commandName;
  ScsStatus   m_returnStatus;
  std::vector<std::string> m_textStatus;
};

// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSCTLEVENT_H
