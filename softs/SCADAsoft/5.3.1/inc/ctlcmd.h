/******************************************************************************/
/*									      */
/*  FILE		: ctlcmd.h                                            */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 1999/11/26					      */
/*  LANGUAGE		: C++						      */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW								      */
/*	Definition of C++ class CtlCmdServer providing ORB client access    */
/*	to the CTLCMD component server (process ctlcmdpro).                   */
/*	An object of such a class must be built be the client process in      */
/*	order to access services to this component .                          */
/*	This file is included by the file "ctlcefunc.h", which is itself      */
/*	included by C compiled source files. So, the parts of the current     */
/*	file which are not useful for this "ctlcefunc.h" file are enclosed   */
/*	by "#ifdef __cplusplus" and "#endif" preprocessor directives.         */ 
/*............................................................................*/
/*  CONTENTS								      */
/******************************************************************************/
/* IDENTIFICATION:							      */
/* $Id: ctlcmd.h,v 1.2 2000/02/28 14:15:46 jpu Exp jpu $ */
/* 									      */
/* HISTORY: 								      */
/* $Log: ctlcmd.h,v $
 * Revision 1.2  2000/02/28 14:15:46  jpu
 * Add environment argument in prototype of CtlCmdReturnCallback function
 *
 * Revision 1.1  2000/01/31 10:19:58  jpu
 * Initial revision
 * */
/******************************************************************************/
#ifndef _CTLCMD_H
#define _CTLCMD_H

#ifdef __cplusplus

/** \file
 * \brief Supplies ORB client access to the CTLCMD component server.
 */

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/
#include "scs.h"
#include "manager.h"

// Definition of CTL module trace function
#define CtlTrace	ScsTraceFunction(CTL_SCSMODULE)

#endif /* __cplusplus */

/**
   Max length for the name of an internal output variable (IOV).
\code#include "ctlcmd.h"\endcode
\code#define CTL_K_MAXLEN_IOV_NAME   256\endcode
   Format : equipement alias + internal output variable point name.
*/
#define CTL_K_MAXLEN_IOV_NAME		256

/**
   Max length for the value of a structured internal output variable (SIOV).
\code#include "ctlcmd.h"\endcode
\code#define CTL_K_MAX_SIOV_VALUE_SIZE   512\endcode
   A structured internal output variable is stored as a buffer of bytes. The current define is the maximum size of this buffer. Contents of such a buffer may be miscellaneous and is not checked: the structure is conventionnal between the field device and the concerned application program.
*/
#define CTL_K_MAX_SIOV_VALUE_SIZE	512


#ifdef __cplusplus

/**
   Prototype of the command execution return callback function.
\code#include "ctlcmd.h"\endcode
   \par Description:
     this function is a function of the client application called by the CTLCMD server to asynchronously notify the client of the result of a command execution. This callback function is called only one time to notify of the execution result of an individual command or of the list of commands. In the case of a commands list, the callback function is called as soon as one command has failed or when all the commands succeed.
   \param environment  [in]: name of the logical environment in which the CTLCMD server is running. 
   \param commandName  [in]: name of the command. When an individual command has been sent, this name is the name of the command. When a list of commands has been sent, this name is the name of the last command of the list when all of the commands succeed, or the name of the first command which has failed.  
   \param returnStatus  [in]: result status of the command.
   \param nbInfo  [in]: information count of valStatus and textstatus list.
   \param valStatus  [in]: condition value list issued from retCondTable or initCondTable.
   \param textStatus  [in]: condition text list issued from retCondTable or initCondTable.
   \param userArg  [in]: optionnal user argument. This argument is the optionnal user argument given in the <em>sendCommand()</em> function and returned back to the client.
   \par Return values:
     none.
*/
typedef void (*CtlCmdReturnCallback)(const char *environment,
				     const char *commandName,
				     ScsStatus   returnStatus,
				     long        nbInfo,
				     long       *valStatus,
				     char      **textStatus,
				     void       *userArg);


/**
   \brief Internal output (command) variable definition for the <em>CTL</em> component.

   This class is used to describe a command to send to an equipment. A command corresponds to an internal output variable (IOV). 
\code#include "ctlcmd.h"\endcode
*/
class CTL_API CtlCmdCommand
{
public:

#endif /* __cplusplus */

