/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsalarmdata.h                                       */
/*  FULL NAME       : ScsAlarmData                                         */
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
/*  ScsAlarmData is the alarm server data. It contains the alarm list and  */
/*  event one.                                                             */
/*.........................................................................*/
/*  COMMENT                                                                */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file defined interface of class 'ScsAlarmData'.                   */
/***************************************************************************/

// Revision 3.12.1  2002/03/26 KLL
// FFT SRC-506 - Initialisation des champs de la liste lors de la création d'une alarme

// Revision 3.14.0  2003/05/19 KLL
// ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
//           nouveau noyau
//
// KLL - 27/07/2003 - Historisation du logEvent
//

#ifndef _SCSALARMDATA_H
#define _SCSALARMDATA_H

#include <stdio.h>
#include "scsdata.h"
#include "olstypes.h"
#include "scsalm.h"

#include<vector>

struct timeval;
class ScsData;
class ScsBasicAckAutomaton;
class OlsCollectableListHis;

class ALMAUT_API ScsAlarmData
{
  // METHODS
 public:
  // constructor
  ScsAlarmData(OlsList*            inAlarmList,
	       OlsCollectableList* inEventList);
  // destructor
  ~ScsAlarmData();

  static  int GetIndex_AlmIdField();
  static  int GetIndex_AutoIdField();
  static  int GetIndex_UserIdField();
  static  int GetIndex_VisibilityField();
  static  int GetIndex_EquipmentNameField();
  static  int GetIndex_ValueEquipmentField();
  static  int GetIndex_AlarmEquipmentField();
  static  int GetIndex_AckEquipmentField();
  static  int GetIndex_SeverityField();
  static  int GetIndex_ShelveField();
  static  int GetIndex_HiddenField();
  static  int GetIndex_MessageField();
  static  int GetIndex_ThemeField();
  static  int GetIndex_EquipmentDateField();
  static  int GetIndex_AcquisitionDateField();
  static  int GetIndex_EventDateField();
  static  int GetIndex_FunctionalField();
  static  int GetIndex_GeographicalField();
  static  int GetIndex_AckAutomatonPointerField();
  // Kll - 2003/05/21 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  static  int GetIndex_EnvironmentField();
  static  int GetIndex_UserField1();
  static  int GetIndex_UserField2();
  static  int GetIndex_DssEventTypeField();

  // test if the key almId is already used
  int almIdExists(const long inAlmId) const;
  // get AutoId
  // cla : autoId has been troncated, the method returns a wrong value for autoId


  // return a new AlmId for internal alarm
  long getNewIntAlmId();
  // return a new AlmId for external alarm
  long getNewExtAlmId();

  // delete alarm data from his list
  int deleteAlarmData(const long inAlmId, 
		      const long inUserId=0);

