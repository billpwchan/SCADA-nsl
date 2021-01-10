//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : opmtypes.h                                             */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Mon Jun 24 17:12:21 2002                               */
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

#ifndef _SCS_OPMTYPES_H_
#define _SCS_OPMTYPES_H_

typedef int            t_category;
typedef unsigned short t_mask;
typedef int            t_maskfield;
typedef int            t_index;

typedef void (*OpmCallback)(const char *profile);

#endif

