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
#ifndef _AN_DBMCONFIGERROR_H
#define _AN_DBMCONFIGERROR_H
static AntStatus DbmConfigInitError(AntStatus::AntError,2100);
inline AntStatus
DbmConfigErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","Init"));
  return DbmConfigInitError;
}
static AntStatus DbmConfigORBError(AntStatus::AntError,2101);
inline AntStatus
DbmConfigErrORB(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","ORB"),arg0);
  return DbmConfigORBError;
}
static AntStatus DbmConfigHostServerError(AntStatus::AntError,2102);
inline AntStatus
DbmConfigErrHostServer(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","HostServer"),arg0);
  return DbmConfigHostServerError;
}
static AntStatus DbmConfigDataBaseConnectionError(AntStatus::AntError,2103);
inline AntStatus
DbmConfigErrDataBaseConnection(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","DataBaseConnection"),arg0);
  return DbmConfigDataBaseConnectionError;
}
static AntStatus DbmConfigPermissionDeniedError(AntStatus::AntError,2104);
inline AntStatus
DbmConfigErrPermissionDenied(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","PermissionDenied"),arg0,arg1);
  return DbmConfigPermissionDeniedError;
}
static AntStatus DbmConfigProfileNotFoundError(AntStatus::AntError,2105);
inline AntStatus
DbmConfigErrProfileNotFound(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","ProfileNotFound"),arg0);
  return DbmConfigProfileNotFoundError;
}
static AntStatus DbmConfigBadReferenceError(AntStatus::AntError,2106);
inline AntStatus
DbmConfigErrBadReference(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadReference",
              source,
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","BadReference"));
  return DbmConfigBadReferenceError;
}
static AntStatus DbmConfigReadErrorError(AntStatus::AntError,2107);
inline AntStatus
DbmConfigErrReadError(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ReadError",
              source,
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","ReadError"));
  return DbmConfigReadErrorError;
}
static AntStatus DbmConfigWriteErrorError(AntStatus::AntError,2108);
inline AntStatus
DbmConfigErrWriteError(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WriteError",
              source,
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","WriteError"));
  return DbmConfigWriteErrorError;
}
static AntStatus DbmConfigDataConversionError(AntStatus::AntError,2109);
inline AntStatus
DbmConfigErrDataConversion(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","DataConversion"),arg0);
  return DbmConfigDataConversionError;
}
static AntStatus DbmConfigGroupUnknownError(AntStatus::AntError,2110);
inline AntStatus
DbmConfigErrGroupUnknown(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","GroupUnknown"),arg0);
  return DbmConfigGroupUnknownError;
}
static AntStatus DbmConfigGroupAlreadyExistError(AntStatus::AntError,2111);
inline AntStatus
DbmConfigErrGroupAlreadyExist(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","GroupAlreadyExist"),arg0);
  return DbmConfigGroupAlreadyExistError;
}
static AntStatus DbmConfigGroupCreationError(AntStatus::AntError,2112);
inline AntStatus
DbmConfigErrGroupCreation(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","GroupCreation"),arg0);
  return DbmConfigGroupCreationError;
}
static AntStatus DbmConfigGroupDeletionError(AntStatus::AntError,2113);
inline AntStatus
DbmConfigErrGroupDeletion(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","GroupDeletion"),arg0);
  return DbmConfigGroupDeletionError;
}
static AntStatus DbmConfigGroupDescriptionError(AntStatus::AntError,2114);
inline AntStatus
DbmConfigErrGroupDescription(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","GroupDescription"),arg0);
  return DbmConfigGroupDescriptionError;
}
static AntStatus DbmConfigGroupSubscriptionError(AntStatus::AntError,2115);
inline AntStatus
DbmConfigErrGroupSubscription(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","GroupSubscription"),arg0);
  return DbmConfigGroupSubscriptionError;
}
static AntStatus DbmConfigGroupUnsubscriptionError(AntStatus::AntError,2116);
inline AntStatus
DbmConfigErrGroupUnsubscription(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","GroupUnsubscription"),arg0);
  return DbmConfigGroupUnsubscriptionError;
}
static AntStatus DbmConfigSubscriptionNotFoundError(AntStatus::AntError,2117);
inline AntStatus
DbmConfigErrSubscriptionNotFound(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","SubscriptionNotFound"),arg0);
  return DbmConfigSubscriptionNotFoundError;
}
static AntStatus DbmConfigFileCreationError(AntStatus::AntError,2118);
inline AntStatus
DbmConfigErrFileCreation(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","FileCreation"),arg0);
  return DbmConfigFileCreationError;
}
static AntStatus DbmConfigFileDeletionError(AntStatus::AntError,2119);
inline AntStatus
DbmConfigErrFileDeletion(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","FileDeletion"),arg0);
  return DbmConfigFileDeletionError;
}
static AntStatus DbmConfigFileNotFoundError(AntStatus::AntError,2120);
inline AntStatus
DbmConfigErrFileNotFound(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","FileNotFound"),arg0);
  return DbmConfigFileNotFoundError;
}
static AntStatus DbmConfigRtapFunctionError(AntStatus::AntError,2121);
inline AntStatus
DbmConfigErrRtapFunction(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","RtapFunction"),arg0);
  return DbmConfigRtapFunctionError;
}
static AntStatus DbmConfigRtapCommunicationError(AntStatus::AntError,2122);
inline AntStatus
DbmConfigErrRtapCommunication(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RtapCommunication",
              source,
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","RtapCommunication"));
  return DbmConfigRtapCommunicationError;
}
static AntStatus DbmConfigFunctionError(AntStatus::AntError,2123);
inline AntStatus
DbmConfigErrFunction(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","Function"),arg0);
  return DbmConfigFunctionError;
}
static AntStatus DbmConfigWriteSecurityError(AntStatus::AntError,2124);
inline AntStatus
DbmConfigErrWriteSecurity(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","WriteSecurity"),arg0);
  return DbmConfigWriteSecurityError;
}
static AntStatus DbmConfigTimeoutError(AntStatus::AntError,2125);
inline AntStatus
DbmConfigErrTimeout(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","Timeout"),arg0,arg1);
  return DbmConfigTimeoutError;
}
static AntStatus DbmConfigFormulaSyntaxError(AntStatus::AntError,2126);
inline AntStatus
DbmConfigErrFormulaSyntax(AntErrorSeverity severity
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
              "DbmConfig",
              AntTrace::trace().getErrorFormat("dbmconfigerror.emf","DbmConfig","FormulaSyntax"),arg0);
  return DbmConfigFormulaSyntaxError;
}
inline const char *
DbmConfigGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 2100:
    return "Init";
  case 2101:
    return "ORB";
  case 2102:
    return "HostServer";
  case 2103:
    return "DataBaseConnection";
  case 2104:
    return "PermissionDenied";
  case 2105:
    return "ProfileNotFound";
  case 2106:
    return "BadReference";
  case 2107:
    return "ReadError";
  case 2108:
    return "WriteError";
  case 2109:
    return "DataConversion";
  case 2110:
    return "GroupUnknown";
  case 2111:
    return "GroupAlreadyExist";
  case 2112:
    return "GroupCreation";
  case 2113:
    return "GroupDeletion";
  case 2114:
    return "GroupDescription";
  case 2115:
    return "GroupSubscription";
  case 2116:
    return "GroupUnsubscription";
  case 2117:
    return "SubscriptionNotFound";
  case 2118:
    return "FileCreation";
  case 2119:
    return "FileDeletion";
  case 2120:
    return "FileNotFound";
  case 2121:
    return "RtapFunction";
  case 2122:
    return "RtapCommunication";
  case 2123:
    return "Function";
  case 2124:
    return "WriteSecurity";
  case 2125:
    return "Timeout";
  case 2126:
    return "FormulaSyntax";
  default:
    return "";
  }
}
#endif
