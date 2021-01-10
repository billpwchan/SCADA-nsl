/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : aibasic3statetimerhisterisis.h                       */
/*  FULL NAME       : AIBasic3StateTimerHisterisis                         */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : LEY K.L.   	                                   */
/*  COMPANY         : SYSECA                                               */
/*  CREATION DATE   : 26 05 2003                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  AI value automaton with 3 states and histerisis                        */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes AIBasic3StateTimerHisterisis's interface.          */
/***************************************************************************/

#ifndef _BS_AIBASIC3STATETIMERHISTERISIS_HEADER_
#define _BS_AIBASIC3STATETIMERHISTERISIS_HEADER_

#include "scsmonobasicstateaihisterisis.h"
#include "scsbasicstatetimer.h"

class ALMSTDAUT_API AIBasic3StateTimerHisterisis : public ScsMonoBasicStateAIHisterisis,
				     public ScsBasicStateTimer
{
 public:
  AIBasic3StateTimerHisterisis(const AlmInteger64  inAutoId,
			       const DbkAddressId* inDbkAdddressid);
  AIBasic3StateTimerHisterisis(const AIBasic3StateTimerHisterisis & inValueAuto);

  ~AIBasic3StateTimerHisterisis();
  
  virtual int    BSFire(double inNewValue);
  virtual int    BSReset();
  int getPS()    {return PS;}
  virtual void   timerCallback ();
  virtual void * getAutomatonTimerPointer() const;

  // redondancy: sauvegarde
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream);
  // redondancy: restauration
  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream);

 private:
  CREATOR_H(AIBasic3StateTimerHisterisis)
  int PS;
  int NS;
  double m_previousValue;
};

#endif   /* _BS_AIBASIC3STATETIMERHISTERISIS_HEADER_ */


