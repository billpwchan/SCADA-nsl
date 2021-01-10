#ifndef _DAC_DACCOMMON_H_
#define _DAC_DACCOMMON_H_


/******************************************************************************/
/*                                                                            */
/*  FILE             : daccommon.h                                            */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Fri Jan 07 15:09:04 2000                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW                                                                  */
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

#ifdef WIN32
// disable warning C4786: symbol greater than 255 character
#pragma warning(disable: 4786)
// disable warning C4251: 'table_' : class 'RWSlistCollectablesPRWGVector' needs to have dll-interface to be used by clients of class 'RWHashTable'
#pragma warning(disable: 4251)
#endif


#include "daceivlist.h"
#include "daceovlist.h"
#include "scs.h"
/* class DacEivList; */
/* class DacEovList; */

extern DACCOM_API ScsStatus init(int argc, char** argv);

int debugTrace( int level, DacEivList& list );
int debugTrace( int level, DacEovList& list );

#endif // _DAC_DACCOMMON_H_
