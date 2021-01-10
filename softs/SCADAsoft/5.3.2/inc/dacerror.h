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
#ifndef _AN_DACERROR_H
#define _AN_DACERROR_H
static AntStatus DacInitError(AntStatus::AntError,1000);
inline AntStatus
DacErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","Init"));
  return DacInitError;
}
static AntStatus DacORBError(AntStatus::AntError,1001);
inline AntStatus
DacErrORB(AntErrorSeverity severity
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
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","ORB"),arg0);
  return DacORBError;
}
static AntStatus DacFileNotFoundError(AntStatus::AntError,1002);
inline AntStatus
DacErrFileNotFound(AntErrorSeverity severity
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
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","FileNotFound"),arg0);
  return DacFileNotFoundError;
}
static AntStatus DacFileAlreadyOpenError(AntStatus::AntError,1003);
inline AntStatus
DacErrFileAlreadyOpen(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FileAlreadyOpen",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","FileAlreadyOpen"),arg0);
  return DacFileAlreadyOpenError;
}
static AntStatus DacFileAlreadyClosedError(AntStatus::AntError,1004);
inline AntStatus
DacErrFileAlreadyClosed(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FileAlreadyClosed",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","FileAlreadyClosed"),arg0);
  return DacFileAlreadyClosedError;
}
static AntStatus DacShallOpenFileError(AntStatus::AntError,1005);
inline AntStatus
DacErrShallOpenFile(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ShallOpenFile",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","ShallOpenFile"),arg0);
  return DacShallOpenFileError;
}
static AntStatus DacVarEnvError(AntStatus::AntError,1006);
inline AntStatus
DacErrVarEnv(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "VarEnv",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","VarEnv"),arg0);
  return DacVarEnvError;
}
static AntStatus DacEmptyNameFromEnvVarError(AntStatus::AntError,1007);
inline AntStatus
DacErrEmptyNameFromEnvVar(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "EmptyNameFromEnvVar",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","EmptyNameFromEnvVar"),arg0);
  return DacEmptyNameFromEnvVarError;
}
static AntStatus DacParseError(AntStatus::AntError,1008);
inline AntStatus
DacErrParse(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Parse",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","Parse"),arg0);
  return DacParseError;
}
static AntStatus DacComDeviceListError(AntStatus::AntError,1009);
inline AntStatus
DacErrComDeviceList(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ComDeviceList",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","ComDeviceList"),arg0,arg1);
  return DacComDeviceListError;
}
static AntStatus DacDeviceAlreadyDefinedError(AntStatus::AntError,1010);
inline AntStatus
DacErrDeviceAlreadyDefined(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DeviceAlreadyDefined",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","DeviceAlreadyDefined"),arg0);
  return DacDeviceAlreadyDefinedError;
}
static AntStatus DacDeviceAlreadyConfiguredError(AntStatus::AntError,1011);
inline AntStatus
DacErrDeviceAlreadyConfigured(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DeviceAlreadyConfigured",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","DeviceAlreadyConfigured"),arg0);
  return DacDeviceAlreadyConfiguredError;
}
static AntStatus DacVariableAlreadyDefinedError(AntStatus::AntError,1012);
inline AntStatus
DacErrVariableAlreadyDefined(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "VariableAlreadyDefined",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","VariableAlreadyDefined"),arg0,arg1);
  return DacVariableAlreadyDefinedError;
}
static AntStatus DacLinkAlreadyDefinedError(AntStatus::AntError,1013);
inline AntStatus
DacErrLinkAlreadyDefined(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "LinkAlreadyDefined",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","LinkAlreadyDefined"),arg0,arg1);
  return DacLinkAlreadyDefinedError;
}
static AntStatus DacAddListError(AntStatus::AntError,1014);
inline AntStatus
DacErrAddList(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AddList",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","AddList"),arg0,arg1);
  return DacAddListError;
}
static AntStatus DacFindListError(AntStatus::AntError,1015);
inline AntStatus
DacErrFindList(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FindList",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","FindList"),arg0,arg1);
  return DacFindListError;
}
static AntStatus DacRemoveListError(AntStatus::AntError,1016);
inline AntStatus
DacErrRemoveList(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RemoveList",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","RemoveList"),arg0,arg1);
  return DacRemoveListError;
}
static AntStatus DacRemoveIntListError(AntStatus::AntError,1017);
inline AntStatus
DacErrRemoveIntList(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "RemoveIntList",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","RemoveIntList"),arg0,arg1);
  return DacRemoveIntListError;
}
static AntStatus DacDeviceNotFoundError(AntStatus::AntError,1018);
inline AntStatus
DacErrDeviceNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DeviceNotFound",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","DeviceNotFound"),arg0);
  return DacDeviceNotFoundError;
}
static AntStatus DacUndefinedDeviceError(AntStatus::AntError,1019);
inline AntStatus
DacErrUndefinedDevice(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UndefinedDevice",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","UndefinedDevice"),arg0);
  return DacUndefinedDeviceError;
}
static AntStatus DacVariableNotFoundError(AntStatus::AntError,1020);
inline AntStatus
DacErrVariableNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "VariableNotFound",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","VariableNotFound"),arg0,arg1);
  return DacVariableNotFoundError;
}
static AntStatus DacProcessNotFoundError(AntStatus::AntError,1021);
inline AntStatus
DacErrProcessNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ProcessNotFound",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","ProcessNotFound"),arg0,arg1);
  return DacProcessNotFoundError;
}
static AntStatus DacInFunctionError(AntStatus::AntError,1022);
inline AntStatus
DacErrInFunction(AntErrorSeverity severity
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
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","InFunction"),arg0);
  return DacInFunctionError;
}
static AntStatus DacUnknownTypeError(AntStatus::AntError,1023);
inline AntStatus
DacErrUnknownType(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "UnknownType",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","UnknownType"),arg0);
  return DacUnknownTypeError;
}
static AntStatus DacBadTypeError(AntStatus::AntError,1024);
inline AntStatus
DacErrBadType(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1,const  char * arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadType",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","BadType"),arg0,arg1,arg2);
  return DacBadTypeError;
}
static AntStatus DacIncompatibleTypeError(AntStatus::AntError,1025);
inline AntStatus
DacErrIncompatibleType(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "IncompatibleType",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","IncompatibleType"),arg0,arg1);
  return DacIncompatibleTypeError;
}
static AntStatus DacNoStateEivError(AntStatus::AntError,1026);
inline AntStatus
DacErrNoStateEiv(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoStateEiv",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","NoStateEiv"),arg0);
  return DacNoStateEivError;
}
static AntStatus DacNoSpyEivError(AntStatus::AntError,1027);
inline AntStatus
DacErrNoSpyEiv(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoSpyEiv",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","NoSpyEiv"),arg0);
  return DacNoSpyEivError;
}
static AntStatus DacNoLinkEivError(AntStatus::AntError,1028);
inline AntStatus
DacErrNoLinkEiv(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoLinkEiv",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","NoLinkEiv"),arg0);
  return DacNoLinkEivError;
}
static AntStatus DacBadValueError(AntStatus::AntError,1029);
inline AntStatus
DacErrBadValue(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0,const  char * arg1,const  char * arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadValue",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","BadValue"),arg0,arg1,arg2);
  return DacBadValueError;
}
static AntStatus DacBadAddressError(AntStatus::AntError,1030);
inline AntStatus
DacErrBadAddress(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "BadAddress",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","BadAddress"),arg0,arg1);
  return DacBadAddressError;
}
static AntStatus DacConnectError(AntStatus::AntError,1031);
inline AntStatus
DacErrConnect(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Connect",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","Connect"),arg0);
  return DacConnectError;
}
static AntStatus DacClientConnectError(AntStatus::AntError,1032);
inline AntStatus
DacErrClientConnect(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1, int  arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ClientConnect",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","ClientConnect"),arg0,arg1,arg2);
  return DacClientConnectError;
}
static AntStatus DacReadFileDescriptorError(AntStatus::AntError,1033);
inline AntStatus
DacErrReadFileDescriptor(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ReadFileDescriptor",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","ReadFileDescriptor"),arg0);
  return DacReadFileDescriptorError;
}
static AntStatus DacFileDescriptorError(AntStatus::AntError,1034);
inline AntStatus
DacErrFileDescriptor(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "FileDescriptor",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","FileDescriptor"),arg0);
  return DacFileDescriptorError;
}
static AntStatus DacCloseFileDescriptorError(AntStatus::AntError,1035);
inline AntStatus
DacErrCloseFileDescriptor(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CloseFileDescriptor",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","CloseFileDescriptor"),arg0);
  return DacCloseFileDescriptorError;
}
static AntStatus DacAcknowledgeError(AntStatus::AntError,1036);
inline AntStatus
DacErrAcknowledge(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Acknowledge",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","Acknowledge"));
  return DacAcknowledgeError;
}
static AntStatus DacWrongAckError(AntStatus::AntError,1037);
inline AntStatus
DacErrWrongAck(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WrongAck",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","WrongAck"));
  return DacWrongAckError;
}
static AntStatus DacAckReceivedError(AntStatus::AntError,1038);
inline AntStatus
DacErrAckReceived(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AckReceived",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","AckReceived"));
  return DacAckReceivedError;
}
static AntStatus DacAckMissingError(AntStatus::AntError,1039);
inline AntStatus
DacErrAckMissing(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AckMissing",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","AckMissing"),arg0);
  return DacAckMissingError;
}
static AntStatus DacCutMessageError(AntStatus::AntError,1040);
inline AntStatus
DacErrCutMessage(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CutMessage",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","CutMessage"));
  return DacCutMessageError;
}
static AntStatus DacNoConnectedError(AntStatus::AntError,1041);
inline AntStatus
DacErrNoConnected(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoConnected",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","NoConnected"));
  return DacNoConnectedError;
}
static AntStatus DacNoComLineError(AntStatus::AntError,1042);
inline AntStatus
DacErrNoComLine(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoComLine",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","NoComLine"));
  return DacNoComLineError;
}
static AntStatus DacDownloadDisableError(AntStatus::AntError,1043);
inline AntStatus
DacErrDownloadDisable(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DownloadDisable",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","DownloadDisable"));
  return DacDownloadDisableError;
}
static AntStatus DacConnectionCoherenceError(AntStatus::AntError,1044);
inline AntStatus
DacErrConnectionCoherence(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ConnectionCoherence",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","ConnectionCoherence"),arg0);
  return DacConnectionCoherenceError;
}
static AntStatus DacCommLineError(AntStatus::AntError,1045);
inline AntStatus
DacErrCommLine(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CommLine",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","CommLine"),arg0,arg1);
  return DacCommLineError;
}
static AntStatus DacNoBufferError(AntStatus::AntError,1046);
inline AntStatus
DacErrNoBuffer(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoBuffer",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","NoBuffer"),arg0);
  return DacNoBufferError;
}
static AntStatus DacNoDacComLaunchedError(AntStatus::AntError,1047);
inline AntStatus
DacErrNoDacComLaunched(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoDacComLaunched",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","NoDacComLaunched"),arg0);
  return DacNoDacComLaunchedError;
}
static AntStatus DacNoForkError(AntStatus::AntError,1048);
inline AntStatus
DacErrNoFork(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoFork",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","NoFork"));
  return DacNoForkError;
}
static AntStatus DacCreatingSocketError(AntStatus::AntError,1049);
inline AntStatus
DacErrCreatingSocket(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CreatingSocket",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","CreatingSocket"));
  return DacCreatingSocketError;
}
static AntStatus DacCommunicationError(AntStatus::AntError,1050);
inline AntStatus
DacErrCommunication(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Communication",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","Communication"),arg0,arg1);
  return DacCommunicationError;
}
static AntStatus DacAlreadyConnectedError(AntStatus::AntError,1051);
inline AntStatus
DacErrAlreadyConnected(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AlreadyConnected",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","AlreadyConnected"),arg0);
  return DacAlreadyConnectedError;
}
static AntStatus DacInvalidatingVariableError(AntStatus::AntError,1052);
inline AntStatus
DacErrInvalidatingVariable(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "InvalidatingVariable",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","InvalidatingVariable"),arg0);
  return DacInvalidatingVariableError;
}
static AntStatus DacSubscribeError(AntStatus::AntError,1053);
inline AntStatus
DacErrSubscribe(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Subscribe",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","Subscribe"),arg0);
  return DacSubscribeError;
}
static AntStatus DacNotificationError(AntStatus::AntError,1054);
inline AntStatus
DacErrNotification(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Notification",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","Notification"),arg0);
  return DacNotificationError;
}
static AntStatus DacNoNotificationError(AntStatus::AntError,1055);
inline AntStatus
DacErrNoNotification(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NoNotification",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","NoNotification"));
  return DacNoNotificationError;
}
static AntStatus DacAppliFunctionError(AntStatus::AntError,1056);
inline AntStatus
DacErrAppliFunction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1,const  char * arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AppliFunction",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","AppliFunction"),arg0,arg1,arg2);
  return DacAppliFunctionError;
}
static AntStatus DacParametersError(AntStatus::AntError,1057);
inline AntStatus
DacErrParameters(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Parameters",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","Parameters"),arg0,arg1);
  return DacParametersError;
}
static AntStatus DacTypeParametersError(AntStatus::AntError,1058);
inline AntStatus
DacErrTypeParameters(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1,const  char * arg2
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "TypeParameters",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","TypeParameters"),arg0,arg1,arg2);
  return DacTypeParametersError;
}
static AntStatus DacCheckFunctionError(AntStatus::AntError,1059);
inline AntStatus
DacErrCheckFunction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CheckFunction",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","CheckFunction"),arg0,arg1);
  return DacCheckFunctionError;
}
static AntStatus DacTransfoFunctionError(AntStatus::AntError,1060);
inline AntStatus
DacErrTransfoFunction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "TransfoFunction",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","TransfoFunction"),arg0,arg1);
  return DacTransfoFunctionError;
}
static AntStatus DacSimServerError(AntStatus::AntError,1061);
inline AntStatus
DacErrSimServer(AntErrorSeverity severity
      ,short line, const char* file
      , int  arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SimServer",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","SimServer"),arg0,arg1);
  return DacSimServerError;
}
static AntStatus DacSimNoNotifCbError(AntStatus::AntError,1062);
inline AntStatus
DacErrSimNoNotifCb(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SimNoNotifCb",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","SimNoNotifCb"));
  return DacSimNoNotifCbError;
}
static AntStatus DacSimSubscrLockError(AntStatus::AntError,1063);
inline AntStatus
DacErrSimSubscrLock(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SimSubscrLock",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","SimSubscrLock"));
  return DacSimSubscrLockError;
}
static AntStatus DacSimBadSpecLineError(AntStatus::AntError,1064);
inline AntStatus
DacErrSimBadSpecLine(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SimBadSpecLine",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","SimBadSpecLine"),arg0,arg1);
  return DacSimBadSpecLineError;
}
static AntStatus DacSimAppendSpecError(AntStatus::AntError,1065);
inline AntStatus
DacErrSimAppendSpec(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SimAppendSpec",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","SimAppendSpec"));
  return DacSimAppendSpecError;
}
static AntStatus DacSimMatchSpecError(AntStatus::AntError,1066);
inline AntStatus
DacErrSimMatchSpec(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SimMatchSpec",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","SimMatchSpec"),arg0);
  return DacSimMatchSpecError;
}
static AntStatus DacSimVarNotFoundError(AntStatus::AntError,1067);
inline AntStatus
DacErrSimVarNotFound(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SimVarNotFound",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","SimVarNotFound"),arg0);
  return DacSimVarNotFoundError;
}
static AntStatus DacMaxReachedError(AntStatus::AntError,1068);
inline AntStatus
DacErrMaxReached(AntErrorSeverity severity
      ,short line, const char* file
      , long  arg0,const  char * arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MaxReached",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","MaxReached"),arg0,arg1);
  return DacMaxReachedError;
}
static AntStatus DacGenericError(AntStatus::AntError,1069);
inline AntStatus
DacErrGeneric(AntErrorSeverity severity
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
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","Generic"),arg0);
  return DacGenericError;
}
static AntStatus DacImplementationError(AntStatus::AntError,1070);
inline AntStatus
DacErrImplementation(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Implementation",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","Implementation"),arg0);
  return DacImplementationError;
}
static AntStatus DacCallbackError(AntStatus::AntError,1071);
inline AntStatus
DacErrCallback(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Callback",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","Callback"));
  return DacCallbackError;
}
static AntStatus DacDisConnectError(AntStatus::AntError,1072);
inline AntStatus
DacErrDisConnect(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "DisConnect",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","DisConnect"),arg0);
  return DacDisConnectError;
}
static AntStatus DacThreadStartFailedError(AntStatus::AntError,1073);
inline AntStatus
DacErrThreadStartFailed(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ThreadStartFailed",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","ThreadStartFailed"));
  return DacThreadStartFailedError;
}
static AntStatus DacThreadStopFailedError(AntStatus::AntError,1074);
inline AntStatus
DacErrThreadStopFailed(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ThreadStopFailed",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","ThreadStopFailed"));
  return DacThreadStopFailedError;
}
static AntStatus DacThreadPostFailedError(AntStatus::AntError,1075);
inline AntStatus
DacErrThreadPostFailed(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "ThreadPostFailed",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","ThreadPostFailed"));
  return DacThreadPostFailedError;
}
static AntStatus DacCommunicationFailedError(AntStatus::AntError,1076);
inline AntStatus
DacErrCommunicationFailed(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "CommunicationFailed",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","CommunicationFailed"),arg0);
  return DacCommunicationFailedError;
}
static AntStatus DacWdgFailedError(AntStatus::AntError,1077);
inline AntStatus
DacErrWdgFailed(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "WdgFailed",
              source,
              "DAC",
              AntTrace::trace().getErrorFormat("dacerror.emf","Dac","WdgFailed"),arg0,arg1);
  return DacWdgFailedError;
}
inline const char *
DacGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 1000:
    return "Init";
  case 1001:
    return "ORB";
  case 1002:
    return "FileNotFound";
  case 1003:
    return "FileAlreadyOpen";
  case 1004:
    return "FileAlreadyClosed";
  case 1005:
    return "ShallOpenFile";
  case 1006:
    return "VarEnv";
  case 1007:
    return "EmptyNameFromEnvVar";
  case 1008:
    return "Parse";
  case 1009:
    return "ComDeviceList";
  case 1010:
    return "DeviceAlreadyDefined";
  case 1011:
    return "DeviceAlreadyConfigured";
  case 1012:
    return "VariableAlreadyDefined";
  case 1013:
    return "LinkAlreadyDefined";
  case 1014:
    return "AddList";
  case 1015:
    return "FindList";
  case 1016:
    return "RemoveList";
  case 1017:
    return "RemoveIntList";
  case 1018:
    return "DeviceNotFound";
  case 1019:
    return "UndefinedDevice";
  case 1020:
    return "VariableNotFound";
  case 1021:
    return "ProcessNotFound";
  case 1022:
    return "InFunction";
  case 1023:
    return "UnknownType";
  case 1024:
    return "BadType";
  case 1025:
    return "IncompatibleType";
  case 1026:
    return "NoStateEiv";
  case 1027:
    return "NoSpyEiv";
  case 1028:
    return "NoLinkEiv";
  case 1029:
    return "BadValue";
  case 1030:
    return "BadAddress";
  case 1031:
    return "Connect";
  case 1032:
    return "ClientConnect";
  case 1033:
    return "ReadFileDescriptor";
  case 1034:
    return "FileDescriptor";
  case 1035:
    return "CloseFileDescriptor";
  case 1036:
    return "Acknowledge";
  case 1037:
    return "WrongAck";
  case 1038:
    return "AckReceived";
  case 1039:
    return "AckMissing";
  case 1040:
    return "CutMessage";
  case 1041:
    return "NoConnected";
  case 1042:
    return "NoComLine";
  case 1043:
    return "DownloadDisable";
  case 1044:
    return "ConnectionCoherence";
  case 1045:
    return "CommLine";
  case 1046:
    return "NoBuffer";
  case 1047:
    return "NoDacComLaunched";
  case 1048:
    return "NoFork";
  case 1049:
    return "CreatingSocket";
  case 1050:
    return "Communication";
  case 1051:
    return "AlreadyConnected";
  case 1052:
    return "InvalidatingVariable";
  case 1053:
    return "Subscribe";
  case 1054:
    return "Notification";
  case 1055:
    return "NoNotification";
  case 1056:
    return "AppliFunction";
  case 1057:
    return "Parameters";
  case 1058:
    return "TypeParameters";
  case 1059:
    return "CheckFunction";
  case 1060:
    return "TransfoFunction";
  case 1061:
    return "SimServer";
  case 1062:
    return "SimNoNotifCb";
  case 1063:
    return "SimSubscrLock";
  case 1064:
    return "SimBadSpecLine";
  case 1065:
    return "SimAppendSpec";
  case 1066:
    return "SimMatchSpec";
  case 1067:
    return "SimVarNotFound";
  case 1068:
    return "MaxReached";
  case 1069:
    return "Generic";
  case 1070:
    return "Implementation";
  case 1071:
    return "Callback";
  case 1072:
    return "DisConnect";
  case 1073:
    return "ThreadStartFailed";
  case 1074:
    return "ThreadStopFailed";
  case 1075:
    return "ThreadPostFailed";
  case 1076:
    return "CommunicationFailed";
  case 1077:
    return "WdgFailed";
  default:
    return "";
  }
}
#endif
