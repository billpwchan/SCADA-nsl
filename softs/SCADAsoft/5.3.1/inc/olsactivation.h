//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : olsactivation.h                                        */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Mon Jan 13 17:20:04 2003                               */
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


#ifndef _SCS_OLSACTIVATION_H_
#define _SCS_OLSACTIVATION_H_

#include "scs.h"

/**
  \file
  \brief OlsList enabling/disabling functions.
*/

/**
\code#include "olsactivation.h"\endcode
   This function activates the OlsList features. It has to be used after calling OlsExportList. The OlsList services are activated by default. 
*/
OLS_API ScsStatus OlsActivateList();

/**
\code#include "olsactivation.h"\endcode
   This function deactivates the OlsList features. It has to be used after calling OlsExportList.
*/
OLS_API ScsStatus OlsDeactivateList();

#endif
