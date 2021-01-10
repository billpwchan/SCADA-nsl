/******************************************************************************/
/*									      */
/*  FILE		: scsalm.h                                            */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 1998/12/14					      */
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
// $Id: scsalm.h,v 1.18 1999/07/08 13:29:26 jmb Exp$
//
// Revision 3.12.1  2002/03/19 KLL
// FFT SRC-498 - Nouvelle API removeAlarm

// Revision 3.14.0  2003/05/22 KLL
// ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
//           nouveau noyau

/******************************************************************************/
#ifndef _SCS_ALM_H
#define _SCS_ALM_H

/** \file
    \brief Access to the Alarm Server component.
*/

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/
#include "scs.h"
#include "sec.h"
#include "secerror.h"
#include "ols.h"

#include "dbk/dbkaddressid.h"

typedef DbkInteger64 AlmInteger64;

/*----------------------------------------------------------------------------*/
/*  TRACE								      */
/*  ex: AlmTrace(LEVEL, "Exemple %i", (int) 5 );			      */
/*----------------------------------------------------------------------------*/
#define AlmTrace			ScsTraceFunction(ALM_SCSMODULE)
#define AlmTraceLevel(level,message)	BaseTraceLevel(ALM_SCSMODULE,level, message)
#define ALM_MODULE			32
// trace level
#define CRITICAL_LEVEL			SCS_LEVEL(0)
#define LAUNCH_LEVEL			SCS_LEVEL(1)
#define UPDT_LEVEL			SCS_LEVEL(2)
#define ACK_LEVEL			SCS_LEVEL(3)
#define TIMER_LEVEL			SCS_LEVEL(4)
#define ALMLST_LEVEL			SCS_LEVEL(5)
#define EVTLST_LEVEL			SCS_LEVEL(6)
#define SNAPSHOT_LEVEL			SCS_LEVEL(7)
#define PERF_LEVEL			SCS_LEVEL(8)
#define CFG_LEVEL			SCS_LEVEL(9)
#define CLIENT_LEVEL			SCS_LEVEL(12)

// Alarm list name
#define ALARM_LIST_NAME    "AlarmList"
#define EVENT_LIST_NAME    "EventList"

///////////////////////////////////////////////////////////////////////////////
// Field names of alarm list
// default alarm server name
#define ALM_DEFAULT_ALARM_SERVER_NAME                           "AlmServer"
//-----------------------------------------------------------------------------
// common
	// used by SCSVISU
#define ALM_DBREF_FIELD_NAME					"AlarmId"
	// used by SCSVISU
#define ALM_EQUIPNAME_FIELD_NAME				"EquipmentName"
#define ALM_EQUIPMENT_VALUE_FIELD_NAME			        "Value"
#define ALM_VALUE_FIELD_NAME					"ValueState"
	// used by SCSVISU
#define ALM_ACK_FIELD_NAME					"AcknowledgeRequired"
	// used by SCSVISU
#define ALM_SEVERITY_FIELD_NAME					"Severity"
#define ALM_HIDDEN_FIELD_NAME					"Hidden"
#define ALM_SHELVE_FIELD_NAME					"Shelve"
#define ALM_MESSAGE_FIELD_NAME					"Message"
#define ALM_FCTCATEGORY_FIELD_NAME				"FunctionalCategory"
#define ALM_GEOCATEGORY_FIELD_NAME				"GeographicalCategory"
#define ALM_TIME_FIELD_NAME					"SCSTime"
#define ALM_EVENT_TIME_FIELD_NAME				ALM_TIME_FIELD_NAME
// Kll - 2003/05/22 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
//                              nouveau noyau
#define ALM_ENVIRONMENT_FIELD_NAME				"Environment"
#define ALM_USERFIELD1_NAME					"User1"
#define ALM_USERFIELD2_NAME					"User2"
#define ALM_GROUP1_FIELD_NAME					ALM_USERFIELD1_NAME
#define ALM_GROUP2_FIELD_NAME					ALM_USERFIELD2_NAME
#define ALM_DSSEVENTTYPE_FIELD_NAME                             "DssEventType"
//-----------------------------------------------------------------------------
// used by transport alarm server
	// used by SCSVISU
