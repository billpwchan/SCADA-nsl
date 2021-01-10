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
#ifndef _AN_DBMERROR_H
#define _AN_DBMERROR_H
static AntStatus DbmInitError(AntStatus::AntError,300);
inline AntStatus
DbmErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","Init"));
  return DbmInitError;
}
static AntStatus DbmORBError(AntStatus::AntError,301);
inline AntStatus
DbmErrORB(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","ORB"),arg0);
  return DbmORBError;
}
static AntStatus DbmHostServerError(AntStatus::AntError,302);
inline AntStatus
DbmErrHostServer(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","HostServer"),arg0);
  return DbmHostServerError;
}
static AntStatus DbmDataBaseConnectionError(AntStatus::AntError,303);
inline AntStatus
DbmErrDataBaseConnection(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","DataBaseConnection"),arg0);
  return DbmDataBaseConnectionError;
}
static AntStatus DbmPermissionDeniedError(AntStatus::AntError,304);
inline AntStatus
DbmErrPermissionDenied(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","PermissionDenied"),arg0,arg1);
  return DbmPermissionDeniedError;
}
static AntStatus DbmProfileNotFoundError(AntStatus::AntError,305);
inline AntStatus
DbmErrProfileNotFound(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","ProfileNotFound"),arg0);
  return DbmProfileNotFoundError;
}
static AntStatus DbmParameterError(AntStatus::AntError,306);
inline AntStatus
DbmErrParameter(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Parameter",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","Parameter"),arg0);
  return DbmParameterError;
}
static AntStatus DbmBadReferenceError(AntStatus::AntError,307);
inline AntStatus
DbmErrBadReference(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadReference",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","BadReference"));
  return DbmBadReferenceError;
}
static AntStatus DbmReadErrorError(AntStatus::AntError,308);
inline AntStatus
DbmErrReadError(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ReadError",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","ReadError"));
  return DbmReadErrorError;
}
static AntStatus DbmWriteErrorError(AntStatus::AntError,309);
inline AntStatus
DbmErrWriteError(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WriteError",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","WriteError"));
  return DbmWriteErrorError;
}
static AntStatus DbmDataConversionError(AntStatus::AntError,310);
inline AntStatus
DbmErrDataConversion(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","DataConversion"),arg0);
  return DbmDataConversionError;
}
static AntStatus DbmGroupUnknownError(AntStatus::AntError,311);
inline AntStatus
DbmErrGroupUnknown(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","GroupUnknown"),arg0);
  return DbmGroupUnknownError;
}
static AntStatus DbmGroupAlreadyExistError(AntStatus::AntError,312);
inline AntStatus
DbmErrGroupAlreadyExist(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","GroupAlreadyExist"),arg0);
  return DbmGroupAlreadyExistError;
}
static AntStatus DbmGroupCreationError(AntStatus::AntError,313);
inline AntStatus
DbmErrGroupCreation(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","GroupCreation"),arg0);
  return DbmGroupCreationError;
}
static AntStatus DbmGroupDeletionError(AntStatus::AntError,314);
inline AntStatus
DbmErrGroupDeletion(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","GroupDeletion"),arg0);
  return DbmGroupDeletionError;
}
static AntStatus DbmGroupDescriptionError(AntStatus::AntError,315);
inline AntStatus
DbmErrGroupDescription(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","GroupDescription"),arg0);
  return DbmGroupDescriptionError;
}
static AntStatus DbmGroupSubscriptionError(AntStatus::AntError,316);
inline AntStatus
DbmErrGroupSubscription(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","GroupSubscription"),arg0);
  return DbmGroupSubscriptionError;
}
static AntStatus DbmGroupUnsubscriptionError(AntStatus::AntError,317);
inline AntStatus
DbmErrGroupUnsubscription(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","GroupUnsubscription"),arg0);
  return DbmGroupUnsubscriptionError;
}
static AntStatus DbmSubscriptionNotFoundError(AntStatus::AntError,318);
inline AntStatus
DbmErrSubscriptionNotFound(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","SubscriptionNotFound"),arg0);
  return DbmSubscriptionNotFoundError;
}
static AntStatus DbmFileCreationError(AntStatus::AntError,319);
inline AntStatus
DbmErrFileCreation(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","FileCreation"),arg0);
  return DbmFileCreationError;
}
static AntStatus DbmFileDeletionError(AntStatus::AntError,320);
inline AntStatus
DbmErrFileDeletion(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","FileDeletion"),arg0);
  return DbmFileDeletionError;
}
static AntStatus DbmFileNotFoundError(AntStatus::AntError,321);
inline AntStatus
DbmErrFileNotFound(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","FileNotFound"),arg0);
  return DbmFileNotFoundError;
}
static AntStatus DbmRtapFunctionError(AntStatus::AntError,322);
inline AntStatus
DbmErrRtapFunction(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","RtapFunction"),arg0);
  return DbmRtapFunctionError;
}
static AntStatus DbmRtapCommunicationError(AntStatus::AntError,323);
inline AntStatus
DbmErrRtapCommunication(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RtapCommunication",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","RtapCommunication"));
  return DbmRtapCommunicationError;
}
static AntStatus DbmFunctionError(AntStatus::AntError,324);
inline AntStatus
DbmErrFunction(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","Function"),arg0);
  return DbmFunctionError;
}
static AntStatus DbmWriteSecurityError(AntStatus::AntError,325);
inline AntStatus
DbmErrWriteSecurity(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","WriteSecurity"),arg0);
  return DbmWriteSecurityError;
}
static AntStatus DbmTimeoutError(AntStatus::AntError,326);
inline AntStatus
DbmErrTimeout(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","Timeout"),arg0,arg1);
  return DbmTimeoutError;
}
static AntStatus DbmFormulaSyntaxError(AntStatus::AntError,327);
inline AntStatus
DbmErrFormulaSyntax(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","FormulaSyntax"),arg0);
  return DbmFormulaSyntaxError;
}
static AntStatus DbmValueSyntaxError(AntStatus::AntError,328);
inline AntStatus
DbmErrValueSyntax(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ValueSyntax",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","ValueSyntax"),arg0);
  return DbmValueSyntaxError;
}
static AntStatus DbmDtdAbsentError(AntStatus::AntError,329);
inline AntStatus
DbmErrDtdAbsent(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DtdAbsent",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","DtdAbsent"),arg0);
  return DbmDtdAbsentError;
}
static AntStatus DbmSnapshotInvalidError(AntStatus::AntError,330);
inline AntStatus
DbmErrSnapshotInvalid(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SnapshotInvalid",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","SnapshotInvalid"),arg0);
  return DbmSnapshotInvalidError;
}
static AntStatus DbmNoMoreClientForThisGroupError(AntStatus::AntError,331);
inline AntStatus
DbmErrNoMoreClientForThisGroup(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoMoreClientForThisGroup",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","NoMoreClientForThisGroup"),arg0);
  return DbmNoMoreClientForThisGroupError;
}
static AntStatus DbmClientNotificationError(AntStatus::AntError,332);
inline AntStatus
DbmErrClientNotification(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1,const  char * arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ClientNotification",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","ClientNotification"),arg0,arg1,arg2);
  return DbmClientNotificationError;
}
static AntStatus DbmCallbackError(AntStatus::AntError,333);
inline AntStatus
DbmErrCallback(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Callback",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","Callback"));
  return DbmCallbackError;
}
static AntStatus DbmInternalError(AntStatus::AntError,334);
inline AntStatus
DbmErrInternal(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Internal",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","Internal"));
  return DbmInternalError;
}
static AntStatus DbmNotSynchronousWritingError(AntStatus::AntError,335);
inline AntStatus
DbmErrNotSynchronousWriting(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NotSynchronousWriting",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","NotSynchronousWriting"),arg0,arg1);
  return DbmNotSynchronousWritingError;
}
static AntStatus DbmStackOverflowError(AntStatus::AntError,336);
inline AntStatus
DbmErrStackOverflow(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "StackOverflow",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","StackOverflow"));
  return DbmStackOverflowError;
}
static AntStatus DbmXMLLoadingFatalError(AntStatus::AntError,337);
inline AntStatus
DbmErrXMLLoadingFatal(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "XMLLoadingFatal",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","XMLLoadingFatal"));
  return DbmXMLLoadingFatalError;
}
static AntStatus DbmDependencyCycleError(AntStatus::AntError,338);
inline AntStatus
DbmErrDependencyCycle(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DependencyCycle",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","DependencyCycle"),arg0);
  return DbmDependencyCycleError;
}
static AntStatus DbmNbDependencyCyclesError(AntStatus::AntError,339);
inline AntStatus
DbmErrNbDependencyCycles(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NbDependencyCycles",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","NbDependencyCycles"),arg0);
  return DbmNbDependencyCyclesError;
}
static AntStatus DbmBadContextError(AntStatus::AntError,340);
inline AntStatus
DbmErrBadContext(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadContext",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","BadContext"),arg0);
  return DbmBadContextError;
}
static AntStatus DbmBadAlarmSynthesisError(AntStatus::AntError,341);
inline AntStatus
DbmErrBadAlarmSynthesis(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadAlarmSynthesis",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","BadAlarmSynthesis"),arg0);
  return DbmBadAlarmSynthesisError;
}
static AntStatus DbmIncorrectAlarmSynthesisError(AntStatus::AntError,342);
inline AntStatus
DbmErrIncorrectAlarmSynthesis(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "IncorrectAlarmSynthesis",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","IncorrectAlarmSynthesis"),arg0);
  return DbmIncorrectAlarmSynthesisError;
}
static AntStatus DbmUnknownUserClassIdError(AntStatus::AntError,343);
inline AntStatus
DbmErrUnknownUserClassId(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownUserClassId",
              source,
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","UnknownUserClassId"),arg0);
  return DbmUnknownUserClassIdError;
}
static AntStatus DbmCreateDirectoryError(AntStatus::AntError,344);
inline AntStatus
DbmErrCreateDirectory(AntErrorSeverity severity
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
              "Dbm",
              AntTrace::trace().getErrorFormat("dbmerror.emf","Dbm","CreateDirectory"),arg0);
  return DbmCreateDirectoryError;
}
inline const char *
DbmGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 300:
    return "Init";
  case 301:
    return "ORB";
  case 302:
    return "HostServer";
  case 303:
    return "DataBaseConnection";
  case 304:
    return "PermissionDenied";
  case 305:
    return "ProfileNotFound";
  case 306:
    return "Parameter";
  case 307:
    return "BadReference";
  case 308:
    return "ReadError";
  case 309:
    return "WriteError";
  case 310:
    return "DataConversion";
  case 311:
    return "GroupUnknown";
  case 312:
    return "GroupAlreadyExist";
  case 313:
    return "GroupCreation";
  case 314:
    return "GroupDeletion";
  case 315:
    return "GroupDescription";
  case 316:
    return "GroupSubscription";
  case 317:
    return "GroupUnsubscription";
  case 318:
    return "SubscriptionNotFound";
  case 319:
    return "FileCreation";
  case 320:
    return "FileDeletion";
  case 321:
    return "FileNotFound";
  case 322:
    return "RtapFunction";
  case 323:
    return "RtapCommunication";
  case 324:
    return "Function";
  case 325:
    return "WriteSecurity";
  case 326:
    return "Timeout";
  case 327:
    return "FormulaSyntax";
  case 328:
    return "ValueSyntax";
  case 329:
    return "DtdAbsent";
  case 330:
    return "SnapshotInvalid";
  case 331:
    return "NoMoreClientForThisGroup";
  case 332:
    return "ClientNotification";
  case 333:
    return "Callback";
  case 334:
    return "Internal";
  case 335:
    return "NotSynchronousWriting";
  case 336:
    return "StackOverflow";
  case 337:
    return "XMLLoadingFatal";
  case 338:
    return "DependencyCycle";
  case 339:
    return "NbDependencyCycles";
  case 340:
    return "BadContext";
  case 341:
    return "BadAlarmSynthesis";
  case 342:
    return "IncorrectAlarmSynthesis";
  case 343:
    return "UnknownUserClassId";
  case 344:
    return "CreateDirectory";
  default:
    return "";
  }
}
#endif
