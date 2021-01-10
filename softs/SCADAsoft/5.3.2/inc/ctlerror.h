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
!! at Mon Jun 06 11:06:18 2016
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
*/
#ifndef _AN_CTLERROR_H
#define _AN_CTLERROR_H
static AntStatus CtlInitError(AntStatus::AntError,1200);
inline AntStatus
CtlErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","Init"));
  return CtlInitError;
}
static AntStatus CtlORBError(AntStatus::AntError,1201);
inline AntStatus
CtlErrORB(AntErrorSeverity severity
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
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","ORB"),arg0);
  return CtlORBError;
}
static AntStatus CtlServerNotRegisteredError(AntStatus::AntError,1202);
inline AntStatus
CtlErrServerNotRegistered(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ServerNotRegistered",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","ServerNotRegistered"),arg0);
  return CtlServerNotRegisteredError;
}
static AntStatus CtlConnectionError(AntStatus::AntError,1203);
inline AntStatus
CtlErrConnection(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Connection",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","Connection"),arg0);
  return CtlConnectionError;
}
static AntStatus CtlRtapFunctionError(AntStatus::AntError,1204);
inline AntStatus
CtlErrRtapFunction(AntErrorSeverity severity
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
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","RtapFunction"),arg0);
  return CtlRtapFunctionError;
}
static AntStatus CtlScadasoftFunctionError(AntStatus::AntError,1205);
inline AntStatus
CtlErrScadasoftFunction(AntErrorSeverity severity
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
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","ScadasoftFunction"),arg0,arg1);
  return CtlScadasoftFunctionError;
}
static AntStatus CtlSystemFunctionError(AntStatus::AntError,1206);
inline AntStatus
CtlErrSystemFunction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SystemFunction",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","SystemFunction"),arg0,arg1);
  return CtlSystemFunctionError;
}
static AntStatus CtlInternalError(AntStatus::AntError,1207);
inline AntStatus
CtlErrInternal(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Internal",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","Internal"),arg0);
  return CtlInternalError;
}
static AntStatus CtlAlmExternError(AntStatus::AntError,1208);
inline AntStatus
CtlErrAlmExtern(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AlmExtern",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","AlmExtern"),arg0,arg1);
  return CtlAlmExternError;
}
static AntStatus CtlBadParamError(AntStatus::AntError,1209);
inline AntStatus
CtlErrBadParam(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadParam",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","BadParam"),arg0);
  return CtlBadParamError;
}
static AntStatus CtlVariableDeclarationError(AntStatus::AntError,1210);
inline AntStatus
CtlErrVariableDeclaration(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "VariableDeclaration",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","VariableDeclaration"),arg0);
  return CtlVariableDeclarationError;
}
static AntStatus CtlMemoryProblemError(AntStatus::AntError,1211);
inline AntStatus
CtlErrMemoryProblem(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MemoryProblem",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","MemoryProblem"),arg0);
  return CtlMemoryProblemError;
}
static AntStatus CtlInitialConditionError(AntStatus::AntError,1212);
inline AntStatus
CtlErrInitialCondition(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InitialCondition",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","InitialCondition"),arg0);
  return CtlInitialConditionError;
}
static AntStatus CtlInitialConditionTimeOutError(AntStatus::AntError,1213);
inline AntStatus
CtlErrInitialConditionTimeOut(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InitialConditionTimeOut",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","InitialConditionTimeOut"));
  return CtlInitialConditionTimeOutError;
}
static AntStatus CtlReturnConditionError(AntStatus::AntError,1214);
inline AntStatus
CtlErrReturnCondition(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ReturnCondition",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","ReturnCondition"),arg0);
  return CtlReturnConditionError;
}
static AntStatus CtlReturnConditionValidError(AntStatus::AntError,1215);
inline AntStatus
CtlErrReturnConditionValid(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ReturnConditionValid",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","ReturnConditionValid"),arg0);
  return CtlReturnConditionValidError;
}
static AntStatus CtlSendCommandError(AntStatus::AntError,1216);
inline AntStatus
CtlErrSendCommand(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SendCommand",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","SendCommand"),arg0,arg1);
  return CtlSendCommandError;
}
static AntStatus CtlBadValueError(AntStatus::AntError,1217);
inline AntStatus
CtlErrBadValue(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadValue",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","BadValue"),arg0,arg1);
  return CtlBadValueError;
}
static AntStatus CtlNoValuePointError(AntStatus::AntError,1218);
inline AntStatus
CtlErrNoValuePoint(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoValuePoint",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","NoValuePoint"),arg0);
  return CtlNoValuePointError;
}
static AntStatus CtlConfigurationError(AntStatus::AntError,1219);
inline AntStatus
CtlErrConfiguration(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Configuration",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","Configuration"),arg0,arg1);
  return CtlConfigurationError;
}
static AntStatus CtlGrcRootNotExistError(AntStatus::AntError,1220);
inline AntStatus
CtlErrGrcRootNotExist(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcRootNotExist",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcRootNotExist"),arg0);
  return CtlGrcRootNotExistError;
}
static AntStatus CtlGrcNotExistError(AntStatus::AntError,1221);
inline AntStatus
CtlErrGrcNotExist(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcNotExist",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcNotExist"),arg0);
  return CtlGrcNotExistError;
}
static AntStatus CtlGrcInvalidDbLocError(AntStatus::AntError,1222);
inline AntStatus
CtlErrGrcInvalidDbLoc(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcInvalidDbLoc",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcInvalidDbLoc"),arg0);
  return CtlGrcInvalidDbLocError;
}
static AntStatus CtlGrcCannotBeLaunchedExeError(AntStatus::AntError,1223);
inline AntStatus
CtlErrGrcCannotBeLaunchedExe(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1, int  arg2, int  arg3, int  arg4, int  arg5
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcCannotBeLaunchedExe",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcCannotBeLaunchedExe"),arg0,arg1,arg2,arg3,arg4,arg5);
  return CtlGrcCannotBeLaunchedExeError;
}
static AntStatus CtlGrcCannotBeLaunchedIniError(AntStatus::AntError,1224);
inline AntStatus
CtlErrGrcCannotBeLaunchedIni(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1, int  arg2, int  arg3
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcCannotBeLaunchedIni",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcCannotBeLaunchedIni"),arg0,arg1,arg2,arg3);
  return CtlGrcCannotBeLaunchedIniError;
}
static AntStatus CtlGrcCannotBeLaunchedInhError(AntStatus::AntError,1225);
inline AntStatus
CtlErrGrcCannotBeLaunchedInh(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1, int  arg2, int  arg3
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcCannotBeLaunchedInh",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcCannotBeLaunchedInh"),arg0,arg1,arg2,arg3);
  return CtlGrcCannotBeLaunchedInhError;
}
static AntStatus CtlGrcProcRunCmdFailedError(AntStatus::AntError,1226);
inline AntStatus
CtlErrGrcProcRunCmdFailed(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcProcRunCmdFailed",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcProcRunCmdFailed"),arg0,arg1);
  return CtlGrcProcRunCmdFailedError;
}
static AntStatus CtlGrcInvalidDbValueError(AntStatus::AntError,1227);
inline AntStatus
CtlErrGrcInvalidDbValue(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcInvalidDbValue",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcInvalidDbValue"),arg0,arg1);
  return CtlGrcInvalidDbValueError;
}
static AntStatus CtlGrcSendingACmdError(AntStatus::AntError,1228);
inline AntStatus
CtlErrGrcSendingACmd(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, float  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcSendingACmd",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcSendingACmd"),arg0,arg1,arg2);
  return CtlGrcSendingACmdError;
}
static AntStatus CtlGrcSendingDCmdError(AntStatus::AntError,1229);
inline AntStatus
CtlErrGrcSendingDCmd(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcSendingDCmd",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcSendingDCmd"),arg0,arg1,arg2);
  return CtlGrcSendingDCmdError;
}
static AntStatus CtlGrcSendingSCmdError(AntStatus::AntError,1230);
inline AntStatus
CtlErrGrcSendingSCmd(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, char * arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcSendingSCmd",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcSendingSCmd"),arg0,arg1,arg2);
  return CtlGrcSendingSCmdError;
}
static AntStatus CtlGrcSendingUCmdError(AntStatus::AntError,1231);
inline AntStatus
CtlErrGrcSendingUCmd(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcSendingUCmd",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcSendingUCmd"),arg0,arg1);
  return CtlGrcSendingUCmdError;
}
static AntStatus CtlGrcRcvCmdCbError(AntStatus::AntError,1232);
inline AntStatus
CtlErrGrcRcvCmdCb(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcRcvCmdCb",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcRcvCmdCb"),arg0);
  return CtlGrcRcvCmdCbError;
}
static AntStatus CtlGrcMaxRetryReachError(AntStatus::AntError,1233);
inline AntStatus
CtlErrGrcMaxRetryReach(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcMaxRetryReach",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcMaxRetryReach"),arg0);
  return CtlGrcMaxRetryReachError;
}
static AntStatus CtlGrcBrcIndexOutOfRangeError(AntStatus::AntError,1234);
inline AntStatus
CtlErrGrcBrcIndexOutOfRange(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, long  arg1, long  arg2, long  arg3
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcBrcIndexOutOfRange",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcBrcIndexOutOfRange"),arg0,arg1,arg2,arg3);
  return CtlGrcBrcIndexOutOfRangeError;
}
static AntStatus CtlLoadingSnapshotError(AntStatus::AntError,1235);
inline AntStatus
CtlErrLoadingSnapshot(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "LoadingSnapshot",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","LoadingSnapshot"),arg0);
  return CtlLoadingSnapshotError;
}
static AntStatus CtlImplementationError(AntStatus::AntError,1236);
inline AntStatus
CtlErrImplementation(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Implementation",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","Implementation"),arg0);
  return CtlImplementationError;
}
static AntStatus CtlGrcExecModeUnknownError(AntStatus::AntError,1237);
inline AntStatus
CtlErrGrcExecModeUnknown(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GrcExecModeUnknown",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","GrcExecModeUnknown"),arg0,arg1);
  return CtlGrcExecModeUnknownError;
}
static AntStatus CtlCallbackError(AntStatus::AntError,1238);
inline AntStatus
CtlErrCallback(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Callback",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","Callback"));
  return CtlCallbackError;
}
static AntStatus CtlCmdNotExecutedError(AntStatus::AntError,1239);
inline AntStatus
CtlErrCmdNotExecuted(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CmdNotExecuted",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","CmdNotExecuted"));
  return CtlCmdNotExecutedError;
}
static AntStatus CtlCmdNotUpdatedError(AntStatus::AntError,1240);
inline AntStatus
CtlErrCmdNotUpdated(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CmdNotUpdated",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","CmdNotUpdated"),arg0);
  return CtlCmdNotUpdatedError;
}
static AntStatus CtlCmdUnWaitedCommandError(AntStatus::AntError,1241);
inline AntStatus
CtlErrCmdUnWaitedCommand(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CmdUnWaitedCommand",
              source,
              "Ctl",
              AntTrace::trace().getErrorFormat("ctlerror.emf","Ctl","CmdUnWaitedCommand"),arg0);
  return CtlCmdUnWaitedCommandError;
}
inline const char *
CtlGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 1200:
    return "Init";
  case 1201:
    return "ORB";
  case 1202:
    return "ServerNotRegistered";
  case 1203:
    return "Connection";
  case 1204:
    return "RtapFunction";
  case 1205:
    return "ScadasoftFunction";
  case 1206:
    return "SystemFunction";
  case 1207:
    return "Internal";
  case 1208:
    return "AlmExtern";
  case 1209:
    return "BadParam";
  case 1210:
    return "VariableDeclaration";
  case 1211:
    return "MemoryProblem";
  case 1212:
    return "InitialCondition";
  case 1213:
    return "InitialConditionTimeOut";
  case 1214:
    return "ReturnCondition";
  case 1215:
    return "ReturnConditionValid";
  case 1216:
    return "SendCommand";
  case 1217:
    return "BadValue";
  case 1218:
    return "NoValuePoint";
  case 1219:
    return "Configuration";
  case 1220:
    return "GrcRootNotExist";
  case 1221:
    return "GrcNotExist";
  case 1222:
    return "GrcInvalidDbLoc";
  case 1223:
    return "GrcCannotBeLaunchedExe";
  case 1224:
    return "GrcCannotBeLaunchedIni";
  case 1225:
    return "GrcCannotBeLaunchedInh";
  case 1226:
    return "GrcProcRunCmdFailed";
  case 1227:
    return "GrcInvalidDbValue";
  case 1228:
    return "GrcSendingACmd";
  case 1229:
    return "GrcSendingDCmd";
  case 1230:
    return "GrcSendingSCmd";
  case 1231:
    return "GrcSendingUCmd";
  case 1232:
    return "GrcRcvCmdCb";
  case 1233:
    return "GrcMaxRetryReach";
  case 1234:
    return "GrcBrcIndexOutOfRange";
  case 1235:
    return "LoadingSnapshot";
  case 1236:
    return "Implementation";
  case 1237:
    return "GrcExecModeUnknown";
  case 1238:
    return "Callback";
  case 1239:
    return "CmdNotExecuted";
  case 1240:
    return "CmdNotUpdated";
  case 1241:
    return "CmdUnWaitedCommand";
  default:
    return "";
  }
}
#endif