#define ALM_INDEX_FIELD_NAME					"Index"
#define ALM_PLIN_FIELD_NAME					"Plin"
#define ALM_AIN_FIELD_NAME					"Ain"
#define ALM_EQUIPCLASS_FIELD_NAME                               "EquipmentClass"
#define ALM_APPLI1_FIELD_NAME					"Appli1"
#define ALM_APPLI2_FIELD_NAME					"Appli2"
#define ALM_FORMAT_FIELD_NAME					"Format"

//-----------------------------------------------------------------------------
// used by new alarm server
#define ALM_THEME_FIELD_NAME					"Theme"
#define ALM_EQUIPMENT_TIME_FIELD_NAME			        "EquipmentDate"
#define ALM_ACQUISITION_TIME_FIELD_NAME			        "AcquisitionDate"
#define ALM_PACKAUTOMATON_FIELD_NAME				"AckAutomatonPointer"
#define ALM_AUTOID_FIELD_NAME					"AutoId"
#define ALM_USERID_FIELD_NAME					"UserID"

///////////////////////////////////////////////////////////////////////////////
// Alarm state
#define ALM_STATE_NORMAL	"N"
#define ALM_STATE_ALARM		"A"
#define ALM_STATE_NOTHING	"-"
// ESA - 13-02-07 - PCR SRC 1226 - add two new states
#define ALM_STATE_UPDATE	"U"
#define ALM_STATE_DELETE	"D"

// NOT USED
#define ALM_STATE_TRANSITION	"T"

///////////////////////////////////////////////////////////////////////////////
// Alarm system connection types
enum { SCS_CURRENT_FUTURE_ALARMS = 0,
       SCS_FUTURE_ALARMS };

class ScsAlmIdl;
class ScsAlmProxy;