  // record the acknowledgement event.
  int logEvent(const long         inAlmId,
	       const AlmInteger64 inAutoId,
	       const char*        inEquipmentName,
	       const char*        inMessage,
	       const int          inAlarmStatus,
	       const int          inAckStatus,
	       const int          inSeverity,
	       const int          inTheme,
	       const double       inAIValue,
	       const timeval &    inEquipmentDate,
	       const timeval &    inAcquisitionDate,
	       const int          inFunctionalCategory,
	       const int          inGeographicalCategory,
	       const long         inUserId = 0,
	       const int          inShelveStatus = 0);
  int logEvent(const long         inAlmId,
	       const AlmInteger64 inAutoId,
	       const char*        inEquipmentName,
	       const char*        inMessage,
	       const int          inAlarmStatus,
	       const int          inAckStatus,
	       const int          inSyeverity,
	       const int          inTheme,
	       const long         inDIValue,
	       const timeval &    inEquipmentDate,
	       const timeval &    inAcquisitionDate,
	       const int          inFunctionalCategory,
	       const int          inGeographicalCategory,
	       const long         inUserId = 0,
	       const int          inShelveStatus = 0);
  int logEvent(const long         inAlmId,
	       const AlmInteger64 inAutoId,
	       const char*        inEquipmentName,
	       const char*        inMessage,
	       const int          inAlarmStatus,
	       const int          inAckStatus,
	       const int          inSeverity,
	       const int          inTheme,
	       const char*        inValue,
	       const timeval &    inEquipmentDate,
	       const timeval &    inAcquisitionDate,
	       const int          inFunctionalCategory,
	       const int          inGeographicalCategory,
	       const long         inUserId = 0,
	       const int          inShelveStatus = 0,
	       const char*        inGroup1 = "",
	       const char*        inGroup2 = "");
  // Kll - 2003/06/16 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  int logEvent(const long         inAlmId,
	       const AlmInteger64 inAutoId,
	       const char*        inEquipmentName,
	       const char*        inMessage,
	       const int          inAlarmStatus,
	       const int          inAckStatus,
	       const int          inSeverity,
	       const int          inTheme,
	       const double       inAIValue,
	       const timeval &    inEquipmentDate,
	       const timeval &    inAcquisitionDate,
	       const int          inFunctionalCategory,
	       const int          inGeographicalCategory,
	       const char *       inEnvironment,
	       const char *       inUserField1,
	       const char *       inUserField2,
	       const char *       inDssEventType,
	       const long         inUserId = 0,
	       const int          inShelveStatus = 0);
  int logEvent(const long         inAlmId,
	       const AlmInteger64 inAutoId,
	       const char*        inEquipmentName,
	       const char*        inMessage,
	       const int          inAlarmStatus,
	       const int          inAckStatus,
	       const int          inSeverity,
	       const int          inTheme,
	       const long         inDIValue,
	       const timeval &    inEquipmentDate,
	       const timeval &    inAcquisitionDate,
	       const int          inFunctionalCategory,
	       const int          inGeographicalCategory,
	       const char *       inEnvironment,
	       const char *       inUserField1,
	       const char *       inUserField2,
	       const char *       inDssEventType,
	       const long         inUserId = 0,
	       const int          inShelveStatus = 0);
  int logEvent(const long         inAlmId,
	       const AlmInteger64 inAutoId,
	       const char*        inEquipmentName,
	       const char*        inMessage,
	       const int          inAlarmStatus,
	       const int          inAckStatus,
	       const int          inSeverity,
	       const int          inTheme,
	       const char*        inValue,
	       const timeval &    inEquipmentDate,
	       const timeval &    inAcquisitionDate,
	       const int          inFunctionalCategory,
	       const int          inGeographicalCategory,
	       const char *       inEnvironment,
	       const char *       inUserField1,
	       const char *       inUserField2,
	       const char *       inDssEventType,
	       const long         inUserId = 0,
	       const int          inShelveStatus = 0);

  // initialize data
  // KLL - 26/03/2003 - FFT SRC-506 - 
  // Initialisation des champs de la liste lors de la création d'une alarme
  int initAlarmData(const long             inAlmId,
		    const AlmInteger64     inAutoId,
		    const int              inHidden,
		    const int              inSeverity,
		    const int              inAlarmStatus,
		    const int              inAckStatus,
		    const int              inShelveStatus,
		    const char*            inEquipmentName,
		    const int              inFunctionalCategory,
		    const int              inGeographicalCategory,
		    const int              inTheme,
		    const char*            inMessage,
		    const timeval &        inEquipmentDate,
		    const timeval &        inAcquisitionDate,
		    ScsBasicAckAutomaton * inpAckAutomaton,
		    const char *           inEnvironment,
		    const char *           inUserField1,
		    const char *           inUserField2,
		    const char *           inDssEventType,
		    const long             inUserId = 0);

  // set the alarm equipment's data.
  int setAlarmEquipmentData(const long  inAlmId,
			    const char* inEquipmentName,
			    const int inFunctionalCategory,
			    const int inGeographicalCategory);
  // set the equipment name's data.
  int setEquipmentName(const long inAlmId,
		       const char* inEquipmentName);
  // set the alarm functional and geographical categories' data.
  int setCategories(const long inAlmId,
		    const int inFunctionalCategory,
		    const int inGeographicalCategory);

  // set the theme data
  int setTheme(const long inAlmId,
	       const int inTheme);
  // set the hidden data
  int setHiddenValue(const long inAlmId,
		     const int inHiddenValue);
  // set the message
  int setMessage(const long inAlmId,
		 const char* inMessage);

  int set_pAckAutomaton(const long inAlmId,
                        ScsBasicAckAutomaton* inpAckAutomaton);
  int setEnvironment (const long   inAlmId,
		      const char * inEnvironment);
  int setUserField1 (const long inAlmId,
		     const char * inUserField1);
  int setUserField2 (const long inAlmId,
		     const char  *inUserField2);
  int setDssEventType (const long   inAlmId,
		       const char * inDssEventType);
  
  // update the alarm's value.
  int updateAlarmListSeverity(const long inAlmId,
			      const int  inSeverity);
  int updateAlarmList(const long       inAlmId,
		      const int        inAlarmStatus,
		      const int        inAckStatus,
		      const int        inShelveStatus,
		      const int        inSeverity);
  int updateAlarmList(const long       inAlmId,
		      const int        inAlarmStatus,
		      const int        inAckStatus,
		      const int        inShelveStatus,
		      const int        inSeverity,
		      const char*      inValue);
  int updateAlarmList(const long       inAlmId,
		      const int        inAlarmStatus,
		      const int        inAckStatus,
		      const int        inShelveStatus,
		      const int        inSeverity,
		      const char*      inValue,
		      const char*      inMessage);
  int updateAlarmList(const long       inAlmId,
		      const int        inAlarmStatus,
		      const int        inAckStatus,
		      const int        inShelveStatus,
		      const int        inSeverity,
		      const char*      inValue,
		      const char*      inMessage,
		      const timeval &  inEquipmentDate,
		      const timeval &  inAcquisitionDate );
  int updateAlarmList(const long       inAlmId,
		      const int        inAlarmStatus,
		      const int        inAckStatus,
		      const int        inShelveStatus,
		      const int        inSeverity,
		      const char*      inValue,
		      const timeval &  inEquipmentDate,
		      const timeval &  inAcquisitionDate );
  int transferAlarm(const long         inOldAlmId,
		    const long         inNewAlmId,
		    const AlmInteger64 inAutoId,
		    const long	       inUserId,
		    const int          inAlarmStatus,
		    const int          inAckStatus,
		    const int          inSeverity,
		    const char*        inValue,
		    const char*        inMessage,
		    const timeval &    inEquipmentDate,
		    const timeval &    inAcquisitionDate );

  ScsBasicAckAutomaton* get_pAckAutomaton(const long inAlmId);


  // link user subscription and user identification
  //      to visibility alarm
  // and return the visisibility rank of the user
  int linkUserToAlarm(const long inSubId,
		      const long inUserId);
  // unlink user subscription and user identification
  int unlinkUserToAlarm(const long inSubId,
			const long inUserId);
  // get the visibility of the alarm
  OlsVisibility getVisibility(const long inAlmId) const;
  // get the user rank in visibility data
  int getVisibilityRank(const long inUserId) const;
  // get the UserIdField value
  long getUserId(const long inAlmId) const;
  // get the UserId inn rank "rank"
  long getUserIdWithRank (const int rank) const;
  // get the used autoId in a range
  SCS_SL_STD(vector)<AlmInteger64> getUsedAutoIdFromRange(const AlmInteger64 inThresholdLow,
							  const AlmInteger64 inThresholdHigh);
  
  // Get number of alarms in _pAlarmList
  int getAlarmsNb () const;

  // Kll - 2003/05/19 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  static  OlsData * NewTempoOlsData (const long             inAlmId,
				    const AlmInteger64     inAutoId,
				    const int              inHidden,
				    const int              inSeverity,
				    const int              inAlarmStatus,
				    const int              inAckStatus,
				    const int              inShelveStatus,
				    const char *           inEquipmentName,
				    const int              inFunctionalCategory,
				    const int              inGeographicalCategory,
				    const int              inTheme,
				    const char *           inMessage,
				    const timeval &        inEquipmentDate,
				    const timeval &        inAcquisitionDate,
				    ScsBasicAckAutomaton * inpAckAutomaton,
				    const char *           inEnvironment,
				    const char *           inUserField1,
				    const char *           inUserField2,
				    const char *           inDssEventType,
				    const long             inUserId);
  static  OlsData * NewTempoOlsData (OlsData * inData = NULL);
  
  OlsData * getData (const long inAlmId) const;

  // OlsList's utils functions: adds default fields.
  static  void AddDefaultFieldToList(OlsList* inpList);
  static  void InitOlsData(OlsData*     iopOlsData,
			  const long   inAlmId);

  static  void UpdateList(OlsData *&         historyData,
			 const AlmInteger64 inAutoId,
			 const char*        inEquipmentName,
			 const char*        inMessage,
			 const int          inAlarmStatus,
			 const int          inAckStatus,
			 const int          inSeverity,
			 const int          inTheme,
			 const char*        inValue,
			 const timeval&     inEquipmentDate,
			 const timeval&     inAcquisitionDate,
			 const int          inFunctionalCategory,
			 const int          inGeographicalCategory,
			 const long         inUserId);

  static  void UpdateData(OlsData*      ioAlarmData,
			 const int     inIndexField,
			 const int     inNewValue);
  static  void UpdateData(OlsData*      ioAlarmData,
			 const int     inIndexField,
			 const char*   inNewValue);
  static  void UpdateData(OlsData*      ioAlarmData,
			 const int     inIndexField,
			 const timeval inNewValue);
  static  void UpdateData(OlsData*      ioAlarmData,
			 const int      inIndexField,
			 const AlmInteger64 inNewValue);
  static  void UpdateData(OlsData*      ioAlarmData,
			 const int     inIndexField,
			 void*         inNewValue);

  // SNAPSHOT
  ScsStatus save(const char* inPathName);
  ScsStatus restore(const char* inPathName);
  
 private:
  // constructor
  ScsAlarmData();
  ScsAlarmData(const ScsAlarmData& inScsAlarmData);
  // _pEventList and _pAlarmList initialization : adds default fields.
  void addDefaultFieldToAllLists();
  // OlsList's utils functions: adds a field.
  static  int AddNewFieldToList(OlsList*  iopList,
				const OlsField& inpNewField);

  OlsData* getNewEvent( const long inAlmId );
  OlsData* createNewAlarmData(const long inAlmId);
  void getAlarmData(const long inAlmId,
		    OlsData*& inOldData,
		    OlsData*& inNewData);
  void getNewAlarmData(const long	inAlmId,
		       OlsData*&	outpOldData,
		       OlsData*&	outpNewData);
  OlsData* copyAlarmData(const long inOldAlmId,
			 const long inNewAlmId);


  static  char* Long2String(const long     inValue);
  static  char* Double2String(const double inValue);

  static  int Bit2IntBitField(const int inBit);

  // MEMBERS
 public:
  // Lists' name
  static  const char* _AlarmListName;
  static  const char* _EventListName;
  // Fields' name
  static  const char* _AlmIdFieldName;
  static  const char* _AutoIdFieldName;
  static  const char* _UserIdFieldName;
  static  const char* _EquipmentName;
  static  const char* _ValueEquipmentFieldName;
  static  const char* _AlarmEquipmentFieldName;
  static  const char* _AckEquipmentFieldName;
  static  const char* _SeverityFieldName;
  static  const char* _ShelveFieldName;
  static  const char* _HiddenFieldName;
  static  const char* _MessageFieldName;
  static  const char* _ThemeFieldName;
  static  const char* _EquipmentDateFieldName;
  static  const char* _AcquisitionDateFieldName;
  static  const char* _EventDateFieldName;
  static  const char* _FunctionalFieldName;
  static  const char* _GeographicalFieldName;
  static  const char* _pAckAutomatonFieldName;
  // Kll - 2003/05/19 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  static  const char * _EnvironmentFieldName;
  static  const char * _UserField1Name;
  static  const char * _UserField2Name;
  static  const char * _DssEventTypeFieldName;

 private:
  // alarm values list
  OlsList *	                _pAlarmList;
  // counter for internal AlmId
  long				_lastIntAlmId;
  // counter for external AlmId
  long				_lastExtAlmId;
  // events list
  OlsCollectableList *		_pEventList;

  // OlsList index
  static  int	_Index_AlmIdField;
  static  int	_Index_AutoIdField;
  static  int	_Index_UserIdField;
  static  int	_Index_EquipmentNameField;
  static  int	_Index_ValueEquipmentField;
  static  int	_Index_AlarmEquipmentField;
  static  int	_Index_AckEquipmentField;
  static  int	_Index_SeverityField;
  static  int	_Index_ShelveField;
  static  int	_Index_HiddenField;
  static  int	_Index_MessageField;
  static  int	_Index_ThemeField;
  static  int	_Index_EquipmentDateField;
  static  int	_Index_AcquisitionDateField;
  static  int	_Index_EventDateField;
  static  int	_Index_FunctionalField;
  static  int	_Index_GeographicalField;
  static  int	_Index_pAckAutomatonField;
  // Kll - 2003/05/19 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  static  int      _Index_EnvironmentField;
  static  int      _Index_UserField1;
  static  int      _Index_UserField2;
  static  int      _Index_DssEventTypeField;

  static  OlsDataSet* _DataSet;

};

#endif // _SCSALARMDATA_H

// end of file scsalarmdata.h
