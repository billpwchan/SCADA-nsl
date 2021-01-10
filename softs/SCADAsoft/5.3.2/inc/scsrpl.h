/******************************************************************************/
/*									      */
/*  FILE		: scsrpl.h                                            */
/*  FULL NAME		: 					              */
/*									      */
/*----------------------------------------------------------------------------*/
/*  COMPANY		: THALES IS					      */
/*  CREATION DATE	: 2004/12/14					      */
/*  LANGUAGE		: C++						      */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2004.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW								      */
/*	                                				      */
/*............................................................................*/
/*  CONTENTS								      */
/******************************************************************************/

#ifndef _SCSRPL_H
#define _SCSRPL_H


/** \file
    \brief Access to the Replay (RPL) component.
*/

#include "scs.h"
#include "scsdefs.h"
#include "scstrace.h"

/*----------------------------------------------------------------------------*/
/*  TRACE								      */
/*  ex: RplTrace(LEVEL, "Exemple %i", (int) 5 );			      */
/*----------------------------------------------------------------------------*/
#define RplTrace			ScsTraceFunction(RPL_SCSMODULE)
#define RplTraceLevel(level,message)	BaseTraceLevel(RPL_SCSMODULE,level, message)


class RplRecordMgrProxy;
class RplRecordServerProxy;
class RplReplayMgrIdl;
class RplReplayIdl;
class RplReplayClient_i;
class RplRecordClientMgrIdl_i;

#define RPLSNAPFILENAME "S_"
#define RPLINCRFILENAME "I_"
#define RPLDIRNAME "Replay"
#define RPLSEPARATORSECMSEC '_'

/**
   \brief This class is used to store a snapshot file information.

\code#include "scsrpl.h"\endcode
*/

class RPL_API RplRecordServerFilesInfo {
 public:

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates a class containing snap files informations.
     \par Return values:
     none.
  */
  RplRecordServerFilesInfo(const char* snapFileName, timeval snapFileDate);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~RplRecordServerFilesInfo();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     Get the snapshot file name
     \par Parameters:
     \par Return values:
     File name.
  */
  char    *getSnapFileName();

  /**
     \par Description:
     Get the snapshot file date
     \par Parameters:
     \par Return values:
     File date.
  */
  timeval  getSnapFileDate();
  //@}

 private:
  char    *_snapFileName;
  timeval  _snapFileDate;

};

/**
   \brief This class is used to store RplRecordMgr informations.

\code#include "scsrpl.h"\endcode
*/

class RPL_API RplRecordServerInfo {
 public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
  */
  RplRecordServerInfo();

  /**
     \par Description:
  */
  ~RplRecordServerInfo();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     allocate the list of information on full snapshot files.
     \par Parameters:
     pSize : number of full snapshot files.
     \par Return values:
     none
  */
  void setSnapFileListSize(int pSize);
  /**
     \par Description:
     allocate the list of information on incremental snapshot files.
     \par Parameters:
     pSize : number of incremental snapshot files.
     \par Return values:
     none
  */
  void setIncrFileListSize(int pSize);

  /**
     \par Description:
     returns the activation of the record manager.
     \par Parameters:
     none.
     \par Return values:
     long : activation
  */
  long isRecServerActivated();

  //@}


  RplRecordServerFilesInfo** _snapFileList;
  int                     _snapFileSize;
  RplRecordServerFilesInfo** _incrFileList;
  int                     _incrFileSize;
  long _activated;
private:

};

typedef ScsStatus (*FullSnapshotCallback)(void *arg,
                                          AntPathName &pathName);

/**
   \brief This class is the interface class for recording of the RPL component.

\code#include "scsrpl.h"\endcode
*/

