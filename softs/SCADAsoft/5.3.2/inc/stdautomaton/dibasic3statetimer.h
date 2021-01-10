/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : dibasic3statetimer.h                                 */
/*  FULL NAME       : DIBasic3StateTimer                                   */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : LEY K.L.   	                                   */
/*  COMPANY         : SYSECA                                               */
/*  CREATION DATE   : 26 05 2003                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  DI value automaton with 3 states                                       */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes DIBasic3StateTimer's interface.                    */
/***************************************************************************/

#ifndef _BS_DIBASIC3STATETIMER_HEADER_
#define _BS_DIBASIC3STATETIMER_HEADER_

#include "scsbasicdivalueautomaton.h"
#include "scsbasicstatetimer.h"

class ALMSTDAUT_API DIBasic3StateTimer : public ScsBasicDIValueAutomaton,
			   public ScsBasicState,
			   public ScsBasicStateTimer
{
 public:
  DIBasic3StateTimer(const AlmInteger64  inAutoId,
		     const DbkAddressId* inDbkAdddressid);
  DIBasic3StateTimer(const DIBasic3StateTimer & inValueAuto);

  ~DIBasic3StateTimer();
  
  virtual int    BSFire(long inNewValue);
  virtual int    BSReset();
  int getPS()    {return PS;}
  virtual void   timerCallback ();
  virtual void * getAutomatonTimerPointer() const;

  // redondancy: sauvegarde
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream);
  // redondancy: restauration
  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream);

 private:
  CREATOR_H(DIBasic3StateTimer)
  int PS;
  int NS;
  long m_previousValue;
};

#endif   /* _BS_DIBASIC3STATETIMER_HEADER_ */


