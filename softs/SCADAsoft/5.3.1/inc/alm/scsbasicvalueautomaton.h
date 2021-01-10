/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsbasicvalueautomaton.h                             */
/*  FULL NAME       : ScsBasicValueAutomaton                               */
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
/*  ScsBasicValueAutomaton is the root class for all the value automate    */
/*  behaviour.                                                             */
/*.........................................................................*/
/*  COMMENT                                                                */
/*  ScsBasicValueAutomaton is an abstract class for value automaton used in*/
/*  the alarm server.                                                      */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsBasicValueAutomaton's interface.                */
/***************************************************************************/
// Revision 3.9.0  2002/11/18 KLL
// FFT SRC-375 - snapshot
//
// Revision 3.11.0  2002/02/13 KLL
// FFT SCADAsoft-180 - Performance du serveur d'alarmes
//
// Revision 3.11.0  2002/02/18 KLL
// FFT SCADAsoft-186 - Vecteur de retour & modification de 
//                     ScsBasicValueAutomaton::updateAckAutomaton
//
// Revision 3.12.1  2002/03/12 KLL
// FFT SCADAsoft-181 - Modification de la méthode removeAutoId
//
// Revision 3.12.1  2002/03/25 KLL
// FFT SRC-498 - Nouvelle API removeAlarm
//
// Revision 3.14.0  2003/05/19 KLL
// FFT SRC-531 - Pb lorsque cette méthode est
//               appelée par DbkSession::removeAutoId donc 
//               Effacer toutes les alarmes à partir de l'automate
// Revision 3.14.0  2003/05/22 KLL
// ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
//           nouveau noyau
//
// Revision 4.3.0  09/08/2004 KLL
// FFT SRC-787
//

#ifndef _SCSBASICVALUEAUTOMATON_H
#define _SCSBASICVALUEAUTOMATON_H

#include "alm/scsbasicautomaton.h"
#include "alm/scsbasicstate.h"

#define MONO	0
#define MULTI	1

class ScsBasicAckAutomaton;

class ALMAUT_API ScsBasicValueAutomaton: public ScsBasicAutomaton
{
  friend class ScsAlarm;
  friend class ScsBasicState;

  // METHODS
 public:
  // constructor
  ScsBasicValueAutomaton(const AlmInteger64  inAutoId,
			 const DbkAddressId* inResultAddress);
  ScsBasicValueAutomaton(const ScsBasicValueAutomaton& inAutomaton );
  // destructor
  virtual ~ScsBasicValueAutomaton() = 0;

  // date
  // set the value dates (equipment date and acquisition).
  void setValueDates(timeval inEquipmentDate,
		     timeval inAcquisitionDate);
  // return the equipment date of the value.
  const timeval getEquipmentDate() const;
  // return the acquisition date of the value.
  const timeval getAcquisitionDate() const;

