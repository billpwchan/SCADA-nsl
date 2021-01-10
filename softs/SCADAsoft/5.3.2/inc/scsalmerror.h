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
#ifndef _AN_SCSALMERROR_H
#define _AN_SCSALMERROR_H
static AntStatus ScsAlmInitError(AntStatus::AntError,500);
inline AntStatus
ScsAlmErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","Init"));
  return ScsAlmInitError;
}
static AntStatus ScsAlmORBError(AntStatus::AntError,501);
inline AntStatus
ScsAlmErrORB(AntErrorSeverity severity
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
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","ORB"),arg0);
  return ScsAlmORBError;
}
static AntStatus ScsAlmHostServerError(AntStatus::AntError,502);
inline AntStatus
ScsAlmErrHostServer(AntErrorSeverity severity
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
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","HostServer"),arg0);
  return ScsAlmHostServerError;
}
static AntStatus ScsAlmSystemFunctionError(AntStatus::AntError,503);
inline AntStatus
ScsAlmErrSystemFunction(AntErrorSeverity severity
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
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","SystemFunction"),arg0);
  return ScsAlmSystemFunctionError;
}
static AntStatus ScsAlmListActionError(AntStatus::AntError,504);
inline AntStatus
ScsAlmErrListAction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ListAction",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","ListAction"),arg0);
  return ScsAlmListActionError;
}
static AntStatus ScsAlmRtapEnvError(AntStatus::AntError,505);
inline AntStatus
ScsAlmErrRtapEnv(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RtapEnv",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","RtapEnv"));
  return ScsAlmRtapEnvError;
}
static AntStatus ScsAlmResetDatabaseError(AntStatus::AntError,506);
inline AntStatus
ScsAlmErrResetDatabase(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ResetDatabase",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","ResetDatabase"));
  return ScsAlmResetDatabaseError;
}
static AntStatus ScsAlmDataBaseConnectionError(AntStatus::AntError,507);
inline AntStatus
ScsAlmErrDataBaseConnection(AntErrorSeverity severity
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
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","DataBaseConnection"),arg0);
  return ScsAlmDataBaseConnectionError;
}
static AntStatus ScsAlmDbmServerNotReachableError(AntStatus::AntError,508);
inline AntStatus
ScsAlmErrDbmServerNotReachable(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DbmServerNotReachable",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","DbmServerNotReachable"),arg0);
  return ScsAlmDbmServerNotReachableError;
}
static AntStatus ScsAlmUndefinedValueAutomatonError(AntStatus::AntError,509);
inline AntStatus
ScsAlmErrUndefinedValueAutomaton(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UndefinedValueAutomaton",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","UndefinedValueAutomaton"),arg0,arg1,arg2);
  return ScsAlmUndefinedValueAutomatonError;
}
static AntStatus ScsAlmUndefinedValueAutomatonExtError(AntStatus::AntError,510);
inline AntStatus
ScsAlmErrUndefinedValueAutomatonExt(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UndefinedValueAutomatonExt",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","UndefinedValueAutomatonExt"),arg0,arg1);
  return ScsAlmUndefinedValueAutomatonExtError;
}
static AntStatus ScsAlmUndefinedAckAutomatonError(AntStatus::AntError,511);
inline AntStatus
ScsAlmErrUndefinedAckAutomaton(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UndefinedAckAutomaton",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","UndefinedAckAutomaton"),arg0,arg1,arg2);
  return ScsAlmUndefinedAckAutomatonError;
}
static AntStatus ScsAlmUndefinedAckAutomatonExtError(AntStatus::AntError,512);
inline AntStatus
ScsAlmErrUndefinedAckAutomatonExt(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UndefinedAckAutomatonExt",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","UndefinedAckAutomatonExt"),arg0,arg1);
  return ScsAlmUndefinedAckAutomatonExtError;
}
static AntStatus ScsAlmNullPointerAutomatonError(AntStatus::AntError,513);
inline AntStatus
ScsAlmErrNullPointerAutomaton(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NullPointerAutomaton",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","NullPointerAutomaton"),arg0,arg1,arg2);
  return ScsAlmNullPointerAutomatonError;
}
static AntStatus ScsAlmNullPointerAutomatonExtError(AntStatus::AntError,514);
inline AntStatus
ScsAlmErrNullPointerAutomatonExt(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NullPointerAutomatonExt",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","NullPointerAutomatonExt"),arg0,arg1);
  return ScsAlmNullPointerAutomatonExtError;
}
static AntStatus ScsAlmNullAckPointerAutomatonError(AntStatus::AntError,515);
inline AntStatus
ScsAlmErrNullAckPointerAutomaton(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NullAckPointerAutomaton",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","NullAckPointerAutomaton"),arg0);
  return ScsAlmNullAckPointerAutomatonError;
}
static AntStatus ScsAlmUnknownAlarmDbRefError(AntStatus::AntError,516);
inline AntStatus
ScsAlmErrUnknownAlarmDbRef(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownAlarmDbRef",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","UnknownAlarmDbRef"),arg0);
  return ScsAlmUnknownAlarmDbRefError;
}
static AntStatus ScsAlmReadEquipmentError(AntStatus::AntError,517);
inline AntStatus
ScsAlmErrReadEquipment(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ReadEquipment",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","ReadEquipment"),arg0);
  return ScsAlmReadEquipmentError;
}
static AntStatus ScsAlmBadExtAlarmIdError(AntStatus::AntError,518);
inline AntStatus
ScsAlmErrBadExtAlarmId(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadExtAlarmId",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","BadExtAlarmId"),arg0);
  return ScsAlmBadExtAlarmIdError;
}
static AntStatus ScsAlmExtShmFullError(AntStatus::AntError,519);
inline AntStatus
ScsAlmErrExtShmFull(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExtShmFull",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","ExtShmFull"));
  return ScsAlmExtShmFullError;
}
static AntStatus ScsAlmTimerInProgressError(AntStatus::AntError,520);
inline AntStatus
ScsAlmErrTimerInProgress(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "TimerInProgress",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","TimerInProgress"),arg0,arg1);
  return ScsAlmTimerInProgressError;
}
static AntStatus ScsAlmExtTimerInProgressError(AntStatus::AntError,521);
inline AntStatus
ScsAlmErrExtTimerInProgress(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExtTimerInProgress",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","ExtTimerInProgress"),arg0);
  return ScsAlmExtTimerInProgressError;
}
static AntStatus ScsAlmBadListSizeError(AntStatus::AntError,522);
inline AntStatus
ScsAlmErrBadListSize(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadListSize",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","BadListSize"),arg0,arg1);
  return ScsAlmBadListSizeError;
}
static AntStatus ScsAlmBadParamError(AntStatus::AntError,523);
inline AntStatus
ScsAlmErrBadParam(AntErrorSeverity severity
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
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","BadParam"),arg0);
  return ScsAlmBadParamError;
}
static AntStatus ScsAlmRtapFunctionError(AntStatus::AntError,524);
inline AntStatus
ScsAlmErrRtapFunction(AntErrorSeverity severity
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
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","RtapFunction"),arg0);
  return ScsAlmRtapFunctionError;
}
static AntStatus ScsAlmScadasoftFunctionError(AntStatus::AntError,525);
inline AntStatus
ScsAlmErrScadasoftFunction(AntErrorSeverity severity
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
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","ScadasoftFunction"),arg0,arg1);
  return ScsAlmScadasoftFunctionError;
}
static AntStatus ScsAlmInternalError(AntStatus::AntError,526);
inline AntStatus
ScsAlmErrInternal(AntErrorSeverity severity
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
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","Internal"),arg0);
  return ScsAlmInternalError;
}
static AntStatus ScsAlmNullPointerAutomatonCreationError(AntStatus::AntError,527);
inline AntStatus
ScsAlmErrNullPointerAutomatonCreation(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, long  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NullPointerAutomatonCreation",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","NullPointerAutomatonCreation"),arg0,arg1);
  return ScsAlmNullPointerAutomatonCreationError;
}
static AntStatus ScsAlmNullPointerAckCreationError(AntStatus::AntError,528);
inline AntStatus
ScsAlmErrNullPointerAckCreation(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NullPointerAckCreation",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","NullPointerAckCreation"),arg0,arg1);
  return ScsAlmNullPointerAckCreationError;
}
static AntStatus ScsAlmTimeoutError(AntStatus::AntError,529);
inline AntStatus
ScsAlmErrTimeout(AntErrorSeverity severity
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
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","Timeout"),arg0,arg1);
  return ScsAlmTimeoutError;
}
static AntStatus ScsAlmDuplicateExtAlarmIdError(AntStatus::AntError,530);
inline AntStatus
ScsAlmErrDuplicateExtAlarmId(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DuplicateExtAlarmId",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","DuplicateExtAlarmId"),arg0);
  return ScsAlmDuplicateExtAlarmIdError;
}
static AntStatus ScsAlmOpenConfigFileError(AntStatus::AntError,531);
inline AntStatus
ScsAlmErrOpenConfigFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "OpenConfigFile",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","OpenConfigFile"),arg0);
  return ScsAlmOpenConfigFileError;
}
static AntStatus ScsAlmReadConfigFileError(AntStatus::AntError,532);
inline AntStatus
ScsAlmErrReadConfigFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ReadConfigFile",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","ReadConfigFile"),arg0);
  return ScsAlmReadConfigFileError;
}
static AntStatus ScsAlmInvalidFieldTypeError(AntStatus::AntError,533);
inline AntStatus
ScsAlmErrInvalidFieldType(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidFieldType",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","InvalidFieldType"),arg0,arg1);
  return ScsAlmInvalidFieldTypeError;
}
static AntStatus ScsAlmInvalidFieldCountError(AntStatus::AntError,534);
inline AntStatus
ScsAlmErrInvalidFieldCount(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidFieldCount",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","InvalidFieldCount"),arg0);
  return ScsAlmInvalidFieldCountError;
}
static AntStatus ScsAlmInvalidFieldListError(AntStatus::AntError,535);
inline AntStatus
ScsAlmErrInvalidFieldList(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidFieldList",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","InvalidFieldList"));
  return ScsAlmInvalidFieldListError;
}
static AntStatus ScsAlmNoAlarmFoundError(AntStatus::AntError,536);
inline AntStatus
ScsAlmErrNoAlarmFound(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoAlarmFound",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","NoAlarmFound"),arg0,arg1);
  return ScsAlmNoAlarmFoundError;
}
static AntStatus ScsAlmOpenReadFileError(AntStatus::AntError,537);
inline AntStatus
ScsAlmErrOpenReadFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "OpenReadFile",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","OpenReadFile"),arg0);
  return ScsAlmOpenReadFileError;
}
static AntStatus ScsAlmOpenWriteFileError(AntStatus::AntError,538);
inline AntStatus
ScsAlmErrOpenWriteFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "OpenWriteFile",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","OpenWriteFile"),arg0);
  return ScsAlmOpenWriteFileError;
}
static AntStatus ScsAlmCreateDirectoryError(AntStatus::AntError,539);
inline AntStatus
ScsAlmErrCreateDirectory(AntErrorSeverity severity
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
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","CreateDirectory"),arg0);
  return ScsAlmCreateDirectoryError;
}
static AntStatus ScsAlmCreateFileError(AntStatus::AntError,540);
inline AntStatus
ScsAlmErrCreateFile(AntErrorSeverity severity
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
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","CreateFile"),arg0);
  return ScsAlmCreateFileError;
}
static AntStatus ScsAlmSnapshotSaveError(AntStatus::AntError,541);
inline AntStatus
ScsAlmErrSnapshotSave(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  long  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SnapshotSave",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","SnapshotSave"),arg0,arg1);
  return ScsAlmSnapshotSaveError;
}
static AntStatus ScsAlmSnapshotRestoreError(AntStatus::AntError,542);
inline AntStatus
ScsAlmErrSnapshotRestore(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  long  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SnapshotRestore",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","SnapshotRestore"),arg0,arg1);
  return ScsAlmSnapshotRestoreError;
}
static AntStatus ScsAlmUnknownKeyError(AntStatus::AntError,543);
inline AntStatus
ScsAlmErrUnknownKey(AntErrorSeverity severity
      ,short line, const char* file
      ,const  long  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownKey",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","UnknownKey"),arg0);
  return ScsAlmUnknownKeyError;
}
static AntStatus ScsAlmUnknownStateError(AntStatus::AntError,544);
inline AntStatus
ScsAlmErrUnknownState(AntErrorSeverity severity
      ,short line, const char* file
      ,const  long  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownState",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","UnknownState"),arg0,arg1);
  return ScsAlmUnknownStateError;
}
static AntStatus ScsAlmNullPointerForAutomatonError(AntStatus::AntError,545);
inline AntStatus
ScsAlmErrNullPointerForAutomaton(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NullPointerForAutomaton",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","NullPointerForAutomaton"),arg0,arg1);
  return ScsAlmNullPointerForAutomatonError;
}
static AntStatus ScsAlmDatabaseAccessError(AntStatus::AntError,546);
inline AntStatus
ScsAlmErrDatabaseAccess(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DatabaseAccess",
              source,
              "ScsAlm",
              AntTrace::trace().getErrorFormat("scsalmerror.emf","ScsAlm","DatabaseAccess"),arg0);
  return ScsAlmDatabaseAccessError;
}
inline const char *
ScsAlmGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 500:
    return "Init";
  case 501:
    return "ORB";
  case 502:
    return "HostServer";
  case 503:
    return "SystemFunction";
  case 504:
    return "ListAction";
  case 505:
    return "RtapEnv";
  case 506:
    return "ResetDatabase";
  case 507:
    return "DataBaseConnection";
  case 508:
    return "DbmServerNotReachable";
  case 509:
    return "UndefinedValueAutomaton";
  case 510:
    return "UndefinedValueAutomatonExt";
  case 511:
    return "UndefinedAckAutomaton";
  case 512:
    return "UndefinedAckAutomatonExt";
  case 513:
    return "NullPointerAutomaton";
  case 514:
    return "NullPointerAutomatonExt";
  case 515:
    return "NullAckPointerAutomaton";
  case 516:
    return "UnknownAlarmDbRef";
  case 517:
    return "ReadEquipment";
  case 518:
    return "BadExtAlarmId";
  case 519:
    return "ExtShmFull";
  case 520:
    return "TimerInProgress";
  case 521:
    return "ExtTimerInProgress";
  case 522:
    return "BadListSize";
  case 523:
    return "BadParam";
  case 524:
    return "RtapFunction";
  case 525:
    return "ScadasoftFunction";
  case 526:
    return "Internal";
  case 527:
    return "NullPointerAutomatonCreation";
  case 528:
    return "NullPointerAckCreation";
  case 529:
    return "Timeout";
  case 530:
    return "DuplicateExtAlarmId";
  case 531:
    return "OpenConfigFile";
  case 532:
    return "ReadConfigFile";
  case 533:
    return "InvalidFieldType";
  case 534:
    return "InvalidFieldCount";
  case 535:
    return "InvalidFieldList";
  case 536:
    return "NoAlarmFound";
  case 537:
    return "OpenReadFile";
  case 538:
    return "OpenWriteFile";
  case 539:
    return "CreateDirectory";
  case 540:
    return "CreateFile";
  case 541:
    return "SnapshotSave";
  case 542:
    return "SnapshotRestore";
  case 543:
    return "UnknownKey";
  case 544:
    return "UnknownState";
  case 545:
    return "NullPointerForAutomaton";
  case 546:
    return "DatabaseAccess";
  default:
    return "";
  }
}
#endif
