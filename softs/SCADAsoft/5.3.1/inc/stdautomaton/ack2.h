/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : ack2.h                                               */
/*  FULL NAME       : Ack2                                                 */
/*-------------------------------------------------------------------------*/
/*  AUTHOR          : LEY K.L.   	                                   */
/*  COMPANY         : SYSECA                                               */
/*  CREATION DATE   : 17 06 2003                                           */
/*  LANGUAGE        : C++                                                  */
/*.........................................................................*/
/*  OVERVIEW                                                               */
/*  Ack without log                                                        */
/*.........................................................................*/
/*  COMMENT                                                                */
/*                                                                         */
/*.........................................................................*/
/*  CONTENTS                                                               */
/*  This file describes Ack2's interface.                                  */
/***************************************************************************/
#ifndef _ACK2_HEADER_
#define _ACK2_HEADER_
 
#include "scsbasicackautomaton.h"

class ALMSTDAUT_API Ack2: public ScsBasicAckAutomaton 
{
 public:
  Ack2 (const AlmInteger64 inAutoId,
       const DbkAddressId* inDbkAddressId);
  Ack2 (const Ack2 & inAck2);
  ~Ack2 ();

  virtual int BSReset();
  virtual int BSFire(const int inNewAlarmState, 
		     int & ioSeverity, 
		     const int inAckRequest, 
		     int & outNewAckState, 
		     const int inShelveRequest, 
		     int & outNewShelveStatus, 
		     const long inUserId);

  int getPS() { return PS; }
 
  // redondancy: sauvegarde
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream);
  // redondancy: restauration
  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream);

 private:
  CREATOR_H(Ack2)
  int PS;
  int NS;
};

#endif // _ACK2_HEADER_

 
