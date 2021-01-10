/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*  FILE            : scsmonobasicstateaihisterisis.h                      */
/*  FULL NAME       : ScsMonoBasicStateAIHisterisis                        */
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
/*  ScsMonoBasicStateAIHisterisis is a new automaton value with new        */
/*  conditions                                                             */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsMonoBasicStateAIHisterisis is a class for automaton used in the     */
/*  alarm                                                                  */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsMonoBasicStateAIHisterisis's interface.         */
/***************************************************************************/
#ifndef _SCSMONOBASICSTATEAIHISTERISIS_H
#define _SCSMONOBASICSTATEAIHISTERISIS_H

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

#include "alm/scsbasicaivalueautomaton.h"
#include "alm/scsbasicstate.h"

class ALMAUT_API ScsMonoBasicStateAIHisterisis: public ScsBasicAIValueAutomaton, public ScsBasicState
{
  // METHODS
 public:
  // constructor
  ScsMonoBasicStateAIHisterisis (const AlmInteger64  inAutoId,
				 const DbkAddressId* inAddressId);
  ScsMonoBasicStateAIHisterisis (const ScsMonoBasicStateAIHisterisis& inAutomaton);
  // destructor
  virtual ~ScsMonoBasicStateAIHisterisis();

  virtual DataAutomatonStruct * getDataAutomatonStruct(ScsAny inKeyOrIndex) const;

  // Surdéfinition de la méthode ScsBasicAIVAlue::setLimits( ... )
  virtual void setLimits(double* inValueLimits,
			 int     inLimitsSize);
  virtual int compare(const double  inNewValue,
		      const double* inLimits,
		      const int     inLimitsSize) const;
  // redondancy: safeguard
  virtual ScsStatus	save	(SCS_SL_STD(ostream)&	outStream);
  // redondancy: restoration
  virtual ScsStatus	restore	(SCS_SL_STD(istream)&	inStream);

  void setHisterisis (double inHisterisis);
  double getHisterisis () const;

// FIELDS
 private:
  double _histerisis;
};
#endif // end of file scsmonobasicstateaihisterisis.h
