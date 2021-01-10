/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : dibasic3statetimerlog.h                              */
/*  FULL NAME       : DIBasic3StateTimerlog                                */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : LEY K.L.   	                                   */
/*  COMPANY         : SYSECA                                               */
/*  CREATION DATE   : 26 05 2003                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  DI value automaton with 2 states and with log when acknowledge         */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes DIBasic3StateTimerLog's interface.                 */
/***************************************************************************/

#ifndef _BS_DIBASIC3STATETIMERLOG_HEADER_
#define _BS_DIBASIC3STATETIMERLOG_HEADER_

#include "dibasic3statetimer.h"

class ALMSTDAUT_API DIBasic3StateTimerLog : public DIBasic3StateTimer
{

 public:
  DIBasic3StateTimerLog(const AlmInteger64  inAutoId,
			const DbkAddressId* inDbkAdddressid);
  ~DIBasic3StateTimerLog();
  
 private:
  CREATOR_H(DIBasic3StateTimerLog)
};
#endif   /* _BS_DIBASIC2STATELOG_HEADER_ */


