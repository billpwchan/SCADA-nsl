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
!! at Mon Jun 06 11:06:17 2016
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
*/
#ifndef _AN_ALMERROR_H
#define _AN_ALMERROR_H
static AntStatus AlmInitError(AntStatus::AntError,500);
inline AntStatus
AlmErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Alm",
              AntTrace::trace().getErrorFormat("almerror.emf","Alm","Init"));
  return AlmInitError;
}
static AntStatus AlmORBError(AntStatus::AntError,501);
inline AntStatus
AlmErrORB(AntErrorSeverity severity
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
              "Alm",
              AntTrace::trace().getErrorFormat("almerror.emf","Alm","ORB"),arg0);
  return AlmORBError;
}
static AntStatus AlmHostError(AntStatus::AntError,502);
inline AntStatus
AlmErrHost(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Host",
              source,
              "Alm",
              AntTrace::trace().getErrorFormat("almerror.emf","Alm","Host"),arg0);
  return AlmHostError;
}
static AntStatus AlmRtapFunctionError(AntStatus::AntError,503);
inline AntStatus
AlmErrRtapFunction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RtapFunction",
              source,
              "Alm",
              AntTrace::trace().getErrorFormat("almerror.emf","Alm","RtapFunction"),arg0);
  return AlmRtapFunctionError;
}
static AntStatus AlmSystemFunctionError(AntStatus::AntError,504);
inline AntStatus
AlmErrSystemFunction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SystemFunction",
              source,
              "Alm",
              AntTrace::trace().getErrorFormat("almerror.emf","Alm","SystemFunction"),arg0);
  return AlmSystemFunctionError;
}
static AntStatus AlmListActionError(AntStatus::AntError,505);
inline AntStatus
AlmErrListAction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ListAction",
              source,
              "Alm",
              AntTrace::trace().getErrorFormat("almerror.emf","Alm","ListAction"),arg0);
  return AlmListActionError;
}
static AntStatus AlmDataBaseConnectionError(AntStatus::AntError,506);
inline AntStatus
AlmErrDataBaseConnection(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DataBaseConnection",
              source,
              "Alm",
              AntTrace::trace().getErrorFormat("almerror.emf","Alm","DataBaseConnection"),arg0);
  return AlmDataBaseConnectionError;
}
static AntStatus AlmASConnectionError(AntStatus::AntError,507);
inline AntStatus
AlmErrASConnection(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ASConnection",
              source,
              "Alm",
              AntTrace::trace().getErrorFormat("almerror.emf","Alm","ASConnection"));
  return AlmASConnectionError;
}
static AntStatus AlmSecurityRestrictionError(AntStatus::AntError,508);
inline AntStatus
AlmErrSecurityRestriction(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SecurityRestriction",
              source,
              "Alm",
              AntTrace::trace().getErrorFormat("almerror.emf","Alm","SecurityRestriction"),arg0,arg1);
  return AlmSecurityRestrictionError;
}
inline const char *
AlmGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 500:
    return "Init";
  case 501:
    return "ORB";
  case 502:
    return "Host";
  case 503:
    return "RtapFunction";
  case 504:
    return "SystemFunction";
  case 505:
    return "ListAction";
  case 506:
    return "DataBaseConnection";
  case 507:
    return "ASConnection";
  case 508:
    return "SecurityRestriction";
  default:
    return "";
  }
}
#endif