class RPL_API RplRecordMgr {
 public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object connected to the Record manager.
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required Record manager is running.
     \param serverName  [in]: name of the Record manager.
     \param priority  [in]: priority of the messages to the Record manager (only useful with redudancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  RplRecordMgr(const char*        logicalEnv,
	       const char*        serverName = "RplRecordMgr",
	       ScsPriorityLevels  priority   = SCS_PRIORITY_NORMAL);
  /**
     \par Description:
     destructor. This function closes the connection with the Record manager.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~RplRecordMgr();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     return the status of the connection to the server process.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : in other cases
  */
  ScsStatus getStatus () const {return _status;};
  
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
     change RplRecordManager corba object proxy.
     \param timeout  [in]: time-out value (in ms).
     \par Return values:
     none
  */
  void changeTimeout(const unsigned int & timeout);

  /**
     \par Description:
     record manager client informs of the full snapshot just created.
     \param in_snapshotName [in]:  client full snapshot file name.
     \par Return values:
     none
  */
  ScsStatus doneSnapshot(const char *in_snapshotName) const;

  /**
     \par Description:
     Connect as a record manager client.
     \param period           [in]: full snapshot period,
     \param snapshotCallback [in]: full snapshot callback,
     \param snapshotArg      [in]: full snapshot callback argument,
     \param snapshotFileName [in]: snapshot file name,
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus connect(int period,
		    FullSnapshotCallback snapshotCallback,
		    void *snapshotArg = 0,
		    const char *snapshotFileName = NULL);

  /**
     \par Description:
     General record request.
     \param sec [in]: record date (number of seconds parts since 1970),
     \param usec [in]: record date (number of micro-seconds parts),
     \param recordSize [in]: record size,
     \param record [in]: record buffer.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus record(long sec,
		   long usec,
		   long recordSize,
                   const char *record) const;

  /**
     \par Description:
     Get the client identification.
     \return
     \li \c client identification.
  */
  long getClientID() { return _clientID; };

  /**
     \par Description:
     Get the snapshot directory.
     \return
     \li \c snapshot directory.
  */
  const char *getSnapshotDir() { return _snapshotDir; };

  /**
     \par Description:
     Get the snapshot filename.
     \return
     \li \c snapshot fileName.
  */
  const char *getSnapshotFileName() { return _snapshotFileName; };

  /**
     \par Description:
     DBK information to be recorded (SCADAsoft internal usage).
  */
  ScsStatus recordDBK(long sec,
		      long usec,
		      long classID,
		      long instanceID,
		      long attributeID,
		      long contextID,
		      long subContextID,
		      long sizeOfBufferValue,
		      const char *bufferValue,
		      long type,
		      long recordStart,
		      long recordEnd,
		      long fieldStart,
		      long fieldEnd) const;

  /**
     \par Description:
     DBK information to be recorded (SCADAsoft internal usage).
  */
  int isActivated();
  
  /**
     \par Description:
     Get the proxy to the server (SCADAsoft internal usage).
  */
  RplRecordMgrProxy *getProxy() { return _proxy;}

  //@}


private:

  RplRecordMgrProxy  *_proxy;
  ScsStatus           _status;
  long                _clientID;
  char               *_snapshotDir;
  char               *_snapshotFileName;
  RplRecordClientMgrIdl_i *_client;
};


/**
   \brief This class is the interface class for the recording exported services of the RPL component.

\code#include "scsrpl.h"\endcode
*/

class RPL_API RplRecordServer {
 public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object connected to the Record manager.
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required Record manager is running.
     \param serverName  [in]: name of the Record manager.
     \param priority  [in]: priority of the messages to the Record manager (only useful with redudancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  RplRecordServer(const char*        logicalEnv,
	       const char*        serverName = "RplRecordMgr",
	       ScsPriorityLevels  priority   = SCS_PRIORITY_NORMAL);
  /**
     \par Description:
     destructor. This function closes the connection with the Record manager.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~RplRecordServer();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     return the status of the connection to the server process.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : in other cases
  */
  ScsStatus getStatus () const {return _status;};
  
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
     change RplRecordManager corba object proxy.
     \param timeout  [in]: time-out value (in ms).
     \par Return values:
     none
  */
  void changeTimeout(const unsigned int & timeout);

  /**
     \par Description:
     request an activation or deactivation on Record Manager.
     \param in_ActivationFlag [in]: activation flag (0 for false, 1 for true).
     \return
     \li \c ScsValid : successful return,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus activate(long in_ActivationFlag);

  /**
     \par Description:
     Get the proxy to the server (SCADAsoft internal usage).
  */
  RplRecordServerProxy *getProxy() { return _proxy;}

  /**
     \par Description:
     get the replay manager informations.
     \param infos [out]: informations on record manager.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getInfos(RplRecordServerInfo &infos) const;

  /**
     \par Description:
     request a full snapshot of an environment.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus doSnapshot();

  //@}

private:

  RplRecordServerProxy  *_proxy;
  ScsStatus           _status;
};

class RplCatalogueItem;
class RplCatalogue;

class RPL_API ScsRplReplayEmulator 
{
public:
    ScsRplReplayEmulator();
    virtual ~ScsRplReplayEmulator();
    
    virtual ScsStatus init(long pDate);
    virtual ScsStatus go(timeval pTime);

protected:
    RplCatalogueItem* getCorrectSnapName(RplCatalogue* pCatalogue, long pDate);
    ScsStatus getCataloguesIndexesBetweenDates(RplCatalogue* pCatalogue, 
                                          const timeval pTimeFrom, 
                                          const timeval pTimeTo,
                                          int& pFirstIndex,
                                          int& pLastIndex);
    RplCatalogue* _snapCatalogue;
    RplCatalogue* _incrCatalogue;

    int _isInitialized;
private:

};


/**
   \brief This class is used to store a snapshot file information.

\code#include "scsrpl.h"\endcode
*/
class RPL_API RplReplayMgrFilesInfo {
 public:

  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates a class containing snap files informations.
     \par Return values:
     none.
  */
  RplReplayMgrFilesInfo(const char* snapFileName, timeval snapFileDate);

  /**
     \par Description:
     destructor.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~RplReplayMgrFilesInfo();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     Get the snapshot file name
     \par Parameters:
     \par Return values:
     File name.
  */
  char    *getSnapFileName();

  /**
     \par Description:
     Get the snapshot file date
     \par Parameters:
     \par Return values:
     File date.
  */
  timeval  getSnapFileDate();
  //@}

 private:
  char    *_snapFileName;
  timeval  _snapFileDate;

};

/**
   \brief This class is used to store RplReplayMgr informations.

\code#include "scsrpl.h"\endcode
*/
class RPL_API RplReplayMgrInfo {
 public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
  */
  RplReplayMgrInfo();

  /**
     \par Description:
  */
  ~RplReplayMgrInfo();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     allocate the list of information on full snapshot files.
     \par Parameters:
     pSize : number of full snapshot files.
     \par Return values:
     none
  */
  void setSnapFileListSize(int pSize);
  /**
     \par Description:
     allocate the list of information on incremental snapshot files.
     \par Parameters:
     pSize : number of incremental snapshot files.
     \par Return values:
     none
  */
  void setIncrFileListSize(int pSize);

  /**
     \par Description:
     \par Parameters:
     \par Return values:
     none
  */
  void setUserInfo(const char* userInfo);

  /**
     \par Description:
     returns the user information set by set setUserInfo.
     \par Parameters:
     none.
     \par Return values:
     none
  */
  char *getUserInfo();

  //@}


  float _speed;
  long  _startDate;
  long  _currentState;

  RplReplayMgrFilesInfo** _snapFileList;
  int                     _snapFileSize;
  RplReplayMgrFilesInfo** _incrFileList;
  int                     _incrFileSize;
private:
  char *_userInfo;

};


/**
   \brief This class is the interface class for the replaying exported services of the RPL component.

\code#include "scsrpl.h"\endcode
*/

class RPL_API RplReplayMgr {
 public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object connected to the Replay manager.
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required Replay manager is running.
     \param serverName  [in]: name of the Replay manager.
     \param priority  [in]: priority of the messages to the Replay manager (only useful with redudancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  RplReplayMgr(const char*        logicalEnv,
	       const char*        serverName = "RplReplayMgr",
	       ScsPriorityLevels  priority   = SCS_PRIORITY_NORMAL);
  /**
     \par Description:
     destructor. This function closes the connection with the Replay manager.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~RplReplayMgr();
  //@}

  /**@name Typedefs / defines*/
  //@{
  /** 
      \par Description:
     enum replay manager state (see <em>getInfos()</em> function).
      \code
      enum WorkingState {
         WAITFORINIT = 1,
         READY,
         RUNNING,
         FREEZE
      }; \endcode
      \par Values:
      \li \c WAITFORINIT : the replay manager is waiting for initialization.
      \li \c READY : the replay manager is ready and is waiting for start.
      \li \c RUNNING : the replay manager is running.
      \li \c FREEZE : the replay manager is freezed.
  */
  enum WorkingState {
    WAITFORINIT = 1,
    READY,
    RUNNING,
    FREEZE
  };

  /**@name General member functions*/
  //@{
  /**
     \par Description:
     return the status of the connection to the server process.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : in other cases
  */
  ScsStatus getStatus () const {return _status;};
  
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
     change RplReplayManager corba object proxy.
     \param timeout  [in]: time-out value (in ms).
     \par Return values:
     none
  */
  void changeTimeout(const unsigned int & timeout);

  /**
     \par Description:
     get the replay manager informations.
     \param infos [out]: RplReplayManager infos.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus getInfos(RplReplayMgrInfo & infos);

  /**
     \par Description:
     request a start of a replay environment.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus start(float pSpeed);

  /**
     \par Description:
     request a stop of a replay environment.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus stop();

  /**
     \par Description:
     request a freeze of a replay environment.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus freeze();

  /**
     \par Description:
     request a unFreeze of a replay environment.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus unFreeze();

  /**
     \par Description:
     request a jump in time.
     \param stepTime        [in]: step time in milliseconds.
      \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus step(unsigned int stepTime);

  /**
     \par Description:
     request a init of a replay environment.
     \param pDate        [in]: start date in seconds.
     \param pSessionInfo [in]: session user's information.
      \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus init(long pDate, const char *pSessionInfo = NULL);

  /**
     \par Description:
     request a snapshot of a replay environment in Training mode.
     \param pSnapPath        [in]: snapshot path.
      \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus snapshotTraining(const char *pSnapPath);

  /**
     \par Description:
     set the emulated time from an external way (training mode only)
     \param pDate        [in]: date to set.
      \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus setTime(timeval pDate);

  //@}

private:

  void rebind();

  SCS_SL_STD(string)   _service;
  SCS_SL_STD(string)   _host;
  RplReplayMgrIdl*     _server;
  ScsStatus            _status;
};

/**
   \brief This class is the interface class for replaying of the RPL component.

   The class <em>RplReplay</em>.
\code#include "scsrpl.h"\endcode
*/

class RPL_API RplReplay {
 public:
  /**@name Constructors / destructor*/
  //@{
  /**
     \par Description:
     constructor. This function creates an interface object connected to the Replay manager.
     \param logicalEnv  [in]: name of the logical SCADAsoft environment in which the required Replay manager is running.
     \param serverName  [in]: name of the Replay manager.
     \param priority  [in]: priority of the messages to the Replay manager (only useful with redudancy).
     \par Return values:
     none. The result of the connection can be obtain by calling the <em>getStatus()</em> function.
  */
  RplReplay(const char*        logicalEnv,
	    const char*        serverName = "RplReplayMgr",
	    ScsPriorityLevels  priority   = SCS_PRIORITY_NORMAL);
  /**
     \par Description:
     destructor. This function closes the connection with the Replay manager.
     \par Parameters:
     none.
     \par Return values:
     none.
  */
  ~RplReplay();
  //@}

  /**@name General member functions*/
  //@{ 
  /**
     \par Description:
     return the status of the connection to the Replay manager process.
     \par Parameters:
     none.
     \return
     \li \c ScsValid : success.
     \li \c ScsError : in other cases
  */
  ScsStatus getStatus () const {return _status;};
  
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
     request a registerForReplay of a replay environment.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  ScsStatus registerForReplay(ScsRplReplayEmulator * in_replayEmulator);

  /**
     \par Description:
     get the Rrequest a full snapshot of an environment.
     \param snapshotDir [in]: snapshot directory.
     \return
     \li \c ScsValid : successful completion,
     \li \c !=ScsValid : in other case.
  */
  //@}

private:

  RplReplayIdl*      _server;
  RplReplayClient_i* _client;
  ScsStatus          _status;
};

#endif