  /* Typedef used for the name of an internal output variable (IOV). */
  typedef char IovName[CTL_K_MAXLEN_IOV_NAME];
  
  /* Union used to store the value of an internal output variable (IOV). */
  typedef union {
    int            discrete;
    float          analog;
    unsigned char *structured;
  } IovValue;

  /**@name Typedefs / defines*/
  /*@{*/

  /**
      \par Description:
     enum corresponding to the possible types of an internal output variable (IOV): discrete, analogic or structured.
      \code
      enum IovType { 
         DIOV = 0,
         AIOV,
         SIOV
      }; \endcode
      \par Values:
      \li \c DIOV:  discrete internal output variable,
      \li \c AIOV:  analog internal output variable,
      \li \c SIOV:  structured internal output variable.
  */
  typedef enum IovType { 
    DIOV = 0,
    AIOV,
    SIOV
  } IovType;

  /**
      \par Description:
     enum corresponding to the possible values for the bypass of initial or return condition.
      \code
      enum BypassMode { 
         NO_BYPASS = 0,
         BYPASS
      }; \endcode
      \par Values:
      \li \c NO_BYPASS:  the initial or return condition is not bypassed,
      \li \c BYPASS:  the initial or return condition is bypassed.
  */
  typedef enum BypassMode { 
    NO_BYPASS = 0,
    BYPASS
  } BypassMode;

  /**
      \par Description:
     enum corresponding to the behaviour when a return condition is already correct: should the command be sent or not ?
      \code
      enum SendBehaviour { 
         NO_SEND = 0,
         SEND_ANYWAY
      }; \endcode
      \par Values:
      \li \c NO_SEND:  the command is not sent,
      \li \c SEND_ANYWAY:  the command is sent anyway.
  */
  typedef enum SendBehaviour { 
    NO_SEND = 0,
    SEND_ANYWAY
  } SendBehaviour;
  /*@}*/

#ifdef __cplusplus

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     default constructor. This function creates a non typed internal outpout variable object.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  CtlCmdCommand();

  /**
     \par Description:
     constructor. This function creates a discrete internal output variable (DIOV) object.
     \param name  [in]: name of the output variable (&quot;<em>equipment_alias:iov_pointName</em>&quot;). The length of the name should not exceed CTL_K_MAXLEN_IOV_NAME characters.
     \param value  [in]: discrete value of the variable.
     \param bypassInitCond  [in]: defines the bypass mode for the init condition of the current commande. If the bypass mode is set (<em>BYPASS</em> value), the commande is sent even if the init condition is not correct. The default value is <em>NO_BYPASS</em>.
     \param bypassRetCond  [in]: defines the bypass mode for the return condition of the current commande. The default value is <em>NO_BYPASS</em>.
     \param sendBehaviour  [in]: defines the send behaviour when the return condition is already correct. The default value is to send the command.
     \par Return values:
     none.
  */
  CtlCmdCommand(const char    *name,
		int            value,
		BypassMode     bypassInitCond = NO_BYPASS,
		BypassMode     bypassRetCond  = NO_BYPASS,
		SendBehaviour  sendBehaviour  = SEND_ANYWAY);

  /**
     \par Description:
     constructor. This function creates an analog internal output variable (AIOV) object.
     \param name  [in]: name of the output variable (&quot;<em>equipment_alias:iov_pointName</em>&quot;). The length of the name should not exceed CTL_K_MAXLEN_IOV_NAME characters.
     \param value  [in]: analog value of the variable.
     \param bypassInitCond  [in]: defines the bypass mode for the init condition of the current commande. If the bypass mode is set (<em>BYPASS</em> value), the commande is sent even if the init condition is not correct. The default value is <em>NO_BYPASS</em>.
     \param bypassRetCond  [in]: defines the bypass mode for the return condition of the current commande. The default value is <em>NO_BYPASS</em>.
     \param sendBehaviour  [in]: defines the send behaviour when the return condition is already correct. The default value is to send the command.
     \par Return values:
     none.
  */
  CtlCmdCommand(const char    *name,
		float          value,
		BypassMode     bypassInitCond = NO_BYPASS,
		BypassMode     bypassRetCond  = NO_BYPASS,
		SendBehaviour  sendBehaviour  = SEND_ANYWAY);

