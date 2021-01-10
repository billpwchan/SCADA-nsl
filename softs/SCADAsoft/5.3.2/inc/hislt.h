//-*-c++-*-
/******************************************************************************/
/*                                                                            */
/*  FILE             : hislt.h                                                */
/*  FULL NAME                :                                                */
/*----------------------------------------------------------------------------*/
/*  COMPANY          : THALES-IS                                              */
/*  CREATION DATE    : Wed Feb 20 15:01:59 2002                               */
/*  LANGUAGE         : C++                                                    */
/*............................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                         */
/*  All rights reserved.                                                      */
/*                                                                            */
/*  Unauthorized access, use, reproduction or distribution is prohibited.     */
/*............................................................................*/
/*  OVERVIEW           Implementation of the interface class for the exported */
/*	services of the LTServer                                              */
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
//
// Revision 4.3.0  18/08/2004 KLL 
// FFT SCS 509 - Traitement de données suite à un changement de VDC
//


#ifndef _SCS_HISLT_H_
#define _SCS_HISLT_H_

#include "scs.h"
#include "histypes.h"

class HisArchiveInfoList;

typedef struct HisArchiveInfo
{
  int type;
  int period;
  int numPeriod;
} HisArchiveInfo;

typedef struct 
{
  char*                dbvId;
  unsigned long        startTime;
  unsigned long        endTime;
  HisArchiveInfoList * archiveInfoList;
} HisLTDBVInfo;

typedef struct
{
  char*         fileName;
  unsigned long startTime;
  unsigned long endTime;
} HisLTFileInfo;

typedef void (*HisLTCallback)(HisLTFileInfo* p_fileInfos, 
			      unsigned int p_infoCount, 
			      ScsAny p_arg, 
			      ScsStatus p_returnStatus);

typedef void (*HisLTDBVIdsCallback)(HisLTDBVInfo* p_dbvInfos, 
				    unsigned short p_infoCount, 
				    ScsAny p_arg, 
				    ScsStatus p_returnStatus);

class HisLTClient_i;
class HisLTProxy;

class HLT_API HisLTServer
{ 
public:

  HisLTServer(const char* p_logicalEnv = 0,
	      const char* p_serverName = "LTServer");

  ~HisLTServer();
  
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
  
  ScsStatus putHistFiles(const char*   p_path,
			 const char*   p_logicalEnv, 
			 const char*   p_hostname,
			 HisLTCallback p_callback = 0,
			 ScsAny        p_arg = 0,
			 const char *  p_dbvId = "",
			 const short   p_type    = ERROR_TYPE) const;

  ScsStatus getHistFiles(char** p_fileNames,
			 unsigned int p_count,
			 const char* p_path, 
			 const char* p_logicalEnv,
			 const char* p_hostname,
			 HisLTCallback p_callback = 0,
			 ScsAny p_arg = 0) const;

  ScsStatus putDBVStructure(const char*         p_dbvId,
			    const unsigned long p_startTime,
			    short *             typeList,
			    int *               periodList,
			    int *               numPeriodList,
			    const int           nbElement, 
			    const char*         p_path, 
			    const char*         p_logicalEnv,
			    const char*         p_hostname,
			    HisLTCallback       p_callback = 0,
			    ScsAny              p_arg = 0) const;

  ScsStatus getDBVStructure(const char*   p_dbvId,
			    const char*   p_path, 
			    const char*   p_logicalEnv,
			    const char*   p_hostname,
			    HisLTCallback p_callback = 0,
			    ScsAny        p_arg = 0) const;

  ScsStatus getAllDBVInfos(unsigned short& p_count,
			   HisLTDBVInfo*& p_infos) const;

  ScsStatus getDBVInfos(unsigned long p_startTime,
			unsigned long p_endTime,
			unsigned short& p_count,
			HisLTDBVInfo*& p_infos) const;

  ScsStatus getStatus() const;

  void getTag(ScsMessageTag& p_tag) const;

private:

  HisLTProxy* _hisLTProxy;
  ScsStatus _hisLTProxyStatus;
  char _localConnection;
  HisLTClient_i* _client;
  ImgMsgTag* _tagProvider;
};
 
inline ScsStatus HisLTServer::getStatus() const
{
  return _hisLTProxyStatus;
}

#endif
