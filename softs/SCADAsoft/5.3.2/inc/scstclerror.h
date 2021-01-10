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
#ifndef _AN_SCSTCLERROR_H
#define _AN_SCSTCLERROR_H
static AntStatus ScsTclInitError(AntStatus::AntError,1100);
inline AntStatus
ScsTclErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","Init"));
  return ScsTclInitError;
}
static AntStatus ScsTclEvalCommandError(AntStatus::AntError,1101);
inline AntStatus
ScsTclErrEvalCommand(AntErrorSeverity severity
      ,short line, const char* file
      , char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "EvalCommand",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","EvalCommand"),arg0);
  return ScsTclEvalCommandError;
}
static AntStatus ScsTclEnvVariableNotFoundError(AntStatus::AntError,1102);
inline AntStatus
ScsTclErrEnvVariableNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "EnvVariableNotFound",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","EnvVariableNotFound"),arg0);
  return ScsTclEnvVariableNotFoundError;
}
static AntStatus ScsTclBadParameterCountError(AntStatus::AntError,1103);
inline AntStatus
ScsTclErrBadParameterCount(AntErrorSeverity severity
      ,short line, const char* file
      , char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadParameterCount",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","BadParameterCount"),arg0);
  return ScsTclBadParameterCountError;
}
static AntStatus ScsTclInvalidCallbackNameError(AntStatus::AntError,1104);
inline AntStatus
ScsTclErrInvalidCallbackName(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidCallbackName",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","InvalidCallbackName"));
  return ScsTclInvalidCallbackNameError;
}
static AntStatus ScsTclExceptionError(AntStatus::AntError,1105);
inline AntStatus
ScsTclErrException(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Exception",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","Exception"));
  return ScsTclExceptionError;
}
static AntStatus ScsTclCorbaExceptionPNEError(AntStatus::AntError,1106);
inline AntStatus
ScsTclErrCorbaExceptionPNE(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, char * arg1, char * arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CorbaExceptionPNE",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","CorbaExceptionPNE"),arg0,arg1,arg2);
  return ScsTclCorbaExceptionPNEError;
}
static AntStatus ScsTclCorbaExceptionisEvError(AntStatus::AntError,1107);
inline AntStatus
ScsTclErrCorbaExceptionisEv(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, char * arg1, char * arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CorbaExceptionisEv",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","CorbaExceptionisEv"),arg0,arg1,arg2);
  return ScsTclCorbaExceptionisEvError;
}
static AntStatus ScsTclExceptionPNEError(AntStatus::AntError,1108);
inline AntStatus
ScsTclErrExceptionPNE(AntErrorSeverity severity
      ,short line, const char* file
      , char * arg0, char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionPNE",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","ExceptionPNE"),arg0,arg1);
  return ScsTclExceptionPNEError;
}
static AntStatus ScsTclExceptionisEvError(AntStatus::AntError,1109);
inline AntStatus
ScsTclErrExceptionisEv(AntErrorSeverity severity
      ,short line, const char* file
      , char * arg0, char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExceptionisEv",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","ExceptionisEv"),arg0,arg1);
  return ScsTclExceptionisEvError;
}
static AntStatus ScsTclNullServerError(AntStatus::AntError,1110);
inline AntStatus
ScsTclErrNullServer(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NullServer",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","NullServer"));
  return ScsTclNullServerError;
}
static AntStatus ScsTclMaxServerReachedError(AntStatus::AntError,1111);
inline AntStatus
ScsTclErrMaxServerReached(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MaxServerReached",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","MaxServerReached"));
  return ScsTclMaxServerReachedError;
}
static AntStatus ScsTclMaxGroupReachedError(AntStatus::AntError,1112);
inline AntStatus
ScsTclErrMaxGroupReached(AntErrorSeverity severity
      ,short line, const char* file
      , char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MaxGroupReached",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","MaxGroupReached"),arg0);
  return ScsTclMaxGroupReachedError;
}
static AntStatus ScsTclGroupAlreadySubscribeError(AntStatus::AntError,1113);
inline AntStatus
ScsTclErrGroupAlreadySubscribe(AntErrorSeverity severity
      ,short line, const char* file
      , char * arg0, char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GroupAlreadySubscribe",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","GroupAlreadySubscribe"),arg0,arg1);
  return ScsTclGroupAlreadySubscribeError;
}
static AntStatus ScsTclGroupUnknownError(AntStatus::AntError,1114);
inline AntStatus
ScsTclErrGroupUnknown(AntErrorSeverity severity
      ,short line, const char* file
      , char * arg0, char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GroupUnknown",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","GroupUnknown"),arg0,arg1);
  return ScsTclGroupUnknownError;
}
static AntStatus ScsTclGroupUnknownCbError(AntStatus::AntError,1115);
inline AntStatus
ScsTclErrGroupUnknownCb(AntErrorSeverity severity
      ,short line, const char* file
      , char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GroupUnknownCb",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","GroupUnknownCb"),arg0);
  return ScsTclGroupUnknownCbError;
}
static AntStatus ScsTclServerNotAvailableError(AntStatus::AntError,1116);
inline AntStatus
ScsTclErrServerNotAvailable(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ServerNotAvailable",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","ServerNotAvailable"),arg0,arg1);
  return ScsTclServerNotAvailableError;
}
static AntStatus ScsTclInvalidEnvError(AntStatus::AntError,1117);
inline AntStatus
ScsTclErrInvalidEnv(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidEnv",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","InvalidEnv"),arg0);
  return ScsTclInvalidEnvError;
}
static AntStatus ScsTclInvalidServerNameError(AntStatus::AntError,1118);
inline AntStatus
ScsTclErrInvalidServerName(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidServerName",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","InvalidServerName"),arg0);
  return ScsTclInvalidServerNameError;
}
static AntStatus ScsTclInvalidOnErrorTypeError(AntStatus::AntError,1119);
inline AntStatus
ScsTclErrInvalidOnErrorType(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidOnErrorType",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","InvalidOnErrorType"),arg0);
  return ScsTclInvalidOnErrorTypeError;
}
static AntStatus ScsTclInvalidCommandTypeError(AntStatus::AntError,1120);
inline AntStatus
ScsTclErrInvalidCommandType(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidCommandType",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","InvalidCommandType"),arg0);
  return ScsTclInvalidCommandTypeError;
}
static AntStatus ScsTclInvalidByPassModeError(AntStatus::AntError,1121);
inline AntStatus
ScsTclErrInvalidByPassMode(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidByPassMode",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","InvalidByPassMode"),arg0);
  return ScsTclInvalidByPassModeError;
}
static AntStatus ScsTclInvalidSendBError(AntStatus::AntError,1122);
inline AntStatus
ScsTclErrInvalidSendB(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidSendB",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","InvalidSendB"),arg0);
  return ScsTclInvalidSendBError;
}
static AntStatus ScsTclInvalidEqpStatusError(AntStatus::AntError,1123);
inline AntStatus
ScsTclErrInvalidEqpStatus(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidEqpStatus",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","InvalidEqpStatus"),arg0);
  return ScsTclInvalidEqpStatusError;
}
static AntStatus ScsTclInvalidVarStatusError(AntStatus::AntError,1124);
inline AntStatus
ScsTclErrInvalidVarStatus(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidVarStatus",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","InvalidVarStatus"),arg0);
  return ScsTclInvalidVarStatusError;
}
static AntStatus ScsTclInvalidVarForceError(AntStatus::AntError,1125);
inline AntStatus
ScsTclErrInvalidVarForce(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidVarForce",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","InvalidVarForce"),arg0);
  return ScsTclInvalidVarForceError;
}
static AntStatus ScsTclInvalidDataTypeError(AntStatus::AntError,1126);
inline AntStatus
ScsTclErrInvalidDataType(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidDataType",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","InvalidDataType"),arg0);
  return ScsTclInvalidDataTypeError;
}
static AntStatus ScsTclBadParameterLengthError(AntStatus::AntError,1127);
inline AntStatus
ScsTclErrBadParameterLength(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadParameterLength",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","BadParameterLength"));
  return ScsTclBadParameterLengthError;
}
static AntStatus ScsTclMaxTimerReachedError(AntStatus::AntError,1128);
inline AntStatus
ScsTclErrMaxTimerReached(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MaxTimerReached",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","MaxTimerReached"));
  return ScsTclMaxTimerReachedError;
}
static AntStatus ScsTclTimerNotFoundError(AntStatus::AntError,1129);
inline AntStatus
ScsTclErrTimerNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "TimerNotFound",
              source,
              "ScsTcl",
              AntTrace::trace().getErrorFormat("scstcl.emf","ScsTcl","TimerNotFound"),arg0);
  return ScsTclTimerNotFoundError;
}
inline const char *
ScsTclGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 1100:
    return "Init";
  case 1101:
    return "EvalCommand";
  case 1102:
    return "EnvVariableNotFound";
  case 1103:
    return "BadParameterCount";
  case 1104:
    return "InvalidCallbackName";
  case 1105:
    return "Exception";
  case 1106:
    return "CorbaExceptionPNE";
  case 1107:
    return "CorbaExceptionisEv";
  case 1108:
    return "ExceptionPNE";
  case 1109:
    return "ExceptionisEv";
  case 1110:
    return "NullServer";
  case 1111:
    return "MaxServerReached";
  case 1112:
    return "MaxGroupReached";
  case 1113:
    return "GroupAlreadySubscribe";
  case 1114:
    return "GroupUnknown";
  case 1115:
    return "GroupUnknownCb";
  case 1116:
    return "ServerNotAvailable";
  case 1117:
    return "InvalidEnv";
  case 1118:
    return "InvalidServerName";
  case 1119:
    return "InvalidOnErrorType";
  case 1120:
    return "InvalidCommandType";
  case 1121:
    return "InvalidByPassMode";
  case 1122:
    return "InvalidSendB";
  case 1123:
    return "InvalidEqpStatus";
  case 1124:
    return "InvalidVarStatus";
  case 1125:
    return "InvalidVarForce";
  case 1126:
    return "InvalidDataType";
  case 1127:
    return "BadParameterLength";
  case 1128:
    return "MaxTimerReached";
  case 1129:
    return "TimerNotFound";
  default:
    return "";
  }
}
#endif
