//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : tsc.h                                                  */
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


#ifndef _TSC_H_
#define _TSC_H_

/** \file
    \brief Access to the Task Scheduler (TSC) component.
*/

#include "scs.h"
#include "tsctypes.h"

class TscTaskArg;
class TscProxy;

/**
   \brief This class allows the use of the management of task scheduler services exported 
   by the Task Scheduler Server.

   This class is the interface class for the services exported by the TSC server.
\code#include "tsc.h"\endcode
*/
class TSC_API TscServer
{

public:

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object connected to the TSC server.
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required TSC server is running.
     \param serverName  [in]: name of the TSC server.
     \param priority  [in]: priority of the messages to the TSC server (only useful with redudancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  TscServer(const char*        logicalEnv,
	    const char*        serverName = "TscServer",
	    ScsPriorityLevels  priority   = SCS_PRIORITY_NORMAL);
  /**
     \par Description:
     destructor. This function closes the connection with the TSC server.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~TscServer();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     return the TscServer object validity.
     \par Parameters:
     none.
     \return
     \li \c ScsStatus : if a CORBA proxy is established,
     \li \c ScsError : in other cases
  */
  ScsStatus isValid() const { return (_proxy ? _status : ScsError); };
  
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
     change TscServer corba object proxy.
     \param timeout  [in]: time-out value (in ms).
     \par Return values:
     none
  */
  void changeTimeout(const unsigned int & timeout);

  /**
     \par Description:
     retreives the daygroup names and Ids.
     \param nbDayGroups [out]: daygroup count,
     \param ids        [out]: Id list,
     \param names      [out]: name list.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getDayGroupNamesAndIds(unsigned short& nbDayGroups, 
				   long*&  ids, 
				   char**& names) const;

  /**
     \par Description:
     get a daygroup date with the daygroup Id.
     \param dgId   [in]: daygroup Id,
     \param nbDates [out]: daygroup date count,
     \param dates  [out]: datygroup date list.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getDates(unsigned short  dgId, 
		     unsigned long&  nbDates, 
		     unsigned long*& dates) const;

  /**
     \par Description:
     set a daygroup date with the daygroup Id.
     \param dgId   [in]: daygroup Id,
     \param nbDates [in]: daygroup date count,
     \param dates  [in]: daygroup date list,
     \param clientName  [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus setDates(unsigned short  dgId, 
		     unsigned long   nbDates, 
		     unsigned long*  dates,
		     char *clientName = NULL) const;

  /**
     \par Description:
     retreives the task name list.
     \param nbTasks  [out]: task count,
     \param taskNames [out]: task name list.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getTaskNames(unsigned long&  nbTasks,
			 char**& taskNames) const;
  /**
     \par Description:
     add a task.
     \param taskString  [in]: task string,
     \param clientName  [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus addTask(const char* taskString,
		    char *clientName = NULL) const;

  /**
     \par Description:
     add a task.
     \param taskName    [in]: task name,
     \param description [in]: task description,
     \param command     [in]: task command,
     \param arguments   [in]: task argument,
     \param startTime   [in]: task start time,
     \param endTime     [in]: task end time,
     \param interval    [in]: task interval in minute,
     \param filter      [in]: task filter,
     \param inhibited   [in]: task inhibition,
     \param log         [in]: task log flag,
     \param removeAtEnd [in]: task removeAtEnd flag,
     \param clientName  [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus addTask(const char* taskName,
		    const char* description,
		    const char* command,
		    TscTaskArg* arguments,		   
		    const char* startTime ="*",
		    const char* endTime = "*",
		    unsigned long interval = 0,
		    const char*  filter = "* * * * * *",
		    unsigned int inhibited = 0,
		    unsigned int log = 0,
		    unsigned int removeAtEnd = 0,
		    char *clientName = NULL) const;

  /**
     \par Description:
     remove a task.
     \param taskName  [in]: task name,
     \param clientName  [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus removeTask(const char* taskName,
		       char *clientName = NULL) const;

  /**
     \par Description:
     disable a task.
     \param taskName   [in]: task name,
     \param clientName [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus disableTask(const char* taskName,
			char *clientName = NULL) const;
  /**
     \par Description:
     enable a task.
     \param taskName   [in] : task name.
     \param clientName [in]: client name.
     \return
     \li \c ScsValid : success.
     \li \c !=ScsValid : in other case.
  */
  ScsStatus enableTask (const char* taskName,
			char *clientName = NULL) const;

  /**
     \par Description:
     enable a task.
     \param taskName [in] : task name.
     \param status   [out]: task name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus isEnabled(const char* taskName, 
		      long       &status) const;

  /**
     \par Description:
     set a task interval.
     \param taskName [in]: task name,
     \param interval [in]: task interval in minute,
     \param clientName  [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus setInterval(const char* taskName, 
			unsigned long interval,
			char *clientName = NULL) const;
  /**
     \par Description:
     set a task interval.
     \param taskName [in]: task name,
     \param interval [in]: task interval in minute.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getInterval(const char* taskName, 
			unsigned long& interval) const;

  /**
     \par Description:
     set a task filter.
     \param taskName [in]: task name,
     \param filter [in]: task filter,
     \param clientName  [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus setFilter(const char* taskName, 
		      const char* filter,
		      char *clientName = NULL) const;

  /**
     \par Description:
     get a task filter.
     \param taskName [in]: task name,
     \param filter [out]: task filter.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getFilter(const char* taskName, 
		      char*& filter) const;

  /**
     \par Description:
     set a task arguments.
     \param taskName   [in]: task name,
     \param arguments  [in]: task arguments,
     \param clientName [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus setArguments(const char* taskName, 
			 const char* arguments,
			 char *clientName = NULL) const;

  /**
     \par Description:
     set a task arguments.
     \param taskName   [in]: task name,
     \param arguments  [in]: task arguments,
     \param clientName [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus setArguments(const char* taskName, 
			 TscTaskArg* arguments,
			 char *clientName = NULL) const;

  /**
     \par Description:
     get a task arguments.
     \param taskName [in]: task name,
     \param arguments [out]: task arguments.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getArguments(const char* taskName, 
			 char*& arguments) const;

  /**
     \par Description:
     set a task end time.
     \param taskName [in]: task name,
     \param endTime [in]: task end time,
     \param clientName  [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus setEndTime(const char* taskName, 
		       unsigned long endTime,
		       char *clientName = NULL) const;
  /**
     \par Description:
     get a task end time.
     \param taskName [in]: task name,
     \param endTime [out]: task end time.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getEndTime(const char* taskName, 
		       unsigned long& endTime) const;

  /**
     \par Description:
     set a task start time.
     \param taskName [in]: task name,
     \param startTime [in]: task start time,
     \param clientName  [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus setStartTime(const char* taskName, 
			 unsigned long startTime,
			 char *clientName = NULL) const;
  /**
     \par Description:
     get a task start time.
     \param taskName [in]: task name,
     \param startTime [out]: task start time.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getStartTime(const char* taskName, 
			 unsigned long& startTime) const;

  /**
     \par Description:
     get a task command.
     \param taskName  [in] : task name.
     \param command   [out]: task command.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getCommand(const char* taskName, 
		       char*& command) const;

  /**
     \par Description:
     set a task command.
     \param taskName  [in] : task name.
     \param command   [in]: task command.
     \param clientName  [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus setCommand(const char* taskName, 
		       const char* command,
		       char *clientName = NULL) const;

 /**
     \par Description:
     get a task type.
     \param taskName [in] : task name.
     \param taskType [out]: task type.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getTaskType(const char* taskName, 
		        TscTaskType& taskType) const;

  /**
     \par Description:
     get a task description.
     \param taskName  [in]: task name.
     \param description [out]: task description.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getDescription(const char* taskName, 
			   char*& description) const;

  /**
     \par Description:
     set a task description.
     \param taskName  [in]: task name.
     \param description [in]: task description.
     \param clientName  [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus setDescription(const char* taskName, 
			   const char* description,
			   char *clientName = NULL) const;

  /**
     \par Log:
     get a task log flag.
     \param taskName  [in]: task name.
     \param log [out]: task log.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getLog(const char* taskName, 
		   int& log) const;
  /**
     \par RemoveAtEnd:
     get a task removeAtEnd flag.
     \param taskName  [in]: task name.
     \param removeAtEnd [out]: task removeAtEnd.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getRemoveAtEnd(const char* taskName, 
			   int& removeAtEnd) const;

  TscProxy * getProxy() { return _proxy;}
  //@}

private:

  TscProxy  * _proxy;
  ScsStatus   _status;

};

#endif
