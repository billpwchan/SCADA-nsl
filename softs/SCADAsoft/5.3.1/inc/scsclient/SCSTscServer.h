// ----------------------------------------------------------------------------
// COMPANY  : THALES-IS
// LANGUAGE : C++
// ----------------------------------------------------------------------------
// Copyright © THALES.
// All rights reserved.
// Unauthorized access, use, reproduction or distribution is prohibited.
// ----------------------------------------------------------------------------
// Module   : scsclient
// File     : SCSTscServer.h
// Date     : 2015/10/12
// ----------------------------------------------------------------------------
// HISTORY  :
// ----------------------------------------------------------------------------
#ifndef SCSCLIENT_SCSTSCSERVER_H
#define SCSCLIENT_SCSTSCSERVER_H
// ----------------------------------------------------------------------------
#include <scsclient/SCSServer.h>
// ----------------------------------------------------------------------------

class TscTaskArg;
// ----------------------------------------------------------------------------
/// \class SCSTscServer
/// \brief TSC server services.
// ----------------------------------------------------------------------------
class SCSCLIENT_API SCSTscServer : public SCSServer {
public:
  /// \enum Type
  /// \par Description:
  /// Defines the type of Scadasoft service. Its value is unique and identifies this service among all others Scadasoft services.
  enum Type { scs_type = 13 };
  /// \par Description:
  /// Creates a new Scadasoft server services.
  /// \param[in] envname The Scadasoft server environment name.
  /// \param[in] servername The Scadasoft service name.
  SCSTscServer(const char* envname, const char* servername);
  virtual ~SCSTscServer();
  /// \par Description:
  /// Tries to establish a connection to the Scadasoft server.
  /// \param[in] direct Indicates whether or not the connection must be direct.
  /// \return The operation result (true means a success, false otherwise).
  virtual bool connect(bool direct = false);
  /// \par Description:
  /// Tries to close the connection to the Scadasoft server.
  /// \return The operation result (true means a success, false otherwise).
  virtual bool disconnect();
 
  /**
     \par Description:
     retrieves the daygroup names and Ids.
     \param nbDayGroups [out]: daygroup count,
     \param ids        [out]: Id list,
     \param names      [out]: name list.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int getDayGroupNamesAndIds(int& nbDayGroups, long*& ids, char**& names) const;

  /**
     \par Description:
     get a daygroup date with the daygroup Id.
     \param dgId   [in]: daygroup Id,
     \param nbDates [out]: daygroup date count,
     \param dates  [out]: daygroup date list.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int getDates(int dgId, int& nbDates, unsigned long*& dates) const;

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
  int setDates(int dgId, int nbDates, unsigned long* dates, const char* clientName = NULL) const;

  /**
     \par Description:
     retreives the task name list.
     \param nbTasks  [out]: task count,
     \param taskNames [out]: task name list.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int getTaskNames(int& nbTasks, char**& taskNames) const;
  
  /**
     \par Description:
     add a task.
     \param taskString  [in]: task string,
     \param clientName  [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int addTask(const char* taskString, const char* clientName = NULL) const;

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
  int addTask(const char* taskName, const char* description, const char* command, TscTaskArg* arguments,		   
		     const char* startTime ="*", const char* endTime = "*", int interval = 0,
		     const char* filter = "* * * * * *", int inhibited = 0, int log = 0,
		     int removeAtEnd = 0, const char* clientName = NULL) const;

  /**
     \par Description:
     remove a task.
     \param taskName  [in]: task name,
     \param clientName  [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int removeTask(const char* taskName, const char* clientName = NULL) const;

  /**
     \par Description:
     disable a task.
     \param taskName   [in]: task name,
     \param clientName [in]: client name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int disableTask(const char* taskName, const char* clientName = NULL) const;
  
  /**
     \par Description:
     enable a task.
     \param taskName   [in] : task name.
     \param clientName [in]: client name.
     \return
     \li \c ScsValid : success.
     \li \c !=ScsValid : in other case.
  */
  int enableTask (const char* taskName, const char* clientName = NULL) const;

  /**
     \par Description:
     enable a task.
     \param taskName [in] : task name.
     \param status   [out]: task name.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int isEnabled(const char* taskName, int& status) const;

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
  int setInterval(const char* taskName, int interval, const char* clientName = NULL) const;
  
  /**
     \par Description:
     set a task interval.
     \param taskName [in]: task name,
     \param interval [in]: task interval in minute.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int getInterval(const char* taskName, int& interval) const;

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
  int setFilter(const char* taskName, const char* filter, const char* clientName = NULL) const;

  /**
     \par Description:
     get a task filter.
     \param taskName [in]: task name,
     \param filter [out]: task filter.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int getFilter(const char* taskName, char*& filter) const;

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
  int setArguments(const char* taskName, const char* arguments, const char* clientName = NULL) const;

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
  int setArguments(const char* taskName, TscTaskArg* arguments, const char* clientName = NULL) const;

  /**
     \par Description:
     get a task arguments.
     \param taskName [in]: task name,
     \param arguments [out]: task arguments.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int getArguments(const char* taskName, char*& arguments) const;

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
  int setEndTime(const char* taskName, unsigned long endTime, const char* clientName = NULL) const;
  
  /**
     \par Description:
     get a task end time.
     \param taskName [in]: task name,
     \param endTime [out]: task end time.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int getEndTime(const char* taskName, unsigned long& endTime) const;

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
  int setStartTime(const char* taskName, unsigned long startTime, const char* clientName = NULL) const;
  /**
     \par Description:
     get a task start time.
     \param taskName [in]: task name,
     \param startTime [out]: task start time.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int getStartTime(const char* taskName, unsigned long& startTime) const;

  /**
     \par Description:
     get a task command.
     \param taskName  [in] : task name.
     \param command   [out]: task command.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int getCommand(const char* taskName, char*& command) const;

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
  int setCommand(const char* taskName, const char* command, const char* clientName = NULL) const;

 /**
     \par Description:
     get a task type.
     \param taskName [in] : task name.
     \param taskType [out]: task type.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
#define TSC_TASKTYPE_ENUM_EXEC 0
#define TSC_TASKTYPE_ENUM_CMD 1
#define TSC_TASKTYPE_ENUM_GRC 2
#define TSC_TASKTYPE_ENUM_EVT 3
#define TSC_NB_TASKTYPE_ENUM 4
  int getTaskType(const char* taskName, int& taskType) const;

  /**
     \par Description:
     get a task description.
     \param taskName  [in]: task name.
     \param description [out]: task description.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int getDescription(const char* taskName, char*& description) const;

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
  int setDescription(const char* taskName, const char* description, const char* clientName = NULL) const;

  /**
     \par Log:
     get a task log flag.
     \param taskName  [in]: task name.
     \param log [out]: task log.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int getLog(const char* taskName, int& log) const;
  
  /**
     \par RemoveAtEnd:
     get a task removeAtEnd flag.
     \param taskName  [in]: task name.
     \param removeAtEnd [out]: task removeAtEnd.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  int getRemoveAtEnd(const char* taskName, int& removeAtEnd) const;
			   
  /// \par Description:
  /// Returns the type of this Scadasoft service.
  /// \return The value of the type.
  virtual int serverType() const { return scs_type; }

protected:
  SCSTscServer() {}
  SCSTscServer(const SCSTscServer&) {}
  virtual void changeState();

private:
  class SCSTscServerImpl;
  SCSTscServerImpl* m_impl;
};
// ----------------------------------------------------------------------------
#endif // SCSCLIENT_SCSTSCSERVER_H
