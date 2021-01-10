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
!! at Fri Nov 15 16:14:22 2013
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
*/
#ifndef _AN_DBMPOLLERERROR_H
#define _AN_DBMPOLLERERROR_H
static AntStatus DbmPollerInitError(AntStatus::AntError,2400);
inline AntStatus
DbmPollerErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","Init"));
  return DbmPollerInitError;
}
static AntStatus DbmPollerORBError(AntStatus::AntError,2401);
inline AntStatus
DbmPollerErrORB(AntErrorSeverity severity
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
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","ORB"),arg0);
  return DbmPollerORBError;
}
static AntStatus DbmPollerHostServerError(AntStatus::AntError,2402);
inline AntStatus
DbmPollerErrHostServer(AntErrorSeverity severity
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
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","HostServer"),arg0);
  return DbmPollerHostServerError;
}
static AntStatus DbmPollerDataBaseConnectionError(AntStatus::AntError,2403);
inline AntStatus
DbmPollerErrDataBaseConnection(AntErrorSeverity severity
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
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","DataBaseConnection"),arg0);
  return DbmPollerDataBaseConnectionError;
}
static AntStatus DbmPollerPermissionDeniedError(AntStatus::AntError,2404);
inline AntStatus
DbmPollerErrPermissionDenied(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "PermissionDenied",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","PermissionDenied"),arg0,arg1);
  return DbmPollerPermissionDeniedError;
}
static AntStatus DbmPollerProfileNotFoundError(AntStatus::AntError,2405);
inline AntStatus
DbmPollerErrProfileNotFound(AntErrorSeverity severity
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
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","ProfileNotFound"),arg0);
  return DbmPollerProfileNotFoundError;
}
static AntStatus DbmPollerBadReferenceError(AntStatus::AntError,2406);
inline AntStatus
DbmPollerErrBadReference(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadReference",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","BadReference"));
  return DbmPollerBadReferenceError;
}
static AntStatus DbmPollerReadErrorError(AntStatus::AntError,2407);
inline AntStatus
DbmPollerErrReadError(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ReadError",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","ReadError"));
  return DbmPollerReadErrorError;
}
static AntStatus DbmPollerWriteErrorError(AntStatus::AntError,2408);
inline AntStatus
DbmPollerErrWriteError(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WriteError",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","WriteError"));
  return DbmPollerWriteErrorError;
}
static AntStatus DbmPollerDataConversionError(AntStatus::AntError,2409);
inline AntStatus
DbmPollerErrDataConversion(AntErrorSeverity severity
      ,short line, const char* file
      ,const  int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DataConversion",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","DataConversion"),arg0);
  return DbmPollerDataConversionError;
}
static AntStatus DbmPollerGroupUnknownError(AntStatus::AntError,2410);
inline AntStatus
DbmPollerErrGroupUnknown(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GroupUnknown",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","GroupUnknown"),arg0);
  return DbmPollerGroupUnknownError;
}
static AntStatus DbmPollerGroupAlreadyExistError(AntStatus::AntError,2411);
inline AntStatus
DbmPollerErrGroupAlreadyExist(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GroupAlreadyExist",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","GroupAlreadyExist"),arg0);
  return DbmPollerGroupAlreadyExistError;
}
static AntStatus DbmPollerGroupCreationError(AntStatus::AntError,2412);
inline AntStatus
DbmPollerErrGroupCreation(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GroupCreation",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","GroupCreation"),arg0);
  return DbmPollerGroupCreationError;
}
static AntStatus DbmPollerGroupDeletionError(AntStatus::AntError,2413);
inline AntStatus
DbmPollerErrGroupDeletion(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GroupDeletion",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","GroupDeletion"),arg0);
  return DbmPollerGroupDeletionError;
}
static AntStatus DbmPollerGroupDescriptionError(AntStatus::AntError,2414);
inline AntStatus
DbmPollerErrGroupDescription(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GroupDescription",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","GroupDescription"),arg0);
  return DbmPollerGroupDescriptionError;
}
static AntStatus DbmPollerGroupSubscriptionError(AntStatus::AntError,2415);
inline AntStatus
DbmPollerErrGroupSubscription(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GroupSubscription",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","GroupSubscription"),arg0);
  return DbmPollerGroupSubscriptionError;
}
static AntStatus DbmPollerGroupUnsubscriptionError(AntStatus::AntError,2416);
inline AntStatus
DbmPollerErrGroupUnsubscription(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GroupUnsubscription",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","GroupUnsubscription"),arg0);
  return DbmPollerGroupUnsubscriptionError;
}
static AntStatus DbmPollerSubscriptionNotFoundError(AntStatus::AntError,2417);
inline AntStatus
DbmPollerErrSubscriptionNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SubscriptionNotFound",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","SubscriptionNotFound"),arg0);
  return DbmPollerSubscriptionNotFoundError;
}
static AntStatus DbmPollerFileCreationError(AntStatus::AntError,2418);
inline AntStatus
DbmPollerErrFileCreation(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FileCreation",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","FileCreation"),arg0);
  return DbmPollerFileCreationError;
}
static AntStatus DbmPollerFileDeletionError(AntStatus::AntError,2419);
inline AntStatus
DbmPollerErrFileDeletion(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FileDeletion",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","FileDeletion"),arg0);
  return DbmPollerFileDeletionError;
}
static AntStatus DbmPollerFileNotFoundError(AntStatus::AntError,2420);
inline AntStatus
DbmPollerErrFileNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FileNotFound",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","FileNotFound"),arg0);
  return DbmPollerFileNotFoundError;
}
static AntStatus DbmPollerRtapFunctionError(AntStatus::AntError,2421);
inline AntStatus
DbmPollerErrRtapFunction(AntErrorSeverity severity
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
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","RtapFunction"),arg0);
  return DbmPollerRtapFunctionError;
}
static AntStatus DbmPollerRtapCommunicationError(AntStatus::AntError,2422);
inline AntStatus
DbmPollerErrRtapCommunication(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RtapCommunication",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","RtapCommunication"));
  return DbmPollerRtapCommunicationError;
}
static AntStatus DbmPollerFunctionError(AntStatus::AntError,2423);
inline AntStatus
DbmPollerErrFunction(AntErrorSeverity severity
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
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","Function"),arg0);
  return DbmPollerFunctionError;
}
static AntStatus DbmPollerWriteSecurityError(AntStatus::AntError,2424);
inline AntStatus
DbmPollerErrWriteSecurity(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WriteSecurity",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","WriteSecurity"),arg0);
  return DbmPollerWriteSecurityError;
}
static AntStatus DbmPollerTimeoutError(AntStatus::AntError,2425);
inline AntStatus
DbmPollerErrTimeout(AntErrorSeverity severity
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
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","Timeout"),arg0,arg1);
  return DbmPollerTimeoutError;
}
static AntStatus DbmPollerFormulaSyntaxError(AntStatus::AntError,2426);
inline AntStatus
DbmPollerErrFormulaSyntax(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FormulaSyntax",
              source,
              "DbmPoller",
              AntTrace::trace().getErrorFormat("dbmpollererror.emf","DbmPoller","FormulaSyntax"),arg0);
  return DbmPollerFormulaSyntaxError;
}
inline const char *
DbmPollerGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 2400:
    return "Init";
  case 2401:
    return "ORB";
  case 2402:
    return "HostServer";
  case 2403:
    return "DataBaseConnection";
  case 2404:
    return "PermissionDenied";
  case 2405:
    return "ProfileNotFound";
  case 2406:
    return "BadReference";
  case 2407:
    return "ReadError";
  case 2408:
    return "WriteError";
  case 2409:
    return "DataConversion";
  case 2410:
    return "GroupUnknown";
  case 2411:
    return "GroupAlreadyExist";
  case 2412:
    return "GroupCreation";
  case 2413:
    return "GroupDeletion";
  case 2414:
    return "GroupDescription";
  case 2415:
    return "GroupSubscription";
  case 2416:
    return "GroupUnsubscription";
  case 2417:
    return "SubscriptionNotFound";
  case 2418:
    return "FileCreation";
  case 2419:
    return "FileDeletion";
  case 2420:
    return "FileNotFound";
  case 2421:
    return "RtapFunction";
  case 2422:
    return "RtapCommunication";
  case 2423:
    return "Function";
  case 2424:
    return "WriteSecurity";
  case 2425:
    return "Timeout";
  case 2426:
    return "FormulaSyntax";
  default:
    return "";
  }
}
#endif
