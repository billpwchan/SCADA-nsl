/******************************************************************************/
/*									      */
/*  FILE		: ctlgrc.h                                            */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 2000/9/4					      */
/*  LANGUAGE		: C++						      */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW								      */
/*	Definition of C++ class CtlGrcServer providing CORBA client access    */
/*	to the CTLGRC component server (process ctlgrcserver).                */
/*	An object of such a class must be built be the client process in      */
/*	order to access services to this component .                          */
/*............................................................................*/
/*  CONTENTS								      */
/******************************************************************************/
#ifndef _CTLGRC_H
#define _CTLGRC_H

#ifdef __cplusplus

/** \file
 * \brief CTL Grouped Remote Control Server structure for the <em>CTLGRC</em> component.
 */

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/
#include "scs.h"
#include "manager.h"

// Definition of CTL module trace function
#define CtlTrace	ScsTraceFunction(CTL_SCSMODULE)

class CTL_API CtlBrc
{
public:

  /**@name Typedefs / defines*/
  /*@{*/
  /** 
      \par Description:
     BRC types list.
      \code
      enum E_ScsCtlGrcBrcType { 
      Cmd = 1,
      Grc,
      MCmd
      } ScsCtlGrcBrcType; \endcode
      \par Values:
      \li \c Cmd: indicates that the BRC is a single command,
      \li \c Grc: indicates that the BRC is a GRC,
      \li \c MCmd: indicates that the BRC is a Multiple command GRC,
  */
  enum ScsCtlGrcBrcType {
    Cmd = 1,
    Grc,
    MCmd
  };

  /**
      \par Description:
     BRC status list.
      \code
      enum E_ScsCtlBrcStatus { 
      NotExecuted = 1,
      Completed,
      Failed
      } ScsCtlBrcStatus; \endcode
       \par Values:
      \li \c NotExecuted:  BRC was not executed,
      \li \c Completed: BRC was executed and completed successfully,
      \li \c Failed: BRC was executed and failed.
  */
  enum ScsCtlBrcStatus {
    NotExecuted = 1,
    Completed,
    Failed,
    Skipped
  };
  /*@}*/
};


/**
   \brief This class defines the CtlGrc typedef.

\code#include "ctlgrc.h"\endcode
*/

class CTL_API CtlGrc
{
public:

  /**@name Typedefs / defines*/
  //@{
  /** 
      \par Description:
     enum corresponding to the possible values for the current status of a GRC.
      \code
      enum E_ScsCtlGrcStatus { 
         Terminated = 1,
         WaitForRun,
         Initializing,
         Running,
         Waiting,
         Stopped,
         Aborted,
         Suspended,
         Resuming
      } ScsCtlGrcStatus; \endcode
      \par Values:
      \li \c Terminated: Execution terminated,
      \li \c WaitForRun:  Waiting for the GRC to be run,
      \li \c Initializing: Initializing execution,
      \li \c Running: Execution running,
      \li \c Waiting: Execution waiting,
      \li \c Stopped: Execution stopped,
      \li \c Aborted: Execution aborted.
      \li \c Suspended: Execution suspended.
      \li \c Resuming: resuming in progress.
  */
  enum ScsCtlGrcStatus {
    Terminated = 1,
    WaitForRun,
    Initializing,
    Running,
    Waiting,
    Stopped,
    Aborted,
    Suspended,
    Resuming
  };


  /**
      \par Description:
     launching mode value list.
      \code
      enum E_ScsCtlGrcMode { 
         Auto = 1,
         StopOnFailed,
         StopOnFirstBRCExecuted
      } ScsCtlGrcMode; \endcode
      \par Values:
      \li \c Auto:  The GRC is excuted sequentially,
      \li \c StopOnFailed:  The GRC execution stopped when a step execution failed.
      \li \c StopOnFirstBRCExecuted:  The GRC execution stopped when the first step is executed (Not necessary the BRC with index=1).
      This allows to execute only one BRC of a GRC
  */
  enum ScsCtlGrcMode {
    Auto = 1,
    StopOnFailed,
    StopOnFirstBRCExecuted
  };


  /**
      \par Description:
     callback updating Type list.
      \code
      enum  E_ScsCtlGrcUpdateType { 
         Brc = 0,
         Grc = 1
      }  ScsCtlGrcUpdateType \endcode
      \par Values:
      \li \c Brc: This is a BrcExeStatus updating,
      \li \c Grc: This is a GrcStatus updating.
  */
  enum ScsCtlGrcUpdateType {
    Brc = 0,
    Grc = 1
  };

  //@}
};

class CtlGrcServerProxy;
class CtlGrcClientIdl_i;

/**
   \brief CTL Grouped Remote Control Server structure for the <em>CTLGRC</em> component.

   This class is used to describe a command to send to an equipment. A command corresponds to an internal output variable (IOV). 
\code#include "ctlgrc.h"\endcode
*/

class CTL_API CtlGrcServer
{
public:

  /**
     Prototype of a GRC execution callback function.
\code#include "ctlgrc.h"\endcode
     \par Description:
     this callback is called each time either the current GRC step, and the current GRC status change.
     \param environment      [in]: logical environment name where the GRC is running.
     \param grcName          [in]: GRC name.  
     \param type             [in]: type of updating (Brc or Grc).
     \param completionStatus [in]: current GRC execution status.
     \param stepNumber       [in]: current execution step.
     \param callbackArg      [in]: user optional argument.
     \par Return values:
     none.
  */
  
