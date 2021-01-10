/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsextalmmonoackvalueautomaton.h                     */
/*  FULL NAME       : ScsExtAlmMonoAckValueAutomaton                       */
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
/*  ScsExtAlmMonoAckValueAutomaton is the root class for extern alarm.     */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsExtAlmMonoAckValueAutomaton is an class for extern alarm value      */
/*  automaton used in the alarm server.                                    */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsExtAlmMonoAckValueAutomaton's interface.        */
/*.........................................................................*/
// Revision 3.12.1  2002/03/25 KLL
// FFT SRC-498 - Nouvelle API removeAlarm

#ifndef _SCSEXTALMMONOACKVALUEAUTOMATON_H
#define _SCSEXTALMMONOACKVALUEAUTOMATON_H

#include "alm/scsmonoackbasicvalueautomaton.h"
#include "alm/scsextvalue.h"

class ALMAUT_API ScsExtAlmMonoAckValueAutomaton: public ScsMonoAckBasicValueAutomaton, public ScsExtValue
{
  // METHODS
 public:
  ScsExtAlmMonoAckValueAutomaton(const AlmInteger64	inAutoId,
				 const DbkAddressId*	inResultAddress);
  ScsExtAlmMonoAckValueAutomaton( const ScsExtAlmMonoAckValueAutomaton& inAutomaton );
  virtual ~ScsExtAlmMonoAckValueAutomaton();

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

  // ESA - 19/06/2006 - PCR PCC 185 + ML2 84
  virtual void logEventValue();

  CREATOR_H(ScsExtAlmMonoAckValueAutomaton)

 protected:
  ScsExtAlmMonoAckValueAutomaton();

  // KLL - 25/03/2003 - FFT SRC 498 - Implémentation de la méthode ScsAlarm::removeAlarm
  virtual void initialize();

  // ESA - 29/08/2006 - PCR SCS 813
  virtual char* getColumnName(){return NULL;};
};

#endif
// _SCSEXTALMMONOACKVALUEAUTOMATON_H

// end of file scsextalmmonoackvalueautomaton.h
