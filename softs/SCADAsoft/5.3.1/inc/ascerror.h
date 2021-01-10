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
#ifndef _AN_ASCERROR_H
#define _AN_ASCERROR_H
static AntStatus AscInitError(AntStatus::AntError,200);
inline AntStatus
AscErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","Init"));
  return AscInitError;
}
static AntStatus AscORBError(AntStatus::AntError,201);
inline AntStatus
AscErrORB(AntErrorSeverity severity
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
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","ORB"),arg0);
  return AscORBError;
}
static AntStatus AscUnixError(AntStatus::AntError,202);
inline AntStatus
AscErrUnix(AntErrorSeverity severity
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
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","Unix"),arg0,arg1);
  return AscUnixError;
}
static AntStatus AscScadasoftFunctionError(AntStatus::AntError,203);
inline AntStatus
AscErrScadasoftFunction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ScadasoftFunction",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","ScadasoftFunction"),arg0,arg1);
  return AscScadasoftFunctionError;
}
static AntStatus AscEnvironmentError(AntStatus::AntError,204);
inline AntStatus
AscErrEnvironment(AntErrorSeverity severity
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
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","Environment"),arg0);
  return AscEnvironmentError;
}
static AntStatus AscOpenFileError(AntStatus::AntError,205);
inline AntStatus
AscErrOpenFile(AntErrorSeverity severity
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
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","OpenFile"),arg0);
  return AscOpenFileError;
}
static AntStatus AscParseFileError(AntStatus::AntError,206);
inline AntStatus
AscErrParseFile(AntErrorSeverity severity
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
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","ParseFile"),arg0);
  return AscParseFileError;
}
static AntStatus AscSameShutdownOrderError(AntStatus::AntError,207);
inline AntStatus
AscErrSameShutdownOrder(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SameShutdownOrder",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","SameShutdownOrder"),arg0);
  return AscSameShutdownOrderError;
}
static AntStatus AscUnknownEnvironmentError(AntStatus::AntError,208);
inline AntStatus
AscErrUnknownEnvironment(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownEnvironment",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","UnknownEnvironment"),arg0);
  return AscUnknownEnvironmentError;
}
static AntStatus AscInactiveServerError(AntStatus::AntError,209);
inline AntStatus
AscErrInactiveServer(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InactiveServer",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","InactiveServer"),arg0);
  return AscInactiveServerError;
}
static AntStatus AscBadServerNameError(AntStatus::AntError,210);
inline AntStatus
AscErrBadServerName(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadServerName",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","BadServerName"),arg0);
  return AscBadServerNameError;
}
static AntStatus AscIncorrectEnvListError(AntStatus::AntError,211);
inline AntStatus
AscErrIncorrectEnvList(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "IncorrectEnvList",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","IncorrectEnvList"),arg0,arg1);
  return AscIncorrectEnvListError;
}
static AntStatus AscProcessNotStartedError(AntStatus::AntError,212);
inline AntStatus
AscErrProcessNotStarted(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ProcessNotStarted",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","ProcessNotStarted"),arg0);
  return AscProcessNotStartedError;
}
static AntStatus AscNoDbmServerError(AntStatus::AntError,213);
inline AntStatus
AscErrNoDbmServer(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoDbmServer",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","NoDbmServer"),arg0);
  return AscNoDbmServerError;
}
static AntStatus AscProcessNotSupervisedError(AntStatus::AntError,214);
inline AntStatus
AscErrProcessNotSupervised(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ProcessNotSupervised",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","ProcessNotSupervised"),arg0);
  return AscProcessNotSupervisedError;
}
static AntStatus AscProcessAlreadyRunningError(AntStatus::AntError,215);
inline AntStatus
AscErrProcessAlreadyRunning(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ProcessAlreadyRunning",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","ProcessAlreadyRunning"),arg0);
  return AscProcessAlreadyRunningError;
}
static AntStatus AscMoreThanOneStandbyError(AntStatus::AntError,216);
inline AntStatus
AscErrMoreThanOneStandby(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MoreThanOneStandby",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","MoreThanOneStandby"),arg0);
  return AscMoreThanOneStandbyError;
}
static AntStatus AscProcessHasCrashedStopEnvError(AntStatus::AntError,217);
inline AntStatus
AscErrProcessHasCrashedStopEnv(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ProcessHasCrashedStopEnv",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","ProcessHasCrashedStopEnv"),arg0);
  return AscProcessHasCrashedStopEnvError;
}
static AntStatus AscBadNbPhysEnv1Error(AntStatus::AntError,218);
inline AntStatus
AscErrBadNbPhysEnv1(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadNbPhysEnv1",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","BadNbPhysEnv1"),arg0,arg1);
  return AscBadNbPhysEnv1Error;
}
static AntStatus AscBadNbPhysEnv01Error(AntStatus::AntError,219);
inline AntStatus
AscErrBadNbPhysEnv01(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadNbPhysEnv01",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","BadNbPhysEnv01"),arg0,arg1);
  return AscBadNbPhysEnv01Error;
}
static AntStatus AscBadNbLogStateError(AntStatus::AntError,220);
inline AntStatus
AscErrBadNbLogState(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadNbLogState",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","BadNbLogState"),arg0,arg1,arg2);
  return AscBadNbLogStateError;
}
static AntStatus AscUnkownProcessError(AntStatus::AntError,221);
inline AntStatus
AscErrUnkownProcess(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnkownProcess",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","UnkownProcess"),arg0);
  return AscUnkownProcessError;
}
static AntStatus AscUnableToSetStateError(AntStatus::AntError,222);
inline AntStatus
AscErrUnableToSetState(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnableToSetState",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","UnableToSetState"),arg0,arg1);
  return AscUnableToSetStateError;
}
static AntStatus AscShutdownError(AntStatus::AntError,223);
inline AntStatus
AscErrShutdown(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Shutdown",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","Shutdown"));
  return AscShutdownError;
}
static AntStatus AscProcessNotInEnvTableError(AntStatus::AntError,224);
inline AntStatus
AscErrProcessNotInEnvTable(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ProcessNotInEnvTable",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","ProcessNotInEnvTable"),arg0);
  return AscProcessNotInEnvTableError;
}
static AntStatus AscWatchdogError(AntStatus::AntError,225);
inline AntStatus
AscErrWatchdog(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Watchdog",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","Watchdog"),arg0);
  return AscWatchdogError;
}
static AntStatus AscCannotAssignProcessorError(AntStatus::AntError,226);
inline AntStatus
AscErrCannotAssignProcessor(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CannotAssignProcessor",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","CannotAssignProcessor"),arg0,arg1);
  return AscCannotAssignProcessorError;
}
static AntStatus AscDuplicateProcessInEnvTableError(AntStatus::AntError,227);
inline AntStatus
AscErrDuplicateProcessInEnvTable(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DuplicateProcessInEnvTable",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","DuplicateProcessInEnvTable"),arg0);
  return AscDuplicateProcessInEnvTableError;
}
static AntStatus AscAuthorizeStandbyError(AntStatus::AntError,228);
inline AntStatus
AscErrAuthorizeStandby(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AuthorizeStandby",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","AuthorizeStandby"),arg0);
  return AscAuthorizeStandbyError;
}
static AntStatus AscEnvironmentLostError(AntStatus::AntError,229);
inline AntStatus
AscErrEnvironmentLost(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "EnvironmentLost",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","EnvironmentLost"),arg0);
  return AscEnvironmentLostError;
}
static AntStatus AscEnvironmentWaitError(AntStatus::AntError,230);
inline AntStatus
AscErrEnvironmentWait(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "EnvironmentWait",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","EnvironmentWait"),arg0,arg1);
  return AscEnvironmentWaitError;
}
static AntStatus AscEnvironmentDownError(AntStatus::AntError,231);
inline AntStatus
AscErrEnvironmentDown(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "EnvironmentDown",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","EnvironmentDown"),arg0);
  return AscEnvironmentDownError;
}
static AntStatus AscFirstReceiveError(AntStatus::AntError,232);
inline AntStatus
AscErrFirstReceive(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FirstReceive",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","FirstReceive"),arg0);
  return AscFirstReceiveError;
}
static AntStatus AscAgainReceiveError(AntStatus::AntError,233);
inline AntStatus
AscErrAgainReceive(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AgainReceive",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","AgainReceive"),arg0);
  return AscAgainReceiveError;
}
static AntStatus AscDoesntRequireToSpecifyStateError(AntStatus::AntError,234);
inline AntStatus
AscErrDoesntRequireToSpecifyState(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DoesntRequireToSpecifyState",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","DoesntRequireToSpecifyState"),arg0);
  return AscDoesntRequireToSpecifyStateError;
}
static AntStatus AscSnapshotInProgressError(AntStatus::AntError,235);
inline AntStatus
AscErrSnapshotInProgress(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SnapshotInProgress",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","SnapshotInProgress"));
  return AscSnapshotInProgressError;
}
static AntStatus AscWrongStateError(AntStatus::AntError,236);
inline AntStatus
AscErrWrongState(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WrongState",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","WrongState"),arg0);
  return AscWrongStateError;
}
static AntStatus AscCannotCreateDirectoryError(AntStatus::AntError,237);
inline AntStatus
AscErrCannotCreateDirectory(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CannotCreateDirectory",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","CannotCreateDirectory"),arg0);
  return AscCannotCreateDirectoryError;
}
static AntStatus AscForeSnapStartError(AntStatus::AntError,238);
inline AntStatus
AscErrForeSnapStart(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ForeSnapStart",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","ForeSnapStart"));
  return AscForeSnapStartError;
}
static AntStatus AscForeSnapEndFailedError(AntStatus::AntError,239);
inline AntStatus
AscErrForeSnapEndFailed(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ForeSnapEndFailed",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","ForeSnapEndFailed"),arg0);
  return AscForeSnapEndFailedError;
}
static AntStatus AscForeSnapEndSuccessError(AntStatus::AntError,240);
inline AntStatus
AscErrForeSnapEndSuccess(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ForeSnapEndSuccess",
              source,
              "Asc",
              AntTrace::trace().getErrorFormat("ascerror.emf","Asc","ForeSnapEndSuccess"));
  return AscForeSnapEndSuccessError;
}
inline const char *
AscGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 200:
    return "Init";
  case 201:
    return "ORB";
  case 202:
    return "Unix";
  case 203:
    return "ScadasoftFunction";
  case 204:
    return "Environment";
  case 205:
    return "OpenFile";
  case 206:
    return "ParseFile";
  case 207:
    return "SameShutdownOrder";
  case 208:
    return "UnknownEnvironment";
  case 209:
    return "InactiveServer";
  case 210:
    return "BadServerName";
  case 211:
    return "IncorrectEnvList";
  case 212:
    return "ProcessNotStarted";
  case 213:
    return "NoDbmServer";
  case 214:
    return "ProcessNotSupervised";
  case 215:
    return "ProcessAlreadyRunning";
  case 216:
    return "MoreThanOneStandby";
  case 217:
    return "ProcessHasCrashedStopEnv";
  case 218:
    return "BadNbPhysEnv1";
  case 219:
    return "BadNbPhysEnv01";
  case 220:
    return "BadNbLogState";
  case 221:
    return "UnkownProcess";
  case 222:
    return "UnableToSetState";
  case 223:
    return "Shutdown";
  case 224:
    return "ProcessNotInEnvTable";
  case 225:
    return "Watchdog";
  case 226:
    return "CannotAssignProcessor";
  case 227:
    return "DuplicateProcessInEnvTable";
  case 228:
    return "AuthorizeStandby";
  case 229:
    return "EnvironmentLost";
  case 230:
    return "EnvironmentWait";
  case 231:
    return "EnvironmentDown";
  case 232:
    return "FirstReceive";
  case 233:
    return "AgainReceive";
  case 234:
    return "DoesntRequireToSpecifyState";
  case 235:
    return "SnapshotInProgress";
  case 236:
    return "WrongState";
  case 237:
    return "CannotCreateDirectory";
  case 238:
    return "ForeSnapStart";
  case 239:
    return "ForeSnapEndFailed";
  case 240:
    return "ForeSnapEndSuccess";
  default:
    return "";
  }
}
#endif
