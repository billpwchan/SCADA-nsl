//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : trace.h                                                */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Thu Sep  3 16:19:45 1998                               */
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
// $Id: trace.h,v 1.2 1999/12/14 11:51:37 jmb Exp $
//
// HISTORY:
// $Log: trace.h,v $
// Revision 1.2  1999/12/14 11:51:37  jmb
// Port on MSVC6
//
// Revision 1.1  1999/02/18 13:11:40  ylo
// Initial revision
//
// Revision 1.1  1998/09/03 14:19:52  ylo
// Initial revision
//


#ifndef _SCS_TRACE_H_
#define _SCS_TRACE_H_

#ifdef SCS_STD
#include <iostream>
#else
#include <iostream.h>
#endif

#include "scsthread.h"

class Trace {
public:
  Trace(const char *msg) { _msg = msg; SCS_SL_STD(cout) << "--> " << getpid() << "/" << ScsThread::GetId()  << " " << _msg << SCS_SL_STD(endl);}
  ~Trace() {SCS_SL_STD(cout) << "<-- " << getpid() << "/" << ScsThread::GetId()  << " "  << _msg << SCS_SL_STD(endl);}
private:
  const char *_msg;
};
#endif
