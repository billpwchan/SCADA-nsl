/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/

/*
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
!! File automatically generated
!! by g:\bin\p530\bin\scsmkerror.exe
!! at Mon Jun 06 11:06:19 2016
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
*/
#ifndef _AN_TCLSERVERERROR_H
#define _AN_TCLSERVERERROR_H
static AntStatus TclServerInitError(AntStatus::AntError,2500);
inline AntStatus
TclServerErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "TclServer",
              AntTrace::trace().getErrorFormat("tclservererror.emf","TclServer","Init"));
  return TclServerInitError;
}
static AntStatus TclServerORBError(AntStatus::AntError,2501);
inline AntStatus
TclServerErrORB(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ORB",
              source,
              "TclServer",
              AntTrace::trace().getErrorFormat("tclservererror.emf","TclServer","ORB"),arg0);
  return TclServerORBError;
}
static AntStatus TclServerHostServerError(AntStatus::AntError,2502);
inline AntStatus
TclServerErrHostServer(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "HostServer",
              source,
              "TclServer",
              AntTrace::trace().getErrorFormat("tclservererror.emf","TclServer","HostServer"),arg0);
  return TclServerHostServerError;
}
inline const char *
TclServerGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 2500:
    return "Init";
  case 2501:
    return "ORB";
  case 2502:
    return "HostServer";
  default:
    return "";
  }
}
#endif
