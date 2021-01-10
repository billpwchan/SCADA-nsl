/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*  FILE            : scsbasicautomaton.h                                  */
/*  FULL NAME       : ScsBasicAutomaton                                    */
/*-------------------------------------------------------------------------*/
/*  COMPANY         : THALES IS                                            */
/*  CREATION DATE   : Fri December 08 2000                                 */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  Copyright © THALES Information Systems 1996-2003.                      */
/*  All rights reserved.                                                   */
/*                                                                         */
/*  Unauthorized access, use, reproduction or distribution is prohibited.  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  ScsBasicAutomaton is the root class for all the automate behaviour.    */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsBasicAutomaton is an abstract class for automaton used in the alarm */
/*  server.                                                                */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsBasicAutomaton's interface.                     */
/***************************************************************************/

// Revision 3.11.0  2002/02/13 KLL
// FFT SCADAsoft-188 - Remove value of _pAlarmList

// Revision 3.11.0  2002/02/28 KLL
// FFT SCADAsoft-186 - Vecteur de retour & modification de 
//                     ScsBasicValueAutomaton::updateAckAutomaton

// Revision 3.12.1  2002/03/20 KLL
// FFT SRC-498 - Nouvelle API removeAlarm

// Revision 3.14.0  2003/05/22 KLL
// ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
//           nouveau noyau

// Revision 4.2.0  2004/06/03 KLL
// FFT SCADAsoft 464 - Merge des automates SRC vers la 4.2.0

#ifndef _SCSBASICAUTOMATON_H
#define _SCSBASICAUTOMATON_H

#ifdef SCS_STD
#include <iostream>
#include <string>
#else
#include <iostream.h>
#endif

#include "scs.h"

#ifdef DBKALMSHMEM
#include "dbk/scsshmem.h"
#endif
// DbmServer
#include "dbm.h"
#include "dbmdirect.h"
// ALMTRACE
#include "scsalm.h"


// size of the result status array
#define DEF_Alarm_Status_Size	    4
typedef int AlarmStatusVector[DEF_Alarm_Status_Size];

class ScsAlarm;
class ScsAlarmData;
class DbkAddressId;

// ALARM ACTION
#define ALM_NONE  0
#define ALM_ACK   1
#define ALM_RAISE 2
#define ALM_RESET 3

// declaration of function type for automaton creation.
class ScsBasicAutomaton ;
typedef ScsBasicAutomaton* (*GetAutomatonCreationFunctionPointer)(const AlmInteger64  inAutoId,
								  const DbkAddressId* inResultAddress);

class ALMAUT_API ScsBasicAutomaton
{
  // METHODS
 public:
  // constructor
  ScsBasicAutomaton(const AlmInteger64       inAutoId,
		    const DbkAddressId*      inResultAddress);
  ScsBasicAutomaton(const ScsBasicAutomaton& inAutomaton );
  // destructor
  virtual ~ScsBasicAutomaton() = 0;

  // create an automaton.
  static  ScsBasicAutomaton* GetNewAutomaton(const char*         inAutomatonName,
					    const AlmInteger64  inAutoId,
					    const DbkAddressId* inResultAddress);


  // get the automaton creation function
  static  GetAutomatonCreationFunctionPointer getAutomatonCreationFunction(const char* inAutomatonName);
  
  // check if the static fields are setting correctly.
  static  int CheckMyself();

  // set the name of DbmServer client
  static  void SetDbmServiceName(const char* inDbmServiceName);
  // get the current DbmServer
  static  DbmServer* GetDbmServer();

  // set the link with the current ScsAlarm.
  static  ScsStatus SetScsAlarm( ScsAlarm* inpScsAlarm );
  // get the current ScsAlarm.
  static  ScsAlarm* GetScsAlarm();

  // set the link with alarms and events lists.
  static  void SetInfos(ScsAlarmData* inpAlarmEventData);

  // set the size of the buffer
  static  void SetBufferSize(const int inBufferNewSize );
  // set the status return option
  static  void SetStatusReturnOption(const int inStatusReturnOption );

  // send data.
  int send(const AlarmStatusVector& inResults) const;
  // KLL - 28/02/2003 - FFT SCADAsoft 186 - Initialize ack automaton name
  // send data.
  static  int Send(const DbkAddressId*      ipAlarmStatusAddress,
		   const AlarmStatusVector& inAlarmStatus);
  static  int SendDI(const DbkAddressId*      ipAlarmStatusAddress,
		     const AlarmStatusVector& inAlarmStatus,
		     const long               inValue);
  static  int SendAI(const DbkAddressId*      ipAlarmStatusAddress,
		     const AlarmStatusVector& inAlarmStatus,
		     const double             inValue);
  // send data.
#ifndef DBKALMSHMEM
  static  const DbmDirectDataSet& GetDbDataBuffer() { return _DbDataBuffer;} ;
  static  void RemoveDbDataBuffer();
#else
  static  void OpenSharedMemmory();
  static  void ResetSharedMemory();
#endif

  // automaton class name
  virtual const char* getAutomatonClassName() = 0;

