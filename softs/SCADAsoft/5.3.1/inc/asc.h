/******************************************************************************/
/*									      */
/*  FILE		: asc.h                                               */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES-IS					      */
/*  CREATION DATE	: 1997/09/30					      */
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
// $Id: asc.h,v 1.5 1999/04/08 15:25:42 ylo Exp $
//
// HISTORY:
// $Log: asc.h,v $
// Revision 1.5  1999/04/08 15:25:42  ylo
// Modify trace mode to configure output file/pipe name.
//
// Revision 1.4  1999/01/20 10:13:14  ylo
// Background snapshot integration.
//
// Revision 1.3  1999/01/14 16:47:11  ylo
// Background snapshot integration.
//
// Revision 1.2  1999/01/12 10:29:46  ylo
// Snapshot management.
//
// Revision 1.1  1998/12/07 13:43:32  ylo
// Initial revision
//
//
/******************************************************************************/
#ifndef _ASC_H_
#define _ASC_H_

/** \file
 * \brief Supervision of the processes of the current environment, when no redundancy is used.
 */

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/
#include "scs.h"

extern ASC_API const int SCS_DISCONNECTED;
extern ASC_API const int SCS_CONNECTED;
extern ASC_API const int SCS_TIMEOUT;

#define AscTrace	ScsTraceFunction(ASC_SCSMODULE)
#define AscTraceLevel(level, message)  BaseTraceLevel(ASC_SCSMODULE, level, message)

class DbkAddressId;
class ScsAddress;

/**
\code#include "asc.h"\endcode
   Prototype of the AscServer notification callback function.
   \param logicalEnv  [in]: name of the SCADAsoft logical environment in which the server is running,
   \param serverName  [in]: server name,
   \param connectionState  [in]:
   \param state  [in]:
   \param arg  [in]: optional user argument passed as parameter of the <em>suscribeState()</em> method and returned back to the callback function when called.
   \par Return values:
     none.
*/
typedef void (*AscCallback)(const char* logicalEnv,
			    const char* serverName,
			    int         connectionState,
			    const char* state,
			    ScsAny      arg);

/**
\code#include "asc.h"\endcode
   Prototype of the AscServer snapshot callback function.
   \param path  [in]: pathname to the directory where the snapshot files will be written,
   \param arg  [in]: optional user argument passed as parameter of the <em>registerForegroundSnapshot()</em> or <em>registerBackgroundSnapshot()</em> method and returned back to the callback function when called.
   \par Return values:
     status of the operation.
*/
typedef ScsStatus (*SnapshotFunction)(const char *path, ScsAny arg);

/**
\code#include "asc.h"\endcode
   Prototype of the AscServer callback function that is triggered when the snapshot ends.
   \param path  [in]: return status of the snapshot,
   \param arg  [in]: optional user argument passed as parameter of the <em>registerEndSnapshot()</em> method and returned back to the callback function when called.
   \par Return values:
     status of the operation.
*/
typedef ScsStatus (*EndSnapshotFunction)(const ScsStatus& snapshotStatus, ScsAny arg);

//**** 
//**** JPU (29/4/04): "Pourquoi le commentaire doxygen de ce typedef est-il en commentaire ?" 
//****
///**
//\code#include "asc.h"\endcode
//   Prototype of the AscServer event callback function.
//   \param addressId  [in]: addressId of the point where the formula SEND_EVENT is applied,
//   \param scsAddress [in]: scsAddress of the point,
//   \param msg  [in]: parameter message of the formula SEND_EVENT,
//   \param arg  [in]: optional user argument passed as parameter of the <em>registerEvenetCallback()</em> method and returned back to the callback function when called.
//   \par Return values:
//   status of the operation.
//*/
typedef ScsStatus (*EventAscFunction)(int addrIdPart1,
				      int addrIdPart2,
				      const ScsAddress& scsAddress, 
				      const char *msg, 
				      const char* serverName,
				      ScsAny arg);

/**
   \brief Abstract class for managing current process state.

   This class must be inherited if the current process wants a more precise state handling (i.e. something more complicate than process running or down).
\code#include "asc.h"\endcode
*/
class ASC_API AscStateMgr
{
public:
  virtual ~AscStateMgr() {}
  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     this method is called when a remote process wants to know the state of the current process.
     \par Parameters:
     none.
     \par Return values:
     the current process state.
  */
  virtual const char* getState() = 0;
  /**
     \par Description:
     this method is called when a remote process (here the supervisor) wants to set the state of the current process.
     \param state  [in]: new state.
     \par Return values:
     none.
  */
  virtual void setState(const char* state) = 0;
  //@}
};

