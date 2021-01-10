/******************************************************************************/
/*									      */
/*  FILE		: scs.h                                               */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
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
// $Id: scs.h,v 1.16 2000/02/10 12:33:26 hot Exp $
//
// HISTORY:
// $Log: scs.h,v $
// Revision 1.16  2000/02/10 12:33:26  hot
// Change Mainloop arguments (ScsInitFunction to ScsApplicativeInitFunction
// Add to ScsData the bit string management
//
// Revision 1.15  2000/02/09 07:19:51  jmb
// Add GetNbPhysEnvRunning() method
//
// Revision 1.14  1999/11/24 19:10:07  scadaref
// Port on MSVC6
//
// Revision 1.13  1999/10/25 10:35:48  ylo
// add ScsData compareTo method
//
// Revision 1.12  1999/10/25 09:13:38  pierre
// add ScsData operator <.
//
// Revision 1.11  1999/08/17 12:06:11  scadaref
// Port on aCC
//
// Revision 1.10  1999/08/05 12:32:17  ylo
// Add mainloop with callback argument.
//
// Revision 1.9  1999/06/16 15:52:18  ylo
// Add ScsUserTraceFunction.
//
// Revision 1.8  1999/06/08 11:23:54  ylo
// Add user trace.
//
// Revision 1.7  1999/04/28 08:27:52  jmb
// Add print function
//
// Revision 1.6  1999/04/16 10:12:36  scadaref
// bug in ScsData cast operator.
//
// Revision 1.5  1999/04/15 17:06:31  scadaref
// add ScsData operator ==.
//
// Revision 1.4  1999/04/15 14:48:11  scadaref
// add the ScsPOINTER type.
//
// Revision 1.3  1999/04/08 15:24:27  ylo
// Modify trace mode to configure output file/pipe name.
//
// Revision 1.2  1999/01/29 10:16:17  ylo
// add Scadasoft::GetServerName().
//
// Revision 1.2  1999/01/15 17:21:44  bertrand
// add Scadasoft::GetServerName().
//
// Revision 1.1  1998/12/07 13:39:21  ylo
// Initial revision
//
//
/******************************************************************************/
#ifndef _SCS_H
#define _SCS_H

/** \file
    \brief General Purpose ScadaSoft Utilities
*/

//{begin internal}
#ifndef WIN32

#include <unistd.h>
#include <stdlib.h>

#else

#if _MSC_VER > 1200
#include <winsock2.h>
#endif
#include <windows.h>

#endif

#include "scsdefs.h"

#ifndef RWSTD_HEADER_REQUIRES_HPP
#include <string>
#else
#include <string.hpp>
#endif

#include "scsdata.h"
#include "scsaddress.h"
#include "scadaorbdefs.h"
//{end internal}

/**
\code#include "scs.h"\endcode
   \par Description:
     enum represents the type of trace output (see <em>Scadasoft::SetTraceOutput()</em>). The possible values are the following :
   \code
   enum ScsTraceMode {
     ScsCOUT = 0,
     ScsCLOG = 1
   }; \endcode
   \par Values:
   \li \c ScsCOUT:  the traces are redirected to the standard output,
   \li \c ScsLOG:  the traces are redirected to a log file.
*/
enum ScsTraceMode {
  ScsCOUT = 0,
  ScsCLOG = 1
};


namespace CORBA {
class SystemException;
}
extern SCS_API SCS_SL_STD(string) ScsGetOrbExceptionText(CORBA::SystemException& sysEx);

/**
   Prototype of the applicative init function which is called at the end of <em>Scadasoft::Initialize()</em>.
\code#include "scs.h"\endcode
*/
typedef ScsStatus (*ScsInitFunction)();

/**
   Prototype of the applicative init function which could be called in the <em>Scadasoft::MainLoop()</em> just before entering infinite event loop.
\code#include "scs.h"\endcode
*/
typedef void (*ScsApplicativeInitFunction)(ScsAny);

/**
   Prototype of the function which is called by <em>Scadasoft::NewThread()</em>.
\code#include "scs.h"\endcode
*/
typedef ScsAny (*ScsThreadFunction)(ScsAny);

/**
   Prototype of the function which is called by the SCADAsoft mainloop when data is received on a file descriptor.
\code#include "scs.h"\endcode
*/
typedef void (*ScsFDFunction)(int, ScsAny);

class ScsShmPage;
class ScsShmPage2;

