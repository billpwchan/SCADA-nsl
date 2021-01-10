/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsbasicstatetimer.h                                 */
/*  FULL NAME       : ScsBasicStateTimer                                   */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : LEY K.L.   	                                   */
/*  COMPANY         : SYSECA                                               */
/*  CREATION DATE   : 02 06 2003                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  value automaton with states and timer                                  */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsBasicStateTimer's interface.                    */
/***************************************************************************/

#ifndef _BS_SCSBASICSTATETIMER_HEADER_
#define _BS_SCSBASICSTATETIMER_HEADER_

#include "alm/scsbasicstate.h"
#include "alm/scsautomatontimer.h"

/* class ScsBasicStateTimer : public ScsBasicState, */
/* 			   public ScsAutomatonTimer */
class ALMAUT_API ScsBasicStateTimer : public ScsAutomatonTimer
{
 public:
  ScsBasicStateTimer(const AlmInteger64 inAutoId);
  ~ScsBasicStateTimer();
  
  virtual void timeout();
  virtual void timerCallback()=0;

  // redondancy: sauvegarde
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream);
  // redondancy: restauration
  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream);

 private:
/*   long _wakeUpTimer; */
};
#endif   /* _BS_SCSBASICSTATETIMER_HEADER_ */


