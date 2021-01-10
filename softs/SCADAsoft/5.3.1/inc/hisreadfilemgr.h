/******************************************************************************/
/*                                                                            */
/*  FILE                : hisreadfilemgr.h                                    */
/*  FULL NAME           :                                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  COMPANY             : THALES                                              */
/*  CREATION DATE       : 03/11/2005                                          */
/*  LANGUAGE            : C++                                                 */
/*  AUTHOR              : J. de KOZAK                                         */
/*............................................................................*/
/*  Copyright © THALES                                                        */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/******************************************************************************/
#ifndef __HISREADFILEMGR_H_
#define __HISREADFILEMGR_H_

/**
  \file
  \brief Utility class used to read periodic archive files without any running SCADASoft envrionment.
*/

#include "histypes.h"

#ifndef RWSTD_HEADER_REQUIRES_HPP
#include <string>
#else
#include <string.hpp>
#endif

class HisArchiveFile;
class HisArchiveStructure;
class HisDatabaseStructure;

#define STATE_NUMBER 6
#define TRANS_NUMBER 5

/**
  \brief A HisReadFileMgr is an automaton used to make the link between HisArchiveFile, HisArchiveStructure and HisDatabaseStructure objects. It is able to decode an archive file without any running SCADASoft environment. Please refer to statechart diagram before using automaton.
  (An object of this class should not be accessed from two different threads.)
*/

class HIS_API HisReadFileMgr
{
 public:
  //automate
  /**@name Typedefs / defines*/
  //@{
  /**
     \par Description:
     enum corresponding to the possible values of automaton state.

     \code
     enum State {
     INIT = 0,
     READY = 1,
     CLOSED = 2,
     ERROR = 3,
     CACHE_LOADED = 4,
     ANY = 5,
     ENDST = 6
     }; \endcode
     \par Values:
     \li \c INIT: automaton has just been built,
     \li \c READY: archive file is open, automaton is waiting for requests,
     \li \c CLOSED: archive file is closed, automaton is waiting to open another archive file,
     \li \c ERROR: automaton is in error, check why with getError function,
     \li \c CACHE_LOADED: one load request has been received, next read requests will use cache.

  */
  enum State {
    MGR_INIT = 0,
    MGR_READY = 1,
    MGR_CLOSED = 2,
    MGR_ERROR = 3,
    MGR_CACHE_LOADED = 4,
    MGR_ANY = 5,
    MGR_ENDST = 6
  };
  /**
     \par Description:
     enum corresponding to the possible values of automaton transition.

     \code
     enum Trans {
     FileOpen = 0,
     Read = 1,
     Load = 2
     Close = 3,
     Error = 4
     }; \endcode
     \par Values:
     \li \c FileOpen: send an opening request to the automaton,
     \li \c Read: send a read request to the automaton,
     \li \c Load: send a load cache request to the automaton
     \li \c Close: send a close request to the automaton,
     \li \c Error: send an error to the automaton.

  */
  enum Trans {
    FileOpen = 0,
    Read = 1,
    Load = 2,
    Close = 3,
    Error = 4
  };
  /**
     \par Description:
     enum corresponding to the possible values of error.

     \code
     enum ErrorType {
     BadTransition = 0,
     FileNotExist = 1,
     FileUnreadable = 2,
     BadFormat = 3,
     BadRequest = 4
     }; \endcode
     \par Values:
     \li \c BadTransition: current state of automaton does not permit the requested transition,
     \li \c FileNotExist: archive file does not exist,
     \li \c FileUnreadable: archive file is not readable,
     \li \c BadFormat: archive file has not the right format,
     \li \c BadRequest: read request is not correct.

  */
  enum ErrorType {
    BadTransition = 0,
    FileNotExist = 1,
    FileUnreadable = 2,
    BadFormat = 3,
    BadRequest = 4
  };
  /**
     \par Description:
     enum corresponding to available levels of trace.

     \code
     enum TraceLevel {
     ErrorLevel = 1,
     AutomatonLevel = 2,
     FunctionLevel = 4
     }; \endcode
     \par Values:
     \li \c ErrorLevel: prints all error messages on standard error output,
     \li \c AutomatonLevel: prints all services requested to automaton <em>HisReadFileMgr</em> on standard output,
     \li \c FunctionLevel: prints all 'in/out' of internal functions on standard output.
  */
  //Any modification here should be reported in histracelib.h
  enum TraceLevel {
    ErrorLevel = 1,
    AutomatonLevel = 2,
    FunctionLevel = 4
  };
  //@}

  /**@name Constructor / Destructor*/
  //@{
  /**
     \par Description:
     Constructor.
     Create a HisReadFileMgr object with the specified archive structure and database structure.

     \param archiveStructureFileName [in]: name of the archive structure file (with full path).
     \param databaseStructureFileName [in]: name of the database structure file (with full path).
  */
  HisReadFileMgr(const char* archiveStructureFileName, const char* databaseStructureFileName);
  /**
     \par Description:
     Delete a HisReadFileMgr object.
  */
  ~HisReadFileMgr();
  //@}

