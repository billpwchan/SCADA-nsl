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
#ifndef _AN_FTSERROR_H
#define _AN_FTSERROR_H
static AntStatus FtsInitError(AntStatus::AntError,1500);
inline AntStatus
FtsErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","Init"));
  return FtsInitError;
}
static AntStatus FtsORBError(AntStatus::AntError,1501);
inline AntStatus
FtsErrORB(AntErrorSeverity severity
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
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","ORB"),arg0);
  return FtsORBError;
}
static AntStatus FtsHostServerError(AntStatus::AntError,1502);
inline AntStatus
FtsErrHostServer(AntErrorSeverity severity
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
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","HostServer"),arg0);
  return FtsHostServerError;
}
static AntStatus FtsPermissionDeniedError(AntStatus::AntError,1503);
inline AntStatus
FtsErrPermissionDenied(AntErrorSeverity severity
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
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","PermissionDenied"),arg0,arg1);
  return FtsPermissionDeniedError;
}
static AntStatus FtsProfileNotFoundError(AntStatus::AntError,1504);
inline AntStatus
FtsErrProfileNotFound(AntErrorSeverity severity
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
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","ProfileNotFound"),arg0);
  return FtsProfileNotFoundError;
}
static AntStatus FtsBusyError(AntStatus::AntError,1505);
inline AntStatus
FtsErrBusy(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Busy",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","Busy"));
  return FtsBusyError;
}
static AntStatus FtsFileNotFoundError(AntStatus::AntError,1506);
inline AntStatus
FtsErrFileNotFound(AntErrorSeverity severity
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
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","FileNotFound"),arg0);
  return FtsFileNotFoundError;
}
static AntStatus FtsDirNotFoundError(AntStatus::AntError,1507);
inline AntStatus
FtsErrDirNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DirNotFound",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","DirNotFound"),arg0);
  return FtsDirNotFoundError;
}
static AntStatus FtsLocalDirScanFailError(AntStatus::AntError,1508);
inline AntStatus
FtsErrLocalDirScanFail(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "LocalDirScanFail",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","LocalDirScanFail"),arg0);
  return FtsLocalDirScanFailError;
}
static AntStatus FtsRemoteDirNotFoundError(AntStatus::AntError,1509);
inline AntStatus
FtsErrRemoteDirNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RemoteDirNotFound",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","RemoteDirNotFound"),arg0,arg1);
  return FtsRemoteDirNotFoundError;
}
static AntStatus FtsRemoteDirGetFailError(AntStatus::AntError,1510);
inline AntStatus
FtsErrRemoteDirGetFail(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RemoteDirGetFail",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","RemoteDirGetFail"),arg0,arg1);
  return FtsRemoteDirGetFailError;
}
static AntStatus FtsCannotCreateRemoteDirError(AntStatus::AntError,1511);
inline AntStatus
FtsErrCannotCreateRemoteDir(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CannotCreateRemoteDir",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","CannotCreateRemoteDir"),arg0,arg1);
  return FtsCannotCreateRemoteDirError;
}
static AntStatus FtsRemoteDirReadFailError(AntStatus::AntError,1512);
inline AntStatus
FtsErrRemoteDirReadFail(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RemoteDirReadFail",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","RemoteDirReadFail"),arg0,arg1);
  return FtsRemoteDirReadFailError;
}
static AntStatus FtsFunctionError(AntStatus::AntError,1513);
inline AntStatus
FtsErrFunction(AntErrorSeverity severity
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
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","Function"),arg0);
  return FtsFunctionError;
}
static AntStatus FtsNoServerError(AntStatus::AntError,1514);
inline AntStatus
FtsErrNoServer(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoServer",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","NoServer"));
  return FtsNoServerError;
}
static AntStatus FtsConnectFailError(AntStatus::AntError,1515);
inline AntStatus
FtsErrConnectFail(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ConnectFail",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","ConnectFail"),arg0);
  return FtsConnectFailError;
}
static AntStatus FtsLoginFailError(AntStatus::AntError,1516);
inline AntStatus
FtsErrLoginFail(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "LoginFail",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","LoginFail"),arg0,arg1);
  return FtsLoginFailError;
}
static AntStatus FtsRenameFileError(AntStatus::AntError,1517);
inline AntStatus
FtsErrRenameFile(AntErrorSeverity severity
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
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","RenameFile"),arg0,arg1);
  return FtsRenameFileError;
}
static AntStatus FtsPutFailError(AntStatus::AntError,1518);
inline AntStatus
FtsErrPutFail(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "PutFail",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","PutFail"),arg0,arg1);
  return FtsPutFailError;
}
static AntStatus FtsGetFailError(AntStatus::AntError,1519);
inline AntStatus
FtsErrGetFail(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GetFail",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","GetFail"),arg0,arg1);
  return FtsGetFailError;
}
static AntStatus FtsLocalDeleteFailError(AntStatus::AntError,1520);
inline AntStatus
FtsErrLocalDeleteFail(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "LocalDeleteFail",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","LocalDeleteFail"),arg0);
  return FtsLocalDeleteFailError;
}
static AntStatus FtsRemoteDeleteFailError(AntStatus::AntError,1521);
inline AntStatus
FtsErrRemoteDeleteFail(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RemoteDeleteFail",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","RemoteDeleteFail"),arg0,arg1);
  return FtsRemoteDeleteFailError;
}
static AntStatus FtsDeleteDirFailError(AntStatus::AntError,1522);
inline AntStatus
FtsErrDeleteDirFail(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DeleteDirFail",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","DeleteDirFail"),arg0,arg1);
  return FtsDeleteDirFailError;
}
static AntStatus FtsChDirFailError(AntStatus::AntError,1523);
inline AntStatus
FtsErrChDirFail(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ChDirFail",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","ChDirFail"),arg0,arg1);
  return FtsChDirFailError;
}
static AntStatus FtsEmptyDirError(AntStatus::AntError,1524);
inline AntStatus
FtsErrEmptyDir(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "EmptyDir",
              source,
              "Fts",
              AntTrace::trace().getErrorFormat("ftserror.emf","Fts","EmptyDir"),arg0,arg1);
  return FtsEmptyDirError;
}
inline const char *
FtsGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 1500:
    return "Init";
  case 1501:
    return "ORB";
  case 1502:
    return "HostServer";
  case 1503:
    return "PermissionDenied";
  case 1504:
    return "ProfileNotFound";
  case 1505:
    return "Busy";
  case 1506:
    return "FileNotFound";
  case 1507:
    return "DirNotFound";
  case 1508:
    return "LocalDirScanFail";
  case 1509:
    return "RemoteDirNotFound";
  case 1510:
    return "RemoteDirGetFail";
  case 1511:
    return "CannotCreateRemoteDir";
  case 1512:
    return "RemoteDirReadFail";
  case 1513:
    return "Function";
  case 1514:
    return "NoServer";
  case 1515:
    return "ConnectFail";
  case 1516:
    return "LoginFail";
  case 1517:
    return "RenameFile";
  case 1518:
    return "PutFail";
  case 1519:
    return "GetFail";
  case 1520:
    return "LocalDeleteFail";
  case 1521:
    return "RemoteDeleteFail";
  case 1522:
    return "DeleteDirFail";
  case 1523:
    return "ChDirFail";
  case 1524:
    return "EmptyDir";
  default:
    return "";
  }
}
#endif
