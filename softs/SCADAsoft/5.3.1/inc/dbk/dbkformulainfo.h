//-*-c++-*-
/*****************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and  */
/*  shall not be disclosed by the recipient to third persons without the     */
/*  written consent of SYSECA.                                               */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  FILE            : dbkdatabase.h                                          */
/*  FULL NAME       :                                                        */
/*---------------------------------------------------------------------------*/
/*  COMPANY         : THALES IS                                              */
/*  CREATION DATE   : Mon May 15 09:00:00 2000                               */
/*  LANGUAGE        : C++                                                    */
/*...........................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                        */
/*  All rights reserved.                                                     */
/*                                                                           */
/*  Unauthorized access, use, reproduction or distribution is prohibited.    */
/*...........................................................................*/
/*  OVERVIEW                                                                 */
/*                                                                           */
/*  The class DbkDatabase is described in the file dbkdatabase.h and         */
/*  implemented in the file dbkdatabase.cpp.                                 */
/*                                                                           */
/*...........................................................................*/
/*  CONTENTS                                                                 */
/*                                                                           */
/*****************************************************************************/


#ifndef _SCS_DBKFORMULAINFO_H_
#define _SCS_DBKFORMULAINFO_H_

#include "scs.h"

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

class DbkSession;

typedef void* (*FuncPointer)(int argc, char* argv[]);
typedef void (*SaveFunction)(SCS_SL_STD(ostream)& os, DbkSession* session);
typedef void (*RestoreFunction)(SCS_SL_STD(istream)& is, DbkSession* session);

class DbkUserFormulaInfo {
public:
  char* _name;
  unsigned short _idFunction;
  FuncPointer _funcPointer;
  int _returnType;
  unsigned int _nbArgs;
  int* _argTypes;
  unsigned int* _argSizes;

  DbkUserFormulaInfo() : _name(0), _idFunction(0), _funcPointer(0), _returnType(0), _nbArgs(0), _argTypes(0), _argSizes(0) {}
  void initializeArgSizes();
};

struct DbkUserDllFormulasInfo {
  unsigned int _nbFormulas;
  DbkUserFormulaInfo *_formulas;
  SaveFunction _saveFunction;
  RestoreFunction _restoreFunction;

  DbkUserDllFormulasInfo(): _nbFormulas(0),_formulas(0),_saveFunction(0),_restoreFunction(0) {}
};

#endif


