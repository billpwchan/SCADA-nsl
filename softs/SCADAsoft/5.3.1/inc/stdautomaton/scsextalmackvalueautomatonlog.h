/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsextalmackvalueautomatonlog.h                      */
/*  FULL NAME       : ScsExtAlmAckValueAutomatonLog                        */
/*-------------------------------------------------------------------------*/
/*  COMPANY         : THALES IS                                            */
/*  CREATION DATE   : Wed May 12 2004                                      */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                      */
/*  All rights reserved.                                                   */
/*                                                                         */
/*  Unauthorized access, use, reproduction or distribution is prohibited.  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  ScsExtAlmAckValueAutomatonLog is the root class for extern alarm.      */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsExtAlmAckValueAutomatonLog is an class for extern alarm value       */
/*  automaton used in the alarm server.                                    */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsExtAlmAckValueAutomatonLog's interface.         */
/*.........................................................................*/

#ifndef _SCSEXTALMACKVALUEAUTOMATONLOG_H
#define _SCSEXTALMACKVALUEAUTOMATONLOG_H


#include "scsextalmackvalueautomaton.h"

class ALMSTDAUT_API ScsExtAlmAckValueAutomatonLog: public ScsExtAlmAckValueAutomaton
{
  // METHODS
 public:
  ScsExtAlmAckValueAutomatonLog(const AlmInteger64	inAutoId,
				 const DbkAddressId*	inResultAddress);
  virtual ~ScsExtAlmAckValueAutomatonLog();

  CREATOR_H(ScsExtAlmAckValueAutomatonLog)

 protected:

};

#endif
// _SCSEXTALMACKVALUEAUTOMATONLOG_H

// end of file scsextalmackvalueautomaton.h
