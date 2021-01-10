/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*  FILE            : scsautomatontimer.h                                  */
/*  FULL NAME       : ScsAutomatonTimer                                    */
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
/*  ScsAutomatonTimer is the root class for all the automate behaviour.    */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsAutomatonTimer is an abstract class for automaton used in the alarm */
/*  server.                                                                */
/*  pure virtual method                                                    */
/*                    ~ScsAutomatonTimer ()                                */
/*    void            registerMyself     ()                                */
/*    const ScsStatus save               ( ostream &outStream )            */
/*    const ScsStatus restore            ( istream &inStream )             */
/*    void            timeout            ()                                */
/*                                                                         */
/*    const int       BS_Fire            () const                          */
/*                                                                         */
/*  The automatons are created by an instance of ScsAutomatonFactory.      */
/*  This factory is, in fact, a proxy. To register an automaton class,     */
/*  an instance, as static field, of ScsAutomatonCreator is needed.        */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsAutomatonTimer's interface.                     */
/*.........................................................................*/

// Revision 3.11.0  2003/03/04 KLL
// FFT SRC-475 - Mauvaise fonctionnement des automates avec timer

// Revision 3.14.0  2003/05/28 KLL
// ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
//           nouveau noyau

#ifndef _SCSAUTOMATONTIMER_H
#define _SCSAUTOMATONTIMER_H

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

#include "scs.h"
#include "scsalm.h"


class ScsTimer;
class ScsAutomatonTimer;

class ALMAUT_API ScsAutomatonTimer
{
 public:
  ScsAutomatonTimer(const AlmInteger64 inAutoId);
  ScsAutomatonTimer(const AlmInteger64 inAutoId,
		    const unsigned int inTimeout);
  ScsAutomatonTimer(const AlmInteger64 inAutoId,
		    const unsigned int inTimeout,
		    const unsigned int inPeriod);
  ScsAutomatonTimer(const ScsAutomatonTimer& inAutomaton);
  virtual ~ScsAutomatonTimer() = 0;

  // arm the timer.
  virtual ScsStatus armTimer();
  // cancel the timer.
  virtual ScsStatus cancelTimer();
  // test if the timer expired.
  int hasTimerExpired();
  // return the next expiration time.
  timeval getWakeUpTime();
  // set the expiration time in seconds, the first if periodic.
  void setTimeout(const unsigned int inTimeout );
  // return the expiration time in milliseconds, the first if periodic.
  unsigned int getTimeout() const;
  // set the period.
  void setPeriod( const unsigned int inPeriod );
  // return the period.
  unsigned int getPeriod() const;
  // KLL - 04/03/2003 - FFT SRC 475 - 
  //       Mauvaise fonctionnement des automates avec timer 
  // get _pTimer
  ScsTimer * getTimer() const;

  // Kll - 2003/06/20 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  void * getTimerPointer() const; 

  // redondancy
  // serialize instance
  virtual ScsStatus	save	(SCS_SL_STD(ostream)&	outStream) = 0;
  // deserialize instance
  virtual ScsStatus	restore	(SCS_SL_STD(istream)&	inStream) = 0;

 protected:
  // default constructor
  ScsAutomatonTimer();
  // callback executed when timer expired; implemented by users.
  virtual void timeout() = 0;

 private:
  // is calling by the timer when time is out.
  static  void WakeUpCallBack(void *arg );

  // FIELDS
 public:
  static  const int _TIME_NOTEXPIRED;
  static  const int _TIME_EXPIRED;

 private:
  // Alarm Identification
  AlmInteger64 _autoId;
  // timer
  ScsTimer*    _pTimer;
  // timer flag
  int          _timeoutflag;
  // the expiration time of the timer, in milliseconds, the first if periodic.
  unsigned int _timeout;
  // the period time of the timer
  unsigned int _period;

};

#endif // _SCSAUTOMATONTIMER_H

// end of file scsautomatontimer.h