  // REDONDANCY
  // redondancy
  // serialize instance
  virtual ScsStatus	save				(SCS_SL_STD(ostream)&	outStream) = 0;
  // deserialize instance
  virtual ScsStatus	restore				(SCS_SL_STD(istream)&	inStream) = 0;
  // save an automaton
  static  ScsStatus	SaveFromSnapshotStream		(SCS_SL_STD(ostream)& outStream, ScsBasicAutomaton*& inAutomaton);
  // restore an automaton
  static  ScsStatus	RestoreFromSnapshotStream	(SCS_SL_STD(istream)& inStream, ScsBasicAutomaton*& outAutomaton);

  // creation date of the automaton.
  const timeval getCreationDate();
  // automaton key
  AlmInteger64 getAutoId() const;
  // alarm status address
  const DbkAddressId* getResultAddress() const;
  // return the key of the current alarm.
  virtual long getAlmId() = 0;
  // add or set an alarm key
  virtual void setAlmId(const long inAlmId) = 0;
  // remove an alarmkey
  virtual void removeAlmId(const long inAlmId) = 0;
  // get the state of the automaton
  virtual int getStatus() const = 0;

  // convert a ScsAddress to DbkAddressId
  static  DbkAddressId* Convert(const ScsAddress* ipScsAddress);
  // convert a DbkAddressId instance to ScsAddress
  static  ScsAddress* Convert(const DbkAddressId* ipDbkAddressId);
  // Read DbmDataSet in database
  static  ScsStatus Read(DbmDataSet& dataSet);
  // DirectRead DbmDirectDataSet in database
  static  ScsStatus DirectRead(DbmDirectDataSet& directDataSet);

  // copy a DbkAddressId pointer if necessary
  void setNewAddrId(const DbkAddressId* inAddrId);

  // to synchronize with the alarm server
  // kll - 22 05 2002 - FFT 288 for SRC 
  void synchronizeAlmServer();

  // return user visibility rank
  static  int GetVisibilityRank(const long inUserId);

  // return _StatusReturnOption
  static  int GetStatusReturnOption() { return _StatusReturnOption; };

  // KLL - FFT SRC 431  - 13/12/2002 : Create a extern alarm
  // ESA - PCR SRC 1024 - 04/12/2006 : Add two new optional parameters
  ScsStatus updtExtAlm(AlmInteger64       &extAutoId,
		       const char*	  state,
		       const char*	  valueAutomaton,
		       const char*	  ackAutomaton,
		       const timeval	  equipmentDate,
		       const timeval	  acquisitionDate,
		       const long	  severity,
		       const long	  functionalCat,
		       const long	  geographicalCat,
		       const char*	  equipmentName,
		       const char*	  message,
		       const char*        group1 = "",
		       const char*        group2 = "",
		       const AlmInteger64 thresholdLow = 0,
		       const AlmInteger64 thresholdHigh = 0);
		       
  // KLL - 14/02/2003 - FFT SCADAsoft 188 - Remove value of _pAlarmList
  static  void SetNoValueOption(const int inNoValueOption );
  static  int GetNoValueOption();

  // JMA - 13/05/2004 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  int       getFlagLogEvent() const;
  void      setFlagLogEvent();
  void      unsetFlagLogEvent();

  // ESA - 13/05/2004 - PCR PCC 185 + ML2 84
  int       getSyntFlagLogEvent() const;
  void      setSyntFlagLogEvent();
  void      unsetSyntFlagLogEvent();

  virtual int BSReset() = 0;

