/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/* and shall not be disclosed by the recipient to third persons without    */
/* the written consent of Thales IS.                                       */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsmultiackbasicaivalueautomatonuser.h               */
/*  FULL NAME       : ScsMultiAckBasicAIValueAutomatonUser                 */
/*-------------------------------------------------------------------------*/
/*  COMPANY         : THALES IS                                            */
/*  CREATION DATE   : Fri February 08 2002                                 */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                      */
/*  All rights reserved.                                                   */
/*                                                                         */
/*  Unauthorized access, use, reproduction or distribution is prohibited.  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  ScsMultiAckBasicAIValueAutomatonUser represents an ai user value       */
/*  automaton                                                              */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsMultiAckBasicAIValueAutomatonUser is an abstract class              */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsMultiAckBasicAIValueAutomatonUser's interface.  */
/***************************************************************************/

#ifndef _SCSMULTIACKBASICAIVALUEAUTOMATONUSER_H
#define _SCSMULTIACKBASICAIVALUEAUTOMATONUSER_H

#include "alm/scsbasicvalueautomaton.h"
#include "alm/scsmultiackbasicaivalueautomaton.h"
#include "alm/scsbasicuser.h"

class ALMAUT_API ScsMultiAckBasicAIValueAutomatonUser: public ScsMultiAckBasicAIValueAutomaton, public ScsBasicUser
{
  //** METHODS *************************************************************/
 public:
  //-- Constructors
  ScsMultiAckBasicAIValueAutomatonUser (const long          inAutoId,
					const DbkAddressId* inDbkAddressId);
  //-- recopy function
  ScsMultiAckBasicAIValueAutomatonUser (const ScsMultiAckBasicAIValueAutomatonUser& inValueAutomaton);
  //-- destructor
  virtual ~ScsMultiAckBasicAIValueAutomatonUser () = 0;

  //-- get value pointer of the user value automaton
  virtual void* getValuePointerUser () const;

  //-- get userId of the value automaton
  virtual long getUserId () const;

  //-- Redondancy
  //--  safeguard
  virtual ScsStatus save (SCS_SL_STD(ostream) &outStream) = 0;
  // restoration
  virtual ScsStatus restore (SCS_SL_STD(istream) &inStream) = 0;

 protected:
  //-- default constructor
  ScsMultiAckBasicAIValueAutomatonUser ();
 private:
  //-- operator= over definition
  ScsMultiAckBasicAIValueAutomatonUser& operator= (const ScsMultiAckBasicAIValueAutomatonUser& inValueAutomaton);

};

#endif // _SCSMULTIACKBASICAIVALUEAUTOMATONUSER_H

//** END of file scsmultiackbasicaivalueautomatonuser.h ********************/                        