  /**
     \par Description:
     constructor. This function creates a structured internal output variable (SIOV) object.
     \param name  [in]: name of the output variable (&quot;<em>equipment_alias:iov_pointName</em>&quot;). The length of the name should not exceed CTL_K_MAXLEN_IOV_NAME characters.
     \param size  [in]: size of the value. The size of the value should not exceed a maximum size (CTL_K_MAX_SIOV_VALUE_SIZE). If the value of the <em>size</em> parameter is bigger than this maximum size or if the buffer pointed by the <em>value</em> parameter contains more bytes than this maximum size, only a number of bytes corresponding to the maximum size are stored in the value.
     \param value  [in]: structured value of the variable. This parameter is a pointer to a buffer containing the structured value.
     \param bypassInitCond  [in]: defines the bypass mode for the init condition of the current commande. If the bypass mode is set (<em>BYPASS</em> value), the commande is sent even if the init condition is not correct. The default value is <em>NO_BYPASS</em>.
     \param bypassRetCond  [in]: defines the bypass mode for the return condition of the current commande. The default value is <em>NO_BYPASS</em>.
     \param sendBehaviour  [in]: defines the send behaviour when the return condition is already correct. The default value is to send the command.
     \par Return values:
     none.
  */
  CtlCmdCommand(const char    *name,
		int            size,
		unsigned char *value,
		BypassMode     bypassInitCond = NO_BYPASS,
		BypassMode     bypassRetCond  = NO_BYPASS,
		SendBehaviour  sendBehaviour  = SEND_ANYWAY);

  /**
     \par Description:
     destructor. This function deletes the IOV object.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~CtlCmdCommand();
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     this function sets the name of the command.
     \par Parameters:
     the command name.
     \par Return values:
     none.
  */
  void setName(const char *name);

  /**
     \par Description:
     this function returns the name of the command.
     \par Parameters:
     none.
     \par Return values:
     the name of the command.
  */
  const char *getName() const { return _name;};

  /**
     \par Description:
     this function returns the type of the command.
     \par Parameters:
     none.
     \par Return values:
     the type of the command (<em>DIOV</em>, <em>AIOV</em> or <em>SIOV</em>).
  */
  IovType getType() const { return _type;};

  /**
     \par Description:
     this function sets the value of a discrete command.
     \par Parameters:
     the command value depending of the command type, and for a structured variable, the value size.
     \par Return values:
     none.
  */
  void setValue(int value);

  /**
     \par Description:
     this function sets the value of an analogic command.
     \par Parameters:
     the command value.
     \par Return values:
     none.
  */
  void setValue(float value);

  /**
     \par Description:
     this function sets the value of a structured command.
     \par Parameters:
     the command value and the value size.
     \par Return values:
     none.
  */
  void setValue(int size, unsigned char *value);

  /**
     \par Description:
     this function returns the value size of the command. This function is meaningful only for a structured command (SIOV).
     \par Parameters:
     none.
     \par Return values:
     the size of the value.
  */
  int getSize() const { return _size;};

  /**
     \par Description:
     this function returns the value of the command.
     \par Parameters:
     none.
     \par Return values:
     a pointer to the value.
  */
  void *getValue() const;

  /**
     \par Description:
     this function sets the bypass mode for initial condition.
     \par Parameters:
     the bypass mode.
     \par Return values:
     none.
  */
  void setBypassInitCond(BypassMode bypassMode);

  /**
     \par Description:
     this function returns the bypass mode for initial condition.
     \par Parameters:
     none.
     \par Return values:
     the bypass mode.
  */
  BypassMode getBypassInitCond() const { return _bypassInitCond;};

  /**
     \par Description:
     this function sets the bypass mode for return condition.
     \par Parameters:
     the bypass mode.
     \par Return values:
     none.
  */
  void setBypassRetCond(BypassMode bypassMode);

  /**
     \par Description:
     this function returns the bypass mode for return condition.
     \par Parameters:
     none.
     \par Return values:
     the bypass mode.
  */
  BypassMode getBypassRetCond() const { return _bypassRetCond;};

