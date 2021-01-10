/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : aibasic2statehisterisis.h                            */
/*  FULL NAME       : AIBasic2StateHisterisis                              */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : LEY K.L.   	                                   */
/*  COMPANY         : SYSECA                                               */
/*  CREATION DATE   : 26 05 2003                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  AI value automaton with 2 states and histerisis                        */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes AIBasic2StateHisterisis's interface.               */
/***************************************************************************/

#ifndef _BS_AIBASIC2STATEHISTERISIS_HEADER_
#define _BS_AIBASIC2STATEHISTERISIS_HEADER_

#include "scsmonobasicstateaihisterisis.h"

class ALMSTDAUT_API AIBasic2StateHisterisis : public ScsMonoBasicStateAIHisterisis
{
 public:
  AIBasic2StateHisterisis (const AlmInteger64    inAutoId,
			   const DbkAddressId *  inDbkAdddressid);
  AIBasic2StateHisterisis (const AIBasic2StateHisterisis & inValueAuto); 
  ~AIBasic2StateHisterisis ();
  
  virtual int BSFire(double inNewValue);
  virtual int BSReset();
  
  int getPS() {return PS;}

  // redondancy: sauvegarde
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream);
  // redondancy: restauration
  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream);

 private:
  CREATOR_H(AIBasic2StateHisterisis)
  int PS;
  int NS;
  double m_previousValue;
};

#endif   /* _BS_AIBASIC2STATEHISTERISIS_HEADER_ */