/**
   \brief This class is the interface class for the exported services of the <em>ASC</em> SCADAsoft component (Application Supervisory and Control).

   This class is used for the supervision of the processes of the current environment, when no redundancy is used.
\code#include "asc.h"\endcode
*/
class ASC_API AscServer
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function is called with an <em>AscStateMgr</em> argument if the application wants to change its state diagram. The call to this constructor changes the state of current process from &quot;<em>SCS_INIT</em>&quot; to &quot;<em>SCS_UP</em>&quot;.
     \param stateMgr  [in]: state manager object.
     \par Return values:
     none.
  */
  AscServer(AscStateMgr* stateMgr = 0);
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     This function changes the current application.
     \param state  [in]: new state.
    */
  void setState(const char * state);
  
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
     this function allows to activate up the traces for user modules and levels of the remote <em>processName</em> application running in the <em>physicalEnv</em> physical environment. The <em>moduleMask</em> parameter is a 32 bits mask defining for which user module(s) the traces are activated (each user component is associated with a module number) and <em>levelMask</em> is the 32 bits mask defining the level(s) for which the traces are activated.
     \param physicalEnv  [in]: physical environment name,
     \param processName  [in]: process name,
     \param moduleMask  [in]: user module mask,
     \param levelMask  [in]: trace level mask.
     \return
     \li \c ScsValid : success.
     \li \c AscUnknownEnvironmentError : the <em>physicalEnv</em> environment is unknown,
     \li \c AscInactiveServerError : the server is not active,
     \li \c AscBadServerNameError : the server is unknown (no environment specified). 
     \li \c AscORBError : error in orb communication.
  */
  ScsStatus setUserTrace(const char *physicalEnv,
			 const char *processName, 
			 int         moduleMask,
			 int         levelMask);
  /**
     \par Description:
     this function allows to activate up the traces for SCADAsoft modules and levels of the remote <em>processName</em> application running in the <em>physicalEnv</em> physical environment. The <em>moduleMask</em> parameter is a 32 bits mask defining for which SCADAsoft module(s) the traces are activated (each SCADAsoft component is associated with a module number) and <em>levelMask</em> is the 32 bits mask defining the level(s) for which the traces are activated.
     \param physicalEnv  [in]: physical environment name,
     \param processName  [in]: process name,
     \param moduleMask  [in]: SCADAsoft module mask,
     \param levelMask  [in]: trace level mask.
     \return
     \li \c ScsValid : success.
     \li \c AscUnknownEnvironmentError : the <em>physicalEnv</em> environment is unknown,
     \li \c AscInactiveServerError : the server is not active,
     \li \c AscBadServerNameError : the server is unknown (no environment specified). 
     \li \c AscORBError : error in orb communication.
  */
  ScsStatus setTrace(const char *physicalEnv,
		     const char *processName, 
		     int         moduleMask,
		     int         levelMask);
  /**
     \par Description:
     this method changes the trace mode of the <em>processN</em> remote application running in the <em>physicalEnv</em> physical environment. &quot;<em>ScsCOUT</em>&quot; means that traces are redirected through the standard ouput of the application, whereas &quot;<em>ScsCLOG</em>&quot; means that traces are redirected in a log file named <em>outputFile</em> (pathname of the log file).
     \param physicalEnv  [in]: physical environment name,
     \param processName  [in]: process name,
     \param outputMode  [in]: the type of trace output,
     \param outputFile  [in]: pathname of log file.
     \return
     \li \c ScsValid : success.
     \li \c AscUnknownEnvironmentError : the <em>physicalEnv</em> environment is unknown,
     \li \c AscInactiveServerError : the server is not active,
     \li \c AscORBError : error in orb communication.
  */
  ScsStatus setTraceOutput(const char   *physicalEnv,
			   const char   *processName, 
			   ScsTraceMode  outputMode,
			   const char   *outputFile);
  /**
     \par Description:
     this function registers the user routine function to be called by the <em>AscServer</em> when foreground snapshot occurs.
     \param snapshotCallback  [in]: foreground snapshot callback function,
     \param arg  [in]: optional user argument returned back to the foreground snapshot callback function when called.
     \par Return values:
     none.
  */
  void registerForegroundSnapshot(SnapshotFunction snapshotCallback, ScsAny arg);
  /**
     \par Description:
     this function registers the user routine function to be called by the <em>AscServer</em> when background snapshot occurs.
     \param function  [in]: background snapshot callback function,
     \param arg  [in]: optional user argument returned back to the background snapshot callback function when called.
     \par Return values:
     none.
  */
  void registerBackgroundSnapshot(SnapshotFunction function, ScsAny arg);
  /**
     \par Description:
     this function registers the user routine function to be called by the <em>AscServer</em> when the snapshot ends.
     \param function  [in]: 'end snapshot' callback function,
     \param arg  [in]: optional user argument returned back to the 'end snapshot' callback function when called.
     \par Return values:
     none.
  */
  void registerEndSnapshot(EndSnapshotFunction function, ScsAny arg);
  /**
     \par Description:
     this function sends an &quot;<em>endBackgroundSnapshot</em>&quot; message to the agent. This function must be called by the application to notify the agent about the termination of its background snapshot part.
     \param snapshotStatus  [in]: return the status of the background snapshot.
     \par Return values:
     none.
  */
  void endBackgroundSnapshot(const ScsStatus& snapshotStatus = ScsValid);

  //  /**
  //     \par Description:
  //     this function registers the user routine function to be called by the <em>AscServer</em> when an event occurs.
  //     \param eventCallback  [in]: event callback function,
  //     \param arg  [in]: optional user argument returned back to the event callback function when called.
  //     \par Return values:
  //     none.
  //  */
  void registerEventAscCallback(EventAscFunction eventCallback, ScsAny arg = NULL);

  void sendEvent(int addrIdPart1, 
		 int addrIdPart2, 
		 const ScsAddress& scsAddress, 
		 const char* msg, 
		 const char* serverName);

  void sendAsyncEvent(int addrIdPart1, 
		      int addrIdPart2, 
		      const ScsAddress& scsAddress, 
		      const char* msg, 
		      const char* serverName);

  //@}

  ScsStatus dump(const char *environment, const char *name);

protected:
  static ScsStatus  _initStatus;
};

#endif
