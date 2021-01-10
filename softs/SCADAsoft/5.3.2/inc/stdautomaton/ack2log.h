/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : ack2log.h                                             */
/*  FULL NAME       : Ack2Log                                               */
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
/*  This file describes Ack2Log's interface.                                */
/***************************************************************************/
#ifndef _ACK2_LOG_HEADER_
#define _ACK2_LOG_HEADER_
 
#include "ack2.h"

class ALMSTDAUT_API Ack2Log: public Ack2 
{
 public:
  Ack2Log (const AlmInteger64  inAutoId,
	  const  DbkAddressId* inDbkAddressId);
  Ack2Log (const Ack2Log &     inAck2Log);
  ~Ack2Log ();

 private:
  CREATOR_H(Ack2Log)
};

#endif // _ACK2_LOG_HEADER_

 
