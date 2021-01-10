/******************************************************************************/
/*									      */
/*  FILE		: scsalmext.h                                         */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 1999/07/13					      */
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
/*	                                				      */
/*............................................................................*/
/*  MODIFICATION:   J.Pujol	3/7/2000				      */
/*  MODIFICATION:   Y.Lozinguez	8/8/2001				      */
/******************************************************************************/
#ifndef _SCSALMEXT_H
#define _SCSALMEXT_H

/** \file
    \brief Remote Access to the Alarm Server.
*/

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/
#include <stdarg.h>

/*----------------------------------------------------------------------------*/
/*  EXTERNALS DEFINITION						      */
/*----------------------------------------------------------------------------*/
#include "scsalm.h"
#include "olstypes.h"

#define ALMEXT_K_FIELD_CLASS_ID         "CLASS"
#define ALMEXT_K_FIELD_ACTIVE           "ACTIVE"
#define ALMEXT_K_FIELD_VALUE_AUTOMATON  "VALUE_AUTOMATON"
#define ALMEXT_K_FIELD_ACK_AUTOMATON    "ACK_AUTOMATON"
#define ALMEXT_K_FIELD_STATE_E          "STATE_E"
#define ALMEXT_K_FIELD_STATE_N          "STATE_N"
#define ALMEXT_K_FIELD_SEVERITY_E       "SEVERITY_E"
#define ALMEXT_K_FIELD_SEVERITY_N       "SEVERITY_N"
#define ALMEXT_K_FIELD_MESSAGE_E        "MESSAGE_E"
#define ALMEXT_K_FIELD_MESSAGE_N        "MESSAGE_N"
#define ALMEXT_K_FIELD_OBJECT_NAME      "OBJECT_NAME"
#define ALMEXT_K_FIELD_FUNCTIONAL_CAT   "FUNCTIONAL_CAT"
#define ALMEXT_K_FIELD_GEOGRAPHICAL_CAT "GEOGRAPHICAL_CAT"
#define ALMEXT_K_FIELD_EQUIPMENT_CLASS  "EQUIPMENT_CLASS"
#define ALMEXT_K_FIELD_GROUP_1          "GROUP_1"
#define ALMEXT_K_FIELD_GROUP_2          "GROUP_2"
#define ALMEXT_K_FIELD_DSS_EVENT_TYPE   "DSS_EVENT_TYPE"
#define ALMEXT_K_FIELD_THEME            "THEME"

enum AlmExtObjectState {
  ALMEXT_OBJ_STATE_NORMAL = 0,
  ALMEXT_OBJ_STATE_ERROR
};

#define ALMEXT_K_STATE_NORMAL  "N"
#define ALMEXT_K_STATE_ALARM   "A"
#define ALMEXT_K_STATE_TRANSIT "T"

#define ALMEXT_K_ACTIVE_TRUE  "TRUE"
#define ALMEXT_K_ACTIVE_FALSE "FALSE"

#define ALMEXT_K_SEP_FIELD_DEF "="

#define ALMEXT_K_MIN_SOURCE_ID 0
#define ALMEXT_K_MAX_SOURCE_ID 31

#define ALMEXT_K_MIN_CLASS_ID 0
#define ALMEXT_K_MAX_CLASS_ID 999

#define ALMEXT_K_MAX_FORMAT_MESS 512

