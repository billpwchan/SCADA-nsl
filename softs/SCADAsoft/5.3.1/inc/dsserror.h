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
#ifndef _AN_DSSERROR_H
#define _AN_DSSERROR_H
static AntStatus DssInitError(AntStatus::AntError,1700);
inline AntStatus
DssErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","Init"));
  return DssInitError;
}
static AntStatus DssORBError(AntStatus::AntError,1701);
inline AntStatus
DssErrORB(AntErrorSeverity severity
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
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","ORB"),arg0);
  return DssORBError;
}
static AntStatus DssHostServerError(AntStatus::AntError,1702);
inline AntStatus
DssErrHostServer(AntErrorSeverity severity
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
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","HostServer"),arg0);
  return DssHostServerError;
}
static AntStatus DssNoServerError(AntStatus::AntError,1703);
inline AntStatus
DssErrNoServer(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoServer",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","NoServer"),arg0);
  return DssNoServerError;
}
static AntStatus DssNoScenarioPointError(AntStatus::AntError,1704);
inline AntStatus
DssErrNoScenarioPoint(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoScenarioPoint",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","NoScenarioPoint"));
  return DssNoScenarioPointError;
}
static AntStatus DssNoScenarioError(AntStatus::AntError,1705);
inline AntStatus
DssErrNoScenario(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoScenario",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","NoScenario"));
  return DssNoScenarioError;
}
static AntStatus DssUnknownEventTypeError(AntStatus::AntError,1706);
inline AntStatus
DssErrUnknownEventType(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownEventType",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","UnknownEventType"),arg0);
  return DssUnknownEventTypeError;
}
static AntStatus DssUnknownEventIdError(AntStatus::AntError,1707);
inline AntStatus
DssErrUnknownEventId(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownEventId",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","UnknownEventId"),arg0,arg1);
  return DssUnknownEventIdError;
}
static AntStatus DssUnknownScenarioIdError(AntStatus::AntError,1708);
inline AntStatus
DssErrUnknownScenarioId(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownScenarioId",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","UnknownScenarioId"),arg0,arg1);
  return DssUnknownScenarioIdError;
}
static AntStatus DssUnknownProcedureNameError(AntStatus::AntError,1709);
inline AntStatus
DssErrUnknownProcedureName(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownProcedureName",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","UnknownProcedureName"),arg0);
  return DssUnknownProcedureNameError;
}
static AntStatus DssNoMoreFreeScenarioError(AntStatus::AntError,1710);
inline AntStatus
DssErrNoMoreFreeScenario(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoMoreFreeScenario",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","NoMoreFreeScenario"),arg0);
  return DssNoMoreFreeScenarioError;
}
static AntStatus DssListActionError(AntStatus::AntError,1711);
inline AntStatus
DssErrListAction(AntErrorSeverity severity
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
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","ListAction"),arg0);
  return DssListActionError;
}
static AntStatus DssUnknownArgumentError(AntStatus::AntError,1712);
inline AntStatus
DssErrUnknownArgument(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownArgument",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","UnknownArgument"),arg0);
  return DssUnknownArgumentError;
}
static AntStatus DssDatabaseWriteError(AntStatus::AntError,1713);
inline AntStatus
DssErrDatabaseWrite(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DatabaseWrite",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","DatabaseWrite"),arg0);
  return DssDatabaseWriteError;
}
static AntStatus DssUnknownAlarmIdError(AntStatus::AntError,1714);
inline AntStatus
DssErrUnknownAlarmId(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownAlarmId",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","UnknownAlarmId"),arg0,arg1);
  return DssUnknownAlarmIdError;
}
static AntStatus DssScenarioNotLockedError(AntStatus::AntError,1715);
inline AntStatus
DssErrScenarioNotLocked(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ScenarioNotLocked",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","ScenarioNotLocked"),arg0,arg1);
  return DssScenarioNotLockedError;
}
static AntStatus DssScenarioAlreadyLockedError(AntStatus::AntError,1716);
inline AntStatus
DssErrScenarioAlreadyLocked(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ScenarioAlreadyLocked",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","ScenarioAlreadyLocked"),arg0,arg1);
  return DssScenarioAlreadyLockedError;
}
static AntStatus DssNoDssEventError(AntStatus::AntError,1717);
inline AntStatus
DssErrNoDssEvent(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoDssEvent",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","NoDssEvent"),arg0);
  return DssNoDssEventError;
}
static AntStatus DssDssEventIsRunningError(AntStatus::AntError,1718);
inline AntStatus
DssErrDssEventIsRunning(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DssEventIsRunning",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","DssEventIsRunning"),arg0);
  return DssDssEventIsRunningError;
}
static AntStatus DssUnknownDssEventIdError(AntStatus::AntError,1719);
inline AntStatus
DssErrUnknownDssEventId(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownDssEventId",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","UnknownDssEventId"),arg0);
  return DssUnknownDssEventIdError;
}
static AntStatus DssBadResourceFileError(AntStatus::AntError,1720);
inline AntStatus
DssErrBadResourceFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadResourceFile",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","BadResourceFile"),arg0);
  return DssBadResourceFileError;
}
static AntStatus DssNoFatherScenarioError(AntStatus::AntError,1721);
inline AntStatus
DssErrNoFatherScenario(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoFatherScenario",
              source,
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","NoFatherScenario"),arg0);
  return DssNoFatherScenarioError;
}
static AntStatus DssScadasoftFunctionError(AntStatus::AntError,1722);
inline AntStatus
DssErrScadasoftFunction(AntErrorSeverity severity
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
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","ScadasoftFunction"),arg0,arg1);
  return DssScadasoftFunctionError;
}
static AntStatus DssInternalError(AntStatus::AntError,1723);
inline AntStatus
DssErrInternal(AntErrorSeverity severity
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
              "Dss",
              AntTrace::trace().getErrorFormat("dsserror.emf","Dss","Internal"),arg0);
  return DssInternalError;
}
inline const char *
DssGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 1700:
    return "Init";
  case 1701:
    return "ORB";
  case 1702:
    return "HostServer";
  case 1703:
    return "NoServer";
  case 1704:
    return "NoScenarioPoint";
  case 1705:
    return "NoScenario";
  case 1706:
    return "UnknownEventType";
  case 1707:
    return "UnknownEventId";
  case 1708:
    return "UnknownScenarioId";
  case 1709:
    return "UnknownProcedureName";
  case 1710:
    return "NoMoreFreeScenario";
  case 1711:
    return "ListAction";
  case 1712:
    return "UnknownArgument";
  case 1713:
    return "DatabaseWrite";
  case 1714:
    return "UnknownAlarmId";
  case 1715:
    return "ScenarioNotLocked";
  case 1716:
    return "ScenarioAlreadyLocked";
  case 1717:
    return "NoDssEvent";
  case 1718:
    return "DssEventIsRunning";
  case 1719:
    return "UnknownDssEventId";
  case 1720:
    return "BadResourceFile";
  case 1721:
    return "NoFatherScenario";
  case 1722:
    return "ScadasoftFunction";
  case 1723:
    return "Internal";
  default:
    return "";
  }
}
#endif
