//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : scshook.h                                              */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Mon May 05 16:39:01 2003                               */
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


#ifndef SCS_HOOK_H
#define SCS_HOOK_H

#ifdef WIN32
#ifdef SCSHOOKS_EXPORTS
#define SCSHOOKS_API __declspec(dllexport)
#else
#define SCSHOOKS_API __declspec(dllimport)
#endif
#else
#define SCSHOOKS_API
#endif

#include "ctlgrc.h"
#include "ctlcmd.h"
#include "dbm.h"

class ScsBasicAckAutomaton;

typedef struct _ScsHook {

  enum OperationType {
    INIT,
    CTL_CMD_EXEC_STATUS,
    CTL_GRC_EXEC_STATUS,
    CTL_GRC_BRC_EXEC_STATUS,
    CTL_GRC_PREPARE,
    CTL_GRC_ABORT_PREPARATION,
    DPC_EQP_CHANGE_EQP_STATUS,
    DPC_EQP_CHANGE_EQP_TAG,
    DPC_EQP_CHANGE_VAR_STATUS,
    DPC_EQP_CHANGE_VAR_FORCE,
    DSS_SCENARIO_INIT,
    DSS_SCENARIO_START,
    DSS_SCENARIO_STOP,
    DSS_SCENARIO_ABORT,
    OPM_SET_MASK,
    OPM_CHANGE_PASSWORD,
    OPM_LOCK_OPERATOR,
    OPM_CHECK_PASSWORD_FAILED,
    ALM_ACKNOWLEDGE,
    TSC_LAUNCH_TASK,
    TSC_DISABLE_TASK,
    TSC_ENABLE_TASK,
    TSC_ADD_TASK,
    TSC_REMOVE_TASK,
    TSC_MODIFY_TASK,
    TSC_TASK_CMD_CALLBACK,
    TSC_TASK_GRC_CALLBACK,
    ALM_SHELVE,  // ESA : PCR JNUP 13
    ALM_UNSHELVE // ESA : PCR JNUP 13
  };

  _ScsHook(const char          * source,
	   const OperationType & opType)
    : _alias(0),
      _status(0),
      _source(source),
      _opType(opType),
      _dbmServer(0),
      _operatorName(0)
  {}

  _ScsHook(const char          * operatorName,
           const char          * source,
	   const OperationType & opType)
    : _alias(0),
      _status(0),
      _source(source),
      _opType(opType),
      _dbmServer(0),
      _operatorName(operatorName)
  {}

  
  _ScsHook(const char          * alias,
	   const int           & status, 
	   const char          * source,
	   const OperationType & opType)
    : _alias(alias),
      _status(status),
      _source(source),
      _opType(opType),
      _dbmServer(0),
      _operatorName(0)
  {}

  _ScsHook(DbmServer * dbmServer)
    : _alias(0),
      _status(-1),
      _source(0),
      _opType(INIT),
      _dbmServer(dbmServer),
      _operatorName(0)
  {}


  _ScsHook()
    : _alias(0),
      _status(-1),
      _source(0),
      _opType(INIT),
      _dbmServer(0)
  {}

  const char          * _alias;
  const int             _status;
  const char          * _source;
  const OperationType   _opType;
  const DbmServer     * _dbmServer;
  const char	      * _operatorName;
} ScsHook;

struct ScsHookIovValue : ScsHook {

  ScsHookIovValue(const char                    * alias,
		  const int                     & status, 
		  const char                    * source,
		  const CtlCmdCommand::IovValue & value,
		  const CtlCmdCommand::IovType  & iovType,
		  const ScsHook::OperationType  & opType)
    : ScsHook(alias, status, source, opType),
      _value(value),
      _iovType(iovType)
  {}
  
  const CtlCmdCommand::IovValue & _value;
  const CtlCmdCommand::IovType  & _iovType;
};

struct ScsHookChgEqpStatus : ScsHook {

  ScsHookChgEqpStatus(const char          * alias,
		      const int           & status, 
		      const int           & prevStatus, 
		      const char          * source,
		      const OperationType & opType)
    : ScsHook(alias, status, source, opType),
      _prevStatus(prevStatus)
  {}

  int _prevStatus;
};

