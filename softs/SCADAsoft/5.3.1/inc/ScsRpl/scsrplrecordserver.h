/******************************************************************************/
/*                S Y S E C A                                                 */
/*                                                                            */
/*  FILE        : scsrplrecordserver.h                                        */
/*  FULL NAME        :                                                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*  AUTHOR        : Isabel Garay                                              */
/*  COMPANY        : THALES-IS                                                */
/*  CREATION DATE    : 26/05/2005                                             */
/*  LANGUAGE        : C++                                                     */
/*............................................................................*/
/*  OVERVIEW                                                                  */
/*    Declaration of the ORB implementation class ScsRplRecordServer          */
/*                                                                            */
/*............................................................................*/
/*  CONTENTS                                                                  */
/*                                                                            */
/******************************************************************************/

#ifndef _SCSRPLRECORDSERVER_H
#define _SCSRPLRECORDSERVER_H

#include "scs.h"
#include "scstype.hh"

class RplRecordMgrIdl_i;
class RplRecordServerIdl_i;
class ScsRplClient;
class AscServer;


class ScsRplRecordServer
{
public:
  ScsRplRecordServer(const char *snapshotPath,
		     const char *rplSnapshotPath,
		     int savingPeriod,
		     unsigned int timeout,
		     int activated,
		     bool sync);
  virtual ~ScsRplRecordServer();

  ScsStatus getStatus() const { return _status; }
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

  static void Initialize(void *arg);

  // Public methods
  virtual ScsStatus writeSnapshot(const char *path);
  virtual void record(ScsRplClient *client,
		      const timeval &recordTime,
		      int recordLength,
                      char *record);
  virtual ScsStatus doneSnapshot(const char *snapshotName);
  virtual void incrementalSnapshot(StringList &fileNameList);
  virtual void activateRecMgr(long pFlag);
  virtual ScsStatus doSnapshot(StringList &fileNameList);

  int isActivated();
  
private:
  ScsStatus             _status;
  RplRecordMgrIdl_i    *_rplRecordManager;
  RplRecordServerIdl_i *_rplRecordServer;
  char*                 _snapshotPath;

  // To avoid multiple instaces of the same class
  ScsRplRecordServer(const ScsRplRecordServer &rhs);
  ScsRplRecordServer &operator=(const ScsRplRecordServer &rhs);
};

#endif // _SCSRPLRECORDSERVER_H
