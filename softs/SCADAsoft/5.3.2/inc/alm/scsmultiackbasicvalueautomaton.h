/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsmultiackbasicvalueautomaton.h                     */
/*  FULL NAME       : ScsMultiAckBasicValueAutomaton                       */
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
/*  ScsMultiAckBasicValueAutomaton is the root class for value automaton   */
/*  with one or more acknowledgement automaton.                            */
/*.........................................................................*/
/*  COMMENT                                                                */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsMultiAckBasicValueAutomaton's interface.        */
/***************************************************************************/

// Revision 3.11.0  2002/02/18 KLL
// FFT SCADAsoft-186 - Vecteur de retour & modification de 
//                     ScsBasicValueAutomaton::updateAckAutomaton

// Revision 4.2.0  2004/06/03 KLL
// FFT SCADAsoft 464 - Merge des automates SRC vers la 4.2.0

#ifndef _SCSMULTIACKBASICVALUEAUTOMATON_H
#define _SCSMULTIACKBASICVALUEAUTOMATON_H

#include "alm/scsbasicvalueautomaton.h"

struct AckAutoStruct
{
  long _almId;
  int _hidden;
  ScsBasicAckAutomaton* _pAckAutomaton;
};

class AckAutoStructRWGDlist;

class ALMAUT_API ScsMultiAckBasicValueAutomaton: public ScsBasicValueAutomaton
{
  // METHODS
 public:
  // constructor
  ScsMultiAckBasicValueAutomaton(const AlmInteger64   inAutoId,
				 const DbkAddressId* inResultAddress);
  ScsMultiAckBasicValueAutomaton(const ScsMultiAckBasicValueAutomaton& inAutomaton );
  // destructor
  virtual ~ScsMultiAckBasicValueAutomaton() = 0;

  // KLL - 20/02/2003 - FFT SCADAsoft 186 
  //                    set acknowledged automaton name.
  virtual int setAckAutomatonName(const char* inAckAutomatonName);
  // set acknowledged time out.
  virtual int setAckAutomatonTimeout(const int inAckTimeout) const;
  // get the associated acknowledge automaton.
  virtual ScsBasicAckAutomaton* getAckAutomaton() const;
  virtual ScsBasicAckAutomaton* getNAckAutomaton();
  // get the acknowledged automaton
  virtual ScsBasicAckAutomaton* getAckAutomaton(const long inAlmId) const;
  virtual ScsBasicAckAutomaton* getAckAutomatonNb(const int inIndex) const;
  virtual int getAckAutomatonNb() const;
  virtual ScsBasicAckAutomaton** getAllAckAutomatons(int&	oAckAutoSize) const;
  virtual ScsBasicAckAutomaton** getAllAckAutomatons(int&	oAckAutoSize,
						     long*&	opAlmIds) const;
  // get the acknowledge status
  virtual int getAckStatus();
  // return the key of the current alarm.
  virtual long getAlmId();
  // set an alarm key
  virtual void setAlmId(const long inAlmId);
  // remove an alarmkey
  virtual void removeAlmId(const long inAlmId);
  // get AlmIds
  virtual void getAllAlmIds(long*& opAlmIds,
			    int& outAlmIdNb);
  // get AlmIds number
  virtual int getAlmIdsNb() const;
  // hide the automaton.
  virtual void hide(const ScsBasicAckAutomaton* ipAckAutomaton);
  // show the automaton.
  virtual void show(const ScsBasicAckAutomaton* ipAckAutomaton);
  // tests if the automaton is being hidden.
  virtual int isHidden(const ScsBasicAckAutomaton* ipAckAutomaton) const;



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
 protected:
  // update the acknowledge automaton the new status
  virtual void updateAckAutomaton(int& outAckStatus);

  // redondancy
  // save state
  virtual ScsStatus save	(SCS_SL_STD(ostream)& opStream) = 0;
  // restore
  virtual ScsStatus restore	(SCS_SL_STD(istream)& ipStream) = 0;

  // KLL - 19/02/2003 - FFT SCADAsoft 186 - Create ack automaton 
  virtual void updateLastAckAutomaton (int& outAckStatus);

  virtual void setNormal();

  virtual void logEventValue(){};

  // ESA - 29/08/2006 - PCR SCS 813
  virtual char* getColumnName(){return NULL;};

 private:
  ScsMultiAckBasicValueAutomaton();

  AckAutoStruct* getNew_pAckAutoStruct();
  AckAutoStruct* addNew_pAckAutoStruct();
  // get the last non acknowledged automaton
  AckAutoStruct* getLastNAckStruct();
  AckAutoStruct* getCurrentAckStruct() const;
  void removeCurrentAckAutomaton();
  // get automaton creation function
  void setAutomatonCreationFunction ();
  ScsBasicAckAutomaton* getCurrentAckAutomaton() const;
  // to delete an AckAutoStruct's instance
  static  void DeleteAckAutoStruct(AckAutoStruct* ipStructToDelete);
  // redondancy
  ScsStatus saveAckAutoStruct		( SCS_SL_STD(ostream)&	outStream,
					  AckAutoStruct*&	inAutoStruct);
  ScsStatus restoreAckAutoStruct	( SCS_SL_STD(istream)&	inStream,
					  AckAutoStruct*&	outAutoStruct);
  ScsStatus saveAckAutoLink		( SCS_SL_STD(ostream)&	outStream,
					  ScsBasicAckAutomaton* inAckAuto);
  ScsStatus restoreAckAutoLink		( SCS_SL_STD(istream)&	inStream,
					  ScsBasicAckAutomaton* inAckAuto);

  // KLL - 19/02/2003 - FFT SCADAsoft 186 - Create ack automaton 
  ScsBasicAckAutomaton * createAckAutomaton();
  void updateAckAutomaton(ScsBasicAckAutomaton * inAckAutomaton,
			  int&                   outAckStatus);

  // FIELDS
 private:
  AckAutoStructRWGDlist*		_packAutomatonList;
  GetAutomatonCreationFunctionPointer	_automatonCreationFunction;

};

#endif // _SCSMULTIACKBASICVALUEAUTOMATON_H

// end of file scsmultiackbasicvalueautomaton.h

