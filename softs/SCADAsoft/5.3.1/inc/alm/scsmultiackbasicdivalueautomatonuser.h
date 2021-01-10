/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/* and shall not be disclosed by the recipient to third persons without    */
/* the written consent of Thales IS.                                       */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsmultiackbasicdivalueautomatonuser.h               */
/*  FULL NAME       : ScsMultiAckBasicDIValueAutomatonUser                 */
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
/*  ScsMultiAckBasicDIValueAutomatonUser represents an di user value       */
/*  automaton                                                              */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsMultiAckBasicDIValueAutomatonUser is an abstract class              */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsMultiAckBasicDIValueAutomatonUser's interface.  */
/***************************************************************************/

#ifndef _SCSMULTIACKBASICDIVALUEAUTOMATONUSER_H
#define _SCSMULTIACKBASICDIVALUEAUTOMATONUSER_H

#include "alm/scsbasicvalueautomaton.h"
#include "alm/scsmultiackbasicdivalueautomaton.h"
#include "alm/scsbasicuser.h"

class ALMAUT_API ScsMultiAckBasicDIValueAutomatonUser: public ScsMultiAckBasicDIValueAutomaton, public ScsBasicUser
{
  //** METHODS *************************************************************/
 public:
  //-- Constructors
  ScsMultiAckBasicDIValueAutomatonUser (const AlmInteger64  inAutoId,
					const DbkAddressId* inDbkAddressId);
  //-- recopy function
  ScsMultiAckBasicDIValueAutomatonUser (const ScsMultiAckBasicDIValueAutomatonUser& inAutomaton);
  //-- destructor
  virtual ~ScsMultiAckBasicDIValueAutomatonUser () = 0;

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
  ScsMultiAckBasicDIValueAutomatonUser ();

 private:  //-- operator= over definition
  ScsMultiAckBasicDIValueAutomatonUser& operator= (const ScsMultiAckBasicDIValueAutomatonUser& inValueAutomaton);

};

#endif // _SCSMULTIACKBASICDIVALUEAUTOMATONUSER_H

//** END of file scsmultiackbasicdivalueautomatonuser.h ********************/                        

