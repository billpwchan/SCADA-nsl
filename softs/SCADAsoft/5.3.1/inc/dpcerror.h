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
!! at Fri Nov 15 16:14:22 2013
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
*/
#ifndef _AN_DPCERROR_H
#define _AN_DPCERROR_H
static AntStatus DpcInitError(AntStatus::AntError,1300);
inline AntStatus
DpcErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","Init"));
  return DpcInitError;
}
static AntStatus DpcORBError(AntStatus::AntError,1301);
inline AntStatus
DpcErrORB(AntErrorSeverity severity
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
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","ORB"),arg0);
  return DpcORBError;
}
static AntStatus DpcServerNotRegisteredError(AntStatus::AntError,1302);
inline AntStatus
DpcErrServerNotRegistered(AntErrorSeverity severity
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
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","ServerNotRegistered"),arg0);
  return DpcServerNotRegisteredError;
}
static AntStatus DpcRtapFunctionError(AntStatus::AntError,1303);
inline AntStatus
DpcErrRtapFunction(AntErrorSeverity severity
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
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","RtapFunction"),arg0);
  return DpcRtapFunctionError;
}
static AntStatus DpcScadasoftFunctionError(AntStatus::AntError,1304);
inline AntStatus
DpcErrScadasoftFunction(AntErrorSeverity severity
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
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","ScadasoftFunction"),arg0,arg1);
  return DpcScadasoftFunctionError;
}
static AntStatus DpcSystemFunctionError(AntStatus::AntError,1305);
inline AntStatus
DpcErrSystemFunction(AntErrorSeverity severity
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
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","SystemFunction"),arg0,arg1);
  return DpcSystemFunctionError;
}
static AntStatus DpcInternalError(AntStatus::AntError,1306);
inline AntStatus
DpcErrInternal(AntErrorSeverity severity
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
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","Internal"),arg0);
  return DpcInternalError;
}
static AntStatus DpcAlmExternError(AntStatus::AntError,1307);
inline AntStatus
DpcErrAlmExtern(AntErrorSeverity severity
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
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","AlmExtern"),arg0,arg1);
  return DpcAlmExternError;
}
static AntStatus DpcCreateDirectoryError(AntStatus::AntError,1308);
inline AntStatus
DpcErrCreateDirectory(AntErrorSeverity severity
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
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","CreateDirectory"),arg0);
  return DpcCreateDirectoryError;
}
static AntStatus DpcBadParamError(AntStatus::AntError,1309);
inline AntStatus
DpcErrBadParam(AntErrorSeverity severity
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
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","BadParam"),arg0);
  return DpcBadParamError;
}
static AntStatus DpcBadStatusError(AntStatus::AntError,1310);
inline AntStatus
DpcErrBadStatus(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadStatus",
              source,
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","BadStatus"),arg0,arg1,arg2);
  return DpcBadStatusError;
}
static AntStatus DpcVariableDeclarationError(AntStatus::AntError,1311);
inline AntStatus
DpcErrVariableDeclaration(AntErrorSeverity severity
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
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","VariableDeclaration"),arg0);
  return DpcVariableDeclarationError;
}
static AntStatus DpcMemoryProblemError(AntStatus::AntError,1312);
inline AntStatus
DpcErrMemoryProblem(AntErrorSeverity severity
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
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","MemoryProblem"),arg0);
  return DpcMemoryProblemError;
}
static AntStatus DpcMaxConnectionsError(AntStatus::AntError,1313);
inline AntStatus
DpcErrMaxConnections(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MaxConnections",
              source,
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","MaxConnections"),arg0);
  return DpcMaxConnectionsError;
}
static AntStatus DpcMaximumSizeError(AntStatus::AntError,1314);
inline AntStatus
DpcErrMaximumSize(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MaximumSize",
              source,
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","MaximumSize"),arg0,arg1);
  return DpcMaximumSizeError;
}
static AntStatus DpcLoadingSnapshotError(AntStatus::AntError,1315);
inline AntStatus
DpcErrLoadingSnapshot(AntErrorSeverity severity
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
              "Dpc",
              AntTrace::trace().getErrorFormat("dpcerror.emf","Dpc","LoadingSnapshot"),arg0);
  return DpcLoadingSnapshotError;
}
inline const char *
DpcGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 1300:
    return "Init";
  case 1301:
    return "ORB";
  case 1302:
    return "ServerNotRegistered";
  case 1303:
    return "RtapFunction";
  case 1304:
    return "ScadasoftFunction";
  case 1305:
    return "SystemFunction";
  case 1306:
    return "Internal";
  case 1307:
    return "AlmExtern";
  case 1308:
    return "CreateDirectory";
  case 1309:
    return "BadParam";
  case 1310:
    return "BadStatus";
  case 1311:
    return "VariableDeclaration";
  case 1312:
    return "MemoryProblem";
  case 1313:
    return "MaxConnections";
  case 1314:
    return "MaximumSize";
  case 1315:
    return "LoadingSnapshot";
  default:
    return "";
  }
}
#endif