  /**@name General Usage member functions*/
  //@{
  /**
     \par Description:
     Open the archive file.

     \param archiveFileName [in]: the name of the archive file to open (with full path).

     \par Return values:
     None.

  */
  void open(const char* archiveFileName);
  /**
     \par Description:
     Close the archive file.

     \par Parameters:
     None.

     \par Return values:
     None.
  */
  void close();
  /**
     \par Description:
     Read selected points in archive file for specified interval.

     \param inPoints [in]: the <em>HisPointSet</em> object is used to choose which points are read in file.
     \param startTime [in]: is used to limit read request in time.
     \param endTime [in]: is used to limit read request in time.
     \param outValues [out]: the <em>HisDbDataSet</em> object will contain all values in requested interval.

     \par Return values:
     None.
  */
  void read(HisPointSet& inPoints, unsigned long startTime, unsigned long endTime, HisDbDataSet& outValues);
  /**
     \par Description:
     Read all points in archive file for the biggest time interval.

     \param outPoints [out]: the <em>HisPointSet</em> object will contain all points available in file.
     \param outValues [out]: the <em>HisDbDataSet</em> object will contain all values for all points.

     \par Return values:
     None.
  */
  void readAll(HisPointSet& outPoints, HisDbDataSet& outValues);
  /**
     \par Description:
     Get point number configured in archive.

     \par Parameters:
     None.

     \par Return values:
     Point number.
  */
  unsigned long getNbPoints();
  /**
     \par Description:
     Read all points in archive file. This function does not supply point values.

     \param outPointSet [out]: the <em>HisPointSet</em> object will contain all points available in file.

     \par Return values:
     None.
  */
  void getPointSet(HisPointSet& outPointSet);
  /**
     \par Description:
     Get period number configured in archive.

     \par Parameters:
     None.

     \par Return values:
     Period number.
  */
  unsigned long getNumPeriod();
  /**
     \par Description:
     Get beginning time of archive file (corresponding to the date of the first value in archive file).

     \par Parameters:
     None.

     \par Return values:
     Start time of archive file.
  */
  unsigned long getStartTime();
  /**
     \par Description:
     Get ending time of archive file (corresponding to the date of the last value in archive file). It is calculated with formula endTime = startTime + period * (numPeriod-1).

     \par Parameters:
     None.

     \par Return values:
     End time of archive file.
  */
  unsigned long getEndTime();
  /**
     \par Description:
     Return the state of the automaton.

     \par Parameters:
     None.

     \par Return values:
     State of automaton.
  */
  State getState() const {return _currentState;};
  /**
     \par Description:
     Return the state in string format of the automaton.

     \par Parameters:
     None.

     \par Return values:
     State of automaton in string format.
  */
#ifdef SCS_STD
  std::string getStateLibel() const {return _stateLibels[(int)_currentState];};
#else
  string getStateLibel() const {return _stateLibels[(int)_currentState];};
#endif
  /**
     \par Description:
     Return the error type of the automaton. This function should only be used if automaton is in ERROR state.

     \par Parameters:
     None.

     \par Return values:
     Error type of automaton.
  */
  ErrorType getError() const {return _error;};
  /**
     \par Description:
     Return the error type string of the automaton. This function should only be used if automaton is in ERROR state.

     \par Parameters:
     None.

     \par Return values:
     Error type of automaton in string format.
  */
#ifdef SCS_STD
  std::string getErrorLibel() const {return _errorLibels[(int)_error];};
#else
  string getErrorLibel() const {return _errorLibels[(int)_error];};
#endif
  /**
     \par Description:
     Check if automaton state is a valid one. The function will return true if internal state is different from ERROR.

     \par Parameters:
     None.

     \par Return values:
     true if state is different from ERROR, false either.
  */
  bool isValid() const {return (_currentState != MGR_ERROR);};
  /**
     \par Description:
     Check if automaton state is ERROR. The function will return true if internal state is ERROR.

     \par Parameters:
     None.

     \par Return values:
     true if state is ERROR, false either.
  */
  bool isError() const {return (_currentState == MGR_ERROR);};
  /**
     \par Description:
     Set trace mask for the whole library hence it's a static function (default value is 3).

     \param traceLevel [in]: level trace chosen (examples: 'HisReadFileMgr::ErrorLevel' or 'HisReadFileMgr::ErrorLevel|HisReadFileMgr::AutomatonLevel')

     \par Return values:
     None.
  */
  static void SetTraceMask(unsigned char traceLevel);

  //@}

  typedef void (HisReadFileMgr::*HisReadFileMgrAction)(void);

 private:
  //automate
  struct Transition {
    State currentState;
    Trans currentTrans;
    State nextState;
    HisReadFileMgrAction action;
  };

  static SCS_SL_STD(string) _stateLibels[];
  static SCS_SL_STD(string) _transLibels[];
  static SCS_SL_STD(string) _errorLibels[];

  void init();

  void onFileOpen();
  void onRead();
  void onLoad();
  void onClose();
  void onReadInCache();
  void onError();

  void sendCmd(Trans event);

  static Transition _transitions[];
  static unsigned char** _stateTransitionMatrix;
  State _currentState;
  ErrorType _error;

  //readMgr
  AntPathName* _archiveFileName;
  AntPathName* _archiveStructureFileName;
  AntPathName* _databaseStructureFileName;

  HisArchiveFile* _archiveFile;
  HisArchiveStructure* _archiveStructure;
  HisDatabaseStructure* _databaseStructure;

  //request
  HisPointSet* _inPoints;
  unsigned long _startTime;
  unsigned long _endTime;
  HisDbDataSet* _outValues;

  //cache
  HisPointSet* _allPoints;
  HisDbDataSet* _allValues;
};

#endif //__HISREADFILEMGR_H_
