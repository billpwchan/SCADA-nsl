/***************************************************************************/
/* The information contained in this document is proprietary to Thales IS  */
/*  and shall not be disclosed by the recipient to third persons without   */
/*  the written consent of Thales IS.                                      */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : scsmonoackbasicvalueautomaton.h                      */
/*  FULL NAME       : ScsMonoAckBasicValueAutomaton                        */
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
/*  ScsMonoAckBasicValueAutomaton is the root class for value automaton    */
/*  with almost one acknowledment automaton.                               */
/*.........................................................................*/
/*  COMMENT                                                                */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes ScsMonoAckBasicValueAutomaton's interface.         */
/***************************************************************************/
//
// Revision 3.11.0  2002/02/18 KLL
// FFT SCADAsoft-186 - Vecteur de retour & modification de 
//                     ScsBasicValueAutomaton::updateAckAutomaton
//
// Revision 3.14.0  2003/06/24 KLL
// ENF MAT - Adaptation des automates RTAP vers le serveur d'alarmes
//           nouveau noyau
//

#ifndef _SCSMONOACKBASICVALUEAUTOMATON_H
#define _SCSMONOACKBASICVALUEAUTOMATON_H

#include "alm/scsbasicvalueautomaton.h"

class ALMAUT_API ScsMonoAckBasicValueAutomaton: public ScsBasicValueAutomaton
{
  // METHODS
  // constructor
 public:
  ScsMonoAckBasicValueAutomaton(const AlmInteger64  inAutoId,
				const DbkAddressId* inResultAddress);
  ScsMonoAckBasicValueAutomaton(const ScsMonoAckBasicValueAutomaton& inAutomaton );
  virtual ~ScsMonoAckBasicValueAutomaton() = 0;

  // KLL - 20/02/2003 - FFT SCADAsoft 186 
  //                    set acknowledged automaton name.
  virtual int setAckAutomatonName(const char* inAckAutomatonName);
  
  // redondancy: sauvegarde
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream) = 0;
  // redondancy: restauration
  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream) = 0;
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

 protected:
  // update the acknowledge automaton the new status
  virtual void updateAckAutomaton(int& outAckStatus);

  // KLL - 19/02/2003 - FFT SCADAsoft 186 - Create ack automaton 
  virtual void updateLastAckAutomaton (int& outAckStatus);

 private:
  ScsMonoAckBasicValueAutomaton();

  // KLL - 19/02/2003 - FFT SCADAsoft 186 - Create ack automaton 
  ScsBasicAckAutomaton * createAckAutomaton();

  // FIELDS
 private:
  long                  _almId;
  int                   _hidden;
  ScsBasicAckAutomaton* _pAckAutomaton;
};

#endif // _SCSMONOACKBASICVALUEAUTOMATON_H

// end of file scsmonoackbasicvalueautomaton.h
