/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*  FILE            : scsautomatoncreator.h                                */
/*  FULL NAME       : ScsAutomatonCreator                                  */
/*-------------------------------------------------------------------------*/
/*  COMPANY         : THALES IS                                            */
/*  CREATION DATE   : December 04 2000                                     */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                      */
/*  All rights reserved.                                                   */
/*                                                                         */
/*  Unauthorized access, use, reproduction or distribution is prohibited.  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  ScsAutomatonCreator contains automation creation informations.         */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsAutomatonFactory manipulate ScsAutomatonCreator instances.          */
/*  If registered to an ScsAutomatonFactory instance, it will be destructed*/
/*  by the  factory                                                        */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsAutomatonCreator's interface                    */
/*.........................................................................*/
/*  HISTORY                                                                */
/*                                                                         */
/*.........................................................................*/

#ifndef _SCSAUTOMATONCREATOR_H
#define _SCSAUTOMATONCREATOR_H

#include "alm/scsbasicautomaton.h"
class DbkAddressId;

class ScsAutomatonCreator
{
  // METHODS
 public:
  ScsAutomatonCreator(const char*                         inAutomatonClassName,
		      GetAutomatonCreationFunctionPointer inAutomatonCreationFunction);
  virtual ~ScsAutomatonCreator();

  // create a new automaton.
  ScsBasicAutomaton* getNewAutomaton(const AlmInteger64	 inAutoId,
				     const DbkAddressId* inResultAddress) const;
  // get the automaton class name
  const char* getAutomatonClassName() const;

  // get the automaton creation function
  GetAutomatonCreationFunctionPointer getAutomatonCreationFunction () const;
 
 private:
  ScsAutomatonCreator();
  ScsAutomatonCreator( const ScsAutomatonCreator& inAutomatonCreator );
  ScsAutomatonCreator &operator= (const ScsAutomatonCreator&);
  // FIELDS
 private:
  char*					_automatonClassName;
  GetAutomatonCreationFunctionPointer	_automatonCreationFunction;
};

#endif // _SCSAUTOMATONCREATOR_H

// scsautomatoncreator.h end
