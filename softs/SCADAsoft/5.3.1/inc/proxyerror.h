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
#ifndef _AN_PROXYERROR_H
#define _AN_PROXYERROR_H
static AntStatus ProxyInitError(AntStatus::AntError,2000);
inline AntStatus
ProxyErrInit(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Init",
              source,
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","Init"));
  return ProxyInitError;
}
static AntStatus ProxyExceptionError(AntStatus::AntError,2001);
inline AntStatus
ProxyErrException(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Exception",
              source,
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","Exception"),arg0);
  return ProxyExceptionError;
}
static AntStatus ProxyORBError(AntStatus::AntError,2002);
inline AntStatus
ProxyErrORB(AntErrorSeverity severity
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
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","ORB"),arg0);
  return ProxyORBError;
}
static AntStatus ProxyHostServerError(AntStatus::AntError,2003);
inline AntStatus
ProxyErrHostServer(AntErrorSeverity severity
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
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","HostServer"),arg0);
  return ProxyHostServerError;
}
static AntStatus ProxyServerNotRegisteredError(AntStatus::AntError,2004);
inline AntStatus
ProxyErrServerNotRegistered(AntErrorSeverity severity
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
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","ServerNotRegistered"),arg0);
  return ProxyServerNotRegisteredError;
}
static AntStatus ProxyScadasoftFunctionError(AntStatus::AntError,2005);
inline AntStatus
ProxyErrScadasoftFunction(AntErrorSeverity severity
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
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","ScadasoftFunction"),arg0,arg1);
  return ProxyScadasoftFunctionError;
}
static AntStatus ProxyAppliFunctionError(AntStatus::AntError,2006);
inline AntStatus
ProxyErrAppliFunction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0, int  arg1
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "AppliFunction",
              source,
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","AppliFunction"),arg0,arg1);
  return ProxyAppliFunctionError;
}
static AntStatus ProxySystemFunctionError(AntStatus::AntError,2007);
inline AntStatus
ProxyErrSystemFunction(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "SystemFunction",
              source,
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","SystemFunction"),arg0);
  return ProxySystemFunctionError;
}
static AntStatus ProxyEnvironmentError(AntStatus::AntError,2008);
inline AntStatus
ProxyErrEnvironment(AntErrorSeverity severity
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
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","Environment"),arg0);
  return ProxyEnvironmentError;
}
static AntStatus ProxyGetClientError(AntStatus::AntError,2009);
inline AntStatus
ProxyErrGetClient(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "GetClient",
              source,
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","GetClient"));
  return ProxyGetClientError;
}
static AntStatus ProxyTimeoutError(AntStatus::AntError,2010);
inline AntStatus
ProxyErrTimeout(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "Timeout",
              source,
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","Timeout"),arg0);
  return ProxyTimeoutError;
}
static AntStatus ProxyImplementationError(AntStatus::AntError,2011);
inline AntStatus
ProxyErrImplementation(AntErrorSeverity severity
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
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","Implementation"),arg0);
  return ProxyImplementationError;
}
static AntStatus ProxyMissingEnvironmentError(AntStatus::AntError,2012);
inline AntStatus
ProxyErrMissingEnvironment(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "MissingEnvironment",
              source,
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","MissingEnvironment"),arg0);
  return ProxyMissingEnvironmentError;
}
static AntStatus ProxyStandbyInactiveError(AntStatus::AntError,2013);
inline AntStatus
ProxyErrStandbyInactive(AntErrorSeverity severity
      ,short line, const char* file
      ,const  char * arg0
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "StandbyInactive",
              source,
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","StandbyInactive"),arg0);
  return ProxyStandbyInactiveError;
}
static AntStatus ProxyNotConnectedError(AntStatus::AntError,2014);
inline AntStatus
ProxyErrNotConnected(AntErrorSeverity severity
      ,short line, const char* file
      
      ,AntErrorContext context=AntDetection
      ,const char* source=0)

{
  if (context == AntDetection) AntTrace::trace().initializeErrorLevel();
  else AntTrace::trace().incrementErrorLevel();
  AntLogError(severity, line, file,
              "NotConnected",
              source,
              "PROXY",
              AntTrace::trace().getErrorFormat("proxyerror.emf","Proxy","NotConnected"));
  return ProxyNotConnectedError;
}
inline const char *
ProxyGetErrorName(AntStatus status)
{
  switch(status.getMinor()) {
  case 2000:
    return "Init";
  case 2001:
    return "Exception";
  case 2002:
    return "ORB";
  case 2003:
    return "HostServer";
  case 2004:
    return "ServerNotRegistered";
  case 2005:
    return "ScadasoftFunction";
  case 2006:
    return "AppliFunction";
  case 2007:
    return "SystemFunction";
  case 2008:
    return "Environment";
  case 2009:
    return "GetClient";
  case 2010:
    return "Timeout";
  case 2011:
    return "Implementation";
  case 2012:
    return "MissingEnvironment";
  case 2013:
    return "StandbyInactive";
  case 2014:
    return "NotConnected";
  default:
    return "";
  }
}
#endif
