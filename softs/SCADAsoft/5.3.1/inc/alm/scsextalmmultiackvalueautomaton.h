/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsextalmmultiackvalueautomaton.h                    */
/*  FULL NAME       : ScsExtAlmMultiAckValueAutomaton                      */
/*-------------------------------------------------------------------------*/
/*  COMPANY         : THALES IS                                            */
/*  CREATION DATE   : Mon August 13 2001                                   */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                      */
/*  All rights reserved.                                                   */
/*                                                                         */
/*  Unauthorized access, use, reproduction or distribution is prohibited.  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  ScsExtAlmMultiAckValueAutomaton is the root class for extern alarm     */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsExtAlmMultiAckValueAutomaton is an class for extern alarm value     */
/*  automaton used in the alarm server.                                    */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsExtAlmMultiAckValueAutomaton's interface.       */
/*.........................................................................*/
// Revision 3.12.1  2002/03/25 KLL
// FFT SRC-498 - Nouvelle API removeAlarm

#ifndef _SCSEXTALMMULTIACKVALUEAUTOMATON_H
#define _SCSEXTALMMULTIACKVALUEAUTOMATON_H

#include "alm/scsmultiackbasicvalueautomaton.h"
#include "alm/scsextvalue.h"

class ALMAUT_API ScsExtAlmMultiAckValueAutomaton: public ScsMultiAckBasicValueAutomaton, public ScsExtValue
{
  // METHODS
 public:
  ScsExtAlmMultiAckValueAutomaton(const AlmInteger64   inAutoId,
				  const DbkAddressId*  inResultAddress);
  ScsExtAlmMultiAckValueAutomaton( const ScsExtAlmMultiAckValueAutomaton& inAutomaton );
  virtual ~ScsExtAlmMultiAckValueAutomaton();

  // redondancy: sauvegarde
  virtual ScsStatus	save(SCS_SL_STD(ostream)& outStream);
  // redondancy: restauration
  virtual ScsStatus	restore(SCS_SL_STD(istream)& inStream);

  // get value in string format
  virtual char* getStringValue() const;

  // get value instance pointer
  virtual void* getValuePointer() const;

  // update value
  virtual void update(const char*	state,
		      const long	severity,
		      const char*	message);

  CREATOR_H(ScsExtAlmMultiAckValueAutomaton)

 protected:
  ScsExtAlmMultiAckValueAutomaton();

  // KLL - 25/03/2003 - FFT SRC 498 - Implémentation de la méthode ScsAlarm::removeAlarm
  virtual void initialize();

};

#endif
// _SCSEXTALMMULTIACKVALUEAUTOMATON_H

// end of file scsextalmmultiackvalueautomaton.h
