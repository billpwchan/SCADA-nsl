/******************************************************************************/
/*									      */
/*  FILE		: agent.h                                             */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES-IS					      */
/*  CREATION DATE	: 1998/11/30					      */
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
// $Id: agent.h,v 1.4 1999/06/07 15:54:06 ylo Exp $
//
// HISTORY:
// $Log: agent.h,v $
// Revision 1.4  1999/06/07 15:54:06  ylo
// Change agent callback prototype (process is now returned)
//
// Revision 1.3  1999/01/26 11:53:35  ylo
// Crash fixing.
//
// Revision 1.3  1999/01/14 17:05:20  ylo
// Only one state for snapshot (background and foreground)
//
// Revision 1.2  1998/12/14 14:02:09  jmb
// Use OlsPhysicalServer instead of OlsServer
//
// Revision 1.1  1998/12/07 13:42:31  ylo
// Initial revision
//
// Revision 1.1  1998/12/02 11:44:28  jmb
// Initial revision
//
/******************************************************************************/
#ifndef _AGENT_H_
#define _AGENT_H_

/** \file
 * \brief Supervision of the processes of the current physical environment.
 */

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/
#include "scs.h"

class AscAgentIdl;
class OlsPhysicalServer;

/**
   Prototype of the <em>AscAgent</em> notification callback function.
\code#include "agent.h"\endcode
   \par Description:
     this function is a client application function called by the <em>AscAgent</em> object to asynchronously notify a client subscribed to the state of a process in a current physical environment.
   \param processName  [in]: name of the process,
   \param state  [in]: current state of the process,
   \param arg  [in]: user optional argument given by the client when it calls the subscription function and returned to it when the current callback function is called by the <em>AscAgent</em>. This parameter is optional, but, if set, could be used to give back information to the client.
   \par Return values:
     none.
*/
typedef void (*AgtSupervisionCallback)(const char *processName,
				       const char *state,
				       void       *arg);

