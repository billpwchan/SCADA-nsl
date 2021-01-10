/******************************************************************************/
/*									      */
/*  FILE		: scsutils.h                                          */
/*  FULL NAME		: Various utility functions required for SCS          */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: Thales-IS					      */
/*  CREATION DATE	: Jan 2002   					      */
/*  LANGUAGE		: C++						      */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW								      */
/*	                                				      */
/*............................................................................*/
/*  CONTENTS								      */
/******************************************************************************/
#ifndef _SCS_UTILS_H
#define _SCS_UTILS_H

/** \file
    \brief Various utility functions.
*/

#ifdef WIN32
#include <time.h>
#else
#include <sys/time.h>
#endif

#include "scsdefs.h"

  /**
     \par Description:
     Extract a server name from an implementation string
     \param implementation  [in]: a string with format: serverName\@[logicalEnv_host]
     \par Return values:
     serverName if successful, NULL otherwise
  */
extern SCS_API char * GetServerNameFromImplementation(const char * implementation);

  /**
     \par Description:
     Extract a logical environment name from an implementation string
     \param implementation  [in]: a string with format: serverName\@logicalEnv[_host]
     \par Return values:
     logicalEnv if successful, NULL otherwise
  */
extern SCS_API char * GetLogicalEnvironmentNameFromImplementation(const char * implementation);

  /**
     \par Description:
     Extract a host name from an implementation string
     \param implementation  [in]: a string with format: [serverName\@logicalEnv]_host
     \par Return values:
     host if successful, NULL otherwise
  */
extern SCS_API char * GetHostNameFromImplementation(const char * implementation);

  /**
     \par Description:
     Extract a physical environment name from an implementation string
     \param implementation  [in]: a string with format: [serverName]\@logicalEnv_host
     \par Return values:
     physical environment name (logicalEnv_host) if successful, NULL otherwise
  */
extern SCS_API char * GetPhysicalEnvironmentNameFromImplementation(const char * implementation);

  /**
     \par Description:
     Extract a logical environment name from a physical environnement string
     \param PhysEnv  [in]: a string with format: logicalEnv_host
     \par Return values:
     logical environment name (logicalEnv) if successful, NULL otherwise
  */
extern SCS_API char * GetLogEnvFromPhysEnv(const char * PhysEnv);

  /**
     \par Description:
     Extract a hostname from a physical environnement string
     \param PhysEnv  [in]: a string with format: logicalEnv_host
     \par Return values:
     hostname (host) if successful , NULL otherwise
  */
extern SCS_API char * GetHostNameFromPhysEnv(const char * PhysEnv);

  /**
     \par Description:
     Extract an objectName from an objectId string
     \param oid  [in]: a string with format: [serverName\@logicalEnv_host]/[marker:]interfaceName
     \par Return values:
      objectName ([marker:]interfaceName) if successful , NULL otherwise
  */
extern SCS_API char *GetObjectNameFromObjectId(const char *oid);

  /**
     \par Description:
     Extract an serverName from an objectId string
     \param oid  [in]: a string with format: serverName\@[logicalEnv_host/marker:interfaceName]
     \par Return values:
      serverName if successful , NULL otherwise
  */
extern SCS_API char *GetServerNameFromObjectId(const char *oid);

  /**
     \par Description:
     Extract an implementation from an objectId string
     \param oid  [in]: a string with format: serverName\@logicalEnv_host/[marker:interfaceName]
     \par Return values:
      serverName\@logicalEnv_host if successful , NULL otherwise
  */
extern SCS_API char *GetImplementationFromObjectId(const char *oid);

typedef char affTimeString[20];

  /**
     \par Description:
     Formats a timeval into a human readable time string
     \param timeStamp  [in]: timeval
     \param aff [in]:
     \par Return values:
     a string_var created on the fly 
  */
extern SCS_API affTimeString &affTime(const timeval &timeStamp, affTimeString &aff);

  /**
     \par Description:
     Formats a long (seconds of a timeval) into a human readable time string
     \param tagTime  [in]: timeval
     \param aff [in]:
     \par Return values:
     a string_var created on the fly 
  */
extern SCS_API affTimeString & affTime(const unsigned long & tagTime, affTimeString & aff);

#endif