/**
   \brief This class is the main class of SCADAsoft.

   The class <em>Scadasoft</em> contains general functions relative to the SCADAsoft initialization, the mainloop, the management of traces, the info concerning the time, the current process or the redundancy.
\code#include "scs.h"\endcode
*/
class SCS_API Scadasoft
{
public:
  /**@name Typedefs / defines*/
  //@{
  /**
     \par Description:
     enum corresponding to the possible values of redundancy type.
     \code
     enum RedundancyType { 
       SCS_NO_REDUNDANCY = 0,
       SCS_SYNCHRONOUS_REDUNDANCY,
       SCS_ASYNCHRONOUS_REDUNDANCY,
       SCS_COLD_REDUNDANCY
     }; \endcode
     \par Values:
     \li \c SCS_NO_REDUNDANCY:  no redundancy,
     \li \c SCS_SYNCHRONOUS_REDUNDANCY:  synchronous redundancy (default type for redundancy),
     \li \c SCS_ASYNCHRONOUS_REDUNDANCY:  asynchronous redundancy (one online server and one standby server running simultaneously, but no synchronisation using <em>InputManager</em>),
     \li \c SCS_COLD_REDUNDANCY:  cold redundancy (only one online server running).
  */
  enum RedundancyType { 
    SCS_NO_REDUNDANCY = 0,
    SCS_SYNCHRONOUS_REDUNDANCY,
    SCS_ASYNCHRONOUS_REDUNDANCY,
    SCS_COLD_REDUNDANCY
  };
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     this method is the SCADAsoft initialization method. It must be called at the beginning of each program using the SCADAsoft library, <b>before calling any other SCADAsoft function</b>. It initializes the server name and environment used by any process in every communication with the current process. If the current process is started by the <em>ascmanager</em> SCADAsoft process, the name of the physical environment is passed in parameter using a &quot;<em>-e</em>&quot; starting option.
     \param physicalEnv  [in]: the physical environment name, 
     \param serverName  [in]: the server name. 
     \return
     \li \c ScsValid : success.
     \li \c ScsEnvironmentError : if <em>SCSHOME</em> or <em>SCSPATH</em> environnement variable is not defined.
     \li \c ScsORBError : if the ORB daemon is not running on the local machine.
  */
  static ScsStatus Initialize(const char *physicalEnv, const char *serverName);
  /**
     \par Description:
     this method releases the resources allocated by SCADAsoft. It shall be invoked just before returning from the main procedure.
  */
  static void Finalize();
  /**
     \par Description:
     this method return the local host.
     \par Parameters:
     none.
     \return
     \li \c Host : local host.
  */
  static const char *GetHost(); 
  /**
     \par Description:
     this method returns the current physical environment name.
     \par Parameters:
     none.
     \par Return values:
     the current physical environment name.
  */
  static const char *GetEnv();
  /**
     \par Description:
     this method returns the current logical environment name.
     \par Parameters:
     none.
     \par Return values:
     the current logical environment name.
  */
  static const char *GetLogicalEnvironment();
  /**
     \par Description:
     this method returns the current server name.
     \par Parameters:
     none.
     \par Return values:
     the current server name.
  */
  static const char *GetServerName();
  /**
     \par Description:
     this method return the current state of SCADAsoft local environment.
     \par Parameters:
     none.
     \return
     \li \c State : current state.
  */
  static const char *GetState(); 
  /**
     \par Description:
     this method registers an applicative initialization function to be called by SCADAsoft at the end of <em>Scadasoft::Initialize()</em>.
     \param function  [in]: the init function .
     \return
     \li \c ScsValid : success.
  */
  static ScsStatus AddInitFunction(ScsInitFunction function);
  /**
     \par Description:
     this method adds the <em>fd</em> file descriptor to the set of file descriptors to be looked at. If some data arrives on this file descriptor, the function specified by the <em>function</em> parameter is called with argument <em>arg</em> (argument is optional). This method should absolutely be called before calling <em>Scadasoft::MainLoop()</em>}.
     \param fd  [in]: file descriptor to add,
     \param function  [in]: function to call,
     \param arg  [in]: function argument.
     \return
     \li \c ScsValid : success.
  */
  static ScsStatus AddFDFunction(int fd, ScsFDFunction function, ScsAny arg = 0);
  /**
     \par Description:
     this method inserts the <em>fd</em> file descriptor to the set of file descriptors to be looked at after the process has entered the SCADAsoft mainloop. If some data arrives on this file descriptor, the function specified by the <em>function</em> parameter is called with argument <em>arg</em> (argument is optional).
     \param fd  [in]: file descriptor to insert,
     \param function  [in]: function to call,
     \param arg  [in]: function argument.
     \return
     \li \c ScsValid : success.
  */
  static ScsStatus InsertFDFunction(int fd, ScsFDFunction function, ScsAny arg = 0);
  /**
     \par Description:
     this method removes the <em>fd</em> file descriptor from the set of file descriptors to be looked at.
     \param fd  [in]: file descriptor to remove.
     \return
     \li \c ScsValid : success.
  */
  static ScsStatus RemoveFDFunction(int fd);
  /**
     \par Description:
     this method suspends the current thread for the specified period in milliseconds. If the process is not multi-threaded, it suspends the whole process.
     \param millisec  [in]: sleeping period value.
     \return
     \li \c ScsValid : success.
  */
  static ScsStatus Sleep(unsigned int millisec);
  /**
     \par Description:
     this method allows to activate up the traces for user modules and levels. The <em>moduleMask</em> parameter is a 32 bits mask defining for which user module(s) the traces are activated (each user component is associated with a module number) and <em>levelMask</em> is the 32 bits mask defining the level(s) for which the traces are activated.
     To produce a trace using SCADAsoft, a macro should be defined for each component in a common include file. For example, for the <em>Ccc</em> component :
\code   #define CccTrace ScsTraceFunction(module) \endcode
     where <em>module</em> is the module number (between 0 and 31) associated with the component. This <em>CccTrace</em> macro is called in the source code in the following way :
\code   CccTrace(SCS_LEVEL(level), format [, arguments]); \endcode
     where <em>level</em> is the level of the trace (between 0 and 31), <em>format</em> is the output format string (as for the <em>printf()</em> C standard library function) and <em>arguments</em> optional arguments corresponding to the output format string. For example :
\code   CccTrace(SCS_LEVEL(3), "Activation of timer %d(%s)", timerId, timerStr); \endcode
     \param moduleMask  [in]: user module mask,
     \param levelMask  [in]: level mask.
     \return
     \li \c ScsValid : success.
  */
  static ScsStatus SetUserTrace(int moduleMask, int levelMask);
  /**
     \par Description:
     this method changes the trace output. If <em>mode</em> parameter is set to <em>ScsCLOG</em>.
     \param outputMode  [in]: the type of trace output,
     \param outputFile  [in]: pathname of log file.
     \return
     \li \c ScsValid : success.
  */
  static ScsStatus SetTraceOutput(ScsTraceMode outputMode, const char *outputFile = 0);
  /**
     \par Description:
     this method returns the system time.
     \par Parameters:
     none.
     \par Return values:
     a timeval structure containing the system time.
  */
  static timeval GetOSTime();
  /**
     \par Description:
     this method returns the SCADAsoft time. This time is a simulated time and should absolutely be used rather than the system time in a process using the SCADAsoft redundancy.
     \par Parameters:
     none.
     \par Return values:
     a timeval structure containing the SCADAsoft time.
  */
  static timeval GetTime();
 /**
     \par Description:
     this method returns the current ORB timeout, in milliseconds, for all remote calls.
     \par Parameters:
     none.
     \par Return values:
     ORB timeout.
  */
  static unsigned int GetORBTimeout();
 /**
     \par Description:
     this method change the ORB timeout, in milliseconds, for all remote calls.
     \param timeout  [in]: ORB timeout in milliseconds.
     \return
     \li \c ScsValid : success.
  */ 
  static ScsStatus SetORBTimeout(unsigned int timeout);
 /**
     \par Description:
     this method unset the ORB timeout to the default ORB timeout for all remote calls.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
  */ 
  static ScsStatus UnSetORBTimeout();
  /**
     \par Description:
     this method return the ORB infinite timeout constant.
     \par Parameters:
     none.
     \par Return values:
     ORB infinite timeout constant.
  */ 
  static unsigned int INFINITE_TIMEOUT();
  /**
     \par Description:
     this method must be called after process initialization. It calls asynchronously the callbacks specified in the initialization phase and starts an infinite event loop.
     \param function  [in]: applicative init function called just before entering the infinite event loop,
     \param arg  [in]: optional argument passed to the init function.
     \return
     \li \c ScsValid : success.
     \li \c ScsORBError : an error occurred calling an ORB function.
  */
  static ScsStatus MainLoop(ScsApplicativeInitFunction function = 0, ScsAny arg = 0);
  /**
     \par Description:
     this method exit of the SCADASoft main loop but not the current process.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  static void Exit();
 /**
     \par Description:
     this method returns the current SCADASoft version.
     \par Parameters:
     none.
     \par Return values:
     the current SCADASoft version.
  */
  static const char *GetVersion();
  /**
     \par Description:
     this method return 1 if the current environment is redondant (synchronous, asynchronous or cold).
     \param redundancyType  [in]:  specifies the type of redundancy to test synchronous, by default).
     \par Return values:
     1 if the environment is redundant and the redundancy type is the specified one, 0 otherwise.
  */
  static int IsRedundant(RedundancyType redundancyType = SCS_SYNCHRONOUS_REDUNDANCY);

