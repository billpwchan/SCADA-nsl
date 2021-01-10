/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsextalmmultipleackvalueautomaton.h                 */
/*  FULL NAME       : ScsExtAlmMultipleAckValueAutomaton                   */
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
/*  ScsExtAlmMultipleAckValueAutomaton is the root class for extern alarm. */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsExtAlmMultipleAckValueAutomaton is an class for extern alarm value  */
/*  automaton used in the alarm server.                                    */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsExtAlmMultipleAckValueAutomaton's interface.    */
/*.........................................................................*/

#ifndef _SCSEXTALMMULTIPLEACKVALUEAUTOMATON_H
#define _SCSEXTALMMULTIPLEACKVALUEAUTOMATON_H

#include "alm/scsextalmmultiackvalueautomaton.h"

class ALMSTDAUT_API ScsExtAlmMultipleAckValueAutomaton : public ScsExtAlmMultiAckValueAutomaton
{
  // METHODS
 public:
  ScsExtAlmMultipleAckValueAutomaton(const AlmInteger64	 inAutoId,
				     const DbkAddressId* inResultAddress);
  ScsExtAlmMultipleAckValueAutomaton(const ScsExtAlmMultipleAckValueAutomaton& inAutomaton);
  virtual ~ScsExtAlmMultipleAckValueAutomaton();
  
  // update value
  virtual void update(const char*	state,
		      const long	severity,
		      const char*	message);
  
  CREATOR_H(ScsExtAlmMultipleAckValueAutomaton)
  
 protected:
  ScsExtAlmMultipleAckValueAutomaton();
 private:
};

#endif
// _SCSEXTALMMULTIPLEACKVALUEAUTOMATON_H

// end of file scsextalmmultipleackvalueautomaton.h
