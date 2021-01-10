/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsmultiackbasicaivalueautomaton.h                   */
/*  FULL NAME       : ScsMultiAckBasicAIValueAutomaton                     */
/*-------------------------------------------------------------------------*/
/*  COMPANY         : THALES IS                                            */
/*  CREATION DATE   : Fri December 08 2000                                 */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                      */
/*  All rights reserved.                                                   */
/*                                                                         */
/*  Unauthorized access, use, reproduction or distribution is prohibited.  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  ScsMultiAckBasicAIValueAutomaton is the root class for all the value   */
/*  automate behaviour used reals.                                         */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsMultiAckBasicAIValueAutomaton is an abstract class for analog value */
/*  automaton used in the alarm server.                                    */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsMultiAckBasicAIValueAutomaton's interface.      */
/*.........................................................................*/
// Revision 3.12.1  2002/03/25 KLL
// FFT SRC-498 - Nouvelle API removeAlarm

// Revision 3.14.0  2003/05/19 KLL
// FFT SRC-531 - Pb lorsque cette méthode est
//               appelée par DbkSession::removeAutoId donc 
//               Effacer toutes les alarmes à partir de l'automate

#ifndef _SCSMULTIACKBASICAIVALUEAUTOMATON_H
#define _SCSMULTIACKBASICAIVALUEAUTOMATON_H

#include "alm/scsmultiackbasicvalueautomaton.h"
#include "alm/scsbasicvalue.h"

class ALMAUT_API ScsMultiAckBasicAIValueAutomaton: public ScsMultiAckBasicValueAutomaton, public ScsBasicAIValue
{
  // METHODS
 public:
  ScsMultiAckBasicAIValueAutomaton(const AlmInteger64 inAlmId,
			   const DbkAddressId*	      inResultAddress);
  ScsMultiAckBasicAIValueAutomaton( const ScsMultiAckBasicAIValueAutomaton& inAutomaton );
  virtual ~ScsMultiAckBasicAIValueAutomaton() = 0;

  // redondancy: sauvegarde
  virtual ScsStatus	save(SCS_SL_STD(ostream)& outStream) = 0;
  // redondancy: restauration
  virtual ScsStatus	restore(SCS_SL_STD(istream)& inStream) = 0;

  // get value in string format
  virtual char* getStringValue() const;

  // get value instance pointer
  virtual void* getValuePointer() const;

  // update value
  virtual void update(double inNewValue);

  // KLL - 25/03/2003 - FFT SRC 498 - Implémentation de la méthode ScsAlarm::removeAlarm
  virtual int createDbmDirectDataToWrite(DbmDirectData *& data);

 protected:
  ScsMultiAckBasicAIValueAutomaton();

};

#endif // _SCSMULTIACKBASICAIVALUEAUTOMATON_H

// end of file scsmultiackbasicaivalueautomaton.h
