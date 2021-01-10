/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsbasicaivalueautomaton.h                           */
/*  FULL NAME       : ScsBasicAIValueAutomaton                             */
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
/*  ScsBasicAIValueAutomaton is the root class for all the value automate  */
/*  behaviour used reals.                                                  */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsBasicAIValueAutomaton is an abstract class for analog value         */
/*  automaton used in the alarm server.                                    */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsBasicAIValueAutomaton's interface.              */
/*.........................................................................*/
// Revision 3.12.1  2002/03/25 KLL
// FFT SRC-498 - Nouvelle API removeAlarm

// Revision 3.14.0  2003/05/19 KLL
// FFT SRC-531 - Pb lorsque cette méthode est
//               appelée par DbkSession::removeAutoId donc 
//               Effacer toutes les alarmes à partir de l'automate

// Revision 3.14.0  19/06/2003 KLL
// FFT SRC 542 - Interblocage entre le dbserver et le serveur d'alarmes
//

#ifndef _SCSBASICAIVALUEAUTOMATON_H
#define _SCSBASICAIVALUEAUTOMATON_H

#include "alm/scsmonoackbasicvalueautomaton.h"
#include "alm/scsbasicvalue.h"

class ALMAUT_API ScsBasicAIValueAutomaton: public ScsMonoAckBasicValueAutomaton, public ScsBasicAIValue
{
  // METHODS
 public:
  ScsBasicAIValueAutomaton(const AlmInteger64  inAutoId,
			   const DbkAddressId* inResultAddress);
  ScsBasicAIValueAutomaton( const ScsBasicAIValueAutomaton& inAutomaton );
  virtual ~ScsBasicAIValueAutomaton() = 0;

  // redondancy: sauvegarde
  virtual ScsStatus	save	(SCS_SL_STD(ostream)&	outStream) = 0;
  // redondancy: restauration
  virtual ScsStatus	restore	(SCS_SL_STD(istream)&	inStream) = 0;

  // get value in string format
  virtual char* getStringValue() const;

  // get value instance pointer
  virtual void* getValuePointer() const;

  // update value
  virtual void update(double inNewValue);

  // KLL - 19/06/2003 - FFT SRC 542 - Interblocage dbserver et le serveur d'alarmes
  virtual int createDbmDirectDataToWrite(DbmDirectData *& data);

  // ESA - 19/06/2006 - PCR PCC 185 + ML2 84
  virtual void logEventValue();

  // ESA - 29/08/2006 - PCR SCS 813
  virtual char* getColumnName();

 protected:
  ScsBasicAIValueAutomaton();

};

#endif // _SCSBASICAIVALUEAUTOMATON_H

// end of file scsbasicaivalueautomaton.h

