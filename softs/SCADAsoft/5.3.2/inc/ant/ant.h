/*
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
!! File automatically generated
!! by ..\msvc5\antools\mkerror\stat_st\Debug\mkerror.exe
!! at Mon Nov 23 12:01:29 1998
!!!!!!!!!! DO NOT EDIT !!!!!!!!!!
*/
#ifndef _AN_ANT_H
#define _AN_ANT_H
static AntStatus AntBadMessageFileLocationError(AntStatus::AntError,0);
inline AntStatus
AntErrBadMessageFileLocation(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadMessageFileLocation",
              source,
              "antools",
              AntTrace::trace().getErrorFormat("ant.emf","Ant","BadMessageFileLocation"),arg0);
  return AntBadMessageFileLocationError;
}
static AntStatus AntIncoherentFormatError(AntStatus::AntError,1);
inline AntStatus
AntErrIncoherentFormat(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "IncoherentFormat",
              source,
              "antools",
              AntTrace::trace().getErrorFormat("ant.emf","Ant","IncoherentFormat"),arg0);
  return AntIncoherentFormatError;
}
static AntStatus AntUncheckedFormatError(AntStatus::AntError,2);
inline AntStatus
AntErrUncheckedFormat(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UncheckedFormat",
              source,
              "antools",
              AntTrace::trace().getErrorFormat("ant.emf","Ant","UncheckedFormat"),arg0);
  return AntUncheckedFormatError;
}
#endif
