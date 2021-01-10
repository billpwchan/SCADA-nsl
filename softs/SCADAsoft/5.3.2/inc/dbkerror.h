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
!! at Mon Jun 06 11:06:19 2016
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
*/
#ifndef _AN_DBKERROR_H
#define _AN_DBKERROR_H
static AntStatus DbkORBError(AntStatus::AntError,2600);
inline AntStatus
DbkErrORB(AntErrorSeverity severity
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
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","ORB"),arg0);
  return DbkORBError;
}
static AntStatus DbkUnixError(AntStatus::AntError,2601);
inline AntStatus
DbkErrUnix(AntErrorSeverity severity
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
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","Unix"),arg0,arg1);
  return DbkUnixError;
}
static AntStatus DbkFormulaSyntaxError(AntStatus::AntError,2602);
inline AntStatus
DbkErrFormulaSyntax(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FormulaSyntax",
              source,
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","FormulaSyntax"),arg0);
  return DbkFormulaSyntaxError;
}
static AntStatus DbkAddressIdError(AntStatus::AntError,2603);
inline AntStatus
DbkErrAddressId(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AddressId",
              source,
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","AddressId"),arg0);
  return DbkAddressIdError;
}
static AntStatus DbkDtdAbsentError(AntStatus::AntError,2604);
inline AntStatus
DbkErrDtdAbsent(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DtdAbsent",
              source,
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","DtdAbsent"),arg0);
  return DbkDtdAbsentError;
}
static AntStatus DbkFatherUnknownError(AntStatus::AntError,2605);
inline AntStatus
DbkErrFatherUnknown(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FatherUnknown",
              source,
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","FatherUnknown"),arg0);
  return DbkFatherUnknownError;
}
static AntStatus DbkAliasAlreadyExistError(AntStatus::AntError,2606);
inline AntStatus
DbkErrAliasAlreadyExist(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AliasAlreadyExist",
              source,
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","AliasAlreadyExist"),arg0);
  return DbkAliasAlreadyExistError;
}
static AntStatus DbkNameAlreadyExistError(AntStatus::AntError,2607);
inline AntStatus
DbkErrNameAlreadyExist(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NameAlreadyExist",
              source,
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","NameAlreadyExist"),arg0);
  return DbkNameAlreadyExistError;
}
static AntStatus DbkPointUnknownError(AntStatus::AntError,2608);
inline AntStatus
DbkErrPointUnknown(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "PointUnknown",
              source,
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","PointUnknown"),arg0);
  return DbkPointUnknownError;
}
static AntStatus DbkPathCreationError(AntStatus::AntError,2609);
inline AntStatus
DbkErrPathCreation(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "PathCreation",
              source,
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","PathCreation"),arg0);
  return DbkPathCreationError;
}
static AntStatus DbkFileOpenError(AntStatus::AntError,2610);
inline AntStatus
DbkErrFileOpen(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FileOpen",
              source,
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","FileOpen"),arg0);
  return DbkFileOpenError;
}
static AntStatus DbkWrongArgNumberError(AntStatus::AntError,2611);
inline AntStatus
DbkErrWrongArgNumber(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WrongArgNumber",
              source,
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","WrongArgNumber"),arg0,arg1,arg2);
  return DbkWrongArgNumberError;
}
static AntStatus DbkWrongArgTypeError(AntStatus::AntError,2612);
inline AntStatus
DbkErrWrongArgType(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1,const  char * arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WrongArgType",
              source,
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","WrongArgType"),arg0,arg1,arg2);
  return DbkWrongArgTypeError;
}
static AntStatus DbkCannotEvaluateArgError(AntStatus::AntError,2613);
inline AntStatus
DbkErrCannotEvaluateArg(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CannotEvaluateArg",
              source,
              "Dbk",
              AntTrace::trace().getErrorFormat("dbkerror.emf","Dbk","CannotEvaluateArg"),arg0,arg1);
  return DbkCannotEvaluateArgError;
}
inline const char *
DbkGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 2600:
    return "ORB";
  case 2601:
    return "Unix";
  case 2602:
    return "FormulaSyntax";
  case 2603:
    return "AddressId";
  case 2604:
    return "DtdAbsent";
  case 2605:
    return "FatherUnknown";
  case 2606:
    return "AliasAlreadyExist";
  case 2607:
    return "NameAlreadyExist";
  case 2608:
    return "PointUnknown";
  case 2609:
    return "PathCreation";
  case 2610:
    return "FileOpen";
  case 2611:
    return "WrongArgNumber";
  case 2612:
    return "WrongArgType";
  case 2613:
    return "CannotEvaluateArg";
  default:
    return "";
  }
}
#endif
