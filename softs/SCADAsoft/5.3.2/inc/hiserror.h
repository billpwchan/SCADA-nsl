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
#ifndef _AN_HISERROR_H
#define _AN_HISERROR_H
static AntStatus HisInitError(AntStatus::AntError,600);
inline AntStatus
HisErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","Init"));
  return HisInitError;
}
static AntStatus HisORBError(AntStatus::AntError,601);
inline AntStatus
HisErrORB(AntErrorSeverity severity
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
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","ORB"),arg0);
  return HisORBError;
}
static AntStatus HisHostServerError(AntStatus::AntError,602);
inline AntStatus
HisErrHostServer(AntErrorSeverity severity
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
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","HostServer"),arg0);
  return HisHostServerError;
}
static AntStatus HisRtapFunctionError(AntStatus::AntError,603);
inline AntStatus
HisErrRtapFunction(AntErrorSeverity severity
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
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","RtapFunction"),arg0);
  return HisRtapFunctionError;
}
static AntStatus HisFunctionError(AntStatus::AntError,604);
inline AntStatus
HisErrFunction(AntErrorSeverity severity
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
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","Function"),arg0);
  return HisFunctionError;
}
static AntStatus HisSystemFunctionError(AntStatus::AntError,605);
inline AntStatus
HisErrSystemFunction(AntErrorSeverity severity
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
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","SystemFunction"),arg0);
  return HisSystemFunctionError;
}
static AntStatus HisDataBaseConnectionError(AntStatus::AntError,606);
inline AntStatus
HisErrDataBaseConnection(AntErrorSeverity severity
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
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","DataBaseConnection"),arg0);
  return HisDataBaseConnectionError;
}
static AntStatus HisArchiveCreationError(AntStatus::AntError,607);
inline AntStatus
HisErrArchiveCreation(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ArchiveCreation",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","ArchiveCreation"),arg0);
  return HisArchiveCreationError;
}
static AntStatus HisPropertiesConflictError(AntStatus::AntError,608);
inline AntStatus
HisErrPropertiesConflict(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "PropertiesConflict",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","PropertiesConflict"),arg0,arg1);
  return HisPropertiesConflictError;
}
static AntStatus HisArchiveNotFoundError(AntStatus::AntError,609);
inline AntStatus
HisErrArchiveNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ArchiveNotFound",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","ArchiveNotFound"),arg0);
  return HisArchiveNotFoundError;
}
static AntStatus HisPermissionDeniedError(AntStatus::AntError,610);
inline AntStatus
HisErrPermissionDenied(AntErrorSeverity severity
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
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","PermissionDenied"),arg0,arg1);
  return HisPermissionDeniedError;
}
static AntStatus HisProfileNotFoundError(AntStatus::AntError,611);
inline AntStatus
HisErrProfileNotFound(AntErrorSeverity severity
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
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","ProfileNotFound"),arg0);
  return HisProfileNotFoundError;
}
static AntStatus HisInvalidPathnameError(AntStatus::AntError,612);
inline AntStatus
HisErrInvalidPathname(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidPathname",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","InvalidPathname"),arg0);
  return HisInvalidPathnameError;
}
static AntStatus HisCreateDirectoryError(AntStatus::AntError,613);
inline AntStatus
HisErrCreateDirectory(AntErrorSeverity severity
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
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","CreateDirectory"),arg0);
  return HisCreateDirectoryError;
}
static AntStatus HisRemoveDirectoryError(AntStatus::AntError,614);
inline AntStatus
HisErrRemoveDirectory(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RemoveDirectory",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","RemoveDirectory"),arg0);
  return HisRemoveDirectoryError;
}
static AntStatus HisRenameFileError(AntStatus::AntError,615);
inline AntStatus
HisErrRenameFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RenameFile",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","RenameFile"),arg0,arg1);
  return HisRenameFileError;
}
static AntStatus HisCreateFileError(AntStatus::AntError,616);
inline AntStatus
HisErrCreateFile(AntErrorSeverity severity
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
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","CreateFile"),arg0);
  return HisCreateFileError;
}
static AntStatus HisCopyFileError(AntStatus::AntError,617);
inline AntStatus
HisErrCopyFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CopyFile",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","CopyFile"),arg0,arg1);
  return HisCopyFileError;
}
static AntStatus HisOpenFileError(AntStatus::AntError,618);
inline AntStatus
HisErrOpenFile(AntErrorSeverity severity
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
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","OpenFile"),arg0);
  return HisOpenFileError;
}
static AntStatus HisOpenDirError(AntStatus::AntError,619);
inline AntStatus
HisErrOpenDir(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "OpenDir",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","OpenDir"),arg0);
  return HisOpenDirError;
}
static AntStatus HisParseFileError(AntStatus::AntError,620);
inline AntStatus
HisErrParseFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ParseFile",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","ParseFile"),arg0);
  return HisParseFileError;
}
static AntStatus HisNoAddressesInListError(AntStatus::AntError,621);
inline AntStatus
HisErrNoAddressesInList(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoAddressesInList",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","NoAddressesInList"));
  return HisNoAddressesInListError;
}
static AntStatus HisInvalidTypeError(AntStatus::AntError,622);
inline AntStatus
HisErrInvalidType(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidType",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","InvalidType"),arg0);
  return HisInvalidTypeError;
}
static AntStatus HisTypeUndefinedError(AntStatus::AntError,623);
inline AntStatus
HisErrTypeUndefined(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "TypeUndefined",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","TypeUndefined"),arg0,arg1);
  return HisTypeUndefinedError;
}
static AntStatus HisTypeIncorrectError(AntStatus::AntError,624);
inline AntStatus
HisErrTypeIncorrect(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "TypeIncorrect",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","TypeIncorrect"),arg0,arg1);
  return HisTypeIncorrectError;
}
static AntStatus HisTimeoutError(AntStatus::AntError,625);
inline AntStatus
HisErrTimeout(AntErrorSeverity severity
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
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","Timeout"),arg0,arg1);
  return HisTimeoutError;
}
static AntStatus HisFunctionNotImplementedError(AntStatus::AntError,626);
inline AntStatus
HisErrFunctionNotImplemented(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FunctionNotImplemented",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","FunctionNotImplemented"),arg0);
  return HisFunctionNotImplementedError;
}
static AntStatus HisArchiveNameIncorrectError(AntStatus::AntError,627);
inline AntStatus
HisErrArchiveNameIncorrect(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ArchiveNameIncorrect",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","ArchiveNameIncorrect"),arg0);
  return HisArchiveNameIncorrectError;
}
static AntStatus HisArchiveIncorrectError(AntStatus::AntError,628);
inline AntStatus
HisErrArchiveIncorrect(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ArchiveIncorrect",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","ArchiveIncorrect"),arg0);
  return HisArchiveIncorrectError;
}
static AntStatus HisArchiveNotImplementedError(AntStatus::AntError,629);
inline AntStatus
HisErrArchiveNotImplemented(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ArchiveNotImplemented",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","ArchiveNotImplemented"),arg0);
  return HisArchiveNotImplementedError;
}
static AntStatus HisPropertyNotImplementedError(AntStatus::AntError,630);
inline AntStatus
HisErrPropertyNotImplemented(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "PropertyNotImplemented",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","PropertyNotImplemented"),arg0,arg1);
  return HisPropertyNotImplementedError;
}
static AntStatus HisNoBufferAvailableError(AntStatus::AntError,631);
inline AntStatus
HisErrNoBufferAvailable(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoBufferAvailable",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","NoBufferAvailable"));
  return HisNoBufferAvailableError;
}
static AntStatus HisNoSubscriptionDefinedError(AntStatus::AntError,632);
inline AntStatus
HisErrNoSubscriptionDefined(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoSubscriptionDefined",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","NoSubscriptionDefined"));
  return HisNoSubscriptionDefinedError;
}
static AntStatus HisSubscriptionAlreadyDefinedError(AntStatus::AntError,633);
inline AntStatus
HisErrSubscriptionAlreadyDefined(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SubscriptionAlreadyDefined",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","SubscriptionAlreadyDefined"));
  return HisSubscriptionAlreadyDefinedError;
}
static AntStatus HisInvalidQualityTypeError(AntStatus::AntError,634);
inline AntStatus
HisErrInvalidQualityType(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidQualityType",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","InvalidQualityType"),arg0);
  return HisInvalidQualityTypeError;
}
static AntStatus HisInvalidTimestampTypeError(AntStatus::AntError,635);
inline AntStatus
HisErrInvalidTimestampType(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidTimestampType",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","InvalidTimestampType"),arg0);
  return HisInvalidTimestampTypeError;
}
static AntStatus HisInvalidPeriodError(AntStatus::AntError,636);
inline AntStatus
HisErrInvalidPeriod(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidPeriod",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","InvalidPeriod"),arg0,arg1);
  return HisInvalidPeriodError;
}
static AntStatus HisAttributeNotFoundError(AntStatus::AntError,637);
inline AntStatus
HisErrAttributeNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AttributeNotFound",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","AttributeNotFound"),arg0,arg1);
  return HisAttributeNotFoundError;
}
static AntStatus HisTooMuchDBVsError(AntStatus::AntError,638);
inline AntStatus
HisErrTooMuchDBVs(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "TooMuchDBVs",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","TooMuchDBVs"),arg0,arg1,arg2);
  return HisTooMuchDBVsError;
}
static AntStatus HisBadFileError(AntStatus::AntError,639);
inline AntStatus
HisErrBadFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadFile",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","BadFile"),arg0);
  return HisBadFileError;
}
static AntStatus HisTransfertLTError(AntStatus::AntError,640);
inline AntStatus
HisErrTransfertLT(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "TransfertLT",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","TransfertLT"),arg0);
  return HisTransfertLTError;
}
static AntStatus HisDeleteFileError(AntStatus::AntError,641);
inline AntStatus
HisErrDeleteFile(AntErrorSeverity severity
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
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","DeleteFile"),arg0);
  return HisDeleteFileError;
}
static AntStatus HisNoLTServeurError(AntStatus::AntError,642);
inline AntStatus
HisErrNoLTServeur(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoLTServeur",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","NoLTServeur"));
  return HisNoLTServeurError;
}
static AntStatus HisConnexionLTError(AntStatus::AntError,643);
inline AntStatus
HisErrConnexionLT(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ConnexionLT",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","ConnexionLT"));
  return HisConnexionLTError;
}
static AntStatus HisPointSetError(AntStatus::AntError,644);
inline AntStatus
HisErrPointSet(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "PointSet",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","PointSet"),arg0,arg1);
  return HisPointSetError;
}
static AntStatus HisPointSetNotFoundError(AntStatus::AntError,645);
inline AntStatus
HisErrPointSetNotFound(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "PointSetNotFound",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","PointSetNotFound"),arg0);
  return HisPointSetNotFoundError;
}
static AntStatus HisBadSubError(AntStatus::AntError,646);
inline AntStatus
HisErrBadSub(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadSub",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","BadSub"),arg0,arg1);
  return HisBadSubError;
}
static AntStatus HisBadParamError(AntStatus::AntError,647);
inline AntStatus
HisErrBadParam(AntErrorSeverity severity
      ,short line, const char* file
      , long  arg0, long  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadParam",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","BadParam"),arg0,arg1);
  return HisBadParamError;
}
static AntStatus HisStaticSaveArchiveError(AntStatus::AntError,648);
inline AntStatus
HisErrStaticSaveArchive(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "StaticSaveArchive",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","StaticSaveArchive"),arg0);
  return HisStaticSaveArchiveError;
}
static AntStatus HisDescSaveArchiveError(AntStatus::AntError,649);
inline AntStatus
HisErrDescSaveArchive(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DescSaveArchive",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","DescSaveArchive"),arg0);
  return HisDescSaveArchiveError;
}
static AntStatus HisWrongAttributError(AntStatus::AntError,650);
inline AntStatus
HisErrWrongAttribut(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WrongAttribut",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","WrongAttribut"),arg0);
  return HisWrongAttributError;
}
static AntStatus HisWrongOperatorError(AntStatus::AntError,651);
inline AntStatus
HisErrWrongOperator(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WrongOperator",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","WrongOperator"),arg0);
  return HisWrongOperatorError;
}
static AntStatus HisTypeFieldCriteriaError(AntStatus::AntError,652);
inline AntStatus
HisErrTypeFieldCriteria(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, int  arg1, int  arg2, int  arg3
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "TypeFieldCriteria",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","TypeFieldCriteria"),arg0,arg1,arg2,arg3);
  return HisTypeFieldCriteriaError;
}
static AntStatus HisNoInstancesError(AntStatus::AntError,653);
inline AntStatus
HisErrNoInstances(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoInstances",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","NoInstances"),arg0);
  return HisNoInstancesError;
}
static AntStatus HisStatusCallbackError(AntStatus::AntError,654);
inline AntStatus
HisErrStatusCallback(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "StatusCallback",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","StatusCallback"));
  return HisStatusCallbackError;
}
static AntStatus HisNoHistorisationFoundError(AntStatus::AntError,655);
inline AntStatus
HisErrNoHistorisationFound(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoHistorisationFound",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","NoHistorisationFound"),arg0,arg1);
  return HisNoHistorisationFoundError;
}
static AntStatus HisGetDBVIdsError(AntStatus::AntError,656);
inline AntStatus
HisErrGetDBVIds(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GetDBVIds",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","GetDBVIds"));
  return HisGetDBVIdsError;
}
static AntStatus HisNoStaticAttrError(AntStatus::AntError,657);
inline AntStatus
HisErrNoStaticAttr(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoStaticAttr",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","NoStaticAttr"),arg0);
  return HisNoStaticAttrError;
}
static AntStatus HisReadStaticAttrError(AntStatus::AntError,658);
inline AntStatus
HisErrReadStaticAttr(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ReadStaticAttr",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","ReadStaticAttr"),arg0);
  return HisReadStaticAttrError;
}
static AntStatus HisParseQueryError(AntStatus::AntError,659);
inline AntStatus
HisErrParseQuery(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ParseQuery",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","ParseQuery"),arg0,arg1);
  return HisParseQueryError;
}
static AntStatus HisWrongCriteriaError(AntStatus::AntError,660);
inline AntStatus
HisErrWrongCriteria(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WrongCriteria",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","WrongCriteria"),arg0,arg1);
  return HisWrongCriteriaError;
}
static AntStatus HisConfigFileError(AntStatus::AntError,661);
inline AntStatus
HisErrConfigFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ConfigFile",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","ConfigFile"),arg0);
  return HisConfigFileError;
}
static AntStatus HisMoveDirError(AntStatus::AntError,662);
inline AntStatus
HisErrMoveDir(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MoveDir",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","MoveDir"),arg0,arg1);
  return HisMoveDirError;
}
static AntStatus HisNoLocalServerError(AntStatus::AntError,663);
inline AntStatus
HisErrNoLocalServer(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoLocalServer",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","NoLocalServer"),arg0,arg1);
  return HisNoLocalServerError;
}
static AntStatus HisGetFileLTError(AntStatus::AntError,664);
inline AntStatus
HisErrGetFileLT(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, int  arg1, int  arg2, int  arg3
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GetFileLT",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","GetFileLT"),arg0,arg1,arg2,arg3);
  return HisGetFileLTError;
}
static AntStatus HisLoadNotFoundError(AntStatus::AntError,665);
inline AntStatus
HisErrLoadNotFound(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "LoadNotFound",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","LoadNotFound"),arg0);
  return HisLoadNotFoundError;
}
static AntStatus HisNoServerForOldDbvError(AntStatus::AntError,666);
inline AntStatus
HisErrNoServerForOldDbv(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoServerForOldDbv",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","NoServerForOldDbv"),arg0,arg1,arg2);
  return HisNoServerForOldDbvError;
}
static AntStatus HisNoProxyError(AntStatus::AntError,667);
inline AntStatus
HisErrNoProxy(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoProxy",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","NoProxy"),arg0,arg1,arg2);
  return HisNoProxyError;
}
static AntStatus HisNoDBVError(AntStatus::AntError,668);
inline AntStatus
HisErrNoDBV(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoDBV",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","NoDBV"),arg0,arg1);
  return HisNoDBVError;
}
static AntStatus HisNumPeriodError(AntStatus::AntError,669);
inline AntStatus
HisErrNumPeriod(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, int  arg1,const  char * arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NumPeriod",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","NumPeriod"),arg0,arg1,arg2);
  return HisNumPeriodError;
}
static AntStatus HisDBVreloadingError(AntStatus::AntError,670);
inline AntStatus
HisErrDBVreloading(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DBVreloading",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","DBVreloading"),arg0,arg1,arg2);
  return HisDBVreloadingError;
}
static AntStatus HisDBVreloadError(AntStatus::AntError,671);
inline AntStatus
HisErrDBVreload(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DBVreload",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","DBVreload"),arg0);
  return HisDBVreloadError;
}
static AntStatus HisDBVStructureError(AntStatus::AntError,672);
inline AntStatus
HisErrDBVStructure(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DBVStructure",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","DBVStructure"),arg0);
  return HisDBVStructureError;
}
static AntStatus HisRemovePathError(AntStatus::AntError,673);
inline AntStatus
HisErrRemovePath(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RemovePath",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","RemovePath"),arg0);
  return HisRemovePathError;
}
static AntStatus HisNoElementsToReadError(AntStatus::AntError,674);
inline AntStatus
HisErrNoElementsToRead(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoElementsToRead",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","NoElementsToRead"));
  return HisNoElementsToReadError;
}
static AntStatus HisInvalidColumnInListError(AntStatus::AntError,675);
inline AntStatus
HisErrInvalidColumnInList(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidColumnInList",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","InvalidColumnInList"),arg0,arg1);
  return HisInvalidColumnInListError;
}
static AntStatus HisUnReadArchiveError(AntStatus::AntError,676);
inline AntStatus
HisErrUnReadArchive(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnReadArchive",
              source,
              "His",
              AntTrace::trace().getErrorFormat("hiserror.emf","His","UnReadArchive"),arg0,arg1,arg2);
  return HisUnReadArchiveError;
}
inline const char *
HisGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 600:
    return "Init";
  case 601:
    return "ORB";
  case 602:
    return "HostServer";
  case 603:
    return "RtapFunction";
  case 604:
    return "Function";
  case 605:
    return "SystemFunction";
  case 606:
    return "DataBaseConnection";
  case 607:
    return "ArchiveCreation";
  case 608:
    return "PropertiesConflict";
  case 609:
    return "ArchiveNotFound";
  case 610:
    return "PermissionDenied";
  case 611:
    return "ProfileNotFound";
  case 612:
    return "InvalidPathname";
  case 613:
    return "CreateDirectory";
  case 614:
    return "RemoveDirectory";
  case 615:
    return "RenameFile";
  case 616:
    return "CreateFile";
  case 617:
    return "CopyFile";
  case 618:
    return "OpenFile";
  case 619:
    return "OpenDir";
  case 620:
    return "ParseFile";
  case 621:
    return "NoAddressesInList";
  case 622:
    return "InvalidType";
  case 623:
    return "TypeUndefined";
  case 624:
    return "TypeIncorrect";
  case 625:
    return "Timeout";
  case 626:
    return "FunctionNotImplemented";
  case 627:
    return "ArchiveNameIncorrect";
  case 628:
    return "ArchiveIncorrect";
  case 629:
    return "ArchiveNotImplemented";
  case 630:
    return "PropertyNotImplemented";
  case 631:
    return "NoBufferAvailable";
  case 632:
    return "NoSubscriptionDefined";
  case 633:
    return "SubscriptionAlreadyDefined";
  case 634:
    return "InvalidQualityType";
  case 635:
    return "InvalidTimestampType";
  case 636:
    return "InvalidPeriod";
  case 637:
    return "AttributeNotFound";
  case 638:
    return "TooMuchDBVs";
  case 639:
    return "BadFile";
  case 640:
    return "TransfertLT";
  case 641:
    return "DeleteFile";
  case 642:
    return "NoLTServeur";
  case 643:
    return "ConnexionLT";
  case 644:
    return "PointSet";
  case 645:
    return "PointSetNotFound";
  case 646:
    return "BadSub";
  case 647:
    return "BadParam";
  case 648:
    return "StaticSaveArchive";
  case 649:
    return "DescSaveArchive";
  case 650:
    return "WrongAttribut";
  case 651:
    return "WrongOperator";
  case 652:
    return "TypeFieldCriteria";
  case 653:
    return "NoInstances";
  case 654:
    return "StatusCallback";
  case 655:
    return "NoHistorisationFound";
  case 656:
    return "GetDBVIds";
  case 657:
    return "NoStaticAttr";
  case 658:
    return "ReadStaticAttr";
  case 659:
    return "ParseQuery";
  case 660:
    return "WrongCriteria";
  case 661:
    return "ConfigFile";
  case 662:
    return "MoveDir";
  case 663:
    return "NoLocalServer";
  case 664:
    return "GetFileLT";
  case 665:
    return "LoadNotFound";
  case 666:
    return "NoServerForOldDbv";
  case 667:
    return "NoProxy";
  case 668:
    return "NoDBV";
  case 669:
    return "NumPeriod";
  case 670:
    return "DBVreloading";
  case 671:
    return "DBVreload";
  case 672:
    return "DBVStructure";
  case 673:
    return "RemovePath";
  case 674:
    return "NoElementsToRead";
  case 675:
    return "InvalidColumnInList";
  case 676:
    return "UnReadArchive";
  default:
    return "";
  }
}
#endif
