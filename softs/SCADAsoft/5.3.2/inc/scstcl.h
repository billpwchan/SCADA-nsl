//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : scstcl.h                                               */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Mon Feb  7 09:51:24 2000                               */
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
// $Id: scstcl.h,v 1.1 2000/02/08 13:58:11 scadaref Exp $
//
// HISTORY:
// $Log: scstcl.h,v $
// Revision 1.1  2000/02/08 13:58:11  scadaref
// Initial revision
//

#ifndef _SCS_SCSTCL_H_
#define _SCS_SCSTCL_H_

#include "tcl.h"

extern "C"
{
#ifdef WIN32
__declspec(dllexport) 
#endif
int Scstcl_Init(Tcl_Interp *);
}

#endif

