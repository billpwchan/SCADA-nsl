//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : dss.h                                                  */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES IS                                              */
/*  CREATION DATE    : Tue May  2 15:30:32 2000                               */
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


#ifndef _SCS_DSS_H_
#define _SCS_DSS_H_

#define DssTrace	ScsTraceFunction(DSS_SCSMODULE)

#define DSS_EVENT_LIST_NAME "DssEventList"

#define DSS_TYPE_FIELD_NAME	   "Type"
#define DSS_ID_FIELD_NAME	   "Id"
#define DSS_STATUS_FIELD_NAME      "Status"
#define DSS_OWNER_FIELD_NAME	   "Owner"
#define DSS_SCENARIO_FIELD_NAME    "Scenario"
#define DSS_SCENARIOID_FIELD_NAME  "ScenarioId"
#define DSS_MESSAGE_FIELD_NAME	   "Message"
#define DSS_ALARMID_FIELD_NAME     "AlarmId"
#define DSS_ENVIRONMENT_FIELD_NAME "Environment"
#define DSS_EVENT_TIME_FIELD_NAME  "DssEventTime"
#define DSS_SEVERITY_FIELD_NAME    "Severity"
#define DSS_EQUIPMENTNAME_FIELD_NAME  "EquipmentName"
#include "scs.h"


enum Mode {
    Automatic = 0,
    SemiAutomatic = 1,
    Manual = 2
};

enum NodeState {
    NotExecuted = 0,
    Executed = 1,
    CurrentNode = 2,
    Running = 3,
    Faulty = 4
};

enum linkState {
    NotInPath = 0,
    InPath = 1,
    Proposed = 2,
    Conflicting = 3,
    Forced = 4
};


class DssProxy;

class DSS_API DssServer
{
public:
  DssServer(const char *logicalEnv = 0,
	    const char *serverName = "DssServer",
	    ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);

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

  ScsStatus getProcedures(char  *eventType,
			  char **&procedures,
			  int   &nb) const;

  ScsStatus createScenario(char  *procedureName,
			   int    eventId,
			   int    mode,
			   char **argNames,
			   int    nbArgNames,
			   char *&argValue) const;

  ScsStatus createVirtualScenario(char  *procedureName,
				  char  *eventType,
				  char  *message,
				  int    mode,
				  char **argNames,
				  int    nbArgNames,
				  char *&argValue) const;

  ScsStatus createSubScenario(int    scenarioId,
			      int   &subScenarioId) const;

  ScsStatus lockScenario(int   scenarioId,
			 char *owner) const;

  ScsStatus unlockScenario(int   scenarioId) const;

  ScsStatus successScenario(int scenarioId) const;

  ScsStatus failureScenario(int scenarioId) const;

  ScsStatus cancelScenario(int scenarioId) const;

  ScsStatus createEvent(int   scenarioId,
			char *type) const;

  ScsStatus removeEvent(int   eventKeyId) const;

  ScsStatus initModes(int  scenarioId,
		      int *modes,
		      int  nb) const;

  ScsStatus changeMode(int scenarioId,
		       int newMode) const;

  ScsStatus setVariable(int   scenarioId,
			int   varIndex,
			char *varValue) const;

  ScsStatus setResult(int scenarioId,
		      char *value) const;
  ScsStatus getResult(int scenarioId,
		      char *&value) const;

  ScsStatus afterNode(int scenarioId,
		      int oldNodeId,
		      int outputLinkId,
		      int newNodeId) const;

  ScsStatus beforeNode(int scenarioId,
		       int inputLinkId,
		       int nodeId) const;

  ScsStatus forceLink(int scenarioId,
		      int oldNodeId,
		      int linkId) const;

  ScsStatus cancelForcing(int scenarioId,
			  int conflictingLinkId) const;

  ScsStatus acceptForcing(int scenarioId,
			  int linkId,
			  int oldLinkId) const;

  ScsStatus nodeError(int scenarioId,
		      int nodeId) const;

  ScsStatus clearScenario(int scenarioId,
			  int recurse) const;

  ScsStatus getEventTypeList( char **&eventType,
			      int   &nb) const;

  ScsStatus getCurrentState(int scenarioId,
			    char*& state) const;

  ScsStatus getEventId(int scenarioId,
		       int& eventId) const;

  // FFT NEL 625
  ScsStatus getOldSubScenarioId(int  parentScenarioId,
				int  relatedCallstepNodeId,
				int &oldSubScenarioId) const;

  // FFT NEL 625
  ScsStatus setCallstepNodeId(int  subScenarioId,
			      int  relatedCallstepNodeId);

private:

  DssProxy       * _proxy;
  ScsStatus        _status;
};

#endif
