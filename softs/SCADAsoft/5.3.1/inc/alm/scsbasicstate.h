/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*  FILE            : scsbasicstate.h                                      */
/*  FULL NAME       : ScsBasicState                                        */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : LEY K.L.                                             */
/*  COMPANY         : THALES IS                                            */
/*  CREATION DATE   : 26 05 2003                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                      */
/*  All rights reserved.                                                   */
/*                                                                         */
/*  Unauthorized access, use, reproduction or distribution is prohibited.  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  ScsBasicState is a new automaton value with new conditions             */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsBasicState is a class for automaton used in the alarm               */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsBasicState's interface.                         */
/***************************************************************************/
#ifndef _SCSBASICSTATE_H
#define _SCSBASICSTATE_H

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

#include "scsalm.h"

class  ScsBasicValueAutomaton;

struct DataAutomatonStruct {
  int          _format;
  int          _state;
  int          _severity;
  char *       _valueLabel;
};

class ALMAUT_API ScsBasicState
{
  // METHODS
 public:
  // constructor
  ScsBasicState(const AlmInteger64 inAutoId);
  ScsBasicState(const ScsBasicState& inAutomaton);

  // destructor
  virtual ~ScsBasicState();
  
  int  setValueAutomatonPointer (ScsBasicValueAutomaton * inValueAutomaton);
  void setNbstate (int inNbState);
  void setFormat (int inFormat);
  void setValueLabel (const char * inValueLabel);
  void setState (int inState);
  void setFormatMessage (ScsAny inNewValue = NULL);
  void setPointPath(const char * inPointPath);

  int                getNbState () const;
  int                getFormat () const;
  const char *             getValueLabel () const;
  ScsBasicValueAutomaton * getValueAutomatonPointer () const;
  const char *             getPointPath () const;
  
  int getValueTableElement () const { return _valueTableElement;};
  virtual DataAutomatonStruct * getDataAutomatonStruct(ScsAny inKeyOrIndex) const ;

  ScsStatus convertAttributToInt (const char* inAttributList,
				  int & value);

  // redondancy: safeguard
  virtual ScsStatus	save	(SCS_SL_STD(ostream)&	outStream);
  // redondancy: restoration
  virtual ScsStatus	restore	(SCS_SL_STD(istream)&	inStream);

  // FIELDS
 private:
  ScsBasicValueAutomaton * _valueAutomatonPointer;
  AlmInteger64             _autoId;
  int                      _nbState;
  int                      _format;
  char *                   _valueLabel;
  char *                   _pointPath;
  int                      _valueTableElement;

  // Private elements, this attributes cannot be get nor be read
  void *                   _valueTable;

};
#endif // end of file scsbasicstate.h
