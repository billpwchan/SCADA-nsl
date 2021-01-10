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
#ifndef _AN_DBMREADERERROR_H
#define _AN_DBMREADERERROR_H
static AntStatus DbmReaderInitError(AntStatus::AntError,2200);
inline AntStatus
DbmReaderErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","Init"));
  return DbmReaderInitError;
}
static AntStatus DbmReaderORBError(AntStatus::AntError,2201);
inline AntStatus
DbmReaderErrORB(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","ORB"),arg0);
  return DbmReaderORBError;
}
static AntStatus DbmReaderHostServerError(AntStatus::AntError,2202);
inline AntStatus
DbmReaderErrHostServer(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","HostServer"),arg0);
  return DbmReaderHostServerError;
}
static AntStatus DbmReaderDataBaseConnectionError(AntStatus::AntError,2203);
inline AntStatus
DbmReaderErrDataBaseConnection(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","DataBaseConnection"),arg0);
  return DbmReaderDataBaseConnectionError;
}
static AntStatus DbmReaderPermissionDeniedError(AntStatus::AntError,2204);
inline AntStatus
DbmReaderErrPermissionDenied(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","PermissionDenied"),arg0,arg1);
  return DbmReaderPermissionDeniedError;
}
static AntStatus DbmReaderProfileNotFoundError(AntStatus::AntError,2205);
inline AntStatus
DbmReaderErrProfileNotFound(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","ProfileNotFound"),arg0);
  return DbmReaderProfileNotFoundError;
}
static AntStatus DbmReaderBadReferenceError(AntStatus::AntError,2206);
inline AntStatus
DbmReaderErrBadReference(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadReference",
              source,
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","BadReference"));
  return DbmReaderBadReferenceError;
}
static AntStatus DbmReaderReadErrorError(AntStatus::AntError,2207);
inline AntStatus
DbmReaderErrReadError(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ReadError",
              source,
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","ReadError"));
  return DbmReaderReadErrorError;
}
static AntStatus DbmReaderWriteErrorError(AntStatus::AntError,2208);
inline AntStatus
DbmReaderErrWriteError(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WriteError",
              source,
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","WriteError"));
  return DbmReaderWriteErrorError;
}
static AntStatus DbmReaderDataConversionError(AntStatus::AntError,2209);
inline AntStatus
DbmReaderErrDataConversion(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","DataConversion"),arg0);
  return DbmReaderDataConversionError;
}
static AntStatus DbmReaderGroupUnknownError(AntStatus::AntError,2210);
inline AntStatus
DbmReaderErrGroupUnknown(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","GroupUnknown"),arg0);
  return DbmReaderGroupUnknownError;
}
static AntStatus DbmReaderGroupAlreadyExistError(AntStatus::AntError,2211);
inline AntStatus
DbmReaderErrGroupAlreadyExist(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","GroupAlreadyExist"),arg0);
  return DbmReaderGroupAlreadyExistError;
}
static AntStatus DbmReaderGroupCreationError(AntStatus::AntError,2212);
inline AntStatus
DbmReaderErrGroupCreation(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","GroupCreation"),arg0);
  return DbmReaderGroupCreationError;
}
static AntStatus DbmReaderGroupDeletionError(AntStatus::AntError,2213);
inline AntStatus
DbmReaderErrGroupDeletion(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","GroupDeletion"),arg0);
  return DbmReaderGroupDeletionError;
}
static AntStatus DbmReaderGroupDescriptionError(AntStatus::AntError,2214);
inline AntStatus
DbmReaderErrGroupDescription(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","GroupDescription"),arg0);
  return DbmReaderGroupDescriptionError;
}
static AntStatus DbmReaderGroupSubscriptionError(AntStatus::AntError,2215);
inline AntStatus
DbmReaderErrGroupSubscription(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","GroupSubscription"),arg0);
  return DbmReaderGroupSubscriptionError;
}
static AntStatus DbmReaderGroupUnsubscriptionError(AntStatus::AntError,2216);
inline AntStatus
DbmReaderErrGroupUnsubscription(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","GroupUnsubscription"),arg0);
  return DbmReaderGroupUnsubscriptionError;
}
static AntStatus DbmReaderSubscriptionNotFoundError(AntStatus::AntError,2217);
inline AntStatus
DbmReaderErrSubscriptionNotFound(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","SubscriptionNotFound"),arg0);
  return DbmReaderSubscriptionNotFoundError;
}
static AntStatus DbmReaderFileCreationError(AntStatus::AntError,2218);
inline AntStatus
DbmReaderErrFileCreation(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","FileCreation"),arg0);
  return DbmReaderFileCreationError;
}
static AntStatus DbmReaderFileDeletionError(AntStatus::AntError,2219);
inline AntStatus
DbmReaderErrFileDeletion(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","FileDeletion"),arg0);
  return DbmReaderFileDeletionError;
}
static AntStatus DbmReaderFileNotFoundError(AntStatus::AntError,2220);
inline AntStatus
DbmReaderErrFileNotFound(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","FileNotFound"),arg0);
  return DbmReaderFileNotFoundError;
}
static AntStatus DbmReaderRtapFunctionError(AntStatus::AntError,2221);
inline AntStatus
DbmReaderErrRtapFunction(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","RtapFunction"),arg0);
  return DbmReaderRtapFunctionError;
}
static AntStatus DbmReaderRtapCommunicationError(AntStatus::AntError,2222);
inline AntStatus
DbmReaderErrRtapCommunication(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RtapCommunication",
              source,
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","RtapCommunication"));
  return DbmReaderRtapCommunicationError;
}
static AntStatus DbmReaderFunctionError(AntStatus::AntError,2223);
inline AntStatus
DbmReaderErrFunction(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","Function"),arg0);
  return DbmReaderFunctionError;
}
static AntStatus DbmReaderWriteSecurityError(AntStatus::AntError,2224);
inline AntStatus
DbmReaderErrWriteSecurity(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","WriteSecurity"),arg0);
  return DbmReaderWriteSecurityError;
}
static AntStatus DbmReaderTimeoutError(AntStatus::AntError,2225);
inline AntStatus
DbmReaderErrTimeout(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","Timeout"),arg0,arg1);
  return DbmReaderTimeoutError;
}
static AntStatus DbmReaderFormulaSyntaxError(AntStatus::AntError,2226);
inline AntStatus
DbmReaderErrFormulaSyntax(AntErrorSeverity severity
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
              "DbmReader",
              AntTrace::trace().getErrorFormat("dbmreadererror.emf","DbmReader","FormulaSyntax"),arg0);
  return DbmReaderFormulaSyntaxError;
}
inline const char *
DbmReaderGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 2200:
    return "Init";
  case 2201:
    return "ORB";
  case 2202:
    return "HostServer";
  case 2203:
    return "DataBaseConnection";
  case 2204:
    return "PermissionDenied";
  case 2205:
    return "ProfileNotFound";
  case 2206:
    return "BadReference";
  case 2207:
    return "ReadError";
  case 2208:
    return "WriteError";
  case 2209:
    return "DataConversion";
  case 2210:
    return "GroupUnknown";
  case 2211:
    return "GroupAlreadyExist";
  case 2212:
    return "GroupCreation";
  case 2213:
    return "GroupDeletion";
  case 2214:
    return "GroupDescription";
  case 2215:
    return "GroupSubscription";
  case 2216:
    return "GroupUnsubscription";
  case 2217:
    return "SubscriptionNotFound";
  case 2218:
    return "FileCreation";
  case 2219:
    return "FileDeletion";
  case 2220:
    return "FileNotFound";
  case 2221:
    return "RtapFunction";
  case 2222:
    return "RtapCommunication";
  case 2223:
    return "Function";
  case 2224:
    return "WriteSecurity";
  case 2225:
    return "Timeout";
  case 2226:
    return "FormulaSyntax";
  default:
    return "";
  }
}
#endif