struct ScsHookGrc : ScsHook {
  ScsHookGrc(const char          * alias,
	     const int           & status, 
	     const long          & step, 
	     const char          * source,
	     const OperationType & opType)
    : ScsHook(alias, status, source, opType),
      _step(step)
  {}

  long _step;
};

struct ScsHookGrcStep : ScsHookGrc {
  ScsHookGrcStep(const char*         alias,
		 const int&          status, 
		 const long&         step,
		 const char*         eqpEnv,
		 const char*         eqpName,
		 CtlCmdServer*       ctlcmd,
		 const char*         source,
		 const OperationType & opType)
    : ScsHookGrc(alias, status, step, source, opType),
      _equipmentEnvironment(eqpEnv),
      _equipmentName(eqpName),
      _ctlCmd(ctlcmd)
  {}

  const char* _equipmentEnvironment;
  const char* _equipmentName;
  CtlCmdServer* _ctlCmd;
};

struct ScsHookTagging : ScsHook {

  ScsHookTagging(const char          * alias,
		 const int           & status, 
		 const char          * source,
		 const char          * tag1,
		 const char          * tag2,
		 const OperationType & opType)
    : ScsHook(alias, status, source, opType),
      _tag1(tag1),
      _tag2(tag2)
  {}

  const char * _tag1;
  const char * _tag2;
};

struct ScsHookStrValue : ScsHook {

  ScsHookStrValue(const char                   * alias,
		  const int                    & status, 
		  const char                   * source,
		  const char                   * strValue,
		  const ScsHook::OperationType & opType)
    : ScsHook(alias, status, source, opType),
      _value(strValue)
  {}

  const char * _value;
};

struct ScsHookDssScenario : ScsHook {

  ScsHookDssScenario(const char                   * name,
		     const int                    scenarioId, 
		     const int                    mode, 
		     const int                    eventId, 
		     const char                   * eqpName,
		     const char                   * source,
		     const ScsHook::OperationType & opType)
    : ScsHook(source, opType),
      _name(name),
      _scenarioId(scenarioId),
      _mode(mode),
      _eventId(eventId),
      _eqpName(eqpName)
  {}

  const char * _name;
  const int    _scenarioId;
  const int    _mode;
  const int    _eventId;
  const char * _eqpName;
};


struct ScsHookOpmMask : ScsHook {

  ScsHookOpmMask(const char                   *profile,
		 const int                     location,
		 const int                     function,
		 const long                    maskMode,
		 const unsigned short          mask,
		 const char                   *source,
		 const ScsHook::OperationType &opType)
    : ScsHook(source, opType),
      _profile(profile),
      _location(location),
      _function(function),
      _maskMode(maskMode),
      _mask(mask)
  {}

  const char           *_profile;
  const int             _location;
  const int             _function;
  const long            _maskMode;
  const unsigned short  _mask;
};

struct ScsHookOpmPassword : ScsHook {

  ScsHookOpmPassword(const char                   *operatorName,
		     const char                   *source,
		     const ScsHook::OperationType &opType)
    : ScsHook(operatorName, source, opType) 
  {}
};

struct ScsHookOpmLockOperator : ScsHook {

  ScsHookOpmLockOperator(const char                   *operatorName,
                         const char                   *source,
                         const ScsHook::OperationType &opType)
    : ScsHook(operatorName, source, opType)
  {}
};

struct ScsHookOpmCheckPasswordFailed : ScsHook {

  ScsHookOpmCheckPasswordFailed(const char                   *operatorName,
                                const char                   *source,
                                const ScsHook::OperationType &opType)
    : ScsHook(operatorName, source, opType) 
  {}
};

struct ScsHookAlmAcknowledge : ScsHook {

  ScsHookAlmAcknowledge(const char*                  source,
			const char*                  currentAlarmMessage,
			ScsBasicAckAutomaton*        ackAutomaton,
			const ScsHook::OperationType &opType)
    : ScsHook(source, opType),
      _currentAlarmMessage(currentAlarmMessage),
      _newAlarmMessage(0),
      _ackAutomaton(ackAutomaton)
  {}

  ~ScsHookAlmAcknowledge() {
    if (_newAlarmMessage != 0) { delete _newAlarmMessage;}
  }
  
  unsigned char alarmMessageHasChanged() { return (_newAlarmMessage != 0);};
  const char *getNewMessage() { return (const char *)_newAlarmMessage;};

