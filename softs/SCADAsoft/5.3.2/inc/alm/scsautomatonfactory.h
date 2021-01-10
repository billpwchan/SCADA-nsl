/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*  FILE            : scsautomatonfactory.h                                */
/*  FULL NAME       : ScsAutomatonFactory                                  */
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
/*  ScsAutomatonFactory creates dynamically automatons.                    */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsAutomatonFactory is a mixture of a factory pattern and a proxy.     */
/*  The main reason of this architecture is we need to instanciate         */
/*  dynamically unknown automatons. The automatons derived from the        */
/*  ScsBasicAutomaton class.                                               */
/*  All the informations needed for automatons creation are containing in  */
/*  an instance of ScsAutomatonCreator.                                    */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsAutomatonFactory's interface.                   */
/*.........................................................................*/
/*  HISTORY                                                                */
/*                                                                         */
/*.........................................................................*/

#ifndef _SCSAUTOMATONFACTORY_H
#define _SCSAUTOMATONFACTORY_H

// ScsAutomatonCreator
#include "alm/scsautomatoncreator.h"
// ScsBasicAutomaton
#include "alm/scsbasicautomaton.h"

class ScsBasicAutomaton;
class DbkAddressId;
class ScsAutomatonCreatorRWGSlist;
class DbmServer;

typedef int (*ScsAlmInitFunction)(DbmServer* server, void* arg);
typedef int (*ScsAlmGlobalSave)(SCS_SL_STD(ostream)& os, void* arg);
typedef int (*ScsAlmGlobalRestore)(SCS_SL_STD(istream)& os, void* arg);

class ALMAUT_API ScsAutomatonFactory
{
  // METHODS
 public:
  // singleton: creation control
  static  ScsAutomatonFactory* GetUniqueAutomatonFactory();
  // singleton: deletion control
  static  void DeleteUniqueAutomatonFactory();
  // singleton: synchronize control
  static  void SetUniqueAutomatonFactory(ScsAutomatonFactory* inExternalSingleton);

  // register automaton class
  int registerAutomatonClass(const char*                         inAutomatonClassName,
			     GetAutomatonCreationFunctionPointer inAutomatonCreationFunction);
  // add a new automaton creator.
  int registerAutomatonCreator( ScsAutomatonCreator* inpAutomatonCreator );
  // remove an automaton creator.
  ScsAutomatonCreator* unregisterAutomatonCreator(const char* inAutomatonClassName );

  // register a init function callback
  int registerInitFunction(ScsAlmInitFunction fct, void* arg);

  // register snapshot function callbacks
  int registerSnapshotFunctions(ScsAlmGlobalSave sfct, void* saveArg,
				ScsAlmGlobalRestore rfct, void* restoreAg);

  int callInitFunction(DbmServer* server);
  int callGlobalSave(SCS_SL_STD(ostream)& os);
  int callGlobalRestore(SCS_SL_STD(istream)& is);

  // create a new automaton.
  ScsBasicAutomaton* getNewAutomaton(const char* inAutomatonName,
				     const AlmInteger64	 inAutoId,
				     const DbkAddressId* inResultAddress) const;

  // get the automaton creation function
  GetAutomatonCreationFunctionPointer getAutomatonCreationFunction (const char* inAutomatonName) const;

 private:
  ScsAutomatonFactory();
  ScsAutomatonFactory(const ScsAutomatonFactory& inAutomatonFactory );
  virtual ~ScsAutomatonFactory();

  // FIELDS
 private:
  static  ScsAutomatonFactory* _SINGLETON;
  ScsAutomatonCreatorRWGSlist* _pAutomatonCreatorList;

  ScsAlmInitFunction _initFct;
  void* _initArg;
  ScsAlmGlobalSave _saveFct;
  void* _saveArg;
  ScsAlmGlobalRestore _restoreFct;
  void* _restoreArg;
};

#endif //_SCSAUTOMATONFACTORY_H
