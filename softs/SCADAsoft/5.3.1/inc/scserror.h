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
!! at Fri Nov 15 16:14:20 2013
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
*/
#ifndef _AN_SCSERROR_H
#define _AN_SCSERROR_H
static AntStatus ScsInitError(AntStatus::AntError,100);
inline AntStatus
ScsErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","Init"));
  return ScsInitError;
}
static AntStatus ScsORBError(AntStatus::AntError,101);
inline AntStatus
ScsErrORB(AntErrorSeverity severity
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
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ORB"),arg0);
  return ScsORBError;
}
static AntStatus ScsEnvironmentError(AntStatus::AntError,102);
inline AntStatus
ScsErrEnvironment(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Environment",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","Environment"),arg0);
  return ScsEnvironmentError;
}
static AntStatus ScsUnixError(AntStatus::AntError,103);
inline AntStatus
ScsErrUnix(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Unix",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","Unix"),arg0,arg1);
  return ScsUnixError;
}
static AntStatus ScsExceptionUnknownError(AntStatus::AntError,104);
inline AntStatus
ScsErrExceptionUnknown(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionUnknown",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionUnknown"));
  return ScsExceptionUnknownError;
}
static AntStatus ScsExceptionBadParamError(AntStatus::AntError,105);
inline AntStatus
ScsErrExceptionBadParam(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionBadParam",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionBadParam"));
  return ScsExceptionBadParamError;
}
static AntStatus ScsExceptionNoMemoryError(AntStatus::AntError,106);
inline AntStatus
ScsErrExceptionNoMemory(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionNoMemory",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionNoMemory"));
  return ScsExceptionNoMemoryError;
}
static AntStatus ScsExceptionImpLimitError(AntStatus::AntError,107);
inline AntStatus
ScsErrExceptionImpLimit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionImpLimit",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionImpLimit"));
  return ScsExceptionImpLimitError;
}
static AntStatus ScsExceptionCommFailureError(AntStatus::AntError,108);
inline AntStatus
ScsErrExceptionCommFailure(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionCommFailure",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionCommFailure"));
  return ScsExceptionCommFailureError;
}
static AntStatus ScsExceptionInvObjRefError(AntStatus::AntError,109);
inline AntStatus
ScsErrExceptionInvObjRef(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionInvObjRef",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionInvObjRef"));
  return ScsExceptionInvObjRefError;
}
static AntStatus ScsExceptionNoPermissionError(AntStatus::AntError,110);
inline AntStatus
ScsErrExceptionNoPermission(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionNoPermission",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionNoPermission"));
  return ScsExceptionNoPermissionError;
}
static AntStatus ScsExceptionInternalError(AntStatus::AntError,111);
inline AntStatus
ScsErrExceptionInternal(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionInternal",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionInternal"));
  return ScsExceptionInternalError;
}
static AntStatus ScsExceptionMarshalError(AntStatus::AntError,112);
inline AntStatus
ScsErrExceptionMarshal(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionMarshal",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionMarshal"));
  return ScsExceptionMarshalError;
}
static AntStatus ScsExceptionInitializeError(AntStatus::AntError,113);
inline AntStatus
ScsErrExceptionInitialize(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionInitialize",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionInitialize"));
  return ScsExceptionInitializeError;
}
static AntStatus ScsExceptionNoImplementError(AntStatus::AntError,114);
inline AntStatus
ScsErrExceptionNoImplement(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionNoImplement",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionNoImplement"));
  return ScsExceptionNoImplementError;
}
static AntStatus ScsExceptionBadTypeCodeError(AntStatus::AntError,115);
inline AntStatus
ScsErrExceptionBadTypeCode(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionBadTypeCode",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionBadTypeCode"));
  return ScsExceptionBadTypeCodeError;
}
static AntStatus ScsExceptionBadOperationError(AntStatus::AntError,116);
inline AntStatus
ScsErrExceptionBadOperation(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionBadOperation",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionBadOperation"));
  return ScsExceptionBadOperationError;
}
static AntStatus ScsExceptionNoRessourcesError(AntStatus::AntError,117);
inline AntStatus
ScsErrExceptionNoRessources(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionNoRessources",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionNoRessources"));
  return ScsExceptionNoRessourcesError;
}
static AntStatus ScsExceptionNoResponseError(AntStatus::AntError,118);
inline AntStatus
ScsErrExceptionNoResponse(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionNoResponse",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionNoResponse"));
  return ScsExceptionNoResponseError;
}
static AntStatus ScsExceptionPersistStoreError(AntStatus::AntError,119);
inline AntStatus
ScsErrExceptionPersistStore(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionPersistStore",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionPersistStore"));
  return ScsExceptionPersistStoreError;
}
static AntStatus ScsExceptionBadInvOrderError(AntStatus::AntError,120);
inline AntStatus
ScsErrExceptionBadInvOrder(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionBadInvOrder",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionBadInvOrder"));
  return ScsExceptionBadInvOrderError;
}
static AntStatus ScsExceptionTransientError(AntStatus::AntError,121);
inline AntStatus
ScsErrExceptionTransient(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionTransient",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionTransient"));
  return ScsExceptionTransientError;
}
static AntStatus ScsExceptionFreeMemError(AntStatus::AntError,122);
inline AntStatus
ScsErrExceptionFreeMem(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionFreeMem",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionFreeMem"));
  return ScsExceptionFreeMemError;
}
static AntStatus ScsExceptionInvIdentError(AntStatus::AntError,123);
inline AntStatus
ScsErrExceptionInvIdent(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionInvIdent",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionInvIdent"));
  return ScsExceptionInvIdentError;
}
static AntStatus ScsExceptionInvFlagError(AntStatus::AntError,124);
inline AntStatus
ScsErrExceptionInvFlag(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionInvFlag",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionInvFlag"));
  return ScsExceptionInvFlagError;
}
static AntStatus ScsExceptionIntfReposError(AntStatus::AntError,125);
inline AntStatus
ScsErrExceptionIntfRepos(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionIntfRepos",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionIntfRepos"));
  return ScsExceptionIntfReposError;
}
static AntStatus ScsExceptionBadContextError(AntStatus::AntError,126);
inline AntStatus
ScsErrExceptionBadContext(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionBadContext",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionBadContext"));
  return ScsExceptionBadContextError;
}
static AntStatus ScsExceptionObjAdapterError(AntStatus::AntError,127);
inline AntStatus
ScsErrExceptionObjAdapter(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionObjAdapter",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionObjAdapter"));
  return ScsExceptionObjAdapterError;
}
static AntStatus ScsExceptionDataConversionError(AntStatus::AntError,128);
inline AntStatus
ScsErrExceptionDataConversion(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionDataConversion",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionDataConversion"));
  return ScsExceptionDataConversionError;
}
static AntStatus ScsExceptionObjectNotExistError(AntStatus::AntError,129);
inline AntStatus
ScsErrExceptionObjectNotExist(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionObjectNotExist",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionObjectNotExist"));
  return ScsExceptionObjectNotExistError;
}
static AntStatus ScsExceptionTransactionRequiredError(AntStatus::AntError,130);
inline AntStatus
ScsErrExceptionTransactionRequired(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionTransactionRequired",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionTransactionRequired"));
  return ScsExceptionTransactionRequiredError;
}
static AntStatus ScsExceptionTransactionRolledbackError(AntStatus::AntError,131);
inline AntStatus
ScsErrExceptionTransactionRolledback(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionTransactionRolledback",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionTransactionRolledback"));
  return ScsExceptionTransactionRolledbackError;
}
static AntStatus ScsExceptionInvalidTransactionError(AntStatus::AntError,132);
inline AntStatus
ScsErrExceptionInvalidTransaction(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionInvalidTransaction",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionInvalidTransaction"));
  return ScsExceptionInvalidTransactionError;
}
static AntStatus ScsExceptionInvPolicyError(AntStatus::AntError,133);
inline AntStatus
ScsErrExceptionInvPolicy(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionInvPolicy",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionInvPolicy"));
  return ScsExceptionInvPolicyError;
}
static AntStatus ScsExceptionCodeIncompatibleError(AntStatus::AntError,134);
inline AntStatus
ScsErrExceptionCodeIncompatible(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionCodeIncompatible",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionCodeIncompatible"));
  return ScsExceptionCodeIncompatibleError;
}
static AntStatus ScsExceptionRebindError(AntStatus::AntError,135);
inline AntStatus
ScsErrExceptionRebind(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionRebind",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionRebind"));
  return ScsExceptionRebindError;
}
static AntStatus ScsExceptionTimeoutError(AntStatus::AntError,136);
inline AntStatus
ScsErrExceptionTimeout(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionTimeout",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionTimeout"));
  return ScsExceptionTimeoutError;
}
static AntStatus ScsExceptionTransactionUnavailableError(AntStatus::AntError,137);
inline AntStatus
ScsErrExceptionTransactionUnavailable(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionTransactionUnavailable",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionTransactionUnavailable"));
  return ScsExceptionTransactionUnavailableError;
}
static AntStatus ScsExceptionTransactionModeError(AntStatus::AntError,138);
inline AntStatus
ScsErrExceptionTransactionMode(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionTransactionMode",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionTransactionMode"));
  return ScsExceptionTransactionModeError;
}
static AntStatus ScsExceptionBadQosError(AntStatus::AntError,139);
inline AntStatus
ScsErrExceptionBadQos(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionBadQos",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","ExceptionBadQos"));
  return ScsExceptionBadQosError;
}
static AntStatus ScsCallbackError(AntStatus::AntError,140);
inline AntStatus
ScsErrCallback(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Callback",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","Callback"),arg0);
  return ScsCallbackError;
}
static AntStatus ScsFileNotFoundError(AntStatus::AntError,141);
inline AntStatus
ScsErrFileNotFound(AntErrorSeverity severity
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
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","FileNotFound"),arg0);
  return ScsFileNotFoundError;
}
static AntStatus ScsFileBadFormatError(AntStatus::AntError,142);
inline AntStatus
ScsErrFileBadFormat(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FileBadFormat",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","FileBadFormat"),arg0);
  return ScsFileBadFormatError;
}
static AntStatus ScsFileSyntaxErrorError(AntStatus::AntError,143);
inline AntStatus
ScsErrFileSyntaxError(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FileSyntaxError",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","FileSyntaxError"),arg0,arg1);
  return ScsFileSyntaxErrorError;
}
static AntStatus ScsFileBadValueError(AntStatus::AntError,144);
inline AntStatus
ScsErrFileBadValue(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1,const  char * arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FileBadValue",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scserror.emf","Scs","FileBadValue"),arg0,arg1,arg2);
  return ScsFileBadValueError;
}
inline const char *
ScsGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 100:
    return "Init";
  case 101:
    return "ORB";
  case 102:
    return "Environment";
  case 103:
    return "Unix";
  case 104:
    return "ExceptionUnknown";
  case 105:
    return "ExceptionBadParam";
  case 106:
    return "ExceptionNoMemory";
  case 107:
    return "ExceptionImpLimit";
  case 108:
    return "ExceptionCommFailure";
  case 109:
    return "ExceptionInvObjRef";
  case 110:
    return "ExceptionNoPermission";
  case 111:
    return "ExceptionInternal";
  case 112:
    return "ExceptionMarshal";
  case 113:
    return "ExceptionInitialize";
  case 114:
    return "ExceptionNoImplement";
  case 115:
    return "ExceptionBadTypeCode";
  case 116:
    return "ExceptionBadOperation";
  case 117:
    return "ExceptionNoRessources";
  case 118:
    return "ExceptionNoResponse";
  case 119:
    return "ExceptionPersistStore";
  case 120:
    return "ExceptionBadInvOrder";
  case 121:
    return "ExceptionTransient";
  case 122:
    return "ExceptionFreeMem";
  case 123:
    return "ExceptionInvIdent";
  case 124:
    return "ExceptionInvFlag";
  case 125:
    return "ExceptionIntfRepos";
  case 126:
    return "ExceptionBadContext";
  case 127:
    return "ExceptionObjAdapter";
  case 128:
    return "ExceptionDataConversion";
  case 129:
    return "ExceptionObjectNotExist";
  case 130:
    return "ExceptionTransactionRequired";
  case 131:
    return "ExceptionTransactionRolledback";
  case 132:
    return "ExceptionInvalidTransaction";
  case 133:
    return "ExceptionInvPolicy";
  case 134:
    return "ExceptionCodeIncompatible";
  case 135:
    return "ExceptionRebind";
  case 136:
    return "ExceptionTimeout";
  case 137:
    return "ExceptionTransactionUnavailable";
  case 138:
    return "ExceptionTransactionMode";
  case 139:
    return "ExceptionBadQos";
  case 140:
    return "Callback";
  case 141:
    return "FileNotFound";
  case 142:
    return "FileBadFormat";
  case 143:
    return "FileSyntaxError";
  case 144:
    return "FileBadValue";
  default:
    return "";
  }
}
#endif