/**
   \brief This class provides a remote access to the alarm server of SCADAsoft.

   This class is used to remotely access the services of the alarm server of SCADAsoft. It allows to declare new external alarms or events. The characteristics of alarm classes are specified in a configuration file.
\code#include "scsalmext.h"\endcode
*/
class ALM_API ScsAlmExtern
{
public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates a connection with the alarm server running in SCADAsoft logical environment <em>logicalEnv</em>. The characteristics of the external alarms are specified in the <em>fileName</em> configuration file.
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the alarm server is running,
     \param fileName  [in]: pathname for the alarm configuration file,
     \param sourceId  [in]: identification number (0-31) of the client application component (used to elaborate the unique external alarm identification number),
     \param priority  [in]: priority of the messages to the HIS server (only useful with redundancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  ScsAlmExtern(const char*        logicalEnv,
	       const char*        fileName,
	       short              sourceId = 0,
	       ScsPriorityLevels  priority = SCS_PRIORITY_NORMAL);
  /**
     \par Description:
     destructor. This function closes the connection with the alarm server.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
 ~ScsAlmExtern();
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
     \li \c AlmBadParamError : the value of source id parameter is not correct.
     \li \c AlmRtapFunctionError : error connecting to Rtap database.
     \li \c AlmScadasoftFunctionError : error connecting to ScsAlmServer or DbmServer.
     \li \c AlmInternalError : the alarm configuration file cannot be read or is incorrect.
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
     this function reset all the External alarms of an equipment to a Normal state, severity, and Message.
     \param objectName  [in]: equipment name. 
     \param messageOfReset  [in]: Global Message of Reset to Normal; Valid Message for all external alrms on the equipment.
     \return
     \li \c ScsValid : success.
     \li \c AlmBadParamError : the value of an input parameter is not correct.
     \li \c AlmInternalError : no configuration data were found for specified alarm class.
  */
  ScsStatus setExtToNormal( const char *objectName, const char *messageOfReset);
  /**
     \par Description:
     this function declares a new (external) alarm. The number of parameters of this function is variable.
     \param classId  [in]: identification number (0-999) of the alarm class (used to elaborate the unique external alarm identification number),
     \param objectName  [in]: object name (used as an equipment point alias) concerned by the alarm, if any,
     \param objectId  [in]: object identification number (should be specified only if no object name parameter was specified),
     \param objectState  [in]: object state (ALMEXT_OBJ_STATE_NORMAL or ALMEXT_OBJ_STATE_ERROR) determining which alarm attributes of the configuration file will be used,
     \param ...  [in]: other optional parameters used to construct the alarm message. Theses parameters correspond to the message format as defined in the alarm configuration file.
     \return
     \li \c ScsValid : success.
     \li \c AlmBadParamError : the value of an input parameter is not correct.
     \li \c AlmInternalError : no configuration data were found for specified alarm class.
     \li \c AlmRtapFunctionError : error reading database using Rtap.
     \li \c AlmScadasoftFunctionError : error reading database using DbmServer or calling <em>notify()</em> function of alarm server.
  */
  ScsStatus notify(short       classId,
                   const char *objectName,
                   short       objectId,
                   int         objectState, ...);
  /**
     \par Description:
     this function declares a new (external) event. The number of parameters of this function is variable. For an event, only the normal part of message, severity an state is taken into account from the configuration file.
     \param classId  [in]: identification number (0-999) of the event class,
     \param objectName  [in]: object name (used as an equipment point alias) concerned by the event, if any,
     \param objectId  [in]: object identification number (should be specified only if no object name parameter was specified),
     \param ...  [in]: other optional parameters used to construct the event message. Theses parameters correspond to the message format as defined in the alarm/event configuration file.
     \return
     \li \c ScsValid : success.
     \li \c AlmBadParamError : the value of an input parameter is not correct.
     \li \c AlmInternalError : no configuration data were found for specified event class.
     \li \c AlmRtapFunctionError : error reading database using Rtap.
     \li \c AlmScadasoftFunctionError : error reading database using DbmServer or calling <em>notify()</em> function of alarm server.
  */
  ScsStatus sendEvent(short       classId,
		      const char *objectName,
		      short       objectId, ...);
  /**
     \par Description:
     this function is an alternative method to declare a new (external) alarm or a new event. The number of parameters of this function is variable.
     \param classId  [in]: identification number (0-999) of the alarm class (used to elaborate the unique external alarm identification number),
     \param objectName  [in]: object name (used as an equipment point alias) concerned by the alarm, if any,
     \param objectId  [in]: object identification number (should be specified only if no object name parameter was specified),
     \param objectState  [in]: object state (ALMEXT_OBJ_STATE_NORMAL or ALMEXT_OBJ_STATE_ERROR) determining which alarm attributes of the configuration file will be used,
     \param args  [in]: variables parameters used to construct the alarm message. Theses parameters correspond to the message format as defined in the alarm configuration file.
     \return
     \li \c ScsValid : success.
     \li \c AlmBadParamError : the value of an input parameter is not correct.
     \li \c AlmInternalError : no configuration data were found for specified alarm class.
     \li \c AlmRtapFunctionError : error reading database using Rtap.
     \li \c AlmScadasoftFunctionError : error reading database using DbmServer or calling <em>notify()</em> function of alarm server.
  */
  ScsStatus notify(short       classId,
                   const char *objectName,
                   short       objectId,
                   int         objectState,
		   va_list     args);
  /**
     \par Description:
     this function is an alternative method to declare a new (external) alarm or a new event. The number of parameters of this function is variable.
     \param alarmId  [out]: identification number (0-999) of the generated alarm,
     \param classId  [in]: identification number (0-999) of the alarm class (used to elaborate the unique external alarm identification number),
     \param objectName  [in]: object name (used as an equipment point alias) concerned by the alarm, if any,
     \param objectId  [in]: object identification number (should be specified only if no object name parameter was specified),
     \param objectState  [in]: object state (ALMEXT_OBJ_STATE_NORMAL or ALMEXT_OBJ_STATE_ERROR) determining which alarm attributes of the configuration file will be used,
     \param args  [in]: variables parameters used to construct the alarm message. Theses parameters correspond to the message format as defined in the alarm configuration file.
     \return
     \li \c ScsValid : success.
     \li \c AlmBadParamError : the value of an input parameter is not correct.
     \li \c AlmInternalError : no configuration data were found for specified alarm class.
     \li \c AlmRtapFunctionError : error reading database using Rtap.
     \li \c AlmScadasoftFunctionError : error reading database using DbmServer or calling <em>notify()</em> function of alarm server.
  */
  ScsStatus notify(long &alarmId,
                   short       classId,
                   const char *objectName,
                   short       objectId,
                   int         objectState,
		   va_list     args);

  /**
     \par Description:
     this function declares a new (external) event. The number of parameters of this function is variable. For an event, only the normal part of message, severity an state is taken into account from the configuration file.
     \param classId  [in]: identification number (0-999) of the event class,
     \param objectName  [in]: object name (used as an equipment point alias) concerned by the event, if any,
     \param objectId  [in]: object identification number (should be specified only if no object name parameter was specified),
     \param args  [in]: variables parameters used to construct the event message. Theses parameters correspond to the message format as defined in the alarm configuration file.
     \return
     \li \c ScsValid : success.
     \li \c AlmBadParamError : the value of an input parameter is not correct.
     \li \c AlmInternalError : no configuration data were found for specified event class.
     \li \c AlmRtapFunctionError : error reading database using Rtap.
     \li \c AlmScadasoftFunctionError : error reading database using DbmServer or calling <em>notify()</em> function of alarm server.
  */
  ScsStatus sendEvent(short       classId,
		      const char *objectName,
		      short       objectId,
		      va_list     args);
  /**
     \par Description:
     this function returns the pointer of AlmServer created in ScsAlmExtern.
     \par Parameters :
     None.
     \return
     \li \c NULL : if the creation of external alarm had failed.
     \li \c Valid pointer otherwise.
  */
  ScsAlmServer* getAlmServer() const { return _scsAlmServer; };

  //@}

  /*
     this function declares a new (external) alarm.
     Do not use this function, it is not documented and not supported function (for affairs). Internal use is authorized only for SCADAsoft.
     \param objectName : object name (used as an equipment point alias) concerned by the alarm, if any,
     \param classId : identification number (0-999) of the alarm class (used to elaborate the unique external alarm identification number),
     \param objectId : object identification number (should be specified only if no object name parameter was specified),
     \param objectState : object state (ALMEXT_OBJ_STATE_NORMAL or ALMEXT_OBJ_STATE_ERROR) determining which alarm attributes of the configuration file will be used,
     \param message : the alarm message.

     \return
     \li \c ScsValid : success.
     \li \c AlmBadParamError : the value of an input parameter is not correct.
     \li \c AlmInternalError : no configuration data were found for specified alarm class.
     \li \c AlmRtapFunctionError : error reading database using Rtap.
     \li \c AlmScadasoftFunctionError : error reading database using DbmServer or calling <em>notify()</em> function of alarm server.
  */
  ScsStatus notify(short       classId,
                   short       objectId,
                   const char *objectName,
                   int         objectState, 
                   const char* message);

  /**
     \par Description:
     this function declares a new (external) event.
     Do not use this function, it is not documented and not supported function (for affairs). Internal use is authorized only for SCADAsoft.
     \param classId  [in]: identification number (0-999) of the event class,
     \param objectName  [in]: object name (used as an equipment point alias) concerned by the event, if any,
     \param objectId  [in]: object identification number (should be specified only if no object name parameter was specified),
     \param message : the alarm message.
     \return
     \li \c ScsValid : success.
     \li \c AlmBadParamError : the value of an input parameter is not correct.
     \li \c AlmInternalError : no configuration data were found for specified event class.
     \li \c AlmRtapFunctionError : error reading database using Rtap.
     \li \c AlmScadasoftFunctionError : error reading database using DbmServer or calling <em>notify()</em> function of alarm server.
  */
  ScsStatus sendEvent(short       classId,
		      short       objectId,
		      const char *objectName,
		      const char* message);
  /*
     this function gets the format of the message.
     Do not use this function, it is not documented and not supported function (for affairs). Internal use is authorized only for SCADAsoft.
     classId : identification number (0-999) of the alarm class (used to elaborate the unique external alarm identification number),
     objectState : object state (ALMEXT_OBJ_STATE_NORMAL or ALMEXT_OBJ_STATE_ERROR) determining which alarm attributes of the configuration file will be used,
     message : the alarm message to return.

     return:
     ScsValid : success.
     AlmBadParamError : the value of an input parameter is not correct.
     AlmInternalError : no configuration data were found for specified alarm class.
     AlmRtapFunctionError : error reading database using Rtap.
     AlmScadasoftFunctionError : error reading database using DbmServer or calling <em>notify()</em> function of alarm server.
  */
  ScsStatus getMessageFormat(short         classId,
                          int           objectState,
                          char * const &messageFormat);
protected:
  ScsStatus readConfigFile(const char *fileName);
  ScsStatus getFromConfig(short         classId,
                          int           objectState,
			  int          &active,
                          char * const &valueAutomaton,
                          char * const &ackAutomaton,
                          char * const &state,
                          int          &severity,
                          char * const &objectName,
                          int          &functionalCat,
                          int          &geographicalCat,
                          int          &equipmentClass,
                          char * const &group1,
                          char * const &group2,
                          char * const &messageFormat,
                          char * const &dssEventType,
			  int          &theme);
  ScsStatus formatMessage(const char   *messageFormat,
                          char * const &message,
			  va_list       args);

  ScsStatus      _status;
  ScsAlmServer  *_scsAlmServer;
  OlsDataSet    *_configList;
  short          _sourceId;
};

#endif
