/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : ackshelvetimer.h                                     */
/*  FULL NAME       : AckShelveTimer                                       */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : ESA   	                                           */
/*  COMPANY         : Thales Transportation Systems                        */
/*  CREATION DATE   : 30 04 2008                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  Ack with automatic unshelve without log                                */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes AckShelveTimer's interface.                        */
/***************************************************************************/
#ifndef _ACKSHELVETIMER_HEADER_
#define _ACKSHELVETIMER_HEADER_
 
#include "scsbasicackautomaton.h"
#include "scsautomatontimer.h"

class ALMSTDAUT_API AckShelveTimer : public ScsBasicAckAutomaton,
                       public ScsAutomatonTimer
{
 public:
  AckShelveTimer (const AlmInteger64  inAutoId,
		  const DbkAddressId* inDbkAddressId);
  AckShelveTimer (const AckShelveTimer & inAckShelveTimer);
  ~AckShelveTimer();
  
  virtual int BSFire(const int inNewAlarmState, 
		     int & ioSeverity, 
		     const int inAckRequest, 
		     int & outNewAckState, 
		     const int inShelveRequest, 
		     int & outNewShelveStatus, 
		     const long inUserId);
  virtual void timeout();
  virtual void * getAutomatonTimerPointer() const;
  
  // redondancy
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream);
  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream);
  
 private:
  CREATOR_H(AckShelveTimer)
  // current timer manager
  int _profile;
};

#endif // _ACKSHELVETIMER_HEADER_
