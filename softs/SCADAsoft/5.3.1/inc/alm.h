/******************************************************************************/
/*									      */
/*  FILE		: alm.h                                               */
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
// $Id: alm.h,v 1.13 1999/08/10 13:30:57 ylo Exp $
//
// HISTORY:
// $Log: alm.h,v $
// Revision 1.13  1999/08/10 13:30:57  ylo
// Make almserver working with synchronous and asynchronous redundancy.
//
// Revision 1.12  1998/08/24 15:49:47  jpu
// Add environment parameter in initDatabase() and initialize()
//
// Revision 1.11  1998/07/16 13:14:19  jpu
// Remove AlmServer:: before subscribeToActions()
//
// Revision 1.10  1998/06/19 13:12:16  jpu
// Add acknowledgeAddress(), acknowledgeAddressWR() and getAlarmIds()
//
// Revision 1.9  1998/05/28 18:14:33  jpu
// Change all long parameters to int for port on DEC OSF1 v4.0
//
// Revision 1.8  1998/04/03 16:32:19  jpu
// Add define of ALM_MODULE
//
// Revision 1.7  1998/03/23 18:27:28  jpu
// Modifications relative to redundancy
//
// Revision 1.6  1998/03/13 13:37:53  bertrand
// add define AlmTrace.
//
// Revision 1.5  1997/12/22 16:20:49  jpu
// Add initDatabase()
//
// Revision 1.4  1997/12/19 18:52:53  jpu
// Add initialize(), fieldsInitDone() and initASConnection()
//
// Revision 1.3  1997/12/05 15:37:59  bertrand
// incorporate comments for doc++
//
// Revision 1.2  1997/11/18 13:24:33  jpu
// Modify prototype of AlmServer() to include environment
//
// Revision 1.1  1997/10/29 12:34:57  jpu
// Initial revision
//
/******************************************************************************/
#ifndef _ALM_H
#define _ALM_H

/*----------------------------------------------------------------------------*/
/*  ENVIRONMENT								      */
/*----------------------------------------------------------------------------*/
#include "scs.h"
#include "sec.h"
#include "secerror.h"
#include "ols.h"
#define AlmTrace	ScsTraceFunction(ALM_SCSMODULE)
#define AlmTraceLevel(level, message) BaseTraceLevel(ALM_SCSMODULE, level, message)

// Alarm list name
#define ALARM_LIST_NAME    "AlarmList"

// Field names of alarm list
#define PLIN_FIELD_NAME	   "Plin"
#define AIN_FIELD_NAME	   "Ain"
#define INDEX_FIELD_NAME   "Index"
#define ACK_FIELD_NAME	   "Acknowledge"
#define TIME_FIELD_NAME	   "Time"
#define MSG_FIELD_NAME	   "Message"
#define SHELVE_FIELD_NAME  "Shelve"

// Alarm system connection types
enum { SCS_CURRENT_FUTURE_ALARMS = 0,
       SCS_FUTURE_ALARMS };


class AlmIdl;
class AlmServerIdl_i;

/* Warning: this class is no more documented...
   The AlmServer class documented is in the "scsalm.h" file.
  #include <alm.h>.
  .
  */
class AlmServer : public OlsManager
{
public:
  /* name Constructors / destructor*/
  /**/
  /*
    .
    constructor: create a connection with the alarm server serverName running in SCADAsoft environment environment.
    */
  AlmServer(const char *environment = 0, const char *serverName = "AlmServer");
  /*
    .
    destructor: close the connection with the alarm server.
  */
  ~AlmServer();
  /**/

