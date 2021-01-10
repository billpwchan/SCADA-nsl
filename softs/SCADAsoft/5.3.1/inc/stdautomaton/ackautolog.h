/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : ackautolog.h                                         */
/*  FULL NAME       : AckAutoLog                                           */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : ESA   	                                           */
/*  COMPANY         : Thales Transportation Systems                        */
/*  CREATION DATE   : 30 04 2008                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  Automatic acknowledgement with log                                     */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes AckAutoLog's interface.                            */
/***************************************************************************/
#ifndef _ACKAUTO_LOG_HEADER_
#define _ACKAUTO_LOG_HEADER_

#include "ackauto.h"

class ALMSTDAUT_API AckAutoLog : public AckAuto
{
 public:
  AckAutoLog (const AlmInteger64  inAutoId,
	      const DbkAddressId* inDbkAddressId);
  AckAutoLog (const AckAutoLog &  inAckAutoLog);
  ~AckAutoLog();
  
 private:
  CREATOR_H(AckAutoLog)
};

#endif // _ACK_LOG_HEADER_