  /**
     \par Description:
     this function sets the send behaviour when the return condition is already correct.
     \par Parameters:
     the send behaviour.
     \par Return values:
     none.
  */
  void setSendBehaviour(SendBehaviour sendBehaviour);

  /**
     \par Description:
     this function returns the send behaviour.
     \par Parameters:
     none.
     \par Return values:
     the send behaviour.
  */
  SendBehaviour getSendBehaviour() const { return _sendBehaviour;};
  //@}

  /**@name Operators / cast*/
  //@{
  /**
     \par Description:
     assignment operator.
     \par Parameters:
     a reference to the object to assign from.
     \par Return values:
     a reference to the object resulting of the assignment.
  */
  CtlCmdCommand &operator=(CtlCmdCommand& command);
  //@}

  /**@name Save / restore methods*/
  //@{
  /**
     \par Description:
     this function is used to save the object into an output stream.
     \param os  [in]: the output stream.
     \par Return values:
     none.
    */
  virtual void save(SCS_SL_STD(ostream)& os) const;
  /**
     \par Description:
     this function is used to restore the object from an input stream.
     \param is  [in]: the input stream.
     \par Return values:
     ScsValid if succeeded.
    */
  virtual ScsStatus restore(SCS_SL_STD(istream)& is);
  //@}

private:
  // Name of the internal output variable (&quot;<em>equipment_alias:iov_pointName</em>&quot;)
  IovName       _name;
  // Type of the internal output variable
  IovType       _type;
  // Value of the internal output variable
  IovValue      _value;
  // Size of value for a structured variable
  int           _size;
  // Bypass mode for init condition
  BypassMode    _bypassInitCond;
  // Bypass mode for return condition
  BypassMode    _bypassRetCond;
  // Send behaviour
  SendBehaviour _sendBehaviour;
};

class CtlCmdServerProxy;
class CtlCmdClientIdl_i;


/**
   \brief This class allows to request the execution of commands list.
   
   This class is the interface class for the services exported by the CTLCMD server. It is used to request the execution of commands list. 
\code#include "ctlcmd.h"\endcode
*/

class CTL_API CtlCmdServer
{
public:
  /**@name Typedefs / defines*/
  //@{

  /**
      \par Description:
     Multiple command mode.
      \code
      enum E_ScsCtlMCmdMode {
      ContinueOnFailed = 1,
      StopOnFailed
      };
      typedef E_ScsCtlMCmdMode ScsCtlMCmdMode; \endcode
      \par Values:
      \li \c ContinueOnFailed:  The CtlCmdServer continue its execution on sending command failure,
      \li \c StopOnFailed:  The CtlCmdServer stop its execution on sending command failure.
  */
  enum E_ScsCtlMCmdMode {
    ContinueOnFailed = 1,
    StopOnFailed
  };
  typedef E_ScsCtlMCmdMode ScsCtlMCmdMode;

