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
!! at Fri Nov 15 16:14:23 2013
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
*/
#ifndef _AN_SCSRPLERROR_H
#define _AN_SCSRPLERROR_H
static AntStatus ScsRplScadasoftFunctionError(AntStatus::AntError,2800);
inline AntStatus
ScsRplErrScadasoftFunction(AntErrorSeverity severity
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
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","ScadasoftFunction"),arg0,arg1);
  return ScsRplScadasoftFunctionError;
}
static AntStatus ScsRplBadParamError(AntStatus::AntError,2801);
inline AntStatus
ScsRplErrBadParam(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadParam",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","BadParam"),arg0,arg1);
  return ScsRplBadParamError;
}
static AntStatus ScsRplORBError(AntStatus::AntError,2802);
inline AntStatus
ScsRplErrORB(AntErrorSeverity severity
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
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","ORB"),arg0);
  return ScsRplORBError;
}
static AntStatus ScsRplEnvironmentError(AntStatus::AntError,2803);
inline AntStatus
ScsRplErrEnvironment(AntErrorSeverity severity
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
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","Environment"),arg0);
  return ScsRplEnvironmentError;
}
static AntStatus ScsRplUnixError(AntStatus::AntError,2804);
inline AntStatus
ScsRplErrUnix(AntErrorSeverity severity
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
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","Unix"),arg0,arg1);
  return ScsRplUnixError;
}
static AntStatus ScsRplInconsistentObjectError(AntStatus::AntError,2805);
inline AntStatus
ScsRplErrInconsistentObject(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InconsistentObject",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","InconsistentObject"),arg0);
  return ScsRplInconsistentObjectError;
}
static AntStatus ScsRplWritingFileError(AntStatus::AntError,2806);
inline AntStatus
ScsRplErrWritingFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WritingFile",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","WritingFile"),arg0);
  return ScsRplWritingFileError;
}
static AntStatus ScsRplNoMoreRecordToReadError(AntStatus::AntError,2807);
inline AntStatus
ScsRplErrNoMoreRecordToRead(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoMoreRecordToRead",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","NoMoreRecordToRead"));
  return ScsRplNoMoreRecordToReadError;
}
static AntStatus ScsRplForbiddenLoadError(AntStatus::AntError,2808);
inline AntStatus
ScsRplErrForbiddenLoad(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ForbiddenLoad",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","ForbiddenLoad"));
  return ScsRplForbiddenLoadError;
}
static AntStatus ScsRplForbiddenUnfreezeError(AntStatus::AntError,2809);
inline AntStatus
ScsRplErrForbiddenUnfreeze(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ForbiddenUnfreeze",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","ForbiddenUnfreeze"));
  return ScsRplForbiddenUnfreezeError;
}
static AntStatus ScsRplForbiddenFreezeError(AntStatus::AntError,2810);
inline AntStatus
ScsRplErrForbiddenFreeze(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ForbiddenFreeze",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","ForbiddenFreeze"));
  return ScsRplForbiddenFreezeError;
}
static AntStatus ScsRplForbiddenStepError(AntStatus::AntError,2811);
inline AntStatus
ScsRplErrForbiddenStep(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ForbiddenStep",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","ForbiddenStep"));
  return ScsRplForbiddenStepError;
}
static AntStatus ScsRplForbiddenStopError(AntStatus::AntError,2812);
inline AntStatus
ScsRplErrForbiddenStop(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ForbiddenStop",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","ForbiddenStop"));
  return ScsRplForbiddenStopError;
}
static AntStatus ScsRplForbiddenStartError(AntStatus::AntError,2813);
inline AntStatus
ScsRplErrForbiddenStart(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ForbiddenStart",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","ForbiddenStart"));
  return ScsRplForbiddenStartError;
}
static AntStatus ScsRplLoadingSnapshotError(AntStatus::AntError,2814);
inline AntStatus
ScsRplErrLoadingSnapshot(AntErrorSeverity severity
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
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","LoadingSnapshot"),arg0);
  return ScsRplLoadingSnapshotError;
}
static AntStatus ScsRplForbiddenSnapshotNotTrainingError(AntStatus::AntError,2815);
inline AntStatus
ScsRplErrForbiddenSnapshotNotTraining(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ForbiddenSnapshotNotTraining",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","ForbiddenSnapshotNotTraining"));
  return ScsRplForbiddenSnapshotNotTrainingError;
}
static AntStatus ScsRplForbiddenSnapshotNotFrozenError(AntStatus::AntError,2816);
inline AntStatus
ScsRplErrForbiddenSnapshotNotFrozen(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ForbiddenSnapshotNotFrozen",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","ForbiddenSnapshotNotFrozen"));
  return ScsRplForbiddenSnapshotNotFrozenError;
}
static AntStatus ScsRplForbiddenSetTimeNotTrainingError(AntStatus::AntError,2817);
inline AntStatus
ScsRplErrForbiddenSetTimeNotTraining(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ForbiddenSetTimeNotTraining",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","ForbiddenSetTimeNotTraining"));
  return ScsRplForbiddenSetTimeNotTrainingError;
}
static AntStatus ScsRplGenericError(AntStatus::AntError,2818);
inline AntStatus
ScsRplErrGeneric(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Generic",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","Generic"),arg0);
  return ScsRplGenericError;
}
static AntStatus ScsRplRecordInactiveError(AntStatus::AntError,2819);
inline AntStatus
ScsRplErrRecordInactive(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RecordInactive",
              source,
              "Scadasoft",
              AntTrace::trace().getErrorFormat("scsrplerror.emf","ScsRpl","RecordInactive"),arg0);
  return ScsRplRecordInactiveError;
}
inline const char *
ScsRplGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 2800:
    return "ScadasoftFunction";
  case 2801:
    return "BadParam";
  case 2802:
    return "ORB";
  case 2803:
    return "Environment";
  case 2804:
    return "Unix";
  case 2805:
    return "InconsistentObject";
  case 2806:
    return "WritingFile";
  case 2807:
    return "NoMoreRecordToRead";
  case 2808:
    return "ForbiddenLoad";
  case 2809:
    return "ForbiddenUnfreeze";
  case 2810:
    return "ForbiddenFreeze";
  case 2811:
    return "ForbiddenStep";
  case 2812:
    return "ForbiddenStop";
  case 2813:
    return "ForbiddenStart";
  case 2814:
    return "LoadingSnapshot";
  case 2815:
    return "ForbiddenSnapshotNotTraining";
  case 2816:
    return "ForbiddenSnapshotNotFrozen";
  case 2817:
    return "ForbiddenSetTimeNotTraining";
  case 2818:
    return "Generic";
  case 2819:
    return "RecordInactive";
  default:
    return "";
  }
}
#endif
