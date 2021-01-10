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
#ifndef _AN_IMGERROR_H
#define _AN_IMGERROR_H
static AntStatus ImgInitError(AntStatus::AntError,900);
inline AntStatus
ImgErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","Init"));
  return ImgInitError;
}
static AntStatus ImgORBError(AntStatus::AntError,901);
inline AntStatus
ImgErrORB(AntErrorSeverity severity
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
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","ORB"),arg0);
  return ImgORBError;
}
static AntStatus ImgUnixError(AntStatus::AntError,902);
inline AntStatus
ImgErrUnix(AntErrorSeverity severity
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
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","Unix"),arg0,arg1);
  return ImgUnixError;
}
static AntStatus ImgNoManagerError(AntStatus::AntError,903);
inline AntStatus
ImgErrNoManager(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoManager",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","NoManager"));
  return ImgNoManagerError;
}
static AntStatus ImgEnvironmentDownError(AntStatus::AntError,904);
inline AntStatus
ImgErrEnvironmentDown(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "EnvironmentDown",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","EnvironmentDown"));
  return ImgEnvironmentDownError;
}
static AntStatus ImgMsgSendError(AntStatus::AntError,905);
inline AntStatus
ImgErrMsgSend(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MsgSend",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","MsgSend"),arg0,arg1);
  return ImgMsgSendError;
}
static AntStatus ImgMsgGetResultError(AntStatus::AntError,906);
inline AntStatus
ImgErrMsgGetResult(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MsgGetResult",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","MsgGetResult"),arg0,arg1);
  return ImgMsgGetResultError;
}
static AntStatus ImgMsgTooManyAnswersError(AntStatus::AntError,907);
inline AntStatus
ImgErrMsgTooManyAnswers(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1, int  arg2, int  arg3
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MsgTooManyAnswers",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","MsgTooManyAnswers"),arg0,arg1,arg2,arg3);
  return ImgMsgTooManyAnswersError;
}
static AntStatus ImgWaitQueueNoPreviousError(AntStatus::AntError,908);
inline AntStatus
ImgErrWaitQueueNoPrevious(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WaitQueueNoPrevious",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","WaitQueueNoPrevious"));
  return ImgWaitQueueNoPreviousError;
}
static AntStatus ImgMsgQueueDoesNotExistError(AntStatus::AntError,909);
inline AntStatus
ImgErrMsgQueueDoesNotExist(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MsgQueueDoesNotExist",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","MsgQueueDoesNotExist"),arg0);
  return ImgMsgQueueDoesNotExistError;
}
static AntStatus ImgImgUpdateTimeError(AntStatus::AntError,910);
inline AntStatus
ImgErrImgUpdateTime(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ImgUpdateTime",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","ImgUpdateTime"));
  return ImgImgUpdateTimeError;
}
static AntStatus ImgImgBadNbPhysEnvRunningError(AntStatus::AntError,911);
inline AntStatus
ImgErrImgBadNbPhysEnvRunning(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ImgBadNbPhysEnvRunning",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","ImgBadNbPhysEnvRunning"));
  return ImgImgBadNbPhysEnvRunningError;
}
static AntStatus ImgNoSnapshotFileError(AntStatus::AntError,912);
inline AntStatus
ImgErrNoSnapshotFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoSnapshotFile",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","NoSnapshotFile"),arg0);
  return ImgNoSnapshotFileError;
}
static AntStatus ImgImgStandbyUpError(AntStatus::AntError,913);
inline AntStatus
ImgErrImgStandbyUp(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ImgStandbyUp",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","ImgStandbyUp"));
  return ImgImgStandbyUpError;
}
static AntStatus ImgRtapSnapshotError(AntStatus::AntError,914);
inline AntStatus
ImgErrRtapSnapshot(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RtapSnapshot",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","RtapSnapshot"));
  return ImgRtapSnapshotError;
}
static AntStatus ImgNoReplyError(AntStatus::AntError,915);
inline AntStatus
ImgErrNoReply(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoReply",
              source,
              "Img",
              AntTrace::trace().getErrorFormat("imgerror.emf","Img","NoReply"));
  return ImgNoReplyError;
}
inline const char *
ImgGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 900:
    return "Init";
  case 901:
    return "ORB";
  case 902:
    return "Unix";
  case 903:
    return "NoManager";
  case 904:
    return "EnvironmentDown";
  case 905:
    return "MsgSend";
  case 906:
    return "MsgGetResult";
  case 907:
    return "MsgTooManyAnswers";
  case 908:
    return "WaitQueueNoPrevious";
  case 909:
    return "MsgQueueDoesNotExist";
  case 910:
    return "ImgUpdateTime";
  case 911:
    return "ImgBadNbPhysEnvRunning";
  case 912:
    return "NoSnapshotFile";
  case 913:
    return "ImgStandbyUp";
  case 914:
    return "RtapSnapshot";
  case 915:
    return "NoReply";
  default:
    return "";
  }
}
#endif
