/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : ackshelvetimerlog.h                                  */
/*  FULL NAME       : AckShelveTimerLog                                    */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : ESA   	                                           */
/*  COMPANY         : Thales Transportation Systems                        */
/*  CREATION DATE   : 30 04 2008                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  Ack with automatic unshelve with log                                   */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes AckShelveTimerLog's interface.                     */
/***************************************************************************/
#ifndef _ACKSHELVETIMER_LOG_HEADER_
#define _ACKSHELVETIMER_LOG_HEADER_

#include "ackshelvetimer.h"

class ALMSTDAUT_API AckShelveTimerLog : public AckShelveTimer
{
 public:
  AckShelveTimerLog (const AlmInteger64  inAutoId,
	      const DbkAddressId* inDbkAddressId);
  AckShelveTimerLog (const AckShelveTimerLog &  inAckShelveTimerLog);
  ~AckShelveTimerLog();
  
 private:
  CREATOR_H(AckShelveTimerLog)
};

#endif // _ACKSHELVETIMER_LOG_HEADER_
