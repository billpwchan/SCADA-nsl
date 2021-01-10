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
!! at Mon Jun 06 11:06:20 2016
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
*/
#ifndef _AN_VISUERROR_H
#define _AN_VISUERROR_H
static AntStatus VisInitError(AntStatus::AntError,2900);
inline AntStatus
VisErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Vis",
              AntTrace::trace().getErrorFormat("visuerror.emf","Vis","Init"));
  return VisInitError;
}
static AntStatus VisORBError(AntStatus::AntError,2901);
inline AntStatus
VisErrORB(AntErrorSeverity severity
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
              "Vis",
              AntTrace::trace().getErrorFormat("visuerror.emf","Vis","ORB"),arg0);
  return VisORBError;
}
static AntStatus VisHostServerError(AntStatus::AntError,2902);
inline AntStatus
VisErrHostServer(AntErrorSeverity severity
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
              "Vis",
              AntTrace::trace().getErrorFormat("visuerror.emf","Vis","HostServer"),arg0);
  return VisHostServerError;
}
static AntStatus VisNoServerError(AntStatus::AntError,2903);
inline AntStatus
VisErrNoServer(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoServer",
              source,
              "Vis",
              AntTrace::trace().getErrorFormat("visuerror.emf","Vis","NoServer"),arg0);
  return VisNoServerError;
}
static AntStatus VisScadasoftFunctionError(AntStatus::AntError,2904);
inline AntStatus
VisErrScadasoftFunction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ScadasoftFunction",
              source,
              "Vis",
              AntTrace::trace().getErrorFormat("visuerror.emf","Vis","ScadasoftFunction"),arg0,arg1);
  return VisScadasoftFunctionError;
}
static AntStatus VisInternalError(AntStatus::AntError,2905);
inline AntStatus
VisErrInternal(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Internal",
              source,
              "Vis",
              AntTrace::trace().getErrorFormat("visuerror.emf","Vis","Internal"),arg0);
  return VisInternalError;
}
inline const char *
VisGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 2900:
    return "Init";
  case 2901:
    return "ORB";
  case 2902:
    return "HostServer";
  case 2903:
    return "NoServer";
  case 2904:
    return "ScadasoftFunction";
  case 2905:
    return "Internal";
  default:
    return "";
  }
}
#endif
