//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : red.h                                                  */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Fri Aug 21 17:09:20 1998                               */
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
// $Id: red.h,v 1.1 1998/12/14 14:02:01 ylo Exp $
//
// HISTORY:
// $Log: red.h,v $
// Revision 1.1  1998/12/14 14:02:01  ylo
// Initial revision
//


#ifndef _RED_H
#define _RED_H

#define RedTrace	ScsTraceFunction(RED_SCSMODULE)
#define RedTraceLevel(level, message) BaseTraceLevel(RED_SCSMODULE, level, message)
#define RED_MODULE	(1 << RED_SCSMODULE)

#ifdef _SCSLOG__
inline void ScsLogTrace(short level, 
			short line, const char* file,
			const char* format, ...)

{
  if (Scadasoft::IsEnable(level))
    {
      va_list args;
      AntMessageBody  message;
      message[0] = '\0';
      va_start(args, format);
      vsnprintf(message ,AntMessageMaxSize-1, format, args);
      AntPrintTrace(level, line, file, message);
      va_end(args);
    }
#else
inline void ScsLogTrace(short , 
			short , const char* ,
			const char* , ...)
{
#endif
}

#endif