  // Redondancy
  // sauvegarde
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream) = 0;
  // restauration
  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream) = 0;

  // get the alarm status vector
  void getAlarmStatusVector(AlarmStatusVector& statusVector);
  // get the status of the automaton
  virtual int getStatus() const;
  // get the severity of the alarm
  int getSeverity() const;

  // AckAutomaton
  //  set acknowledged automaton name.
  virtual int setAckAutomatonName(const char* inAckAutomatonName);
  // set acknowledged time out.
  virtual int setAckAutomatonTimeout(const int inAckTimeout) const = 0;
  // get the current acknowledged automaton.
  virtual ScsBasicAckAutomaton* getAckAutomaton() const = 0;
  virtual ScsBasicAckAutomaton* getNAckAutomaton() = 0;
  // get the acknowledged automaton
  virtual ScsBasicAckAutomaton* getAckAutomaton(const long inAlmId) const = 0;
  virtual ScsBasicAckAutomaton* getAckAutomatonNb(const int inIndex) const = 0;
  virtual int getAckAutomatonNb() const = 0;
  // get the acknowledge status
  virtual int getAckStatus() = 0;
  // update the database the new alarm status.
  void updateNewAckStatus(const int inNewSeverity);
  // get acknowledged automatons
  virtual ScsBasicAckAutomaton** getAllAckAutomatons(int&	oAckAutoSize) const = 0;
  virtual ScsBasicAckAutomaton** getAllAckAutomatons(int&	oAckAutoSize,
						     long*&	opAlmIds) const = 0;
  // get AlmIds
  virtual void getAllAlmIds(long*& opAlmIds,
			    int& outAlmIdNb) = 0;

  // get AlmIds number
  virtual int getAlmIdsNb() const = 0;
  // get value in string format
  virtual char* getStringValue() const = 0;
  // hide the automaton.
  virtual void hide(const ScsBasicAckAutomaton* ipAckAutomaton) = 0;
  // show the automaton.
  virtual void show(const ScsBasicAckAutomaton* ipAckAutomaton) = 0;
  // tests if the automaton is being hidden.
  virtual int isHidden(const ScsBasicAckAutomaton* ipAckAutomaton) const = 0;

  // get equipment name
  const char* getEquipmentName() const;
  // get categories
  int getFunctionalCategory() const;
  int getGeographicalCategory() const;
  // get theme
  int getTheme() const;
  // set equipment name
  virtual void setEquipmentName(const char* inEquipmentName);
  // set categories
  virtual void setCategories(const int inFunctionalCategory,
		     const int inGeographicalCategory);
  // set theme
  virtual void setTheme(const int inTheme );
  // Kll - 2003/05/22 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  virtual void setEnvironment(const char *  inEnvironment);
  virtual void setUserField1(const char *   inUserField1);
  virtual void setUserField2(const char *   inUserField2);
  virtual void setDssEventType(const char * inDssEventType);
  const char * getEnvironment() const;
  const char * getUserField1() const;
  const char * getUserField2() const;
  const char * getDssEventType() const;

  // return message associated.
  const char* getMessage() const;

  // get value instance pointer
  virtual void* getValuePointer() const = 0;

  // get value user instance pointer
  virtual void* getValuePointerUser () const;

  //  get acknowledged automaton name.
  const char* getAckAutomatonName() const;

  // get userId of the value automaton
  virtual long getUserId () const;

  //FFT SRC 375 - KLL - 18/11/2002
  static  int readMessage (char * &             message,
			  SCS_SL_STD(istream)& inStream);
  static  int writeMessage (char *               message,
			   SCS_SL_STD(ostream)& outStream);
  
  // KLL - 14/02/2003 - FFT SCADAsoft 180 - Performance AlmServer
  int getFlagAttributsModify() const;
  virtual void setFlagAttributsModify(int          inStatus, 
				      int          inSeverity, 
				      timeval      inEquipmentDate,
				      timeval      inAcquisitionDate,
				      const char * inMessage,
				      long         oldValue,
				      long         newValue);
  virtual void setFlagAttributsModify(int          inStatus, 
				      int          inSeverity, 
				      timeval      inEquipmentDate,
				      timeval      inAcquisitionDate,
				      const char * inMessage,
				      double       oldValue,
				      double       newValue);
  virtual void setFlagAttributsModify(int          inStatus, 
				      int          inSeverity, 
				      timeval      inEquipmentDate,
				      timeval      inAcquisitionDate,
				      const char * inMessage,
				      const char * oldState,
				      const char * newState);
  virtual void unsetFlagAttributsModify();

  // KLL - 25/03/2003 - FFT SRC 498 - Implémentation de la méthode ScsAlarm::removeAlarm
  // REMARQUE : On suppose que les formules sont de type SCS_ALARM_DI(AI)
  //            Cette restriction est faite car on suppose que pour l'instant seul SRC 
  //            utilise les méthodes ScsAlarm::removeAlarm et ScsAlarm::removeAutoId et 
  //            actuellement il n'utilise que des formules de ce type là.
  virtual int createDbmDirectDataToWrite(DbmDirectData *& inData);


  // Kll - 2003/06/18 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  void createTempoData (ScsBasicAckAutomaton * inAckAutomaton);
  void deleteTempoData();
  void modifyTempoData();
  OlsData *  getTempoData () const;

  // get ScsAutomatonTimer pointer
  virtual void* getAutomatonTimerPointer() const;

  //FFT SRC 426 - KLL - 19/12/2002
  virtual int BSReset();

  short getTypeValueAutomaton () const {return _typeValueAutomaton;} ;
  void setTypeValueAutomaton (short typeValueAutomaton)  {_typeValueAutomaton = typeValueAutomaton;} ;

  // ESA - 29/08/2006 - PCR SCS 813
  virtual char* getColumnName() = 0;

 protected:
  // alarm state
  virtual void setAlarm();
  virtual void setNormal();
  // Kll - 2003/05/27 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  virtual void setTransition();

  // KLL - 20/02/2003 - FFT SCADAsoft 186 - Create ack automaton 
  virtual void setFleetingAlarm();
  // severity
  void setSeverity(int inNewSeverity);

  // set message
  void setMessage(const char* inMsg);

  // update the acknowledge automaton the new status
  virtual void updateAckAutomaton(int& outAckStatus) = 0;

  // KLL - 19/02/2003 - FFT SCADAsoft 186 - Create ack automaton 
  virtual void updateLastAckAutomaton (int& outAckStatus) = 0;
  
  //FFT SCADAsoft 181 - KLL - 12/03/2003
  // Modification du comportement de la méthode ScsAlarm::removeAutoId
  virtual void removeAutoId();

  // KLL - 25/03/2003 - FFT SRC 498 - Implémentation de la méthode ScsAlarm::removeAlarm
  virtual void removeAlarm(const long inAlmId);

  // KLL - 19/05/2003 - FFT SRC 531 - Effacer toutes les alarmes 
  virtual int removeAllAlmIds ();

  /// ESA - 19/06/2006 - PCR PCC 185 + ML2 84
  virtual void logEventValue() = 0;
  // log event for DI value
  virtual void LogEvent(const long inValue);
  // log event for AI value
  virtual void LogEvent(const double inValue);
  // set removing command receiver list flag
  void setFlagRemoveFromCommandList();
  // unset removing command receiver list flag
  void unsetFlagRemoveFromCommandList();
  // get removing command receiver list flag
  short getFlagRemoveFromCommandList();

 private:
  ScsBasicValueAutomaton();

  // FIELDS
 public:
  // alarm state
  static  const int  _ALARM;
  static  const int  _NORMAL;
  // Kll - 2003/05/22 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  static  const int  _TRANSITION;
  static  const int  _NOTHING;
  // ESA - 13-02-07 - PCR SRC 1226 - add two new states
  static  const int  _UPDATE;
  static  const int  _DELETE;

  // broadcast display property
  static  const int  _HIDDEN;
  static  const int  _SHOW;

  //FFT SCADAsoft 181 - KLL - 12/03/2003
  // Modification du comportement de la méthode ScsAlarm::removeAutoId
  static  const char* _REMOVE_AUTOID_MSG;

 private:
  // alarm state
  int     _alarmed;
  // alarm severity
  int     _severity;
  // equipment date
  timeval _equipmentDate;
  // acquisition date
  timeval _acquisitionDate;
  // acknowledged automaton name associated
  char*   _ackAutomatonName;
  // message
  char*   _message;
  // equipment name
  char*   _equipmentName;
  // functional category
  int     _fctCat;
  // geographical category
  int     _geoCat;
  // theme
  int     _theme;
  // Kll - 2003/05/22 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  char * _environment;
  char * _userField1;
  char * _userField2;
  char * _dssEventType;

  // KLL - 14/02/2003 - FFT SCADAsoft 180 - Performance AlmServer
  int _flagAttributsModify;
  int _flagVectorReturn;

  // Kll - 2003/06/18 - ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
  //                              nouveau noyau
  // Remplace le tempoList de RTAP
  OlsData * _tempoData;

  // Type of value automaton (Multi or Mono)
  short _typeValueAutomaton;

  // Remove from command receiver list flag
  short _flagRemoveFromCommandList;
};

#endif // _SCSBASICVALUEAUTOMATON_H

// end of file scsbasicvalueautomaton.h