  //@}

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object connected to the CTLCMD server.
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required CTLCMD server is running.
     \param returnCallback  [in]: address of the command execution return callback function which will be used to notify a client of the execution of a command.
     \param priority  [in]: priority of the messages to the CtlCmdServer (only useful with redundancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  CtlCmdServer(const char*           logicalEnv,
	       CtlCmdReturnCallback  returnCallback = NULL,
	       ScsPriorityLevels     priority = SCS_PRIORITY_NORMAL);
  
  /**
     \par Description:
     destructor. This function closes the connection with the CTLCMD server.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~CtlCmdServer();
  //@}

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     return the status of the connection to the CTLCMD server process.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c CtlHostServerError : cannot connect with the ascmanager process.
     \li \c CtlORBError : cannot connect with the remote CTLCMD server.
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
     this function sends a command (IOV, internal output variable) or a list of commands to execute to the DAC component. When several commands are specified into the list, this means that they should be treated together. They are all sent to DAC or no one: if one of the commands of the list can not be sent (no valid command, initial condition not correct, ...), no command is sent and the current function returns with an error status corresponding to the error. The initial conditions of all the commands of the list are verified, but only the return condition of the first command is verified. <b>Warning:</b> individual commands should not be sent into a list.
     \param nbCommands  [in]: number of commands.
     \param commandsList  [in]: list of commands.
     \param source  [in]: source of the request (7 characters max). This parameter is used for event logging: when it is not set, no event is logged when this function is called.
     \param userArg  [in]: optionnal user argument. This argument is given back when the command return callback is called by the CTLCMD server.
     \return
     \li \c ScsValid : success.
     \li \c CtlCommandSendingError : error sending a command to the DAC component.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlDBMError : an error was returned by a function of the DBM component.
     \li \c CtlExecutionError : command variable already executing.
     \li \c CtlInternalError : internal error.
     \li \c CtlMemoryError : memory allocation error.
     \li \c CtlORBError : ORB communication error (exception raised).
     \li \c CtlTimerError : timer activation error.
     \li \c CtlVariableNameError : variable identification error (variable not in DB or ambiguous identification).
     \li \c CtlVariableStatusError : variable status error (not valid).
     \li \c CtlVariableTypeError : variable type error.
     \li \c CtlVariableValueError : bad value to be given to the variable.
  */
  ScsStatus sendCommand(int            nbCommands,
			CtlCmdCommand *commandsList,
			const char    *source = NULL,
			void          *userArg = NULL);

  /**
     \par Description:
     this function sends multiple commands (IOV, internal output variable) or a list of commands to execute to the DAC component. Each command is process as a single command. This means that te callback can be called several time.
     \param nbCommands  [in]: number of commands.
     \param commandsList  [in]: list of commands.
     \param mode  [in]: sendMCommand mode (see enum ScsCtlMCmdMode).
     \param scsStatusList [out]: return status.
     \param source  [in]: source of the request (7 characters max). This parameter is used for event logging: when it is not set, no event is logged when this function is called.
     \param userArg  [in]: optionnal user argument. This argument is given back when the command return callback is called by the CTLCMD server.
     \return
     \li \c ScsValid : success.
     \li \c CtlCommandSendingError : error sending a command to the DAC component.
     \li \c CtlDBAccessError : database access error.
     \li \c CtlDBMError : an error was returned by a function of the DBM component.
     \li \c CtlExecutionError : command variable already executing.
     \li \c CtlInternalError : internal error.
     \li \c CtlMemoryError : memory allocation error.
     \li \c CtlORBError : ORB communication error (exception raised).
     \li \c CtlTimerError : timer activation error.
     \li \c CtlVariableNameError : variable identification error (variable not in DB or ambiguous identification).
     \li \c CtlVariableStatusError : variable status error (not valid).
     \li \c CtlVariableTypeError : variable type error.
     \li \c CtlVariableValueError : bad value to be given to the variable.
  */
  ScsStatus sendMCommand(int            nbCommands,
			 CtlCmdCommand *commandsList,
			 ScsCtlMCmdMode mode,
			 ScsStatus     *scsStatusList,
			 const char    *source = NULL,
			 void          *userArg = NULL);

  /**
     \par Description:
     this function sends a command (IOV, internal output variable) to execute to the DAC component asynchronsously. 
     \param command  [in]: a command.
     \param source  [in]: source of the request (7 characters max). This parameter is used for event logging: when it is not set, no event is logged when this function is called.
     \return
     \li \c ScsValid : success.
     \li \c CtlORBError : ORB communication error (exception raised).
  */
  ScsStatus sendCommandAsync(const CtlCmdCommand& command,
			     const char*          source = NULL);
  
  /**
     \par Description:
     return the name of the CTLCMD server to which the interface object is connected.
     \par Parameters:
     none.
     \par Return values:
     the name of the server.
  */
  const char *getServerName();
  
  /**
     \par Description:
     return the logical SCADAsoft environment name of the CTLCMD server to which the interface object is connected.
     \par Parameters:
     none.
     \par Return values:
     the name of the environment.
  */
  const char *getServerEnv() { return _envName;};
  //@}
  
private:
  CtlCmdServerProxy *_proxy;
  ScsStatus          _status;
  CtlCmdClientIdl_i *_client;
  char              *_envName;
};

#endif /* __cplusplus */

#endif /* _CTLCMD_H */
