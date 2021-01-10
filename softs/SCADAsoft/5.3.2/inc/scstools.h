/******************************************************************************/
/*									      */
/*  FILE		: scstools.h                                          */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 2001/03/27					      */
/*  LANGUAGE		: C++						      */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW				   				      */
/*	Various useful tools for Scadasoft    				      */
/*	                                				      */
/*............................................................................*/
/*  CONTENTS								      */
/******************************************************************************/

#ifndef _SCSTOOLS_H
#define _SCSTOOLS_H

#include <stdlib.h>
#include <string.h>
#include "scsdefs.h"

#ifdef __cplusplus
inline void pathWinToUnix(char * path) {
  unsigned int i;
  for (i=0; i< strlen(path); i++) {
    if (path[i] == '\\') path[i] = '/';
  }
}

inline void pathUnixToWin(char * path) {
  unsigned int i;
  for (i=0; i< strlen(path); i++) {
    if (path[i] == '/') path[i] = '\\';
  }
}

#else
/* this file is compiled in C file where inline keyword does not exists */
static void pathWinToUnix(char * path) {
  unsigned int i;
  for (i=0; i< strlen(path); i++) {
    if (path[i] == '\\') path[i] = '/';
  }
}

static void pathUnixToWin(char * path) {
  unsigned int i;
  for (i=0; i< strlen(path); i++) {
    if (path[i] == '/') path[i] = '\\';
  }
}

#endif

#if defined( SCS_DLL ) && !defined( _SCS_TAO_ ) 
extern SCS_API void ScsLocalTerminateCallback();

#define SCS_REGISTER_END_PROCESS atexit(ScsLocalTerminateCallback);

#else
#define SCS_REGISTER_END_PROCESS
#endif

#endif


