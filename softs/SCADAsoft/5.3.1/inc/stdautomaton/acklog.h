/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : acklog.h                                             */
/*  FULL NAME       : AckLog                                               */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : LEY K.L.   	                                   */
/*  COMPANY         : SYSECA                                               */
/*  CREATION DATE   : 17 06 2003                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  Ack without log                                                        */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes AckLog's interface.                                */
/***************************************************************************/
#ifndef _ACK_LOG_HEADER_
#define _ACK_LOG_HEADER_
 
#include "ack.h"

class ALMSTDAUT_API AckLog: public Ack 
{
 public:
  AckLog (const AlmInteger64  inAutoId,
	  const DbkAddressId* inDbkAddressId);
  AckLog (const AckLog &      inAckLog);
  ~AckLog ();

 private:
  CREATOR_H(AckLog)
};

#endif // _ACK_LOG_HEADER_

 
