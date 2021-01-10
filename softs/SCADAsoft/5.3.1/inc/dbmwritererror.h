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
#ifndef _AN_DBMWRITERERROR_H
#define _AN_DBMWRITERERROR_H
static AntStatus DbmWriterInitError(AntStatus::AntError,2300);
inline AntStatus
DbmWriterErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","Init"));
  return DbmWriterInitError;
}
static AntStatus DbmWriterORBError(AntStatus::AntError,2301);
inline AntStatus
DbmWriterErrORB(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","ORB"),arg0);
  return DbmWriterORBError;
}
static AntStatus DbmWriterHostServerError(AntStatus::AntError,2302);
inline AntStatus
DbmWriterErrHostServer(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","HostServer"),arg0);
  return DbmWriterHostServerError;
}
static AntStatus DbmWriterDataBaseConnectionError(AntStatus::AntError,2303);
inline AntStatus
DbmWriterErrDataBaseConnection(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","DataBaseConnection"),arg0);
  return DbmWriterDataBaseConnectionError;
}
static AntStatus DbmWriterPermissionDeniedError(AntStatus::AntError,2304);
inline AntStatus
DbmWriterErrPermissionDenied(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","PermissionDenied"),arg0,arg1);
  return DbmWriterPermissionDeniedError;
}
static AntStatus DbmWriterProfileNotFoundError(AntStatus::AntError,2305);
inline AntStatus
DbmWriterErrProfileNotFound(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","ProfileNotFound"),arg0);
  return DbmWriterProfileNotFoundError;
}
static AntStatus DbmWriterBadReferenceError(AntStatus::AntError,2306);
inline AntStatus
DbmWriterErrBadReference(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadReference",
              source,
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","BadReference"));
  return DbmWriterBadReferenceError;
}
static AntStatus DbmWriterReadErrorError(AntStatus::AntError,2307);
inline AntStatus
DbmWriterErrReadError(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ReadError",
              source,
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","ReadError"));
  return DbmWriterReadErrorError;
}
static AntStatus DbmWriterWriteErrorError(AntStatus::AntError,2308);
inline AntStatus
DbmWriterErrWriteError(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WriteError",
              source,
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","WriteError"));
  return DbmWriterWriteErrorError;
}
static AntStatus DbmWriterDataConversionError(AntStatus::AntError,2309);
inline AntStatus
DbmWriterErrDataConversion(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","DataConversion"),arg0);
  return DbmWriterDataConversionError;
}
static AntStatus DbmWriterGroupUnknownError(AntStatus::AntError,2310);
inline AntStatus
DbmWriterErrGroupUnknown(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","GroupUnknown"),arg0);
  return DbmWriterGroupUnknownError;
}
static AntStatus DbmWriterGroupAlreadyExistError(AntStatus::AntError,2311);
inline AntStatus
DbmWriterErrGroupAlreadyExist(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","GroupAlreadyExist"),arg0);
  return DbmWriterGroupAlreadyExistError;
}
static AntStatus DbmWriterGroupCreationError(AntStatus::AntError,2312);
inline AntStatus
DbmWriterErrGroupCreation(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","GroupCreation"),arg0);
  return DbmWriterGroupCreationError;
}
static AntStatus DbmWriterGroupDeletionError(AntStatus::AntError,2313);
inline AntStatus
DbmWriterErrGroupDeletion(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","GroupDeletion"),arg0);
  return DbmWriterGroupDeletionError;
}
static AntStatus DbmWriterGroupDescriptionError(AntStatus::AntError,2314);
inline AntStatus
DbmWriterErrGroupDescription(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","GroupDescription"),arg0);
  return DbmWriterGroupDescriptionError;
}
static AntStatus DbmWriterGroupSubscriptionError(AntStatus::AntError,2315);
inline AntStatus
DbmWriterErrGroupSubscription(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","GroupSubscription"),arg0);
  return DbmWriterGroupSubscriptionError;
}
static AntStatus DbmWriterGroupUnsubscriptionError(AntStatus::AntError,2316);
inline AntStatus
DbmWriterErrGroupUnsubscription(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","GroupUnsubscription"),arg0);
  return DbmWriterGroupUnsubscriptionError;
}
static AntStatus DbmWriterSubscriptionNotFoundError(AntStatus::AntError,2317);
inline AntStatus
DbmWriterErrSubscriptionNotFound(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","SubscriptionNotFound"),arg0);
  return DbmWriterSubscriptionNotFoundError;
}
static AntStatus DbmWriterFileCreationError(AntStatus::AntError,2318);
inline AntStatus
DbmWriterErrFileCreation(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","FileCreation"),arg0);
  return DbmWriterFileCreationError;
}
static AntStatus DbmWriterFileDeletionError(AntStatus::AntError,2319);
inline AntStatus
DbmWriterErrFileDeletion(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","FileDeletion"),arg0);
  return DbmWriterFileDeletionError;
}
static AntStatus DbmWriterFileNotFoundError(AntStatus::AntError,2320);
inline AntStatus
DbmWriterErrFileNotFound(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","FileNotFound"),arg0);
  return DbmWriterFileNotFoundError;
}
static AntStatus DbmWriterRtapFunctionError(AntStatus::AntError,2321);
inline AntStatus
DbmWriterErrRtapFunction(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","RtapFunction"),arg0);
  return DbmWriterRtapFunctionError;
}
static AntStatus DbmWriterRtapCommunicationError(AntStatus::AntError,2322);
inline AntStatus
DbmWriterErrRtapCommunication(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RtapCommunication",
              source,
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","RtapCommunication"));
  return DbmWriterRtapCommunicationError;
}
static AntStatus DbmWriterFunctionError(AntStatus::AntError,2323);
inline AntStatus
DbmWriterErrFunction(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","Function"),arg0);
  return DbmWriterFunctionError;
}
static AntStatus DbmWriterWriteSecurityError(AntStatus::AntError,2324);
inline AntStatus
DbmWriterErrWriteSecurity(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","WriteSecurity"),arg0);
  return DbmWriterWriteSecurityError;
}
static AntStatus DbmWriterTimeoutError(AntStatus::AntError,2325);
inline AntStatus
DbmWriterErrTimeout(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","Timeout"),arg0,arg1);
  return DbmWriterTimeoutError;
}
static AntStatus DbmWriterFormulaSyntaxError(AntStatus::AntError,2326);
inline AntStatus
DbmWriterErrFormulaSyntax(AntErrorSeverity severity
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
              "DbmWriter",
              AntTrace::trace().getErrorFormat("dbmwritererror.emf","DbmWriter","FormulaSyntax"),arg0);
  return DbmWriterFormulaSyntaxError;
}
inline const char *
DbmWriterGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 2300:
    return "Init";
  case 2301:
    return "ORB";
  case 2302:
    return "HostServer";
  case 2303:
    return "DataBaseConnection";
  case 2304:
    return "PermissionDenied";
  case 2305:
    return "ProfileNotFound";
  case 2306:
    return "BadReference";
  case 2307:
    return "ReadError";
  case 2308:
    return "WriteError";
  case 2309:
    return "DataConversion";
  case 2310:
    return "GroupUnknown";
  case 2311:
    return "GroupAlreadyExist";
  case 2312:
    return "GroupCreation";
  case 2313:
    return "GroupDeletion";
  case 2314:
    return "GroupDescription";
  case 2315:
    return "GroupSubscription";
  case 2316:
    return "GroupUnsubscription";
  case 2317:
    return "SubscriptionNotFound";
  case 2318:
    return "FileCreation";
  case 2319:
    return "FileDeletion";
  case 2320:
    return "FileNotFound";
  case 2321:
    return "RtapFunction";
  case 2322:
    return "RtapCommunication";
  case 2323:
    return "Function";
  case 2324:
    return "WriteSecurity";
  case 2325:
    return "Timeout";
  case 2326:
    return "FormulaSyntax";
  default:
    return "";
  }
}
#endif
