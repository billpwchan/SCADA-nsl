/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsextvalue.h                                        */
/*  FULL NAME       : ScsExtValue                                          */
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
/*  ScsExtValue is a class for extern basic value.                         */
/*.........................................................................*/
/*  COMMENT                                                                */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsExtValue's interface and implementation.        */
/***************************************************************************/

#ifndef SCSEXTVALUE_H
#define SCSEXTVALUE_H

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

#include "scs.h"

class ALMAUT_API ScsExtValue
{
// METHODS
 public:
  // default constructor
  ScsExtValue();
  // constructor for copy
  ScsExtValue(const ScsExtValue& inScsExtValueInstance);
  // destructor
  virtual ~ScsExtValue();

  // redundancy
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream);
  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream);

  // value
  void setState(const char* inState);
  // get
  const char* getState() const;
  // convert state to scsbasicvalueautomaton status
  static  int ConvertState(const char* inState);

  // update value
  virtual void update(const char*	state,
		      const long	severity, 
		      const char*	message) = 0;

 protected:
  // automaton instance pointer
  void * getPointer() const;

// FIELDS
 private:
  char* _state;

};

#endif
// SCSEXTVALUE_H

// end of file scsextvalue.h