/**
   \brief This class is one of the interface classes for the exported services of the <em>RED</em> SCADAsoft component (redundancy).

   This class is used for the supervision of the processes of the current physical environment.
\code#include "agent.h"\endcode
*/
class ASC_API AscAgent
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface <em>AscAgent</em> object connected to the <em>ascmanager</em> process of current physical environment.
     \par Parameters:
     none.
     \par Return values:
     none. The result of the connection can be obtained by calling the <em>getStatus()</em> function.
  */
  AscAgent();
  //@}

  ~AscAgent();




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
  ScsStatus deactivate();
  /**
     \par Description:
     this function subscribes to the state of the process named <em>processName</em> running in the current physical environment. The connection between the current application and the <em>processName</em> process is periodically checked. If a change in this connection occurs, then the <em>notificationCallback</em> callback function is called with the status of the connection: &quot;<em>SCS_DOWN</em>&quot; means the connection is down whereas &quot;<em>SCS_UP</em>&quot; means the connection is up and &quot;<em>SCS_INIT</em>&quot; means the connection is up, but no <em>AscServer</em> object was created. If the remote process has implemented an <em>AscStateMgr</em> object, the state &quot;<em>SCS_UP</em>&quot; will be replaced by all states supported by the remote process.
     \param processName  [in]: process name,
     \param subscriptionId  [out]: subscription identifier,
     \param notificationCallback  [in]: user notification callback function,
     \param arg  [in]: user optional argument passed to the notification callback function when called.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus subscribeState(const char             *processName,
			   int                    &subscriptionId, 
			   AgtSupervisionCallback  notificationCallback, 
			   ScsAny                  arg = 0);
  /**
     \par Description:
     this function subscribe to the state of the process named <em>processName</em> running in the current physical environment. The connection between the current application and the <em>processName</em> process is periodically checked. If a change in this connection occurs, then the <em>notificationCallback</em> callback function is called with the status of the connection: &quot;<em>SCS_DOWN</em>&quot; means the connection is down whereas &quot;<em>SCS_UP</em>&quot; means the connection is up and &quot;<em>SCS_INIT</em>&quot; means the connection is up, but no <em>AscServer</em> object was created. If the remote process has implemented an <em>AscStateMgr</em> object, the state &quot;<em>SCS_UP</em>&quot; will be replace by all state supported by the remote process. The current state of the process is also returned.
     \param processName  [in]: process name,
     \param subscriptionId  [out]: subscription identifier,
     \param state  [out]: process current state,
     \param notificationCallback  [in]: user notification callback function,
     \param arg  [in]: user optional argument passed to the notification callback function when called.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus subscribeState(const char              *processName,
			   int                     &subscriptionId, 
			   char                   *&state,
			   AgtSupervisionCallback   notificationCallback, 
			   ScsAny                   arg = 0);
  /**
     \par Description:
     this function cancels the specified subscription to the state of a process running in the current physical environment.
     \param subscriptionId  [in]: subscription identifier.
     \return
     \li \c ScsValid : success.
     \li \c AscORBError : error in orb communication.
     \li \c OlsBadSubscriptionIdError : bad subscription identifier.
    */
   ScsStatus unsubscribe(int subscriptionId);
  /**
     \par Description:
     this function returns the state of the remote <em>processName</em> application running in the current physical environment.
     \param processName  [in]: process name,
     \param state  [out]: process current state.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getState(const char *processName, char *&state);
  /**
     \par Description:
     this function changes the state of the remote <em>processName</em> application running in the current physical environment.
     \param processName  [in]: process name,
     \param state  [in]: new state.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus setState(const char *processName, const char *state);

  /**
     \par Description:
     this function allows a process to specify its state - used in PUSH supervision.
     \param processName  [in]: process name,
     \param state  [in]: new state.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus specifyState(const char *processName, const char *state);

 /**
     \par Description:
     this function test the state of the local watchdog.
     \param state  [out]: watchdog current state.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus testWatchdog(char *&state);
  /**
     \par Description:
     this function get the last life time of the local watchdog.
     \param lastlifetime  [out]: last watchdog life time.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getWatchdogLastLifeTime(timeval &lastlifetime);
  /**
     \par Description:
     this function get the mode of the local watchdog.
     \param mode  [out]: watchdog current mode.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getWatchdogMode(int &mode);
  /**
     \par Description:
     this function get the state of the network 1 for send.
     \param state  [out]: network 1 send current state.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getNet1SendState(char *&state);
  /**
     \par Description:
     this function get the last time of the network 1 for send.
     \param lasttime  [out]: network 1 send last time.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getLastNet1SendStateTime(timeval &lasttime);
  /**
     \par Description:
     this function get the state of the network 1 for receive.
     \param state  [out]: network 1 receive current state.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getNet1RecvState(char *&state);
  /**
     \par Description:
     this function get the last time of the network 1 for receive.
     \param lasttime  [out]: network 1 receive last time.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getLastNet1RecvStateTime(timeval &lasttime);
  /**
     \par Description:
     this function get the state of the network 2 for send.
     \param state  [out]: network 2 send current state.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getNet2SendState(char *&state);
  /**
     \par Description:
     this function get the last time of the network 2 for send.
     \param lasttime  [out]: network 2 send last time.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getLastNet2SendStateTime(timeval &lasttime);
  /**
     \par Description:
     this function get the state of the network 2 for receive.
     \param state  [out]: network 2 receive current state.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getNet2RecvState(char *&state);
  /**
     \par Description:
     this function get the last time of the network 2 for receive.
     \param lasttime  [out]: network 2 receive last time.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getLastNet2RecvStateTime(timeval &lasttime);
  /**
     \par Description:
     this function get the state of the serial line for send.
     \param state  [out]: serial line send current state.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getSerSendState(char *&state);
  /**
     \par Description:
     this function get the last time of the serial line for send.
     \param lasttime  [out]: serial line send last time.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getLastSerSendStateTime(timeval &lasttime);
  /**
     \par Description:
     this function get the state of the serial line for receive.
     \param state  [out]: serial line receive current state.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getSerRecvState(char *&state);
  /**
     \par Description:
     this function get the last time of the serial line for receive.
     \param lasttime  [out]: serial line receive last time.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getLastSerRecvStateTime(timeval &lasttime);
  /**
     \par Description:
     this function start a command through the ascmanager same a process of ScsEnvTable.
     \param serverName  [in]: name of server to start.
     \param termination  [in]: termination parameter (NONE | SHUTDOWN | RETRY).
     \param notification  [in]: notification parameter (YES | NO).
     \param supervision  [in]: supervision parameter (NONE | CORBA | UNIX | RTAP | PUSH).
     \param priority  [in]: priority parameter (LOWEST | BELOW_NORMAL | NORMAL | ABOVE_NORMAL | HIGHEST).
     \param snapshot  [in]: snapshot parameter (NONE | BACKGROUND | FOREGROUND).
     \param runString  [in]: run string parameter.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus runCommand(const char *serverName, const char *termination, const char *notification, const char *supervision, const char *priority, const char *snapshot, const char *runString);
 /**
     \par Description:
     this function returns information on process which is starting of ScsEnvTable.
     \param processName  [out]: name of process which is starting.
     \param phase  [out]: phase of process which is starting.
     \param nbprocesstostart  [out]: number of process on starting in ScsEnvTable.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus startProcessInfo(char *&processName, int &phase, int &nbprocesstostart);
  /**
     \par Description:
     this function returns informations on n processes of ScsEnvTable.
     \param infos  [out]: char* matrix (12xn) with \em i varying from \em 0 to \em nbprocess-1 :
     \li infos[0][i] : name of process
     \li infos[1][i] : state of process (SCS_UP | SCS_INIT | SCS_DOWN...)
     \li infos[2][i] : phase of process
     \li infos[3][i] : termination of process (NONE | SHUTDOWN | RETRY)
     \li infos[4][i] : notification of process (YES | NO)
     \li infos[5][i] : shutdown order of process
     \li infos[6][i] : supervision type of process (NONE | CORBA | UNIX | RTAP | PUSH)
     \li infos[7][i] : priority of process (LOWEST | BELOW_NORMAL | NORMAL | ABOVE_NORMAL | HIGHEST)
     \li infos[8][i] : run string of process
     \li infos[9][i] : snapshot of process (NONE | BACKGROUND | FOREGROUND)
     \li infos[10][i] : init timeout of process
     \li infos[11][i] : pid of process (? | pid)
     \param nbprocess  [out]: number of process in ScsEnvTable
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus getProcessInfos(char *** &infos, int &nbprocess);
  /**
     \par Description:
     this function shutdown local environment.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
    */
  ScsStatus shutdown();
  /**
     \par Description:
     this function request a snapshot of the environment. All the output files will be located under the root pathname.
     \param path  [in]: pathname of the snapshots root directory. The directory must exist and be writable.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : error.
     \li \c AscORBError : error in orb communication.
     \li \c AscSnapshotInProgress : A snapshot already had been requested.
     \li \c AscWrongState : The environment is not ready to do a snapshot.
    */
  ScsStatus forceEnvironmentSnapshot(const char* path);
  //@}

  struct ASC_API StateNotificationArg {
    AgtSupervisionCallback  _callback;
    void                   *_arg;

    StateNotificationArg() { _callback = 0; _arg = 0;}
  };

private:
   
  ScsStatus             _status;
  AscAgentIdl          *_agent;
  OlsPhysicalServer    *_processServ;
  StateNotificationArg  _stateNotificationArg;   
};

#endif
