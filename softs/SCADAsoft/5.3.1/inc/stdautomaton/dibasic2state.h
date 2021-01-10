/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : dibasic2state.h                                      */
/*  FULL NAME       : DIBasic2State                                        */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : LEY K.L.   	                                   */
/*  COMPANY         : SYSECA                                               */
/*  CREATION DATE   : 26 05 2003                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  DI value automaton with 2 states                                       */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes DIBasic2State's interface.                         */
/***************************************************************************/

#ifndef _BS_DIBASIC2STATE_HEADER_
#define _BS_DIBASIC2STATE_HEADER_

#include "scsbasicstate.h"
#include "scsbasicdivalueautomaton.h"

class ALMSTDAUT_API DIBasic2State : public ScsBasicDIValueAutomaton, public ScsBasicState
{

 public:
  DIBasic2State (const AlmInteger64    inAutoId,
		 const DbkAddressId *  inDbkAdddressid);
  DIBasic2State (const DIBasic2State & inValueAuto); 
  ~DIBasic2State ();
  
  virtual int BSFire(long inNewValue);
  virtual int BSReset();
  
  int getPS() {return PS;}

  // redondancy: sauvegarde
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream);
  // redondancy: restauration
  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream);

 private:
  CREATOR_H(DIBasic2State)
  int  PS;
  int  NS;
  long m_previousValue;
};

#endif   /* _BS_DIBASIC2STATE_HEADER_ */