  /* name General Usage Member functions*/
  /**/
  /*
     .
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
  /*
    .
    Description:
    subscription for a stand-by server to the operator actions received on the hot server.
    Return Values:
    the possible values for the returned ScsStatus are: ScsValid or
    \begin{itemize}
    \li \c     AlmORBError: if an ORB exception was caught.
    \end{itemize}
    */
  ScsStatus subscribeToActions(AlmIdl   *standbyServer,
			       char     *&alarmsList);
  /*
    .
    Description:
    acknowledge the alarms specified in the identifier list parameter. If any alarms cannot be acknowledged (because they do not exist or are already acknowledged), the method returns an error code. count is set to the number of ids in the list.
    Return Values:
    the possible values for the returned ScsStatus are: ScsValid or
    \begin{itemize}
    \li \c     AlmRtapFunctionError: if an Rtap function has returned an error,
    \li \c     AlmORBError: if an ORB exception was caught.
    \end{itemize}
    */
  ScsStatus acknowledge(int *alarmIdList, short &count);
  /*
    .
    Description:
    acknowledge the alarms specified in the plin list and ain list parameters. If any alarms cannot be acknowledged (because they do not exist or are already acknowledged), the method returns an error code. count is set to the number of plin or ain in the lists.
    Return Values:
    the possible values for the returned ScsStatus are: ScsValid or
    \begin{itemize}
    \li \c     AlmRtapFunctionError: if an Rtap function has returned an error,
    \li \c     AlmORBError: if an ORB exception was caught.
    \end{itemize}
    */
  ScsStatus acknowledgePlinAin(int *plinList, int *ainList, short &count);
  /*
    .
    Description:
    acknowledge the alarm specified in the ScsAddress parameter. If the specification level of the address is the point, the function acknowledges all the alarms associated with the point, else if the specification level of the address is the attribute, the function acknowledges the alarm associated with the attribute. If there is some security restriction on some alarms, the only returned information is the error return code: AlmSecurityRestrictionError (see acknowledgeAddressWR() method).
    Return Values:
    the possible values for the returned ScsStatus are: ScsValid or
    \begin{itemize}
    \li \c     AlmRtapFunctionError: if an Rtap function has returned an error,
    \li \c     AlmORBError: if an ORB exception was caught.
    \li \c     AlmSecurityRestrictionError: if there is a security restriction on some alarms.
    \end{itemize}
    */
  ScsStatus acknowledgeAddress(ScsAddress address);
  /*
    .
    Description:
    acknowledge the alarm specified in the ScsAddress parameter (with return values). If the specification level of the address is the point, the function acknowledges all the alarms associated with the point, else if the specification level of the address is the attribute, the function acknowledges the alarm associated with the attribute. If there is some security restriction on some alarms, the alarms are not acknowledged and some information are returned: the list and the number of id of alarms which could be acknowledged, the list and the number of id of alarms which could not be acknowledged and a list of status corresponding to the second list of alarm ids.
    Return Values:
    the possible values for the returned ScsStatus are: ScsValid or
    \begin{itemize}
    \li \c     AlmRtapFunctionError: if an Rtap function has returned an error,
    \li \c     AlmORBError: if an ORB exception was caught.
    \li \c     AlmSecurityRestrictionError: if there is a security restriction on some alarms.
    \end{itemize}
    */
  ScsStatus acknowledgeAddressWR(ScsAddress   address,
				 int        *&validIdList,
				 int         &nbValidIds,
				 int        *&noValidIdList,
				 int         &nbNoValidIds,
				 ScsStatus  *&statusList);
  /*
    .
    Description:
    returns the identificators of the alarms associated with the point specified in the ScsAddress parameter. If the specification level of the address is the point, the function returns all the identificators of all the alarms associated with the point, else if the specification level of the address is the attribute, the function returns the identificator of the alarm associated with the attribute.
    Return Values:
    the possible values for the returned ScsStatus are: ScsValid or
    \begin{itemize}
    \li \c     AlmRtapFunctionError: if an Rtap function has returned an error,
    \li \c     AlmORBError: if an ORB exception was caught.
    \end{itemize}
    */
  ScsStatus getAlarmIds(ScsAddress address, int *&idList, short &count);
  /*
    .
    Description:
    shelve the alarms specified in identifier list parameter. If any alarms cannot be shelved (because they do not exist or are already shelved), the method returns an error code. count is set to the number of ids in the list.
    Return Values:
    the possible values for the returned ScsStatus are: ScsValid or
    \begin{itemize}
    \li \c     AlmListActionError: if an action on the alarms list has returned an error,
    \li \c     AlmORBError: if an ORB exception was caught.
    \end{itemize}
    */
  ScsStatus shelve(int *alarmIdList, short &count);
  /*
    .
    Description:
    shelve the alarms specified in plin list and ain list parameters. If any alarms cannot be shelved (because they do not exist or are already shelved), the method returns an error code. count is set to the number of plin or ain in the lists.
    Return Values:
    the possible values for the returned ScsStatus are: ScsValid or
    \begin{itemize}
    \li \c     AlmListActionError: if an action on the alarms list has returned an error,
    \li \c     AlmORBError: if an ORB exception was caught.
    \end{itemize}
    */
  ScsStatus shelvePlinAin(int *plinList, int *ainList, short &count);
  /*
    .
    Description:
    unshelve the alarms specified in identifier list parameter. If any alarms cannot be unshelved (because they do not exist or are not shelved), the method returns an error code. count is set to the number of ids in the list.
    Return Values:
    the possible values for the returned ScsStatus are: ScsValid or
    \begin{itemize}
    \li \c     AlmListActionError: if an action on the alarms list has returned an error,
    \li \c     AlmORBError: if an ORB exception was caught.
    \end{itemize}
    */
  ScsStatus unshelve(int *alarmIdList, short &count);
  /*
    .
    Description:
    unshelve the alarms specified in plin list and ain list parameters. If any alarms cannot be unshelved (because they do not exist or are not shelved), the method returns an error code. count is set to the number of plin or ain in the list.
    Return Values:
    the possible values for the returned ScsStatus are: ScsValid or
    \begin{itemize}
    \li \c     AlmListActionError: if an action on the alarms list has returned an error,
    \li \c     AlmORBError: if an ORB exception was caught.
    \end{itemize}
    */
  ScsStatus unshelvePlinAin(int *plinList, int *ainList, short &count);
  /*
    .
    Description:
    inhibit the alarm generation for equipment.
    Return Values:
    the possible values for the returned ScsStatus are: ScsValid or
    \begin{itemize}
    \li \c     AlmRtapFunctionError: if an Rtap function has returned an error,
    \li \c     AlmORBError: if an ORB exception was caught.
    \end{itemize}
    */
  ScsStatus inhibit(const char *equipmentName);
  /*
    .
    Description:
    uninhibit the alarm generation for equipment.
    Return Values:
    the possible values for the returned ScsStatus are: ScsValid or
    \begin{itemize}
    \li \c     AlmRtapFunctionError: if an Rtap function has returned an error,
    \li \c     AlmORBError: if an ORB exception was caught.
    \end{itemize}
    */
  ScsStatus uninhibit(const char *equipmentName);
  /**/

private:
  ScsStatus      _status;
  AlmIdl        *_almServerIdl;
  char          *_userName;	// Name of user logged in current terminal
};

#endif

