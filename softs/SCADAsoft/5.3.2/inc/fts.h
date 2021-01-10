/******************************************************************************/
/*                                                                            */
/*  FILE                : fts.h                                               */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  COMPANY             : THALES IS                                           */
/*  CREATION DATE       : 2000/01/10                                          */
/*  LANGUAGE            : C++                                                 */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*      Definition of C++ class FtsServer providing ORB client access         */
/*      to the FTS component server (process ftsserver).                      */
/*      An object of such a class must be built by the client process in      */
/*      order to access services to this component.                           */
/*............................................................................*/
/*  CONTENTS                                                                  */

/******************************************************************************/
/* IDENTIFICATION:                                                            */
/* $Id$                                                                       */
/*                                                                            */
/* HISTORY:                                                                   */
/* $Log$                                                                      */

/******************************************************************************/
#ifndef _FTS_H
#define _FTS_H

/**
  \file
  \brief Access to the FTS component Server
*/

/*----------------------------------------------------------------------------*/

#include "scs.h"
#include "manager.h"
#include "scsdefs.h"

#ifndef TRUE
#  define TRUE  1
#  define FALSE 0
#endif

#define LIST_ALL                0
#define LIST_ONLY_FILES      	1
#define LIST_ONLY_DIR        	2

#define LISTDIR_FILENAME "listdir.txt"

// Definition of FTS module trace function
#define FtsTrace        ScsTraceFunction(FTS_SCSMODULE)

/**
   Enum corresponding to the possible file transfer types given back to the
return callback function.
   \code
   enum FtsTransferType
   {
     TO_HOST = 0,
     FROM_HOST,
     TO_ENV,
     FROM_ENV
   }; \endcode
   \par Values:
   \li \c TO_HOST:  file transfer to a remote host,
   \li \c FROM_HOST:  file transfer from a remote host,
   \li \c TO_ENV:  file transfer to a remote SCADAsoft environment,
   \li \c FROM_ENV:  file transfer from a remote SCADAsoft environment.
*/
enum FtsTransferType
{
    TO_HOST = 0,
    FROM_HOST,
    TO_ENV,
    FROM_ENV
};

/**
   Prototype of the file transfer return callback function.
\code#include "fts.h"\endcode
   \par Description:
     this function is a function of the client
application called by the FTS server to notify the client asynchronously of
the result of a file transfer.  This callback function is called only once to
notify of the result of a file transfer.
   \param arg  [in]: Argument supplied in the transfer request.
   \param returnStatus  [in]: result status of the file transfer; it may
be:
   \li <em>ScsValid</em> : success.
   \li <em>FtsFtpError</em> : Ftp communication error.
   \par Return values:
     none.
*/

typedef void (*FtsReturnCallback)(ScsAny    arg,
                                  ScsStatus returnStatus);


class FtsProxy;
class FtsClient_i;