  const char* _currentAlarmMessage;
  char* _newAlarmMessage;
  ScsBasicAckAutomaton* _ackAutomaton;
};

struct ScsHookAlmShelve : ScsHook {

  ScsHookAlmShelve(const char*                  source,
		   const char*                  currentAlarmMessage,
		   ScsBasicAckAutomaton*        ackAutomaton,
		   const ScsHook::OperationType &opType)
    : ScsHook(source, opType),
      _currentAlarmMessage(currentAlarmMessage),
      _newAlarmMessage(0),
      _ackAutomaton(ackAutomaton)
  {}
  
  ~ScsHookAlmShelve() {
    if (_newAlarmMessage != 0) { delete _newAlarmMessage;}
  }
  
  unsigned char alarmMessageHasChanged() { return (_newAlarmMessage != 0);};
  const char *getNewMessage() { return (const char *)_newAlarmMessage;};

  const char* _currentAlarmMessage;
  char* _newAlarmMessage;
  ScsBasicAckAutomaton* _ackAutomaton;
};

struct ScsHookAlmUnshelve : ScsHook {
  
  ScsHookAlmUnshelve(const char*                  source,
		   const char*                  currentAlarmMessage,
		     ScsBasicAckAutomaton*        ackAutomaton,
		     const ScsHook::OperationType &opType)
    : ScsHook(source, opType),
      _currentAlarmMessage(currentAlarmMessage),
      _newAlarmMessage(0),
      _ackAutomaton(ackAutomaton)
  {}

  ~ScsHookAlmUnshelve() {
    if (_newAlarmMessage != 0) { delete _newAlarmMessage;}
  }
  
  unsigned char alarmMessageHasChanged() { return (_newAlarmMessage != 0);};
  const char *getNewMessage() { return (const char *)_newAlarmMessage;};

  const char* _currentAlarmMessage;
  char* _newAlarmMessage;
  ScsBasicAckAutomaton* _ackAutomaton;
};

struct ScsHookTscLaunchTask : ScsHook {

  ScsHookTscLaunchTask(const char                   *source,
		       const char                   *taskName,
		       const char                   *command,
		       const char                   *arguments,
		       const char                   *description,
		       const ScsHook::OperationType &opType)
    : ScsHook(source, opType),
      _taskName(taskName),
      _command(command),
      _arguments(arguments),
      _description(description)
  {}

  ~ScsHookTscLaunchTask() {
  }
  
  const char *_taskName;
  const char *_command;
  const char *_arguments;
  const char *_description;
};

struct ScsHookTscCmdCallbackTask : ScsHook {

  ScsHookTscCmdCallbackTask(const char *source,
		       const char *commandName,
		       ScsStatus   returnStatus,
		       long        nbInfo,
		       long       *valStatus,
		       char      **textStatus,
		       const ScsHook::OperationType &opType)
    : ScsHook(source, opType),
      _commandName(commandName),
      _returnStatus(returnStatus),
      _nbInfo(nbInfo),
      _valStatus(valStatus),
      _textStatus(textStatus)
  {}

  ~ScsHookTscCmdCallbackTask() {
  }
  
  const char *_commandName;
  ScsStatus   _returnStatus;
  long        _nbInfo;
  long*       _valStatus;
  char**      _textStatus;
};

struct ScsHookTscGrcCallbackTask : ScsHook {

  ScsHookTscGrcCallbackTask(const char *source,
			    const char *grcName,
			    CtlGrc::ScsCtlGrcStatus completionStatus,
			    long        stepNumber,
			    const ScsHook::OperationType &opType)
    : ScsHook(source, opType),
      _grcName(grcName),
      _completionStatus(completionStatus),
      _stepNumber(stepNumber)
  {}

  ~ScsHookTscGrcCallbackTask() {
  }
  
  const char *_grcName;
  CtlGrc::ScsCtlGrcStatus _completionStatus;
  long _stepNumber;
};

typedef struct ScsHookTscLaunchTask ScsHookTscDisableTask,
  ScsHookTscEnableTask,
  ScsHookTscRemoveTask,
  ScsHookTscAddTask,
  ScsHookTscModifyTask;

SCSHOOKS_API void ScsHookFunction(const ScsHook * hook);

#endif
