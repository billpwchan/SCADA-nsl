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
#ifndef _AN_OPMERROR_H
#define _AN_OPMERROR_H
static AntStatus OpmInitError(AntStatus::AntError,1400);
inline AntStatus
OpmErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","Init"));
  return OpmInitError;
}
static AntStatus OpmORBError(AntStatus::AntError,1401);
inline AntStatus
OpmErrORB(AntErrorSeverity severity
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
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","ORB"),arg0);
  return OpmORBError;
}
static AntStatus OpmScadasoftInitError(AntStatus::AntError,1402);
inline AntStatus
OpmErrScadasoftInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ScadasoftInit",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","ScadasoftInit"));
  return OpmScadasoftInitError;
}
static AntStatus OpmScadasoftFunctionError(AntStatus::AntError,1403);
inline AntStatus
OpmErrScadasoftFunction(AntErrorSeverity severity
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
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","ScadasoftFunction"),arg0,arg1);
  return OpmScadasoftFunctionError;
}
static AntStatus OpmGetEnvError(AntStatus::AntError,1404);
inline AntStatus
OpmErrGetEnv(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GetEnv",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","GetEnv"),arg0);
  return OpmGetEnvError;
}
static AntStatus OpmOpenFileError(AntStatus::AntError,1405);
inline AntStatus
OpmErrOpenFile(AntErrorSeverity severity
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
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","OpenFile"),arg0);
  return OpmOpenFileError;
}
static AntStatus OpmParseFileError(AntStatus::AntError,1406);
inline AntStatus
OpmErrParseFile(AntErrorSeverity severity
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
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","ParseFile"),arg0);
  return OpmParseFileError;
}
static AntStatus OpmLoadingSnapshotError(AntStatus::AntError,1407);
inline AntStatus
OpmErrLoadingSnapshot(AntErrorSeverity severity
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
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","LoadingSnapshot"),arg0);
  return OpmLoadingSnapshotError;
}
static AntStatus OpmInitOlsServerError(AntStatus::AntError,1408);
inline AntStatus
OpmErrInitOlsServer(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InitOlsServer",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InitOlsServer"));
  return OpmInitOlsServerError;
}
static AntStatus OpmSubscribeError(AntStatus::AntError,1409);
inline AntStatus
OpmErrSubscribe(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Subscribe",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","Subscribe"),arg0);
  return OpmSubscribeError;
}
static AntStatus OpmSubscribeRemoteError(AntStatus::AntError,1410);
inline AntStatus
OpmErrSubscribeRemote(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1,const  char * arg2, int  arg3
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SubscribeRemote",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","SubscribeRemote"),arg0,arg1,arg2,arg3);
  return OpmSubscribeRemoteError;
}
static AntStatus OpmFieldCountError(AntStatus::AntError,1411);
inline AntStatus
OpmErrFieldCount(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FieldCount",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","FieldCount"),arg0,arg1,arg2);
  return OpmFieldCountError;
}
static AntStatus OpmSubscribeStateError(AntStatus::AntError,1412);
inline AntStatus
OpmErrSubscribeState(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SubscribeState",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","SubscribeState"));
  return OpmSubscribeStateError;
}
static AntStatus OpmUnsubscribeError(AntStatus::AntError,1413);
inline AntStatus
OpmErrUnsubscribe(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Unsubscribe",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","Unsubscribe"),arg0);
  return OpmUnsubscribeError;
}
static AntStatus OpmUpdateLocalBufferError(AntStatus::AntError,1414);
inline AntStatus
OpmErrUpdateLocalBuffer(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UpdateLocalBuffer",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","UpdateLocalBuffer"));
  return OpmUpdateLocalBufferError;
}
static AntStatus OpmInvStringMaskError(AntStatus::AntError,1415);
inline AntStatus
OpmErrInvStringMask(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvStringMask",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InvStringMask"),arg0);
  return OpmInvStringMaskError;
}
static AntStatus OpmInvStringFlagError(AntStatus::AntError,1416);
inline AntStatus
OpmErrInvStringFlag(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvStringFlag",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InvStringFlag"),arg0);
  return OpmInvStringFlagError;
}
static AntStatus OpmInvBitFieldMaskError(AntStatus::AntError,1417);
inline AntStatus
OpmErrInvBitFieldMask(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvBitFieldMask",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InvBitFieldMask"),arg0);
  return OpmInvBitFieldMaskError;
}
static AntStatus OpmInvEnvNameError(AntStatus::AntError,1418);
inline AntStatus
OpmErrInvEnvName(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvEnvName",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InvEnvName"),arg0);
  return OpmInvEnvNameError;
}
static AntStatus OpmInvFuncCategoryError(AntStatus::AntError,1419);
inline AntStatus
OpmErrInvFuncCategory(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvFuncCategory",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InvFuncCategory"),arg0);
  return OpmInvFuncCategoryError;
}
static AntStatus OpmInvFuncNameError(AntStatus::AntError,1420);
inline AntStatus
OpmErrInvFuncName(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvFuncName",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InvFuncName"),arg0);
  return OpmInvFuncNameError;
}
static AntStatus OpmInvLocCategoryError(AntStatus::AntError,1421);
inline AntStatus
OpmErrInvLocCategory(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvLocCategory",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InvLocCategory"),arg0);
  return OpmInvLocCategoryError;
}
static AntStatus OpmInvLocNameError(AntStatus::AntError,1422);
inline AntStatus
OpmErrInvLocName(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvLocName",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InvLocName"),arg0);
  return OpmInvLocNameError;
}
static AntStatus OpmInvActCategoryError(AntStatus::AntError,1423);
inline AntStatus
OpmErrInvActCategory(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvActCategory",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InvActCategory"),arg0);
  return OpmInvActCategoryError;
}
static AntStatus OpmInvActNameError(AntStatus::AntError,1424);
inline AntStatus
OpmErrInvActName(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvActName",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InvActName"),arg0);
  return OpmInvActNameError;
}
static AntStatus OpmInvProfNameError(AntStatus::AntError,1425);
inline AntStatus
OpmErrInvProfName(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvProfName",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InvProfName"),arg0);
  return OpmInvProfNameError;
}
static AntStatus OpmInvServerNameError(AntStatus::AntError,1426);
inline AntStatus
OpmErrInvServerName(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvServerName",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InvServerName"),arg0);
  return OpmInvServerNameError;
}
static AntStatus OpmInvAttributeError(AntStatus::AntError,1427);
inline AntStatus
OpmErrInvAttribute(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvAttribute",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InvAttribute"),arg0);
  return OpmInvAttributeError;
}
static AntStatus OpmNoDataError(AntStatus::AntError,1428);
inline AntStatus
OpmErrNoData(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoData",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","NoData"),arg0,arg1);
  return OpmNoDataError;
}
static AntStatus OpmNoFieldError(AntStatus::AntError,1429);
inline AntStatus
OpmErrNoField(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoField",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","NoField"),arg0,arg1);
  return OpmNoFieldError;
}
static AntStatus OpmNoDefinitionsError(AntStatus::AntError,1430);
inline AntStatus
OpmErrNoDefinitions(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoDefinitions",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","NoDefinitions"),arg0,arg1);
  return OpmNoDefinitionsError;
}
static AntStatus OpmNoProfilesError(AntStatus::AntError,1431);
inline AntStatus
OpmErrNoProfiles(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoProfiles",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","NoProfiles"),arg0,arg1);
  return OpmNoProfilesError;
}
static AntStatus OpmNoProfilesExitError(AntStatus::AntError,1432);
inline AntStatus
OpmErrNoProfilesExit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoProfilesExit",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","NoProfilesExit"));
  return OpmNoProfilesExitError;
}
static AntStatus OpmNoOperatorsExitError(AntStatus::AntError,1433);
inline AntStatus
OpmErrNoOperatorsExit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoOperatorsExit",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","NoOperatorsExit"));
  return OpmNoOperatorsExitError;
}
static AntStatus OpmProfNotLoadedError(AntStatus::AntError,1434);
inline AntStatus
OpmErrProfNotLoaded(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ProfNotLoaded",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","ProfNotLoaded"),arg0);
  return OpmProfNotLoadedError;
}
static AntStatus OpmProfAlreadyLoadedError(AntStatus::AntError,1435);
inline AntStatus
OpmErrProfAlreadyLoaded(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ProfAlreadyLoaded",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","ProfAlreadyLoaded"),arg0);
  return OpmProfAlreadyLoadedError;
}
static AntStatus OpmProfNotFoundError(AntStatus::AntError,1436);
inline AntStatus
OpmErrProfNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ProfNotFound",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","ProfNotFound"),arg0);
  return OpmProfNotFoundError;
}
static AntStatus OpmOperatorNotFoundError(AntStatus::AntError,1437);
inline AntStatus
OpmErrOperatorNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "OperatorNotFound",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","OperatorNotFound"),arg0);
  return OpmOperatorNotFoundError;
}
static AntStatus OpmPasswordNotValidError(AntStatus::AntError,1438);
inline AntStatus
OpmErrPasswordNotValid(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "PasswordNotValid",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","PasswordNotValid"),arg0);
  return OpmPasswordNotValidError;
}
static AntStatus OpmPasswordTooLongError(AntStatus::AntError,1439);
inline AntStatus
OpmErrPasswordTooLong(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "PasswordTooLong",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","PasswordTooLong"));
  return OpmPasswordTooLongError;
}
static AntStatus OpmPasswordTooShortError(AntStatus::AntError,1440);
inline AntStatus
OpmErrPasswordTooShort(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "PasswordTooShort",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","PasswordTooShort"),arg0);
  return OpmPasswordTooShortError;
}
static AntStatus OpmOperatorLockedError(AntStatus::AntError,1441);
inline AntStatus
OpmErrOperatorLocked(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "OperatorLocked",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","OperatorLocked"));
  return OpmOperatorLockedError;
}
static AntStatus OpmSyntaxErrorError(AntStatus::AntError,1442);
inline AntStatus
OpmErrSyntaxError(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1,const  char * arg2,const  char * arg3
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SyntaxError",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","SyntaxError"),arg0,arg1,arg2,arg3);
  return OpmSyntaxErrorError;
}
static AntStatus OpmListEmptyError(AntStatus::AntError,1443);
inline AntStatus
OpmErrListEmpty(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ListEmpty",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","ListEmpty"),arg0);
  return OpmListEmptyError;
}
static AntStatus OpmUnkTypeError(AntStatus::AntError,1444);
inline AntStatus
OpmErrUnkType(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnkType",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","UnkType"),arg0);
  return OpmUnkTypeError;
}
static AntStatus OpmInFunctionError(AntStatus::AntError,1445);
inline AntStatus
OpmErrInFunction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InFunction",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","InFunction"),arg0,arg1);
  return OpmInFunctionError;
}
static AntStatus OpmFileAccessError(AntStatus::AntError,1446);
inline AntStatus
OpmErrFileAccess(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FileAccess",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","FileAccess"),arg0,arg1);
  return OpmFileAccessError;
}
static AntStatus OpmInternalError(AntStatus::AntError,1447);
inline AntStatus
OpmErrInternal(AntErrorSeverity severity
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
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","Internal"),arg0);
  return OpmInternalError;
}
static AntStatus OpmTooMuchProfilesError(AntStatus::AntError,1448);
inline AntStatus
OpmErrTooMuchProfiles(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "TooMuchProfiles",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","TooMuchProfiles"),arg0,arg1);
  return OpmTooMuchProfilesError;
}
static AntStatus OpmOperatorAlreadyExistError(AntStatus::AntError,1449);
inline AntStatus
OpmErrOperatorAlreadyExist(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "OperatorAlreadyExist",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","OperatorAlreadyExist"),arg0);
  return OpmOperatorAlreadyExistError;
}
static AntStatus OpmOperatorIsNullError(AntStatus::AntError,1450);
inline AntStatus
OpmErrOperatorIsNull(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "OperatorIsNull",
              source,
              "Opm",
              AntTrace::trace().getErrorFormat("opmerror.emf","Opm","OperatorIsNull"));
  return OpmOperatorIsNullError;
}
inline const char *
OpmGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 1400:
    return "Init";
  case 1401:
    return "ORB";
  case 1402:
    return "ScadasoftInit";
  case 1403:
    return "ScadasoftFunction";
  case 1404:
    return "GetEnv";
  case 1405:
    return "OpenFile";
  case 1406:
    return "ParseFile";
  case 1407:
    return "LoadingSnapshot";
  case 1408:
    return "InitOlsServer";
  case 1409:
    return "Subscribe";
  case 1410:
    return "SubscribeRemote";
  case 1411:
    return "FieldCount";
  case 1412:
    return "SubscribeState";
  case 1413:
    return "Unsubscribe";
  case 1414:
    return "UpdateLocalBuffer";
  case 1415:
    return "InvStringMask";
  case 1416:
    return "InvStringFlag";
  case 1417:
    return "InvBitFieldMask";
  case 1418:
    return "InvEnvName";
  case 1419:
    return "InvFuncCategory";
  case 1420:
    return "InvFuncName";
  case 1421:
    return "InvLocCategory";
  case 1422:
    return "InvLocName";
  case 1423:
    return "InvActCategory";
  case 1424:
    return "InvActName";
  case 1425:
    return "InvProfName";
  case 1426:
    return "InvServerName";
  case 1427:
    return "InvAttribute";
  case 1428:
    return "NoData";
  case 1429:
    return "NoField";
  case 1430:
    return "NoDefinitions";
  case 1431:
    return "NoProfiles";
  case 1432:
    return "NoProfilesExit";
  case 1433:
    return "NoOperatorsExit";
  case 1434:
    return "ProfNotLoaded";
  case 1435:
    return "ProfAlreadyLoaded";
  case 1436:
    return "ProfNotFound";
  case 1437:
    return "OperatorNotFound";
  case 1438:
    return "PasswordNotValid";
  case 1439:
    return "PasswordTooLong";
  case 1440:
    return "PasswordTooShort";
  case 1441:
    return "OperatorLocked";
  case 1442:
    return "SyntaxError";
  case 1443:
    return "ListEmpty";
  case 1444:
    return "UnkType";
  case 1445:
    return "InFunction";
  case 1446:
    return "FileAccess";
  case 1447:
    return "Internal";
  case 1448:
    return "TooMuchProfiles";
  case 1449:
    return "OperatorAlreadyExist";
  case 1450:
    return "OperatorIsNull";
  default:
    return "";
  }
}
#endif
