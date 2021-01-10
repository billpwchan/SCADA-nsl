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
#ifndef _AN_OLSERROR_H
#define _AN_OLSERROR_H
static AntStatus OlsInitError(AntStatus::AntError,400);
inline AntStatus
OlsErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","Init"));
  return OlsInitError;
}
static AntStatus OlsORBError(AntStatus::AntError,401);
inline AntStatus
OlsErrORB(AntErrorSeverity severity
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
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","ORB"),arg0);
  return OlsORBError;
}
static AntStatus OlsHostServerError(AntStatus::AntError,402);
inline AntStatus
OlsErrHostServer(AntErrorSeverity severity
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
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","HostServer"),arg0);
  return OlsHostServerError;
}
static AntStatus OlsBadFilterError(AntStatus::AntError,403);
inline AntStatus
OlsErrBadFilter(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadFilter",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","BadFilter"));
  return OlsBadFilterError;
}
static AntStatus OlsAlreadyDefinedFilterError(AntStatus::AntError,404);
inline AntStatus
OlsErrAlreadyDefinedFilter(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AlreadyDefinedFilter",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","AlreadyDefinedFilter"),arg0);
  return OlsAlreadyDefinedFilterError;
}
static AntStatus OlsUnknownFilterError(AntStatus::AntError,405);
inline AntStatus
OlsErrUnknownFilter(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownFilter",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","UnknownFilter"),arg0);
  return OlsUnknownFilterError;
}
static AntStatus OlsBadSubscriptionIdError(AntStatus::AntError,406);
inline AntStatus
OlsErrBadSubscriptionId(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadSubscriptionId",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","BadSubscriptionId"),arg0);
  return OlsBadSubscriptionIdError;
}
static AntStatus OlsBadDataKeyError(AntStatus::AntError,407);
inline AntStatus
OlsErrBadDataKey(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadDataKey",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","BadDataKey"),arg0);
  return OlsBadDataKeyError;
}
static AntStatus OlsBadListNameError(AntStatus::AntError,408);
inline AntStatus
OlsErrBadListName(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadListName",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","BadListName"),arg0);
  return OlsBadListNameError;
}
static AntStatus OlsDataModeUndefinedError(AntStatus::AntError,409);
inline AntStatus
OlsErrDataModeUndefined(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DataModeUndefined",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","DataModeUndefined"));
  return OlsDataModeUndefinedError;
}
static AntStatus OlsBadDataModeError(AntStatus::AntError,410);
inline AntStatus
OlsErrBadDataMode(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadDataMode",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","BadDataMode"));
  return OlsBadDataModeError;
}
static AntStatus OlsNoTimeFieldError(AntStatus::AntError,411);
inline AntStatus
OlsErrNoTimeField(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoTimeField",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","NoTimeField"));
  return OlsNoTimeFieldError;
}
static AntStatus OlsBadPathnameError(AntStatus::AntError,412);
inline AntStatus
OlsErrBadPathname(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadPathname",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","BadPathname"),arg0);
  return OlsBadPathnameError;
}
static AntStatus OlsCreateDirectoryError(AntStatus::AntError,413);
inline AntStatus
OlsErrCreateDirectory(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CreateDirectory",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","CreateDirectory"),arg0);
  return OlsCreateDirectoryError;
}
static AntStatus OlsCreateFileError(AntStatus::AntError,414);
inline AntStatus
OlsErrCreateFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CreateFile",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","CreateFile"),arg0);
  return OlsCreateFileError;
}
static AntStatus OlsOpenFileError(AntStatus::AntError,415);
inline AntStatus
OlsErrOpenFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "OpenFile",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","OpenFile"),arg0);
  return OlsOpenFileError;
}
static AntStatus OlsDeleteFileError(AntStatus::AntError,416);
inline AntStatus
OlsErrDeleteFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DeleteFile",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","DeleteFile"),arg0);
  return OlsDeleteFileError;
}
static AntStatus OlsWarningRemoveFileError(AntStatus::AntError,417);
inline AntStatus
OlsErrWarningRemoveFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WarningRemoveFile",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","WarningRemoveFile"),arg0,arg1);
  return OlsWarningRemoveFileError;
}
static AntStatus OlsTimeoutError(AntStatus::AntError,418);
inline AntStatus
OlsErrTimeout(AntErrorSeverity severity
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
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","Timeout"),arg0,arg1);
  return OlsTimeoutError;
}
static AntStatus OlsNoClientError(AntStatus::AntError,419);
inline AntStatus
OlsErrNoClient(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1,const  char * arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoClient",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","NoClient"),arg0,arg1,arg2);
  return OlsNoClientError;
}
static AntStatus OlsNoMoreClientError(AntStatus::AntError,420);
inline AntStatus
OlsErrNoMoreClient(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoMoreClient",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","NoMoreClient"),arg0,arg1);
  return OlsNoMoreClientError;
}
static AntStatus OlsCallbackError(AntStatus::AntError,421);
inline AntStatus
OlsErrCallback(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Callback",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","Callback"));
  return OlsCallbackError;
}
static AntStatus OlsCannotLinkError(AntStatus::AntError,422);
inline AntStatus
OlsErrCannotLink(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CannotLink",
              source,
              "Ols",
              AntTrace::trace().getErrorFormat("olserror.emf","Ols","CannotLink"),arg0,arg1);
  return OlsCannotLinkError;
}
inline const char *
OlsGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 400:
    return "Init";
  case 401:
    return "ORB";
  case 402:
    return "HostServer";
  case 403:
    return "BadFilter";
  case 404:
    return "AlreadyDefinedFilter";
  case 405:
    return "UnknownFilter";
  case 406:
    return "BadSubscriptionId";
  case 407:
    return "BadDataKey";
  case 408:
    return "BadListName";
  case 409:
    return "DataModeUndefined";
  case 410:
    return "BadDataMode";
  case 411:
    return "NoTimeField";
  case 412:
    return "BadPathname";
  case 413:
    return "CreateDirectory";
  case 414:
    return "CreateFile";
  case 415:
    return "OpenFile";
  case 416:
    return "DeleteFile";
  case 417:
    return "WarningRemoveFile";
  case 418:
    return "Timeout";
  case 419:
    return "NoClient";
  case 420:
    return "NoMoreClient";
  case 421:
    return "Callback";
  case 422:
    return "CannotLink";
  default:
    return "";
  }
}
#endif
