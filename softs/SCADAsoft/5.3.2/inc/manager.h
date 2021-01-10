/******************************************************************************/
/*									      */
/*  FILE		: manager.h                                               */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 1998/08/06					      */
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
// IDENTIFICATION:
// $Id: manager.h,v 1.5 1999/06/07 15:53:21 ylo Exp $
//
// HISTORY:
// $Log: manager.h,v $
// Revision 1.5  1999/06/07 15:53:21  ylo
// Change manager callback prototype (environment and process are now returned)
//
// Revision 1.4  1999/05/03 07:52:54  ylo
// Fix getState problem when nobody have already talked to the environment.
// Add SCS_DEGRADED state
//
// Revision 1.3  1999/02/26 10:21:12  ylo
// Add getStatus method.
//
// Revision 1.2  1998/12/14 14:02:38  jmb
// Use OlsPhysicalServer instead of OlsServer
//
// Revision 1.1  1998/12/07 13:45:23  ylo
// Initial revision
//
// Revision 1.4  1998/12/02 11:45:46  jmb
// Add process parameter to getState and subscribeState methods.
// Suppression of setState method.
//
// Revision 1.3  1998/11/27 14:25:29  ylo
// Add supervision callback.
//
// Revision 1.2  1998/11/24 14:29:28  jmb
// Add getHosts & getEnvs methods
//
// Revision 1.1  1998/11/06 11:09:44  jmb
// Initial revision
//
/******************************************************************************/
#ifndef _MANAGER_H_
#define _MANAGER_H_

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/
#include "scs.h"

/**
  \file
  \brief Access to the AscManager component
*/

class AscManagerIdl;
class OlsPhysicalServer;

/**
   \brief Prototype of the <em>AscManager</em> notification callback function.

\code#include "manager.h"\endcode
   \par Description:
     this function is a client application function called by the <em>AscManager</em> object to asynchronously notify a client subscribed to the state of a process in a logical environment (current or remote environment).
   \param logicalEnv  [in]: name of the logical environment in which the process is running,
   \param processName  [in]: name of the process,
   \param state  [in]: current state of the process,
   \param arg  [in]: user optional argument given by the client when it calls the subscription function and returned to it when the current callback function is called by the <em>Ascmanager</em> object. This parameter is optional, but, if set, could be used to give back information to the client.
   \par Return values:
     none.
*/
typedef void (*MgrSupervisionCallback)(const char *logicalEnv,
				       const char *processName,
				       const char *state,
				       void       *arg);