  /**
     \par Description:
     this method return 1 if the current environment use emulated time.
     \par Return values:
     1 if the environment use the emulated time, 0 otherwise.
  */
  static int UseEmulatedTime();

  /**
     \par Description:
     this method freezes or unfreezes the current environment in training mode.
     \par Return values:
     None.
  */
  static void Freeze(int pFrozen);

  /**
     \par Description:
     this method returns 1 if the current environment is frozen in training mode, 0 otherwise.
     \par Return values:
     1 if the environment is frozen, 0 otherwise.
  */
  static int IsFrozen();

  /**
     \par Description:
     this method returns 1 if the current environment is in training mode, 0 otherwise.
     \par Return values:
     1 if the environment is in training mode, 0 otherwise.
  */
  static int IsInTrainingMode();
  //@}

  /* No more documented...
     \par Description:
     this method creates a new thread which runs the start routine specified by the <em>function</em> parameter. This is a way to handle multiple inputs in the same process. The size of the writable area of the stack for the thread is ajusted to the value of the optional <em>stackSize</em> parameter (in bytes). If this parameter is ommited, the default machine stack size is used.
     \param function  [in]: the start routine,
     \param arg  [in]: address value copied and passed to the thread's start routine,
     \param stackSize  [in]: stack size.
     \return
     \li \c ScsValid : success.
     \li \c ScsUnixError : an error occurred calling an Unix system function.
  */
  static ScsStatus NewThread(ScsThreadFunction function,
			     ScsAny arg,
			     int stackSize = 0);
  /* No more documented...
     \par Description:
     this method is used when having a multi threaded process in order to avoid access conflict between thread. This is a general mutex at the process level.
     \param sig  [in]: (????).
     \return
     \li \c ScsValid : success.
  */
  static ScsStatus GetToken(int sig = 0);
  /* No more documented...
     \par Description:
     this method is used to releases the mutex in a multi-threaded process.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
  */
  static ScsStatus ReleaseToken();
  /* No more documented...
     \par Description:
     this method registers a function to be called in case the <em>sig</em> parameter of <em>Scadasoft::GetToken()</em> function is set to non zero.
     \param function  [in]: signal function.
     \return
     \li \c ScsValid : success.
  */
  static ScsStatus SendSignal(ScsInitFunction function);
  /* No more documented...
     \par Description:
     this method redefine a trace level.
     \param moduleMask  [in]: module trace mask,
     \param {\elevelMask}  [in]: level trace mask.
     \return
     \li \c ScsValid : success.
  */
  static ScsStatus SetTrace(int moduleMask, int levelMask);
  /* No more documented...
     \par Description:
     this method redefine a module trace mask.
     \param moduleMask  [in]: module trace mask.
     \return
     \li \c ScsValid : success.
  */
  static ScsStatus SetModule(int module);
  /* No more documented...
     \par Description:
     this method return 1 if a level trace mask is running.
     \param moduleMask  [in]: level trace mask.
     \return
     \li \c 1 : level trace running.
  */
  static int IsEnable(int level);
  /* No more documented...
     \par Description:
     this method return 1 if a level trace mask is running for a particular module.
     \param module  [in]: module to be tested.
     \param level  [in]: level trace mask.
     \return
     \li \c 1 : level trace running.
  */
  static int IsModuleEnable(int module, int level);
  /* No more documented...
     \par Description:
     this method return the number of physical environment are running.
     \par Parameters:
     none.
     \return
     \li \c NbPhysEnvRunning : number of physical environment running.
  */
  static int GetNbPhysEnvRunning();
  /* No more documented...
     \par Description:
     this method set the default ORB timeout for all remote calls.
     \param timeout  [in]: ORB timeout in milliseconds.
     \return
     \li \c ScsValid : success.
  */ 
  static ScsStatus SetORBDefaultTimeout(unsigned int timeout);

private:
  static void SetTime(const timeval &currentTime);
  static void SetState(const char* state);

  static char       *_environment;
  static char       *_serverName;
  static ScsShmPage *_sharedMemory;
  static ScsShmPage2 *_sharedMemory2;  

  friend class AscMgrState;
  friend class InputMgr_i;
  friend class ScsWatchdog_i;
  friend class AscData;
  friend class LocalEnvDiag;
  friend class LocalPhysEnv;
  friend class AscEnvManager;
  friend class RplReplayMgrIdl_i;
  friend class RplReplayAgentClient_i;

  /**
   * Default constructor is private and not implemented.
   */
  Scadasoft();
  
  /**
   * Copy constructor is private and not implemented.
   */
  Scadasoft(const Scadasoft&);
  
  /**
   * Assigment operator is private and not implemented.
   */
  Scadasoft& operator=(const Scadasoft&);
  
public:  
  /**
   * Timekeeper frequency :  only used by SCADAsoft timer to compute next wake up time.
   */

  static int GetTimekeeperFrequency();
  
};

// Trace handling
#include "scstrace.h"

// useful tools
#include "scstools.h"

#endif
