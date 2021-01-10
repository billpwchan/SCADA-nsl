//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : tsctypes.h                                             */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Mon May 05 16:43:43 2003                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/
// IDENTIFICATION:
// $Id: $
//
// HISTORY:
// $Log: $


#ifndef _TSCTYPES_H_
#define _TSCTYPES_H_

/**
  \file
  \brief classes, typedefs and functions used in Tsc context
*/

#include "ctlcmd.h"
#include "ctlgrc.h"

#define TSC_TASKTYPE_FMT "##%02d##"
#define TSC_TASKSTRING_HEAD "Task="
#define TSC_TASKSTRING_SEP  ";"

/** 
\code#include "tsctypes.h"\endcode
    \par Description:
    enum corresponding to the task type.
    \code
    enum TscTaskType {
    TSC_TASKTYPE_EXEC = 0,
    TSC_TASKTYPE_CMD,
    TSC_TASKTYPE_GRC,
    TSC_TASKTYPE_EVT,
    TSC_NB_TASKTYPE
    }; \endcode
    \par Values:
    \li \c TSC_TASKTYPE_EXEC: the task execute a command in background,           
    \li \c TSC_TASKTYPE_CMD:  the task call CtlCmdServer::sendMCommand in the local environment,           
    \li \c TSC_TASKTYPE_GRC:  the task call CtlGrcServer::launchGrc in the local environment,           
    \li \c TSC_TASKTYPE_EVT:  the task send an event to a process in the local environment, the process will execute the function registered by AscServer::registerEventAscCallback.
*/
enum TscTaskType {
  TSC_TASKTYPE_EXEC = 0,
  TSC_TASKTYPE_CMD,
  TSC_TASKTYPE_GRC,
  TSC_TASKTYPE_EVT,
  TSC_NB_TASKTYPE
};

/**
   \brief This class is the based class used to describe a task argument.

\code#include "tsctypes.h"\endcode
*/
class TSC_API TscTaskArg {
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor.
     \par Parameters:
     \param taskType  [in]: the task type.
     \par Return values:
     none.
  */
  TscTaskArg(TscTaskType taskType = TSC_NB_TASKTYPE):_taskType(taskType) {};

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  virtual ~TscTaskArg() {};
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>TscTaskArg</em> object into an output stream. 
     \param os  [in]: the output stream.
     \par Return values:
     none.
    */
  virtual void               save(SCS_SL_STD(ostream) & os);  

  /**
     \par Description:
     this function is used to restore an <em>TscTaskArg</em> object from an input stream.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  virtual ScsStatus          restore(SCS_SL_STD(istream) & is);
  //@}

  /**@name General member functions*/
  /**
     \par Description:
     this function returns the type of the argument.
     \par Parameters:
     none.
     \par Return values:
     the argument type.
  */
  TscTaskType getType() { return _taskType; };
  //@}

private:
  TscTaskType _taskType;
};

/**
   \brief This class describe a task argument for a EXEC task.

\code#include "tsctypes.h"\endcode
*/
class TSC_API TscTaskExecArg : public TscTaskArg
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor.
     \par Parameters:
     \param arguments  [in]: the task argument.
     \par Return values:
     none.
  */
  TscTaskExecArg(const char* arguments = NULL);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~TscTaskExecArg();
  //@}

  /**@name General member functions*/
  /**
     \par Description:
     this function returns the argument.
     \par Parameters:
     none
     \par Return values:
     the argument.
  */
  const char*        getArg() const { return _arg; };
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>TscTaskArg</em> object into an output stream. 
     \param os  [in]: the output stream.
     \par Return values:
     none.
    */
  void               save(SCS_SL_STD(ostream) & os);  

  /**
     \par Description:
     this function is used to restore an <em>TscTaskArg</em> object from an input stream.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  ScsStatus          restore(SCS_SL_STD(istream) & is);  
  //@}

private:
  char*              _arg;
};

/**
   \brief This class describe a task argument for a CMD task.

\code#include "tsctypes.h"\endcode
*/
class TSC_API TscTaskCmdArg : public TscTaskArg
{

public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor of a task argument to describe a CMD task (see CtlCmdServer::sendMCommand).
     \par Parameters:
     \param nbCmds  [in]: the numbers of commands.
     \param cmds    [in]: the arrays of commands.
     \param mode    [in]: the mode for sending commands.
     \par Return values:
     none.
  */
  TscTaskCmdArg(int nbCmds = 0, 
		CtlCmdCommand* cmds = NULL, 
		CtlCmdServer::ScsCtlMCmdMode mode = CtlCmdServer::ContinueOnFailed);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~TscTaskCmdArg();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     this function returns the number of commands.
     \par Parameters:
     none
     \par Return values:
     the number of commands.
  */

