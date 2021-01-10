/******************************************************************************/
/*									      */
/*  FILE		: ols.h                                               */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 1997/09/30					      */
/*  LANGUAGE		: C++						      */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW								      */
/*	                                				      */
/*............................................................................*/
/*  CONTENTS								      */
/******************************************************************************/
// IDENTIFICATION:
// $Id: ols.h,v 1.5 1999/11/30 17:10:21 scadaref Exp $
//
// HISTORY:
// $Log: ols.h,v $
// Revision 1.5  1999/11/30 17:10:21  scadaref
// Port on MSVC6
//
// Revision 1.4  1999/09/17 12:43:43  scadaref
// Fix SPR ??? for Manchester (remote acknowledge on AlmServer)
//
// Revision 1.3  1998/12/15 16:18:07  ylo
// Create ols/libinternal for ascManager needs.
//
// Revision 1.2  1998/12/15 14:33:48  ylo
// Create ols/libinternal for ascManager needs.
//
// Revision 1.1  1998/12/07 13:38:47  ylo
// Initial revision
//
//
/******************************************************************************/
#ifndef _OLSTRACE_H
#define _OLSTRACE_H

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/

static int IsOlsTraceUp()
{
    if (getenv("OLSTRACE"))
       return 1;
    else
       return 0;
}

static int IsAscTraceUp()
{
    if (getenv("ASCTRACE"))
       return 1;
    else
       return 0;
}

static int IsScsTraceUp()
{
    if (getenv("SCSTRACE"))
       return 1;
    else
       return 0;
}

#endif
