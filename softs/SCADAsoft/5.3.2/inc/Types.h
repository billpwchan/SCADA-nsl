//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : Types.h                                                */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : SYSECA                                                 */
/*  CREATION DATE    : 19/02/98                                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW         : Common types definition                                */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
// IDENTIFICATION:
// $Id: $
//
// HISTORY:
// $Log: $

#ifndef __TYPES_H__
#define __TYPES_H__

/** \file
    \brief Various basic type definitions common to all scadasoft components.
*/

#include "scs.h"
//#include "dbm.h"

typedef void ScsObject;

typedef int ScsBool;

#ifndef True
#define True 1
#define False 0
#endif


/** Accessor Method Type.
    Accessors 'Set' and 'Get' methods prototypes.*/
//typedef void (*AccessMethod) (ScsObject* pObject, ScsData& pValue );
typedef void (*AccessMethodSet) (ScsObject* pObject, const ScsData& pValue );
typedef void (*AccessMethodGet) (ScsObject* pObject, ScsData& pValue );

/** Variable Update Method.
    Used to modify an object registered to a ScsFormula.*/
typedef void (*LinkCallBack) ( const char* pName,
                               ScsObject* pObject,
                               ScsData& pValue );

class DbmDataSet;
/** SCADAsoft Callback prototype.
    Prototype of the function called by SCADAsoft when updating a data*/
//typedef void (*SCADAsoftCallBack) ( const DbmDataSet& pDataSet, ScsAny pArgument );
typedef void (*SCADAsoftCallBack) (const DbmDataSet& pDataSet, ScsAny pArgument);

/** Refresh Modes.
     Accessors Refresh modes. Values are ScsModeNone, ScsModeConstant,
     ScsModeRead, ScsModeReadWrite, ScsModePoll*/
typedef enum { ScsModeNone,
               ScsModeConstant,
               ScsModeRead,
               ScsModeReadWrite,
               ScsModePoll,
               ScsModeComputed,
               ScsModeHistory,
               ScsModeAny
             } ScsMode;


/** Available modules.
	Accessors modules. Values are VISU_DBM, VISU_POL, VISU_OPM, VISU_FTS, VISU_TSC, VISU_DSS, VISU_HIS, 
	VISU_LST, VISU_OLS, VISU_ALM*/
typedef enum _ScsModules 
{
  VISU_DBM = 0, 
  VISU_POL, 
  VISU_OPM, 
  VISU_FTS, 
  VISU_TSC, 
  VISU_DSS, 
  VISU_HIS, 
  VISU_LST, 
  VISU_OLS, 
  VISU_ALM,
  VISU_NB_MODULES
}
ScsModules;

#define ScsPreRegisterProperty(WINDLL_EXP_DEF, _class_)                                \
/* Static constructor to insert above into factory: */                \
struct WINDLL_EXP_DEF AnStaticPropertyConstructor(_class_) {                         \
  AnStaticPropertyConstructor(_class_)();                             \
  ~AnStaticPropertyConstructor(_class_)();                            \
};                                                                    \
static AnStaticPropertyConstructor(_class_) AnName2(AnDummy,_class_);


#endif

