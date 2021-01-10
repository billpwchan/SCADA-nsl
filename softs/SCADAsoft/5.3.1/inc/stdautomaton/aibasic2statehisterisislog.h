/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : aibasic2statehisterisislog.h                         */
/*  FULL NAME       : AIBasic2StateHisterisislog                           */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : LEY K.L.   	                                   */
/*  COMPANY         : SYSECA                                               */
/*  CREATION DATE   : 26 05 2003                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  AI value automaton with 2 states, histerisis and with log event        */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes AIBasic2StateHisterisisLog's interface.            */
/***************************************************************************/

#ifndef _BS_AIBASIC2STATEHISTERISISLOG_HEADER_
#define _BS_AIBASIC2STATEHISTERISISLOG_HEADER__

#include "aibasic2statehisterisis.h"

class ALMSTDAUT_API AIBasic2StateHisterisisLog : public AIBasic2StateHisterisis
{

 public:
  AIBasic2StateHisterisisLog(const AlmInteger64  inAutoId,
			     const DbkAddressId* inDbkAdddressid);
  ~AIBasic2StateHisterisisLog();
  
 private:
  CREATOR_H(AIBasic2StateHisterisisLog)
};
#endif   /* _BS_AIBASIC2STATEHISTERISISLOG_HEADER_ */


