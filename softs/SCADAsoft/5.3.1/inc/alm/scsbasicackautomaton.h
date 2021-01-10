/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsbasicackautomaton.h                               */
/*  FULL NAME       : ScsBasicAckAutomaton                                 */
/*-------------------------------------------------------------------------*/
/*  COMPANY         : THALES IS                                            */
/*  CREATION DATE   : Fri December 08 2000                                 */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                      */
/*  All rights reserved.                                                   */
/*                                                                         */
/*  Unauthorized access, use, reproduction or distribution is prohibited.  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  ScsBasicAckAutomaton is the root class for all the acknowledge automate*/
/*  behaviour.                                                             */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsBasicAckAutomaton is an abstract class for acknowledge automaton    */
/*  used in the alarm server.                                              */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsBasicAckAutomaton's interface.                  */
/***************************************************************************/

// Revision 3.11.0  2002/02/24 KLL
// FFT SCADAsoft-180 - Performance du serveur d'alarmes

// Revision 3.14.0  2003/06/17 KLL
// ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
//           nouveau noyau

#ifndef _SCSBASICACKAUTOMATON_H
#define _SCSBASICACKAUTOMATON_H

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

#include "alm/scsbasicautomaton.h"
#include "alm/scsbasicvalueautomaton.h"

#include "scs.h"

class ALMAUT_API ScsBasicAckAutomaton: public ScsBasicAutomaton
{
  //KLL - 23/01/03/ - FFT SRC 413 - superUserId
  friend class ScsAlarm;

  // METHODS
 public:

  enum LogFrom
    {
      NEW_VALUE,
      ACK,
      SHELVE,
      UNSHELVE,
      UNKNOWN
    };

  ScsBasicAckAutomaton(const AlmInteger64  inAutoId,
		       const DbkAddressId* inResultAddress);
  ScsBasicAckAutomaton(const ScsBasicAckAutomaton& inAutomaton );
  virtual ~ScsBasicAckAutomaton() = 0;

  // return the acknowledged status.
  virtual int getStatus() const;
  // return the shelve status.
  int getShelved() const;

  // tests if the automaton is being acknowledged.
  int isAcknowledged() const;
  // tests if the automaton is being shelved.
  int isShelved() const;

  // acknowledge the automaton.
  int acknowledge(const long inUserId = 0);
  // shelve the automaton.
  int shelve(const long inUserId = 0);
  // unshelve the automaton.
  int unshelve(const long inUserId = 0);

  // hide the automaton.
  void hide();
  // show the automaton.
  void show();
  // tests if the automaton is being hidden.
  int isHidden() const;

  // link with the associated value automaton.
  void setValueAutomaton( ScsBasicValueAutomaton* inValueAutomaton );
  // get the associated value automaton
  ScsBasicValueAutomaton* getValueAutomaton();
  // set the new value domain.
  void setNewAlarmState(const int  inNewAlarmState,
			int&       outAckStatus,
			int&       ioSeverity,
			const long inUserId=0);

  // redondancy: sauvegarde
  virtual ScsStatus	save	(SCS_SL_STD(ostream)&	outStream) = 0;
  // redondancy: restauration
  virtual ScsStatus	restore	(SCS_SL_STD(istream)&	inStream) = 0;

  // return the key of the current alarm.
  virtual long getAlmId();
  // add or set an alarm key
  virtual void setAlmId(const long inAlmId);
  // remove an alarmkey
  virtual void removeAlmId(const long inAlmId);

  // AlarmList message
  void setStartMsg(const char* inPrologue);
  const char* getStartMsg() const;
  void setEndMsg(const char* inEpilogue);
  const char* getEndMsg() const;
  char* createAlmListMsg(const char* inCorps = NULL) const;
  void updateAlmListMsg(const char* inCorps = NULL);

  // Alarm: start and end
  // set clearing links of two acknowledged automatons
  static  void OffClearing(ScsBasicAckAutomaton* iopPrecAck,
			  ScsBasicAckAutomaton* iopCurrAck);
  // set arbitrary the link with start or end alarm ack automaton
  inline void setOffClearing(const int iNewAlarmPosition,
			     ScsBasicAckAutomaton* iopLinkedAckAuto = NULL)
    {
      _alarmposition = iNewAlarmPosition;
      if (iNewAlarmPosition == _START_ALARM)
	_pEndAckAutomaton = iopLinkedAckAuto;
      else if (iNewAlarmPosition == _END_ALARM)
	_pStartAckAutomaton = iopLinkedAckAuto;
    }
  // get the acknowledment automaton of start alarm
  inline ScsBasicAckAutomaton *	getStartAlarmAck() const
    {
      return _pStartAckAutomaton;
    };
  // get the acknowledment automaton of end alarm
  inline ScsBasicAckAutomaton *	getEndAlarmAck() const
    {
      return _pEndAckAutomaton;
    };
  // get the position of the current acknowledment automaton
  inline int getAlarmPosition() const
    {
      return _alarmposition;
    }

