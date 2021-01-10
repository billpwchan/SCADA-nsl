/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsextalmackvalueautomaton.h                         */
/*  FULL NAME       : ScsExtAlmAckValueAutomaton                           */
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
/*  ScsExtAlmAckValueAutomaton is the root class for extern alarm.         */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsExtAlmAckValueAutomaton is an class for extern alarm value          */
/*  automaton used in the alarm server.                                    */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsExtAlmAckValueAutomaton's interface.            */
/*.........................................................................*/

#ifndef _SCSEXTALMACKVALUEAUTOMATON_H
#define _SCSEXTALMACKVALUEAUTOMATON_H

#include "alm/scsextalmmonoackvalueautomaton.h"

class ALMSTDAUT_API ScsExtAlmAckValueAutomaton: public ScsExtAlmMonoAckValueAutomaton
{
  // METHODS
 public:
  ScsExtAlmAckValueAutomaton(const AlmInteger64	inAutoId,
				 const DbkAddressId*	inResultAddress);
  ScsExtAlmAckValueAutomaton( const ScsExtAlmAckValueAutomaton& inAutomaton );
  virtual ~ScsExtAlmAckValueAutomaton();

  // update value
  virtual void update(const char*	state,
		      const long	severity,
		      const char*	message);

  CREATOR_H(ScsExtAlmAckValueAutomaton)

 protected:
  ScsExtAlmAckValueAutomaton();

};

#endif
// _SCSEXTALMACKVALUEAUTOMATON_H

// end of file scsextalmackvalueautomaton.h
