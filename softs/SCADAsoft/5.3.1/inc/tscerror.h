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
#ifndef _AN_TSCERROR_H
#define _AN_TSCERROR_H
static AntStatus TscInitError(AntStatus::AntError,1600);
inline AntStatus
TscErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","Init"));
  return TscInitError;
}
static AntStatus TscORBError(AntStatus::AntError,1601);
inline AntStatus
TscErrORB(AntErrorSeverity severity
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
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","ORB"),arg0);
  return TscORBError;
}
static AntStatus TscNoServerError(AntStatus::AntError,1602);
inline AntStatus
TscErrNoServer(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoServer",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","NoServer"),arg0,arg1);
  return TscNoServerError;
}
static AntStatus TscAlmServerError(AntStatus::AntError,1603);
inline AntStatus
TscErrAlmServer(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AlmServer",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","AlmServer"),arg0);
  return TscAlmServerError;
}
static AntStatus TscInvalidError(AntStatus::AntError,1604);
inline AntStatus
TscErrInvalid(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Invalid",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","Invalid"));
  return TscInvalidError;
}
static AntStatus TscEmptyError(AntStatus::AntError,1605);
inline AntStatus
TscErrEmpty(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Empty",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","Empty"),arg0);
  return TscEmptyError;
}
static AntStatus TscBadDgDateFormatError(AntStatus::AntError,1606);
inline AntStatus
TscErrBadDgDateFormat(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadDgDateFormat",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","BadDgDateFormat"),arg0);
  return TscBadDgDateFormatError;
}
static AntStatus TscBadDateError(AntStatus::AntError,1607);
inline AntStatus
TscErrBadDate(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadDate",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","BadDate"),arg0);
  return TscBadDateError;
}
static AntStatus TscPastDateError(AntStatus::AntError,1608);
inline AntStatus
TscErrPastDate(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "PastDate",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","PastDate"),arg0);
  return TscPastDateError;
}
static AntStatus TscBadDgNameError(AntStatus::AntError,1609);
inline AntStatus
TscErrBadDgName(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadDgName",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","BadDgName"),arg0);
  return TscBadDgNameError;
}
static AntStatus TscBadDgIdError(AntStatus::AntError,1610);
inline AntStatus
TscErrBadDgId(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadDgId",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","BadDgId"),arg0);
  return TscBadDgIdError;
}
static AntStatus TscUnexpectedStatementError(AntStatus::AntError,1611);
inline AntStatus
TscErrUnexpectedStatement(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnexpectedStatement",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","UnexpectedStatement"),arg0);
  return TscUnexpectedStatementError;
}
static AntStatus TscBadTaskFormatError(AntStatus::AntError,1612);
inline AntStatus
TscErrBadTaskFormat(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadTaskFormat",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","BadTaskFormat"),arg0);
  return TscBadTaskFormatError;
}
static AntStatus TscBadTaskNameError(AntStatus::AntError,1613);
inline AntStatus
TscErrBadTaskName(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadTaskName",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","BadTaskName"),arg0);
  return TscBadTaskNameError;
}
static AntStatus TscBadCommandError(AntStatus::AntError,1614);
inline AntStatus
TscErrBadCommand(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadCommand",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","BadCommand"),arg0);
  return TscBadCommandError;
}
static AntStatus TscInvalidIntervalError(AntStatus::AntError,1615);
inline AntStatus
TscErrInvalidInterval(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidInterval",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","InvalidInterval"),arg0);
  return TscInvalidIntervalError;
}
static AntStatus TscInvalidLogError(AntStatus::AntError,1616);
inline AntStatus
TscErrInvalidLog(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidLog",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","InvalidLog"),arg0,arg1);
  return TscInvalidLogError;
}
static AntStatus TscInvalidStartError(AntStatus::AntError,1617);
inline AntStatus
TscErrInvalidStart(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidStart",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","InvalidStart"),arg0);
  return TscInvalidStartError;
}
static AntStatus TscInvalidEndError(AntStatus::AntError,1618);
inline AntStatus
TscErrInvalidEnd(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidEnd",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","InvalidEnd"),arg0);
  return TscInvalidEndError;
}
static AntStatus TscInvalidTaskError(AntStatus::AntError,1619);
inline AntStatus
TscErrInvalidTask(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidTask",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","InvalidTask"),arg0);
  return TscInvalidTaskError;
}
static AntStatus TscInvalidCommandError(AntStatus::AntError,1620);
inline AntStatus
TscErrInvalidCommand(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidCommand",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","InvalidCommand"),arg0);
  return TscInvalidCommandError;
}
static AntStatus TscBadFilterFormatError(AntStatus::AntError,1621);
inline AntStatus
TscErrBadFilterFormat(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadFilterFormat",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","BadFilterFormat"),arg0);
  return TscBadFilterFormatError;
}
static AntStatus TscBadFilterItemError(AntStatus::AntError,1622);
inline AntStatus
TscErrBadFilterItem(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadFilterItem",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","BadFilterItem"),arg0,arg1);
  return TscBadFilterItemError;
}
static AntStatus TscFileAccessError(AntStatus::AntError,1623);
inline AntStatus
TscErrFileAccess(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FileAccess",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","FileAccess"),arg0);
  return TscFileAccessError;
}
static AntStatus TscUnknownTaskError(AntStatus::AntError,1624);
inline AntStatus
TscErrUnknownTask(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownTask",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","UnknownTask"),arg0);
  return TscUnknownTaskError;
}
static AntStatus TscUnknownDayGroupError(AntStatus::AntError,1625);
inline AntStatus
TscErrUnknownDayGroup(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownDayGroup",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","UnknownDayGroup"),arg0);
  return TscUnknownDayGroupError;
}
static AntStatus TscInFunctionError(AntStatus::AntError,1626);
inline AntStatus
TscErrInFunction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InFunction",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","InFunction"),arg0);
  return TscInFunctionError;
}
static AntStatus TscInvalidInhibitedError(AntStatus::AntError,1627);
inline AntStatus
TscErrInvalidInhibited(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidInhibited",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","InvalidInhibited"),arg0,arg1);
  return TscInvalidInhibitedError;
}
static AntStatus TscExecutionFailedError(AntStatus::AntError,1628);
inline AntStatus
TscErrExecutionFailed(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ExecutionFailed",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","ExecutionFailed"),arg0,arg1);
  return TscExecutionFailedError;
}
static AntStatus TscTaskAlreadyExistError(AntStatus::AntError,1629);
inline AntStatus
TscErrTaskAlreadyExist(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "TaskAlreadyExist",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","TaskAlreadyExist"),arg0);
  return TscTaskAlreadyExistError;
}
static AntStatus TscBadArgumentTypeError(AntStatus::AntError,1630);
inline AntStatus
TscErrBadArgumentType(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadArgumentType",
              source,
              "Tsc",
              AntTrace::trace().getErrorFormat("tscerror.emf","Tsc","BadArgumentType"),arg0,arg1,arg2);
  return TscBadArgumentTypeError;
}
inline const char *
TscGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 1600:
    return "Init";
  case 1601:
    return "ORB";
  case 1602:
    return "NoServer";
  case 1603:
    return "AlmServer";
  case 1604:
    return "Invalid";
  case 1605:
    return "Empty";
  case 1606:
    return "BadDgDateFormat";
  case 1607:
    return "BadDate";
  case 1608:
    return "PastDate";
  case 1609:
    return "BadDgName";
  case 1610:
    return "BadDgId";
  case 1611:
    return "UnexpectedStatement";
  case 1612:
    return "BadTaskFormat";
  case 1613:
    return "BadTaskName";
  case 1614:
    return "BadCommand";
  case 1615:
    return "InvalidInterval";
  case 1616:
    return "InvalidLog";
  case 1617:
    return "InvalidStart";
  case 1618:
    return "InvalidEnd";
  case 1619:
    return "InvalidTask";
  case 1620:
    return "InvalidCommand";
  case 1621:
    return "BadFilterFormat";
  case 1622:
    return "BadFilterItem";
  case 1623:
    return "FileAccess";
  case 1624:
    return "UnknownTask";
  case 1625:
    return "UnknownDayGroup";
  case 1626:
    return "InFunction";
  case 1627:
    return "InvalidInhibited";
  case 1628:
    return "ExecutionFailed";
  case 1629:
    return "TaskAlreadyExist";
  case 1630:
    return "BadArgumentType";
  default:
    return "";
  }
}
#endif