  int                getNbCommands() const { return _nbCmds; };
  /**
     \par Description:
     this function returns the array of commands.
     \par Parameters:
     none
     \par Return values:
     the number of commands.
  */

  CtlCmdCommand*     getCommands() const { return _cmds; };

  /**
     \par Description:
     this function returns the mode for sending commands.
     \par Parameters:
     none
     \par Return values:
     the mode for sending commands.
  */
  CtlCmdServer::ScsCtlMCmdMode     getMode() const { return _mode; };
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>TscTaskArg</em> object into an output stream. 
     \param os  [in]: the output stream.
     \par Return values:
     none.
    */
  void               save(SCS_SL_STD(ostream) & os);
  
  /**
     \par Description:
     this function is used to restore an <em>TscTaskArg</em> object from an input stream.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  ScsStatus          restore(SCS_SL_STD(istream) & is);  
  //@}


private:
  int                              _nbCmds;
  CtlCmdCommand*                   _cmds;
  CtlCmdServer::ScsCtlMCmdMode     _mode;

};
 
/**
   \brief This class describe a task argument for a GRC task.

\code#include "tsctypes.h"\endcode
*/
class TSC_API TscTaskGrcArg : public TscTaskArg
{

public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor of a task argument to describe a GRC task (see CtlGrcServer::launchGrc).
     \par Parameters:
     \param grcName    [in]: the name of the GRC.
     \param mode       [in]: the mode of the GRC to launch.
     \par Return values:
     none.
  */
  TscTaskGrcArg(const char* grcName = NULL, 
		CtlGrc::ScsCtlGrcMode mode = CtlGrc::Auto);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~TscTaskGrcArg();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     this function returns the name of the GRC to launch.
     \par Parameters:
     none
     \par Return values:
     the name of the GRC to launch.
  */
  const char*               getGrcName() const { return _grcName; };       

  /**
     \par Description:
     this function returns the mode of the GRC to launch.
     \par Parameters:
     none
     \par Return values:
     the mode of the GRC to launch.
  */
  CtlGrc::ScsCtlGrcMode     getMode() const { return _mode; };
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>TscTaskArg</em> object into an output stream. 
     \param os  [in]: the output stream.
     \par Return values:
     none.
    */
  void               save(SCS_SL_STD(ostream) & os);  

  /**
     \par Description:
     this function is used to restore an <em>TscTaskArg</em> object from an input stream.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  ScsStatus          restore(SCS_SL_STD(istream) & is); 
  //@} 

private:
  char*                     _grcName;
  CtlGrc::ScsCtlGrcMode     _mode;

};

/**
   \brief This class describe a task argument for a EVT task.

\code#include "tsctypes.h"\endcode
*/
class TSC_API TscTaskEvtArg : public TscTaskArg
{

public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor of a task argument to describe a EVT task (see AscServer::registerEventAscCallback).
     \par Parameters:
     \param procName    [in]: the name of the process to call.
     \param event       [in]: the message to send.
     \param syncEvent   [in]: 0 for an asynchronous call, not 0 for a syncrhonous call.
     \par Return values:
     none.
  */
  TscTaskEvtArg(const char* procName = NULL, 
		const char* event = NULL,
		int   syncEvent = 1);

  ~TscTaskEvtArg();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     this function returns the name of the process to call.
     \par Parameters:
     none
     \par Return values:
     the name of the process to call.
  */
  const char*               getProcName() const { return _procName; };       

  /**
     \par Description:
     this function returns the event to send.
     \par Parameters:
     none
     \par Return values:
     the event to send.
  */
  const char*               getEvent() const { return _event; };       

  /**
     \par Description:
     this function returns if the call have to be synchronous.
     \par Parameters:
     none
     \par Return values:
     return 1 if the call have to be synchronous.
  */
  int                       isSyncEvent() const { return (_syncEvent != 0); };

  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the <em>TscTaskArg</em> object into an output stream. 
     \param os  [in]: the output stream.
     \par Return values:
     none.
    */
  void               save(SCS_SL_STD(ostream) & os);  

  /**
     \par Description:
     this function is used to restore an <em>TscTaskArg</em> object from an input stream.
     \param is  [in]: the input stream.
     \par Return values:
     none.
    */
  ScsStatus          restore(SCS_SL_STD(istream) & is);  
  //@}

private:
  char*                     _procName;
  char*                     _event;
  int                       _syncEvent;
};

#endif
