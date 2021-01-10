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
#ifndef _AN_SECERROR_H
#define _AN_SECERROR_H
static AntStatus SecInitError(AntStatus::AntError,800);
inline AntStatus
SecErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","Init"));
  return SecInitError;
}
static AntStatus SecORBError(AntStatus::AntError,801);
inline AntStatus
SecErrORB(AntErrorSeverity severity
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
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","ORB"),arg0);
  return SecORBError;
}
static AntStatus SecHostServerError(AntStatus::AntError,802);
inline AntStatus
SecErrHostServer(AntErrorSeverity severity
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
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","HostServer"),arg0);
  return SecHostServerError;
}
static AntStatus SecFunctionError(AntStatus::AntError,803);
inline AntStatus
SecErrFunction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Function",
              source,
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","Function"),arg0);
  return SecFunctionError;
}
static AntStatus SecUserNameNotValidError(AntStatus::AntError,804);
inline AntStatus
SecErrUserNameNotValid(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UserNameNotValid",
              source,
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","UserNameNotValid"),arg0);
  return SecUserNameNotValidError;
}
static AntStatus SecUserFileOpenError(AntStatus::AntError,805);
inline AntStatus
SecErrUserFileOpen(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UserFileOpen",
              source,
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","UserFileOpen"),arg0);
  return SecUserFileOpenError;
}
static AntStatus SecUserFileIOError(AntStatus::AntError,806);
inline AntStatus
SecErrUserFileIO(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UserFileIO",
              source,
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","UserFileIO"),arg0);
  return SecUserFileIOError;
}
static AntStatus SecProfileAlreadyLoadedError(AntStatus::AntError,807);
inline AntStatus
SecErrProfileAlreadyLoaded(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ProfileAlreadyLoaded",
              source,
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","ProfileAlreadyLoaded"),arg0);
  return SecProfileAlreadyLoadedError;
}
static AntStatus SecProfileNotFoundError(AntStatus::AntError,808);
inline AntStatus
SecErrProfileNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ProfileNotFound",
              source,
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","ProfileNotFound"),arg0);
  return SecProfileNotFoundError;
}
static AntStatus SecGetGroupMaskError(AntStatus::AntError,809);
inline AntStatus
SecErrGetGroupMask(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GetGroupMask",
              source,
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","GetGroupMask"),arg0);
  return SecGetGroupMaskError;
}
static AntStatus SecGetReadCategoriesError(AntStatus::AntError,810);
inline AntStatus
SecErrGetReadCategories(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GetReadCategories",
              source,
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","GetReadCategories"),arg0);
  return SecGetReadCategoriesError;
}
static AntStatus SecGetWriteCategoriesError(AntStatus::AntError,811);
inline AntStatus
SecErrGetWriteCategories(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GetWriteCategories",
              source,
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","GetWriteCategories"),arg0);
  return SecGetWriteCategoriesError;
}
static AntStatus SecGetApplicationListError(AntStatus::AntError,812);
inline AntStatus
SecErrGetApplicationList(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GetApplicationList",
              source,
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","GetApplicationList"),arg0);
  return SecGetApplicationListError;
}
static AntStatus SecTimeoutError(AntStatus::AntError,813);
inline AntStatus
SecErrTimeout(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Timeout",
              source,
              "Sec",
              AntTrace::trace().getErrorFormat("secerror.emf","Sec","Timeout"),arg0,arg1);
  return SecTimeoutError;
}
inline const char *
SecGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 800:
    return "Init";
  case 801:
    return "ORB";
  case 802:
    return "HostServer";
  case 803:
    return "Function";
  case 804:
    return "UserNameNotValid";
  case 805:
    return "UserFileOpen";
  case 806:
    return "UserFileIO";
  case 807:
    return "ProfileAlreadyLoaded";
  case 808:
    return "ProfileNotFound";
  case 809:
    return "GetGroupMask";
  case 810:
    return "GetReadCategories";
  case 811:
    return "GetWriteCategories";
  case 812:
    return "GetApplicationList";
  case 813:
    return "Timeout";
  default:
    return "";
  }
}
#endif
