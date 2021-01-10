//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : ascconnection.h                                        */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Wed May 26 15:02:43 1999                               */
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
// $Id: ascconnection.h,v 1.2 1999/06/02 13:43:31 scadaref Exp $
//
// HISTORY:
// $Log: ascconnection.h,v $
// Revision 1.2  1999/06/02 13:43:31  scadaref
// *** empty log message ***
//
// Revision 1.1  1999/06/02 10:57:06  ylo
// Initial revision
//


#ifndef _SCS_ASCCONNECTION_H_
#define _SCS_ASCCONNECTION_H_

#include "scsdefs.h"

class AscManager;

enum AscConnectionType {
  AscConnectionTypeError,
  AscExternalSingle,
  AscExternalRedundant,
  AscExternalAsyncRedundant,
  AscInternalSingle,
  AscInternalRedundant,
  AscInternalRedundantSynchronised,
  AscInternalAsyncRedundant
};

extern ASC_API AscConnectionType
ascGetConnectionType(AscManager *ascMgr, const char *environment, char **&physEnvs, char **&hosts, short &nbPhysEnvs);

#endif