/**
   \brief This class provides a remote access to the alarm server of SCADAsoft.

   This class is used to remotely access the services of the alarm server of SCADAsoft. It allows to declare new alarms or events, and to acknowledge some alarms.
\code#include "scsalm.h"\endcode
*/
class ALM_API ScsAlmServer : public OlsServer
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates a connection with the alarm server named <em>serverName</em> running in SCADAsoft logical environment <em>environment</em>.
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the alarm server is running,
     \param serverName  [in]: name of the alarm server (default name is recommended).
     \param priority [in]:
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  ScsAlmServer(const char *logicalEnv = 0,
	       const char *serverName = ALM_DEFAULT_ALARM_SERVER_NAME,
	       ScsPriorityLevels priority = SCS_PRIORITY_NORMAL);
  /**
     \par Description:
     destructor. This function closes the connection with the alarm server.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~ScsAlmServer();
  //@}
  
  /**@name General member functions*/
  //@{
  /**
     \par Description:
     return the status of the connection to the remote alarm server.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c AlmHostServerError : cannot connect to the ascmanager process.
     \li \c AlmORBError : cannot connect with the remote alarm server.
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
     this function acknowledges the alarms specified in the identifier list parameter. If any alarms cannot be acknowledged (because they do not exist or are already acknowledged), the method returns an error code. <em>idCount</em> is set to the number of ids in the list.
     \param alarmIdList  [in]: list of alarm identifiers,
     \param idCount  [in]: number of alarm identifiers,
     \param inUserId  [in]: userId of alarm identifiers, its default value is 0.
     \return
     \li \c ScsValid : success.
     \li \c AlmORBError : cannot connect with the remote alarm server.
  */
  // CREATION : 08 02 2002 - USER : K.L. LEY - COMMENTS : API C++ for user value automaton
  ScsStatus acknowledgeAlarm(int*  alarmIdList, 
			     short idCount,
			     int   inUserId = 0);

  /**
     \par Description:
     this function shelvess the alarms specified in the identifier list parameter. If any alarms cannot be shelved (because they do not exist or are already shelved), the method returns an error code. <em>idCount</em> is set to the number of ids in the list.
     \param alarmIdList  [in]: list of alarm identifiers,
     \param idCount  [in]: number of alarm identifiers,
     \param inUserId  [in]: userId of alarm identifiers, its default value is 0.
     \return
     \li \c ScsValid : success.
     \li \c AlmORBError : cannot connect with the remote alarm server.
  */
  // MODIFIED : 08 02 2002 - USER : K.L. LEY - COMMENTS : API C++ for user value automaton
  ScsStatus shelveAlarm(int*  alarmIdList, 
			short idCount,
			int   inUserId = 0);
  /**
     \par Description:
     this function unshelvess the alarms specified in the identifier list parameter. If any alarms cannot be unshelved (because they do not exist or are already unshelved), the method returns an error code. <em>idCount</em> is set to the number of ids in the list.
     \param alarmIdList  [in]: list of alarm identifiers,
     \param idCount  [in]: number of alarm identifiers,
     \param inUserId  [in]: userId of alarm identifiers, its default value is 0.
     \return
     \li \c ScsValid : success.
     \li \c AlmORBError : cannot connect with the remote alarm server.
  */
  ScsStatus unshelveAlarm(int*  alarmIdList, 
			  short idCount,
			  int   inUserId = 0);

  /**
     \par Description:
     this function declares a new (external) alarm or a new event.
     \param extAlmId  [out]: alarm identifier,
     \param extAutoId [inout]: value automaton identifier (for entry mode, should absolutely be a negative value for an external alarm or a null value for an event). If the thresholdLow and/or thresholdLow parameter(s) is/are not null in order to define a range, the parameter is calculated by ScsAlmServer. In this case, it corresponds to the first free autoId found in the range.
     \param state  [in]: alarm state ("A" for alarm, "N" for normal or "T" for transitory),
     \param valueAutomaton  [in]: name of the value automaton,
     \param ackAutomaton  [in]: name of the ack automaton,
     \param equipmentDate [in]:
     \param acquisitionDate [in]:
     \param severity  [in]: alarm severity,
     \param functionalCat  [in]: functional category (applicative value), used for alarm synthesis,
     \param geographicalCat  [in]: geographical category (applicative value), used for alarm synthesis,
     \param equipmentName  [in]: equipment name,
     \param message  [in]: textual description of the alarm,
     \param group1 [in]:
     \param group2 [in]:
     \param thresholdLow [in]: low threshold of the range, should be a negative value if used. Its default value is 0,
     \param thresholdHigh [in]: high threshold of the range, should be a negative value if used. Its default value is 0.
     \return
     \li \c ScsValid : success.
     \li \c ErrListAction : cannot update event list.
     \li \c NullPointerAutomatonCreation : cannot create value automaton.
     \li \c ErrNullPointerAckCreation : cannot create acknowlegement automaton.
     \li \c ErrDuplicateExtAlarmId : wrong state or external alarm already existed.
     \li \c ErrInternal : internal error.
     \li \c ErrNullPointerAutomatonExt : cannot find value automaton.
  */
  // 04 12 2006 - USER : ESA - COMMENTS : PCR SRC 1204 - add two new optional parameters
  ScsStatus updtExtAlm(AlmInteger64	&extAlmId,
		       AlmInteger64     &extAutoId,
		       char*		state,
		       char*		valueAutomaton,
		       char*		ackAutomaton,
		       timeval		equipmentDate,
		       timeval		acquisitionDate,
		       int		severity,
		       int		functionalCat,
		       int		geographicalCat,
		       char*		equipmentName,
		       char*		message,
		       char*            group1,
		       char*            group2,
		       AlmInteger64     thresholdLow = 0,
		       AlmInteger64     thresholdHigh = 0);

  /**
     \par Description:
     this function create a new DI user value automaton.
     \param inScsAddress  [in]: ScsAddress string of the DI value automaton (should absolutely be a positive value and different from 0),
     \param inLimits  [in]: limits's list,
     \param inLimitsSize  [in]: size of the limits's list,
     \param inUserId  [in]: userId of the user value automaton,
     \param inValueAutomatonName  [in]: value automaton's name, its default value is empty,
     \param inAckAutomatonName  [in]: ack automaton's name, its default value is empty.
     \return
     \li \c ScsValid : success.
     \li \c ErrListAction : cannot update event list.
     \li \c NullPointerAutomatonCreation : cannot create value automaton.
     \li \c ErrNullPointerAckCreation : cannot create acknowlegement automaton.
     \li \c ErrInternal : internal error.
     \li \c ErrNullPointerAutomatonExt : cannot find value automaton.
  */
  ScsStatus createUserAlarmDI (const char * inScsAddress,
			       long *       inLimits,
			       int          inLimitsSize,
			       int          inUserId,
			       const char * inValueAutomatonName = 0,
			       const char * inAckAutomatonName   = 0);

  /**
     \par Description:
     this function create a new AI user value automaton.
     \param inScsAddress  [in]: ScsAddress string of the AI value automaton (should absolutely be a positive value and different from 0,
     \param inLimits [in]:
     \param inLimitsSize [in]:
     \param inUserId  [in]: userId of the user value automaton,
     \param inValueAutomatonName  [in]: value automaton's name, its default value is empty,
     \param inAckAutomatonName  [in]: ack automaton's name, its default value is empty.
     \return
     \li \c ScsValid : success.
     \li \c ErrListAction : cannot update event list.
     \li \c NullPointerAutomatonCreation : cannot create value automaton.
     \li \c ErrNullPointerAckCreation : cannot create acknowlegement automaton.
     \li \c ErrInternal : internal error.
     \li \c ErrNullPointerAutomatonExt : cannot find value automaton.
  */
  ScsStatus createUserAlarmAI (const char * inScsAddress,
			       double *     inLimits,
			       int          inLimitsSize,
			       int          inUserId,
			       const char * inValueAutomatonName = 0,
			       const char * inAckAutomatonName   = 0);

  /**
     \par Description:
     this function delete an user value automaton.
     \param inScsAddress  [in]: ScsAddress string of the user value automaton (should absolutely be a positive value and different from 0,
     \param inUserId  [in]: userId of the user value automaton.
     \return
     \li \c ScsValid : success.
     \li \c ErrListAction : cannot update event list.
     \li \c ErrInternal : internal error.
     \li \c ErrNullPointerAutomatonExt : cannot find value automaton.
  */
  ScsStatus deleteUserAlarm (const char * inScsAddress,
			     int          inUserId);
  
  /**
     \par Description:
     hide the alarms specified in identifier list parameter. If any alarms cannot be hidden (because they do not exist or are already shelved), the method returns an error code. count is set to the number of ids in the list.
     \par Return values:
     the possible values for the returned ScsStatus are: ScsValid or ScsError
    \li \c AlmListActionError : if an action on the alarms list has returned an error,
    \li \c AlmORBError : if an ORB exception was caught.
  */
  ScsStatus hideAlarm(int *alarmIdList, short idCount);
  /**
     \par Description:
     show the alarms specified in identifier list parameter. If any alarms cannot be show (because they do not exist or are already shelved), the method returns an error code. count is set to the number of ids in the list.
     \par Return values:
     the possible values for the returned ScsStatus are: ScsValid or ScsError
    \li \c AlmListActionError : if an action on the alarms list has returned an error,
    \li \c AlmORBError : if an ORB exception was caught.
  */
  ScsStatus showAlarm(int *alarmIdList, short idCount);

  /**
     \par Description:
     this function reset to NORMAL state all the external alarms generated by equipment.
     \param equipName  [in]: Name of Equipment
     \param sourceId  [in]: Identification of process, which generate External alarms.
     \param classIdIdx [in]:
     \param stateIdx [in]:
     \param severIdx [in]:
     \param messageOfReset [in]:
     \param pConfig [in]:
     \return
     \li \c ScsValid : success.
     \li \c ScsErrror : error.
  */
  ScsStatus setExtToNormal(const char   *equipName, 
			   int          sourceId, 
			   int          classIdIdx,
			   int          stateIdx,
 			   int          severIdx,
			   const char   *messageOfReset,
			   OlsDataSet   *pConfig);

  /**
     \par Description:
     this function set the userId.
     \param inSubscriptionId  [in]: user subscriptionId
     \param inUserId  [in]: userId.
     \return
     \li \c ScsValid : success.
     \li \c ScsErrror : error.
  */
  ScsStatus setUserId(int inSubscriptionId, 
		      int inUserId);

  /**
     \par Description:
     this function unset the userId.
     \param inSubscriptionId  [in]: user subscriptionId
     \param inUserId  [in]: userId.
     \param inFlagDelete [in]:
     \return
     \li \c ScsValid : success.
     \li \c ScsErrror : error.
  */
  ScsStatus unsetUserId(int inSubscriptionId, 
			int inUserId,
			int inFlagDelete=1);

  /**
     \par Description:
     get the rank in the "visibility" field of the user.
     \param inUserId  [in]: userId.
     \param outUserVisibilityRank  [in]: the rank in the "visibility" field of the user.
     \return
     \li \c ScsValid : success.
     \li \c ScsErrror : error.
  */
  ScsStatus getUserVisibilityRank (int inUserId, int &outUserVisibilityRank);

  /**
     \par Description:
     this function declares a new (external) alarm or a new event.
     \param alarmId  [in]: alarm identifier,
     \param exist  [out]: 1 if existed.
     \return
     \li \c ScsValid : success.
     \li \c AlmORBError : cannot connect with the remote alarm server.
  */ 
  ScsStatus alarmIdExists(int alarmId, int &exist);


  /**
     \par Description:
     this function modify the values of User defined fields in alarm List, event List and tempo list , the method returns an error code.
     \param listName  [in]: list name,
     \param alarmIdCount  [in]: number of alarm identifiers.
     \param alarmIdList  [in]: list of alarm identifiers,
     \param fieldCountList  [in]: list of fields count for each alarm ,
     \param fieldList  [in]: list  of fileds to modify the value.
     \return
     \li \c ScsValid : success.
     \li \c AlmORBError : cannot connect with the remote alarm server.
  */
  ScsStatus modifyUserFields( const char         *listName,
                                    int           alarmIdCount, 
                                    int          *alarmIdList, 
                                    int          *fieldCountList,
                                    OlsField    **fieldList );

  /**
     \par Description:
     Remove all alarms with the autoId in the list <em>inAutoIdList</em>.
     \param inAutoIdList  [in]: List of autoId.
     \param inAutoIdCount  [in]: number of inAutoIdList elements.
     \return
     \li \c ScsValid : success.
     \li \c AlmORBError : cannot remove all alarms.
  */
  // USER : K.L. LEY - FFT SRC 426 - COMMENTS : API C++ for remove all alarms with autoIds
  //                                            in inAutoIdList
  ScsStatus removeAutoId (AlmInteger64 * inAutoIdList,
			  short          inAutoIdCount);


  /**
     \par Description:
     this function remove all alarms with the almId's list entered.
     \param alarmIdList  [in]: list of alarm identifiers,
     \param idCount  [in]: number of alarm identifiers.
     \return
     \li \c ScsValid : success.
     \li \c AlmORBError : cannot connect with the remote alarm server.
  */
  // CREATION : 19 03 2003 - USER : K.L. LEY - COMMENTS : API C++ for FFT SRC 498
  ScsStatus removeAlarm(int*  alarmIdList, 
			short idCount);

  //ScsStatus newValues(const NewValueDataList& alarmValueDataList);
  ScsAlmProxy* getProxy() {return _proxy;};

  // Username accessors to be logged
  const char* getUserName();
  void setUserName(const char* newName);
  //@}

  // External alarm notification function (only called by AlmExtern class)
  ScsStatus notify(AlmInteger64 &extAlmId,
		   int   alarmClass,
		   int   sourceId,
		   char *state,
		   char *valueAutomaton,
		   char *ackAutomaton,
		   int   severity,
		   int   functionalCat,
		   int   geographicalCat,
		   char *equipmentName,
		   int   equipmentClass,
		   char *message,
		   char *group1,
		   char *group2,
		   char *dssEventType = NULL,
		   int   equipmentId = -1,
		   int   theme = -1);
private:
  
  ScsAlmProxy       *_proxy;
  ScsStatus          _status;
  char              *_userName;
};

#endif
