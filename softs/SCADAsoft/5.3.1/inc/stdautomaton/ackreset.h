/***************************************************************************/
/*  The information contained in this document is proprietary to SYSECA and*/
/*  shall not be disclosed by the recipient to third persons without the   */
/*  written consent of SYSECA.                                             */
/*-------------------------------------------------------------------------*/
/*                                                                         */
/*  FILE            : ackreset.h                                           */
/*  FULL NAME       : AckReset                                             */
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
/*  This file describes AckLog's interface.                                */
/***************************************************************************/
#ifndef _ACK_RESET_HEADER_
#define _ACK_RESET_HEADER_
 
#include "scsbasicackautomaton.h"

class ALMSTDAUT_API AckReset: public ScsBasicAckAutomaton 
{
 public:
  AckReset (const AlmInteger64  inAutoId,
	    const DbkAddressId* inDbkAddressId);
  AckReset (const AckReset &    inAckReset);
  ~AckReset ();

  virtual int BSReset();
  virtual int BSFire(const int  inNewAlarmState, 
		     int &      ioSeverity, 
		     const int  inAckRequest, 
		     int &      outNewAckState, 
		     const int  inShelveRequest, 
		     int &      outNewShelveStatus, 
		     const long inUserId);

  int getPS() { return PS;}
 
  // redondancy: sauvegarde
  virtual ScsStatus save(SCS_SL_STD(ostream)& outStream);
  // redondancy: restauration
  virtual ScsStatus restore(SCS_SL_STD(istream)& inStream);

 private:
  CREATOR_H(AckReset)
  int PS;
  int NS;
};

#endif // _ACK_RESET_HEADER_

 