/**
   \brief This class is one of the interface classes for the exported services of the <em>RED</em> SCADAsoft component (redundancy).

   This class is used for the supervision of the processes of the current logical environment or of another logical environment.
\code#include "manager.h"\endcode
*/
class ASC_API AscManager
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface <em>AscManager</em> object connected to the <em>ascmanager</em> process of current physical environment.
     \par Parameters:
     none.
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  AscManager();
  //@}

  ~AscManager();

  

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     return the status of the connection to the <em>ascmanager</em> process.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c AscORBError : cannot connect with the remote <em>ascmanager</em>.
  */
  ScsStatus getStatus() const { return _status;};
  
  /**
     \par Description:
     this function deactivates the embedded CORBA services.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
  */
  virtual ScsStatus deactivate();
  
  /**
     \par Description:
     this function subscribe to the state of the process named <em>processName</em> running in the <em>logicalEnv</em> logical environment. The connection between the current application and the <em>processName</em> process is periodically checked. If a change in this connection occurs, then the <em>notificationCallback</em> callback function is called with the status of the connection: &quot;<em>SCS_DOWN</em>&quot; means the connection is down whereas &quot;<em>SCS_UP</em>&quot; means the connection is up and &quot;<em>SCS_INIT</em>&quot; means the connection is up, but no <em>AscServer</em> object was created. If the remote process has implemented an <em>AscStateMgr</em> object, the state &quot;<em>SCS_UP</em>&quot; will be replace by all state supported by the remote process.
     \param logicalEnv  [in]: name of the logical environment in which the process is running,
     \param processName  [in]: process name,
     \param subscriptionId  [out]: subscription identifier,
     \param notificationCallback  [in]: user notification callback function,
     \param arg  [in]: user optional argument passed to the notification callback function when called.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus subscribeState(const char             *logicalEnv,
			   const char             *processName,
			   int                    &subscriptionId, 
			   MgrSupervisionCallback  notificationCallback, 
			   ScsAny                  arg = 0);
  /**
     \par Description:
     this function subscribe to the state of the process named <em>processName</em> running in the <em>logicalEnv</em> logical environment. The connection between the current application and the <em>processName</em> process is periodically checked. If a change in this connection occurs, then the <em>notificationCallback</em> callback function is called with the status of the connection: &quot;<em>SCS_DOWN</em>&quot; means the connection is down whereas &quot;<em>SCS_UP</em>&quot; means the connection is up and &quot;<em>SCS_INIT</em>&quot; means the connection is up, but no <em>AscServer</em> object was created. If the remote process has implemented an <em>AscStateMgr</em> object, the state &quot;<em>SCS_UP</em>&quot; will be replace by all state supported by the remote process. The current state of the process is also returned.
     \param logicalEnv  [in]: name of the logical environment in which the process is running,
     \param processName  [in]: process name,
     \param state  [out]: process current state,
     \param subscriptionId  [out]: subscription identifier,
     \param notificationCallback  [in]: user notification callback function,
     \param arg  [in]: user optional argument passed to the notification callback function when called.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus subscribeState(const char              *logicalEnv,
			   const char              *processName,
			   char                   *&state,
			   int                     &subscriptionId, 
			   MgrSupervisionCallback   notificationCallback, 
			   ScsAny                   arg = 0);
  /**
     \par Description:
     this function cancels the specified subscription to the state of a remote process running in the <em>logicalEnv</em> logical environment.
     \param logicalEnv  [in]: name of the logical environment in which the process is running,
     \param subscribeId  [in]: subscription identifier.
     \return
     \li \c ScsValid : success.
     \li \c AscORBError : error in orb communication.
     \li \c OlsBadSubscriptionIdError : bad subscription identifier.
    */
  ScsStatus unsubscribe(const char *logicalEnv, int &subscribeId);

  /**
     \par Description:
     this function returns the state of the remote <em>processName</em> application running in the <em>logicalEnv</em> logical environment.
     \param logicalEnv  [in]: name of the logical environment in which the process is running,
     \param processName  [in]: process name,
     \param state  [out]: process current state.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getState(const char  *logicalEnv,
		     const char  *processName,
		     char       *&state);

  /**
     \par Description:
     this function sets the state of a remote <em>processName</em> application running in the <em>physEnvName</em> physical environment.
     \param physEnvName  [in]: name of the physical environment in which the process is running,
     \param processName  [in]: process name,
     \param state        [in]: new process state.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus setState(const char * physEnvName,
		     const char * processName,
		     const char * state);

  /**
     \par Description:
     this function returns the list of hosts on which may run the <em>logicalEnv</em> logical environment.
     \param logicalEnv  [in]: name of the logical environment,
     \param hostNames  [out]: list of host names,
     \param count  [out]: number of hosts.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getHosts(const char  *logicalEnv,
		     char       **&hostNames,
		     short        &count);
  /**
     \par Description:
     this function returns the list of physical environment names associated with the <em>logicalEnv</em> logical environment.
     \param logicalEnv  [in]: name of the logical environment,
     \param envNames  [out]: list of physical environment names,
     \param count  [out]: number of environments.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getEnvs(const char   *logicalEnv,
		    char       **&envNames,
		    short        &count);
  /**
    \par Description:
     this function check periodically connection between the application and the name server running in the environment environment. If a change in this connection occurs, then callback is called with the status of the connection. " SCS_DOWN " means connection down whereas " SCS_UP " means connection up. If the remote application has implemented a AscStateMgr, the state " SCS_UP " will be replace by all state supported by the remote application.
    \param physEnvironment  [in]: name of the physical environment,
    \param logEnvironment  [in]: name of the logical environment,
    \param process  [in]: process name,
    \param subscribeId  [out]: subscription identifier.
    \param callback  [in]: supervision callback function,
    \param arg  [in]: user optional argument passed to the supervision callback function when called.
    \return
    \li \c ScsValid : success.
    \li \c ScsError : error.
    \li \c AscORBError : error in orb communication
    \li \c AscUnknownEnvironmentError : environment is unknown.
    \li \c AscInactiveServerError : server name is not active.
    \li \c AscBadServerNameError : server is unknown (no environment specified).  
   */
  ScsStatus subscribePhysState(const char *physEnvironment,
			       const char *logEnvironment,
			       const char *process,
			       int        &subscribeId, 
			       MgrSupervisionCallback callback, 
			       ScsAny arg = 0);
  /**
    \par Description:
     this function check periodically connection between the application and the name server running in the environment environment. If a change in this connection occurs, then callback is called with the status of the connection. " SCS_DOWN " means connection down whereas " SCS_UP " means connection up. If the remote application has implemented a AscStateMgr, the state " SCS_UP " will be replace by all state supported by the remote application. The current connection state and state are also returned.
    \param physEnvironment  [in]: name of the physical environment,
    \param logEnvironment  [in]: name of the logical environment,
    \param process  [in]: process name,
    \param state  [out]: process current state,
    \param subscribeId  [out]: subscription identifier.
    \param callback  [in]: supervision callback function,
    \param arg  [in]: user optional argument passed to the supervision callback function when called.
    \return
    \li \c ScsValid : success.
    \li \c ScsError : error.
    \li \c AscORBError : error in orb communication
    \li \c AscUnknownEnvironmentError : environment is unknown.
    \li \c AscInactiveServerError : server name is not active.
    \li \c AscBadServerNameError : server is unknown (no environment specified).  
   */
  ScsStatus subscribePhysState(const char  *physEnvironment,
			       const char  *logEnvironment,
			       const char  *process,
			       char       *&state,
			       int         &subscribeId, 
			       MgrSupervisionCallback callback, 
			       ScsAny arg = 0);
  /**
    \par Description:
     this function unsubscribe to the state of a remote manager running in the environment.
    \param subscribeId  [in]: subscription identifier.
    \return
    \li \c ScsValid : success.
    \li \c ScsError : error.
    \li \c AscORBError : error in orb communication
    \li \c AscUnknownEnvironmentError : environment is unknown.
    \li \c AscInactiveServerError : server name is not active.
    \li \c AscBadServerNameError : server is unknown (no environment specified).  
   */
  ScsStatus unsubscribePhys(int  subscribeId);
  /**
    \par Description:
     this function check periodically connection between the application and the name server running in the environment environment. If a change in this connection occurs, then callback is called with the status of the connection. " SCS_DOWN " means connection down whereas " SCS_UP " means connection up. If the remote application has implemented a AscStateMgr, the state " SCS_UP " will be replace by all state supported by the remote application. The current connection state and state are also returned.
    \param physEnvironment  [in]: name of the physical environment,
    \param process  [in]: process name,
    \param state  [out]: process current state.
    \return
    \li \c ScsValid : success.
    \li \c ScsError : error.
    \li \c AscORBError : error in orb communication
    \li \c AscUnknownEnvironmentError : environment is unknown.
    \li \c AscInactiveServerError : server name is not active.
    \li \c AscBadServerNameError : server is unknown (no environment specified).  
   */
  ScsStatus getPhysState(const char  *physEnvironment,
			 const char  *process,
			 char       *&state);
  /**
    \par Description:
     this function returns the type of redundancy of the specified logical environment.
    \param logicalEnv  [in]: name of the logical environment,
    \param redundancyType  [out]: redundancy type.
    \return
    \li \c ScsValid : success.
    \li \c AscORBError : error in orb communication
    \li \c AscUnknownEnvironmentError : environment is unknown.
    \li \c AscInactiveServerError : server name is not active.
   */
  ScsStatus getRedundancyType(const char                *logicalEnv,
			      Scadasoft::RedundancyType &redundancyType);
  //@}

  struct StateNotificationArg {
    MgrSupervisionCallback  _callback;
    void                   *_arg;

    StateNotificationArg() { _callback = 0; _arg = 0;}
  };

private:
   
  ScsStatus             _status;
  AscManagerIdl        *_manager;
  OlsPhysicalServer    *_envServ;
};

#endif