/**
   \brief This class is the interface class for the services exported by the FTS
server.\.

  The FtsServer class allows the user to reqest the transfer of a file or
the contents of a directory between the local host and a remote host or a
remote SCADAsoft environment.  Recursive copying of subdirectories is not
handled.  The remote username and password is determined by the local FTS
server from a configuration file, according to the remote host or
SCADAsoft environment name.

\code#include "fts.h"\endcode
*/
class FTS_API FtsServer
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor.  This function creates an interface object connected to the local FTS server.
     \param returnCallback  [in]: address of the file transfer return callback function which is used to notify a client of the result of a file transfer.
     \param environment  [in]: The Scadasoft environment on which the FtsServer program resides.
     \param name  [in]: The name of the FtsServer process.
     \param priority  [in]: priority of the messages to the FtsServer (only useful with redudancy).
     \par Return values:
     none.  The result of the connection can be obtained by calling the <em>getStatus()</em> function.
  */
  FtsServer (FtsReturnCallback returnCallback = NULL,
	     const char *environment = 0,
	     const char *name = "FtsServer",
	     ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);

  /**
     \par Description:
     destructor.  This function closes the connection with the local FTS server.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
    ~FtsServer ();
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     return the status of the connection to the FTS server process.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c FtsHostServerError : cannot connect with the ascmanager process.
     \li \c FtsORBError : cannot connect with the remote FTS server.
  */
    ScsStatus getStatus () const {return _status;};

  /**
     \par Description:
     this function deactivates the embedded CORBA services.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
  */
  ScsStatus deactivate();
  
  /**
     \par Description:
     this function renames a file on a remote env.
     \param envName  [in]: name of the remote environment on which the file has to be renamed.
     \param oldPathName  [in]: Absolute path  name of the file to be renamed. 
     \param newFileName  [in]: new file Name (without path ).
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception
raised).
  */
    ScsStatus renameFileOnEnvSynchro (const char    *envName,
				      const char    *oldPathName,
				      const char    *newFileName,
				      char           mode = 'I');

  /**
     \par Description:
     this function renames a file on a remote host.
     \param hostName  [in]: name of the remote host on which the file has to be renamed .
     \param oldPathName  [in]: Absolute path  name of the file to be renamed. 
     \param newFileName  [in]: new file Name (without path ).
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus renameFileOnHostSynchro (const char    *hostName,
				       const char    *oldPathName,
				       const char    *newFileName,
				       char           mode = 'I');

  /**
     \par Description:
     this function initiates a file transfer from the local host to a remote host.
     \param hostName  [in]: name of the remote host to which the file is to be transferred.
     \param fromPath  [in]: local path (absolute or relative to local home directory) of the file to be transferred. 
     \param toPath  [in]: remote path (absolute or relative to remote home directory) to which the file is to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFile  [in]: boolean indicating whether the source file is to be deleted after a successful transfer.
     \param arg  [in]: argument to be passed by FtsServer to the callback function on completion of the transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus putFileInHost (const char    *hostName,
                             const char    *fromPath,
                             const char    *toPath,
                             char           mode = 'I',
                             unsigned char  deleteFile = FALSE,
                             ScsAny         arg = NULL);

  /**
     \par Description:
     this function initiates a synchronized file transfer from the local host to a remote host.
     \param hostName  [in]: name of the remote host to which the file is to be transferred.
     \param fromPath  [in]: local path (absolute or relative to local home directory) of the file to be transferred. 
     \param toPath  [in]: remote path (absolute or relative to remote home directory) to which the file is to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFile  [in]: boolean indicating whether the source file is to be deleted after a successful transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus putFileInHostSynchro (const char    *hostName,
                             const char    *fromPath,
                             const char    *toPath,
                             char           mode = 'I',
                             unsigned char  deleteFile = FALSE);
  /**
     \par Description:
     this function initiates a directory transfer from the local host to a remote host.
     \param hostName  [in]: name of the remote host to which the directory is to be transferred.
     \param fromPath  [in]: local path (absolute or relative to local home directory) of the directory whose contents are to be transferred. 
     \param toPath  [in]: remote path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFiles  [in]: boolean indicating whether the source files are to be deleted after a successful transfer.
     \param arg  [in]: argument to be passed by FtsServer to the callback function on completion of the transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus putDirInHost (const char    *hostName,
                            const char    *fromPath,
                            const char    *toPath,
                            char           mode = 'I',
                            unsigned char  deleteFiles = FALSE,
                            ScsAny         arg = NULL);

  /**
     \par Description:
     this function initiates a directory transfer from the local host to a remote host on a synchronous way.
     \param hostName  [in]: name of the remote host to which the directory is to be transferred.
     \param fromPath  [in]: local path (absolute or relative to local home directory) of the directory whose contents are to be transferred. 
     \param toPath  [in]: remote path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFiles  [in]: boolean indicating whether the source files are to be deleted after a successful transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus putDirInHostSynchro (const char    *hostName,
                            const char    *fromPath,
                            const char    *toPath,
                            char           mode = 'I',
                            unsigned char  deleteFiles = FALSE);

  /**
     \par Description:
      this function create a directory on a named remote host.
     \param hostName  [in]: name of the remote host to which the directory is to be transferred.
     \param toPath  [in]: remote path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus mkDirInHost (const char    *hostName,
                            const char    *toPath,
                            char           mode = 'I');

  /**
     \par Description:
      this function delete a file on a named remote host.
     \param hostName  [in]: name of the remote host to which the directory is to be transferred.
     \param toPath  [in]: remote path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus deleteFileInHost (const char    *hostName,
                            	const char    *toPath,
                            	char           mode = 'I');

 /**
     \par Description:
      this function delete a directory on a named remote host.
     \param hostName  [in]: name of the remote host to which the directory is to be transferred.
     \param toPath  [in]: remote path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus rmDirInHost (const char    *hostName,
                            const char    *toPath,
                            char           mode = 'I');

 /**
     \par Description:
      this function list a directory on a named remote host.
     \param hostName  [in]: name of the remote host to which the directory is to be transferred.
     \param toPath  [in]: remote path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param arg  [in]: argument to be passed by FtsServer to the callback function on completion of the transfer.
     \param listDirFileName  [in]: name of the file containing the subdirectories and files 's list.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus listDirInHost (const char    *hostName,
                            const char     *toPath,
                            char           mode = 'I',
                            ScsAny         arg = NULL,
		 	    const char 	   *listDirFileName = NULL);


 /**
     \par Description:
      this function list a directory on a named remote host on a synchronous way.
     \param hostName  [in]: name of the remote host to which the directory is to be transferred.
     \param toPath  [in]: remote path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param listDirFileName  [in]: name of the file containing the subdirectories and files 's list.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus listDirInHostSynchro (const char    *hostName,
                            const char     *toPath,
                            char           mode = 'I',
			     //ScsAny         arg = NULL,
		 	    const char 	   *listDirFileName = NULL);


  /**
     \par Description:
    this function transfers specific files (ex: *.txt) from a remote host to the local host on a synchronous way.
     \param hostName  [in]: name of the remote host from which the file is to be transferred.
     \param fromPath  [in]: remote path (absolute or relative to remote home directory) of the file to be transferred.
     \param toPath  [in]: local path (absolute or relative to the local home directory) to which the file is to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFile  [in]: boolean indicating whether the source file is to be deleted after a successful transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus getFilesFromHostSynchro (const char    *hostName,
				       const char    *fromPath,
				       const char    *toPath,
				       char           mode = 'I',
				       unsigned char  deleteFile = FALSE);


  /**
     \par Description:
     this function initiates a file transfer from a remote host to the local host.
     \param hostName  [in]: name of the remote host from which the file is to be transferred.
     \param fromPath  [in]: remote path (absolute or relative to remote home directory) of the file to be transferred.
     \param toPath  [in]: local path (absolute or relative to the local home directory) to which the file is to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFile  [in]: boolean indicating whether the source file is to be deleted after a successful transfer.
     \param arg  [in]: argument to be passed by FtsServer to the callback function on completion of the transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus getFileFromHost (const char    *hostName,
                               const char    *fromPath,
                               const char    *toPath,
                               char           mode = 'I',
                               unsigned char  deleteFile = FALSE,
                               ScsAny         arg = NULL);

  /**
     \par Description:
     this function initiates a directory transfer from a remote host to the local host.
     \param hostName  [in]: name of the remote host from which the or directory is to be transferred.
     \param fromPath  [in]: remote path (absolute or relative to remote home directory) of the directory whose contents are to be transferred.
     \param toPath  [in]: local path (absolute or relative to local home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFiles  [in]: boolean indicating whether the source files are to be deleted after a successful transfer.
     \param arg  [in]: argument to be passed by FtsServer to the callback function on completion of the transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus getDirFromHost (const char    *hostName,
                              const char    *fromPath,
                              const char    *toPath,
                              char           mode = 'I',
                              unsigned char  deleteFiles = FALSE,
                              ScsAny         arg = NULL);

  /**
     \par Description:
     this function initiates a directory transfer from a remote host to the local host on a synchronous way.
     \param hostName  [in]: name of the remote host from which the or directory is to be transferred.
     \param fromPath  [in]: remote path (absolute or relative to remote home directory) of the directory whose contents are to be transferred.
     \param toPath  [in]: local path (absolute or relative to local home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFiles  [in]: boolean indicating whether the source files are to be deleted after a successful transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus getDirFromHostSynchro (const char    *hostName,
                              const char    *fromPath,
                              const char    *toPath,
                              char           mode = 'I',
                              unsigned char  deleteFiles = FALSE);

  /**
     \par Description:
     this function initiates a file transfer from the local host to a remote SCADAsoft environment.
     \param envName  [in]: name of the remote SCADAsoft environment to which the file is to be transferred.  This may be a logical environment name for an inter-environment file transfer or a physical environment name for an intra-redundant-environment file transfer.
     \param fromPath  [in]: local path (absolute or relative to local home directory) of the file to be transferred.
     \param toPath  [in]: remote path (absolute or relative to remote home directory) to which the file is to be transferred. 
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFile  [in]: boolean indicating whether the source file is to be deleted after a successful transfer.
     \param arg  [in]: argument to be passed by FtsServer to the callback function on completion of the transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus putFileInEnv (const char     *envName,
                            const char     *fromPath,
                            const char     *toPath,
                            char            mode = 'I',
                            unsigned char   deleteFile = FALSE,
                            ScsAny          arg = NULL);

  /**
     \par Description:
     this function initiates a file transfer from the local host to a remote SCADAsoft environment on a synchronous way.
     \param envName  [in]: name of the remote SCADAsoft environment to which the file is to be transferred.  This may be a logical environment name for an inter-environment file transfer or a physical environment name for an intra-redundant-environment file transfer.
     \param fromPath  [in]: local path (absolute or relative to local home directory) of the file to be transferred.
     \param toPath  [in]: remote path (absolute or relative to remote home directory) to which the file is to be transferred. 
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFile  [in]: boolean indicating whether the source file is to be deleted after a successful transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus putFileInEnvSynchro (const char     *envName,
                            const char     *fromPath,
                            const char     *toPath,
                            char            mode = 'I',
                            unsigned char   deleteFile = FALSE);
  /**
     \par Description:
     this function initiates a directory transfer from the local host to a remote SCADAsoft environment.
     \param envName  [in]: name of the remote SCADAsoft environment to which the directory is to be transferred.  This may be a logical environment name for an inter-environment file transfer or a physical environment name for an intra-redundant-environment file transfer.
     \param fromPath  [in]: local path (absolute or relative to local home directory) of the directory whose contents are to be transferred.
     \param toPath  [in]: remote path (absolute or relative to remote home directory) to which the directory's contents are to be transferred. 
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFiles  [in]: boolean indicating whether the source files are to be deleted after a successful transfer.
     \param arg  [in]: argument to be passed by FtsServer to the callback function on completion of the transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus putDirInEnv (const char     *envName,
                           const char     *fromPath,
                           const char     *toPath,
                           char            mode = 'I',
                           unsigned char   deleteFiles = FALSE,
                           ScsAny          arg = NULL);

 /**
     \par Description:
     this function initiates a directory transfer from the local host to a remote SCADAsoft environment on a synchronous way.
     \param envName  [in]: name of the remote SCADAsoft environment to which the directory is to be transferred.  This may be a logical environment name for an inter-environment file transfer or a physical environment name for an intra-redundant-environment file transfer.
     \param fromPath  [in]: local path (absolute or relative to local home directory) of the directory whose contents are to be transferred.
     \param toPath  [in]: remote path (absolute or relative to remote home directory) to which the directory's contents are to be transferred. 
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFiles  [in]: boolean indicating whether the source files are to be deleted after a successful transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus putDirInEnvSynchro (const char     *envName,
                           const char     *fromPath,
                           const char     *toPath,
                           char            mode = 'I',
                           unsigned char   deleteFiles = FALSE);

  /**
     \par Description:
     this function initiates a file transfer from a remote SCADAsoft environment to the local host.
     \param envName  [in]: name of the remote SCADAsoft environment from which the file is to be transferred.  This may be a logical environment name for an inter-environment file transfer or a physical environment name for an intra-redundant-environment file transfer.
     \param fromPath  [in]: remote path (absolute or relative to remote home directory) of the file to be transferred.
     \param toPath  [in]: local path (absolute or relative to local home directory) to which the file is to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFile  [in]: oolean indicating whether the source file is to be deleted after a successful transfer.
     \param arg  [in]: argument to be passed by FtsServer to the callback function on completion of the transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus getFileFromEnv (const char    *envName,
                              const char    *fromPath,
                              const char    *toPath,
                              char           mode = 'I',
                              unsigned char  deleteFile = FALSE,
                              ScsAny         arg = NULL);
  /**
     \par Description:
     this function initiates a file transfer from a remote online host of a SCADAsoft environment to the local host.
     \param envName  [in]: name of the remote SCADAsoft environment from which the file is to be transferred.  This may be a logical environment name for an inter-environment file transfer or a physical environment name for an intra-redundant-environment file transfer.
     \param fromPath  [in]: remote path (absolute or relative to remote home directory) of the file to be transferred.
     \param toPath  [in]: local path (absolute or relative to local home directory) to which the file is to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFile  [in]: oolean indicating whether the source file is to be deleted after a successful transfer.
     \param arg  [in]: argument to be passed by FtsServer to the callback function on completion of the transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus getFileFromOnLine(const char    *envName,
				const char    *fromPath,
				const char    *toPath,
				char           mode = 'I',
				unsigned char  deleteFile = FALSE,
				ScsAny         arg = NULL);
  /**
     \par Description:
     this function initiates a directory transfer from a remote SCADAsoft environment to the local host.
     \param envName  [in]: name of the remote SCADAsoft environment from which the directory is to be transferred.  This may be a logical environment name for an inter-environment file transfer or a physical environment name for an intra-redundant-environment file transfer.
     \param fromPath  [in]: remote path (absolute or relative to remote home directory) of the directory whose contents are to be transferred.
     \param toPath  [in]: local path (absolute or relative to local home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFiles  [in]: boolean indicating whether the source files are to be deleted after a successful transfer.
     \param arg  [in]: argument to be passed by FtsServer to the callback function on completion of the transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus getDirFromEnv (const char    *envName,
                             const char    *fromPath,
                             const char    *toPath,
                             char           mode = 'I',
                             unsigned char  deleteFiles = FALSE,
                             ScsAny         arg = NULL);

  /**
     \par Description:
     this function initiates a directory transfer from a remote SCADAsoft environment to the local host.
     \param envName  [in]: name of the remote SCADAsoft environment from which the directory is to be transferred.  This may be a logical environment name for an inter-environment file transfer or a physical environment name for an intra-redundant-environment file transfer.
     \param fromPath  [in]: remote path (absolute or relative to remote home directory) of the directory whose contents are to be transferred.
     \param toPath  [in]: local path (absolute or relative to local home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFiles  [in]: boolean indicating whether the source files are to be deleted after a successful transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus getDirFromEnvSynchro (const char    *envName,
                             const char    *fromPath,
                             const char    *toPath,
                             char           mode = 'I',
                             unsigned char  deleteFiles = FALSE);
  /**
     \par Description:
      this function create a directory on a named local host.
     \param envName  [in]: name of the local host to which the directory is to be transferred.
     \param fromPath  [in]: local path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus mkDirInEnv (const char    *envName,
                            const char    *fromPath,
                            char           mode = 'I');

  /**
     \par Description:
      this function delete a file on a named local host.
     \param envName  [in]: name of the remote host to which the directory is to be transferred.
     \param fromPath  [in]: remote path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus deleteFileInEnv (const char    *envName,
                            	const char    *fromPath,
                            	char           mode = 'I');

 /**
     \par Description:
      this function delete a directory on a named local host.
     \param envName  [in]: name of the local host to which the directory is to be transferred.
     \param fromPath  [in]: local path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus rmDirInEnv (const char    *envName,
                            const char    *fromPath,
                            char           mode = 'I');

 /**
     \par Description:
      this function list a directory on a named local host.
     \param envName  [in]: name of the local host to which the directory is to be transferred.
     \param fromPath  [in]: local path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param arg  [in]: argument to be passed by FtsServer to the callback function on completion of the transfer.
     \param listDirFileName  [in]: name of the file containing the subdirectories and files 's list.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus listDirInEnv (const char    *envName,
                            const char     *fromPath,
                            char           mode = 'I',
                            ScsAny         arg = NULL,
		 	    const char 	   *listDirFileName = NULL);

 /**
     \par Description:
      this function list a directory on the online host of a remote SCADAsoft environment.
     \param envName  [in]: name of the remote environment.
     \param fromPath  [in]: local path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param arg  [in]: argument to be passed by FtsServer to the callback function on completion of the transfer.
     \param listDirFileName  [in]: name of the file containing the subdirectories and files 's list.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus listDirInOnLine(const char*    envName,
			      const char*    fromPath,
			      char           mode = 'I',
			      ScsAny         arg = NULL,
			      const char*    listDirFileName = NULL);


 /**
     \par Description:
      this function list a directory on a named local host on a synchronous way.
     \param envName  [in]: name of the local host to which the directory is to be transferred.
     \param fromPath  [in]: local path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param listDirFileName  [in]: name of the file containing the subdirectories and files 's list.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus listDirInEnvSynchro (const char    *envName,
                            const char     *fromPath,
                            char           mode = 'I',
			     //ScsAny         arg = NULL,
		 	    const char 	   *listDirFileName = NULL);


  /**
     \par Description:
    this function transfers specific files (ex: *.txt) from the local host to a remote host on a synchronous way.
     \param envName  [in]: name of the local host from which the file is to be transferred.
     \param fromPath  [in]: remote path (absolute or relative to remote home directory) of the file to be transferred.
     \param toPath  [in]: local path (absolute or relative to the local home directory) to which the file is to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFile  [in]: boolean indicating whether the source file is to be deleted after a successful transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus getFilesFromEnvSynchro (const char    *envName,
				       const char    *fromPath,
				       const char    *toPath,
				       char           mode = 'I',
				       unsigned char  deleteFile = FALSE);

    /**
       \par Description:
      this function transfers specific files (ex: *.txt) from the a remote online host to the local host on a synchronous way.
       \param envName [in]: name of the remote environment from which the file is to be transferred. The online host is part of that environment. No recovery mechanism is implemented in case of online failure.
       \param fromPath  [in]: local path (absolute or relative to local home directory) of the file to be transferred.
       \param toPath  [in]: local path (absolute or relative to the local home directory) to which the file is to be transferred.
      \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
      \param deleteFile  [in]: boolean indicating whether the source file is to be deleted after a successful transfer.
      \return
      \li \c ScsValid : success.
      \li \c FtsFileAccessError : local file access error.
      \li \c FtsWorkingError : file transfer already in progress error.
      \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus getFilesFromOnLineSynchro (const char    *envName,
				       const char    *fromPath,
				       const char    *toPath,
				       char           mode = 'I',
				       unsigned char  deleteFile = FALSE);

  /**
     \par Description:
     this function initiates a directory transfer from a remote online host of a SCADAsoft environment to the local host.
     \param envName [in]: name of the remote SCADAsoft environment from which the directory is to be transferred. It must be a logical environment name for an inter-environment file transfer. No recovery mechanism is implemented in case of online failure.
     \param fromPath [in]: remote path (absolute or relative to remote home directory) of the directory whose contents are to be transferred.
     \param toPath [in]: local path (absolute or relative to local home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param deleteFiles  [in]: boolean indicating whether the source file is to be deleted after a successful transfer.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus getDirFromOnLineSynchro (const char    *envName,
                             const char    *fromPath,
                             const char    *toPath,
                             char           mode = 'I',
                             unsigned char  deleteFiles = FALSE);

 /**
     \par Description:
      this function list a directory on the remote online host on a synchronous way.
     \param envName [in]: name of the remote to which the directory is to be transferred. The online host is part of that environment. No recovery mechanism is implemented in case of online failure.
     \param fromPath [in]: local path (absolute or relative to remote home directory) to which the directory's contents are to be transferred.
     \param mode  [in]: ftp transfer mode - 'A' for ascii, 'I' for image.
     \param listDirFileName  [in]: name of the file containing the subdirectories and files 's list.
     \return
     \li \c ScsValid : success.
     \li \c FtsFileAccessError : local file access error.
     \li \c FtsWorkingError : file transfer already in progress error.
     \li \c FtsORBError : ORB communication error (exception raised).
  */
    ScsStatus listDirInOnLineSynchro (const char    *envName,
                            const char     *fromPath,
                            char           mode = 'I',
		 	    const char 	   *listDirFileName = NULL);




  //@}

private:

    FtsProxy          *_proxy;
    ScsStatus          _status;
    FtsClient_i       *_client;
    unsigned char      _replyFlag;
    FtsTransferType    _transfType;
    char              *_userName;
};

#endif /* _FTS_H */
