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
!! at Fri Nov 15 16:14:21 2013
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
*/
#ifndef _AN_TRDERROR_H
#define _AN_TRDERROR_H
static AntStatus TrdInitError(AntStatus::AntError,700);
inline AntStatus
TrdErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Trd",
              AntTrace::trace().getErrorFormat("trderror.emf","Trd","Init"));
  return TrdInitError;
}
static AntStatus TrdSubscriptionNotFoundError(AntStatus::AntError,701);
inline AntStatus
TrdErrSubscriptionNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SubscriptionNotFound",
              source,
              "Trd",
              AntTrace::trace().getErrorFormat("trderror.emf","Trd","SubscriptionNotFound"),arg0,arg1);
  return TrdSubscriptionNotFoundError;
}
static AntStatus TrdNullFieldCountError(AntStatus::AntError,702);
inline AntStatus
TrdErrNullFieldCount(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NullFieldCount",
              source,
              "Trd",
              AntTrace::trace().getErrorFormat("trderror.emf","Trd","NullFieldCount"));
  return TrdNullFieldCountError;
}
static AntStatus TrdBadAttributeError(AntStatus::AntError,703);
inline AntStatus
TrdErrBadAttribute(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadAttribute",
              source,
              "Trd",
              AntTrace::trace().getErrorFormat("trderror.emf","Trd","BadAttribute"),arg0,arg1);
  return TrdBadAttributeError;
}
inline const char *
TrdGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 700:
    return "Init";
  case 701:
    return "SubscriptionNotFound";
  case 702:
    return "NullFieldCount";
  case 703:
    return "BadAttribute";
  default:
    return "";
  }
}
#endif
