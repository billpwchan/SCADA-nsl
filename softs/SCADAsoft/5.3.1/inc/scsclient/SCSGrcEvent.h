// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSGrcEvent.h
// Date     : 2015/10/12
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSGRCEVENT_H
#define SCSCLIENT_SCSGRCEVENT_H
// ----------------------------------------------------------------------------

#include <scsclient/SCSEvent.h>
#include <scsclient/SCSGrcEventListener.h>


// Possible values for stepCompletionStatus

// for isBasicStep == 1 -- Step status
#define BRCSTEP_STATUS_NotExecuted 1
#define BRCSTEP_STATUS_Completed 2
#define BRCSTEP_STATUS_Failed 3
#define BRCSTEP_STATUS_Skipped 4

// for isBasicStep == 0 -- GRC global status
#define GRCSTEP_STATUS_Terminated  1
#define GRCSTEP_STATUS_WaitForRun 2
#define GRCSTEP_STATUS_Initializing 3
#define GRCSTEP_STATUS_Running 4
#define GRCSTEP_STATUS_Waiting 5
#define GRCSTEP_STATUS_Stopped 6
#define GRCSTEP_STATUS_Aborted 7
#define GRCSTEP_STATUS_Suspended 8
#define GRCSTEP_STATUS_Resuming 9
 
  
// ----------------------------------------------------------------------------
/// \class SCSGrcEvent
/// \brief Grc server event.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSGrcEvent : public SCSEvent {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft event. Its value is unique and identifies this 
  /// service among all others Scadasoft events.
  enum Type { scs_type = 12 };
  
  /// \par Description:
  /// Creates a new event
  SCSGrcEvent(const char *grcName, int isBasicStep, int stepCompletionStatus, int stepNumber)
   : m_grcName(grcName), m_isBasicStep(isBasicStep), m_stepCompletionStatus(stepCompletionStatus), m_step(stepNumber) {}
  
  virtual ~SCSGrcEvent();
  
  const char* getGrcName() const { return m_grcName.c_str(); }
  
  int getStepNumber() const { return m_step; }
  int getStepCompletionStatus() const { return m_stepCompletionStatus; }
  int isBasicStep() const { return m_isBasicStep; }
  
  /// \par Description:
  /// Listener accessor.
  /// \return The associated events listener.
  SCSGrcEventListener* getGrcListener() const { return (SCSGrcEventListener*)getListener(); }
       
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
  std::string m_grcName;
  int m_isBasicStep;
  int m_stepCompletionStatus;
  int m_step;
};

// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSGRCEVENT_H
