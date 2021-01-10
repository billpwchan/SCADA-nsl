/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : aibasic3statetimerhisterisislog.h                    */
/*  FULL NAME       : AIBasic3StateTimerHisterisislog                      */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : LEY K.L.   	                                   */
/*  COMPANY         : SYSECA                                               */
/*  CREATION DATE   : 26 05 2003                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  AI value automaton with 2 states, histerisis and with log when         */
/*  acknowledge                                                            */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes AIBasic3StateTimerHisterisisLog's interface.       */
/***************************************************************************/

#ifndef _BS_AIBASIC3STATETIMERHISTERISISLOG_HEADER_
#define _BS_AIBASIC3STATETIMERHISTERISISLOG_HEADER_

#include "aibasic3statetimerhisterisis.h"

class ALMSTDAUT_API AIBasic3StateTimerHisterisisLog : public AIBasic3StateTimerHisterisis
{

 public:
  AIBasic3StateTimerHisterisisLog(const AlmInteger64  inAutoId,
				  const DbkAddressId* inDbkAdddressid);
  ~AIBasic3StateTimerHisterisisLog();
  
 private:
  CREATOR_H(AIBasic3StateTimerHisterisisLog)
};
#endif   /* _BS_DIBASIC2STATELOG_HEADER_ */


