//-*-c++-*-
/*****************************************************************************/
/*  The information contained in this document is proprietary to THALES IS   */
/*  and shall not be disclosed by the recipient to third persons without the */
/*  written consent of THALES IS.                                            */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  FILE            : ScsRplClient.h                                         */
/*  FULL NAME       :                                                        */
/*---------------------------------------------------------------------------*/
/*  COMPANY         : THALES IS                                              */
/*  CREATION DATE   : Mon May 15 09:00:00 2000                               */
/*  LANGUAGE        : C++                                                    */
/*...........................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                        */
/*  All rights reserved.                                                     */
/*                                                                           */
/*  Unauthorized access, use, reproduction or distribution is prohibited.    */
/*...........................................................................*/
/*  OVERVIEW                                                                 */
/*                                                                           */
/*  Generic class for saving replay data.                                    */
/*                                                                           */
/*...........................................................................*/
/*  CONTENTS                                                                 */
/*                                                                           */
/*****************************************************************************/

#ifndef _SCSRPLCLIENT_H_
#define _SCSRPLCLIENT_H_

#include <string>

#include "scsdefs.h"
#include "scadaorb.h"
#include "scsrplrecordfile.h"
#include "rplrecordclientmgr.hh"

class ScsRplClient {

 public:
  ScsRplClient(const char *);
  ~ScsRplClient();

  void setClientID(long);
  long getClientID();

  const char *getSnapshotFileName();

  void setRecordFile(ScsRplRecordFile *);
  ScsRplRecordFile *getRecordFile();
  
  void setClientIdl(RplRecordClientMgrIdl* pClientIdl);
  RplRecordClientMgrIdl* getClientIdl() { return _clientIdl.in(); };
  

 private:
  SCS_SL_STD(string)  _snapshotFileName;
  long                _clientID;
  ScsRplRecordFile   *_rplRecordFile;
  RplRecordClientMgrIdl_var _clientIdl;
};

#endif