  //KLL - 23/01/03/ - FFT SRC 413 - superUserId
  static  long GetSuperUserId ();
 
  // KLL - 24/02/2003 - FFT SCADAsoft 180 - Performance AlmServer
  int getFlagAttributsModify() const;
  virtual void unsetFlagAttributsModify();
  virtual void setFlagAttributsModify();
  
  // get ScsAutomatonTimer pointer
  virtual void* getAutomatonTimerPointer() const;

 protected:
  // default constructor
  ScsBasicAckAutomaton();

  // set equipment name
  virtual void setEquipmentName(const char* inEquipmentName);
  // set categories
  virtual void setCategories(const int inFunctionalCategory,
			     const int inGeographicalCategory);
  // set theme
  virtual void setTheme(const int inTheme );

  virtual int BSFire(const int inNewAlarmState,
		     int& ioSeverity,
		     const int inAcknowledgedRequest,
		     int& outNewAckStatus,
		     const int inShelvedRequest,
		     int& outNewShelvedStatus,
		     const long inUserId) = 0;

  // Updates the automaton the new value domain.
  virtual void update(const int inNewAlarmState,
		      int& ioSeverity,
		      int& outNewAckStatus,
		      int&  outNewShelveStatus,
		      const long inUserId = 0)
    {
      BSFire(inNewAlarmState,ioSeverity,_ERROR,outNewAckStatus,_ERROR,outNewShelveStatus,inUserId);
    };
  // update the automaton the new ack status.
  virtual void ackUpdate(const int inNewAckStatus,
			 int&  ioSeverity,
			 int&  outNewAckStatus,
			 int&  outNewShelveStatus,
			 const long inUserId)
    {
      if (getValueAutomaton() != NULL)
        BSFire(_ERROR,ioSeverity,inNewAckStatus,outNewAckStatus,_ERROR,outNewShelveStatus,inUserId);
    };
  // update the automaton the new shelved status.
  inline virtual void shelveUpdate(const int inNewShelveStatus,
				   int&  ioSeverity,
				   int&  outNewAckStatus,
				   int&  outNewShelveStatus,
				   const long inUserId)
    {
      if (getValueAutomaton() != NULL)
        BSFire(_ERROR,ioSeverity,_ERROR,outNewAckStatus,inNewShelveStatus,outNewShelveStatus,inUserId);
    };

  // reset the automaton
  virtual int BSReset();

  /// ESA - 19/06/2006 - PCR PCC 185 + ML2 84
  virtual void LogEvent(LogFrom);

 private:
  //KLL - 23/01/03/ - FFT SRC 413 - superUserId
  static  void SetSuperUserId (const long inSuperUserId);

// FIELDS
 public:
  static  const int _ERROR;
  // acknowledged status
  static  const int _ACKNOWLEDGED;
  // shelved status
  static  const int _SHELVED;

  // Starting alarm value
  static  const int _START_ALARM;
  // Ending alarm value
  static  const int _END_ALARM;

 private:
  // almId
  long _almId;
  // acknowledged state of the automaton
  int _acknowledged;
  // shelved state of the automaton
  int _shelved;
  // value automaton associated
  ScsBasicValueAutomaton*  _pValueAutomaton;
  // start/end alarm ack
  int _alarmposition;
  ScsBasicAckAutomaton* _pStartAckAutomaton;
  ScsBasicAckAutomaton* _pEndAckAutomaton;
  // AlarmList Message
  char* _prologueMsg;
  char* _epilogueMsg;

  //KLL - 23/01/03/ - FFT SRC 413 - superUserId
  static  long _SuperUserId;

  // KLL - 24/02/2003 - FFT SCADAsoft 180 - Performance AlmServer
  int _flagAttributsModify;
};

#endif // _SCSBASICACKAUTOMATON_H

// end of file scsbasicackautomaton.h