  typedef void (*CtlGrcCompletionCallback)(const char *environment,
					   const char *grcName,
					   CtlGrc::ScsCtlGrcUpdateType type,
					   long        completionStatus,
					   long        stepNumber,
                                           ScsAny      callbackArg);

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object connected to the CTLGRC server.

     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required CTLCMD server is running.
     \param completionCallback  [in]: address of the GRC execution return callback function which will be used to notify a client of the execution of a GRC.
     \param completionCallbackArg  [in]: user optional argument used by the notification callback function.
     \param priority  [in]: priority of the messages to the CtlGrcServer (only useful with redudancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> functi
on.
  */

  CtlGrcServer(const char *logicalEnv = NULL,
               CtlGrcCompletionCallback completionCallback = NULL,
               ScsAny completionCallbackArg = NULL,
	       ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);

  /**
     \par Description:
     destructor. This function closes the connection with the CTLGRC server.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~CtlGrcServer();
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     return the status of the connection to the CTLGRC server.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c CtlHostServerError : cannot connect with the ascmanager process.
     \li \c CtlORBError : cannot connect with the remote CTLGRC server.
  */
  ScsStatus getStatus();
  
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
     this function allows to trigger a preparation hook in the ctlgrcserver. It does nothing by default.
     \param in_grcName  [in]: GRC name.
     \param source      [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  ScsStatus prepareGrc(const char* in_grcName, const char* source = NULL) const;

  /**
     \par Description:
     this function allows to trigger a hook in the ctlgrcserver to abort the preparation actions. It does nothing by default.
     \param in_grcName  [in]: GRC name.
     \param source      [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  ScsStatus abortGrcPreparation(const char* in_grcName, const char* source = NULL) const;

  /**
     \par Description:
     this function launch a GRC.
     \param in_grcName  [in]: GRC name.
     \param in_grcMode  [in]: GRC mode.
     \param source      [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  ScsStatus launchGrc(const char* in_grcName, CtlGrc::ScsCtlGrcMode in_grcMode = CtlGrc::Auto, const char    *source = NULL) const;

  /**
     \par Description:
     this function just launch one BRC of a GRC.
     \param in_grcName  [in]: GRC name.
     \param in_brcNum   [in]: BRC index.
     \param source      [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  ScsStatus launchGrcStep(const char* in_grcName, long in_brcNum, const char* source = NULL) const;
  
  /**
     \par Description:
     this function launches a GRC starting a specified step and skips some steps.
     \param in_grcName   [in]: GRC name.
     \param in_grcMode   [in]: GRC mode.
     \param in_grcStep   [in]: index of the first step to execute.
     \param in_grcStepsToSkip  [in]: Array of GRC steps to skipp.
     \param in_count     [in]: Array size.
     \param source       [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  ScsStatus launchGrc(const char*           in_grcName, 
		      CtlGrc::ScsCtlGrcMode in_grcMode, 
		      long                  in_grcStep, 
		      const long*           in_grcStepsToSkip, 
		      short                 in_count,
		      const char*           source = NULL) const;
  
  /**
     \par Description:
     this function launch a GRC starting at a specified BRC.
     \param in_grcName  [in]: GRC name.
     \param in_brcNum   [in]: BRC index.
     \param source      [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  ScsStatus launchGrcAtStep(const char* in_grcName,
			    long        in_brcNum,
			    const char* source = NULL) const;
  
  /**
     \par Description:
     this function launches a GRC and skips some steps.
     \param in_grcName   [in]: GRC name.
     \param in_grcSteps  [in]: Array of GRC steps to skipp.
     \param in_count     [in]: Array size.
     \param source       [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  ScsStatus launchGrcSkippingSteps(const char*  in_grcName,
				   const long*  in_grcSteps,
				   short        in_count,
				   const char*  source = NULL) const;

  /**
     \par Description:
     this function aborts a GRC.
     \param in_grcName   [in]: GRC name.
     \param source       [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  ScsStatus abortGrc(const char* in_grcName, const char* source = NULL);

  /**
     \par Description:
     this function suspends a GRC.
     \param in_grcName   [in]: GRC name.
     \param source       [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  ScsStatus suspendGrc(const char* in_grcName, const char* source = NULL);
  
  /**
     \par Description:
     this function resumes a suspended GRC.
     \param in_grcName   [in]: GRC name.
     \param source       [in]: any string identifier that names the source of the command.
     \return
     \li \c ScsValid : success.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  ScsStatus resumeGrc(const char* in_grcName, const char* source = NULL);
  
  /**
     \par Description:
     return the name of the CTLGRC server to which the interface object is connected.
     \par Parameters:
     none.
     \par Return values:
     the name of the server.
  */
  const char *getServerName() { return _serverName;};
  
  /**
     \par Description:
     return the logical SCADAsoft environment name of the CTLGRC server to which the interface object is connected.
     \par Parameters:
     none.
     \par Return values:
     the name of the environment.
  */
  const char *getServerEnv() { return _envName;};
  //@}
  
private:

  CtlGrcServerProxy *_proxy;
  ScsStatus          _status;
  CtlGrcClientIdl_i *_client;
  char              *_serverName;
  char              *_envName;
};

#endif /* __cplusplus */

#endif /* _CTLGRC_H */