 protected:
  // set events
  // record the acknowledgement event.
  virtual int logEvent(const char*	inEquipmentName,
		       const char*	inMessage,
		       const int		inAlarmStatus, 
		       const int		inAckStatus,
		       const int		inSeverity,
		       const int		inTheme,
		       const double	inAIValue,
		       const timeval&	inEquipmentDate,
		       const timeval&	inAcquisitionDate,
		       const int		inFunctionalCategory,
		       const int		inGeographicalCategory,
		       const long		inUserId = 0,
		       const int          inShelveStatus = 0);
  virtual int logEvent(const char*	inEquipmentName,
		       const char*	inMessage,
		       const int		inAlarmStatus, 
		       const int		inAckStatus,
		       const int		inSeverity,
		       const int		inTheme,
		       const long		inDIValue,
		       const timeval&	inEquipmentDate,
		       const timeval&	inAcquisitionDate,
		       const int		inFunctionalCategory,
		       const int		inGeographicalCategory,
		       const long		inUserId = 0,
		       const int          inShelveStatus = 0);
  // Kll - 2003/06/16 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  virtual int logEvent(const char*	inEquipmentName,
		       const char*	inMessage,
		       const int		inAlarmStatus, 
		       const int		inAckStatus,
		       const int		inSeverity,
		       const int		inTheme,
		       const long		inDIValue,
		       const timeval&	inEquipmentDate,
		       const timeval&	inAcquisitionDate,
		       const int		inFunctionalCategory,
		       const int		inGeographicalCategory,
		       const char *       inEnvironment,
		       const char *       inUserField1,
		       const char *       inUserField2,
		       const char *       inDssEventType,
		       const long		inUserId = 0,
		       const int          inShelveStatus = 0);
  virtual int logEvent(const char*	inEquipmentName,
		       const char*	inMessage,
		       const int		inAlarmStatus, 
		       const int		inAckStatus,
		       const int		inSeverity,
		       const int		inTheme,
		       const double	inAIValue,
		       const timeval&	inEquipmentDate,
		       const timeval&	inAcquisitionDate,
		       const int		inFunctionalCategory,
		       const int		inGeographicalCategory,
		       const char *       inEnvironment,
		       const char *       inUserField1,
		       const char *       inUserField2,
		       const char *       inDssEventType,
		       const long		inUserId = 0,
		       const int          inShelveStatus = 0);
  // set message in alarms list
  int setAlmListMsg(const long inAlmId, const char* inMessage);
  int setAlmListMsg(const char* inMessage);
  // set equipment name
  virtual void setEquipmentName(const char* inEquipmentName) = 0;
  // set categories
  virtual void setCategories(const int inFunctionalCategory,
			     const int inGeographicalCategory) = 0;
  // set theme
  virtual void setTheme(const int inTheme ) = 0;
  // Kll - 2003/05/22 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  virtual void setEnvironment(const char *  inEnvironment);
  virtual void setUserField1(const char *   inUserField1);
  virtual void setUserField2(const char *   inUserField2);
  virtual void setDssEventType(const char * inDssEventType);
  
  void setUserName(const char* name) { _username = name; }
  const char* getUserName() const { return _username.c_str(); }

  // get visibility
  int getVisibility(const long inAlmId);
  int getVisibility();
  // return UserId of an alarm
  long GetUserId(const long inAlmId);
  // return current UserId
  long getUserId();
  // get UserId with the rank of the user
  long getUserIdWithRank (const int rank) const; 

  // get datalists
  static  ScsAlarmData* GetDataLists();


 private:
  // default constructor
  ScsBasicAutomaton();

  // create a new Dbm client
  static  DbmServer* NewDbmServer();

// FIELDS
 private:
  // server part
  // ScsAlarmServer
  static  ScsAlarm*        _pScsAlarmServer;
  // DbmServer
  static  char*            _pDbmServiceName;
  static  DbmServer*       _pDbmServer;
#ifdef DBKALMSHMEM
  static  ScsSharedMemory_t _Mem;
  static  unsigned int     _ResultCounter;
#else
  // DbmDirectDataSet
  static  DbmDirectDataSet _DbDataBuffer;
#endif
  // alarms & events lists
  static  ScsAlarmData*    _pDataLists;
  // buffer size
  static  int              _BufferSize;
  // status return option
  static  int              _StatusReturnOption;
  // KLL - 14/02/2003 - FFT SCADAsoft 188 - Remove value of _pAlarmList
  static  int              _NoValueOption;
  
  // automaton part
  // date of creation of the automaton
  timeval       _creationDate;
  // key of the alarm (if external, negative)
  AlmInteger64            _autoId;
  // address in the database of the alarm status
  DbkAddressId*           _resultAddress;

  // JMA - 13/05/2004 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  int _flagLogEvent;

  // synthesis log event flag
  int _syntFlagLogEvent;
  
  SCS_SL_STD(string) _username;
};

// Macro for dynamic creation
#define DECL_CREATOR(CLASS_NAME,AUTOMATON_NAME)\
 public:\
  static const char* GetAutomatonClassName()\
    {\
      return #AUTOMATON_NAME;\
    };\
  static ScsBasicAutomaton* CreateNewAutomaton(const AlmInteger64 inAutoId,const DbkAddressId* inResultAddress)\
    {\
      return ( dynamic_cast<ScsBasicAutomaton*>( new CLASS_NAME(inAutoId,inResultAddress) ) );\
    };\
  inline virtual const char* getAutomatonClassName()\
    { return GetAutomatonClassName(); }

#define CREATOR_CPP(CLASS_NAME,AUTOMATON_NAME)\
 const char* CLASS_NAME::GetAutomatonClassName() {return #AUTOMATON_NAME;};\
 ScsBasicAutomaton* CLASS_NAME::CreateNewAutomaton(const AlmInteger64 inAutoId, const DbkAddressId* inResultAddress) { return ( dynamic_cast<ScsBasicAutomaton*>( new CLASS_NAME(inAutoId,inResultAddress) ) ); }
#define CREATOR_H(CLASS_NAME)\
 public:\
  static const char* GetAutomatonClassName();\
  static ScsBasicAutomaton* CreateNewAutomaton(const AlmInteger64 inAutoId, const DbkAddressId* inResultAddress);\
  inline virtual const char* getAutomatonClassName() { return GetAutomatonClassName(); };

#define INIT_LIBRARY(FACTORY,CLASS_NAME) \
 FACTORY->registerAutomatonClass( \
  CLASS_NAME::GetAutomatonClassName(), \
  CLASS_NAME::CreateNewAutomaton )

#endif // _SCSBASICAUTOMATON_H

// end of file scsbasicautomaton.h
